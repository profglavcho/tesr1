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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   mt9d115mipi_Sensor.h
 *
 * Project:
 * --------
 *   YUSU
 *
 * Description:
 * ------------
 *   Header file of Sensor driver
 *
 *
 * Author:
 * -------
 *   Guangye Yang (mtk70662)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:$
 * $Modtime:$
 * $Log:$
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MT9D115MIPI_SENSOR_H
#define _MT9D115MIPI_SENSOR_H

typedef enum group_enum {
    PRE_GAIN=0,
    CMMCLK_CURRENT,
    FRAME_RATE_LIMITATION,
    REGISTER_EDITOR,
    GROUP_TOTAL_NUMS
} FACTORY_GROUP_ENUM;


#define ENGINEER_START_ADDR 10
#define FACTORY_START_ADDR 0


typedef enum register_index
{
	SENSOR_BASEGAIN=FACTORY_START_ADDR,
	PRE_GAIN_R_INDEX,
	PRE_GAIN_Gr_INDEX,
	PRE_GAIN_Gb_INDEX,
	PRE_GAIN_B_INDEX,
	FACTORY_END_ADDR
} FACTORY_REGISTER_INDEX;

typedef enum engineer_index
{
    CMMCLK_CURRENT_INDEX=ENGINEER_START_ADDR,
    ENGINEER_END
} FACTORY_ENGINEER_INDEX;



typedef struct
{
    SENSOR_REG_STRUCT	Reg[ENGINEER_END];
    SENSOR_REG_STRUCT	CCT[FACTORY_END_ADDR];
} SENSOR_DATA_STRUCT, *PSENSOR_DATA_STRUCT;


#define CURRENT_MAIN_SENSOR                MT9D115MIPI_MICRON


#define MT9D115MIPI_WRITE_ID_1	0x78
#define MT9D115MIPI_READ_ID_1	0x79
#define MT9D115MIPI_WRITE_ID_2	0x7A
#define MT9D115MIPI_READ_ID_2	0x7B


#define MT9D115MIPI_IMAGE_SENSOR_FULL_HACTIVE		1608
#define MT9D115MIPI_IMAGE_SENSOR_FULL_VACTIVE		1208
#define MT9D115MIPI_IMAGE_SENSOR_PV_HACTIVE			808
#define MT9D115MIPI_IMAGE_SENSOR_PV_VACTIVE			608
#define MT9D115MIPI_IMAGE_SENSOR_VIDEO_HACTIVE		1288
#define MT9D115MIPI_IMAGE_SENSOR_VIDEO_VACTIVE		728 

#define MT9D115MIPI_IMAGE_SENSOR_3D_PV_HACTIVE			1288
#define MT9D115MIPI_IMAGE_SENSOR_3D_PV_VACTIVE			728
#define MT9D115MIPI_IMAGE_SENSOR_3D_FULL_HACTIVE		1608
#define MT9D115MIPI_IMAGE_SENSOR_3D_FULL_VACTIVE		1208



#define MT9D115MIPI_FULL_START_X					2
#define MT9D115MIPI_FULL_START_Y					2
#define MT9D115MIPI_IMAGE_SENSOR_FULL_WIDTH			(MT9D115MIPI_IMAGE_SENSOR_FULL_HACTIVE - 8)  //1600
#define MT9D115MIPI_IMAGE_SENSOR_FULL_HEIGHT		(MT9D115MIPI_IMAGE_SENSOR_FULL_VACTIVE - 8)  //1200

#define MT9D115MIPI_PV_START_X						2
#define MT9D115MIPI_PV_START_Y						2
#define MT9D115MIPI_IMAGE_SENSOR_PV_WIDTH			(MT9D115MIPI_IMAGE_SENSOR_PV_HACTIVE - 8)	//800
#define MT9D115MIPI_IMAGE_SENSOR_PV_HEIGHT			(MT9D115MIPI_IMAGE_SENSOR_PV_VACTIVE - 8)	//600

#define MT9D115MIPI_VIDEO_START_X						2
#define MT9D115MIPI_VIDEO_START_Y						2
#define MT9D115MIPI_IMAGE_SENSOR_VIDEO_WIDTH			(MT9D115MIPI_IMAGE_SENSOR_VIDEO_HACTIVE - 8)	//800
#define MT9D115MIPI_IMAGE_SENSOR_VIDEO_HEIGHT			(MT9D115MIPI_IMAGE_SENSOR_VIDEO_VACTIVE - 8)	//600


#define MT9D115MIPI_3D_FULL_START_X					2
#define MT9D115MIPI_3D_FULL_START_Y					2
#define MT9D115MIPI_IMAGE_SENSOR_3D_FULL_WIDTH			(MT9D115MIPI_IMAGE_SENSOR_3D_FULL_HACTIVE - 8)  //1600
#define MT9D115MIPI_IMAGE_SENSOR_3D_FULL_HEIGHT		    (MT9D115MIPI_IMAGE_SENSOR_3D_FULL_VACTIVE - 8)  //1200

