/*
 * system_DBC.h
 *
 *  Created on: 21.02.2024
 *      Author: Richard Frei
 */

/**
 * !!!!! Wichtig !!!!!
 * Aktuell sind die DBCs per hand geschrieben. Es muss IMMER vor der nutztung
 * der Structs/Unions �berpr�ft werden ob die mit den Neuen DBCs �ber
 * einstimmen!
 *
 */

#ifndef SYSTEM_LIB_SYSTEM_DBC_H
#define SYSTEM_LIB_SYSTEM_DBC_H

#include <inttypes.h>
#include <stdbool.h>

enum CAN_MESSAGE_TX_METHODE
{
    CAN_MSG_TXM_CYCLIC = 0,
    CAN_MSG_TXM_SPONTANEOUS,
    CAN_MSG_TXM_CYCLIC_IF_ACTIVE,
    CAN_MSG_TXM_SPONTANEOUS_WITH_DELAY,
    CAN_MSG_TXM_CYCLIC_AND_SPONTANEOUS,
    CAN_MSG_TXM_CYCLIC_AND_SPONTANEOUS_WITH_DELAY,
    CAN_MSG_TXM_SPONTANEOUS_WITH_REPETITION,
    CAN_MSG_TXM_CYCLIC_IF_ACTIVE_AND_SPONTANEOUS_WITH_DELAY,
};

enum CAN_NETWORK_NODES
{
    CAN_NW_NODE_AIN_F1,
    CAN_NW_NODE_AIN_F2,
    CAN_NW_NODE_AIN_R1,
    CAN_NW_NODE_AIN_SB_L,
    CAN_NW_NODE_AIN_SB_R,
    CAN_NW_NODE_AMI,
    CAN_NW_NODE_ASB,
    CAN_NW_NODE_DIO_AS,
    CAN_NW_NODE_DIO_DASH,
    CAN_NW_NODE_ECU,
    CAN_NW_NODE_EPOS,
    CAN_NW_NODE_FSG_LOGGER,
    CAN_NW_NODE_HSS_BL,
    CAN_NW_NODE_HSS_FAN_L,
    CAN_NW_NODE_HSS_FAN_R,
    CAN_NW_NODE_HSS_PUMP_L,
    CAN_NW_NODE_HSS_PUMP_R,
    CAN_NW_NODE_HSS_RTDS,
    CAN_NW_NODE_I2C_FW,
    CAN_NW_NODE_I2C_RW,
    CAN_NW_NODE_I2C_SB_L,
    CAN_NW_NODE_I2C_SB_R,
    CAN_NW_NODE_IMU_F,
    CAN_NW_NODE_IMU_R,
    CAN_NW_NODE_IO_TEST,
    CAN_NW_NODE_JETSON,
    CAN_NW_NODE_LOGGER,
    CAN_NW_NODE_RES,
    CAN_NW_NODE_RTK,
    CAN_NW_NODE_VN1640A
};

enum Vehicle_Status
{
    VS_UNDEFINED_STARTUP = 0,
    VS_WAIT_FOR_TSA,
    VS_RTD_OFF,
    VS_WAIT_FOR_RTD,
    VS_DRIVE,
    VS_LC_ON,
    VS_SCS_ERROR,
};

enum LED_Status
{
    LED_S_OFF, LED_S_ON, LED_S_START_UP_TEST, LED_S_ERROR,
};

enum AS_States
{
    AS_state_off = 1,
    AS_state_ready,
    AS_state_driving,
    AS_state_emergency_brake,
    AS_state_finish
};

enum EBS_States
{
    EBS_state_unavailable = 1, EBS_state_armed, EBS_state_activated
};

enum AMI_States
{
    AMI_state_acceleration = 1,
    AMI_state_skidpad,
    AMI_state_trackdrive,
    AMI_state_braketest,
    AMI_state_inspection,
    AMI_state_autocross
};

enum Service_Brake_States
{
    Service_brake_state_disengaged = 1,
    Service_brake_state_engaged,
    Service_brake_state_available
};

// ----------------------------- HSC_Vehicle_Status ----------------------------

