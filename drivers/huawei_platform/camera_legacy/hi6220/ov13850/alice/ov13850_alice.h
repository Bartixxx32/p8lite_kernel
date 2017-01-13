/*
 *  ov13850 camera driver head file
 *
 *  Author: 	Willianm Lee
 *  Date:  	2014/05/04
 *  Version:	1.0
 *  History:	2014/05/04      Frist add driver for ov13850
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _OV13850_ALICE_H_
#define _OV13850_ALICE_H_


#include "../isp/k3_isp_io.h"

static const struct _sensor_reg_t ov13850_alice_init_regs[] = {
	/* Global Setting */
	//{0x0103, 0x01} , //software reset, set before init settings
	{0x0300, 0x01}, 
	{0x0301, 0x00},
	{0x0302, 0x28},
	{0x0303, 0x00}, 
	{0x030a, 0x00}, 
	{0x300f, 0x11}, 
	{0x3010, 0x01}, 
	{0x3011, 0x76}, 
	{0x3012, 0x41}, 
	{0x3013, 0x12}, 
	{0x3014, 0x11}, 
	{0x301f, 0x03}, 
	{0x3106, 0x00}, 
	{0x3210, 0x47}, 
	{0x3500, 0x00}, 
	{0x3501, 0x60}, 
	{0x3502, 0x00}, 
	{0x3503, 0x03}, // gain N+2, expo N+2
	{0x3506, 0x00}, 
	{0x3507, 0x02}, 
	{0x3508, 0x00}, 
	{0x350a, 0x00}, 
	{0x350b, 0x10},// 0x80->0x10
	{0x350e, 0x00}, 
	{0x350f, 0x10}, 
	{0x351a, 0x00}, 
	{0x351b, 0x10}, 
	{0x351c, 0x00}, 
	{0x351d, 0x20}, 
	{0x351e, 0x00}, 
	{0x351f, 0x40}, 
	{0x3520, 0x00}, 
	{0x3521, 0x80}, 
	{0x3600, 0xc0}, 
	{0x3601, 0xfc}, 
	{0x3602, 0x02}, 
	{0x3603, 0x78}, 
	{0x3604, 0xb1}, 
	{0x3605, 0xb5}, 
	{0x3606, 0x73}, 
	{0x3607, 0x07}, 
	{0x3609, 0x40}, 
	{0x360a, 0x30}, 
	{0x360b, 0x91},
    {0x360c, 0x09}, //decrease the noise in low light
	{0x360f, 0x02}, 
	{0x3611, 0x10}, 
	{0x3612, 0x27}, 
	{0x3613, 0x33}, 
	{0x3615, 0x0c}, 
	{0x3616, 0x0e}, 
	{0x3641, 0x02}, 
	{0x3660, 0x82}, 
	{0x3668, 0x54}, 
	{0x3669, 0x00}, 
	{0x366a, 0x3f}, 
	{0x3667, 0xa0}, 
	{0x3702, 0x40}, 
	{0x3703, 0x44}, 
	{0x3704, 0x2c}, 
	{0x3705, 0x01}, 
	{0x3706, 0x15}, 
	{0x3707, 0x44}, 
	{0x3708, 0x3c}, 
	{0x3709, 0x1f}, 
	{0x370a, 0x27}, 
	{0x370b, 0x3c}, 
	{0x3720, 0x55}, 
	{0x3722, 0x84}, 
	{0x3728, 0x40}, 
	{0x372a, 0x00}, 
	{0x372b, 0x02}, 
	{0x372e, 0x22}, 
	{0x372f, 0x90}, 
	{0x3730, 0x00}, 
	{0x3731, 0x00}, 
	{0x3732, 0x00}, 
	{0x3733, 0x00}, 
	{0x3710, 0x28}, 
	{0x3716, 0x03}, 
	{0x3718, 0x10}, 
    {0x3719, 0x0c}, //decrease the noise in low light
	{0x371a, 0x08}, 
	{0x371c, 0xfc}, 
	{0x3748, 0x00}, 
	{0x3760, 0x13}, 
	{0x3761, 0x33}, 
	{0x3762, 0x86}, 
	{0x3763, 0x16}, 
	{0x3767, 0x24}, 
	{0x3768, 0x06}, 
	{0x3769, 0x45}, 
	{0x376c, 0x23}, 
	{0x376f, 0x80}, 
	{0x3773, 0x06}, 
	{0x3d84, 0x00}, //  OTP program disable
	{0x3d85, 0x17}, //  OTP power up load data enable, power load setting enable, software load setting enable
	{0x3d8c, 0x73}, 
	{0x3d8d, 0xbf}, 
	{0x3820, 0x06},
	{0x3821, 0x02},
	{0x3823, 0x00}, 
	{0x3826, 0x00}, 
	{0x3827, 0x02}, 
	{0x3834, 0x00}, 
	{0x3835, 0x1c}, 
	{0x3836, 0x08}, 
	{0x3837, 0x02}, 
	{0x4000, 0xf1}, //  BLC offset trig en, format change trig en, gain trig en, exp trig en, median en
	{0x4001, 0x00}, 
	{0x400b, 0x0c}, 
	{0x4011, 0x00}, 
	{0x401a, 0x00}, 
	{0x401b, 0x00}, 
	{0x401c, 0x00}, 
	{0x401d, 0x00}, 
	{0x4020, 0x00}, 
	{0x4021, 0xe4}, 
	{0x4022, 0x04}, 
	{0x4023, 0xd7}, 
	{0x4024, 0x05}, 
	{0x4025, 0xbc}, 
	{0x4026, 0x05}, 
	{0x4027, 0xbf}, 
	{0x4028, 0x00}, 
	{0x4029, 0x02}, 
	{0x402a, 0x04}, 
	{0x402b, 0x08}, 
	{0x402c, 0x02}, 
	{0x402d, 0x02}, 
	{0x402e, 0x0c}, 
	{0x402f, 0x08}, 
	{0x403d, 0x2c}, 
	{0x403f, 0x7f}, 
	{0x4041, 0x07}, 
	{0x4500, 0x82}, 
	{0x4501, 0x3c}, 
	{0x458b, 0x00}, 
	{0x459c, 0x00}, 
	{0x459d, 0x00}, 
	{0x459e, 0x00}, 
	{0x4601, 0x81}, 
	{0x4602, 0x22}, 
	{0x4603, 0x01}, 
	{0x4837, 0x19}, 
	{0x4d00, 0x04}, 
	{0x4d01, 0x42}, 
	{0x4d02, 0xd1}, 
	{0x4d03, 0x90}, 
	{0x4d04, 0x66}, 
	{0x4d05, 0x65}, 
	{0x4d0b, 0x00}, 
	{0x5000, 0x0e}, 
	{0x5001, 0x09},//01-->09 open digital gain
	{0x5002, 0x07}, 
	{0x5013, 0x40}, 
	{0x501c, 0x00}, 
	{0x501d, 0x10}, 
	{0x510f, 0xfc}, 
	{0x5110, 0xf0}, 
	{0x5111, 0x10}, 
	{0x536d, 0x02}, 
	{0x536e, 0x67}, 
	{0x536f, 0x01}, 
	{0x5370, 0x4c}, 
	{0x5400, 0x00}, 
	{0x5400, 0x00}, 
	{0x5401, 0x61}, 
	{0x5402, 0x00}, 
	{0x5403, 0x00}, 
	{0x5404, 0x00}, 
	{0x5405, 0x40}, 
	{0x540c, 0x05}, 
	{0x5500, 0x03}, //open digital gain
	{0x5501, 0x00}, 
	{0x5b00, 0x00}, 
	{0x5b01, 0x00}, 
	{0x5b02, 0x01}, 
	{0x5b03, 0xff}, 
	{0x5b04, 0x02}, 
	{0x5b05, 0x6c}, 
	{0x5b09, 0x02}, 
	{0x5e00, 0x00}, //  test pattern disable
	{0x5e10, 0x1c}, //  ISP test disable
	{0x0100, 0x00}, // standby
};
static const struct _sensor_reg_t ov13850_alice_framesize_quater[] = {
	//@@Raw 10bit RES_2080x1560_30fps_514.25Mbps/lane
	//XCLK = 20.57M, sysclk = 63M, MIPIBitRate = 514.25Mbps/lane
	//HTS = 4736, VTS = 1728
	{0x0100, 0x00}, //software standby
	{0x0300, 0x02},
	{0x0302, 0x32},
	{0x0303, 0x00},
	//{0x3501, 0x60}, 
	{0x3612, 0x27}, 
	{0x3614, 0x31},
	{0x370a, 0x27}, 
	{0x372a, 0x00}, 
	{0x372f, 0x90}, 
	{0x3800, 0x00}, 
	{0x3801, 0x08}, //H crop start L
	{0x3802, 0x00}, 
	{0x3803, 0x04}, //V crop start L
	{0x3804, 0x10}, 
	{0x3805, 0x97}, //H crop end L
	{0x3806, 0x0c}, 
	{0x3807, 0x4b}, //V crop end L
	{0x3808, 0x08}, //H output size H
	{0x3809, 0x20}, //H output size L
	{0x380a, 0x06}, //V output size H
	{0x380b, 0x18}, // V output size L
	{0x380c, 0x12}, // HTS H
	{0x380d, 0x80}, // HTS L
	{0x380e, 0x06}, // VTS H
	{0x380f, 0xfa}, // VTS L
	{0x3810, 0x00}, 
	{0x3811, 0x14},
	{0x3812, 0x00}, //V win off	
	{0x3813, 0x06}, 
	{0x3814, 0x31}, // H inc
	{0x3815, 0x31}, // V inc
	{0x3820, 0x06, 0x04}, // V flip on, V bin on
	{0x3821, 0x02, 0x04}, 
	{0x3836, 0x08}, 
	{0x3837, 0x02}, 
	{0x4020, 0x00}, 
	{0x4021, 0xe4}, 
	{0x4022, 0x04}, 
	{0x4023, 0xd7}, 
	{0x4024, 0x05}, 
	{0x4025, 0xbc}, 
	{0x4026, 0x05}, 
	{0x4027, 0xbf}, 
	{0x4501, 0x3c}, 
	{0x4601, 0x82}, 
	{0x4603, 0x01}, // VFIFO
	{0x4837, 0x1f}, // MIPI global timing
	{0x5401, 0x61}, 
	{0x5405, 0x40}, 

	{0x5101, 0x02},//DPC parameter
	{0x5102, 0x01},
	{0x5103, 0x01},
	{0x5104, 0x02},
	{0x5105, 0x01},
	{0x5106, 0x01},
	{0x5107, 0x00},
	{0x5108, 0x00},
	{0x5109, 0x00},
	{0x510d, 0xfe},
	{0x510e, 0x0c},
	{0x510f, 0xfc},
	{0x5110, 0xf0},
	{0x5111, 0x10},
	{0x5112, 0x74},
	{0x5113, 0x06},
	{0x5116, 0x00}, 

	{0x0100, 0x01}, // wake up, streaming
};

