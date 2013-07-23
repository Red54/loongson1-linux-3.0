/*
 * Driver for OV7675 from OV
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */
#ifndef __GC0308_H__
#define __GC0308_H__

struct gc0308_reg {
	unsigned char addr;
	unsigned char val;
};

struct gc0308_regset_type {
	unsigned char *regset;
	int len;
};

/*
 * Macro
 */
#define REGSET_LENGTH(x)	(sizeof(x)/sizeof(gc0308_reg))

/*
 * User defined commands
 */
/* S/W defined features for tune */
#define REG_DELAY	0xFF00	/* in ms */
#define REG_CMD		0xFFFF	/* Followed by command */

/* Following order should not be changed */
enum image_size_gc0308 {
	/* This SoC supports upto UXGA (1600*1200) */
#if 0
	QQVGA,	/* 160*120*/
	QCIF,	/* 176*144 */
	QVGA,	/* 320*240 */
	CIF,	/* 352*288 */
#endif
	VGA,	/* 640*480 */
#if 0
	SVGA,	/* 800*600 */

	HD720P,	/* 1280*720 */
	SXGA,	/* 1280*1024 */
	UXGA,	/* 1600*1200 */
#endif
};

/*
 * Following values describe controls of camera
 * in user aspect and must be match with index of ov7675_regset[]
 * These values indicates each controls and should be used
 * to control each control
 */
enum gc0308_control {
	GC0308_INIT,
	GC0308_EV,
	GC0308_AWB,
	GC0308_MWB,
	GC0308_EFFECT,
	GC0308_CONTRAST,
	GC0308_SATURATION,
	GC0308_SHARPNESS,
};

#define GC0308_REGSET(x)	{	\
	.regset = x,			\
	.len = sizeof(x)/sizeof(gc0308_reg),}


#ifdef CONFIG_CAMERA_CONTROLLED_BY_ARM
/*
 * User tuned register setting values
 */
