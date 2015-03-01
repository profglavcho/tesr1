#include <linux/types.h>
#include <mach/mt_pm_ldo.h>
#include <cust_gyro.h>

/*---------------------------------------------------------------------------*/
static struct gyro_hw cust_gyro_hw = {
    .addr =0x68,
    .i2c_num = 2,
    .direction = 2,
    .power_id = MT65XX_POWER_NONE,  /*!< LDO is not used */
    .power_vol= VOL_DEFAULT,        /*!< LDO is not used */
    .firlen = 0,                   /*!< don't enable low pass fileter */
    .is_batch_supported = false,
};
/*---------------------------------------------------------------------------*/
struct gyro_hw* mpu3050_get_cust_gyro_hw(void)
{
    return &cust_gyro_hw;
}