#define HSC_VEHICLE_STATUS_ID 0x103
#define HSC_VEHICLE_STATUS_DLC 8         // Number of Bytes
#define HSC_VEHICLE_STATUS_CYCLE_TIME 10 // Millisecond Period
#define HSC_VEHICLE_STATUS_TX_METHODE CAN_MSG_TXM_CYCLIC
#define HSC_VEHICLE_STATUS_TRANSMITTER CAN_NW_NODE_ECU

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
struct HSC_Vehicle_Status_Return_STRUCT
{
    enum Vehicle_Status State;
    bool IMD_ERROR;
    bool AMS_ERROR;
    uint8_t GEN_SCS;
    float Velocity;
};

extern inline struct HSC_Vehicle_Status_Return_STRUCT
HSC_Vehicle_Status_ConvertToVar(union HSC_Vehicle_Status_UNION o);

extern inline void
HSC_Vehicle_Status_ConvertToCAN(union HSC_Vehicle_Status_UNION *o,
                                struct HSC_Vehicle_Status_Return_STRUCT u);

// ----------------------------- HSC_DriverInput ----------------------------

#define HSC_DRIVERINPUT_ID 0x104
#define HSC_DRIVERINPUT_DLC 3         // Number of Bytes
#define HSC_DRIVERINPUT_CYCLE_TIME 10 // Millisecond Period
#define HSC_DRIVERINPUT_TX_METHODE CAN_MSG_TXM_CYCLIC
#define HSC_DRIVERINPUT_TRANSMITTER CAN_NW_NODE_AIN_F1

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
struct HSC_DriverInput_Return_STRUCT
{
    float Throttle;
    bool Brake_Pressed;
    bool Throttle_Valid;
    bool Brake_Valid;
    uint8_t GEN_SCS;
};

extern inline struct HSC_DriverInput_Return_STRUCT
HSC_DriverInput_ConvertToVar(union HSC_DriverInput_UNION o);

extern inline void
HSC_DriverInput_ConvertToCAN(union HSC_DriverInput_UNION *o,
                             struct HSC_DriverInput_Return_STRUCT u);

// -------------------------------- HSC_Steering -------------------------------

#define HSC_STEERING_ID 0x105
#define HSC_STEERING_DLC 4         // Number of Bytes
#define HSC_STEERING_CYCLE_TIME 10 // Millisecond Period
#define HSC_STEERING_TX_METHODE CAN_MSG_TXM_CYCLIC
#define HSC_STEERING_TRANSMITTER CAN_NW_NODE_AIN_F2

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
struct HSC_Steering_Return_STRUCT
{
    float SteeringWheel_Angle;
    float Steering_Angle;
    bool Angle_Valid;
    uint8_t GEN_SCS;
};

extern inline struct HSC_Steering_Return_STRUCT
HSC_Steering_ConvertToVar(union HSC_Steering_UNION o);

extern inline void
HSC_Steering_ConvertToCAN(union HSC_Steering_UNION *o,
                          struct HSC_Steering_Return_STRUCT u);

// -------------------------------- LSC_Dash_Buttons
// -------------------------------

#define LSC_DASH_BUTTONS_ID 0x181
#define LSC_DASH_BUTTONS_DLC 2          // Number of Bytes
#define LSC_DASH_BUTTONS_CYCLE_TIME 100 // Millisecond Period
#define LSC_DASH_BUTTONS_TX_METHODE CAN_MSG_TXM_CYCLIC_AND_SPONTANEOUS
#define LSC_DASH_BUTTONS_TRANSMITTER CAN_NW_NODE_DIO_DASH

union LSC_Dash_Buttons_UNION
{
    uint64_t data;
    struct
    {
        uint64_t TSA :1;
        uint64_t RTD :1;
        uint64_t Logging :1;
        uint64_t GEN_SCS :3;
        uint64_t reserved1 :2;
        uint64_t Display_Enter :1;
        uint64_t Display_Backwards :1;
        uint64_t Display_Forwards :1;
    };
};
struct LSC_Dash_Buttons_Return_STRUCT
{
    bool TSA;
    bool RTD;
    bool Logging;
    uint8_t GEN_SCS;
    bool Display_Enter;
    bool Display_Backwards;
    bool Display_Forwards;
};

