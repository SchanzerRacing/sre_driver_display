
/***
 * Header File from DBC
 * Auto-generated using Python
 * 23.04.2026, 17:56:30 UTC
 ***/

#ifndef SRE_DBC_H
#define SRE_DBC_H

#if __has_include("../config.h")
#include "../config.h"

#else
#error "No Config found"

#endif

#include <stdbool.h>

#if defined ARCH_F280013X
#include <hw_lib.h>
#include <inttypes.h>

#elif defined ARCH_RPI
#include <stdint.h>

#else
#error "No fitting config found"

#endif

#if defined ARCH_F280013X

#ifdef INLINE
#define SOFT_INLINE INLINE

#else
#define SOFT_INLINE inline

#endif

#else
#define SOFT_INLINE

#endif

/* -------------------------- GW_PE_TorqueCurrents -------------------------- */

#define GW_PE_TORQUE_CURRENTS_ID 0x380
#define GW_PE_TORQUE_CURRENTS_DLC 8         // Number of Bytes
#define GW_PE_TORQUE_CURRENTS_CYCLE_TIME 10 // Milliseconds

union GW_PE_TorqueCurrents_Union
{

  uint64_t data;

  struct
  {

    int64_t tq_fl : 16;
    int64_t tq_fr : 16;
    int64_t tq_rl : 16;
    int64_t tq_rr : 16;
  };
};

struct GW_PE_TorqueCurrents_Struct
{
  int16_t tq_fl;
  int16_t tq_fr;
  int16_t tq_rl;
  int16_t tq_rr;
};

extern SOFT_INLINE void
GW_PE_TorqueCurrents_UnionToStruct(struct GW_PE_TorqueCurrents_Struct *s,
                                   union GW_PE_TorqueCurrents_Union u);

extern SOFT_INLINE void
GW_PE_TorqueCurrents_StructToUnion(union GW_PE_TorqueCurrents_Union *u,
                                   struct GW_PE_TorqueCurrents_Struct s);

/* -------------------------------- SF2_Info -------------------------------- */

#define SF2_INFO_ID 0x7FC
#define SF2_INFO_DLC 8          // Number of Bytes
#define SF2_INFO_CYCLE_TIME 100 // Milliseconds

union SF2_Info_Union
{

  uint64_t data;

  struct
  {

    uint64_t serial_no : 24;
    uint64_t sensor_no : 8;
    int64_t temp_sens : 8;
    uint64_t curr_led : 8;
    uint64_t st_st : 1;
    uint64_t self_test : 1;
    uint64_t sensor_ok : 1;
    uint64_t temp_ok : 1;
    uint64_t optic_ok : 1;
    uint64_t curr_high : 1;
    uint64_t curr_ok : 1;
    uint64_t power_ok : 1;
    uint64_t dbcledcal : 1;
    uint64_t ledstatus : 2;
    uint64_t v25_ok : 1;
    uint64_t v33_ok : 1;
    uint64_t vdd_ok : 1;
    uint64_t vee_ok : 1;
    uint64_t reserved_1 : 1;
  };
};

struct SF2_Info_Struct
{
  uint32_t serial_no;
  uint8_t sensor_no;
  int8_t temp_sens;
  float curr_led;
  bool st_st;
  bool self_test;
  bool sensor_ok;
  bool temp_ok;
  bool optic_ok;
  bool curr_high;
  bool curr_ok;
  bool power_ok;
  bool dbcledcal;
  uint8_t ledstatus;
  bool v25_ok;
  bool v33_ok;
  bool vdd_ok;
  bool vee_ok;
};

extern SOFT_INLINE void SF2_Info_UnionToStruct(struct SF2_Info_Struct *s,
                                               union SF2_Info_Union u);

extern SOFT_INLINE void SF2_Info_StructToUnion(union SF2_Info_Union *u,
                                               struct SF2_Info_Struct s);

/* ------------------------------- SF2_Data2 ------------------------------- */

#define SF2_DATA_2_ID 0x7FB
#define SF2_DATA_2_DLC 6          // Number of Bytes
#define SF2_DATA_2_CYCLE_TIME 100 // Milliseconds

union SF2_Data2_Union
{

  uint64_t data;

  struct
  {

    int64_t vel_x : 16;
    int64_t vel_y : 16;
    int64_t slip_angle_sf_2 : 16;
    uint64_t reserved_1 : 16;
  };
};

struct SF2_Data2_Struct
{
  float vel_x;
  float vel_y;
  float slip_angle_sf_2;
};

extern SOFT_INLINE void SF2_Data2_UnionToStruct(struct SF2_Data2_Struct *s,
                                                union SF2_Data2_Union u);

extern SOFT_INLINE void SF2_Data2_StructToUnion(union SF2_Data2_Union *u,
                                                struct SF2_Data2_Struct s);

/* ------------------------------- SF2_Data1 ------------------------------- */

#define SF2_DATA_1_ID 0x7FA
#define SF2_DATA_1_DLC 8          // Number of Bytes
#define SF2_DATA_1_CYCLE_TIME 100 // Milliseconds

union SF2_Data1_Union
{

  uint64_t data;

  struct
  {

    uint64_t timestamp : 16;
    uint64_t velocity_sf_2 : 16;
    uint64_t dist_sf_2 : 32;
  };
};

struct SF2_Data1_Struct
{
  uint16_t timestamp;
  float velocity_sf_2;
  float dist_sf_2;
};

extern SOFT_INLINE void SF2_Data1_UnionToStruct(struct SF2_Data1_Struct *s,
                                                union SF2_Data1_Union u);

extern SOFT_INLINE void SF2_Data1_StructToUnion(union SF2_Data1_Union *u,
                                                struct SF2_Data1_Struct s);

/* ------------------------------ LOG_DashLEDs ------------------------------ */

#define LOG_DASH_LEDS_ID 0x787
#define LOG_DASH_LEDS_DLC 1          // Number of Bytes
#define LOG_DASH_LEDS_CYCLE_TIME 100 // Milliseconds

union LOG_DashLEDs_Union
{

  uint64_t data;

  struct
  {

    uint64_t imd : 1;
    uint64_t reserved_1 : 1;
    uint64_t ams_led : 1;
    uint64_t reserved_2 : 61;
  };
};

struct LOG_DashLEDs_Struct
{
  bool imd;
  bool ams_led;
};

extern SOFT_INLINE void
LOG_DashLEDs_UnionToStruct(struct LOG_DashLEDs_Struct *s,
                           union LOG_DashLEDs_Union u);

extern SOFT_INLINE void
LOG_DashLEDs_StructToUnion(union LOG_DashLEDs_Union *u,
                           struct LOG_DashLEDs_Struct s);

/* ---------------------------- LSC_DASH_Buttons ---------------------------- */

#define LSC_DASH_BUTTONS_ID 0x181
#define LSC_DASH_BUTTONS_DLC 1          // Number of Bytes
#define LSC_DASH_BUTTONS_CYCLE_TIME 100 // Milliseconds

union LSC_DASH_Buttons_Union
{

  uint64_t data;

  struct
  {

    uint64_t tsa : 1;
    uint64_t rtd : 1;
    uint64_t reserved_1 : 3;
    uint64_t gen_scs : 3;
    uint64_t reserved_2 : 56;
  };
};

struct LSC_DASH_Buttons_Struct
{
  bool tsa;
  bool rtd;
  uint8_t gen_scs;
};

extern SOFT_INLINE void
LSC_DASH_Buttons_UnionToStruct(struct LSC_DASH_Buttons_Struct *s,
                               union LSC_DASH_Buttons_Union u);

extern SOFT_INLINE void
LSC_DASH_Buttons_StructToUnion(union LSC_DASH_Buttons_Union *u,
                               struct LSC_DASH_Buttons_Struct s);

/* ---------------------------- SAF_DASH_Status ---------------------------- */

#define SAF_DASH_STATUS_ID 0x55
#define SAF_DASH_STATUS_DLC 1          // Number of Bytes
#define SAF_DASH_STATUS_CYCLE_TIME 100 // Milliseconds

union SAF_DASH_Status_Union
{

  uint64_t data;

  struct
  {

    uint64_t scs_error : 1;
    uint64_t message_error : 1;
    uint64_t output_no_change_error : 1;
    uint64_t reserved_1 : 2;
    uint64_t gen_scs : 3;
    uint64_t reserved_2 : 56;
  };
};

struct SAF_DASH_Status_Struct
{
  bool scs_error;
  bool message_error;
  bool output_no_change_error;
  uint8_t gen_scs;
};

extern SOFT_INLINE void
SAF_DASH_Status_UnionToStruct(struct SAF_DASH_Status_Struct *s,
                              union SAF_DASH_Status_Union u);

extern SOFT_INLINE void
SAF_DASH_Status_StructToUnion(union SAF_DASH_Status_Union *u,
                              struct SAF_DASH_Status_Struct s);

/* ----------------------------- LOG_ECU_ERRORS ----------------------------- */

#define LOG_ECU_ERRORS_ID 0x7C8
#define LOG_ECU_ERRORS_DLC 4          // Number of Bytes
#define LOG_ECU_ERRORS_CYCLE_TIME 100 // Milliseconds

union LOG_ECU_ERRORS_Union
{

  uint64_t data;

  struct
  {

    uint64_t temp_err : 1;
    uint64_t mt_driver_input : 1;
    uint64_t mt_zoco_front : 1;
    uint64_t mt_asb_status : 1;
    uint64_t mt_steering : 1;
    uint64_t mt_st_wheel_status : 1;
    uint64_t mt_zoco_left : 1;
    uint64_t mt_zoco_right : 1;
    uint64_t mt_drive_command : 1;
    uint64_t mt_zoco_rear : 1;
    uint64_t mt_extern_button : 1;
    uint64_t mt_saf_fuseboard : 1;
    uint64_t mt_bat_pcb_info : 1;
    uint64_t mt_bat_pcb_control : 1;
    uint64_t mt_bat_pcb_soc : 1;
    uint64_t mt_temp_pcb_1 : 1;
    uint64_t mt_temp_pcb_2 : 1;
    uint64_t mt_temp_pcb_3 : 1;
    uint64_t mt_temp_pcb_4 : 1;
    uint64_t mt_temp_pcb_5 : 1;
    uint64_t mt_temp_pcb_6 : 1;
    uint64_t mt_lsc_dash_buttons : 1;
    uint64_t mt_saf_dash_status : 1;
    uint64_t scs_dash : 1;
    uint64_t scs_asb_status : 1;
    uint64_t scs_zoco_front : 1;
    uint64_t scs_zoco_left : 1;
    uint64_t scs_zoco_rear : 1;
    uint64_t scs_zoco_right : 1;
    uint64_t scs_st_wheel : 1;
    uint64_t scs_fuseboard : 1;
    uint64_t reserved_1 : 33;
  };
};

struct LOG_ECU_ERRORS_Struct
{
  bool temp_err;
  bool mt_driver_input;
  bool mt_zoco_front;
  bool mt_asb_status;
  bool mt_steering;
  bool mt_st_wheel_status;
  bool mt_zoco_left;
  bool mt_zoco_right;
  bool mt_drive_command;
  bool mt_zoco_rear;
  bool mt_extern_button;
  bool mt_saf_fuseboard;
  bool mt_bat_pcb_info;
  bool mt_bat_pcb_control;
  bool mt_bat_pcb_soc;
  bool mt_temp_pcb_1;
  bool mt_temp_pcb_2;
  bool mt_temp_pcb_3;
  bool mt_temp_pcb_4;
  bool mt_temp_pcb_5;
  bool mt_temp_pcb_6;
  bool mt_lsc_dash_buttons;
  bool mt_saf_dash_status;
  bool scs_dash;
  bool scs_asb_status;
  bool scs_zoco_front;
  bool scs_zoco_left;
  bool scs_zoco_rear;
  bool scs_zoco_right;
  bool scs_st_wheel;
  bool scs_fuseboard;
};

extern SOFT_INLINE void
LOG_ECU_ERRORS_UnionToStruct(struct LOG_ECU_ERRORS_Struct *s,
                             union LOG_ECU_ERRORS_Union u);

extern SOFT_INLINE void
LOG_ECU_ERRORS_StructToUnion(union LOG_ECU_ERRORS_Union *u,
                             struct LOG_ECU_ERRORS_Struct s);

/* --------------------------- PARS_ECU_Settings --------------------------- */

#define PARS_ECU_SETTINGS_ID 0x581
#define PARS_ECU_SETTINGS_DLC 8          // Number of Bytes
#define PARS_ECU_SETTINGS_CYCLE_TIME 100 // Milliseconds

union PARS_ECU_Settings_Union
{

  uint64_t data;

  struct
  {

    uint64_t enable_recu_s : 1;
    uint64_t change_params : 1;
    uint64_t enable_tv_s : 1;
    uint64_t enable_dynamic_torque_s : 1;
    uint64_t enable_launch_control_s : 1;
    uint64_t enable_torque_limit_s : 1;
    uint64_t enable_opd_s : 1;
    uint64_t enable_speed_limit_s : 1;
    uint64_t recu_percentage_s : 5;
    uint64_t opd_lower_input_s : 5;
    uint64_t opd_output_brake_s : 5;
    uint64_t opd_output_drive_s : 5;
    uint64_t opd_splitting_point_s : 5;
    uint64_t opd_upper_input_s : 5;
    uint64_t car_control_speed_switch_s : 3;
    uint64_t car_control_max_speed_s : 5;
    uint64_t max_power_s : 8;
    uint64_t max_torque_s : 8;
    uint64_t car_control_slip_angle_switch_s : 2;
  };
};

struct PARS_ECU_Settings_Struct
{
  bool enable_recu_s;
  bool change_params;
  bool enable_tv_s;
  bool enable_dynamic_torque_s;
  bool enable_launch_control_s;
  bool enable_torque_limit_s;
  bool enable_opd_s;
  bool enable_speed_limit_s;
  float recu_percentage_s;
  float opd_lower_input_s;
  float opd_output_brake_s;
  float opd_output_drive_s;
  float opd_splitting_point_s;
  float opd_upper_input_s;
  uint8_t car_control_speed_switch_s;
  float car_control_max_speed_s;
  float max_power_s;
  float max_torque_s;
  uint8_t car_control_slip_angle_switch_s;
};

extern SOFT_INLINE void
PARS_ECU_Settings_UnionToStruct(struct PARS_ECU_Settings_Struct *s,
                                union PARS_ECU_Settings_Union u);

extern SOFT_INLINE void
PARS_ECU_Settings_StructToUnion(union PARS_ECU_Settings_Union *u,
                                struct PARS_ECU_Settings_Struct s);

/* --------------------------- PARC_ECU_Settings --------------------------- */

#define PARC_ECU_SETTINGS_ID 0x5C1
#define PARC_ECU_SETTINGS_DLC 8          // Number of Bytes
#define PARC_ECU_SETTINGS_CYCLE_TIME 100 // Milliseconds

union PARC_ECU_Settings_Union
{

  uint64_t data;

  struct
  {

    uint64_t enable_recu_c : 1;
    uint64_t enable_acc_drosselung_c : 1;
    uint64_t enable_tv_c : 1;
    uint64_t enable_dynamic_torque_c : 1;
    uint64_t enable_launch_control_c : 1;
    uint64_t enable_torque_limit_c : 1;
    uint64_t enable_opd_c : 1;
    uint64_t enable_speed_limit_c : 1;
    uint64_t recu_percentage_c : 5;
    uint64_t opd_lower_input_c : 5;
    uint64_t opd_output_brake_c : 5;
    uint64_t opd_output_drive_c : 5;
    uint64_t opd_splitting_point_c : 5;
    uint64_t opd_upper_input_c : 5;
    uint64_t car_control_speed_switch_c : 3;
    uint64_t car_control_max_speed_c : 5;
    uint64_t max_power_c : 8;
    uint64_t max_torque_c : 8;
    uint64_t car_control_slip_angle_switch_c : 2;
  };
};

struct PARC_ECU_Settings_Struct
{
  bool enable_recu_c;
  bool enable_acc_drosselung_c;
  bool enable_tv_c;
  bool enable_dynamic_torque_c;
  bool enable_launch_control_c;
  bool enable_torque_limit_c;
  bool enable_opd_c;
  bool enable_speed_limit_c;
  float recu_percentage_c;
  float opd_lower_input_c;
  float opd_output_brake_c;
  float opd_output_drive_c;
  float opd_splitting_point_c;
  float opd_upper_input_c;
  uint8_t car_control_speed_switch_c;
  float car_control_max_speed_c;
  float max_power_c;
  float max_torque_c;
  uint8_t car_control_slip_angle_switch_c;
};

