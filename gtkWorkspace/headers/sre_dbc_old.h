
/*
 * Generated Header File from DBC
 * Auto-generated using Python SIU
 */
#ifndef SRE_DBC_H
#define SRE_DBC_H

#include <inttypes.h>
#include <stdbool.h>

// ----------------------------- LOG_SBG_ODO_INFO ----------------------------
#define LOG_SBG_ODO_INFO_ID 0x128
#define LOG_SBG_ODO_INFO_DLC 6         // Number of Bytes

union LOG_SBG_ODO_INFO_UNION
{
    uint64_t data;
    struct
    {
        uint64_t time_stamp : 32;
        uint64_t odo_real_meas : 1;
        uint64_t odo_time_sync : 1;
        uint64_t reserved : 30;
    };
};

// ----------------------------- HSC_SBG_POSITION_ACC ----------------------------
#define HSC_SBG_POSITION_ACC_ID 0x120
#define HSC_SBG_POSITION_ACC_DLC 6         // Number of Bytes

union HSC_SBG_POSITION_ACC_UNION
{
    uint64_t data;
    struct
    {
        uint64_t latitude_acc : 16;
        uint64_t longitude_acc : 16;
        uint64_t altitude_acc : 16;
        uint64_t reserved : 16;
    };
};

// ----------------------------- HSC_SBG_EULER_ACC ----------------------------
#define HSC_SBG_EULER_ACC_ID 0x11d
#define HSC_SBG_EULER_ACC_DLC 6         // Number of Bytes

union HSC_SBG_EULER_ACC_UNION
{
    uint64_t data;
    struct
    {
        uint64_t roll_acc : 16;
        uint64_t pitch_acc : 16;
        uint64_t yaw_acc : 16;
        uint64_t reserved : 16;
    };
};

// ----------------------------- HSC_SBG_EULER ----------------------------
#define HSC_SBG_EULER_ID 0x11c
#define HSC_SBG_EULER_DLC 6         // Number of Bytes

union HSC_SBG_EULER_UNION
{
    uint64_t data;
    struct
    {
        uint64_t roll : 16;
        uint64_t pitch : 16;
        uint64_t yaw : 16;
        uint64_t reserved : 16;
    };
};

// ----------------------------- LOG_SBG_EKF_INFO ----------------------------
#define LOG_SBG_EKF_INFO_ID 0x11a
#define LOG_SBG_EKF_INFO_DLC 4         // Number of Bytes

union LOG_SBG_EKF_INFO_UNION
{
    uint64_t data;
    struct
    {
        uint64_t time_stamp : 32;
        uint64_t reserved : 32;
    };
};

// ----------------------------- LOG_SBG_IMU_INFO ----------------------------
#define LOG_SBG_IMU_INFO_ID 0x115
#define LOG_SBG_IMU_INFO_DLC 8         // Number of Bytes

union LOG_SBG_IMU_INFO_UNION
{
    uint64_t data;
    struct
    {
        uint64_t time_stamp : 32;
        uint64_t temperature : 16;
        uint64_t reserved : 16;
    };
};

// ----------------------------- LOG_TireForces ----------------------------
#define LOG_TIREFORCES_ID 0x793
#define LOG_TIREFORCES_DLC 8         // Number of Bytes

union LOG_TireForces_UNION
{
    uint64_t data;
    struct
    {
        uint64_t TireForce_FL : 16;
        uint64_t TireForce_FR : 16;
        uint64_t TireForce_RL : 16;
        uint64_t TireForce_RR : 16;
    };
};

// ----------------------------- LOG_slip_ratio ----------------------------
#define LOG_SLIP_RATIO_ID 0x792
#define LOG_SLIP_RATIO_DLC 8         // Number of Bytes

union LOG_slip_ratio_UNION
{
    uint64_t data;
    struct
    {
        uint64_t slip_ratio_FL : 16;
        uint64_t slip_ratio_FR : 16;
        uint64_t slip_ratio_RL : 16;
        uint64_t slip_ratio_RR : 16;
    };
};

// ----------------------------- LOG_TV_request ----------------------------
#define LOG_TV_REQUEST_ID 0x794
#define LOG_TV_REQUEST_DLC 8         // Number of Bytes

union LOG_TV_request_UNION
{
    uint64_t data;
    struct
    {
        uint64_t TV_FL : 8;
        uint64_t TV_FR : 8;
        uint64_t TV_RR : 8;
        uint64_t TV_RL : 8;
        uint64_t reserved : 32;
    };
};

// ----------------------------- LOG_slip_angle ----------------------------
#define LOG_SLIP_ANGLE_ID 0x791
#define LOG_SLIP_ANGLE_DLC 8         // Number of Bytes

union LOG_slip_angle_UNION
{
    uint64_t data;
    struct
    {
        uint64_t slip_angle_FL : 16;
        uint64_t slip_angle_FR : 16;
        uint64_t slip_angle_RL : 16;
        uint64_t slip_angle_RR : 16;
    };
};

// ----------------------------- HSC_SBG_TRUE_HEADING ----------------------------
#define HSC_SBG_TRUE_HEADING_ID 0x136
#define HSC_SBG_TRUE_HEADING_DLC 8         // Number of Bytes

union HSC_SBG_TRUE_HEADING_UNION
{
    uint64_t data;
    struct
    {
        uint64_t true_heading : 16;
        uint64_t true_heading_acc : 16;
        uint64_t pitch : 16;
        uint64_t reserved : 16;
    };
};