static const struct _sensor_reg_t ov13850_alice_framesize_fullsize_nonzsl[] = {
#if 0 //10fps
//@@Raw 10bit RES_4160x3120_10fps_500Mbps
	//XCLK = 20.57M, sysclk = 61.71M, MIPIBitRate = 514.25Mbps/lane
	//HTS = 7200, VTS = 3328
	{0x0100, 0x00}, //software standby
	{0x0300, 0x00},
	{0x0302, 0x19},
	{0x0303, 0x00},
	//{0x3501, 0xc0}, 
	{0x3612, 0x27}, 
	{0x3614, 0x30},
	{0x370a, 0x24}, 
	{0x372a, 0x04}, 
	{0x372f, 0xa0}, 
	{0x3800, 0x00}, 
	{0x3801, 0x14}, //H crop start L
	{0x3802, 0x00}, 
	{0x3803, 0x0c}, //V crop start L
	{0x3804, 0x10}, 
	{0x3805, 0x8b}, //H crop end L
	{0x3806, 0x0c}, 
	{0x3807, 0x43}, //V crop end L
	{0x3808, 0x10}, //H output size H
	{0x3809, 0x40}, //H output size L
	{0x380a, 0x0c}, //V output size H
	{0x380b, 0x30}, //V output size L
	{0x380c, 0x1c},
	{0x380d, 0x20}, 
	{0x380e, 0x0d},
	{0x380f, 0x00}, 
	{0x3810, 0x00}, 
	{0x3811, 0x1c}, 
	{0x3812, 0x00}, 
	{0x3813, 0x04}, 
	{0x3814, 0x11}, //H inc
	{0x3815, 0x11},  //V inc
	{0x3820, 0x04, 0x04}, //V flip off, V bin off
	{0x3821, 0x00, 0x04}, //H mirror on, H bin off
	{0x3836, 0x04}, 
	{0x3837, 0x01}, 
	{0x4020, 0x02}, 
	{0x4021, 0x3C}, 
	{0x4022, 0x0E}, 
	{0x4023, 0x37}, 
	{0x4024, 0x0F}, 
	{0x4025, 0x1C}, 
	{0x4026, 0x0F}, 
	{0x4027, 0x1F}, 
	{0x4501, 0x38}, 
	{0x4601, 0x04}, 
	{0x4603, 0x01}, //VFIFO
	{0x4837, 0x1f},//MIPI global timing
	{0x5401, 0x71}, 
	{0x5405, 0x80}, 

	{0x0100, 0x01},
#else //13fps
//@@Raw 10bit RES_4160x3120_13fps_500Mbps
//XCLK = 20.57M, sysclk = 61.71M, MIPIBitRate = 514.25Mbps/lane
//HTS = 5704, VTS = 3328
{0x0100, 0x00},//software standby
{0x0300, 0x00},
{0x0302, 0x19},
{0x0303, 0x00},
//{0x3501, 0xc0},
{0x3612, 0x27},
{0x3614, 0x30},
{0x370a, 0x24},
{0x372a, 0x04},
{0x372f, 0xa0},
{0x3800, 0x00},
{0x3801, 0x14},//H crop start L
{0x3802, 0x00},
{0x3803, 0x0c},//V crop start L
{0x3804, 0x10},   
{0x3805, 0x8b},//H crop end L
{0x3806, 0x0c},
{0x3807, 0x43},//V crop end L
{0x3808, 0x10},//H output size H
{0x3809, 0x40},//H output size L
{0x380a, 0x0c},//V output size H
{0x380b, 0x30},//V output size L
{0x380c, 0x16},//1c
{0x380d, 0x48},//20
{0x380e, 0x0d},
{0x380f, 0x00},
{0x3810, 0x00},
{0x3811, 0x1c},
{0x3812, 0x00},
{0x3813, 0x04},
{0x3814, 0x11},//H inc
{0x3815, 0x11},//V inc
{0x3820, 0x04, 0x04}, //V flip off, V bin off
{0x3821, 0x00, 0x04}, //H mirror on, H bin off
{0x3836, 0x04},
{0x3837, 0x01},
{0x4020, 0x02},
{0x4021, 0x3C},
{0x4022, 0x0E},
{0x4023, 0x37},
{0x4024, 0x0F},
{0x4025, 0x1C},
{0x4026, 0x0F},
{0x4027, 0x1F},
{0x4501, 0x38},
{0x4601, 0x04},
{0x4603, 0x01},//VFIFO
{0x4837, 0x1f},//MIPI global timing
{0x5401, 0x71},
{0x5405, 0x80},

{0x5101, 0x02},//DPC parameter
{0x5102, 0x01},
{0x5103, 0x01},
{0x5104, 0x02},
{0x5105, 0x01},
{0x5106, 0x01},
{0x5107, 0x00},
{0x5108, 0x00},
{0x5109, 0x00},
{0x510d, 0xfe},
{0x510e, 0x0c},
{0x510f, 0xfc},
{0x5110, 0xf0},
{0x5111, 0x10},
{0x5112, 0x74},
{0x5113, 0x06},
{0x5116, 0x00},

{0x0100, 0x01}
#endif
};

