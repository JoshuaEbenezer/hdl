//----------------------------------------------------------------------------
//      _____
//     *     *
//    *____   *____
//   * *===*   *==*
//  *___*===*___**  AVNET
//       *======*
//        *====*
//----------------------------------------------------------------------------
//
// This design is the property of Avnet.  Publication of this
// design is not authorized without written consent from Avnet.
//
// Please direct any questions or issues to the MicroZed Community Forums:
//    http://www.microzed.org
//
// Disclaimer:
//    Avnet, Inc. makes no warranty for the use of this code or design.
//    This code is provided  "As Is". Avnet, Inc assumes no responsibility for
//    any errors, which may appear in this code, nor does it make a commitment
//    to update the information contained herein. Avnet, Inc specifically
//    disclaims any implied warranties of fitness for a particular purpose.
//                     Copyright(c) 2013 Avnet, Inc.
//                             All rights reserved.
//
//----------------------------------------------------------------------------
//
// Create Date:         Jul 01, 2013
// Design Name:         ZedBoard ALI3 Controller Demonstration
// Module Name:         zed_ali3_controller_demo.h
// Project Name:        ZedBoard ALI3 Display Kit
// Target Devices:      Zynq-7000
// Hardware Boards:     ZedBoard, MicroZed, Zed Display Kit
//
// Tool versions:       Vivado 2015.2
//
// Description:         Zed Display Kit Demo
//                      This application will configure the display kit for
//                      480*800 display output.
//
// Dependencies:
//
// Revision:            Nov 15, 2011: 1.00 Initial version
//                      May 23, 2013: 1.02 Updated for Zed Display Kit - 14.5
//                      Jul  1, 2013: 1.03 Revised for MicroZed target
//                      Feb  7, 2014: 1.03 Revised for MicroZed FMC-CC target
//                      Jun  4, 2015: 1.04 Revised for MicroZed EMBV target
//                      Sep 17, 2015: 1.05 Updated for 2015.2 release
//                      Oct 28, 2015: 1.05 Updated to support 10" Ampire 
//                                         display kit and Vivado 2015.2
//                      Dec 10, 2015: 1.06 Updated to support PicoZed FMC2
//
//----------------------------------------------------------------------------

#ifndef __ZED_ALI3_CONTROLLER_DEMO_H__
#define __ZED_ALI3_CONTROLLER_DEMO_H__

#include "xparameters.h"
#include "types.h"

#include "sleep.h"

// I2C related.
#include "zed_iic.h"

// Video related
#include "xaxivdma.h"
#include "video_resolution.h"
#include "video_frame_buffer.h"

// Interrupt related.
#include "xscugic.h"
#include "xil_exception.h"

// PS GPIO related.
#include "xgpiops.h"

/*
 * The following constants map to the XPAR parameters created in the
 * xparameters.h file. They are defined here such that a user can easily
 * change all the needed parameters in one place.
 */
#define GPIO_DEVICE_ID  	XPAR_XGPIOPS_0_DEVICE_ID

#define X_OFFSET	20		// offset value to center control panel on 1280 horizontal
#define Y_OFFSET	140		// offset value to center control panel on 800 vertical
/* User interface positional map. */
#define BUTTON0_POSITION_X                     144 + X_OFFSET // "SW1" - "N"
#define BUTTON1_POSITION_X                     144 + X_OFFSET // "SW2" - "S"
#define BUTTON2_POSITION_X                     225 + X_OFFSET // "SW3" - "E"
#define BUTTON3_POSITION_X                      63 + X_OFFSET // "SW4" - "W"
#define BUTTON4_POSITION_X                     144 + X_OFFSET // "SW5" - "C"
#define BUTTON0_POSITION_Y                     194 + Y_OFFSET // "SW1" - "N"
#define BUTTON1_POSITION_Y                     356 + Y_OFFSET // "SW2" - "S"
#define BUTTON2_POSITION_Y                     275 + Y_OFFSET // "SW3" - "E"
#define BUTTON3_POSITION_Y                     275 + Y_OFFSET // "SW4" - "W"
#define BUTTON4_POSITION_Y                     275 + Y_OFFSET // "SW5" - "C"