// ----------------------------- HSC_SBG_ALTITUDE ----------------------------
#define HSC_SBG_ALTITUDE_ID 0x11f
#define HSC_SBG_ALTITUDE_DLC 6         // Number of Bytes

union HSC_SBG_ALTITUDE_UNION
{
    uint64_t data;
    struct
    {
        uint64_t altitude : 32;
        uint64_t undulation : 16;
        uint64_t reserved : 16;
    };
};

// ----------------------------- HSC_SBG_POSITION ----------------------------
#define HSC_SBG_POSITION_ID 0x11e
#define HSC_SBG_POSITION_DLC 8         // Number of Bytes

union HSC_SBG_POSITION_UNION
{
    uint64_t data;
    struct
    {
        uint64_t latitude : 32;
        uint64_t longitude : 32;
    };
};

// ----------------------------- LOG_SBG_HEADING_INFO ----------------------------
#define LOG_SBG_HEADING_INFO_ID 0x135
#define LOG_SBG_HEADING_INFO_DLC 6         // Number of Bytes

union LOG_SBG_HEADING_INFO_UNION
{
    uint64_t data;
    struct
    {
        uint64_t time_stamp : 32;
        uint64_t reserved : 32;
    };
};

// ----------------------------- LOG_SBG_POS_INFO ----------------------------
#define LOG_SBG_POS_INFO_ID 0x131
#define LOG_SBG_POS_INFO_DLC 8         // Number of Bytes

union LOG_SBG_POS_INFO_UNION
{
    uint64_t data;
    struct
    {
        uint64_t time_stamp : 32;
        uint64_t reserved : 32;
    };
};

// ----------------------------- LOG_SBG_GPS1_VEL_INFO ----------------------------
#define LOG_SBG_GPS1_VEL_INFO_ID 0x12d
#define LOG_SBG_GPS1_VEL_INFO_DLC 8         // Number of Bytes

union LOG_SBG_GPS1_VEL_INFO_UNION
{
    uint64_t data;
    struct
    {
        uint64_t time_stamp : 32;
        uint64_t reserved : 32;
    };
};

// ----------------------------- LOG_SBG_STATUS_03 ----------------------------
#define LOG_SBG_STATUS_03_ID 0x112
#define LOG_SBG_STATUS_03_DLC 6         // Number of Bytes

union LOG_SBG_STATUS_03_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- LOG_SBG_STATUS_02 ----------------------------
#define LOG_SBG_STATUS_02_ID 0x111
#define LOG_SBG_STATUS_02_DLC 8         // Number of Bytes

union LOG_SBG_STATUS_02_UNION
{
    uint64_t data;
    struct
    {
        uint64_t sbg_porta_valid : 1;
        uint64_t sbg_portb_valid : 1;
        uint64_t sbg_porta_rx_ok : 1;
        uint64_t sbg_porta_tx_ok : 1;
        uint64_t sbg_portb_rx_ok : 1;
        uint64_t sbg_can_valid : 1;
        uint64_t sbg_can_rx_ok : 1;
        uint64_t sbg_can_tx_ok : 1;
        uint64_t reserved : 56;
    };
};

// ----------------------------- LOG_SBG_STATUS_01 ----------------------------
#define LOG_SBG_STATUS_01_ID 0x110
#define LOG_SBG_STATUS_01_DLC 8         // Number of Bytes

union LOG_SBG_STATUS_01_UNION
{
    uint64_t data;
    struct
    {
        uint64_t sbg_time_stamp : 32;
        uint64_t sbg_main_power_ok : 1;
        uint64_t sbg_imu_power_ok : 1;
        uint64_t sbg_gps_power_ok : 1;
        uint64_t sbg_settings_ok : 1;
        uint64_t sbg_temp_ok : 1;
        uint64_t sbg_datalogger_ok : 1;
        uint64_t sbg_cpu_ok : 1;
        uint64_t reserved : 25;
    };
};

// ----------------------------- HSC_SBG_TRACK_SLIP_CURVE ----------------------------
#define HSC_SBG_TRACK_SLIP_CURVE_ID 0x124
#define HSC_SBG_TRACK_SLIP_CURVE_DLC 7         // Number of Bytes

union HSC_SBG_TRACK_SLIP_CURVE_UNION
{
    uint64_t data;
    struct
    {
        uint64_t angle_track : 16;
        uint64_t angle_slip : 16;
        uint64_t curvature_radius : 16;
        uint64_t track_valid : 1;
        uint64_t slip_valid : 1;
        uint64_t curvature_valid : 1;
        uint64_t reserved : 13;
    };
};

// ----------------------------- HSC_SBG_EKF_VEL_BODY ----------------------------
#define HSC_SBG_EKF_VEL_BODY_ID 0x123
#define HSC_SBG_EKF_VEL_BODY_DLC 6         // Number of Bytes

union HSC_SBG_EKF_VEL_BODY_UNION
{
    uint64_t data;
    struct
    {
        uint64_t velocity_x : 16;
        uint64_t velocity_y : 16;
        uint64_t velocity_z : 16;
        uint64_t reserved : 16;
    };
};

// ----------------------------- HSC_SBG_GYRO ----------------------------
#define HSC_SBG_GYRO_ID 0x117
#define HSC_SBG_GYRO_DLC 6         // Number of Bytes