extern SOFT_INLINE void
PARC_ECU_Settings_UnionToStruct(struct PARC_ECU_Settings_Struct *s,
                                union PARC_ECU_Settings_Union u);

extern SOFT_INLINE void
PARC_ECU_Settings_StructToUnion(union PARC_ECU_Settings_Union *u,
                                struct PARC_ECU_Settings_Struct s);

/* ------------------------------ LOG_Aero_SPR ------------------------------ */

#define LOG_AERO_SPR_ID 0x7C6
#define LOG_AERO_SPR_DLC 8         // Number of Bytes
#define LOG_AERO_SPR_CYCLE_TIME 10 // Milliseconds

union LOG_Aero_SPR_Union
{

  uint64_t data;

  struct
  {

    uint64_t temp_1_spr : 10;
    uint64_t temp_2_spr : 10;
    uint64_t temp_3_spr : 10;
    uint64_t hum_1_spr : 10;
    uint64_t hum_2_spr : 10;
    uint64_t hum_3_spr : 10;
    uint64_t reserved_1 : 4;
  };
};

struct LOG_Aero_SPR_Struct
{
  float temp_1_spr;
  float temp_2_spr;
  float temp_3_spr;
  float hum_1_spr;
  float hum_2_spr;
  float hum_3_spr;
};

extern SOFT_INLINE void
LOG_Aero_SPR_UnionToStruct(struct LOG_Aero_SPR_Struct *s,
                           union LOG_Aero_SPR_Union u);

extern SOFT_INLINE void
LOG_Aero_SPR_StructToUnion(union LOG_Aero_SPR_Union *u,
                           struct LOG_Aero_SPR_Struct s);

/* ------------------------------ LOG_Aero_SPL ------------------------------ */

#define LOG_AERO_SPL_ID 0x7C5
#define LOG_AERO_SPL_DLC 8         // Number of Bytes
#define LOG_AERO_SPL_CYCLE_TIME 10 // Milliseconds

union LOG_Aero_SPL_Union
{

  uint64_t data;

  struct
  {

    uint64_t temp_1_spl : 10;
    uint64_t temp_2_spl : 10;
    uint64_t temp_3_spl : 10;
    uint64_t hum_1_spl : 10;
    uint64_t hum_2_spl : 10;
    uint64_t hum_3_spl : 10;
    uint64_t reserved_1 : 4;
  };
};

struct LOG_Aero_SPL_Struct
{
  float temp_1_spl;
  float temp_2_spl;
  float temp_3_spl;
  float hum_1_spl;
  float hum_2_spl;
  float hum_3_spl;
};

extern SOFT_INLINE void
LOG_Aero_SPL_UnionToStruct(struct LOG_Aero_SPL_Struct *s,
                           union LOG_Aero_SPL_Union u);

extern SOFT_INLINE void
LOG_Aero_SPL_StructToUnion(union LOG_Aero_SPL_Union *u,
                           struct LOG_Aero_SPL_Struct s);

/* ------------------------------ LOG_Aero_RW ------------------------------ */

#define LOG_AERO_RW_ID 0x7C7
#define LOG_AERO_RW_DLC 5         // Number of Bytes
#define LOG_AERO_RW_CYCLE_TIME 10 // Milliseconds

union LOG_Aero_RW_Union
{

  uint64_t data;

  struct
  {

    uint64_t temp_1_rw : 10;
    uint64_t temp_2_rw : 10;
    uint64_t hum_1_rw : 10;
    uint64_t hum_2_rw : 10;
    uint64_t reserved_1 : 24;
  };
};

struct LOG_Aero_RW_Struct
{
  float temp_1_rw;
  float temp_2_rw;
  float hum_1_rw;
  float hum_2_rw;
};

extern SOFT_INLINE void LOG_Aero_RW_UnionToStruct(struct LOG_Aero_RW_Struct *s,
                                                  union LOG_Aero_RW_Union u);

extern SOFT_INLINE void LOG_Aero_RW_StructToUnion(union LOG_Aero_RW_Union *u,
                                                  struct LOG_Aero_RW_Struct s);

/* ------------------------------ LOG_Aero_FW ------------------------------ */

#define LOG_AERO_FW_ID 0x7C4
#define LOG_AERO_FW_DLC 5         // Number of Bytes
#define LOG_AERO_FW_CYCLE_TIME 10 // Milliseconds

union LOG_Aero_FW_Union
{

  uint64_t data;

  struct
  {

    uint64_t temp_1_fw : 10;
    uint64_t temp_2_fw : 10;
    uint64_t hum_1_fw : 10;
    uint64_t hum_2_fw : 10;
    uint64_t reserved_1 : 24;
  };
};

struct LOG_Aero_FW_Struct
{
  float temp_1_fw;
  float temp_2_fw;
  float hum_1_fw;
  float hum_2_fw;
};

extern SOFT_INLINE void LOG_Aero_FW_UnionToStruct(struct LOG_Aero_FW_Struct *s,
                                                  union LOG_Aero_FW_Union u);

extern SOFT_INLINE void LOG_Aero_FW_StructToUnion(union LOG_Aero_FW_Union *u,
                                                  struct LOG_Aero_FW_Struct s);

/* ------------------------------ CAL_EPOS_HC ------------------------------ */

#define CAL_EPOS_HC_ID 0x488
#define CAL_EPOS_HC_DLC 2          // Number of Bytes
#define CAL_EPOS_HC_CYCLE_TIME 100 // Milliseconds

union CAL_EPOS_HC_Union
{

  uint64_t data;

  struct
  {

    uint64_t voltage_epos : 12;
    uint64_t reserved_1 : 52;
  };
};

struct CAL_EPOS_HC_Struct
{
  uint16_t voltage_epos;
};

extern SOFT_INLINE void CAL_EPOS_HC_UnionToStruct(struct CAL_EPOS_HC_Struct *s,
                                                  union CAL_EPOS_HC_Union u);

extern SOFT_INLINE void CAL_EPOS_HC_StructToUnion(union CAL_EPOS_HC_Union *u,
                                                  struct CAL_EPOS_HC_Struct s);

/* -------------------------------- CAL_SDC -------------------------------- */

#define CAL_SDC_ID 0x487
#define CAL_SDC_DLC 2          // Number of Bytes
#define CAL_SDC_CYCLE_TIME 100 // Milliseconds

union CAL_SDC_Union
{

  uint64_t data;

  struct
  {

    uint64_t voltage_sdc : 12;
    uint64_t reserved_1 : 52;
  };
};

struct CAL_SDC_Struct
{
  uint16_t voltage_sdc;
};

extern SOFT_INLINE void CAL_SDC_UnionToStruct(struct CAL_SDC_Struct *s,
                                              union CAL_SDC_Union u);

extern SOFT_INLINE void CAL_SDC_StructToUnion(union CAL_SDC_Union *u,
                                              struct CAL_SDC_Struct s);

/* ------------------------------ CAL_WT_Right ------------------------------ */

#define CAL_WT_RIGHT_ID 0x486
#define CAL_WT_RIGHT_DLC 8          // Number of Bytes
#define CAL_WT_RIGHT_CYCLE_TIME 100 // Milliseconds

union CAL_WT_Right_Union
{

  uint64_t data;

  struct
  {

    uint64_t vin_1_r : 16;
    uint64_t vin_2_r : 16;
    uint64_t vin_3_r : 16;
    uint64_t vin_4_r : 16;
  };
};

struct CAL_WT_Right_Struct
{
  uint16_t vin_1_r;
  uint16_t vin_2_r;
  uint16_t vin_3_r;
  uint16_t vin_4_r;
};

extern SOFT_INLINE void
CAL_WT_Right_UnionToStruct(struct CAL_WT_Right_Struct *s,
                           union CAL_WT_Right_Union u);

extern SOFT_INLINE void
CAL_WT_Right_StructToUnion(union CAL_WT_Right_Union *u,
                           struct CAL_WT_Right_Struct s);

/* ------------------------------ CAL_WT_Left ------------------------------ */

#define CAL_WT_LEFT_ID 0x482
#define CAL_WT_LEFT_DLC 8          // Number of Bytes
#define CAL_WT_LEFT_CYCLE_TIME 100 // Milliseconds

union CAL_WT_Left_Union
{

  uint64_t data;

  struct
  {

    uint64_t vin_1_l : 16;
    uint64_t vin_2_l : 16;
    uint64_t vin_3_l : 16;
    uint64_t vin_4_l : 16;
  };
};

struct CAL_WT_Left_Struct
{
  uint16_t vin_1_l;
  uint16_t vin_2_l;
  uint16_t vin_3_l;
  uint16_t vin_4_l;
};

extern SOFT_INLINE void CAL_WT_Left_UnionToStruct(struct CAL_WT_Left_Struct *s,
                                                  union CAL_WT_Left_Union u);

extern SOFT_INLINE void CAL_WT_Left_StructToUnion(union CAL_WT_Left_Union *u,
                                                  struct CAL_WT_Left_Struct s);

/* ------------------------------- CAL_LV_LEM ------------------------------- */

#define CAL_LV_LEM_ID 0x481
#define CAL_LV_LEM_DLC 2          // Number of Bytes
#define CAL_LV_LEM_CYCLE_TIME 100 // Milliseconds

union CAL_LV_LEM_Union
{

  uint64_t data;

  struct
  {

    uint64_t voltage_lvlem : 12;
    uint64_t reserved_1 : 52;
  };
};

struct CAL_LV_LEM_Struct
{
  uint16_t voltage_lvlem;
};

extern SOFT_INLINE void CAL_LV_LEM_UnionToStruct(struct CAL_LV_LEM_Struct *s,
                                                 union CAL_LV_LEM_Union u);

extern SOFT_INLINE void CAL_LV_LEM_StructToUnion(union CAL_LV_LEM_Union *u,
                                                 struct CAL_LV_LEM_Struct s);

/* -------------------------------- LOG_SDC -------------------------------- */

#define LOG_SDC_ID 0x7B1
#define LOG_SDC_DLC 2          // Number of Bytes
#define LOG_SDC_CYCLE_TIME 100 // Milliseconds

union LOG_SDC_Union
{

  uint64_t data;

  struct
  {

    uint64_t sdc_res : 1;
    uint64_t sdc_fr : 1;
    uint64_t sdc_asb : 1;
    uint64_t sdc_bspd : 1;
    uint64_t sdc_bots : 1;
    uint64_t sdc_fl : 1;
    uint64_t sdc_dash : 1;
    uint64_t sdc_inertia : 1;
    uint64_t sdc_rl : 1;
    uint64_t sdc_tsal : 1;
    uint64_t sdc_rr : 1;
    uint64_t sdc_hvd : 1;
    uint64_t sdc_ts_connector : 1;
    uint64_t sdc_tsms : 1;
    uint64_t reserved_1 : 50;
  };
};

struct LOG_SDC_Struct
{
  bool sdc_res;
  bool sdc_fr;
  bool sdc_asb;
  bool sdc_bspd;
  bool sdc_bots;
  bool sdc_fl;
  bool sdc_dash;
  bool sdc_inertia;
  bool sdc_rl;
  bool sdc_tsal;
  bool sdc_rr;
  bool sdc_hvd;
  bool sdc_ts_connector;
  bool sdc_tsms;
};

extern SOFT_INLINE void LOG_SDC_UnionToStruct(struct LOG_SDC_Struct *s,
                                              union LOG_SDC_Union u);

extern SOFT_INLINE void LOG_SDC_StructToUnion(union LOG_SDC_Union *u,
                                              struct LOG_SDC_Struct s);

/* --------------------------- LOG_FUSE_Currents --------------------------- */

#define LOG_FUSE_CURRENTS_ID 0x7B0
#define LOG_FUSE_CURRENTS_DLC 4          // Number of Bytes
#define LOG_FUSE_CURRENTS_CYCLE_TIME 100 // Milliseconds

union LOG_FUSE_Currents_Union
{

  uint64_t data;

  struct
  {

    uint64_t epos_current : 16;
    uint64_t sdc_current : 16;
    uint64_t reserved_1 : 32;
  };
};

struct LOG_FUSE_Currents_Struct
{
  uint16_t epos_current;
  uint16_t sdc_current;
};

extern SOFT_INLINE void
LOG_FUSE_Currents_UnionToStruct(struct LOG_FUSE_Currents_Struct *s,
                                union LOG_FUSE_Currents_Union u);

extern SOFT_INLINE void
LOG_FUSE_Currents_StructToUnion(union LOG_FUSE_Currents_Union *u,
                                struct LOG_FUSE_Currents_Struct s);

/* ---------------------------- PARC_FUSE_States ---------------------------- */

#define PARC_FUSE_STATES_ID 0x5C0
#define PARC_FUSE_STATES_DLC 2          // Number of Bytes
#define PARC_FUSE_STATES_CYCLE_TIME 100 // Milliseconds

union PARC_FUSE_States_Union
{

  uint64_t data;

  struct
  {

    uint64_t fb_acu : 1;
    uint64_t fb_asb : 1;
    uint64_t fb_dash : 1;
    uint64_t fb_epos : 1;
    uint64_t fb_fan_l : 1;
    uint64_t fb_fan_r : 1;
    uint64_t fb_gps : 1;
    uint64_t fb_pef : 1;
    uint64_t fb_per : 1;
    uint64_t fb_pumps : 1;
    uint64_t fb_sensors : 1;
    uint64_t fb_vcu : 1;
    uint64_t reserved_1 : 52;
  };
};

struct PARC_FUSE_States_Struct
{
  bool fb_acu;
  bool fb_asb;
  bool fb_dash;
  bool fb_epos;
  bool fb_fan_l;
  bool fb_fan_r;
  bool fb_gps;
  bool fb_pef;
  bool fb_per;
  bool fb_pumps;
  bool fb_sensors;
  bool fb_vcu;
};

extern SOFT_INLINE void
PARC_FUSE_States_UnionToStruct(struct PARC_FUSE_States_Struct *s,
                               union PARC_FUSE_States_Union u);

extern SOFT_INLINE void
PARC_FUSE_States_StructToUnion(union PARC_FUSE_States_Union *u,
                               struct PARC_FUSE_States_Struct s);

/* ---------------------------- PARS_FUSE_States ---------------------------- */

#define PARS_FUSE_STATES_ID 0x580
#define PARS_FUSE_STATES_DLC 2          // Number of Bytes
#define PARS_FUSE_STATES_CYCLE_TIME 100 // Milliseconds

union PARS_FUSE_States_Union
{

  uint64_t data;

  struct
  {

    uint64_t fb_acu : 1;
    uint64_t fb_asb : 1;
    uint64_t fb_dash : 1;
    uint64_t fb_epos : 1;
    uint64_t fb_fan_l : 1;
    uint64_t fb_fan_r : 1;
    uint64_t fb_gps : 1;
    uint64_t fb_pef : 1;
    uint64_t fb_per : 1;
    uint64_t fb_pumps : 1;
    uint64_t fb_sensors : 1;
    uint64_t fb_vcu : 1;
    uint64_t reserved_1 : 52;
  };
};

struct PARS_FUSE_States_Struct
{
  bool fb_acu;
  bool fb_asb;
  bool fb_dash;
  bool fb_epos;
  bool fb_fan_l;
  bool fb_fan_r;
  bool fb_gps;
  bool fb_pef;
  bool fb_per;
  bool fb_pumps;
  bool fb_sensors;
  bool fb_vcu;
};

extern SOFT_INLINE void
PARS_FUSE_States_UnionToStruct(struct PARS_FUSE_States_Struct *s,
                               union PARS_FUSE_States_Union u);

extern SOFT_INLINE void
PARS_FUSE_States_StructToUnion(union PARS_FUSE_States_Union *u,
                               struct PARS_FUSE_States_Struct s);

/* -------------------------- SAF_Fuseboard_Status -------------------------- */

#define SAF_FUSEBOARD_STATUS_ID 0x57
#define SAF_FUSEBOARD_STATUS_DLC 1          // Number of Bytes
#define SAF_FUSEBOARD_STATUS_CYCLE_TIME 100 // Milliseconds

union SAF_Fuseboard_Status_Union
{

  uint64_t data;

  struct
  {

    uint64_t scs_error : 1;
    uint64_t message_error : 1;
    uint64_t output_no_change_error : 1;
    uint64_t reserved_1 : 2;
    uint64_t gen_scs : 3;
    uint64_t reserved_2 : 56;
  };
};