static const struct _sensor_reg_t ov13850_alice_framesize_fullsize_nonzsl_long_expo[] = {
//@@Raw 10bit RES_4160x3120_3.02fps
//XCLK = 20.57M, sysclk = 12.08M, MIPIBitRate = 114.28Mbps/lane
{0x0100, 0x00},//software standby
{0x0300, 0x00},
{0x0302, 0x32},
{0x0303, 0x08},
{0x3612, 0x7f},
{0x3614, 0x2f},
{0x370a, 0x24},
{0x372a, 0x04},
{0x372f, 0xa0},
{0x3800, 0x00},
{0x3801, 0x14},//H crop start L
{0x3802, 0x00},
{0x3803, 0x0c},//V crop start L
{0x3804, 0x10},
{0x3805, 0x8b},//H crop end L
{0x3806, 0x0c},
{0x3807, 0x43},//V crop end L
{0x3808, 0x10},//H output size H
{0x3809, 0x40},//H output size L
{0x380a, 0x0c},//V output size H
{0x380b, 0x30},//V output size L
{0x380c, 0x12},
{0x380d, 0xc0},
{0x380e, 0x0d},
{0x380f, 0x00},
{0x3810, 0x00},
{0x3811, 0x1c},
{0x3812, 0x00},
{0x3813, 0x04},
{0x3814, 0x11},//H inc
{0x3815, 0x11},//V inc
{0x3820, 0x04, 0x04}, //V flip off, V bin off
{0x3821, 0x00, 0x04}, //H mirror on, H bin off
{0x3836, 0x04},
{0x3837, 0x01},
{0x4020, 0x02},
{0x4021, 0x3C},
{0x4022, 0x0E},
{0x4023, 0x37},
{0x4024, 0x0F},
{0x4025, 0x1C},
{0x4026, 0x0F},
{0x4027, 0x1F},
{0x4501, 0x38},
{0x4601, 0x04},
{0x4603, 0x01},//VFIFO
{0x4837, 0x8c},//MIPI global timing
{0x5401, 0x71},
{0x5405, 0x80},

{0x5101, 0x02},//DPC parameter
{0x5102, 0x01},
{0x5103, 0x01},
{0x5104, 0x02},
{0x5105, 0x01},
{0x5106, 0x01},
{0x5107, 0x00},
{0x5108, 0x00},
{0x5109, 0x00},
{0x510d, 0xfe},
{0x510e, 0x0c},
{0x510f, 0xfc},
{0x5110, 0xf0},
{0x5111, 0x10},
{0x5112, 0x74},
{0x5113, 0x06},
{0x5116, 0x00},

{0x0100, 0x01}
};