union HSC_SBG_GYRO_UNION
{
    uint64_t data;
    struct
    {
        uint64_t gyro_x : 16;
        uint64_t gyro_y : 16;
        uint64_t gyro_z : 16;
        uint64_t reserved : 16;
    };
};

// ----------------------------- HSC_SBG_ACCEL ----------------------------
#define HSC_SBG_ACCEL_ID 0x116
#define HSC_SBG_ACCEL_DLC 6         // Number of Bytes

union HSC_SBG_ACCEL_UNION
{
    uint64_t data;
    struct
    {
        uint64_t accel_x : 16;
        uint64_t accel_y : 16;
        uint64_t accel_z : 16;
        uint64_t reserved : 16;
    };
};

// ----------------------------- GW_Battery_Cells ----------------------------
#define GW_BATTERY_CELLS_ID 0x386
#define GW_BATTERY_CELLS_DLC 7         // Number of Bytes

union GW_Battery_Cells_UNION
{
    uint64_t data;
    struct
    {
        uint64_t TempMin : 7;
        uint64_t TempAvg : 7;
        uint64_t TempMax : 7;
        uint64_t Voltage_Min : 16;
        uint64_t Voltage_Max : 16;
        uint64_t reserved : 11;
    };
};

// ----------------------------- GW_Battery_Status ----------------------------
#define GW_BATTERY_STATUS_ID 0x385
#define GW_BATTERY_STATUS_DLC 4         // Number of Bytes

union GW_Battery_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t State : 4;
        uint64_t SOC_Internal : 14;
        uint64_t Power : 14;
        uint64_t reserved : 32;
    };
};

// ----------------------------- GW_PE_FrontLeft ----------------------------
#define GW_PE_FRONTLEFT_ID 0x384
#define GW_PE_FRONTLEFT_DLC 8         // Number of Bytes

union GW_PE_FrontLeft_UNION
{
    uint64_t data;
    struct
    {
        uint64_t TempMotor : 16;
        uint64_t TempInverter : 16;
        uint64_t TempIGBT : 16;
        uint64_t ActualVelocity : 16;
    };
};

// ----------------------------- GW_PE_RearLeft ----------------------------
#define GW_PE_REARLEFT_ID 0x383
#define GW_PE_REARLEFT_DLC 8         // Number of Bytes

union GW_PE_RearLeft_UNION
{
    uint64_t data;
    struct
    {
        uint64_t TempMotor : 16;
        uint64_t TempInverter : 16;
        uint64_t TempIGBT : 16;
        uint64_t ActualVelocity : 16;
    };
};

// ----------------------------- GW_PE_RearRight ----------------------------
#define GW_PE_REARRIGHT_ID 0x382
#define GW_PE_REARRIGHT_DLC 8         // Number of Bytes

union GW_PE_RearRight_UNION
{
    uint64_t data;
    struct
    {
        uint64_t TempMotor : 16;
        uint64_t TempInverter : 16;
        uint64_t TempIGBT : 16;
        uint64_t ActualVelocity : 16;
    };
};

// ----------------------------- GW_PE_FrontRight ----------------------------
#define GW_PE_FRONTRIGHT_ID 0x381
#define GW_PE_FRONTRIGHT_DLC 8         // Number of Bytes

union GW_PE_FrontRight_UNION
{
    uint64_t data;
    struct
    {
        uint64_t TempMotor : 16;
        uint64_t TempInverter : 16;
        uint64_t TempIGBT : 16;
        uint64_t ActualVelocity : 16;
    };
};

// ----------------------------- EXC_BATFAN_Control ----------------------------
#define EXC_BATFAN_CONTROL_ID 0x412
#define EXC_BATFAN_CONTROL_DLC 1         // Number of Bytes

union EXC_BATFAN_Control_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Fan_request : 7;
        uint64_t Fan_On : 1;
        uint64_t reserved : 56;
    };
};

// ----------------------------- LOG_ASSILEDs ----------------------------
#define LOG_ASSILEDS_ID 0x790
#define LOG_ASSILEDS_DLC 1         // Number of Bytes

union LOG_ASSILEDs_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Yellow : 1;
        uint64_t Blue : 1;
        uint64_t reserved : 62;
    };
};

// ----------------------------- HSC_IMU_Rear ----------------------------
#define HSC_IMU_REAR_ID 0x107
#define HSC_IMU_REAR_DLC 8         // Number of Bytes

union HSC_IMU_Rear_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- HSC_IMU_Front ----------------------------
#define HSC_IMU_FRONT_ID 0x106
#define HSC_IMU_FRONT_DLC 8         // Number of Bytes

union HSC_IMU_Front_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- EXC_FAN_Control ----------------------------
#define EXC_FAN_CONTROL_ID 0x40f
#define EXC_FAN_CONTROL_DLC 1         // Number of Bytes

union EXC_FAN_Control_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Fan_request : 7;
        uint64_t Fan_On : 1;
        uint64_t reserved : 56;
    };
};

// ----------------------------- EXC_PUMP_Control ----------------------------
#define EXC_PUMP_CONTROL_ID 0x410
#define EXC_PUMP_CONTROL_DLC 1         // Number of Bytes

union EXC_PUMP_Control_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Pump_request : 7;
        uint64_t Pump_On : 1;
        uint64_t reserved : 56;
    };
};

// ----------------------------- HSC_Vehicle_Status ----------------------------
#define HSC_VEHICLE_STATUS_ID 0x103
#define HSC_VEHICLE_STATUS_DLC 8         // Number of Bytes