struct SAF_Fuseboard_Status_Struct
{
  bool scs_error;
  bool message_error;
  bool output_no_change_error;
  uint8_t gen_scs;
};

extern SOFT_INLINE void
SAF_Fuseboard_Status_UnionToStruct(struct SAF_Fuseboard_Status_Struct *s,
                                   union SAF_Fuseboard_Status_Union u);

extern SOFT_INLINE void
SAF_Fuseboard_Status_StructToUnion(union SAF_Fuseboard_Status_Union *u,
                                   struct SAF_Fuseboard_Status_Struct s);

/* --------------------------- SAF_StWheel_Status --------------------------- */

#define SAF_ST_WHEEL_STATUS_ID 0x58
#define SAF_ST_WHEEL_STATUS_DLC 1          // Number of Bytes
#define SAF_ST_WHEEL_STATUS_CYCLE_TIME 100 // Milliseconds

union SAF_StWheel_Status_Union
{

  uint64_t data;

  struct
  {

    uint64_t scs_error : 1;
    uint64_t message_error : 1;
    uint64_t output_no_change_error : 1;
    uint64_t reserved_1 : 2;
    uint64_t gen_scs : 3;
    uint64_t reserved_2 : 56;
  };
};

struct SAF_StWheel_Status_Struct
{
  bool scs_error;
  bool message_error;
  bool output_no_change_error;
  uint8_t gen_scs;
};

extern SOFT_INLINE void
SAF_StWheel_Status_UnionToStruct(struct SAF_StWheel_Status_Struct *s,
                                 union SAF_StWheel_Status_Union u);

extern SOFT_INLINE void
SAF_StWheel_Status_StructToUnion(union SAF_StWheel_Status_Union *u,
                                 struct SAF_StWheel_Status_Struct s);

/* ------------------------- SAF_ZoCo_Right_Status ------------------------- */

#define SAF_ZO_CO_RIGHT_STATUS_ID 0x54
#define SAF_ZO_CO_RIGHT_STATUS_DLC 1          // Number of Bytes
#define SAF_ZO_CO_RIGHT_STATUS_CYCLE_TIME 100 // Milliseconds

union SAF_ZoCo_Right_Status_Union
{

  uint64_t data;

  struct
  {

    uint64_t scs_error : 1;
    uint64_t gen_scs : 3;
    uint64_t reserved_1 : 60;
  };
};

struct SAF_ZoCo_Right_Status_Struct
{
  bool scs_error;
  uint8_t gen_scs;
};

extern SOFT_INLINE void
SAF_ZoCo_Right_Status_UnionToStruct(struct SAF_ZoCo_Right_Status_Struct *s,
                                    union SAF_ZoCo_Right_Status_Union u);

extern SOFT_INLINE void
SAF_ZoCo_Right_Status_StructToUnion(union SAF_ZoCo_Right_Status_Union *u,
                                    struct SAF_ZoCo_Right_Status_Struct s);

/* -------------------------- SAF_ZoCo_Left_Status -------------------------- */

#define SAF_ZO_CO_LEFT_STATUS_ID 0x53
#define SAF_ZO_CO_LEFT_STATUS_DLC 1          // Number of Bytes
#define SAF_ZO_CO_LEFT_STATUS_CYCLE_TIME 100 // Milliseconds

union SAF_ZoCo_Left_Status_Union
{

  uint64_t data;

  struct
  {

    uint64_t scs_error : 1;
    uint64_t gen_scs : 3;
    uint64_t reserved_1 : 60;
  };
};

struct SAF_ZoCo_Left_Status_Struct
{
  bool scs_error;
  uint8_t gen_scs;
};

extern SOFT_INLINE void
SAF_ZoCo_Left_Status_UnionToStruct(struct SAF_ZoCo_Left_Status_Struct *s,
                                   union SAF_ZoCo_Left_Status_Union u);

extern SOFT_INLINE void
SAF_ZoCo_Left_Status_StructToUnion(union SAF_ZoCo_Left_Status_Union *u,
                                   struct SAF_ZoCo_Left_Status_Struct s);

/* ------------------------------ LOG_Odometry ------------------------------ */

#define LOG_ODOMETRY_ID 0x796
#define LOG_ODOMETRY_DLC 2          // Number of Bytes
#define LOG_ODOMETRY_CYCLE_TIME 100 // Milliseconds

union LOG_Odometry_Union
{

  uint64_t data;

  struct
  {

    int64_t rear_average_tire_speed : 16;
    uint64_t reserved_1 : 48;
  };
};

struct LOG_Odometry_Struct
{
  float rear_average_tire_speed;
};

extern SOFT_INLINE void
LOG_Odometry_UnionToStruct(struct LOG_Odometry_Struct *s,
                           union LOG_Odometry_Union u);

extern SOFT_INLINE void
LOG_Odometry_StructToUnion(union LOG_Odometry_Union *u,
                           struct LOG_Odometry_Struct s);

/* ------------------------ LOG_ThrottleBrakeRequest ------------------------ */

#define LOG_THROTTLE_BRAKE_REQUEST_ID 0x795
#define LOG_THROTTLE_BRAKE_REQUEST_DLC 2          // Number of Bytes
#define LOG_THROTTLE_BRAKE_REQUEST_CYCLE_TIME 100 // Milliseconds

union LOG_ThrottleBrakeRequest_Union
{

  uint64_t data;

  struct
  {

    uint64_t requested_throttle : 8;
    uint64_t requested_brake : 8;
    uint64_t reserved_1 : 48;
  };
};

struct LOG_ThrottleBrakeRequest_Struct
{
  uint8_t requested_throttle;
  uint8_t requested_brake;
};

extern SOFT_INLINE void LOG_ThrottleBrakeRequest_UnionToStruct(
    struct LOG_ThrottleBrakeRequest_Struct *s,
    union LOG_ThrottleBrakeRequest_Union u);

extern SOFT_INLINE void LOG_ThrottleBrakeRequest_StructToUnion(
    union LOG_ThrottleBrakeRequest_Union *u,
    struct LOG_ThrottleBrakeRequest_Struct s);

/* ---------------------------- LOG_SBG_ODO_Info ---------------------------- */

#define LOG_SBG_ODO_INFO_ID 0x79D
#define LOG_SBG_ODO_INFO_DLC 6          // Number of Bytes
#define LOG_SBG_ODO_INFO_CYCLE_TIME 100 // Milliseconds

union LOG_SBG_ODO_Info_Union
{

  uint64_t data;

  struct
  {

    uint64_t time_stamp : 32;
    uint64_t odo_real_meas : 1;
    uint64_t odo_time_sync : 1;
    uint64_t reserved_1 : 30;
  };
};

struct LOG_SBG_ODO_Info_Struct
{
  uint32_t time_stamp;
  bool odo_real_meas;
  bool odo_time_sync;
};

extern SOFT_INLINE void
LOG_SBG_ODO_Info_UnionToStruct(struct LOG_SBG_ODO_Info_Struct *s,
                               union LOG_SBG_ODO_Info_Union u);

extern SOFT_INLINE void
LOG_SBG_ODO_Info_StructToUnion(union LOG_SBG_ODO_Info_Union *u,
                               struct LOG_SBG_ODO_Info_Struct s);

/* -------------------------- HSC_SBG_Position_Acc -------------------------- */

#define HSC_SBG_POSITION_ACC_ID 0x120
#define HSC_SBG_POSITION_ACC_DLC 6          // Number of Bytes
#define HSC_SBG_POSITION_ACC_CYCLE_TIME 100 // Milliseconds

union HSC_SBG_Position_Acc_Union
{

  uint64_t data;

  struct
  {

    uint64_t latitude_acc : 16;
    uint64_t longitude_acc : 16;
    uint64_t altitude_acc : 16;
    uint64_t reserved_1 : 16;
  };
};

struct HSC_SBG_Position_Acc_Struct
{
  float latitude_acc;
  float longitude_acc;
  float altitude_acc;
};

extern SOFT_INLINE void
HSC_SBG_Position_Acc_UnionToStruct(struct HSC_SBG_Position_Acc_Struct *s,
                                   union HSC_SBG_Position_Acc_Union u);

extern SOFT_INLINE void
HSC_SBG_Position_Acc_StructToUnion(union HSC_SBG_Position_Acc_Union *u,
                                   struct HSC_SBG_Position_Acc_Struct s);

/* --------------------------- HSC_SBG_Euler_Acc --------------------------- */

#define HSC_SBG_EULER_ACC_ID 0x11D
#define HSC_SBG_EULER_ACC_DLC 6          // Number of Bytes
#define HSC_SBG_EULER_ACC_CYCLE_TIME 100 // Milliseconds

union HSC_SBG_Euler_Acc_Union
{

  uint64_t data;

  struct
  {

    uint64_t roll_acc : 16;
    uint64_t pitch_euler_acc : 16;
    uint64_t yaw_acc : 16;
    uint64_t reserved_1 : 16;
  };
};

struct HSC_SBG_Euler_Acc_Struct
{
  float roll_acc;
  float pitch_euler_acc;
  float yaw_acc;
};

extern SOFT_INLINE void
HSC_SBG_Euler_Acc_UnionToStruct(struct HSC_SBG_Euler_Acc_Struct *s,
                                union HSC_SBG_Euler_Acc_Union u);

extern SOFT_INLINE void
HSC_SBG_Euler_Acc_StructToUnion(union HSC_SBG_Euler_Acc_Union *u,
                                struct HSC_SBG_Euler_Acc_Struct s);

/* ----------------------------- HSC_SBG_Euler ----------------------------- */

#define HSC_SBG_EULER_ID 0x11C
#define HSC_SBG_EULER_DLC 6          // Number of Bytes
#define HSC_SBG_EULER_CYCLE_TIME 100 // Milliseconds

union HSC_SBG_Euler_Union
{

  uint64_t data;

  struct
  {

    int64_t roll_euler : 16;
    int64_t pitch_euler : 16;
    int64_t yaw : 16;
    uint64_t reserved_1 : 16;
  };
};

struct HSC_SBG_Euler_Struct
{
  float roll_euler;
  float pitch_euler;
  float yaw;
};

extern SOFT_INLINE void
HSC_SBG_Euler_UnionToStruct(struct HSC_SBG_Euler_Struct *s,
                            union HSC_SBG_Euler_Union u);

extern SOFT_INLINE void
HSC_SBG_Euler_StructToUnion(union HSC_SBG_Euler_Union *u,
                            struct HSC_SBG_Euler_Struct s);

/* ---------------------------- LOG_SBG_EKF_Info ---------------------------- */

#define LOG_SBG_EKF_INFO_ID 0x79C
#define LOG_SBG_EKF_INFO_DLC 4          // Number of Bytes
#define LOG_SBG_EKF_INFO_CYCLE_TIME 100 // Milliseconds

union LOG_SBG_EKF_Info_Union
{

  uint64_t data;

  struct
  {

    uint64_t time_stamp : 32;
    uint64_t reserved_1 : 32;
  };
};

struct LOG_SBG_EKF_Info_Struct
{
  uint32_t time_stamp;
};

extern SOFT_INLINE void
LOG_SBG_EKF_Info_UnionToStruct(struct LOG_SBG_EKF_Info_Struct *s,
                               union LOG_SBG_EKF_Info_Union u);

extern SOFT_INLINE void
LOG_SBG_EKF_Info_StructToUnion(union LOG_SBG_EKF_Info_Union *u,
                               struct LOG_SBG_EKF_Info_Struct s);

/* ---------------------------- LOG_SBG_IMU_Info ---------------------------- */

#define LOG_SBG_IMU_INFO_ID 0x79B
#define LOG_SBG_IMU_INFO_DLC 8          // Number of Bytes
#define LOG_SBG_IMU_INFO_CYCLE_TIME 100 // Milliseconds

union LOG_SBG_IMU_Info_Union
{

  uint64_t data;

  struct
  {

    uint64_t time_stamp : 32;
    int64_t reserved_1 : 16;
    int64_t temperature : 16;
  };
};

struct LOG_SBG_IMU_Info_Struct
{
  uint32_t time_stamp;
  float temperature;
};

extern SOFT_INLINE void
LOG_SBG_IMU_Info_UnionToStruct(struct LOG_SBG_IMU_Info_Struct *s,
                               union LOG_SBG_IMU_Info_Union u);

extern SOFT_INLINE void
LOG_SBG_IMU_Info_StructToUnion(union LOG_SBG_IMU_Info_Union *u,
                               struct LOG_SBG_IMU_Info_Struct s);

/* ----------------------------- LOG_TireForces ----------------------------- */

#define LOG_TIRE_FORCES_ID 0x793
#define LOG_TIRE_FORCES_DLC 8          // Number of Bytes
#define LOG_TIRE_FORCES_CYCLE_TIME 100 // Milliseconds

union LOG_TireForces_Union
{

  uint64_t data;

  struct
  {

    uint64_t tire_force_fl : 16;
    uint64_t tire_force_fr : 16;
    uint64_t tire_force_rl : 16;
    uint64_t tire_force_rr : 16;
  };
};

struct LOG_TireForces_Struct
{
  float tire_force_fl;
  float tire_force_fr;
  float tire_force_rl;
  float tire_force_rr;
};

extern SOFT_INLINE void
LOG_TireForces_UnionToStruct(struct LOG_TireForces_Struct *s,
                             union LOG_TireForces_Union u);

extern SOFT_INLINE void
LOG_TireForces_StructToUnion(union LOG_TireForces_Union *u,
                             struct LOG_TireForces_Struct s);

/* ----------------------------- LOG_SlipRatio ----------------------------- */

#define LOG_SLIP_RATIO_ID 0x792
#define LOG_SLIP_RATIO_DLC 8          // Number of Bytes
#define LOG_SLIP_RATIO_CYCLE_TIME 100 // Milliseconds

union LOG_SlipRatio_Union
{

  uint64_t data;

  struct
  {

    int64_t slip_ratio_fl : 16;
    int64_t slip_ratio_fr : 16;
    int64_t slip_ratio_rl : 16;
    int64_t slip_ratio_rr : 16;
  };
};

struct LOG_SlipRatio_Struct
{
  float slip_ratio_fl;
  float slip_ratio_fr;
  float slip_ratio_rl;
  float slip_ratio_rr;
};

extern SOFT_INLINE void
LOG_SlipRatio_UnionToStruct(struct LOG_SlipRatio_Struct *s,
                            union LOG_SlipRatio_Union u);

extern SOFT_INLINE void
LOG_SlipRatio_StructToUnion(union LOG_SlipRatio_Union *u,
                            struct LOG_SlipRatio_Struct s);

/* ----------------------------- LOG_TV_request ----------------------------- */

#define LOG_TV_REQUEST_ID 0x794
#define LOG_TV_REQUEST_DLC 8          // Number of Bytes
#define LOG_TV_REQUEST_CYCLE_TIME 100 // Milliseconds

union LOG_TV_request_Union
{

  uint64_t data;

  struct
  {

    int64_t tv_fl : 16;
    int64_t tv_fr : 16;
    int64_t tv_rr : 16;
    int64_t tv_rl : 16;
  };
};

struct LOG_TV_request_Struct
{
  float tv_fl;
  float tv_fr;
  float tv_rr;
  float tv_rl;
};

extern SOFT_INLINE void
LOG_TV_request_UnionToStruct(struct LOG_TV_request_Struct *s,
                             union LOG_TV_request_Union u);

extern SOFT_INLINE void
LOG_TV_request_StructToUnion(union LOG_TV_request_Union *u,
                             struct LOG_TV_request_Struct s);

/* ----------------------------- LOG_SlipAngle ----------------------------- */

#define LOG_SLIP_ANGLE_ID 0x791
#define LOG_SLIP_ANGLE_DLC 8          // Number of Bytes
#define LOG_SLIP_ANGLE_CYCLE_TIME 100 // Milliseconds

union LOG_SlipAngle_Union
{

  uint64_t data;

  struct
  {

    int64_t slip_angle_fl : 16;
    int64_t slip_angle_fr : 16;
    int64_t slip_angle_rl : 16;
    int64_t slip_angle_rr : 16;
  };
};

struct LOG_SlipAngle_Struct
{
  float slip_angle_fl;
  float slip_angle_fr;
  float slip_angle_rl;
  float slip_angle_rr;
};

extern SOFT_INLINE void
LOG_SlipAngle_UnionToStruct(struct LOG_SlipAngle_Struct *s,
                            union LOG_SlipAngle_Union u);