#if 0
static unsigned char gc0308_init_reg[][2] = {  //  2010-12-16 kim 
{0xfe,0x00},
//{0x28,0x76},
{0x0f,0x00},
{0x01,0x6a},
{0x02,0x70},
{0xe2,0x00},
{0xe3,0x96},
{0xe4,0x02},
{0xe5,0x58},
{0xe6,0x02},
{0xe7,0xee},
{0xe8,0x03},
{0xe9,0x84},
{0xea,0x0e},
{0xeb,0xa6},
{0xec,0x20},
{0x05,0x00},
{0x06,0x00},
{0x07,0x00},
{0x08,0x00},
{0x09,0x01},
{0x0a,0xe8},
{0x0b,0x02},
{0x0c,0x88},
{0x0d,0x02},
{0x0e,0x02},
{0x10,0x26},
{0x11,0x0d},
{0x12,0x2a},
{0x13,0x00},
{0x14,0x11},// urbetter
{0x15,0x0a},
{0x16,0x05},
{0x17,0x01},
{0x18,0x44},
{0x19,0x44},
{0x1a,0x2a},
{0x1b,0x00},
{0x1c,0x49},
{0x1d,0x9a},
{0x1e,0x61},
{0x1f,0x16},
{0x20,0xff},
{0x21,0xfa},
{0x22,0x57},
{0x24,0xa2},//0xa0},
{0x25,0x0f},
{0x26,0x02},//0x03}, // 0x01
{0x2f,0x01},
{0x30,0xf7},
{0x31,0x50},
{0x32,0x00},
{0x39,0x04},
{0x3a,0x20},
{0x3b,0x20},
{0x3c,0x00},
{0x3d,0x00},
{0x3e,0x00},
{0x3f,0x00},
{0x50,0x16}, // 0x14
{0x53,0x80},
{0x54,0x87},
{0x55,0x87},
{0x56,0x80},
{0x8b,0x10},
{0x8c,0x10},
{0x8d,0x10},
{0x8e,0x10},
{0x8f,0x10},
{0x90,0x10},
{0x91,0x3c},
{0x92,0x50},
{0x5d,0x12},
{0x5e,0x1a},
{0x5f,0x24},
{0x60,0x07},
{0x61,0x15},
{0x62,0x0f}, // 0x08
{0x64,0x01},  // 0x03
{0x66,0xe8},
{0x67,0x86},
{0x68,0xa2},
{0x69,0x18},
{0x6a,0x0f},
{0x6b,0x00},
{0x6c,0x5f},
{0x6d,0x8f},
{0x6e,0x55},
{0x6f,0x38},
{0x70,0x15},
{0x71,0x33},
{0x72,0xdc},
{0x73,0x80},
{0x74,0x02},
{0x75,0x3f},
{0x76,0x02},
{0x77,0x57}, // 0x47
{0x78,0x88},
{0x79,0x81},
{0x7a,0x81},
{0x7b,0x22},
{0x7c,0xff},
{0x93,0x46},
{0x94,0x00},
{0x95,0x03},
{0x96,0xd0},
{0x97,0x40},
{0x98,0xf0},
{0xb1,0x3c},
{0xb2,0x3c},
{0xb3,0x44}, //0x40
{0xb6,0xe0},
{0xbd,0x3C},
{0xbe,0x36},
{0xd0,0xC9},
{0xd1,0x10},
{0xd2,0x90},
{0xd3,0x88},
{0xd5,0xF2},
{0xd6,0x10},
{0xdb,0x92},
{0xdc,0xA5},
{0xdf,0x23},
{0xd9,0x00},
{0xda,0x00},
{0xe0,0x09},
{0xed,0x04},
{0xee,0xa0},
{0xef,0x40},
{0x80,0x03},
#if 0
{0x9F,0x0E},
{0xA0,0x1C},
{0xA1,0x34},
{0xA2,0x48},
{0xA3,0x5A},
{0xA4,0x6B},
{0xA5,0x7B},
{0xA6,0x95},
{0xA7,0xAB},
{0xA8,0xBF},
{0xA9,0xCE},
{0xAA,0xD9},
{0xAB,0xE4},
{0xAC,0xEC},
{0xAD,0xF7},
{0xAE,0xFD},
{0xAF,0xFF},
#elif 0
{0x9F,0x10},
{0xA0,0x20},
{0xA1,0x38},
{0xA2,0x4e},
{0xA3,0x63},
{0xA4,0x76},
{0xA5,0x87},
{0xA6,0xa2},
{0xA7,0xb8},
{0xA8,0xca},
{0xA9,0xd8},
{0xAA,0xe3},
{0xAB,0xEb},
{0xAC,0xf0},
{0xAD,0xF8},
{0xAE,0xFD},
{0xAF,0xFF},
#else
{0x9F,0x14},
{0xA0,0x28},
{0xA1,0x44},
{0xA2,0x5d},
{0xA3,0x72},
{0xA4,0x86},
{0xA5,0x95},
{0xA6,0xb1},
{0xA7,0xc6},
{0xA8,0xd5},
{0xA9,0xe1},
{0xAA,0xea},
{0xAB,0xf1},
{0xAC,0xf5},
{0xAD,0xFb},
{0xAE,0xFe},
{0xAF,0xFF},
#endif
{0xc0,0x00},
{0xc1,0x14},
{0xc2,0x21},
{0xc3,0x36},
{0xc4,0x49},
{0xc5,0x5B},
{0xc6,0x6B},
{0xc7,0x7B},
{0xc8,0x98},
{0xc9,0xB4},
{0xca,0xCE},
{0xcb,0xE8},
{0xcc,0xFF},
{0xf0,0x02},
{0xf1,0x01},
{0xf2,0x04},
{0xf3,0x30},
{0xf9,0x9f},
{0xfa,0x78},
{0xfe,0x01},
{0x00,0xf5},
{0x02,0x20},
{0x04,0x10},
{0x05,0x10},
{0x06,0x20},
{0x08,0x15},
{0x0a,0xa0},
{0x0b,0x64},
{0x0c,0x08},
{0x0e,0x4C},
{0x0f,0x39},
{0x10,0x41},
{0x11,0x37},
{0x12,0x24},
{0x13,0x39},
{0x14,0x45},
{0x15,0x45},
{0x16,0xc2},
{0x17,0xA8},
{0x18,0x18},
{0x19,0x55},
{0x1a,0xd8},
{0x1b,0xf5},
{0x70,0x40},
{0x71,0x58},
{0x72,0x30},
{0x73,0x48},
{0x74,0x20},
{0x75,0x60},
{0x77,0x20},
{0x78,0x32},
{0x30,0x03},
{0x31,0x40},
{0x32,0x10},
{0x33,0xe0},
{0x34,0xe0},
{0x35,0x00},
{0x36,0x80},
{0x37,0x00},
{0x38,0x04},
{0x39,0x09},
{0x3a,0x12},
{0x3b,0x1C},
{0x3c,0x28},
{0x3d,0x31},
{0x3e,0x44},
{0x3f,0x57},
{0x40,0x6C},
{0x41,0x81},
{0x42,0x94},
{0x43,0xA7},
{0x44,0xB8},
{0x45,0xD6},
{0x46,0xEE},
{0x47,0x0d},
{0xfe,0x00}, 
};
#endif 