union HSC_Vehicle_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t State : 3;
        uint64_t IMD_ERROR : 1;
        uint64_t AMS_ERROR : 1;
        uint64_t GEN_SCS : 3;
        uint64_t Velocity : 8;
        uint64_t velocity_ms : 16;
        uint64_t slip_angle : 16;
        uint64_t reserved : 16;
    };
};

// ----------------------------- LSC_Extern_Buttons ----------------------------
#define LSC_EXTERN_BUTTONS_ID 0x182
#define LSC_EXTERN_BUTTONS_DLC 1         // Number of Bytes

union LSC_Extern_Buttons_UNION
{
    uint64_t data;
    struct
    {
        uint64_t TSA : 1;
        uint64_t GEN_SCS : 3;
        uint64_t reserved : 60;
    };
};

// ----------------------------- LSC_Dash_Buttons ----------------------------
#define LSC_DASH_BUTTONS_ID 0x181
#define LSC_DASH_BUTTONS_DLC 2         // Number of Bytes

union LSC_Dash_Buttons_UNION
{
    uint64_t data;
    struct
    {
        uint64_t TSA : 1;
        uint64_t RTD : 1;
        uint64_t Logging : 1;
        uint64_t GEN_SCS : 3;
        uint64_t Display_Enter_Long : 1;
        uint64_t Display_Backwards_Long : 1;
        uint64_t Display_Enter : 1;
        uint64_t Display_Backwards : 1;
        uint64_t Display_Forwards : 1;
        uint64_t Display_Forwards_Long : 1;
        uint64_t reserved : 52;
    };
};

// ----------------------------- SAF_IMU_R_Status ----------------------------
#define SAF_IMU_R_STATUS_ID 0x59
#define SAF_IMU_R_STATUS_DLC 1         // Number of Bytes

union SAF_IMU_R_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t SCS_ERROR : 1;
        uint64_t I2C_Node_ERROR : 1;
        uint64_t GEN_SCS : 3;
        uint64_t reserved : 59;
    };
};

// ----------------------------- SAF_IMU_F_Status ----------------------------
#define SAF_IMU_F_STATUS_ID 0x58
#define SAF_IMU_F_STATUS_DLC 1         // Number of Bytes

union SAF_IMU_F_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t SCS_ERROR : 1;
        uint64_t I2C_Node_ERROR : 1;
        uint64_t GEN_SCS : 3;
        uint64_t reserved : 59;
    };
};

// ----------------------------- SAF_HSS_RTDS_Status ----------------------------
#define SAF_HSS_RTDS_STATUS_ID 0x57
#define SAF_HSS_RTDS_STATUS_DLC 3         // Number of Bytes

union SAF_HSS_RTDS_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t SCS_ERROR : 1;
        uint64_t Message_ERROR : 1;
        uint64_t RTDS_ERROR : 1;
        uint64_t GEN_SCS : 3;
        uint64_t RTDS_Sensing : 12;
        uint64_t reserved : 46;
    };
};

// ----------------------------- SAF_HSS_REAR_Status ----------------------------
#define SAF_HSS_REAR_STATUS_ID 0x56
#define SAF_HSS_REAR_STATUS_DLC 3         // Number of Bytes

union SAF_HSS_REAR_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t SCS_ERROR : 1;
        uint64_t Message_ERROR : 1;
        uint64_t Brake_Light_ERROR : 1;
        uint64_t GEN_SCS : 3;
        uint64_t Brake_Light_Sensing : 12;
        uint64_t reserved : 46;
    };
};

// ----------------------------- SAF_DIO_AS_Status ----------------------------
#define SAF_DIO_AS_STATUS_ID 0x55
#define SAF_DIO_AS_STATUS_DLC 1         // Number of Bytes

union SAF_DIO_AS_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t SCS_ERROR : 1;
        uint64_t Message_ERROR : 1;
        uint64_t Output_NoChange_ERROR : 1;
        uint64_t GEN_SCS : 3;
        uint64_t reserved : 58;
    };
};

// ----------------------------- SAF_DIO_DASH_Status ----------------------------
#define SAF_DIO_DASH_STATUS_ID 0x54
#define SAF_DIO_DASH_STATUS_DLC 1         // Number of Bytes

union SAF_DIO_DASH_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t SCS_ERROR : 1;
        uint64_t Message_ERROR : 1;
        uint64_t Output_NoChange_ERROR : 1;
        uint64_t GEN_SCS : 3;
        uint64_t reserved : 58;
    };
};

// ----------------------------- SAF_AIN_F2_Status ----------------------------
#define SAF_AIN_F2_STATUS_ID 0x52
#define SAF_AIN_F2_STATUS_DLC 1         // Number of Bytes

union SAF_AIN_F2_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t SCS_ERROR : 1;
        uint64_t Steering_ERROR : 1;
        uint64_t GEN_SCS : 3;
        uint64_t reserved : 59;
    };
};

// ----------------------------- SAF_AIN_F1_Status ----------------------------
#define SAF_AIN_F1_STATUS_ID 0x51
#define SAF_AIN_F1_STATUS_DLC 1         // Number of Bytes

union SAF_AIN_F1_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t SCS_ERROR : 1;
        uint64_t Throttle_Lower_ERROR : 1;
        uint64_t Throttle_Upper_ERROR : 1;
        uint64_t Throttle_Differential_ERROR : 1;
        uint64_t Brake_ERROR : 1;
        uint64_t GEN_SCS : 3;
        uint64_t reserved : 56;
    };
};