extern SOFT_INLINE void
LOG_SlipAngle_StructToUnion(union LOG_SlipAngle_Union *u,
                            struct LOG_SlipAngle_Struct s);

/* -------------------------- HSC_SBG_True_Heading -------------------------- */

#define HSC_SBG_TRUE_HEADING_ID 0x136
#define HSC_SBG_TRUE_HEADING_DLC 8          // Number of Bytes
#define HSC_SBG_TRUE_HEADING_CYCLE_TIME 100 // Milliseconds

union HSC_SBG_True_Heading_Union
{

  uint64_t data;

  struct
  {

    uint64_t true_heading : 16;
    uint64_t true_heading_acc : 16;
    int64_t pitch_heading : 16;
    uint64_t reserved_1 : 16;
  };
};

struct HSC_SBG_True_Heading_Struct
{
  float true_heading;
  float true_heading_acc;
  float pitch_heading;
};

extern SOFT_INLINE void
HSC_SBG_True_Heading_UnionToStruct(struct HSC_SBG_True_Heading_Struct *s,
                                   union HSC_SBG_True_Heading_Union u);

extern SOFT_INLINE void
HSC_SBG_True_Heading_StructToUnion(union HSC_SBG_True_Heading_Union *u,
                                   struct HSC_SBG_True_Heading_Struct s);

/* ---------------------------- HSC_SBG_Altitude ---------------------------- */

#define HSC_SBG_ALTITUDE_ID 0x11F
#define HSC_SBG_ALTITUDE_DLC 6          // Number of Bytes
#define HSC_SBG_ALTITUDE_CYCLE_TIME 100 // Milliseconds

union HSC_SBG_Altitude_Union
{

  uint64_t data;

  struct
  {

    int64_t altitude : 32;
    int64_t undulation : 16;
    uint64_t reserved_1 : 16;
  };
};

struct HSC_SBG_Altitude_Struct
{
  float altitude;
  float undulation;
};

extern SOFT_INLINE void
HSC_SBG_Altitude_UnionToStruct(struct HSC_SBG_Altitude_Struct *s,
                               union HSC_SBG_Altitude_Union u);

extern SOFT_INLINE void
HSC_SBG_Altitude_StructToUnion(union HSC_SBG_Altitude_Union *u,
                               struct HSC_SBG_Altitude_Struct s);

/* ---------------------------- HSC_SBG_Position ---------------------------- */

#define HSC_SBG_POSITION_ID 0x11E
#define HSC_SBG_POSITION_DLC 8          // Number of Bytes
#define HSC_SBG_POSITION_CYCLE_TIME 100 // Milliseconds

union HSC_SBG_Position_Union
{

  uint64_t data;

  struct
  {

    int64_t latitude : 32;
    int64_t longitude : 32;
  };
};

struct HSC_SBG_Position_Struct
{
  float latitude;
  float longitude;
};

extern SOFT_INLINE void
HSC_SBG_Position_UnionToStruct(struct HSC_SBG_Position_Struct *s,
                               union HSC_SBG_Position_Union u);

extern SOFT_INLINE void
HSC_SBG_Position_StructToUnion(union HSC_SBG_Position_Union *u,
                               struct HSC_SBG_Position_Struct s);

/* -------------------------- LOG_SBG_Heading_Info -------------------------- */

#define LOG_SBG_HEADING_INFO_ID 0x7A0
#define LOG_SBG_HEADING_INFO_DLC 6          // Number of Bytes
#define LOG_SBG_HEADING_INFO_CYCLE_TIME 100 // Milliseconds

union LOG_SBG_Heading_Info_Union
{

  uint64_t data;

  struct
  {

    uint64_t time_stamp : 32;
    uint64_t reserved_1 : 32;
  };
};

struct LOG_SBG_Heading_Info_Struct
{
  uint32_t time_stamp;
};

extern SOFT_INLINE void
LOG_SBG_Heading_Info_UnionToStruct(struct LOG_SBG_Heading_Info_Struct *s,
                                   union LOG_SBG_Heading_Info_Union u);

extern SOFT_INLINE void
LOG_SBG_Heading_Info_StructToUnion(union LOG_SBG_Heading_Info_Union *u,
                                   struct LOG_SBG_Heading_Info_Struct s);

/* ---------------------------- LOG_SBG_POS_Info ---------------------------- */

#define LOG_SBG_POS_INFO_ID 0x79F
#define LOG_SBG_POS_INFO_DLC 8          // Number of Bytes
#define LOG_SBG_POS_INFO_CYCLE_TIME 100 // Milliseconds

union LOG_SBG_POS_Info_Union
{

  uint64_t data;

  struct
  {

    uint64_t time_stamp : 32;
    uint64_t reserved_1 : 32;
  };
};

struct LOG_SBG_POS_Info_Struct
{
  uint32_t time_stamp;
};

extern SOFT_INLINE void
LOG_SBG_POS_Info_UnionToStruct(struct LOG_SBG_POS_Info_Struct *s,
                               union LOG_SBG_POS_Info_Union u);

extern SOFT_INLINE void
LOG_SBG_POS_Info_StructToUnion(union LOG_SBG_POS_Info_Union *u,
                               struct LOG_SBG_POS_Info_Struct s);

/* ------------------------- LOG_SBG_GPS1_Vel_Info ------------------------- */

#define LOG_SBG_GPS1_VEL_INFO_ID 0x79E
#define LOG_SBG_GPS1_VEL_INFO_DLC 8          // Number of Bytes
#define LOG_SBG_GPS1_VEL_INFO_CYCLE_TIME 100 // Milliseconds

union LOG_SBG_GPS1_Vel_Info_Union
{

  uint64_t data;

  struct
  {

    uint64_t time_stamp : 32;
    uint64_t reserved_1 : 32;
  };
};

struct LOG_SBG_GPS1_Vel_Info_Struct
{
  uint32_t time_stamp;
};

extern SOFT_INLINE void
LOG_SBG_GPS1_Vel_Info_UnionToStruct(struct LOG_SBG_GPS1_Vel_Info_Struct *s,
                                    union LOG_SBG_GPS1_Vel_Info_Union u);

extern SOFT_INLINE void
LOG_SBG_GPS1_Vel_Info_StructToUnion(union LOG_SBG_GPS1_Vel_Info_Union *u,
                                    struct LOG_SBG_GPS1_Vel_Info_Struct s);

/* --------------------------- LOG_SBG_Status_03 --------------------------- */

#define LOG_SBG_STATUS_03_ID 0x79A
#define LOG_SBG_STATUS_03_DLC 6          // Number of Bytes
#define LOG_SBG_STATUS_03_CYCLE_TIME 100 // Milliseconds

union LOG_SBG_Status_03_Union
{

  uint64_t data;

  struct
  {

    uint64_t reserved_1 : 64;
  };
};

struct LOG_SBG_Status_03_Struct
{
};

extern SOFT_INLINE void
LOG_SBG_Status_03_UnionToStruct(struct LOG_SBG_Status_03_Struct *s,
                                union LOG_SBG_Status_03_Union u);

extern SOFT_INLINE void
LOG_SBG_Status_03_StructToUnion(union LOG_SBG_Status_03_Union *u,
                                struct LOG_SBG_Status_03_Struct s);

/* --------------------------- LOG_SBG_Status_02 --------------------------- */

#define LOG_SBG_STATUS_02_ID 0x799
#define LOG_SBG_STATUS_02_DLC 8          // Number of Bytes
#define LOG_SBG_STATUS_02_CYCLE_TIME 100 // Milliseconds

union LOG_SBG_Status_02_Union
{

  uint64_t data;

  struct
  {

    uint64_t sbg_porta_valid : 1;
    uint64_t sbg_portb_valid : 1;
    uint64_t reserved_1 : 3;
    uint64_t sbg_porta_rx_ok : 1;
    uint64_t sbg_porta_tx_ok : 1;
    uint64_t sbg_portb_rx_ok : 1;
    uint64_t reserved_2 : 17;
    uint64_t sbg_can_valid : 1;
    uint64_t sbg_can_rx_ok : 1;
    uint64_t sbg_can_tx_ok : 1;
    uint64_t reserved_3 : 36;
  };
};

struct LOG_SBG_Status_02_Struct
{
  bool sbg_porta_valid;
  bool sbg_portb_valid;
  bool sbg_porta_rx_ok;
  bool sbg_porta_tx_ok;
  bool sbg_portb_rx_ok;
  bool sbg_can_valid;
  bool sbg_can_rx_ok;
  bool sbg_can_tx_ok;
};

extern SOFT_INLINE void
LOG_SBG_Status_02_UnionToStruct(struct LOG_SBG_Status_02_Struct *s,
                                union LOG_SBG_Status_02_Union u);

extern SOFT_INLINE void
LOG_SBG_Status_02_StructToUnion(union LOG_SBG_Status_02_Union *u,
                                struct LOG_SBG_Status_02_Struct s);

/* --------------------------- LOG_SBG_Status_01 --------------------------- */

#define LOG_SBG_STATUS_01_ID 0x798
#define LOG_SBG_STATUS_01_DLC 8          // Number of Bytes
#define LOG_SBG_STATUS_01_CYCLE_TIME 100 // Milliseconds

union LOG_SBG_Status_01_Union
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
    uint64_t reserved_1 : 25;
  };
};

struct LOG_SBG_Status_01_Struct
{
  uint32_t sbg_time_stamp;
  bool sbg_main_power_ok;
  bool sbg_imu_power_ok;
  bool sbg_gps_power_ok;
  bool sbg_settings_ok;
  bool sbg_temp_ok;
  bool sbg_datalogger_ok;
  bool sbg_cpu_ok;
};

extern SOFT_INLINE void
LOG_SBG_Status_01_UnionToStruct(struct LOG_SBG_Status_01_Struct *s,
                                union LOG_SBG_Status_01_Union u);

extern SOFT_INLINE void
LOG_SBG_Status_01_StructToUnion(union LOG_SBG_Status_01_Union *u,
                                struct LOG_SBG_Status_01_Struct s);

/* ------------------------ HSC_SBG_Track_Slip_Curve ------------------------ */

#define HSC_SBG_TRACK_SLIP_CURVE_ID 0x124
#define HSC_SBG_TRACK_SLIP_CURVE_DLC 7          // Number of Bytes
#define HSC_SBG_TRACK_SLIP_CURVE_CYCLE_TIME 100 // Milliseconds

union HSC_SBG_Track_Slip_Curve_Union
{

  uint64_t data;

  struct
  {

    int64_t track_angle : 16;
    int64_t slip_angle_sbg : 16;
    uint64_t curvature_radius : 16;
    uint64_t track_valid : 1;
    uint64_t slip_valid : 1;
    uint64_t curvature_valid : 1;
    uint64_t reserved_1 : 13;
  };
};

struct HSC_SBG_Track_Slip_Curve_Struct
{
  float track_angle;
  float slip_angle_sbg;
  float curvature_radius;
  bool track_valid;
  bool slip_valid;
  bool curvature_valid;
};

extern SOFT_INLINE void HSC_SBG_Track_Slip_Curve_UnionToStruct(
    struct HSC_SBG_Track_Slip_Curve_Struct *s,
    union HSC_SBG_Track_Slip_Curve_Union u);

extern SOFT_INLINE void HSC_SBG_Track_Slip_Curve_StructToUnion(
    union HSC_SBG_Track_Slip_Curve_Union *u,
    struct HSC_SBG_Track_Slip_Curve_Struct s);

/* -------------------------- HSC_SBG_EKF_Vel_Body -------------------------- */

#define HSC_SBG_EKF_VEL_BODY_ID 0x123
#define HSC_SBG_EKF_VEL_BODY_DLC 6          // Number of Bytes
#define HSC_SBG_EKF_VEL_BODY_CYCLE_TIME 100 // Milliseconds

union HSC_SBG_EKF_Vel_Body_Union
{

  uint64_t data;

  struct
  {

    int64_t velocity_x : 16;
    int64_t velocity_y : 16;
    int64_t velocity_z : 16;
    uint64_t reserved_1 : 16;
  };
};

struct HSC_SBG_EKF_Vel_Body_Struct
{
  float velocity_x;
  float velocity_y;
  float velocity_z;
};

extern SOFT_INLINE void
HSC_SBG_EKF_Vel_Body_UnionToStruct(struct HSC_SBG_EKF_Vel_Body_Struct *s,
                                   union HSC_SBG_EKF_Vel_Body_Union u);

extern SOFT_INLINE void
HSC_SBG_EKF_Vel_Body_StructToUnion(union HSC_SBG_EKF_Vel_Body_Union *u,
                                   struct HSC_SBG_EKF_Vel_Body_Struct s);

/* ------------------------------ HSC_SBG_Gyro ------------------------------ */

#define HSC_SBG_GYRO_ID 0x117
#define HSC_SBG_GYRO_DLC 6          // Number of Bytes
#define HSC_SBG_GYRO_CYCLE_TIME 100 // Milliseconds

union HSC_SBG_Gyro_Union
{

  uint64_t data;

  struct
  {

    int64_t gyro_x : 16;
    int64_t gyro_y : 16;
    int64_t gyro_z : 16;
    uint64_t reserved_1 : 16;
  };
};

struct HSC_SBG_Gyro_Struct
{
  float gyro_x;
  float gyro_y;
  float gyro_z;
};

extern SOFT_INLINE void
HSC_SBG_Gyro_UnionToStruct(struct HSC_SBG_Gyro_Struct *s,
                           union HSC_SBG_Gyro_Union u);

extern SOFT_INLINE void
HSC_SBG_Gyro_StructToUnion(union HSC_SBG_Gyro_Union *u,
                           struct HSC_SBG_Gyro_Struct s);

/* ----------------------------- HSC_SBG_Accel ----------------------------- */

#define HSC_SBG_ACCEL_ID 0x116
#define HSC_SBG_ACCEL_DLC 6          // Number of Bytes
#define HSC_SBG_ACCEL_CYCLE_TIME 100 // Milliseconds

union HSC_SBG_Accel_Union
{

  uint64_t data;

  struct
  {

    int64_t accel_x : 16;
    int64_t accel_y : 16;
    int64_t accel_z : 16;
    uint64_t reserved_1 : 16;
  };
};

struct HSC_SBG_Accel_Struct
{
  float accel_x;
  float accel_y;
  float accel_z;
};

extern SOFT_INLINE void
HSC_SBG_Accel_UnionToStruct(struct HSC_SBG_Accel_Struct *s,
                            union HSC_SBG_Accel_Union u);

extern SOFT_INLINE void
HSC_SBG_Accel_StructToUnion(union HSC_SBG_Accel_Union *u,
                            struct HSC_SBG_Accel_Struct s);

/* ---------------------------- GW_Battery_Cells ---------------------------- */

#define GW_BATTERY_CELLS_ID 0x386
#define GW_BATTERY_CELLS_DLC 7          // Number of Bytes
#define GW_BATTERY_CELLS_CYCLE_TIME 100 // Milliseconds

union GW_Battery_Cells_Union
{

  uint64_t data;

  struct
  {

    uint64_t temp_min : 7;
    uint64_t reserved_1 : 1;
    uint64_t temp_avg : 7;
    uint64_t reserved_2 : 1;
    uint64_t temp_max : 7;
    uint64_t reserved_3 : 1;
    uint64_t voltage_min : 16;
    uint64_t voltage_max : 16;
    uint64_t reserved_4 : 8;
  };
};

struct GW_Battery_Cells_Struct
{
  uint8_t temp_min;
  uint8_t temp_avg;
  uint8_t temp_max;
  float voltage_min;
  float voltage_max;
};

extern SOFT_INLINE void
GW_Battery_Cells_UnionToStruct(struct GW_Battery_Cells_Struct *s,
                               union GW_Battery_Cells_Union u);

extern SOFT_INLINE void
GW_Battery_Cells_StructToUnion(union GW_Battery_Cells_Union *u,
                               struct GW_Battery_Cells_Struct s);

/* --------------------------- GW_Battery_Status --------------------------- */
typedef enum
{
  BATSTATE_BAT_ERROR = 10,
  BATSTATE_IMD_ERROR = 9,
  BATSTATE_BMS_ERROR = 8,
  BATSTATE_AIR_WARNING = 7,
  BATSTATE_TSA = 6,
  BATSTATE_TS_STARTUP = 5,
  BATSTATE_WAIT_FOR_TS = 4,
  BATSTATE_SDC_CAR_OPEN = 3,
  BATSTATE_BMS_RESET = 2,
  BATSTATE_START = 1,
  BATSTATE_UNDEFINED = 0,
} GW_Battery_Status_BatState;