extern inline struct LSC_Dash_Buttons_Return_STRUCT
LSC_Dash_Buttons_ConvertToVar(union LSC_Dash_Buttons_UNION o);

extern inline void
LSC_Dash_Buttons_ConvertToCAN(union LSC_Dash_Buttons_UNION *o,
                              struct LSC_Dash_Buttons_Return_STRUCT u);

// ----------------------------- LOG_BrakePressures ----------------------------

#define LOG_BRAKEPRESSURES_ID 0x515
#define LOG_BRAKEPRESSURES_DLC 3         // Number of Bytes
#define LOG_BRAKEPRESSURES_CYCLE_TIME 10 // Millisecond Period
#define LOG_BRAKEPRESSURES_TX_METHODE CAN_MSG_TXM_CYCLIC
#define LOG_BRAKEPRESSURES_TRANSMITTER CAN_NW_NODE_AIN_F1

union LOG_BrakePressures_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Front :12;
        uint64_t Rear :12;
    };
};
struct LOG_BrakePressures_Return_STRUCT
{
    uint32_t Front;
    uint32_t Rear;
};

extern inline struct LOG_BrakePressures_Return_STRUCT
LOG_BrakePressures_ConvertToVar(union LOG_BrakePressures_UNION o);

extern inline void
LOG_BrakePressures_ConvertToCAN(union LOG_BrakePressures_UNION *o,
                                struct LOG_BrakePressures_Return_STRUCT u);

// ----------------------------- SAF_AIN_F1_Status -----------------------------

#define SAF_AIN_F1_STATUS_ID 0x51
#define SAF_AIN_F1_STATUS_DLC 1          // Number of Bytes
#define SAF_AIN_F1_STATUS_CYCLE_TIME 100 // Millisecond Period
#define SAF_AIN_F1_STATUS_TX_METHODE CAN_MSG_TXM_CYCLIC_AND_SPONTANEOUS
#define SAF_AIN_F1_STATUS_TRANSMITTER CAN_NW_NODE_AIN_F1

union SAF_AIN_F1_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t SCS_ERROR :1;
        uint64_t Throttle_Lower_ERROR :1;
        uint64_t Throttle_Upper_ERROR :1;
        uint64_t Throttle_Differential_ERROR :1;
        uint64_t Brake_ERROR :1;
        uint64_t GEN_SCS :3;
    };
};
struct SAF_AIN_F1_Status_Return_STRUCT
{
    bool SCS_ERROR;
    bool Throttle_Lower_ERROR;
    bool Throttle_Upper_ERROR;
    bool Throttle_Differential_ERROR;
    bool Brake_ERROR;
    uint8_t GEN_SCS;
};

extern inline struct SAF_AIN_F1_Status_Return_STRUCT
SAF_AIN_F1_Status_ConvertToVar(union SAF_AIN_F1_Status_UNION o);

extern inline void
SAF_AIN_F1_Status_ConvertToCAN(union SAF_AIN_F1_Status_UNION *o,
                               struct SAF_AIN_F1_Status_Return_STRUCT u);

// --------------------------------- CAL_APPS ----------------------------------

#define CAL_APPS_ID 0x48F
#define CAL_APPS_DLC 6          // Number of Bytes
#define CAL_APPS_CYCLE_TIME 100 // Millisecond Period
#define CAL_APPS_TX_METHODE CAN_MSG_TXM_CYCLIC_IF_ACTIVE
#define CAL_APPS_TRANSMITTER CAN_NW_NODE_AIN_F1

union CAL_APPS_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Upper_3V3 :12;
        uint64_t Lower_3V3 :12;
        uint64_t Upper_5V :12;
        uint64_t Lower_5V :12;
    };
};
struct CAL_APPS_Return_STRUCT
{
    float Upper_3V3;
    float Lower_3V3;
    float Upper_5V;
    float Lower_5V;
};