//@@Raw 10bit RES_4160x3120_1.129fps
//XCLK = 20.57M, sysclk = 12.08M, MIPIBitRate = 114.28Mbps/lane
static const struct _sensor_reg_t ov13850_alice_framesize_fullsize_nonzsl_8S_expo[] ={
{0x0100, 0x00},//software standby
{0x0300, 0x00},
{0x0302, 0x32},
{0x0303, 0x08},
{0x3612, 0x7f},
{0x3614, 0x2f},
{0x370a, 0x24},
{0x372a, 0x04},
{0x372f, 0xa0},
{0x3800, 0x00},
{0x3801, 0x14},//H crop start L
{0x3802, 0x00},
{0x3803, 0x0c},//V crop start L
{0x3804, 0x10},
{0x3805, 0x8b},//H crop end L
{0x3806, 0x0c},
{0x3807, 0x43},//V crop end L
{0x3808, 0x10},//H output size H
{0x3809, 0x40},//H output size L
{0x380a, 0x0c},//V output size H
{0x380b, 0x30},//V output size L
{0x380c, 0x32},
{0x380d, 0x00},
{0x380e, 0x0d},
{0x380f, 0x10},
{0x3810, 0x00},
{0x3811, 0x1c},
{0x3812, 0x00},
{0x3813, 0x04},
{0x3814, 0x11},//H inc
{0x3815, 0x11},//V inc
{0x3820, 0x04, 0x04}, //V flip off, V bin off
{0x3821, 0x00, 0x04}, //H mirror on, H bin off
{0x3836, 0x04},
{0x3837, 0x01},
{0x4020, 0x02},
{0x4021, 0x3C},
{0x4022, 0x0E},
{0x4023, 0x37},
{0x4024, 0x0F},
{0x4025, 0x1C},
{0x4026, 0x0F},
{0x4027, 0x1F},
{0x4501, 0x38},
{0x4601, 0x04},
{0x4603, 0x01},//VFIFO
{0x4837, 0x8c},//MIPI global timing
{0x5401, 0x71},
{0x5405, 0x80},

{0x5101, 0x00},//DPC parameter
{0x5102, 0x00},
{0x5103, 0x00},
{0x5104, 0x00},
{0x5105, 0x00},
{0x5106, 0x00},
{0x5107, 0x00},
{0x5108, 0x00},
{0x5109, 0x00},
{0x510d, 0xff},
{0x510e, 0x0f},
{0x510f, 0xff},
{0x5110, 0xff},
{0x5111, 0x15},
{0x5112, 0x77},
{0x5113, 0x07},
{0x5116, 0x3f},

{0x0100, 0x01}

};