#define GW_BATTERY_STATUS_ID 0x385
#define GW_BATTERY_STATUS_DLC 6          // Number of Bytes
#define GW_BATTERY_STATUS_CYCLE_TIME 100 // Milliseconds

union GW_Battery_Status_Union
{

  uint64_t data;

  struct
  {

    uint64_t bat_state : 4;
    uint64_t soc_internal : 14;
    uint64_t power : 14;
    int64_t current : 16;
    uint64_t reserved_1 : 16;
  };
};

struct GW_Battery_Status_Struct
{
  GW_Battery_Status_BatState bat_state;
  float soc_internal;
  float power;
  float current;
};

extern SOFT_INLINE void
GW_Battery_Status_UnionToStruct(struct GW_Battery_Status_Struct *s,
                                union GW_Battery_Status_Union u);

extern SOFT_INLINE void
GW_Battery_Status_StructToUnion(union GW_Battery_Status_Union *u,
                                struct GW_Battery_Status_Struct s);

/* ---------------------------- GW_PE_FrontLeft ---------------------------- */

#define GW_PE_FRONT_LEFT_ID 0x384
#define GW_PE_FRONT_LEFT_DLC 8          // Number of Bytes
#define GW_PE_FRONT_LEFT_CYCLE_TIME 100 // Milliseconds

union GW_PE_FrontLeft_Union
{

  uint64_t data;

  struct
  {

    int64_t temp_motor_fl : 16;
    int64_t temp_inverter_fl : 16;
    int64_t temp_igbt_fl : 16;
    int64_t actual_velocity_fl : 16;
  };
};

struct GW_PE_FrontLeft_Struct
{
  float temp_motor_fl;
  float temp_inverter_fl;
  float temp_igbt_fl;
  int16_t actual_velocity_fl;
};

extern SOFT_INLINE void
GW_PE_FrontLeft_UnionToStruct(struct GW_PE_FrontLeft_Struct *s,
                              union GW_PE_FrontLeft_Union u);

extern SOFT_INLINE void
GW_PE_FrontLeft_StructToUnion(union GW_PE_FrontLeft_Union *u,
                              struct GW_PE_FrontLeft_Struct s);

/* ----------------------------- GW_PE_RearLeft ----------------------------- */

#define GW_PE_REAR_LEFT_ID 0x383
#define GW_PE_REAR_LEFT_DLC 8          // Number of Bytes
#define GW_PE_REAR_LEFT_CYCLE_TIME 100 // Milliseconds

union GW_PE_RearLeft_Union
{

  uint64_t data;

  struct
  {

    int64_t temp_motor_rl : 16;
    int64_t temp_inverter_rl : 16;
    int64_t temp_igbt_rl : 16;
    int64_t actual_velocity_rl : 16;
  };
};

struct GW_PE_RearLeft_Struct
{
  float temp_motor_rl;
  float temp_inverter_rl;
  float temp_igbt_rl;
  int16_t actual_velocity_rl;
};

extern SOFT_INLINE void
GW_PE_RearLeft_UnionToStruct(struct GW_PE_RearLeft_Struct *s,
                             union GW_PE_RearLeft_Union u);

extern SOFT_INLINE void
GW_PE_RearLeft_StructToUnion(union GW_PE_RearLeft_Union *u,
                             struct GW_PE_RearLeft_Struct s);

/* ---------------------------- GW_PE_RearRight ---------------------------- */

#define GW_PE_REAR_RIGHT_ID 0x382
#define GW_PE_REAR_RIGHT_DLC 8          // Number of Bytes
#define GW_PE_REAR_RIGHT_CYCLE_TIME 100 // Milliseconds

union GW_PE_RearRight_Union
{

  uint64_t data;

  struct
  {

    int64_t temp_motor_rr : 16;
    int64_t temp_inverter_rr : 16;
    int64_t temp_igbt_rr : 16;
    int64_t actual_velocity_rr : 16;
  };
};

struct GW_PE_RearRight_Struct
{
  float temp_motor_rr;
  float temp_inverter_rr;
  float temp_igbt_rr;
  int16_t actual_velocity_rr;
};

extern SOFT_INLINE void
GW_PE_RearRight_UnionToStruct(struct GW_PE_RearRight_Struct *s,
                              union GW_PE_RearRight_Union u);

extern SOFT_INLINE void
GW_PE_RearRight_StructToUnion(union GW_PE_RearRight_Union *u,
                              struct GW_PE_RearRight_Struct s);

/* ---------------------------- GW_PE_FrontRight ---------------------------- */

#define GW_PE_FRONT_RIGHT_ID 0x381
#define GW_PE_FRONT_RIGHT_DLC 8          // Number of Bytes
#define GW_PE_FRONT_RIGHT_CYCLE_TIME 100 // Milliseconds

union GW_PE_FrontRight_Union
{

  uint64_t data;

  struct
  {

    int64_t temp_motor_fr : 16;
    int64_t temp_inverter_fr : 16;
    int64_t temp_igbt_fr : 16;
    int64_t actual_velocity_fr : 16;
  };
};

struct GW_PE_FrontRight_Struct
{
  float temp_motor_fr;
  float temp_inverter_fr;
  float temp_igbt_fr;
  int16_t actual_velocity_fr;
};

extern SOFT_INLINE void
GW_PE_FrontRight_UnionToStruct(struct GW_PE_FrontRight_Struct *s,
                               union GW_PE_FrontRight_Union u);

extern SOFT_INLINE void
GW_PE_FrontRight_StructToUnion(union GW_PE_FrontRight_Union *u,
                               struct GW_PE_FrontRight_Struct s);

/* --------------------------- EXC_BATFAN_Control --------------------------- */

#define EXC_BATFAN_CONTROL_ID 0x412
#define EXC_BATFAN_CONTROL_DLC 1          // Number of Bytes
#define EXC_BATFAN_CONTROL_CYCLE_TIME 100 // Milliseconds

union EXC_BATFAN_Control_Union
{

  uint64_t data;

  struct
  {

    uint64_t fan_request : 7;
    uint64_t fan_on : 1;
    uint64_t reserved_1 : 56;
  };
};

struct EXC_BATFAN_Control_Struct
{
  uint8_t fan_request;
  bool fan_on;
};

extern SOFT_INLINE void
EXC_BATFAN_Control_UnionToStruct(struct EXC_BATFAN_Control_Struct *s,
                                 union EXC_BATFAN_Control_Union u);

extern SOFT_INLINE void
EXC_BATFAN_Control_StructToUnion(union EXC_BATFAN_Control_Union *u,
                                 struct EXC_BATFAN_Control_Struct s);

/* ------------------------------ LOG_ASSILEDs ------------------------------ */

#define LOG_ASSILEDS_ID 0x790
#define LOG_ASSILEDS_DLC 1          // Number of Bytes
#define LOG_ASSILEDS_CYCLE_TIME 100 // Milliseconds

union LOG_ASSILEDs_Union
{

  uint64_t data;

  struct
  {

    uint64_t yellow : 1;
    uint64_t reserved_1 : 1;
    uint64_t blue_assi : 1;
    uint64_t reserved_2 : 61;
  };
};

struct LOG_ASSILEDs_Struct
{
  bool yellow;
  bool blue_assi;
};

extern SOFT_INLINE void
LOG_ASSILEDs_UnionToStruct(struct LOG_ASSILEDs_Struct *s,
                           union LOG_ASSILEDs_Union u);

extern SOFT_INLINE void
LOG_ASSILEDs_StructToUnion(union LOG_ASSILEDs_Union *u,
                           struct LOG_ASSILEDs_Struct s);

/* ---------------------------- EXC_FAN_Control ---------------------------- */

#define EXC_FAN_CONTROL_ID 0x40F
#define EXC_FAN_CONTROL_DLC 1          // Number of Bytes
#define EXC_FAN_CONTROL_CYCLE_TIME 100 // Milliseconds

union EXC_FAN_Control_Union
{

  uint64_t data;

  struct
  {

    uint64_t fan_request : 7;
    uint64_t fan_on : 1;
    uint64_t reserved_1 : 56;
  };
};

struct EXC_FAN_Control_Struct
{
  uint8_t fan_request;
  bool fan_on;
};

extern SOFT_INLINE void
EXC_FAN_Control_UnionToStruct(struct EXC_FAN_Control_Struct *s,
                              union EXC_FAN_Control_Union u);

extern SOFT_INLINE void
EXC_FAN_Control_StructToUnion(union EXC_FAN_Control_Union *u,
                              struct EXC_FAN_Control_Struct s);

/* ---------------------------- EXC_PUMP_Control ---------------------------- */

#define EXC_PUMP_CONTROL_ID 0x410
#define EXC_PUMP_CONTROL_DLC 1          // Number of Bytes
#define EXC_PUMP_CONTROL_CYCLE_TIME 100 // Milliseconds

union EXC_PUMP_Control_Union
{

  uint64_t data;

  struct
  {

    uint64_t pump_request : 7;
    uint64_t pump_on : 1;
    uint64_t reserved_1 : 56;
  };
};

struct EXC_PUMP_Control_Struct
{
  uint8_t pump_request;
  bool pump_on;
};

extern SOFT_INLINE void
EXC_PUMP_Control_UnionToStruct(struct EXC_PUMP_Control_Struct *s,
                               union EXC_PUMP_Control_Union u);

extern SOFT_INLINE void
EXC_PUMP_Control_StructToUnion(union EXC_PUMP_Control_Union *u,
                               struct EXC_PUMP_Control_Struct s);

/* --------------------------- HSC_Vehicle_Status --------------------------- */
typedef enum
{
  CARSTATE_SCS_ERROR = 6,
  CARSTATE_LC_ON = 5,
  CARSTATE_DRIVE = 4,
  CARSTATE_WAIT_FOR_RTD = 3,
  CARSTATE_RTD_OFF = 2,
  CARSTATE_WAIT_FOR_TSA = 1,
  CARSTATE_UNDEFINED_OR_STARTUP = 0,
} HSC_Vehicle_Status_CarState;

#define HSC_VEHICLE_STATUS_ID 0x103
#define HSC_VEHICLE_STATUS_DLC 4         // Number of Bytes
#define HSC_VEHICLE_STATUS_CYCLE_TIME 10 // Milliseconds

union HSC_Vehicle_Status_Union
{

  uint64_t data;

  struct
  {

    uint64_t car_state : 3;
    uint64_t imd_error : 1;
    uint64_t ams_error : 1;
    uint64_t gen_scs : 3;
    uint64_t velocity : 8;
    int64_t velocity_ms : 16;
    uint64_t reserved_1 : 32;
  };
};

struct HSC_Vehicle_Status_Struct
{
  HSC_Vehicle_Status_CarState car_state;
  bool imd_error;
  bool ams_error;
  uint8_t gen_scs;
  float velocity;
  float velocity_ms;
};

extern SOFT_INLINE void
HSC_Vehicle_Status_UnionToStruct(struct HSC_Vehicle_Status_Struct *s,
                                 union HSC_Vehicle_Status_Union u);

extern SOFT_INLINE void
HSC_Vehicle_Status_StructToUnion(union HSC_Vehicle_Status_Union *u,
                                 struct HSC_Vehicle_Status_Struct s);

/* --------------------------- LSC_Extern_Buttons --------------------------- */

#define LSC_EXTERN_BUTTONS_ID 0x182
#define LSC_EXTERN_BUTTONS_DLC 1          // Number of Bytes
#define LSC_EXTERN_BUTTONS_CYCLE_TIME 100 // Milliseconds

union LSC_Extern_Buttons_Union
{

  uint64_t data;

  struct
  {

    uint64_t tsa_ext : 1;
    uint64_t gen_scs : 3;
    uint64_t reserved_1 : 60;
  };
};

struct LSC_Extern_Buttons_Struct
{
  bool tsa_ext;
  uint8_t gen_scs;
};

extern SOFT_INLINE void
LSC_Extern_Buttons_UnionToStruct(struct LSC_Extern_Buttons_Struct *s,
                                 union LSC_Extern_Buttons_Union u);

extern SOFT_INLINE void
LSC_Extern_Buttons_StructToUnion(union LSC_Extern_Buttons_Union *u,
                                 struct LSC_Extern_Buttons_Struct s);

/* --------------------------- SAF_SmSe_AS_Status --------------------------- */

#define SAF_SM_SE_AS_STATUS_ID 0x56
#define SAF_SM_SE_AS_STATUS_DLC 1          // Number of Bytes
#define SAF_SM_SE_AS_STATUS_CYCLE_TIME 100 // Milliseconds

union SAF_SmSe_AS_Status_Union
{

  uint64_t data;

  struct
  {

    uint64_t scs_error : 1;
    uint64_t message_error : 1;
    uint64_t output_no_change_error : 1;
    uint64_t reserved_1 : 2;
    uint64_t gen_scs : 3;
    uint64_t reserved_2 : 56;
  };
};

struct SAF_SmSe_AS_Status_Struct
{
  bool scs_error;
  bool message_error;
  bool output_no_change_error;
  uint8_t gen_scs;
};

extern SOFT_INLINE void
SAF_SmSe_AS_Status_UnionToStruct(struct SAF_SmSe_AS_Status_Struct *s,
                                 union SAF_SmSe_AS_Status_Union u);

extern SOFT_INLINE void
SAF_SmSe_AS_Status_StructToUnion(union SAF_SmSe_AS_Status_Union *u,
                                 struct SAF_SmSe_AS_Status_Struct s);

/* -------------------------- SAF_ZoCo_Rear_Status -------------------------- */

#define SAF_ZO_CO_REAR_STATUS_ID 0x52
#define SAF_ZO_CO_REAR_STATUS_DLC 5          // Number of Bytes
#define SAF_ZO_CO_REAR_STATUS_CYCLE_TIME 100 // Milliseconds

union SAF_ZoCo_Rear_Status_Union
{

  uint64_t data;

  struct
  {

    uint64_t scs_error : 1;
    uint64_t rtds_error : 1;
    uint64_t brake_light_error : 1;
    uint64_t message_error : 1;
    uint64_t reserved_1 : 1;
    uint64_t gen_scs : 3;
    uint64_t brake_light_state : 1;
    uint64_t rtds_state : 1;
    uint64_t reserved_2 : 54;
  };
};

struct SAF_ZoCo_Rear_Status_Struct
{
  bool scs_error;
  bool rtds_error;
  bool brake_light_error;
  bool message_error;
  uint8_t gen_scs;
  bool brake_light_state;
  bool rtds_state;
};

extern SOFT_INLINE void
SAF_ZoCo_Rear_Status_UnionToStruct(struct SAF_ZoCo_Rear_Status_Struct *s,
                                   union SAF_ZoCo_Rear_Status_Union u);

extern SOFT_INLINE void
SAF_ZoCo_Rear_Status_StructToUnion(union SAF_ZoCo_Rear_Status_Union *u,
                                   struct SAF_ZoCo_Rear_Status_Struct s);

/* ------------------------- SAF_ZoCo_Front_Status ------------------------- */

#define SAF_ZO_CO_FRONT_STATUS_ID 0x51
#define SAF_ZO_CO_FRONT_STATUS_DLC 2          // Number of Bytes
#define SAF_ZO_CO_FRONT_STATUS_CYCLE_TIME 100 // Milliseconds

union SAF_ZoCo_Front_Status_Union
{

  uint64_t data;

  struct
  {

    uint64_t scs_error : 1;
    uint64_t throttle_lower_error : 1;
    uint64_t throttle_upper_error : 1;
    uint64_t throttle_differential_error : 1;
    uint64_t brake_error : 1;
    uint64_t gen_scs : 3;
    uint64_t steering_error : 1;
    uint64_t reserved_1 : 55;
  };
};

struct SAF_ZoCo_Front_Status_Struct
{
  bool scs_error;
  bool throttle_lower_error;
  bool throttle_upper_error;
  bool throttle_differential_error;
  bool brake_error;
  uint8_t gen_scs;
  bool steering_error;
};

extern SOFT_INLINE void
SAF_ZoCo_Front_Status_UnionToStruct(struct SAF_ZoCo_Front_Status_Struct *s,
                                    union SAF_ZoCo_Front_Status_Union u);

