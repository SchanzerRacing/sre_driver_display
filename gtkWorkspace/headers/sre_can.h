#ifndef SRE_CAN_H
#define SRE_CAN_H


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


// CAN Mapping
typedef struct {
    int can_id;
    void *union_ptr;
    size_t union_size;
} can_mapping_t;

#define NUM_MAPPINGS (sizeof(can_mappings) / sizeof(can_mappings[0]))


// ----------------------------- HSC_Vehicle_Status ----------------------------

#define HSC_VEHICLE_STATUS_ID 0x103
#define HSC_VEHICLE_STATUS_DLC 8        
 // Number of Bytes
union HSC_Vehicle_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t State :3;
        uint64_t IMD_ERROR :1;
        uint64_t AMS_ERROR :1;
        uint64_t GEN_SCS :3;
        uint64_t Velocity :8;
        uint64_t reserved :48;
    };
};

// ----------------------------- HSC_DriverInput ----------------------------

#define HSC_DRIVERINPUT_ID 0x104
#define HSC_DRIVERINPUT_DLC 3         // Number of Bytes

union HSC_DriverInput_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Throttle :16;
        uint64_t Brake_Pressed :1;
        uint64_t Throttle_Valid :1;
        uint64_t Brake_Valid :1;
        uint64_t reserved :2;
        uint64_t GEN_SCS :3;
    };
};

// -------------------------------- HSC_Steering -------------------------------

#define HSC_STEERING_ID 0x105
#define HSC_STEERING_DLC 4

union HSC_Steering_UNION
{
    uint64_t data;
    struct
    {
        int64_t SteeringWheel_Angle :12;
        int64_t Steering_Angle :12;
        uint64_t Angle_Valid :1;
        uint64_t GEN_SCS :3;
        uint64_t reserved :4;
    };
};

// ----------------------------- LOG_BrakePressures ----------------------------

#define LOG_BRAKEPRESSURES_ID 0x515
#define LOG_BRAKEPRESSURES_DLC 3         // Number of Bytes

union LOG_BrakePressures_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Front :12;
        uint64_t Rear :12;
    };
};

// -------------------------------- DV_System_Status-------------------------------

#define DV_SYSTEM_STATUS_ID 0x502
#define DV_SYSTEM_STATUS_DLC 5          // Number of Bytes

union DV_System_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t AS_State :3;
        uint64_t EBS_State :2;
        uint64_t AMI_State :3;
        uint64_t SteeringState :1;
        uint64_t ServiceBrakeState :2;
        uint64_t LapCounter :4;
        uint64_t ConesCount_Actual :8;
        uint64_t ConesCount_ALL :17;
    };
};

// -------------------------------- LOG_LEM --------------------------------

#define LOG_LEM_ID 0x786
#define LOG_LEM_DLC 2           // Number of Bytes

union LOG_LEM_UNION
{
    uint64_t data;
    struct
    {
        uint64_t LV_current :16;
    };
};

// ---------------------- GW_Battery_Status ----------------------------
#define GW_BATTERY_STATUS_ID 0x385
#define GW_BATTERY_STATUS_DLC 4

union GW_Battery_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Power:14;
        uint64_t SOC_Internal:14;
        uint64_t State:4;
    };
};
#endif // SRE_CAN_H