extern inline struct CAL_APPS_Return_STRUCT
CAL_APPS_ConvertToVar(union CAL_APPS_UNION o);

extern inline void CAL_APPS_ConvertToCAN(union CAL_APPS_UNION *o,
                                         struct CAL_APPS_Return_STRUCT u);

// ---------------------------- CAL_BrakePressures -----------------------------

#define CAL_BRAKEPRESSURES_ID 0x485
#define CAL_BRAKEPRESSURES_DLC 6          // Number of Bytes
#define CAL_BRAKEPRESSURES_CYCLE_TIME 100 // Millisecond Period
#define CAL_BRAKEPRESSURES_TX_METHODE CAN_MSG_TXM_CYCLIC_IF_ACTIVE
#define CAL_BRAKEPRESSURES_TRANSMITTER CAN_NW_NODE_AIN_F1

union CAL_BrakePressures_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Front_3V3 :12;
        uint64_t Rear_3V3 :12;
        uint64_t Front_5V :12;
        uint64_t Rear_5V :12;
    };
};
struct CAL_BrakePressures_Return_STRUCT
{
    float Front_3V3;
    float Rear_3V3;
    float Front_5V;
    float Rear_5V;
};

extern inline struct CAL_BrakePressures_Return_STRUCT
CAL_BrakePressures_ConvertToVar(union CAL_BrakePressures_UNION o);

extern inline void
CAL_BrakePressures_ConvertToCAN(union CAL_BrakePressures_UNION *o,
                                struct CAL_BrakePressures_Return_STRUCT u);

// --------------------------- CAL_CalibrationMaster ---------------------------

#define CAL_CALIBRATIONMASTER_ID 0x480
#define CAL_CALIBRATIONMASTER_DLC 1          // Number of Bytes
#define CAL_CALIBRATIONMASTER_CYCLE_TIME 100 // Millisecond Period
#define CAL_CALIBRATIONMASTER_TX_METHODE CAN_MSG_TXM_CYCLIC_IF_ACTIVE
#define CAL_CALIBRATIONMASTER_TRANSMITTER CAN_NW_NODE_VN1640A

union CAL_CalibrationMaster_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserverd :8;
    };
};
struct CAL_CalibrationMaster_Return_STRUCT
{
};

extern inline struct CAL_CalibrationMaster_Return_STRUCT
CAL_CalibrationMaster_ConvertToVar(union CAL_CalibrationMaster_UNION o);

extern inline void CAL_CalibrationMaster_ConvertToCAN(
        union CAL_CalibrationMaster_UNION *o,
        struct CAL_CalibrationMaster_Return_STRUCT u);

// ----------------------------- SAF_AIN_F2_Status -----------------------------

#define SAF_AIN_F2_STATUS_ID 0x52
#define SAF_AIN_F2_STATUS_DLC 1          // Number of Bytes
#define SAF_AIN_F2_STATUS_CYCLE_TIME 100 // Millisecond Period
#define SAF_AIN_F2_STATUS_TX_METHODE CAN_MSG_TXM_CYCLIC_AND_SPONTANEOUS
#define SAF_AIN_F2_STATUS_TRANSMITTER CAN_NW_NODE_AIN_F2

union SAF_AIN_F2_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t SCS_ERROR :1;
        uint64_t Steering_ERROR :1;
        uint64_t GEN_SCS :3;
    };
};
struct SAF_AIN_F2_Status_Return_STRUCT
{
    bool SCS_ERROR;
    bool Steering_ERROR;
    uint8_t GEN_SCS;
};

extern inline struct SAF_AIN_F2_Status_Return_STRUCT
SAF_AIN_F2_Status_ConvertToVar(union SAF_AIN_F2_Status_UNION o);

extern inline void
SAF_AIN_F2_Status_ConvertToCAN(union SAF_AIN_F2_Status_UNION *o,
                               struct SAF_AIN_F2_Status_Return_STRUCT u);

// --------------------------------- CAL_SteeringAngle
// ----------------------------------