#if 1
	static unsigned char gc0308_init_reg[][2] = {  //  2010-12-16 kim 
{0xfe,0x00},
{0x0f,0x00},
{0x01,0x6a},
{0x02,0x70},
{0xe2,0x00},
{0xe3,0x96},
{0xe4,0x02},
{0xe5,0x58},
{0xe6,0x02},
{0xe7,0x58},
{0xe8,0x02},
{0xe9,0x58},
{0xea,0x0e},
{0xeb,0xa6},
{0xec,0x20},
{0x05,0x00},
{0x06,0x00},
{0x07,0x00},
{0x08,0x00},
{0x09,0x01},
{0x0a,0xe8},
{0x0b,0x02},
{0x0c,0x88},
{0x0d,0x02},
{0x0e,0x02},
{0x10,0x26},
{0x11,0x0d},
{0x12,0x2a},
{0x13,0x00},
{0x14,0x10},
{0x15,0x0a},
{0x16,0x05},
{0x17,0x01},
{0x18,0x44},
{0x19,0x44},
{0x1a,0x2a},
{0x1b,0x00},
{0x1c,0x49},
{0x1d,0x9a},
{0x1e,0x61},
{0x1f,0x16},
{0x20,0xff},
{0x21,0xfa},
{0x22,0x57},
{0x24,0xa0},
{0x25,0x0f},
{0x26,0x03}, // 0x01
{0x2f,0x01},
{0x30,0xf7},
{0x31,0x50},
{0x32,0x00},
{0x39,0x04},
{0x3a,0x20},
{0x3b,0x20},
{0x3c,0x00},
{0x3d,0x00},
{0x3e,0x00},
{0x3f,0x00},
{0x50,0x16}, // 0x14
{0x53,0x80},
{0x54,0x87},
{0x55,0x87},
{0x56,0x80},
{0x8b,0x10},
{0x8c,0x10},
{0x8d,0x10},
{0x8e,0x10},
{0x8f,0x10},
{0x90,0x10},
{0x91,0x3c},
{0x92,0x50},
{0x5d,0x12},
{0x5e,0x1a},
{0x5f,0x24},
{0x60,0x07},
{0x61,0x15},
{0x62,0x0f}, // 0x08
{0x64,0x01},  // 0x03
{0x66,0xe8},
{0x67,0x86},
{0x68,0xa2},
{0x69,0x18},
{0x6a,0x0f},
{0x6b,0x00},
{0x6c,0x5f},
{0x6d,0x8f},
{0x6e,0x55},
{0x6f,0x38},
{0x70,0x15},
{0x71,0x33},
{0x72,0xdc},
{0x73,0x80},
{0x74,0x02},
{0x75,0x3f},
{0x76,0x02},
{0x77,0x57}, // 0x47
{0x78,0x88},
{0x79,0x81},
{0x7a,0x81},
{0x7b,0x22},
{0x7c,0xff},
{0x93,0x46},
{0x94,0x00},
{0x95,0x03},
{0x96,0xd0},
{0x97,0x40},
{0x98,0xf0},
{0xb1,0x3c},
{0xb2,0x3c},
{0xb3,0x44}, //0x40
{0xb6,0xe0},
{0xbd,0x3C},
{0xbe,0x36},
{0xd0,0xC9},
{0xd1,0x10},
{0xd2,0x90},
{0xd3,0x88},
{0xd5,0xF2},
{0xd6,0x10},
{0xdb,0x92},
{0xdc,0xA5},
{0xdf,0x23},
{0xd9,0x00},
{0xda,0x00},
{0xe0,0x09},
{0xed,0x04},
{0xee,0xa0},
{0xef,0x40},
{0x80,0x03},
#if 0
{0x9F,0x0E},
{0xA0,0x1C},
{0xA1,0x34},
{0xA2,0x48},
{0xA3,0x5A},
{0xA4,0x6B},
{0xA5,0x7B},
{0xA6,0x95},
{0xA7,0xAB},
{0xA8,0xBF},
{0xA9,0xCE},
{0xAA,0xD9},
{0xAB,0xE4},
{0xAC,0xEC},
{0xAD,0xF7},
{0xAE,0xFD},
{0xAF,0xFF},
#elif 0
{0x9F,0x10},
{0xA0,0x20},
{0xA1,0x38},
{0xA2,0x4e},
{0xA3,0x63},
{0xA4,0x76},
{0xA5,0x87},
{0xA6,0xa2},
{0xA7,0xb8},
{0xA8,0xca},
{0xA9,0xd8},
{0xAA,0xe3},
{0xAB,0xEb},
{0xAC,0xf0},
{0xAD,0xF8},
{0xAE,0xFD},
{0xAF,0xFF},
#else
{0x9F,0x14},
{0xA0,0x28},
{0xA1,0x44},
{0xA2,0x5d},
{0xA3,0x72},
{0xA4,0x86},
{0xA5,0x95},
{0xA6,0xb1},
{0xA7,0xc6},
{0xA8,0xd5},
{0xA9,0xe1},
{0xAA,0xea},
{0xAB,0xf1},
{0xAC,0xf5},
{0xAD,0xFb},
{0xAE,0xFe},
{0xAF,0xFF},
#endif
{0xc0,0x00},
{0xc1,0x14},
{0xc2,0x21},
{0xc3,0x36},
{0xc4,0x49},
{0xc5,0x5B},
{0xc6,0x6B},
{0xc7,0x7B},
{0xc8,0x98},
{0xc9,0xB4},
{0xca,0xCE},
{0xcb,0xE8},
{0xcc,0xFF},
{0xf0,0x02},
{0xf1,0x01},
{0xf2,0x04},
{0xf3,0x30},
{0xf9,0x9f},
{0xfa,0x78},
{0xfe,0x01},
{0x00,0xf5},
{0x02,0x20},
{0x04,0x10},
{0x05,0x10},
{0x06,0x20},
{0x08,0x15},
{0x0a,0xa0},
{0x0b,0x64},
{0x0c,0x08},
{0x0e,0x4C},
{0x0f,0x39},
{0x10,0x41},
{0x11,0x37},
{0x12,0x24},
{0x13,0x39},
{0x14,0x45},
{0x15,0x45},
{0x16,0xc2},
{0x17,0xA8},
{0x18,0x18},
{0x19,0x55},
{0x1a,0xd8},
{0x1b,0xf5},
{0x70,0x40},
{0x71,0x58},
{0x72,0x30},
{0x73,0x48},
{0x74,0x20},
{0x75,0x60},
{0x77,0x20},
{0x78,0x32},
{0x30,0x03},
{0x31,0x40},
{0x32,0x10},
{0x33,0xe0},
{0x34,0xe0},
{0x35,0x00},
{0x36,0x80},
{0x37,0x00},
{0x38,0x04},
{0x39,0x09},
{0x3a,0x12},
{0x3b,0x1C},
{0x3c,0x28},
{0x3d,0x31},
{0x3e,0x44},
{0x3f,0x57},
{0x40,0x6C},
{0x41,0x81},
{0x42,0x94},
{0x43,0xA7},
{0x44,0xB8},
{0x45,0xD6},
{0x46,0xEE},
{0x47,0x0d},
{0xfe,0x00}, 
};
#endif