// ----------------------------- SAF_ECU_Status ----------------------------
#define SAF_ECU_STATUS_ID 0x50
#define SAF_ECU_STATUS_DLC 1         // Number of Bytes

union SAF_ECU_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t SCS_ERROR : 1;
        uint64_t Message_ERROR : 1;
        uint64_t GEN_SCS : 3;
        uint64_t reserved : 59;
    };
};

// ----------------------------- HSC_Steering ----------------------------
#define HSC_STEERING_ID 0x105
#define HSC_STEERING_DLC 4         // Number of Bytes

union HSC_Steering_UNION
{
    uint64_t data;
    struct
    {
        uint64_t SteeringWheel_Angle : 12;
        uint64_t Steering_Angle : 12;
        uint64_t Angle_Valid : 1;
        uint64_t GEN_SCS : 3;
        uint64_t reserved : 36;
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
        uint64_t Throttle : 16;
        uint64_t Brake_Pressed : 1;
        uint64_t Throttle_Valid : 1;
        uint64_t Brake_Valid : 1;
        uint64_t GEN_SCS : 3;
        uint64_t reserved : 42;
    };
};

// ----------------------------- CANO_RES_NMT_EC ----------------------------
#define CANO_RES_NMT_EC_ID 0x711
#define CANO_RES_NMT_EC_DLC 1         // Number of Bytes

union CANO_RES_NMT_EC_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- CANO_EPOS_NMT_EC ----------------------------
#define CANO_EPOS_NMT_EC_ID 0x70c
#define CANO_EPOS_NMT_EC_DLC 1         // Number of Bytes

union CANO_EPOS_NMT_EC_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- CANO_RES_RSDO ----------------------------
#define CANO_RES_RSDO_ID 0x611
#define CANO_RES_RSDO_DLC 8         // Number of Bytes

union CANO_RES_RSDO_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- CANO_EPOS_RSDO ----------------------------
#define CANO_EPOS_RSDO_ID 0x60c
#define CANO_EPOS_RSDO_DLC 8         // Number of Bytes

union CANO_EPOS_RSDO_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- CANO_RES_TSDO ----------------------------
#define CANO_RES_TSDO_ID 0x591
#define CANO_RES_TSDO_DLC 8         // Number of Bytes

union CANO_RES_TSDO_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- CANO_EPOS_TSDO ----------------------------
#define CANO_EPOS_TSDO_ID 0x58c
#define CANO_EPOS_TSDO_DLC 8         // Number of Bytes

union CANO_EPOS_TSDO_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- DV_FREE_TO_USE_2 ----------------------------
#define DV_FREE_TO_USE_2_ID 0x514
#define DV_FREE_TO_USE_2_DLC 0         // Number of Bytes

union DV_FREE_TO_USE_2_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- CANO_RES_EMCY ----------------------------
#define CANO_RES_EMCY_ID 0x91
#define CANO_RES_EMCY_DLC 8         // Number of Bytes

union CANO_RES_EMCY_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- DV_SCS_Errors ----------------------------
#define DV_SCS_ERRORS_ID 0x511
#define DV_SCS_ERRORS_DLC 8         // Number of Bytes

union DV_SCS_Errors_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- DV_AMI_Status ----------------------------
#define DV_AMI_STATUS_ID 0x505
#define DV_AMI_STATUS_DLC 1         // Number of Bytes

union DV_AMI_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t State : 3;
        uint64_t GEN_SCS : 3;
        uint64_t reserved : 58;
    };
};

// ----------------------------- DV_ASB_Pressure ----------------------------
#define DV_ASB_PRESSURE_ID 0x513
#define DV_ASB_PRESSURE_DLC 3         // Number of Bytes

union DV_ASB_Pressure_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Pressure1 : 12;
        uint64_t Pressure2 : 12;
        uint64_t reserved : 40;
    };
};

// ----------------------------- DV_DrivingDynamics1 ----------------------------
#define DV_DRIVINGDYNAMICS1_ID 0x500
#define DV_DRIVINGDYNAMICS1_DLC 8         // Number of Bytes

union DV_DrivingDynamics1_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Speed_Actual : 8;
        uint64_t Speed_Target : 8;
        uint64_t SteeringAngle_Actual : 8;
        uint64_t SteeringAngle_Target : 8;
        uint64_t BrakeHydr_Actual : 8;
        uint64_t BrakeHydr_Target : 8;
        uint64_t MotorMoment_Actual : 8;
        uint64_t MotorMoment_Target : 8;
    };
};

// ----------------------------- DV_DrivingDynamics2 ----------------------------
#define DV_DRIVINGDYNAMICS2_ID 0x501
#define DV_DRIVINGDYNAMICS2_DLC 6         // Number of Bytes

union DV_DrivingDynamics2_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Acceleration_Longitudinal : 16;
        uint64_t Acceleration_Lateral : 16;
        uint64_t YawRate : 16;
        uint64_t reserved : 16;
    };
};

// ----------------------------- DV_System_Status ----------------------------
#define DV_SYSTEM_STATUS_ID 0x502
#define DV_SYSTEM_STATUS_DLC 5         // Number of Bytes