#define CAL_STEERING_ID 0x490
#define CAL_STEERING_DLC 2          // Number of Bytes
#define CAL_STEERING_CYCLE_TIME 100 // Millisecond Period
#define CAL_STEERING_TX_METHODE CAN_MSG_TXM_CYCLIC_IF_ACTIVE
#define CAL_STEERING_TRANSMITTER CAN_NW_NODE_AIN_F2

union CAL_Steering_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Steering_3V3 :12;
        uint64_t Steering_5V :12;
    };
};
struct CAL_Steering_Return_STRUCT
{
    float Steering_3V3;
    float Steering_5V;
};

extern inline struct CAL_Steering_Return_STRUCT
CAL_Steering_ConvertToVar(union CAL_Steering_UNION o);

extern inline void
CAL_Steering_ConvertToCAN(union CAL_Steering_UNION *o,
                          struct CAL_Steering_Return_STRUCT u);

// ------------------------------- LOG_DashLEDs --------------------------------

#define LOG_DASHLEDS_ID 0x787
#define LOG_DASHLEDS_DLC 1        // Number of Bytes
#define LOG_DASHLEDS_CYCLE_TIME 0 // Millisecond Period
#define LOG_DASHLEDS_TX_METHODE CAN_MSG_TXM_SPONTANEOUS
#define LOG_DASHLEDS_TRANSMITTER CAN_NW_NODE_DIO_DASH

union LOG_DashLEDs_UNION
{
    uint64_t data;
    struct
    {
        uint64_t IMD :1;
        uint64_t reserved1 :1;
        uint64_t AMS :1;
        uint64_t reserved2 :5;
    };
};
struct LOG_DashLEDs_Return_STRUCT
{
    bool IMD;
    bool AMS;
};

extern inline struct LOG_DashLEDs_Return_STRUCT
LOG_DashLEDs_ConvertToVar(union LOG_DashLEDs_UNION o);

extern inline void
LOG_DashLEDs_ConvertToCAN(union LOG_DashLEDs_UNION *o,
                          struct LOG_DashLEDs_Return_STRUCT u);

// ------------------------------- SAF_DIO_DASH_Status
// ----------------------------

#define SAF_DIO_DASH_STATUS_ID 0x54
#define SAF_DIO_DASH_STATUS_DLC 1          // Number of Bytes
#define SAF_DIO_DASH_STATUS_CYCLE_TIME 100 // Millisecond Period
#define SAF_DIO_DASH_STATUS_TX_METHODE CAN_MSG_TXM_CYCLIC_AND_SPONTANEOUS
#define SAF_DIO_DASH_STATUS_TRANSMITTER CAN_NW_NODE_DIO_DASH

union SAF_DIO_DASH_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t SCS_ERROR :1;
        uint64_t Message_ERROR :1;
        uint64_t Output_NoChange_ERROR :1;
        uint64_t reserved1 :2;
        uint64_t GEN_SCS :3;
    };
};
struct SAF_DIO_DASH_Status_Return_STRUCT
{
    bool SCS_ERROR;
    bool Message_ERROR;
    bool Output_NoChange_ERROR;
    uint8_t GEN_SCS;
};

extern inline struct SAF_DIO_DASH_Status_Return_STRUCT
SAF_DIO_DASH_Status_ConvertToVar(union SAF_DIO_DASH_Status_UNION o);

extern inline void
SAF_DIO_DASH_Status_ConvertToCAN(union SAF_DIO_DASH_Status_UNION *o,
                                 struct SAF_DIO_DASH_Status_Return_STRUCT u);

// ------------------------------- SAF_DIO_AS_Status
// ----------------------------

#define SAF_DIO_AS_STATUS_ID 0x55
#define SAF_DIO_AS_STATUS_DLC 1          // Number of Bytes
#define SAF_DIO_AS_STATUS_CYCLE_TIME 100 // Millisecond Period
#define SAF_DIO_AS_STATUS_TX_METHODE CAN_MSG_TXM_CYCLIC_AND_SPONTANEOUS
#define SAF_DIO_AS_STATUS_TRANSMITTER CAN_NW_NODE_DIO_AS