extern SOFT_INLINE void
SAF_ZoCo_Front_Status_StructToUnion(union SAF_ZoCo_Front_Status_Union *u,
                                    struct SAF_ZoCo_Front_Status_Struct s);

/* ----------------------------- SAF_ECU_Status ----------------------------- */

#define SAF_ECU_STATUS_ID 0x50
#define SAF_ECU_STATUS_DLC 1          // Number of Bytes
#define SAF_ECU_STATUS_CYCLE_TIME 100 // Milliseconds

union SAF_ECU_Status_Union
{

  uint64_t data;

  struct
  {

    uint64_t scs_error : 1;
    uint64_t message_error : 1;
    uint64_t gen_scs : 3;
    uint64_t reserved_1 : 59;
  };
};

struct SAF_ECU_Status_Struct
{
  bool scs_error;
  bool message_error;
  uint8_t gen_scs;
};

extern SOFT_INLINE void
SAF_ECU_Status_UnionToStruct(struct SAF_ECU_Status_Struct *s,
                             union SAF_ECU_Status_Union u);

extern SOFT_INLINE void
SAF_ECU_Status_StructToUnion(union SAF_ECU_Status_Union *u,
                             struct SAF_ECU_Status_Struct s);

/* ------------------------------ HSC_Steering ------------------------------ */

#define HSC_STEERING_ID 0x105
#define HSC_STEERING_DLC 4         // Number of Bytes
#define HSC_STEERING_CYCLE_TIME 10 // Milliseconds

union HSC_Steering_Union
{

  uint64_t data;

  struct
  {

    int64_t steering_wheel_angle : 12;
    int64_t steering_angle : 12;
    uint64_t st_angle_valid : 1;
    uint64_t gen_scs : 3;
    uint64_t reserved_1 : 36;
  };
};

struct HSC_Steering_Struct
{
  float steering_wheel_angle;
  float steering_angle;
  bool st_angle_valid;
  uint8_t gen_scs;
};

extern SOFT_INLINE void
HSC_Steering_UnionToStruct(struct HSC_Steering_Struct *s,
                           union HSC_Steering_Union u);

extern SOFT_INLINE void
HSC_Steering_StructToUnion(union HSC_Steering_Union *u,
                           struct HSC_Steering_Struct s);

/* ---------------------------- HSC_DriverInput ---------------------------- */

#define HSC_DRIVER_INPUT_ID 0x104
#define HSC_DRIVER_INPUT_DLC 3         // Number of Bytes
#define HSC_DRIVER_INPUT_CYCLE_TIME 10 // Milliseconds

union HSC_DriverInput_Union
{

  uint64_t data;

  struct
  {

    uint64_t throttle : 16;
    uint64_t brake_pressed : 1;
    uint64_t throttle_valid : 1;
    uint64_t brake_valid : 1;
    uint64_t reserved_1 : 2;
    uint64_t gen_scs : 3;
    uint64_t reserved_2 : 40;
  };
};

struct HSC_DriverInput_Struct
{
  float throttle;
  bool brake_pressed;
  bool throttle_valid;
  bool brake_valid;
  uint8_t gen_scs;
};

extern SOFT_INLINE void
HSC_DriverInput_UnionToStruct(struct HSC_DriverInput_Struct *s,
                              union HSC_DriverInput_Union u);

extern SOFT_INLINE void
HSC_DriverInput_StructToUnion(union HSC_DriverInput_Union *u,
                              struct HSC_DriverInput_Struct s);

/* ---------------------------- CANO_RES_NMT_EC ---------------------------- */

#define CANO_RES_NMT_EC_ID 0x711
#define CANO_RES_NMT_EC_DLC 1          // Number of Bytes
#define CANO_RES_NMT_EC_CYCLE_TIME 100 // Milliseconds

union CANO_RES_NMT_EC_Union
{

  uint64_t data;

  struct
  {

    uint64_t reserved_1 : 64;
  };
};

struct CANO_RES_NMT_EC_Struct
{
};

extern SOFT_INLINE void
CANO_RES_NMT_EC_UnionToStruct(struct CANO_RES_NMT_EC_Struct *s,
                              union CANO_RES_NMT_EC_Union u);

extern SOFT_INLINE void
CANO_RES_NMT_EC_StructToUnion(union CANO_RES_NMT_EC_Union *u,
                              struct CANO_RES_NMT_EC_Struct s);

/* ----------------------------- CANO_RES_RSDO ----------------------------- */

#define CANO_RES_RSDO_ID 0x611
#define CANO_RES_RSDO_DLC 8          // Number of Bytes
#define CANO_RES_RSDO_CYCLE_TIME 100 // Milliseconds

union CANO_RES_RSDO_Union
{

  uint64_t data;

  struct
  {

    uint64_t reserved_1 : 64;
  };
};

struct CANO_RES_RSDO_Struct
{
};

extern SOFT_INLINE void
CANO_RES_RSDO_UnionToStruct(struct CANO_RES_RSDO_Struct *s,
                            union CANO_RES_RSDO_Union u);

extern SOFT_INLINE void
CANO_RES_RSDO_StructToUnion(union CANO_RES_RSDO_Union *u,
                            struct CANO_RES_RSDO_Struct s);

/* ----------------------------- CANO_RES_TSDO ----------------------------- */

#define CANO_RES_TSDO_ID 0x591
#define CANO_RES_TSDO_DLC 8          // Number of Bytes
#define CANO_RES_TSDO_CYCLE_TIME 100 // Milliseconds

union CANO_RES_TSDO_Union
{

  uint64_t data;

  struct
  {

    uint64_t reserved_1 : 64;
  };
};

struct CANO_RES_TSDO_Struct
{
};

extern SOFT_INLINE void
CANO_RES_TSDO_UnionToStruct(struct CANO_RES_TSDO_Struct *s,
                            union CANO_RES_TSDO_Union u);

extern SOFT_INLINE void
CANO_RES_TSDO_StructToUnion(union CANO_RES_TSDO_Union *u,
                            struct CANO_RES_TSDO_Struct s);

/* ---------------------------- DV_FREE_TO_USE_2 ---------------------------- */

#define DV_FREE_TO_USE_2_ID 0x514
#define DV_FREE_TO_USE_2_DLC 0          // Number of Bytes
#define DV_FREE_TO_USE_2_CYCLE_TIME 100 // Milliseconds

union DV_FREE_TO_USE_2_Union
{

  uint64_t data;

  struct
  {

    uint64_t reserved_1 : 64;
  };
};

struct DV_FREE_TO_USE_2_Struct
{
};

extern SOFT_INLINE void
DV_FREE_TO_USE_2_UnionToStruct(struct DV_FREE_TO_USE_2_Struct *s,
                               union DV_FREE_TO_USE_2_Union u);

extern SOFT_INLINE void
DV_FREE_TO_USE_2_StructToUnion(union DV_FREE_TO_USE_2_Union *u,
                               struct DV_FREE_TO_USE_2_Struct s);

/* ----------------------------- CANO_RES_EMCY ----------------------------- */

#define CANO_RES_EMCY_ID 0x91
#define CANO_RES_EMCY_DLC 8          // Number of Bytes
#define CANO_RES_EMCY_CYCLE_TIME 100 // Milliseconds

union CANO_RES_EMCY_Union
{

  uint64_t data;

  struct
  {

    uint64_t reserved_1 : 64;
  };
};

struct CANO_RES_EMCY_Struct
{
};

extern SOFT_INLINE void
CANO_RES_EMCY_UnionToStruct(struct CANO_RES_EMCY_Struct *s,
                            union CANO_RES_EMCY_Union u);

extern SOFT_INLINE void
CANO_RES_EMCY_StructToUnion(union CANO_RES_EMCY_Union *u,
                            struct CANO_RES_EMCY_Struct s);

/* ----------------------------- DV_SCS_Errors ----------------------------- */

#define DV_SCS_ERRORS_ID 0x511
#define DV_SCS_ERRORS_DLC 8         // Number of Bytes
#define DV_SCS_ERRORS_CYCLE_TIME 10 // Milliseconds

union DV_SCS_Errors_Union
{

  uint64_t data;

  struct
  {

    uint64_t reserved_1 : 64;
  };
};

struct DV_SCS_Errors_Struct
{
};

extern SOFT_INLINE void
DV_SCS_Errors_UnionToStruct(struct DV_SCS_Errors_Struct *s,
                            union DV_SCS_Errors_Union u);

extern SOFT_INLINE void
DV_SCS_Errors_StructToUnion(union DV_SCS_Errors_Union *u,
                            struct DV_SCS_Errors_Struct s);

/* ----------------------------- DV_AMI_Status ----------------------------- */
typedef enum
{
  AMI_STATE_AUTOX = 6,
  AMI_STATE_INSPECTION = 5,
  AMI_STATE_EBSTEST = 4,
  AMI_STATE_TRACKDRIVE = 3,
  AMI_STATE_SKIDPAD = 2,
  AMI_STATE_ACCEL = 1,
  AMI_STATE_MANUAL = 0,
} DV_AMI_Status_AMI_State;

#define DV_AMI_STATUS_ID 0x505
#define DV_AMI_STATUS_DLC 1          // Number of Bytes
#define DV_AMI_STATUS_CYCLE_TIME 100 // Milliseconds

union DV_AMI_Status_Union
{

  uint64_t data;

  struct
  {

    uint64_t ami_state : 3;
    uint64_t gen_scs : 3;
    uint64_t reserved_1 : 58;
  };
};

struct DV_AMI_Status_Struct
{
  DV_AMI_Status_AMI_State ami_state;
  uint8_t gen_scs;
};

extern SOFT_INLINE void
DV_AMI_Status_UnionToStruct(struct DV_AMI_Status_Struct *s,
                            union DV_AMI_Status_Union u);

extern SOFT_INLINE void
DV_AMI_Status_StructToUnion(union DV_AMI_Status_Union *u,
                            struct DV_AMI_Status_Struct s);

/* ---------------------------- DV_ASB_Pressure ---------------------------- */

#define DV_ASB_PRESSURE_ID 0x513
#define DV_ASB_PRESSURE_DLC 3          // Number of Bytes
#define DV_ASB_PRESSURE_CYCLE_TIME 100 // Milliseconds

union DV_ASB_Pressure_Union
{

  uint64_t data;

  struct
  {

    uint64_t pressure_1 : 12;
    uint64_t pressure_2 : 12;
    uint64_t reserved_1 : 40;
  };
};

struct DV_ASB_Pressure_Struct
{
  float pressure_1;
  float pressure_2;
};

extern SOFT_INLINE void
DV_ASB_Pressure_UnionToStruct(struct DV_ASB_Pressure_Struct *s,
                              union DV_ASB_Pressure_Union u);

extern SOFT_INLINE void
DV_ASB_Pressure_StructToUnion(union DV_ASB_Pressure_Union *u,
                              struct DV_ASB_Pressure_Struct s);

/* -------------------------- DV_DrivingDynamics1 -------------------------- */

#define DV_DRIVING_DYNAMICS_1_ID 0x500
#define DV_DRIVING_DYNAMICS_1_DLC 8          // Number of Bytes
#define DV_DRIVING_DYNAMICS_1_CYCLE_TIME 100 // Milliseconds

union DV_DrivingDynamics1_Union
{

  uint64_t data;

  struct
  {

    uint64_t speed_actual : 8;
    uint64_t speed_target : 8;
    int64_t steering_angle_actual : 8;
    int64_t steering_angle_target : 8;
    uint64_t brake_hydr_actual : 8;
    uint64_t brake_hydr_target : 8;
    int64_t motor_moment_actual : 8;
    int64_t motor_moment_target : 8;
  };
};

struct DV_DrivingDynamics1_Struct
{
  uint8_t speed_actual;
  uint8_t speed_target;
  float steering_angle_actual;
  float steering_angle_target;
  uint8_t brake_hydr_actual;
  uint8_t brake_hydr_target;
  int8_t motor_moment_actual;
  int8_t motor_moment_target;
};

extern SOFT_INLINE void
DV_DrivingDynamics1_UnionToStruct(struct DV_DrivingDynamics1_Struct *s,
                                  union DV_DrivingDynamics1_Union u);

extern SOFT_INLINE void
DV_DrivingDynamics1_StructToUnion(union DV_DrivingDynamics1_Union *u,
                                  struct DV_DrivingDynamics1_Struct s);

/* -------------------------- DV_DrivingDynamics2 -------------------------- */

#define DV_DRIVING_DYNAMICS_2_ID 0x501
#define DV_DRIVING_DYNAMICS_2_DLC 6          // Number of Bytes
#define DV_DRIVING_DYNAMICS_2_CYCLE_TIME 100 // Milliseconds

union DV_DrivingDynamics2_Union
{

  uint64_t data;

  struct
  {

    int64_t acceleration_longitudinal : 16;
    int64_t acceleration_lateral : 16;
    int64_t yaw_rate : 16;
    uint64_t reserved_1 : 16;
  };
};

struct DV_DrivingDynamics2_Struct
{
  float acceleration_longitudinal;
  float acceleration_lateral;
  float yaw_rate;
};

extern SOFT_INLINE void
DV_DrivingDynamics2_UnionToStruct(struct DV_DrivingDynamics2_Struct *s,
                                  union DV_DrivingDynamics2_Union u);

extern SOFT_INLINE void
DV_DrivingDynamics2_StructToUnion(union DV_DrivingDynamics2_Union *u,
                                  struct DV_DrivingDynamics2_Struct s);

/* ---------------------------- DV_System_Status ---------------------------- */
typedef enum
{
  AS_STATE_FINISHED = 5,
  AS_STATE_EMERGENCY = 4,
  AS_STATE_DRIVING = 3,
  AS_STATE_READY = 2,
  AS_STATE_OFF = 1,
  AS_STATE__ = 0,
} DV_System_Status_AS_State;

typedef enum
{
  SYS_AMI_STATE_AUTOX = 6,
  SYS_AMI_STATE_INSPECTION = 5,
  SYS_AMI_STATE_EBSTEST = 4,
  SYS_AMI_STATE_TRACKDRIVE = 3,
  SYS_AMI_STATE_SKIDPAD = 2,
  SYS_AMI_STATE_ACCEL = 1,
  SYS_AMI_STATE_MANUAL = 0,
} DV_System_Status_AMI_State;

#define DV_SYSTEM_STATUS_ID 0x502
#define DV_SYSTEM_STATUS_DLC 5          // Number of Bytes
#define DV_SYSTEM_STATUS_CYCLE_TIME 100 // Milliseconds

union DV_System_Status_Union
{

  uint64_t data;

  struct
  {

    uint64_t as_state : 3;
    uint64_t ebs_state : 2;
    uint64_t ami_state : 3;
    uint64_t steering_state : 1;
    uint64_t service_brake_state : 2;
    uint64_t lap_counter : 4;
    uint64_t cones_count_actual : 8;
    uint64_t cones_count_all : 17;
    uint64_t reserved_1 : 24;
  };
};

struct DV_System_Status_Struct
{
  DV_System_Status_AS_State as_state;
  uint8_t ebs_state;
  DV_System_Status_AMI_State ami_state;
  bool steering_state;
  uint8_t service_brake_state;
  uint8_t lap_counter;
  uint8_t cones_count_actual;
  uint32_t cones_count_all;
};

extern SOFT_INLINE void
DV_System_Status_UnionToStruct(struct DV_System_Status_Struct *s,
                               union DV_System_Status_Union u);

extern SOFT_INLINE void
DV_System_Status_StructToUnion(union DV_System_Status_Union *u,
                               struct DV_System_Status_Struct s);

/* ----------------------------- DV_ASB_Status ----------------------------- */

#define DV_ASB_STATUS_ID 0x503
#define DV_ASB_STATUS_DLC 3         // Number of Bytes
#define DV_ASB_STATUS_CYCLE_TIME 10 // Milliseconds

union DV_ASB_Status_Union
{

  uint64_t data;

  struct
  {

    uint64_t asms : 1;
    uint64_t ebs_state : 2;
    uint64_t service_brake_state : 2;
    uint64_t check_sequence : 3;
    uint64_t checkup_complete : 1;
    uint64_t sdc_closed : 1;
    uint64_t scs_error : 1;
    uint64_t trigger_cause : 4;
    uint64_t asb_state : 3;
    uint64_t gen_scs : 3;
    uint64_t reserved_1 : 43;
  };
};

struct DV_ASB_Status_Struct
{
  bool asms;
  uint8_t ebs_state;
  uint8_t service_brake_state;
  uint8_t check_sequence;
  bool checkup_complete;
  bool sdc_closed;
  bool scs_error;
  uint8_t trigger_cause;
  uint8_t asb_state;
  uint8_t gen_scs;
};

