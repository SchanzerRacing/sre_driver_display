#ifndef SRE_CAN_H
#define SRE_CAN_H

#include "sre_dbc.h"

#include <gtk/gtk.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

void can_loop();
uint8_t read_and_match();
void setup_can();
void close_can();

// CAN STRUCTS
extern struct HSC_Vehicle_Status_Struct HSC_Vehicle_Status;
extern struct HSC_DriverInput_Struct HSC_DriverInput;
extern struct HSC_Steering_Struct HSC_Steering;
extern struct LOG_BrakePressures_Struct LOG_BrakePressures;
extern struct DV_System_Status_Struct DV_System_Status;
extern struct LOG_LEM_Struct LOG_LEM;
extern struct GW_Battery_Status_Struct GW_Battery_Status;
extern struct DV_ASB_Pressure_Struct DV_ASB_Pressure;
extern struct DV_ASB_Status_Struct DV_ASB_Status;
extern struct DV_AMI_Status_Struct DV_AMI_Status;
extern struct GW_Battery_Cells_Struct GW_Battery_Cells;
extern struct GW_PE_FrontLeft_Struct GW_PE_FrontLeft;
extern struct GW_PE_FrontRight_Struct GW_PE_FrontRight;
extern struct GW_PE_RearLeft_Struct GW_PE_RearLeft;
extern struct GW_PE_RearRight_Struct GW_PE_RearRight;
extern struct HSC_SBG_EKF_Vel_Body_Struct HSC_SBG_EKF_VEL_BODY;
extern struct HSC_SBG_Accel_Struct HSC_SBG_ACCEL;
extern struct LOG_LEM_Struct LOG_LEM;

// Safety Messages
// enum SAF_AIN_F1_Status_ERRORS {SCS_ERROR_AIN, Throttle_Lower_ERROR, Throttle_Upper_ERROR, Throttle_Differential_ERROR, Brake_ERROR, GEN_SCS};
// static const char* SAF_AIN_F1_Status_ERRORS_STR[] = {"SCS Error", "Throttle Lower Error", "Throttle Upper Error", "Throttle Differential Error", "Brake Error", "GEN SCS"};

// CAN Mapping
typedef struct
{
	int can_id;
	void *struct_ptr;
	void (*union_to_struct)(void *, uint64_t);
} can_mapping_t;

#define NUM_MAPPINGS (sizeof(can_mappings) / sizeof(can_mappings[0]))

#endif // SRE_CAN_H