union SAF_DIO_AS_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t SCS_ERROR :1;
        uint64_t Message_ERROR :1;
        uint64_t Output_NoChange_ERROR :1;
        uint64_t reserved1 :2;
        uint64_t GEN_SCS :3;
    };
};
struct SAF_DIO_AS_Status_Return_STRUCT
{
    bool SCS_ERROR;
    bool Message_ERROR;
    bool Output_NoChange_ERROR;
    uint8_t GEN_SCS;
};

extern inline struct SAF_DIO_AS_Status_Return_STRUCT
SAF_DIO_AS_Status_ConvertToVar(union SAF_DIO_AS_Status_UNION o);

extern inline void
SAF_DIO_AS_Status_ConvertToCAN(union SAF_DIO_AS_Status_UNION *o,
                               struct SAF_DIO_AS_Status_Return_STRUCT u);

// ------------------------------- LOG_ASSILEDs --------------------------------

#define LOG_ASSILEDS_ID 0x790
#define LOG_ASSILEDS_DLC 1        // Number of Bytes
#define LOG_ASSILEDS_CYCLE_TIME 0 // Millisecond Period
#define LOG_ASSILEDS_TX_METHODE CAN_MSG_TXM_SPONTANEOUS
#define LOG_ASSILEDS_TRANSMITTER CAN_NW_NODE_DIO_AS

union LOG_ASSILEDs_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Yellow :1;
        uint64_t reserved1 :1;
        uint64_t Blue :1;
        uint64_t reserved2 :5;
    };
};
struct LOG_ASSILEDs_Return_STRUCT
{
    bool Yellow;
    bool Blue;
};

extern inline struct LOG_ASSILEDs_Return_STRUCT
LOG_ASSILEDs_ConvertToVar(union LOG_ASSILEDs_UNION o);

extern inline void
LOG_ASSILEDs_ConvertToCAN(union LOG_ASSILEDs_UNION *o,
                          struct LOG_ASSILEDs_Return_STRUCT u);

// -------------------------------- LSC_Extern_Buttons
// -------------------------------

#define LSC_EXTERN_BUTTONS_ID 0x182
#define LSC_EXTERN_BUTTONS_DLC 1          // Number of Bytes
#define LSC_EXTERN_BUTTONS_CYCLE_TIME 100 // Millisecond Period
#define LSC_EXTERN_BUTTONS_TX_METHODE CAN_MSG_TXM_CYCLIC_AND_SPONTANEOUS
#define LSC_EXTERN_BUTTONS_TRANSMITTER CAN_NW_NODE_DIO_AS

union LSC_Extern_Buttons_UNION
{
    uint64_t data;
    struct
    {
        uint64_t TSA :1;
        uint64_t GEN_SCS :3;
    };
};
struct LSC_Extern_Buttons_Return_STRUCT
{
    bool TSA;
    uint8_t GEN_SCS;
};

extern inline struct LSC_Extern_Buttons_Return_STRUCT
LSC_Extern_Buttons_ConvertToVar(union LSC_Extern_Buttons_UNION o);

extern inline void
LSC_Extern_Buttons_ConvertToCAN(union LSC_Extern_Buttons_UNION *o,
                                struct LSC_Extern_Buttons_Return_STRUCT u);

// -------------------------------- DV_System_Status
// -------------------------------

#define DV_SYSTEM_STATUS_ID 0x502
#define DV_SYSTEM_STATUS_DLC 5          // Number of Bytes
#define DV_SYSTEM_STATUS_CYCLE_TIME 100 // Millisecond Period
#define DV_SYSTEM_STATUS_TX_METHODE CAN_MSG_TXM_CYCLIC
#define DV_SYSTEM_STATUS_TRANSMITTER CAN_NW_NODE_JETSON

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
struct DV_System_Status_Return_STRUCT
{
    enum AS_States AS_State;
    enum EBS_States EBS_State;
    enum AMI_States AMI_State;
    bool SteeringState;
    enum Service_Brake_States ServiceBrakeState;
    uint8_t LapCounter;
    uint8_t ConesCount_Actual;
    uint16_t ConesCount_ALL;
};