static sensor_setting_t ov13850_alice_init_array[] = {
    {ov13850_alice_init_regs, ARRAY_SIZE(ov13850_alice_init_regs)},
};

static framesize_s ov13850_alice_framesizes[] = {
    //2080x1560, 30fps
    {0, 0, 2080, 1560, 4736, 1786, 30, 30, 0x214, 0x1bb, 0x100, VIEW_FULL, RESOLUTION_4_3, false, false,ECGC_TYPE_MAX, {ov13850_alice_framesize_quater, ARRAY_SIZE(ov13850_alice_framesize_quater)}, CLK_500M, 33417, 253754880},
    //4160x3120, 10fps
    //{0, 0, 4160, 3120, 7200, 3328, 10, 10, 0x156, 0x11e, 0xa8, VIEW_FULL, RESOLUTION_4_3, false, false, ECGC_TYPE_NORMAL_BSHUTTER_SHORT,{ov13850_framesize_fullsize_nonzsl, ARRAY_SIZE(ov13850_framesize_fullsize_nonzsl)}, CLK_500M},
    //4160x3120, 13fps
    {0, 0, 4160, 3120, 5704, 3328, 13, 13, 0x1B0, 0x168, 0xD0, VIEW_FULL, RESOLUTION_4_3, false, false, ECGC_TYPE_NORMAL_BSHUTTER_SHORT,{ov13850_alice_framesize_fullsize_nonzsl, ARRAY_SIZE(ov13850_alice_framesize_fullsize_nonzsl)}, CLK_500M, 76718, 246777856},
    //4160x3120, 3.02fps long expo
    {0, 0, 4160, 3120, 4800, 3328, 3, 3, 0x65, 0x54, 0xD0, VIEW_FULL, RESOLUTION_4_3, false, false, ECGC_TYPE_BSHUTTER_LONG,{ov13850_alice_framesize_fullsize_nonzsl_long_expo, ARRAY_SIZE(ov13850_alice_framesize_fullsize_nonzsl_long_expo)}, CLK_150M, 3296680, 48242688},
    //4160x3120, 1.129fps long expo
    {0, 0, 4160, 3120, 12800, 3344, 1, 1, 0x26, 0x1f, 0x12, VIEW_FULL, RESOLUTION_4_3, false, false, ECGC_TYPE_MAX,{ov13850_alice_framesize_fullsize_nonzsl_8S_expo, ARRAY_SIZE(ov13850_alice_framesize_fullsize_nonzsl_8S_expo)}, CLK_150M, 8001009, 48324813},

};

#endif /* _OV13850_ALICE_H_ */
/************************** END ***************************/
