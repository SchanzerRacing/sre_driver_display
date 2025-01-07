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
extern union HSC_Vehicle_Status_UNION HSC_Vehicle_Status;
extern union HSC_DriverInput_UNION HSC_DriverInput;
extern union HSC_Steering_UNION HSC_Steering;
extern union LOG_BrakePressures_UNION LOG_BrakePressures;
extern union DV_System_Status_UNION DV_System_Status;
extern union LOG_LEM_UNION LOG_LEM;
extern union GW_Battery_Status_UNION GW_Battery_Status;
extern union DV_ASB_Pressure_UNION DV_ASB_Pressure;
extern union DV_ASB_Status_UNION DV_ASB_Status;
extern union DV_AMI_Status_UNION DV_AMI_Status;
extern union SAF_AIN_F1_Status_UNION SAF_AIN_F1_Status;

// Safety Messages
enum SAF_AIN_F1_Status_ERRORS {SCS_ERROR_AIN, Throttle_Lower_ERROR, Throttle_Upper_ERROR, Throttle_Differential_ERROR, Brake_ERROR, GEN_SCS};
static const char* SAF_AIN_F1_Status_ERRORS_STR[] = {"SCS Error", "Throttle Lower Error", "Throttle Upper Error", "Throttle Differential Error", "Brake Error", "GEN SCS"};

// CAN Mapping
typedef struct {
    int can_id;
    void *union_ptr;
    size_t union_size;
} can_mapping_t;

#define NUM_MAPPINGS (sizeof(can_mappings) / sizeof(can_mappings[0]))

#endif // SRE_CAN_H