extern inline struct DV_System_Status_Return_STRUCT
DV_System_Status_ConvertToVar(union DV_System_Status_UNION o);

extern inline void
DV_System_Status_ConvertToCAN(union DV_System_Status_UNION *o,
                              struct DV_System_Status_Return_STRUCT u);

// -------------------------------- SAF_HSS_RTDS_Status
// -------------------------------

#define SAF_HSS_RTDS_STATUS_ID 0x57
#define SAF_HSS_RTDS_STATUS_DLC 3          // Number of Bytes
#define SAF_HSS_RTDS_STATUS_CYCLE_TIME 100 // Millisecond Period
#define SAF_HSS_RTDS_STATUS_TX_METHODE CAN_MSG_TXM_CYCLIC_AND_SPONTANEOUS
#define SAF_HSS_RTDS_STATUS_TRANSMITTER CAN_NW_NODE_HSS_RTDS

union SAF_HSS_RTDS_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t SCS_ERROR :1;
        uint64_t Message_ERROR :1;
        uint64_t RTDS_ERROR :1;
        uint64_t reserved1 :2;
        uint64_t GEN_SCS :3;
        uint64_t RTDS_Sensing :12;
        uint64_t reserved2 :4;
    };
};
struct SAF_HSS_RTDS_Status_Return_STRUCT
{
    bool SCS_ERROR;
    bool Message_ERROR;
    bool RTDS_ERROR;
    uint8_t GEN_SCS;
    float RTDS_Sensing;
};

extern inline struct SAF_HSS_RTDS_Status_Return_STRUCT
SAF_HSS_RTDS_Status_ConvertToVar(union SAF_HSS_RTDS_Status_UNION o);

extern inline void
SAF_HSS_RTDS_Status_ConvertToCAN(union SAF_HSS_RTDS_Status_UNION *o,
                                 struct SAF_HSS_RTDS_Status_Return_STRUCT u);

// -------------------------------- DV_DriveCommand
// -------------------------------

#define DV_DRIVECOMMAND_ID 0x512
#define DV_DRIVECOMMAND_DLC 5         // Number of Bytes
#define DV_DRIVECOMMAND_CYCLE_TIME 10 // Millisecond Period
#define DV_DRIVECOMMAND_TX_METHODE CAN_MSG_TXM_CYCLIC
#define DV_DRIVECOMMAND_TRANSMITTER CAN_NW_NODE_JETSON

union DV_DriveCommand_UNION
{
    uint64_t data;
    struct
    {
        uint64_t RTD_Request :1;
        uint64_t EBS_Trigger :1;
        uint64_t ThrottleCommand :10;
        uint64_t BrakeCommand :10;
        uint64_t RecuCommand :10;
        uint64_t GEN_SCS :3;
        uint64_t reserved :5;
    };
};
struct DV_DriveCommand_Return_STRUCT
{
    bool RTD_Request;
    bool EBS_Trigger;
    float ThrottleCommand;
    float BrakeCommand;
    float RecuCommand;
    uint8_t GEN_SCS;
};

extern inline struct DV_DriveCommand_Return_STRUCT
DV_DriveCommand_ConvertToVar(union DV_DriveCommand_UNION o);

extern inline void
DV_DriveCommand_ConvertToCAN(union DV_DriveCommand_UNION *o,
                             struct DV_DriveCommand_Return_STRUCT u);

// -------------------------------- SAF_HSS_BL_Status
// -------------------------------

#define SAF_HSS_BL_STATUS_ID 0x56
#define SAF_HSS_BL_STATUS_DLC 3          // Number of Bytes
#define SAF_HSS_BL_STATUS_CYCLE_TIME 100 // Millisecond Period
#define SAF_HSS_BL_STATUS_TX_METHODE CAN_MSG_TXM_CYCLIC_AND_SPONTANEOUS
#define SAF_HSS_BL_STATUS_TRANSMITTER CAN_NW_NODE_HSS_BL