union DV_System_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t AS_State : 3;
        uint64_t EBS_State : 2;
        uint64_t AMI_State : 3;
        uint64_t SteeringState : 1;
        uint64_t ServiceBrakeState : 2;
        uint64_t LapCounter : 4;
        uint64_t ConesCount_Actual : 8;
        uint64_t ConesCount_All : 17;
        uint64_t reserved : 24;
    };
};

// ----------------------------- DV_ASB_Status ----------------------------
#define DV_ASB_STATUS_ID 0x503
#define DV_ASB_STATUS_DLC 3         // Number of Bytes

union DV_ASB_Status_UNION
{
    uint64_t data;
    struct
    {
        uint64_t ASMS : 1;
        uint64_t EBS_State : 2;
        uint64_t ServiceBrakeState : 2;
        uint64_t CheckSequence : 3;
        uint64_t CheckupComplete : 1;
        uint64_t SDC_Closed : 1;
        uint64_t SCS_ERROR : 1;
        uint64_t TriggerCause : 4;
        uint64_t State : 3;
        uint64_t GEN_SCS : 3;
        uint64_t reserved : 43;
    };
};

// ----------------------------- CANO_RES_TPDO4 ----------------------------
#define CANO_RES_TPDO4_ID 0x491
#define CANO_RES_TPDO4_DLC 0         // Number of Bytes

union CANO_RES_TPDO4_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- CANO_RES_TPDO3 ----------------------------
#define CANO_RES_TPDO3_ID 0x391
#define CANO_RES_TPDO3_DLC 0         // Number of Bytes

union CANO_RES_TPDO3_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- CANO_RES_TPDO2 ----------------------------
#define CANO_RES_TPDO2_ID 0x291
#define CANO_RES_TPDO2_DLC 0         // Number of Bytes

union CANO_RES_TPDO2_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- CANO_RES_RPDO3 ----------------------------
#define CANO_RES_RPDO3_ID 0x411
#define CANO_RES_RPDO3_DLC 0         // Number of Bytes

union CANO_RES_RPDO3_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- CANO_RES_RPDO2 ----------------------------
#define CANO_RES_RPDO2_ID 0x311
#define CANO_RES_RPDO2_DLC 0         // Number of Bytes

union CANO_RES_RPDO2_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- CANO_RES_RPDO1 ----------------------------
#define CANO_RES_RPDO1_ID 0x211
#define CANO_RES_RPDO1_DLC 0         // Number of Bytes

union CANO_RES_RPDO1_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- CANO_EPOS_RPDO4 ----------------------------
#define CANO_EPOS_RPDO4_ID 0x50c
#define CANO_EPOS_RPDO4_DLC 6         // Number of Bytes

union CANO_EPOS_RPDO4_UNION
{
    uint64_t data;
    struct
    {
        uint64_t controlword : 16;
        uint64_t target_velocity : 32;
        uint64_t reserved : 16;
    };
};

// ----------------------------- CANO_EPOS_RPDO3 ----------------------------
#define CANO_EPOS_RPDO3_ID 0x40c
#define CANO_EPOS_RPDO3_DLC 6         // Number of Bytes

union CANO_EPOS_RPDO3_UNION
{
    uint64_t data;
    struct
    {
        uint64_t controlword : 16;
        uint64_t target_position : 32;
        uint64_t reserved : 16;
    };
};

// ----------------------------- CANO_EPOS_RPDO2 ----------------------------
#define CANO_EPOS_RPDO2_ID 0x30c
#define CANO_EPOS_RPDO2_DLC 3         // Number of Bytes

union CANO_EPOS_RPDO2_UNION
{
    uint64_t data;
    struct
    {
        uint64_t controlword : 16;
        uint64_t modes_of_operation : 8;
        uint64_t reserved : 40;
    };
};

// ----------------------------- CANO_EPOS_RPDO1 ----------------------------
#define CANO_EPOS_RPDO1_ID 0x20c
#define CANO_EPOS_RPDO1_DLC 2         // Number of Bytes

union CANO_EPOS_RPDO1_UNION
{
    uint64_t data;
    struct
    {
        uint64_t controlword : 16;
        uint64_t reserved : 48;
    };
};

// ----------------------------- CANO_RES_State ----------------------------
#define CANO_RES_STATE_ID 0x191
#define CANO_RES_STATE_DLC 8         // Number of Bytes

union CANO_RES_State_UNION
{
    uint64_t data;
    struct
    {
        uint64_t K1_eStop : 1;
        uint64_t K2_Switch : 1;
        uint64_t K3_Button : 1;
        uint64_t LinkQuality : 8;
        uint64_t PreAlarm : 1;
        uint64_t RaceMode : 1;
        uint64_t reserved : 51;
    };
};

// ----------------------------- CANO_EPOS_TPDO4 ----------------------------
#define CANO_EPOS_TPDO4_ID 0x48c
#define CANO_EPOS_TPDO4_DLC 6         // Number of Bytes

union CANO_EPOS_TPDO4_UNION
{
    uint64_t data;
    struct
    {
        uint64_t statusword : 16;
        uint64_t velocity_actual_value : 32;
        uint64_t reserved : 16;
    };
};

// ----------------------------- CANO_EPOS_TPDO3 ----------------------------
#define CANO_EPOS_TPDO3_ID 0x38c
#define CANO_EPOS_TPDO3_DLC 6         // Number of Bytes