#define GC0308_INIT_REGS	(sizeof(gc0308_init_reg) / sizeof(gc0308_init_reg[0]))    

unsigned char gc0308_windows_640[][2] = {
    {0x05,0x00},
    {0x06,0x00},
    {0x07,0x00},
    {0x08,0x00},
    {0x09,0x01},
    {0x0a,0xe8},
    {0x0b,0x02},
    {0x0c,0x88},
};

unsigned char Gc0308_Data[][2]            = { {0x24,0x00}, };
unsigned char gc0308_output_RGB[][2]      = { {0x24,0xa6}, };
unsigned char gc0308_output_yuv0[][2]     = { {0x24,0xa2}, };
unsigned char gc0308_output_yuv1[][2]     = { {0x24,0xa3}, };
unsigned char gc0308_output_yuv2[][2]     = { {0x24,0xa1}, };
unsigned char gc0308_output_yuv3[][2]     = { {0x24,0xa0}, };
unsigned char gc0308_paddrv[][2]          = { {0x1f,0x33}, };
unsigned char gc0308_syncmode[][2]        = { {0x26,0xf7}, }; // 0xbf by liusu
unsigned char gc0308_syncmode1[][2]       = { {0x26,0xf7}, }; // 0xbf by liusu
unsigned char gc0308_output_en[][2]       = { {0x25,0xff}, };
unsigned char gc0308_windows_2_page1[][2] = { {0xfe,0x01}, };
unsigned char gc0308_windows_2_page0[][2] = { {0xfe,0x00}, };
unsigned char gc0308_windows_2_qvga[][2]  = { {0x54,0x22}, };
unsigned char gc0308_windows_2_vga[][2]   = { {0x54,0x11}, };