#define LED0_POSITION_X                        360 + X_OFFSET // "D6"
#define LED1_POSITION_X                        460 + X_OFFSET // "D7"
#define LED2_POSITION_X                        560 + X_OFFSET // "D8"
#define LED3_POSITION_X                        660 + X_OFFSET // "D9"
#define LED0_POSITION_Y                        300 + Y_OFFSET // "D6"
#define LED1_POSITION_Y                        300 + Y_OFFSET // "D7"
#define LED2_POSITION_Y                        300 + Y_OFFSET // "D8"
#define LED3_POSITION_Y                        300 + Y_OFFSET // "D9"

#define ACCEL_BACKGROUND_POSITION_X            864 + X_OFFSET
#define ACCEL_BACKGROUND_POSITION_Y            0   + Y_OFFSET

#define ACCEL_POSX_HIGH_POSITION_X             900 + X_OFFSET
#define ACCEL_POSX_HIGH_POSITION_Y             36  + Y_OFFSET
#define ACCEL_POSX_MED_POSITION_X              900 + X_OFFSET
#define ACCEL_POSX_MED_POSITION_Y              136 + Y_OFFSET
#define ACCEL_POSX_LOW_POSITION_X              900 + X_OFFSET
#define ACCEL_POSX_LOW_POSITION_Y              236 + Y_OFFSET
#define ACCEL_NEGX_LOW_POSITION_X              900 + X_OFFSET
#define ACCEL_NEGX_LOW_POSITION_Y              336 + Y_OFFSET
#define ACCEL_NEGX_MED_POSITION_X              900 + X_OFFSET
#define ACCEL_NEGX_MED_POSITION_Y              436 + Y_OFFSET
#define ACCEL_NEGX_HIGH_POSITION_X             900 + X_OFFSET
#define ACCEL_NEGX_HIGH_POSITION_Y             536 + Y_OFFSET
                                   
#define ACCEL_POSY_HIGH_POSITION_X             1000 + X_OFFSET
#define ACCEL_POSY_HIGH_POSITION_Y             36   + Y_OFFSET
#define ACCEL_POSY_MED_POSITION_X              1000 + X_OFFSET
#define ACCEL_POSY_MED_POSITION_Y              136  + Y_OFFSET
#define ACCEL_POSY_LOW_POSITION_X              1000 + X_OFFSET
#define ACCEL_POSY_LOW_POSITION_Y              236  + Y_OFFSET
#define ACCEL_NEGY_LOW_POSITION_X              1000 + X_OFFSET
#define ACCEL_NEGY_LOW_POSITION_Y              336  + Y_OFFSET
#define ACCEL_NEGY_MED_POSITION_X              1000 + X_OFFSET
#define ACCEL_NEGY_MED_POSITION_Y              436  + Y_OFFSET
#define ACCEL_NEGY_HIGH_POSITION_X             1000 + X_OFFSET
#define ACCEL_NEGY_HIGH_POSITION_Y             536  + Y_OFFSET
                                   
#define ACCEL_POSZ_HIGH_POSITION_X             1100 + X_OFFSET
#define ACCEL_POSZ_HIGH_POSITION_Y             36   + Y_OFFSET
#define ACCEL_POSZ_MED_POSITION_X              1100 + X_OFFSET
#define ACCEL_POSZ_MED_POSITION_Y              136  + Y_OFFSET
#define ACCEL_POSZ_LOW_POSITION_X              1100 + X_OFFSET
#define ACCEL_POSZ_LOW_POSITION_Y              236  + Y_OFFSET
#define ACCEL_NEGZ_LOW_POSITION_X              1100 + X_OFFSET
#define ACCEL_NEGZ_LOW_POSITION_Y              336  + Y_OFFSET
#define ACCEL_NEGZ_MED_POSITION_X              1100 + X_OFFSET
#define ACCEL_NEGZ_MED_POSITION_Y              436  + Y_OFFSET
#define ACCEL_NEGZ_HIGH_POSITION_X             1100 + X_OFFSET
#define ACCEL_NEGZ_HIGH_POSITION_Y             536  + Y_OFFSET

/* Defines a demo mode enumeration type. */
enum demo_mode
{
    draw = 0,
    control
};

/* Defines a touch controller enumeration type.  The enumeration values
 * just happen to also be the I2C slave address values. */
enum touch_controller_type
{
    none = 0,
    clicktouch = 0x1F,
    dhelectronic = 0x20
};