union SAF_HSS_BL_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t SCS_ERROR :1;
        uint64_t Message_ERROR :1;
        uint64_t Brake_Light_ERROR :1;
        uint64_t reserved1 :2;
        uint64_t GEN_SCS :3;
        uint64_t Brake_Light_Sensing :12;
        uint64_t reserved2 :4;
    };
};
struct SAF_HSS_BL_Status_Return_STRUCT
{
    bool SCS_ERROR;
    bool Message_ERROR;
    bool Brake_Light_ERROR;
    uint8_t GEN_SCS;
    float Brake_Light_Sensing;
};

extern inline struct SAF_HSS_BL_Status_Return_STRUCT
SAF_HSS_BL_Status_ConvertToVar(union SAF_HSS_BL_Status_UNION o);

extern inline void
SAF_HSS_BL_Status_ConvertToCAN(union SAF_HSS_BL_Status_UNION *o,
                               struct SAF_HSS_BL_Status_Return_STRUCT u);

// -------------------------------- LOG_LEM --------------------------------

#define LOG_LEM_ID 0x786
#define LOG_LEM_DLC 2           // Number of Bytes
#define LOG_LEM_CYCLE_TIME 1000 // Millisecond Period
#define LOG_LEM_TX_METHODE CAN_MSG_TXM_CYCLIC
#define LOG_LEM_TRANSMITTER CAN_NW_NODE_AIN_R1

union LOG_LEM_UNION
{
    uint64_t data;
    struct
    {
        uint64_t LV_current :16;
    };
};
struct LOG_LEM_Return_STRUCT
{
    uint16_t LV_current;
};

extern inline struct LOG_LEM_Return_STRUCT
LOG_LEM_ConvertToVar(union LOG_LEM_UNION o);

extern inline void LOG_LEM_ConvertToCAN(union LOG_LEM_UNION *o,
                                        struct LOG_LEM_Return_STRUCT u);

// -------------------------------- LOG_SpringTravel_Front
// --------------------------------
#define LOG_SprTra_F_ID 0x783
#define LOG_SprTra_F_DLC 4
#define LOG_SprTra_F_CYCLE_TIME 100
#define LOG_SprTra_F_METHODE CAN_MSG_TXM_CYCLIC
#define LOG_SprTra_F_TRANSMITTER CAN_NW_NODE_AIN_F2

union LOG_SprTra_F_UNION
{
    uint64_t data;
    struct
    {
        uint64_t FrontLeft :16;
        uint64_t FrontRight :16;
    };
};

struct LOG_SprTra_F_Return_STRUCT
{
    int16_t FrontLeft;
    int16_t FrontRight;
};

extern inline struct LOG_SprTra_F_Return_STRUCT
LOG_SprTra_F_ConvertToVar(union LOG_SprTra_F_UNION o);

extern inline void
LOG_SprTra_F_ConvertToCAN(union LOG_SprTra_F_UNION *o,
                          struct LOG_SprTra_F_Return_STRUCT u);

// -------------------------------- LOG_SpringTravel_Front 
// --------------------------------
///todo fix ID
#define LOG_SprTra_R_ID 0x783
#define LOG_SprTra_R_DLC 4
#define LOG_SprTra_R_CYCLE_TIME 100
#define LOG_SprTra_R_METHODE CAN_MSG_TXM_CYCLIC
#define LOG_SprTra_R_TRANSMITTER CAN_NW_NODE_AIN_F2

union LOG_SprTra_R_UNION
{
    uint64_t data;
    struct
    {
        uint64_t RearLeft :16;
        uint64_t RearRight :16;
    };
};

struct LOG_SprTra_R_Return_STRUCT
{
    int16_t RearLeft;
    int16_t RearRight;
};

extern inline struct LOG_SprTra_R_Return_STRUCT
LOG_SprTra_R_ConvertToVar(union LOG_SprTra_R_UNION o);

extern inline void
LOG_SprTra_R_ConvertToCAN(union LOG_SprTra_R_UNION *o,
                          struct LOG_SprTra_R_Return_STRUCT u);

#endif /* SYSTEM_LIB_SYSTEM_DBC_H */