// effect
unsigned char gc0308_effect_normal [][2] = {
	{0x23,0x00},//normal  
	{0x2d,0x0a},	 
	{0x20,0xff},	 
	{0xd2,0x90},	 
	{0x73,0x00},	 
	{0x77,0x54},	 
	{0xb3,0x40},
	{0xb4,0x80},
	{0xba,0x00},
	{0xbb,0x00},
};

unsigned char gc0308_effect_grayscale [][2] = {
	{0x23,0x02},//grayscale   
    {0x2d,0x0a},     
    {0x20,0xff},     
    {0xd2,0x90},     
    {0x73,0x00},     
    {0xb3,0x40},     
    {0xb4,0x80},         
    {0xba,0x00},
	{0xbb,0x00},
};

unsigned char gc0308_effect_sepia [][2] = {
	{0x23,0x02}, //sepia												
	{0x2d,0x0a},						 
	{0x20,0xff},						 
	{0xd2,0x90},						 
	{0x73,0x00},						 
	{0xb3,0x40},						 
	{0xb4,0x80},						 
	{0xba,0xd0},
	{0xbb,0x28},
};

unsigned char gc0308_effect_sepia_green  [][2] = {
	{0x23,0x02},	//sepia green
	{0x2d,0x0a},	
	{0x20,0xff},	
	{0xd2,0x90},	
	{0x77,0x88},
	{0xb3,0x40},
	{0xb4,0x80},			
	{0xba,0xc0},
	{0xbb,0xc0},	
};

unsigned char gc0308_effect_sepia_blue[][2] = {
	{0x23,0x02}, //sharpness 
	{0x2d,0x0a},  
	{0x20,0xff},	
	{0xd2,0x90},	
	{0x73,0x00},	
	{0xb3,0x40},	
	{0xb4,0x80}, 
	{0xba,0x50}, 
	{0xbb,0xe0}, 
};

unsigned char gc0308_effect_color_inv [][2] = {
	{0x23,0x01}, //sketch				  
	{0x2d,0x0a},
	{0x20,0xff},
	{0xd2,0x90},
	{0x73,0x00},
	{0xb3,0x40},
	{0xb4,0x80},
	{0xba,0x00},
	{0xbb,0x00},
};

unsigned char gc0308_effect_gray_inv [][2] = {
	{0x23,0x03}, //sketch				  
	{0x2d,0x0a},
	{0x20,0xff},
	{0xd2,0x90},
	{0x73,0x00},
	{0xb3,0x40},
	{0xb4,0x80},
	{0xba,0x00},
	{0xbb,0x00},
};


unsigned char gc0308_effect_embossment [][2] = {
	{0x23,0x02}, //sketch				  
	{0x2d,0x0a},
	{0x20,0xbf},
	{0xd2,0x10},
	{0x73,0x01},
	{0x51,0x40},
	{0x52,0x40},
	{0xb3,0x40},
	{0xb4,0x80},
	{0xba,0x00},
	{0xbb,0x00},
};

unsigned char gc0308_effect_sketch [][2] = {
	{0x23,0x02}, //sketch				  
	{0x2d,0x0a},
	{0x20,0xbf},
	{0xd2,0x10},
	{0x73,0x01},
	{0x51,0x40},
	{0x52,0x40},
	{0xb3,0x98},
	{0xb4,0x06},
	{0xba,0x00},
	{0xbb,0x00},
};

unsigned char gc0308_white_balance_auto  [][2] = {
	{0x5a,0x56},	
	{0x5b,0x40},	
	{0x5c,0x4a},	
	// eable AWB
};

unsigned char gc0308_white_balance_cloud [][2] = {
	// disable AWB
	{0x5a,0x8c},	
	{0x5b,0x50},	
	{0x5c,0x40},	
};

unsigned char gc0308_white_balance_daylight [][2] = {
	// disable AWB
	{0x5a,0x74},	
	{0x5b,0x52},	
	{0x5c,0x40},	
};

unsigned char gc0308_white_balance_incandescence [][2] = {
	// disable AWB
	{0x5a,0x48},	
	{0x5b,0x40},	
	{0x5c,0x5c},	
};

unsigned char gc0308_white_balance_fluorescent [][2] = {
	// disable AWB
	{0x5a,0x40},	
	{0x5b,0x42},	
	{0x5c,0x50},	
};

#endif     
#endif