/* This structure contains the context for the Zed Display Kit
 * Standalone Demonstration Application. */
struct struct_zed_ali3_controller_demo_t
{
    int32u bVerbose;

    ////////////////////////////////
    // Video DMA related context
    ////////////////////////////////
    int32u uDeviceId_VDMA_FrameBuffer;
    int32u uBaseAddr_MEM_FrameBuffer;  // address of FB in memory
    int32u uNumFrames_FrameBuffer;

    XAxiVdma vdma_ali3;
    XAxiVdma_DmaSetup vdmacfg_ali3_read;
    XAxiVdma_DmaSetup vdmacfg_ali3_write; // not used in this demo

    // ALI3 video resolution
    int32u ali3_width;
    int32u ali3_height;
    int32u ali3_resolution;

    ////////////////////////////////
    // Touch I2C related context
    ////////////////////////////////
    int32u uBaseAddr_IIC_Touch;

    zed_iic_t touch_iic;

    ////////////////////////////////
    // Interrupt related context
    ////////////////////////////////
    int32u uDeviceId_IRQ_Touch;
    int32u uInterruptId_IRQ_Touch;

    XScuGic Intc;
    XScuGic_Config *pIntcConfig;

    ////////////////////////////////
    // Touch calibration coefficients
    ////////////////////////////////
    int32s calibration_success;
    int32s calibration_An;
    int32s calibration_Bn;
    int32s calibration_Cn;
    int32s calibration_Dn;
    int32s calibration_En;
    int32s calibration_Fn;
    int32s calibration_divisor;

    ////////////////////////////////
    // Touch related statistics
    ////////////////////////////////
    int32u touch_duplicates;
    int32u touch_events;
    int32u touch_irqs;
    int32u touch_overflows;
    int16u touch_posx_raw;
    int16u touch_posy_raw;
    int16u touch_posx_cal;
    int16u touch_posy_cal;
    int8u  touch_gesture;
    int8u  touch_pen_down;
    int8u  touch_pen_down_transition;
    int32u touch_valid;

    ////////////////////////////////
	// Touch I2C slave related context
	////////////////////////////////
	int8u slave_touch_data_offset;
	int8u slave_touch_report_length;
	int8u touch_max_finger_count_supported;

    ////////////////////////////////
    // GPIO related members
    ////////////////////////////////
    int button0_state;
    int button1_state;
    int button2_state;
    int button3_state;
	int button4_state;
	
    int led0_state;
    int led1_state;
    int led2_state;
    int led3_state;


    XGpioPs gpio_driver;	// The driver instance for PS GPIO Device.

    ////////////////////////
    // Accelerometer data //
    ////////////////////////
    int8s accel_x;
    int8s accel_y;
    int8s accel_z;

    int8s accel_x_delta;
    int8s accel_y_delta;
    int8s accel_z_delta;
    enum demo_mode mode;
};
typedef struct struct_zed_ali3_controller_demo_t zed_ali3_controller_demo_t;

int zed_ali3_controller_demo_accel_background(zed_ali3_controller_demo_t *pDemo);
int zed_ali3_controller_demo_accel_indication(zed_ali3_controller_demo_t *pDemo);
int zed_ali3_controller_demo_board_process(zed_ali3_controller_demo_t *pDemo);
int zed_ali3_controller_demo_button(zed_ali3_controller_demo_t *pDemo, int button_number, int button_state);
int zed_ali3_controller_demo_init(zed_ali3_controller_demo_t *pDemo);
int zed_ali3_controller_demo_cbars(zed_ali3_controller_demo_t *pDemo, int32u offset);
int zed_ali3_controller_demo_check_calibrate_request(zed_ali3_controller_demo_t *pDemo);
int zed_ali3_controller_demo_control(zed_ali3_controller_demo_t *pDemo);
int zed_ali3_controller_demo_led(zed_ali3_controller_demo_t *pDemo, int led_number, int led_state);
int zed_ali3_controller_demo_logo(zed_ali3_controller_demo_t *pDemo);
int zed_ali3_controller_demo_touch_calibrate(zed_ali3_controller_demo_t *pDemo);
int zed_ali3_controller_demo_touch_process(zed_ali3_controller_demo_t *pDemo);

#endif // __ZED_ALI3_CONTROLLER_DEMO_H__