union CANO_EPOS_TPDO3_UNION
{
    uint64_t data;
    struct
    {
        uint64_t statusword : 16;
        uint64_t position_actual_value : 32;
        uint64_t reserved : 16;
    };
};

// ----------------------------- CANO_EPOS_TPDO2 ----------------------------
#define CANO_EPOS_TPDO2_ID 0x28c
#define CANO_EPOS_TPDO2_DLC 3         // Number of Bytes

union CANO_EPOS_TPDO2_UNION
{
    uint64_t data;
    struct
    {
        uint64_t statusword : 16;
        uint64_t modes_of_operation_disp : 8;
        uint64_t reserved : 40;
    };
};

// ----------------------------- CANO_EPOS_TPDO1 ----------------------------
#define CANO_EPOS_TPDO1_ID 0x18c
#define CANO_EPOS_TPDO1_DLC 2         // Number of Bytes

union CANO_EPOS_TPDO1_UNION
{
    uint64_t data;
    struct
    {
        uint64_t statusword : 16;
        uint64_t reserved : 48;
    };
};

// ----------------------------- CANO_TIME ----------------------------
#define CANO_TIME_ID 0x100
#define CANO_TIME_DLC 6         // Number of Bytes

union CANO_TIME_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- CANO_EPOS_EMCY ----------------------------
#define CANO_EPOS_EMCY_ID 0x8c
#define CANO_EPOS_EMCY_DLC 8         // Number of Bytes

union CANO_EPOS_EMCY_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- CANO_SYNC ----------------------------
#define CANO_SYNC_ID 0x80
#define CANO_SYNC_DLC 0         // Number of Bytes

union CANO_SYNC_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- CANO_NMT_Node_Control ----------------------------
#define CANO_NMT_NODE_CONTROL_ID 0x0
#define CANO_NMT_NODE_CONTROL_DLC 2         // Number of Bytes

union CANO_NMT_Node_Control_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Requested_State : 8;
        uint64_t Addressed_Node_ID : 8;
        uint64_t reserved : 48;
    };
};

// ----------------------------- CAL_SteeringAngle ----------------------------
#define CAL_STEERINGANGLE_ID 0x490
#define CAL_STEERINGANGLE_DLC 2         // Number of Bytes

union CAL_SteeringAngle_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Voltage : 12;
        uint64_t reserved : 52;
    };
};

// ----------------------------- CAL_APPS ----------------------------
#define CAL_APPS_ID 0x48f
#define CAL_APPS_DLC 6         // Number of Bytes

union CAL_APPS_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Upper_3V3 : 12;
        uint64_t Lower_3V3 : 12;
        uint64_t Upper_5V : 12;
        uint64_t Lower_5V : 12;
        uint64_t reserved : 16;
    };
};

// ----------------------------- CAL_BrakePressures ----------------------------
#define CAL_BRAKEPRESSURES_ID 0x485
#define CAL_BRAKEPRESSURES_DLC 6         // Number of Bytes

union CAL_BrakePressures_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Front_3V3 : 12;
        uint64_t Rear_3V3 : 12;
        uint64_t Front_5V : 12;
        uint64_t Rear_5V : 12;
        uint64_t reserved : 16;
    };
};

// ----------------------------- CAL_SpringTravel_Rear ----------------------------
#define CAL_SPRINGTRAVEL_REAR_ID 0x484
#define CAL_SPRINGTRAVEL_REAR_DLC 7         // Number of Bytes

union CAL_SpringTravel_Rear_UNION
{
    uint64_t data;
    struct
    {
        uint64_t RearRight_Converted : 16;
        uint64_t RearLeft_Converted : 16;
        uint64_t RearRight_Voltage : 12;
        uint64_t RearLeft_Voltage : 12;
        uint64_t reserved : 8;
    };
};

// ----------------------------- CAL_SpringTravel_Front ----------------------------
#define CAL_SPRINGTRAVEL_FRONT_ID 0x483
#define CAL_SPRINGTRAVEL_FRONT_DLC 7         // Number of Bytes

union CAL_SpringTravel_Front_UNION
{
    uint64_t data;
    struct
    {
        uint64_t FrontRight_Converted : 16;
        uint64_t FrontLeft_Converted : 16;
        uint64_t FrontRight_Voltage : 12;
        uint64_t FrontLeft_Voltage : 12;
        uint64_t reserved : 8;
    };
};

// ----------------------------- CAL_CalibrationMaster ----------------------------
#define CAL_CALIBRATIONMASTER_ID 0x480
#define CAL_CALIBRATIONMASTER_DLC 1         // Number of Bytes

union CAL_CalibrationMaster_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- DV_DriveCommand ----------------------------
#define DV_DRIVECOMMAND_ID 0x512
#define DV_DRIVECOMMAND_DLC 5         // Number of Bytes

union DV_DriveCommand_UNION
{
    uint64_t data;
    struct
    {
        uint64_t RTD_Request : 1;
        uint64_t EBS_Trigger : 1;
        uint64_t ThrottleCommand : 10;
        uint64_t BrakeCommand : 10;
        uint64_t RecuCommand : 10;
        uint64_t GEN_SCS : 3;
        uint64_t reserved : 29;
    };
};

// ----------------------------- LOG_WaterTemps_Left ----------------------------
#define LOG_WATERTEMPS_LEFT_ID 0x781
#define LOG_WATERTEMPS_LEFT_DLC 4         // Number of Bytes