#define MT9D115MIPI_3D_PV_START_X						2
#define MT9D115MIPI_3D_PV_START_Y						2
#define MT9D115MIPI_IMAGE_SENSOR_3D_PV_WIDTH			(MT9D115MIPI_IMAGE_SENSOR_3D_PV_HACTIVE - 8)	//800
#define MT9D115MIPI_IMAGE_SENSOR_3D_PV_HEIGHT			(MT9D115MIPI_IMAGE_SENSOR_3D_PV_VACTIVE - 8)	//600



#define	MT9D115MIPI_IMAGE_SENSOR_FULL_HBLANKING		549
#define MT9D115MIPI_IMAGE_SENSOR_FULL_VBLANKING		90
#define	MT9D115MIPI_IMAGE_SENSOR_PV_HBLANKING		1195
#define MT9D115MIPI_IMAGE_SENSOR_PV_VBLANKING		92
#define	MT9D115MIPI_IMAGE_SENSOR_VIDEO_HBLANKING	434
#define MT9D115MIPI_IMAGE_SENSOR_VIDEO_VBLANKING	85


#define	MT9D115MIPI_IMAGE_SENSOR_3D_FULL_HBLANKING		549
#define MT9D115MIPI_IMAGE_SENSOR_3D_FULL_VBLANKING		90
#define	MT9D115MIPI_IMAGE_SENSOR_3D_PV_HBLANKING		434
#define MT9D115MIPI_IMAGE_SENSOR_3D_PV_VBLANKING		85


#define MT9D115MIPI_FULL_PERIOD_PIXEL_NUMS			(MT9D115MIPI_IMAGE_SENSOR_FULL_HACTIVE + MT9D115MIPI_IMAGE_SENSOR_FULL_HBLANKING)  
#define MT9D115MIPI_FULL_PERIOD_LINE_NUMS			(MT9D115MIPI_IMAGE_SENSOR_FULL_VACTIVE + MT9D115MIPI_IMAGE_SENSOR_FULL_VBLANKING)  
#define MT9D115MIPI_PV_PERIOD_PIXEL_NUMS			(MT9D115MIPI_IMAGE_SENSOR_PV_HACTIVE + MT9D115MIPI_IMAGE_SENSOR_PV_HBLANKING)	 
#define MT9D115MIPI_PV_PERIOD_LINE_NUMS				(MT9D115MIPI_IMAGE_SENSOR_PV_VACTIVE + MT9D115MIPI_IMAGE_SENSOR_PV_VBLANKING)    
#define MT9D115MIPI_VIDEO_PERIOD_PIXEL_NUMS			(MT9D115MIPI_IMAGE_SENSOR_VIDEO_HACTIVE + MT9D115MIPI_IMAGE_SENSOR_VIDEO_HBLANKING)	 
#define MT9D115MIPI_VIDEO_PERIOD_LINE_NUMS				(MT9D115MIPI_IMAGE_SENSOR_VIDEO_VACTIVE + MT9D115MIPI_IMAGE_SENSOR_VIDEO_VBLANKING)    


#define MT9D115MIPI_3D_FULL_PERIOD_PIXEL_NUMS			(MT9D115MIPI_IMAGE_SENSOR_3D_FULL_HACTIVE + MT9D115MIPI_IMAGE_SENSOR_3D_FULL_HBLANKING)  
#define MT9D115MIPI_3D_FULL_PERIOD_LINE_NUMS			(MT9D115MIPI_IMAGE_SENSOR_3D_FULL_VACTIVE + MT9D115MIPI_IMAGE_SENSOR_3D_FULL_VBLANKING)  
#define MT9D115MIPI_3D_PV_PERIOD_PIXEL_NUMS			(MT9D115MIPI_IMAGE_SENSOR_3D_PV_HACTIVE + MT9D115MIPI_IMAGE_SENSOR_3D_PV_HBLANKING)	 
#define MT9D115MIPI_3D_PV_PERIOD_LINE_NUMS				(MT9D115MIPI_IMAGE_SENSOR_3D_PV_VACTIVE + MT9D115MIPI_IMAGE_SENSOR_3D_PV_VBLANKING)


#define MT9D115MIPI_FRAME_RATE_UNIT		10
#define MT9D115MIPI_set_frame_rate(a) 	(a * MT9D115MIPI_FRAME_RATE_UNIT)
#define MT9D115MIPI_1X_ZOOM_IN_CAPTURE_FRAME	9



/* SENSOR PRIVATE STRUCT */
struct MT9D115MIPI_SENSOR_STRUCT
{
	kal_uint8 i2c_write_id;
	kal_uint8 i2c_read_id;
	kal_uint16 preview_vt_clk;
	kal_uint16 capture_vt_clk;
	kal_uint16 video_vt_clk;
	kal_uint16 preview_3d_vt_clk;
	kal_uint16 capture_3d_vt_clk;
	kal_uint16 video_3d_vt_clk;	
};


/* FRAME RATE */
#define MT9D115MIPI_FPS(x)                          ((kal_uint32)(10 * (x)))

#endif /* _MT9D115MIPI_SENSOR_H */

