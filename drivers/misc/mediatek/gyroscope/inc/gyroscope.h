/*
* Copyright (C) 2011-2014 MediaTek Inc.
* 
* This program is free software: you can redistribute it and/or modify it under the terms of the 
* GNU General Public License version 2 as published by the Free Software Foundation.
* 
* This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
* without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See the GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along with this program.
* If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __GYROSCOPE_H__
#define __GYROSCOPE_H__


#include <linux/wakelock.h>
#include <linux/interrupt.h>
#include <linux/miscdevice.h>
#include <linux/platform_device.h>
#include <linux/input.h>
#include <linux/workqueue.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/hwmsensor.h>
#include <linux/earlysuspend.h>
#include <linux/hwmsen_dev.h>


#define GYRO_TAG                    "<GYROSCOPE> "
#define GYRO_FUN(f)                printk(GYRO_TAG"%s\n", __func__)
#define GYRO_ERR(fmt, args...)    printk(GYRO_TAG"%s %d : "fmt, __func__, __LINE__, ##args)
#define GYRO_LOG(fmt, args...)    printk(GYRO_TAG fmt, ##args)
#define GYRO_VER(fmt, args...)  printk(GYRO_TAG"%s: "fmt, __func__, ##args) //((void)0)

#define OP_GYRO_DELAY    0X01
#define    OP_GYRO_ENABLE    0X02
#define    OP_GYRO_GET_DATA    0X04

#define GYRO_INVALID_VALUE -1

#define EVENT_TYPE_GYRO_X                  ABS_X
#define EVENT_TYPE_GYRO_Y                  ABS_Y
#define EVENT_TYPE_GYRO_Z                  ABS_Z
#define EVENT_TYPE_GYRO_STATUS     ABS_WHEEL


#define GYRO_VALUE_MAX (32767)
#define GYRO_VALUE_MIN (-32768)
#define GYRO_STATUS_MIN (0)
#define GYRO_STATUS_MAX (64)
#define GYRO_DIV_MAX (32767)
#define GYRO_DIV_MIN (1)


#define MAX_CHOOSE_GYRO_NUM 5

struct gyro_control_path
{
    int (*open_report_data)(int open);//open data rerport to HAL
    int (*enable_nodata)(int en);//only enable not report event to HAL
    int (*set_delay)(u64 delay);
    bool is_report_input_direct;
    bool is_support_batch;
};

struct gyro_data_path
{
    int (*get_data)(int *x,int *y, int *z,int *status);
    int vender_div;
};

struct gyro_init_info
{
      char *name;
    int (*init)(void);
    int (*uninit)(void);
    struct platform_driver* platform_diver_addr;
};

struct gyro_data{
    hwm_sensor_data gyro_data ;
    int data_updata;
    //struct mutex lock;
};

struct gyro_drv_obj {
  void *self;
    int polling;
    int (*gyro_operate)(void* self, uint32_t command, void* buff_in, int size_in,
        void* buff_out, int size_out, int* actualout);
};

struct gyro_context {
    struct input_dev   *idev;
    struct miscdevice   mdev;
    struct work_struct  report;
    struct mutex gyro_op_mutex;
    atomic_t            delay; /*polling period for reporting input event*/
    atomic_t            wake;  /*user-space request to wake-up, used with stop*/
    struct timer_list   timer;  /* polling timer */
    atomic_t            trace;

    struct early_suspend    early_drv;
    atomic_t                early_suspend;
    //struct gyro_drv_obj    drv_obj;
    struct gyro_data       drv_data;
    struct gyro_control_path   gyro_ctl;
    struct gyro_data_path   gyro_data;
    bool            is_active_nodata;        // Active, but HAL don't need data sensor. such as orientation need
    bool            is_active_data;        // Active and HAL need data .
    bool is_first_data_after_enable;
    bool is_polling_run;
    bool is_batch_enable;
};

//driver API for internal
//extern int gyro_enable_nodata(int enable);
//extern int gyro_attach(struct gyro_drv_obj *obj);
//driver API for third party vendor

//for auto detect
extern int gyro_driver_add(struct gyro_init_info* obj) ;
extern int gyro_data_report(int x, int y, int z,int status);
extern int gyro_register_control_path(struct gyro_control_path *ctl);
extern int gyro_register_data_path(struct gyro_data_path *data);
#endif