union LOG_WaterTemps_Left_UNION
{
    uint64_t data;
    struct
    {
        uint64_t FrontLeft_IN : 8;
        uint64_t FrontLeft_OUT : 8;
        uint64_t RearLeft_IN : 8;
        uint64_t RearLeft_OUT : 8;
        uint64_t reserved : 32;
    };
};

// ----------------------------- LOG_WaterTemps_Right ----------------------------
#define LOG_WATERTEMPS_RIGHT_ID 0x782
#define LOG_WATERTEMPS_RIGHT_DLC 4         // Number of Bytes

union LOG_WaterTemps_Right_UNION
{
    uint64_t data;
    struct
    {
        uint64_t FrontRight_IN : 8;
        uint64_t FrontRight_OUT : 8;
        uint64_t RearRight_IN : 8;
        uint64_t RearRight_OUT : 8;
        uint64_t reserved : 32;
    };
};

// ----------------------------- LOG_SpringTravel_Front ----------------------------
#define LOG_SPRINGTRAVEL_FRONT_ID 0x783
#define LOG_SPRINGTRAVEL_FRONT_DLC 4         // Number of Bytes

union LOG_SpringTravel_Front_UNION
{
    uint64_t data;
    struct
    {
        uint64_t FrontLeft : 16;
        uint64_t FrontRight : 16;
        uint64_t reserved : 32;
    };
};

// ----------------------------- LOG_SpringTravel_Rear ----------------------------
#define LOG_SPRINGTRAVEL_REAR_ID 0x784
#define LOG_SPRINGTRAVEL_REAR_DLC 4         // Number of Bytes

union LOG_SpringTravel_Rear_UNION
{
    uint64_t data;
    struct
    {
        uint64_t RearLeft : 16;
        uint64_t RearRight : 16;
        uint64_t reserved : 32;
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
        uint64_t Front : 12;
        uint64_t Rear : 12;
        uint64_t reserved : 40;
    };
};

// ----------------------------- LOG_LEM ----------------------------
#define LOG_LEM_ID 0x786
#define LOG_LEM_DLC 2         // Number of Bytes

union LOG_LEM_UNION
{
    uint64_t data;
    struct
    {
        uint64_t LV : 16;
        uint64_t reserved : 48;
    };
};

// ----------------------------- LOG_DashLEDs ----------------------------
#define LOG_DASHLEDS_ID 0x787
#define LOG_DASHLEDS_DLC 1         // Number of Bytes

union LOG_DashLEDs_UNION
{
    uint64_t data;
    struct
    {
        uint64_t IMD : 1;
        uint64_t AMS : 1;
        uint64_t reserved : 62;
    };
};

// ----------------------------- LOG_BME280s_Left ----------------------------
#define LOG_BME280S_LEFT_ID 0x788
#define LOG_BME280S_LEFT_DLC 0         // Number of Bytes

union LOG_BME280s_Left_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- LOG_BME280s_Right ----------------------------
#define LOG_BME280S_RIGHT_ID 0x789
#define LOG_BME280S_RIGHT_DLC 0         // Number of Bytes

union LOG_BME280s_Right_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- LOG_BME280s_Front ----------------------------
#define LOG_BME280S_FRONT_ID 0x78a
#define LOG_BME280S_FRONT_DLC 0         // Number of Bytes

union LOG_BME280s_Front_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- LOG_BME280s_Rear ----------------------------
#define LOG_BME280S_REAR_ID 0x78b
#define LOG_BME280S_REAR_DLC 0         // Number of Bytes

union LOG_BME280s_Rear_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- LOG_PE_MaxTemps ----------------------------
#define LOG_PE_MAXTEMPS_ID 0x78c
#define LOG_PE_MAXTEMPS_DLC 8         // Number of Bytes

union LOG_PE_MaxTemps_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Front : 8;
        uint64_t Rear : 8;
        uint64_t Left : 8;
        uint64_t Right : 8;
        uint64_t Usage_Front : 8;
        uint64_t Usage_Rear : 8;
        uint64_t Usage_Left : 8;
        uint64_t Usage_Right : 8;
    };
};

// ----------------------------- LOG_EKF_Translation ----------------------------
#define LOG_EKF_TRANSLATION_ID 0x78d
#define LOG_EKF_TRANSLATION_DLC 8         // Number of Bytes

union LOG_EKF_Translation_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Velocity_vx : 16;
        uint64_t Velocity_vy : 16;
        uint64_t Acceleration_ax : 16;
        uint64_t Acceleration_ay : 16;
    };
};

// ----------------------------- LOG_EKF_Rotation ----------------------------
#define LOG_EKF_ROTATION_ID 0x78e
#define LOG_EKF_ROTATION_DLC 8         // Number of Bytes

union LOG_EKF_Rotation_UNION
{
    uint64_t data;
    struct
    {
        uint64_t Heading_psi : 16;
        uint64_t YawRate : 16;
        uint64_t reserved : 32;
    };
};

// ----------------------------- CANO_TLSS ----------------------------
#define CANO_TLSS_ID 0x7e4
#define CANO_TLSS_DLC 8         // Number of Bytes

union CANO_TLSS_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

// ----------------------------- CANO_RLSS ----------------------------
#define CANO_RLSS_ID 0x7e5
#define CANO_RLSS_DLC 8         // Number of Bytes

union CANO_RLSS_UNION
{
    uint64_t data;
    struct
    {
        uint64_t reserved : 64;
    };
};

#endif // SRE_DBC_H