extern SOFT_INLINE void
DV_ASB_Status_UnionToStruct(struct DV_ASB_Status_Struct *s,
                            union DV_ASB_Status_Union u);

extern SOFT_INLINE void
DV_ASB_Status_StructToUnion(union DV_ASB_Status_Union *u,
                            struct DV_ASB_Status_Struct s);

/* ----------------------------- CANO_RES_TPDO4 ----------------------------- */

#define CANO_RES_TPDO4_ID 0x491
#define CANO_RES_TPDO4_DLC 0          // Number of Bytes
#define CANO_RES_TPDO4_CYCLE_TIME 100 // Milliseconds

union CANO_RES_TPDO4_Union
{

  uint64_t data;

  struct
  {

    uint64_t reserved_1 : 64;
  };
};

struct CANO_RES_TPDO4_Struct
{
};

extern SOFT_INLINE void
CANO_RES_TPDO4_UnionToStruct(struct CANO_RES_TPDO4_Struct *s,
                             union CANO_RES_TPDO4_Union u);

extern SOFT_INLINE void
CANO_RES_TPDO4_StructToUnion(union CANO_RES_TPDO4_Union *u,
                             struct CANO_RES_TPDO4_Struct s);

/* ----------------------------- CANO_RES_TPDO3 ----------------------------- */

#define CANO_RES_TPDO3_ID 0x391
#define CANO_RES_TPDO3_DLC 0          // Number of Bytes
#define CANO_RES_TPDO3_CYCLE_TIME 100 // Milliseconds

union CANO_RES_TPDO3_Union
{

  uint64_t data;

  struct
  {

    uint64_t reserved_1 : 64;
  };
};

struct CANO_RES_TPDO3_Struct
{
};

extern SOFT_INLINE void
CANO_RES_TPDO3_UnionToStruct(struct CANO_RES_TPDO3_Struct *s,
                             union CANO_RES_TPDO3_Union u);

extern SOFT_INLINE void
CANO_RES_TPDO3_StructToUnion(union CANO_RES_TPDO3_Union *u,
                             struct CANO_RES_TPDO3_Struct s);

/* ----------------------------- CANO_RES_TPDO2 ----------------------------- */

#define CANO_RES_TPDO2_ID 0x291
#define CANO_RES_TPDO2_DLC 0          // Number of Bytes
#define CANO_RES_TPDO2_CYCLE_TIME 100 // Milliseconds

union CANO_RES_TPDO2_Union
{

  uint64_t data;

  struct
  {

    uint64_t reserved_1 : 64;
  };
};

struct CANO_RES_TPDO2_Struct
{
};

extern SOFT_INLINE void
CANO_RES_TPDO2_UnionToStruct(struct CANO_RES_TPDO2_Struct *s,
                             union CANO_RES_TPDO2_Union u);

extern SOFT_INLINE void
CANO_RES_TPDO2_StructToUnion(union CANO_RES_TPDO2_Union *u,
                             struct CANO_RES_TPDO2_Struct s);

/* ----------------------------- CANO_RES_RPDO3 ----------------------------- */

#define CANO_RES_RPDO3_ID 0x411
#define CANO_RES_RPDO3_DLC 0          // Number of Bytes
#define CANO_RES_RPDO3_CYCLE_TIME 100 // Milliseconds

union CANO_RES_RPDO3_Union
{

  uint64_t data;

  struct
  {

    uint64_t reserved_1 : 64;
  };
};

struct CANO_RES_RPDO3_Struct
{
};

extern SOFT_INLINE void
CANO_RES_RPDO3_UnionToStruct(struct CANO_RES_RPDO3_Struct *s,
                             union CANO_RES_RPDO3_Union u);

extern SOFT_INLINE void
CANO_RES_RPDO3_StructToUnion(union CANO_RES_RPDO3_Union *u,
                             struct CANO_RES_RPDO3_Struct s);

/* ----------------------------- CANO_RES_RPDO2 ----------------------------- */

#define CANO_RES_RPDO2_ID 0x311
#define CANO_RES_RPDO2_DLC 0          // Number of Bytes
#define CANO_RES_RPDO2_CYCLE_TIME 100 // Milliseconds

union CANO_RES_RPDO2_Union
{

  uint64_t data;

  struct
  {

    uint64_t reserved_1 : 64;
  };
};

struct CANO_RES_RPDO2_Struct
{
};

extern SOFT_INLINE void
CANO_RES_RPDO2_UnionToStruct(struct CANO_RES_RPDO2_Struct *s,
                             union CANO_RES_RPDO2_Union u);

extern SOFT_INLINE void
CANO_RES_RPDO2_StructToUnion(union CANO_RES_RPDO2_Union *u,
                             struct CANO_RES_RPDO2_Struct s);

/* ----------------------------- CANO_RES_RPDO1 ----------------------------- */

#define CANO_RES_RPDO1_ID 0x211
#define CANO_RES_RPDO1_DLC 0          // Number of Bytes
#define CANO_RES_RPDO1_CYCLE_TIME 100 // Milliseconds

union CANO_RES_RPDO1_Union
{

  uint64_t data;

  struct
  {

    uint64_t reserved_1 : 64;
  };
};

struct CANO_RES_RPDO1_Struct
{
};

extern SOFT_INLINE void
CANO_RES_RPDO1_UnionToStruct(struct CANO_RES_RPDO1_Struct *s,
                             union CANO_RES_RPDO1_Union u);

extern SOFT_INLINE void
CANO_RES_RPDO1_StructToUnion(union CANO_RES_RPDO1_Union *u,
                             struct CANO_RES_RPDO1_Struct s);

/* ----------------------------- CANO_RES_State ----------------------------- */

#define CANO_RES_STATE_ID 0x191
#define CANO_RES_STATE_DLC 8         // Number of Bytes
#define CANO_RES_STATE_CYCLE_TIME 30 // Milliseconds

union CANO_RES_State_Union
{

  uint64_t data;

  struct
  {

    uint64_t k1_e_stop : 1;
    uint64_t k2_switch : 1;
    uint64_t k3_button : 1;
    uint64_t reserved_1 : 45;
    uint64_t link_quality : 8;
    uint64_t reserved_2 : 6;
    uint64_t pre_alarm : 1;
    uint64_t race_mode : 1;
  };
};

struct CANO_RES_State_Struct
{
  bool k1_e_stop;
  bool k2_switch;
  bool k3_button;
  uint8_t link_quality;
  bool pre_alarm;
  bool race_mode;
};

extern SOFT_INLINE void
CANO_RES_State_UnionToStruct(struct CANO_RES_State_Struct *s,
                             union CANO_RES_State_Union u);

extern SOFT_INLINE void
CANO_RES_State_StructToUnion(union CANO_RES_State_Union *u,
                             struct CANO_RES_State_Struct s);

/* ------------------------------- CANO_TIME ------------------------------- */

#define CANO_TIME_ID 0x100
#define CANO_TIME_DLC 6          // Number of Bytes
#define CANO_TIME_CYCLE_TIME 100 // Milliseconds

union CANO_TIME_Union
{

  uint64_t data;

  struct
  {

    uint64_t reserved_1 : 64;
  };
};

struct CANO_TIME_Struct
{
};

extern SOFT_INLINE void CANO_TIME_UnionToStruct(struct CANO_TIME_Struct *s,
                                                union CANO_TIME_Union u);

extern SOFT_INLINE void CANO_TIME_StructToUnion(union CANO_TIME_Union *u,
                                                struct CANO_TIME_Struct s);

/* ------------------------------- CANO_SYNC ------------------------------- */

#define CANO_SYNC_ID 0x80
#define CANO_SYNC_DLC 0          // Number of Bytes
#define CANO_SYNC_CYCLE_TIME 100 // Milliseconds

union CANO_SYNC_Union
{

  uint64_t data;

  struct
  {

    uint64_t reserved_1 : 64;
  };
};

struct CANO_SYNC_Struct
{
};

extern SOFT_INLINE void CANO_SYNC_UnionToStruct(struct CANO_SYNC_Struct *s,
                                                union CANO_SYNC_Union u);

extern SOFT_INLINE void CANO_SYNC_StructToUnion(union CANO_SYNC_Union *u,
                                                struct CANO_SYNC_Struct s);

/* ------------------------- CANO_NMT_Node_Control ------------------------- */
typedef enum
{
  REQUESTED_STATE_RESET_COMMUNICATION = 130,
  REQUESTED_STATE_RESET_APPLICATION = 129,
  REQUESTED_STATE_STOPPED_MODE = 2,
  REQUESTED_STATE_PRE_OPERATIONAL_MODE = 128,
  REQUESTED_STATE_OPERATIONAL_MODE = 1,
} CANO_NMT_Node_Control_Requested_State;

typedef enum
{
  ADDRESSED_NODE_ID_RES = 17,
  ADDRESSED_NODE_ID_EPOS = 12,
  ADDRESSED_NODE_ID_ALL = 0,
} CANO_NMT_Node_Control_Addressed_Node_ID;

#define CANO_NMT_NODE_CONTROL_ID 0x0
#define CANO_NMT_NODE_CONTROL_DLC 2          // Number of Bytes
#define CANO_NMT_NODE_CONTROL_CYCLE_TIME 100 // Milliseconds

union CANO_NMT_Node_Control_Union
{

  uint64_t data;

  struct
  {

    uint64_t requested_state : 8;
    uint64_t addressed_node_id : 8;
    uint64_t reserved_1 : 48;
  };
};

struct CANO_NMT_Node_Control_Struct
{
  CANO_NMT_Node_Control_Requested_State requested_state;
  CANO_NMT_Node_Control_Addressed_Node_ID addressed_node_id;
};

extern SOFT_INLINE void
CANO_NMT_Node_Control_UnionToStruct(struct CANO_NMT_Node_Control_Struct *s,
                                    union CANO_NMT_Node_Control_Union u);

extern SOFT_INLINE void
CANO_NMT_Node_Control_StructToUnion(union CANO_NMT_Node_Control_Union *u,
                                    struct CANO_NMT_Node_Control_Struct s);

/* --------------------------- CAL_SteeringAngle --------------------------- */

#define CAL_STEERING_ANGLE_ID 0x490
#define CAL_STEERING_ANGLE_DLC 2          // Number of Bytes
#define CAL_STEERING_ANGLE_CYCLE_TIME 100 // Milliseconds

union CAL_SteeringAngle_Union
{

  uint64_t data;

  struct
  {

    uint64_t voltage_stang : 12;
    uint64_t reserved_1 : 52;
  };
};

struct CAL_SteeringAngle_Struct
{
  uint16_t voltage_stang;
};

extern SOFT_INLINE void
CAL_SteeringAngle_UnionToStruct(struct CAL_SteeringAngle_Struct *s,
                                union CAL_SteeringAngle_Union u);

extern SOFT_INLINE void
CAL_SteeringAngle_StructToUnion(union CAL_SteeringAngle_Union *u,
                                struct CAL_SteeringAngle_Struct s);

/* -------------------------------- CAL_APPS -------------------------------- */

#define CAL_APPS_ID 0x48F
#define CAL_APPS_DLC 6          // Number of Bytes
#define CAL_APPS_CYCLE_TIME 100 // Milliseconds

union CAL_APPS_Union
{

  uint64_t data;

  struct
  {

    uint64_t upper_3v3 : 12;
    uint64_t lower_3v3 : 12;
    uint64_t upper_5v : 12;
    uint64_t lower_5v : 12;
    uint64_t reserved_1 : 16;
  };
};

struct CAL_APPS_Struct
{
  uint16_t upper_3v3;
  uint16_t lower_3v3;
  float upper_5v;
  float lower_5v;
};

extern SOFT_INLINE void CAL_APPS_UnionToStruct(struct CAL_APPS_Struct *s,
                                               union CAL_APPS_Union u);

extern SOFT_INLINE void CAL_APPS_StructToUnion(union CAL_APPS_Union *u,
                                               struct CAL_APPS_Struct s);

/* --------------------------- CAL_BrakePressures --------------------------- */

#define CAL_BRAKE_PRESSURES_ID 0x485
#define CAL_BRAKE_PRESSURES_DLC 6          // Number of Bytes
#define CAL_BRAKE_PRESSURES_CYCLE_TIME 100 // Milliseconds

union CAL_BrakePressures_Union
{

  uint64_t data;

  struct
  {

    uint64_t front_3v3 : 12;
    uint64_t rear_3v3 : 12;
    uint64_t front_5v : 12;
    uint64_t rear_5v : 12;
    uint64_t reserved_1 : 16;
  };
};

struct CAL_BrakePressures_Struct
{
  uint16_t front_3v3;
  uint16_t rear_3v3;
  float front_5v;
  float rear_5v;
};

extern SOFT_INLINE void
CAL_BrakePressures_UnionToStruct(struct CAL_BrakePressures_Struct *s,
                                 union CAL_BrakePressures_Union u);

extern SOFT_INLINE void
CAL_BrakePressures_StructToUnion(union CAL_BrakePressures_Union *u,
                                 struct CAL_BrakePressures_Struct s);

/* ------------------------- CAL_SpringTravel_Rear ------------------------- */

#define CAL_SPRING_TRAVEL_REAR_ID 0x484
#define CAL_SPRING_TRAVEL_REAR_DLC 7          // Number of Bytes
#define CAL_SPRING_TRAVEL_REAR_CYCLE_TIME 100 // Milliseconds

union CAL_SpringTravel_Rear_Union
{

  uint64_t data;

  struct
  {

    int64_t rear_right_converted : 16;
    int64_t rear_left_converted : 16;
    uint64_t rear_right_voltage : 12;
    uint64_t rear_left_voltage : 12;
    uint64_t reserved_1 : 8;
  };
};

struct CAL_SpringTravel_Rear_Struct
{
  float rear_right_converted;
  float rear_left_converted;
  uint16_t rear_right_voltage;
  uint16_t rear_left_voltage;
};

extern SOFT_INLINE void
CAL_SpringTravel_Rear_UnionToStruct(struct CAL_SpringTravel_Rear_Struct *s,
                                    union CAL_SpringTravel_Rear_Union u);

extern SOFT_INLINE void
CAL_SpringTravel_Rear_StructToUnion(union CAL_SpringTravel_Rear_Union *u,
                                    struct CAL_SpringTravel_Rear_Struct s);

/* ------------------------- CAL_SpringTravel_Front ------------------------- */

#define CAL_SPRING_TRAVEL_FRONT_ID 0x483
#define CAL_SPRING_TRAVEL_FRONT_DLC 7          // Number of Bytes
#define CAL_SPRING_TRAVEL_FRONT_CYCLE_TIME 100 // Milliseconds

union CAL_SpringTravel_Front_Union
{

  uint64_t data;

  struct
  {

    int64_t front_right_converted : 16;
    int64_t front_left_converted : 16;
    uint64_t front_right_voltage : 12;
    uint64_t front_left_voltage : 12;
    uint64_t reserved_1 : 8;
  };
};

struct CAL_SpringTravel_Front_Struct
{
  float front_right_converted;
  float front_left_converted;
  uint16_t front_right_voltage;
  uint16_t front_left_voltage;
};

extern SOFT_INLINE void
CAL_SpringTravel_Front_UnionToStruct(struct CAL_SpringTravel_Front_Struct *s,
                                     union CAL_SpringTravel_Front_Union u);

extern SOFT_INLINE void
CAL_SpringTravel_Front_StructToUnion(union CAL_SpringTravel_Front_Union *u,
                                     struct CAL_SpringTravel_Front_Struct s);

/* ------------------------- CAL_CalibrationMaster ------------------------- */

#define CAL_CALIBRATION_MASTER_ID 0x480
#define CAL_CALIBRATION_MASTER_DLC 1          // Number of Bytes
#define CAL_CALIBRATION_MASTER_CYCLE_TIME 100 // Milliseconds

union CAL_CalibrationMaster_Union
{

  uint64_t data;

  struct
  {

    uint64_t reserved_1 : 64;
  };
};

struct CAL_CalibrationMaster_Struct
{
};

extern SOFT_INLINE void
CAL_CalibrationMaster_UnionToStruct(struct CAL_CalibrationMaster_Struct *s,
                                    union CAL_CalibrationMaster_Union u);

extern SOFT_INLINE void
CAL_CalibrationMaster_StructToUnion(union CAL_CalibrationMaster_Union *u,
                                    struct CAL_CalibrationMaster_Struct s);

/* ---------------------------- DV_DriveCommand ---------------------------- */

#define DV_DRIVE_COMMAND_ID 0x512
#define DV_DRIVE_COMMAND_DLC 5         // Number of Bytes
#define DV_DRIVE_COMMAND_CYCLE_TIME 10 // Milliseconds

union DV_DriveCommand_Union
{

  uint64_t data;

  struct
  {

    uint64_t rtd_request : 1;
    uint64_t ebs_trigger : 1;
    uint64_t throttle_command : 10;
    uint64_t brake_command : 10;
    uint64_t recu_command : 10;
    uint64_t gen_scs : 3;
    uint64_t reserved_1 : 29;
  };
};

struct DV_DriveCommand_Struct
{
  bool rtd_request;
  bool ebs_trigger;
  float throttle_command;
  float brake_command;
  float recu_command;
  uint8_t gen_scs;
};

extern SOFT_INLINE void
DV_DriveCommand_UnionToStruct(struct DV_DriveCommand_Struct *s,
                              union DV_DriveCommand_Union u);

extern SOFT_INLINE void
DV_DriveCommand_StructToUnion(union DV_DriveCommand_Union *u,
                              struct DV_DriveCommand_Struct s);

/* -------------------------- LOG_WaterTemps_Left -------------------------- */

#define LOG_WATER_TEMPS_LEFT_ID 0x781
#define LOG_WATER_TEMPS_LEFT_DLC 4          // Number of Bytes
#define LOG_WATER_TEMPS_LEFT_CYCLE_TIME 500 // Milliseconds

union LOG_WaterTemps_Left_Union
{

  uint64_t data;

  struct
  {

    uint64_t wt_1_l : 8;
    uint64_t wt_2_l : 8;
    uint64_t wt_3_l : 8;
    uint64_t wt_4_l : 8;
    uint64_t reserved_1 : 32;
  };
};

struct LOG_WaterTemps_Left_Struct
{
  float wt_1_l;
  float wt_2_l;
  float wt_3_l;
  float wt_4_l;
};

extern SOFT_INLINE void
LOG_WaterTemps_Left_UnionToStruct(struct LOG_WaterTemps_Left_Struct *s,
                                  union LOG_WaterTemps_Left_Union u);

extern SOFT_INLINE void
LOG_WaterTemps_Left_StructToUnion(union LOG_WaterTemps_Left_Union *u,
                                  struct LOG_WaterTemps_Left_Struct s);

/* -------------------------- LOG_WaterTemps_Right -------------------------- */

#define LOG_WATER_TEMPS_RIGHT_ID 0x782
#define LOG_WATER_TEMPS_RIGHT_DLC 4          // Number of Bytes
#define LOG_WATER_TEMPS_RIGHT_CYCLE_TIME 500 // Milliseconds

union LOG_WaterTemps_Right_Union
{

  uint64_t data;

  struct
  {

    uint64_t wt_1_r : 8;
    uint64_t wt_2_r : 8;
    uint64_t wt_3_r : 8;
    uint64_t wt_4_r : 8;
    uint64_t reserved_1 : 32;
  };
};

struct LOG_WaterTemps_Right_Struct
{
  float wt_1_r;
  float wt_2_r;
  float wt_3_r;
  float wt_4_r;
};

extern SOFT_INLINE void
LOG_WaterTemps_Right_UnionToStruct(struct LOG_WaterTemps_Right_Struct *s,
                                   union LOG_WaterTemps_Right_Union u);

extern SOFT_INLINE void
LOG_WaterTemps_Right_StructToUnion(union LOG_WaterTemps_Right_Union *u,
                                   struct LOG_WaterTemps_Right_Struct s);

/* ------------------------- LOG_SpringTravel_Front ------------------------- */

#define LOG_SPRING_TRAVEL_FRONT_ID 0x783
#define LOG_SPRING_TRAVEL_FRONT_DLC 4          // Number of Bytes
#define LOG_SPRING_TRAVEL_FRONT_CYCLE_TIME 100 // Milliseconds

union LOG_SpringTravel_Front_Union
{

  uint64_t data;

  struct
  {

    int64_t front_left : 16;
    int64_t front_right : 16;
    uint64_t reserved_1 : 32;
  };
};

struct LOG_SpringTravel_Front_Struct
{
  float front_left;
  float front_right;
};

extern SOFT_INLINE void
LOG_SpringTravel_Front_UnionToStruct(struct LOG_SpringTravel_Front_Struct *s,
                                     union LOG_SpringTravel_Front_Union u);

extern SOFT_INLINE void
LOG_SpringTravel_Front_StructToUnion(union LOG_SpringTravel_Front_Union *u,
                                     struct LOG_SpringTravel_Front_Struct s);

/* ------------------------- LOG_SpringTravel_Rear ------------------------- */

#define LOG_SPRING_TRAVEL_REAR_ID 0x784
#define LOG_SPRING_TRAVEL_REAR_DLC 4          // Number of Bytes
#define LOG_SPRING_TRAVEL_REAR_CYCLE_TIME 100 // Milliseconds

union LOG_SpringTravel_Rear_Union
{

  uint64_t data;

  struct
  {

    int64_t rear_left : 16;
    int64_t rear_right : 16;
    uint64_t reserved_1 : 32;
  };
};

struct LOG_SpringTravel_Rear_Struct
{
  float rear_left;
  float rear_right;
};

extern SOFT_INLINE void
LOG_SpringTravel_Rear_UnionToStruct(struct LOG_SpringTravel_Rear_Struct *s,
                                    union LOG_SpringTravel_Rear_Union u);

extern SOFT_INLINE void
LOG_SpringTravel_Rear_StructToUnion(union LOG_SpringTravel_Rear_Union *u,
                                    struct LOG_SpringTravel_Rear_Struct s);

/* --------------------------- LOG_BrakePressures --------------------------- */

#define LOG_BRAKE_PRESSURES_ID 0x515
#define LOG_BRAKE_PRESSURES_DLC 3         // Number of Bytes
#define LOG_BRAKE_PRESSURES_CYCLE_TIME 10 // Milliseconds

union LOG_BrakePressures_Union
{

  uint64_t data;

  struct
  {

    uint64_t front_bp : 12;
    uint64_t rear_bp : 12;
    uint64_t reserved_1 : 40;
  };
};

struct LOG_BrakePressures_Struct
{
  float front_bp;
  float rear_bp;
};

extern SOFT_INLINE void
LOG_BrakePressures_UnionToStruct(struct LOG_BrakePressures_Struct *s,
                                 union LOG_BrakePressures_Union u);

extern SOFT_INLINE void
LOG_BrakePressures_StructToUnion(union LOG_BrakePressures_Union *u,
                                 struct LOG_BrakePressures_Struct s);

/* -------------------------------- LOG_LEM -------------------------------- */

#define LOG_LEM_ID 0x786
#define LOG_LEM_DLC 2          // Number of Bytes
#define LOG_LEM_CYCLE_TIME 100 // Milliseconds

union LOG_LEM_Union
{

  uint64_t data;

  struct
  {

    uint64_t lv_current : 16;
    uint64_t reserved_1 : 48;
  };
};

struct LOG_LEM_Struct
{
  uint16_t lv_current;
};

extern SOFT_INLINE void LOG_LEM_UnionToStruct(struct LOG_LEM_Struct *s,
                                              union LOG_LEM_Union u);

extern SOFT_INLINE void LOG_LEM_StructToUnion(union LOG_LEM_Union *u,
                                              struct LOG_LEM_Struct s);

/* ------------------------------ LOG_Airp_FW ------------------------------ */

#define LOG_AIRP_FW_ID 0x7C0
#define LOG_AIRP_FW_DLC 4          // Number of Bytes
#define LOG_AIRP_FW_CYCLE_TIME 100 // Milliseconds

union LOG_Airp_FW_Union
{

  uint64_t data;

  struct
  {

    uint64_t airp_1_fw : 16;
    uint64_t airp_2_fw : 16;
    uint64_t reserved_1 : 32;
  };
};

struct LOG_Airp_FW_Struct
{
  float airp_1_fw;
  float airp_2_fw;
};

extern SOFT_INLINE void LOG_Airp_FW_UnionToStruct(struct LOG_Airp_FW_Struct *s,
                                                  union LOG_Airp_FW_Union u);

extern SOFT_INLINE void LOG_Airp_FW_StructToUnion(union LOG_Airp_FW_Union *u,
                                                  struct LOG_Airp_FW_Struct s);

/* ------------------------------ LOG_Airp_SPL ------------------------------ */

#define LOG_AIRP_SPL_ID 0x7C1
#define LOG_AIRP_SPL_DLC 6          // Number of Bytes
#define LOG_AIRP_SPL_CYCLE_TIME 100 // Milliseconds

union LOG_Airp_SPL_Union
{

  uint64_t data;

  struct
  {

    uint64_t airp_1_spl : 16;
    uint64_t airp_2_spl : 16;
    uint64_t airp_3_spl : 16;
    uint64_t reserved_1 : 16;
  };
};

struct LOG_Airp_SPL_Struct
{
  float airp_1_spl;
  float airp_2_spl;
  float airp_3_spl;
};

extern SOFT_INLINE void
LOG_Airp_SPL_UnionToStruct(struct LOG_Airp_SPL_Struct *s,
                           union LOG_Airp_SPL_Union u);

extern SOFT_INLINE void
LOG_Airp_SPL_StructToUnion(union LOG_Airp_SPL_Union *u,
                           struct LOG_Airp_SPL_Struct s);

/* ------------------------------ LOG_Airp_SPR ------------------------------ */

#define LOG_AIRP_SPR_ID 0x7C2
#define LOG_AIRP_SPR_DLC 6          // Number of Bytes
#define LOG_AIRP_SPR_CYCLE_TIME 100 // Milliseconds

union LOG_Airp_SPR_Union
{

  uint64_t data;

  struct
  {

    uint64_t airp_1_spr : 16;
    uint64_t airp_2_spr : 16;
    uint64_t airp_3_spr : 16;
    uint64_t reserved_1 : 16;
  };
};

struct LOG_Airp_SPR_Struct
{
  float airp_1_spr;
  float airp_2_spr;
  float airp_3_spr;
};

extern SOFT_INLINE void
LOG_Airp_SPR_UnionToStruct(struct LOG_Airp_SPR_Struct *s,
                           union LOG_Airp_SPR_Union u);

extern SOFT_INLINE void
LOG_Airp_SPR_StructToUnion(union LOG_Airp_SPR_Union *u,
                           struct LOG_Airp_SPR_Struct s);

/* ------------------------------ LOG_Airp_RW ------------------------------ */

#define LOG_AIRP_RW_ID 0x7C3
#define LOG_AIRP_RW_DLC 4          // Number of Bytes
#define LOG_AIRP_RW_CYCLE_TIME 100 // Milliseconds

union LOG_Airp_RW_Union
{

  uint64_t data;

  struct
  {

    uint64_t airp_1_rw : 16;
    uint64_t airp_2_rw : 16;
    uint64_t reserved_1 : 32;
  };
};

struct LOG_Airp_RW_Struct
{
  float airp_1_rw;
  float airp_2_rw;
};

extern SOFT_INLINE void LOG_Airp_RW_UnionToStruct(struct LOG_Airp_RW_Struct *s,
                                                  union LOG_Airp_RW_Union u);

extern SOFT_INLINE void LOG_Airp_RW_StructToUnion(union LOG_Airp_RW_Union *u,
                                                  struct LOG_Airp_RW_Struct s);

/* ---------------------------- LOG_PE_MaxTemps ---------------------------- */

#define LOG_PE_MAX_TEMPS_ID 0x78C
#define LOG_PE_MAX_TEMPS_DLC 8          // Number of Bytes
#define LOG_PE_MAX_TEMPS_CYCLE_TIME 100 // Milliseconds

union LOG_PE_MaxTemps_Union
{

  uint64_t data;

  struct
  {

    uint64_t front_pe : 8;
    uint64_t rear_pe : 8;
    uint64_t left_pe : 8;
    uint64_t right_pe : 8;
    uint64_t usage_front : 8;
    uint64_t usage_rear : 8;
    uint64_t usage_left : 8;
    uint64_t usage_right : 8;
  };
};

struct LOG_PE_MaxTemps_Struct
{
  float front_pe;
  float rear_pe;
  float left_pe;
  float right_pe;
  float usage_front;
  float usage_rear;
  float usage_left;
  float usage_right;
};

extern SOFT_INLINE void
LOG_PE_MaxTemps_UnionToStruct(struct LOG_PE_MaxTemps_Struct *s,
                              union LOG_PE_MaxTemps_Union u);

extern SOFT_INLINE void
LOG_PE_MaxTemps_StructToUnion(union LOG_PE_MaxTemps_Union *u,
                              struct LOG_PE_MaxTemps_Struct s);

/* -------------------------- LOG_EKF_Translation -------------------------- */

#define LOG_EKF_TRANSLATION_ID 0x78D
#define LOG_EKF_TRANSLATION_DLC 8          // Number of Bytes
#define LOG_EKF_TRANSLATION_CYCLE_TIME 100 // Milliseconds

union LOG_EKF_Translation_Union
{

  uint64_t data;

  struct
  {

    int64_t velocity_vx : 16;
    int64_t velocity_vy : 16;
    int64_t acceleration_ax : 16;
    int64_t acceleration_ay : 16;
  };
};

struct LOG_EKF_Translation_Struct
{
  float velocity_vx;
  float velocity_vy;
  float acceleration_ax;
  float acceleration_ay;
};

extern SOFT_INLINE void
LOG_EKF_Translation_UnionToStruct(struct LOG_EKF_Translation_Struct *s,
                                  union LOG_EKF_Translation_Union u);

extern SOFT_INLINE void
LOG_EKF_Translation_StructToUnion(union LOG_EKF_Translation_Union *u,
                                  struct LOG_EKF_Translation_Struct s);

/* ---------------------------- LOG_EKF_Rotation ---------------------------- */

#define LOG_EKF_ROTATION_ID 0x78E
#define LOG_EKF_ROTATION_DLC 8          // Number of Bytes
#define LOG_EKF_ROTATION_CYCLE_TIME 100 // Milliseconds

union LOG_EKF_Rotation_Union
{

  uint64_t data;

  struct
  {

    int64_t heading_psi : 16;
    int64_t yaw_rate_np : 16;
    uint64_t reserved_1 : 32;
  };
};

struct LOG_EKF_Rotation_Struct
{
  float heading_psi;
  float yaw_rate_np;
};

extern SOFT_INLINE void
LOG_EKF_Rotation_UnionToStruct(struct LOG_EKF_Rotation_Struct *s,
                               union LOG_EKF_Rotation_Union u);

extern SOFT_INLINE void
LOG_EKF_Rotation_StructToUnion(union LOG_EKF_Rotation_Union *u,
                               struct LOG_EKF_Rotation_Struct s);

/* ------------------------------- CANO_TLSS ------------------------------- */

#define CANO_TLSS_ID 0x7E4
#define CANO_TLSS_DLC 8          // Number of Bytes
#define CANO_TLSS_CYCLE_TIME 100 // Milliseconds

union CANO_TLSS_Union
{

  uint64_t data;

  struct
  {

    uint64_t reserved_1 : 64;
  };
};

struct CANO_TLSS_Struct
{
};

extern SOFT_INLINE void CANO_TLSS_UnionToStruct(struct CANO_TLSS_Struct *s,
                                                union CANO_TLSS_Union u);

extern SOFT_INLINE void CANO_TLSS_StructToUnion(union CANO_TLSS_Union *u,
                                                struct CANO_TLSS_Struct s);

/* ------------------------------- CANO_RLSS ------------------------------- */

#define CANO_RLSS_ID 0x7E5
#define CANO_RLSS_DLC 8          // Number of Bytes
#define CANO_RLSS_CYCLE_TIME 100 // Milliseconds

union CANO_RLSS_Union
{

  uint64_t data;

  struct
  {

    uint64_t reserved_1 : 64;
  };
};

struct CANO_RLSS_Struct
{
};

extern SOFT_INLINE void CANO_RLSS_UnionToStruct(struct CANO_RLSS_Struct *s,
                                                union CANO_RLSS_Union u);

extern SOFT_INLINE void CANO_RLSS_StructToUnion(union CANO_RLSS_Union *u,
                                                struct CANO_RLSS_Struct s);

#endif // SYSTEM_DBC
