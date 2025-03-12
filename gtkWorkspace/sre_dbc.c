/***
 * Header File from DBC
 * Auto-generated using Python
 * 21.02.2025, 11:29:17 UTC
 ***/

// #include "common/include/driverlib.h"
// #include "headers/include/f280013x_device.h"

#include "headers/sre_dbc.h" //relative path to really make sure

// Ignore unused variable warnings for these as they are only used on a need to use basis
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

/* ------------------------------ LOG_aero_SPR ------------------------------ */

inline void LOG_aero_SPR_UnionToStruct(
	struct LOG_aero_SPR_Struct *s,
	union LOG_aero_SPR_Union u)
{
	s->temp1 = (float)(u.temp1 / 0.05f);
	s->temp2 = (float)(u.temp2 / 0.05f);
	s->temp3 = (float)(u.temp3 / 0.05f);
	s->hum1 = (float)(u.hum1 / 0.1f);
	s->hum2 = (float)(u.hum2 / 0.1f);
	s->hum3 = (float)(u.hum3 / 0.1f);
}

inline void LOG_aero_SPR_StructToUnion(
	union LOG_aero_SPR_Union *u,
	struct LOG_aero_SPR_Struct s)
{
	u->temp1 = (uint64_t)(s.temp1 / 0.05f);
	u->temp2 = (uint64_t)(s.temp2 / 0.05f);
	u->temp3 = (uint64_t)(s.temp3 / 0.05f);
	u->hum1 = (uint64_t)(s.hum1 / 0.1f);
	u->hum2 = (uint64_t)(s.hum2 / 0.1f);
	u->hum3 = (uint64_t)(s.hum3 / 0.1f);
}

/* ------------------------------ LOG_aero_SPL ------------------------------ */

inline void LOG_aero_SPL_UnionToStruct(
	struct LOG_aero_SPL_Struct *s,
	union LOG_aero_SPL_Union u)
{
	s->temp1 = (float)(u.temp1 / 0.05f);
	s->temp2 = (float)(u.temp2 / 0.05f);
	s->temp3 = (float)(u.temp3 / 0.05f);
	s->hum1 = (float)(u.hum1 / 0.1f);
	s->hum2 = (float)(u.hum2 / 0.1f);
	s->hum3 = (float)(u.hum3 / 0.1f);
}

inline void LOG_aero_SPL_StructToUnion(
	union LOG_aero_SPL_Union *u,
	struct LOG_aero_SPL_Struct s)
{
	u->temp1 = (uint64_t)(s.temp1 / 0.05f);
	u->temp2 = (uint64_t)(s.temp2 / 0.05f);
	u->temp3 = (uint64_t)(s.temp3 / 0.05f);
	u->hum1 = (uint64_t)(s.hum1 / 0.1f);
	u->hum2 = (uint64_t)(s.hum2 / 0.1f);
	u->hum3 = (uint64_t)(s.hum3 / 0.1f);
}

/* ------------------------------ LOG_aero_RW ------------------------------ */

inline void LOG_aero_RW_UnionToStruct(
	struct LOG_aero_RW_Struct *s,
	union LOG_aero_RW_Union u)
{
	s->temp1 = (float)(u.temp1 / 0.05f);
	s->temp2 = (float)(u.temp2 / 0.05f);
	s->hum1 = (float)(u.hum1 / 0.1f);
	s->hum2 = (float)(u.hum2 / 0.1f);
}

inline void LOG_aero_RW_StructToUnion(
	union LOG_aero_RW_Union *u,
	struct LOG_aero_RW_Struct s)
{
	u->temp1 = (uint64_t)(s.temp1 / 0.05f);
	u->temp2 = (uint64_t)(s.temp2 / 0.05f);
	u->hum1 = (uint64_t)(s.hum1 / 0.1f);
	u->hum2 = (uint64_t)(s.hum2 / 0.1f);
}

/* ------------------------------ LOG_aero_FW ------------------------------ */

inline void LOG_aero_FW_UnionToStruct(
	struct LOG_aero_FW_Struct *s,
	union LOG_aero_FW_Union u)
{
	s->temp1 = (float)(u.temp1 / 0.05f);
	s->temp2 = (float)(u.temp2 / 0.05f);
	s->hum1 = (float)(u.hum1 / 0.1f);
	s->hum2 = (float)(u.hum2 / 0.1f);
}

inline void LOG_aero_FW_StructToUnion(
	union LOG_aero_FW_Union *u,
	struct LOG_aero_FW_Struct s)
{
	u->temp1 = (uint64_t)(s.temp1 / 0.05f);
	u->temp2 = (uint64_t)(s.temp2 / 0.05f);
	u->hum1 = (uint64_t)(s.hum1 / 0.1f);
	u->hum2 = (uint64_t)(s.hum2 / 0.1f);
}

/* ------------------------------ CAL_EPOS_HC ------------------------------ */

inline void CAL_EPOS_HC_UnionToStruct(
	struct CAL_EPOS_HC_Struct *s,
	union CAL_EPOS_HC_Union u)
{
	s->voltage = (uint16_t)u.voltage;
}

inline void CAL_EPOS_HC_StructToUnion(
	union CAL_EPOS_HC_Union *u,
	struct CAL_EPOS_HC_Struct s)
{
	u->voltage = (uint64_t)s.voltage;
}

/* -------------------------------- CAL_SDC -------------------------------- */

inline void CAL_SDC_UnionToStruct(
	struct CAL_SDC_Struct *s,
	union CAL_SDC_Union u)
{
	s->voltage = (uint16_t)u.voltage;
}

inline void CAL_SDC_StructToUnion(
	union CAL_SDC_Union *u,
	struct CAL_SDC_Struct s)
{
	u->voltage = (uint64_t)s.voltage;
}

/* ------------------------------ CAL_WT_Right ------------------------------ */

inline void CAL_WT_Right_UnionToStruct(
	struct CAL_WT_Right_Struct *s,
	union CAL_WT_Right_Union u)
{
	s->vin_1 = (uint16_t)u.vin_1;
	s->vin_2 = (uint16_t)u.vin_2;
	s->vin_3 = (uint16_t)u.vin_3;
	s->vin_4 = (uint16_t)u.vin_4;
}

inline void CAL_WT_Right_StructToUnion(
	union CAL_WT_Right_Union *u,
	struct CAL_WT_Right_Struct s)
{
	u->vin_1 = (uint64_t)s.vin_1;
	u->vin_2 = (uint64_t)s.vin_2;
	u->vin_3 = (uint64_t)s.vin_3;
	u->vin_4 = (uint64_t)s.vin_4;
}

/* ------------------------------ CAL_WT_Left ------------------------------ */

inline void CAL_WT_Left_UnionToStruct(
	struct CAL_WT_Left_Struct *s,
	union CAL_WT_Left_Union u)
{
	s->vin_1 = (uint16_t)u.vin_1;
	s->vin_2 = (uint16_t)u.vin_2;
	s->vin_3 = (uint16_t)u.vin_3;
	s->vin_4 = (uint16_t)u.vin_4;
}

inline void CAL_WT_Left_StructToUnion(
	union CAL_WT_Left_Union *u,
	struct CAL_WT_Left_Struct s)
{
	u->vin_1 = (uint64_t)s.vin_1;
	u->vin_2 = (uint64_t)s.vin_2;
	u->vin_3 = (uint64_t)s.vin_3;
	u->vin_4 = (uint64_t)s.vin_4;
}

/* ------------------------------- CAL_LV_LEM ------------------------------- */

inline void CAL_LV_LEM_UnionToStruct(
	struct CAL_LV_LEM_Struct *s,
	union CAL_LV_LEM_Union u)
{
	s->voltage = (uint16_t)u.voltage;
}

inline void CAL_LV_LEM_StructToUnion(
	union CAL_LV_LEM_Union *u,
	struct CAL_LV_LEM_Struct s)
{
	u->voltage = (uint64_t)s.voltage;
}

/* -------------------------------- LOG_SDC -------------------------------- */

inline void LOG_SDC_UnionToStruct(
	struct LOG_SDC_Struct *s,
	union LOG_SDC_Union u)
{
	s->sdc_res = (bool)u.sdc_res;
	s->sdc_fr = (bool)u.sdc_fr;
	s->sdc_asb = (bool)u.sdc_asb;
	s->sdc_bspd = (bool)u.sdc_bspd;
	s->sdc_bots = (bool)u.sdc_bots;
	s->sdc_fl = (bool)u.sdc_fl;
	s->sdc_dash = (bool)u.sdc_dash;
	s->sdc_inertia = (bool)u.sdc_inertia;
	s->sdc_rl = (bool)u.sdc_rl;
	s->sdc_tsal = (bool)u.sdc_tsal;
	s->sdc_rr = (bool)u.sdc_rr;
	s->sdc_hvd = (bool)u.sdc_hvd;
	s->sdc_ts_connector = (bool)u.sdc_ts_connector;
	s->sdc_tsms = (bool)u.sdc_tsms;
}

inline void LOG_SDC_StructToUnion(
	union LOG_SDC_Union *u,
	struct LOG_SDC_Struct s)
{
	u->sdc_res = (uint64_t)s.sdc_res;
	u->sdc_fr = (uint64_t)s.sdc_fr;
	u->sdc_asb = (uint64_t)s.sdc_asb;
	u->sdc_bspd = (uint64_t)s.sdc_bspd;
	u->sdc_bots = (uint64_t)s.sdc_bots;
	u->sdc_fl = (uint64_t)s.sdc_fl;
	u->sdc_dash = (uint64_t)s.sdc_dash;
	u->sdc_inertia = (uint64_t)s.sdc_inertia;
	u->sdc_rl = (uint64_t)s.sdc_rl;
	u->sdc_tsal = (uint64_t)s.sdc_tsal;
	u->sdc_rr = (uint64_t)s.sdc_rr;
	u->sdc_hvd = (uint64_t)s.sdc_hvd;
	u->sdc_ts_connector = (uint64_t)s.sdc_ts_connector;
	u->sdc_tsms = (uint64_t)s.sdc_tsms;
}

/* --------------------------- LOG_FUSE_Currents --------------------------- */

inline void LOG_FUSE_Currents_UnionToStruct(
	struct LOG_FUSE_Currents_Struct *s,
	union LOG_FUSE_Currents_Union u)
{
	s->epos_current = (uint16_t)u.epos_current;
	s->sdc_current = (uint16_t)u.sdc_current;
}

inline void LOG_FUSE_Currents_StructToUnion(
	union LOG_FUSE_Currents_Union *u,
	struct LOG_FUSE_Currents_Struct s)
{
	u->epos_current = (uint64_t)s.epos_current;
	u->sdc_current = (uint64_t)s.sdc_current;
}

/* ---------------------------- PARC_FUSE_States ---------------------------- */

inline void PARC_FUSE_States_UnionToStruct(
	struct PARC_FUSE_States_Struct *s,
	union PARC_FUSE_States_Union u)
{
	s->fb_acu = (bool)u.fb_acu;
	s->fb_asb = (bool)u.fb_asb;
	s->fb_dash = (bool)u.fb_dash;
	s->fb_epos = (bool)u.fb_epos;
	s->fb_fan_l = (bool)u.fb_fan_l;
	s->fb_fan_r = (bool)u.fb_fan_r;
	s->fb_gps = (bool)u.fb_gps;
	s->fb_pef = (bool)u.fb_pef;
	s->fb_per = (bool)u.fb_per;
	s->fb_pumps = (bool)u.fb_pumps;
	s->fb_sensors = (bool)u.fb_sensors;
	s->fb_vcu = (bool)u.fb_vcu;
}

inline void PARC_FUSE_States_StructToUnion(
	union PARC_FUSE_States_Union *u,
	struct PARC_FUSE_States_Struct s)
{
	u->fb_acu = (uint64_t)s.fb_acu;
	u->fb_asb = (uint64_t)s.fb_asb;
	u->fb_dash = (uint64_t)s.fb_dash;
	u->fb_epos = (uint64_t)s.fb_epos;
	u->fb_fan_l = (uint64_t)s.fb_fan_l;
	u->fb_fan_r = (uint64_t)s.fb_fan_r;
	u->fb_gps = (uint64_t)s.fb_gps;
	u->fb_pef = (uint64_t)s.fb_pef;
	u->fb_per = (uint64_t)s.fb_per;
	u->fb_pumps = (uint64_t)s.fb_pumps;
	u->fb_sensors = (uint64_t)s.fb_sensors;
	u->fb_vcu = (uint64_t)s.fb_vcu;
}

/* ---------------------------- PARS_FUSE_States ---------------------------- */

inline void PARS_FUSE_States_UnionToStruct(
	struct PARS_FUSE_States_Struct *s,
	union PARS_FUSE_States_Union u)
{
	s->fb_acu = (bool)u.fb_acu;
	s->fb_asb = (bool)u.fb_asb;
	s->fb_dash = (bool)u.fb_dash;
	s->fb_epos = (bool)u.fb_epos;
	s->fb_fan_l = (bool)u.fb_fan_l;
	s->fb_fan_r = (bool)u.fb_fan_r;
	s->fb_gps = (bool)u.fb_gps;
	s->fb_pef = (bool)u.fb_pef;
	s->fb_per = (bool)u.fb_per;
	s->fb_pumps = (bool)u.fb_pumps;
	s->fb_sensors = (bool)u.fb_sensors;
	s->fb_vcu = (bool)u.fb_vcu;
}

inline void PARS_FUSE_States_StructToUnion(
	union PARS_FUSE_States_Union *u,
	struct PARS_FUSE_States_Struct s)
{
	u->fb_acu = (uint64_t)s.fb_acu;
	u->fb_asb = (uint64_t)s.fb_asb;
	u->fb_dash = (uint64_t)s.fb_dash;
	u->fb_epos = (uint64_t)s.fb_epos;
	u->fb_fan_l = (uint64_t)s.fb_fan_l;
	u->fb_fan_r = (uint64_t)s.fb_fan_r;
	u->fb_gps = (uint64_t)s.fb_gps;
	u->fb_pef = (uint64_t)s.fb_pef;
	u->fb_per = (uint64_t)s.fb_per;
	u->fb_pumps = (uint64_t)s.fb_pumps;
	u->fb_sensors = (uint64_t)s.fb_sensors;
	u->fb_vcu = (uint64_t)s.fb_vcu;
}

/* -------------------------- SAF_Fuseboard_Status -------------------------- */

inline void
SAF_Fuseboard_Status_UnionToStruct(
	struct SAF_Fuseboard_Status_Struct *s,
	union SAF_Fuseboard_Status_Union u)
{
	s->scs_error = (bool)u.scs_error;
	s->message_error = (bool)u.message_error;
	s->output_no_change_error = (bool)u.output_no_change_error;
	s->gen_scs = (uint8_t)u.gen_scs;
}

inline void
SAF_Fuseboard_Status_StructToUnion(
	union SAF_Fuseboard_Status_Union *u,
	struct SAF_Fuseboard_Status_Struct s)
{
	u->scs_error = (uint64_t)s.scs_error;
	u->message_error = (uint64_t)s.message_error;
	u->output_no_change_error = (uint64_t)s.output_no_change_error;
	u->gen_scs = (uint64_t)s.gen_scs;
}

/* --------------------------- SAF_StWheel_Status --------------------------- */

inline void
SAF_StWheel_Status_UnionToStruct(
	struct SAF_StWheel_Status_Struct *s,
	union SAF_StWheel_Status_Union u)
{
	s->scs_error = (bool)u.scs_error;
	s->message_error = (bool)u.message_error;
	s->output_no_change_error = (bool)u.output_no_change_error;
	s->gen_scs = (uint8_t)u.gen_scs;
}

inline void
SAF_StWheel_Status_StructToUnion(
	union SAF_StWheel_Status_Union *u,
	struct SAF_StWheel_Status_Struct s)
{
	u->scs_error = (uint64_t)s.scs_error;
	u->message_error = (uint64_t)s.message_error;
	u->output_no_change_error = (uint64_t)s.output_no_change_error;
	u->gen_scs = (uint64_t)s.gen_scs;
}

/* ------------------------- SAF_ZoCo_Right_Status ------------------------- */

inline void
SAF_ZoCo_Right_Status_UnionToStruct(
	struct SAF_ZoCo_Right_Status_Struct *s,
	union SAF_ZoCo_Right_Status_Union u)
{
	s->scs_error = (bool)u.scs_error;
	s->gen_scs = (uint8_t)u.gen_scs;
}

inline void
SAF_ZoCo_Right_Status_StructToUnion(
	union SAF_ZoCo_Right_Status_Union *u,
	struct SAF_ZoCo_Right_Status_Struct s)
{
	u->scs_error = (uint64_t)s.scs_error;
	u->gen_scs = (uint64_t)s.gen_scs;
}

/* -------------------------- SAF_ZoCo_Left_Status -------------------------- */

inline void
SAF_ZoCo_Left_Status_UnionToStruct(
	struct SAF_ZoCo_Left_Status_Struct *s,
	union SAF_ZoCo_Left_Status_Union u)
{
	s->scs_error = (bool)u.scs_error;
	s->gen_scs = (uint8_t)u.gen_scs;
}

inline void
SAF_ZoCo_Left_Status_StructToUnion(
	union SAF_ZoCo_Left_Status_Union *u,
	struct SAF_ZoCo_Left_Status_Struct s)
{
	u->scs_error = (uint64_t)s.scs_error;
	u->gen_scs = (uint64_t)s.gen_scs;
}

/* ------------------------------ LOG_Odometry ------------------------------ */

inline void LOG_Odometry_UnionToStruct(
	struct LOG_Odometry_Struct *s,
	union LOG_Odometry_Union u)
{
	s->rear_average_tire_speed = (float)(u.rear_average_tire_speed / 0.001f);
}

inline void LOG_Odometry_StructToUnion(
	union LOG_Odometry_Union *u,
	struct LOG_Odometry_Struct s)
{
	u->rear_average_tire_speed = (uint64_t)(s.rear_average_tire_speed / 0.001f);
}

/* ------------------------ LOG_ThrottleBrakeRequest ------------------------ */

inline void LOG_ThrottleBrakeRequest_UnionToStruct(
	struct LOG_ThrottleBrakeRequest_Struct *s,
	union LOG_ThrottleBrakeRequest_Union u)
{
	s->requested_throttle = (uint8_t)u.requested_throttle;
	s->requested_brake = (uint8_t)u.requested_brake;
}

inline void LOG_ThrottleBrakeRequest_StructToUnion(
	union LOG_ThrottleBrakeRequest_Union *u,
	struct LOG_ThrottleBrakeRequest_Struct s)
{
	u->requested_throttle = (uint64_t)s.requested_throttle;
	u->requested_brake = (uint64_t)s.requested_brake;
}

/* ---------------------------- LOG_SBG_ODO_Info ---------------------------- */

inline void LOG_SBG_ODO_Info_UnionToStruct(
	struct LOG_SBG_ODO_Info_Struct *s,
	union LOG_SBG_ODO_Info_Union u)
{
	s->time_stamp = (uint32_t)u.time_stamp;
	s->odo_real_meas = (bool)u.odo_real_meas;
	s->odo_time_sync = (bool)u.odo_time_sync;
}

inline void LOG_SBG_ODO_Info_StructToUnion(
	union LOG_SBG_ODO_Info_Union *u,
	struct LOG_SBG_ODO_Info_Struct s)
{
	u->time_stamp = (uint64_t)s.time_stamp;
	u->odo_real_meas = (uint64_t)s.odo_real_meas;
	u->odo_time_sync = (uint64_t)s.odo_time_sync;
}

/* -------------------------- HSC_SBG_Position_Acc -------------------------- */

inline void
HSC_SBG_Position_Acc_UnionToStruct(
	struct HSC_SBG_Position_Acc_Struct *s,
	union HSC_SBG_Position_Acc_Union u)
{
	s->latitude_acc = (float)(u.latitude_acc / 0.01f);
	s->longitude_acc = (float)(u.longitude_acc / 0.01f);
	s->altitude_acc = (float)(u.altitude_acc / 0.01f);
}

inline void
HSC_SBG_Position_Acc_StructToUnion(
	union HSC_SBG_Position_Acc_Union *u,
	struct HSC_SBG_Position_Acc_Struct s)
{
	u->latitude_acc = (uint64_t)(s.latitude_acc / 0.01f);
	u->longitude_acc = (uint64_t)(s.longitude_acc / 0.01f);
	u->altitude_acc = (uint64_t)(s.altitude_acc / 0.01f);
}

/* --------------------------- HSC_SBG_Euler_Acc --------------------------- */

inline void HSC_SBG_Euler_Acc_UnionToStruct(
	struct HSC_SBG_Euler_Acc_Struct *s,
	union HSC_SBG_Euler_Acc_Union u)
{
	s->roll_acc = (float)(u.roll_acc / 0.0001f);
	s->pitch_acc = (float)(u.pitch_acc / 0.01f);
	s->yaw_acc = (float)(u.yaw_acc / 0.0001f);
}

inline void HSC_SBG_Euler_Acc_StructToUnion(
	union HSC_SBG_Euler_Acc_Union *u,
	struct HSC_SBG_Euler_Acc_Struct s)
{
	u->roll_acc = (uint64_t)(s.roll_acc / 0.0001f);
	u->pitch_acc = (uint64_t)(s.pitch_acc / 0.01f);
	u->yaw_acc = (uint64_t)(s.yaw_acc / 0.0001f);
}

/* ----------------------------- HSC_SBG_Euler ----------------------------- */

inline void HSC_SBG_Euler_UnionToStruct(
	struct HSC_SBG_Euler_Struct *s,
	union HSC_SBG_Euler_Union u)
{
	s->roll = (float)(u.roll / 0.0001f);
	s->pitch = (float)(u.pitch / 0.0001f);
	s->yaw = (float)(u.yaw / 0.0001f);
}

inline void HSC_SBG_Euler_StructToUnion(
	union HSC_SBG_Euler_Union *u,
	struct HSC_SBG_Euler_Struct s)
{
	u->roll = (uint64_t)(s.roll / 0.0001f);
	u->pitch = (uint64_t)(s.pitch / 0.0001f);
	u->yaw = (uint64_t)(s.yaw / 0.0001f);
}

/* ---------------------------- LOG_SBG_EKF_Info ---------------------------- */

inline void LOG_SBG_EKF_Info_UnionToStruct(
	struct LOG_SBG_EKF_Info_Struct *s,
	union LOG_SBG_EKF_Info_Union u)
{
	s->time_stamp = (uint32_t)u.time_stamp;
}

inline void LOG_SBG_EKF_Info_StructToUnion(
	union LOG_SBG_EKF_Info_Union *u,
	struct LOG_SBG_EKF_Info_Struct s)
{
	u->time_stamp = (uint64_t)s.time_stamp;
}

/* ---------------------------- LOG_SBG_IMU_Info ---------------------------- */

inline void LOG_SBG_IMU_Info_UnionToStruct(
	struct LOG_SBG_IMU_Info_Struct *s,
	union LOG_SBG_IMU_Info_Union u)
{
	s->time_stamp = (uint32_t)u.time_stamp;
	s->temperature = (float)(u.temperature / 0.01f);
}

inline void LOG_SBG_IMU_Info_StructToUnion(
	union LOG_SBG_IMU_Info_Union *u,
	struct LOG_SBG_IMU_Info_Struct s)
{
	u->time_stamp = (uint64_t)s.time_stamp;
	u->temperature = (uint64_t)(s.temperature / 0.01f);
}

/* ----------------------------- LOG_TireForces ----------------------------- */

inline void LOG_TireForces_UnionToStruct(
	struct LOG_TireForces_Struct *s,
	union LOG_TireForces_Union u)
{
	s->tire_force_fl = (float)(u.tire_force_fl / 0.02f);
	s->tire_force_fr = (float)(u.tire_force_fr / 0.02f);
	s->tire_force_rl = (float)(u.tire_force_rl / 0.02f);
	s->tire_force_rr = (float)(u.tire_force_rr / 0.02f);
}

inline void LOG_TireForces_StructToUnion(
	union LOG_TireForces_Union *u,
	struct LOG_TireForces_Struct s)
{
	u->tire_force_fl = (uint64_t)(s.tire_force_fl / 0.02f);
	u->tire_force_fr = (uint64_t)(s.tire_force_fr / 0.02f);
	u->tire_force_rl = (uint64_t)(s.tire_force_rl / 0.02f);
	u->tire_force_rr = (uint64_t)(s.tire_force_rr / 0.02f);
}

/* ----------------------------- LOG_SlipRatio ----------------------------- */

inline void LOG_SlipRatio_UnionToStruct(
	struct LOG_SlipRatio_Struct *s,
	union LOG_SlipRatio_Union u)
{
	s->slip_ratio_fl = (float)(u.slip_ratio_fl / 0.01f);
	s->slip_ratio_fr = (float)(u.slip_ratio_fr / 0.01f);
	s->slip_ratio_rl = (float)(u.slip_ratio_rl / 0.01f);
	s->slip_ratio_rr = (float)(u.slip_ratio_rr / 0.01f);
}

inline void LOG_SlipRatio_StructToUnion(
	union LOG_SlipRatio_Union *u,
	struct LOG_SlipRatio_Struct s)
{
	u->slip_ratio_fl = (uint64_t)(s.slip_ratio_fl / 0.01f);
	u->slip_ratio_fr = (uint64_t)(s.slip_ratio_fr / 0.01f);
	u->slip_ratio_rl = (uint64_t)(s.slip_ratio_rl / 0.01f);
	u->slip_ratio_rr = (uint64_t)(s.slip_ratio_rr / 0.01f);
}

/* ----------------------------- LOG_TV_request ----------------------------- */

inline void LOG_TV_request_UnionToStruct(
	struct LOG_TV_request_Struct *s,
	union LOG_TV_request_Union u)
{
	s->tv_fl = (float)(u.tv_fl / 0.2f);
	s->tv_fr = (float)(u.tv_fr / 0.2f);
	s->tv_rr = (float)(u.tv_rr / 0.2f);
	s->tv_rl = (float)(u.tv_rl / 0.2f);
}

inline void LOG_TV_request_StructToUnion(
	union LOG_TV_request_Union *u,
	struct LOG_TV_request_Struct s)
{
	u->tv_fl = (uint64_t)(s.tv_fl / 0.2f);
	u->tv_fr = (uint64_t)(s.tv_fr / 0.2f);
	u->tv_rr = (uint64_t)(s.tv_rr / 0.2f);
	u->tv_rl = (uint64_t)(s.tv_rl / 0.2f);
}

/* ----------------------------- LOG_SlipAngle ----------------------------- */

inline void LOG_SlipAngle_UnionToStruct(
	struct LOG_SlipAngle_Struct *s,
	union LOG_SlipAngle_Union u)
{
	s->slip_angle_fl = (float)(u.slip_angle_fl / 0.01f);
	s->slip_angle_fr = (float)(u.slip_angle_fr / 0.01f);
	s->slip_angle_rl = (float)(u.slip_angle_rl / 0.01f);
	s->slip_angle_rr = (float)(u.slip_angle_rr / 0.01f);
}

inline void LOG_SlipAngle_StructToUnion(
	union LOG_SlipAngle_Union *u,
	struct LOG_SlipAngle_Struct s)
{
	u->slip_angle_fl = (uint64_t)(s.slip_angle_fl / 0.01f);
	u->slip_angle_fr = (uint64_t)(s.slip_angle_fr / 0.01f);
	u->slip_angle_rl = (uint64_t)(s.slip_angle_rl / 0.01f);
	u->slip_angle_rr = (uint64_t)(s.slip_angle_rr / 0.01f);
}

/* -------------------------- HSC_SBG_True_Heading -------------------------- */

inline void
HSC_SBG_True_Heading_UnionToStruct(
	struct HSC_SBG_True_Heading_Struct *s,
	union HSC_SBG_True_Heading_Union u)
{
	s->true_heading = (float)(u.true_heading / 0.01f);
	s->true_heading_acc = (float)(u.true_heading_acc / 0.01f);
	s->pitch = (float)(u.pitch / 0.01f);
}

inline void
HSC_SBG_True_Heading_StructToUnion(
	union HSC_SBG_True_Heading_Union *u,
	struct HSC_SBG_True_Heading_Struct s)
{
	u->true_heading = (uint64_t)(s.true_heading / 0.01f);
	u->true_heading_acc = (uint64_t)(s.true_heading_acc / 0.01f);
	u->pitch = (uint64_t)(s.pitch / 0.01f);
}

/* ---------------------------- HSC_SBG_Altitude ---------------------------- */

inline void HSC_SBG_Altitude_UnionToStruct(
	struct HSC_SBG_Altitude_Struct *s,
	union HSC_SBG_Altitude_Union u)
{
	s->altitude = (float)(u.altitude / 0.001f);
	s->undulation = (float)(u.undulation / 0.005f);
}

inline void HSC_SBG_Altitude_StructToUnion(
	union HSC_SBG_Altitude_Union *u,
	struct HSC_SBG_Altitude_Struct s)
{
	u->altitude = (uint64_t)(s.altitude / 0.001f);
	u->undulation = (uint64_t)(s.undulation / 0.005f);
}

/* ---------------------------- HSC_SBG_Position ---------------------------- */

inline void HSC_SBG_Position_UnionToStruct(
	struct HSC_SBG_Position_Struct *s,
	union HSC_SBG_Position_Union u)
{
	s->latitude = (float)(u.latitude / 1e-07f);
	s->longitude = (float)(u.longitude / 1e-07f);
}

inline void HSC_SBG_Position_StructToUnion(
	union HSC_SBG_Position_Union *u,
	struct HSC_SBG_Position_Struct s)
{
	u->latitude = (uint64_t)(s.latitude / 1e-07f);
	u->longitude = (uint64_t)(s.longitude / 1e-07f);
}

/* -------------------------- LOG_SBG_Heading_Info -------------------------- */

inline void
LOG_SBG_Heading_Info_UnionToStruct(
	struct LOG_SBG_Heading_Info_Struct *s,
	union LOG_SBG_Heading_Info_Union u)
{
	s->time_stamp = (uint32_t)u.time_stamp;
}

inline void
LOG_SBG_Heading_Info_StructToUnion(
	union LOG_SBG_Heading_Info_Union *u,
	struct LOG_SBG_Heading_Info_Struct s)
{
	u->time_stamp = (uint64_t)s.time_stamp;
}

/* ---------------------------- LOG_SBG_POS_Info ---------------------------- */

inline void LOG_SBG_POS_Info_UnionToStruct(
	struct LOG_SBG_POS_Info_Struct *s,
	union LOG_SBG_POS_Info_Union u)
{
	s->time_stamp = (uint32_t)u.time_stamp;
}

inline void LOG_SBG_POS_Info_StructToUnion(
	union LOG_SBG_POS_Info_Union *u,
	struct LOG_SBG_POS_Info_Struct s)
{
	u->time_stamp = (uint64_t)s.time_stamp;
}

/* ------------------------- LOG_SBG_GPS1_Vel_Info ------------------------- */

inline void
LOG_SBG_GPS1_Vel_Info_UnionToStruct(
	struct LOG_SBG_GPS1_Vel_Info_Struct *s,
	union LOG_SBG_GPS1_Vel_Info_Union u)
{
	s->time_stamp = (uint32_t)u.time_stamp;
}

inline void
LOG_SBG_GPS1_Vel_Info_StructToUnion(
	union LOG_SBG_GPS1_Vel_Info_Union *u,
	struct LOG_SBG_GPS1_Vel_Info_Struct s)
{
	u->time_stamp = (uint64_t)s.time_stamp;
}

/* --------------------------- LOG_SBG_Status_03 --------------------------- */

inline void LOG_SBG_Status_03_UnionToStruct(
	struct LOG_SBG_Status_03_Struct *s,
	union LOG_SBG_Status_03_Union u) {}

inline void LOG_SBG_Status_03_StructToUnion(
	union LOG_SBG_Status_03_Union *u,
	struct LOG_SBG_Status_03_Struct s)
{
}

/* --------------------------- LOG_SBG_Status_02 --------------------------- */

inline void LOG_SBG_Status_02_UnionToStruct(
	struct LOG_SBG_Status_02_Struct *s,
	union LOG_SBG_Status_02_Union u)
{
	s->sbg_porta_valid = (bool)u.sbg_porta_valid;
	s->sbg_portb_valid = (bool)u.sbg_portb_valid;
	s->sbg_porta_rx_ok = (bool)u.sbg_porta_rx_ok;
	s->sbg_porta_tx_ok = (bool)u.sbg_porta_tx_ok;
	s->sbg_portb_rx_ok = (bool)u.sbg_portb_rx_ok;
	s->sbg_can_valid = (bool)u.sbg_can_valid;
	s->sbg_can_rx_ok = (bool)u.sbg_can_rx_ok;
	s->sbg_can_tx_ok = (bool)u.sbg_can_tx_ok;
}

inline void LOG_SBG_Status_02_StructToUnion(
	union LOG_SBG_Status_02_Union *u,
	struct LOG_SBG_Status_02_Struct s)
{
	u->sbg_porta_valid = (uint64_t)s.sbg_porta_valid;
	u->sbg_portb_valid = (uint64_t)s.sbg_portb_valid;
	u->sbg_porta_rx_ok = (uint64_t)s.sbg_porta_rx_ok;
	u->sbg_porta_tx_ok = (uint64_t)s.sbg_porta_tx_ok;
	u->sbg_portb_rx_ok = (uint64_t)s.sbg_portb_rx_ok;
	u->sbg_can_valid = (uint64_t)s.sbg_can_valid;
	u->sbg_can_rx_ok = (uint64_t)s.sbg_can_rx_ok;
	u->sbg_can_tx_ok = (uint64_t)s.sbg_can_tx_ok;
}

/* --------------------------- LOG_SBG_Status_01 --------------------------- */

inline void LOG_SBG_Status_01_UnionToStruct(
	struct LOG_SBG_Status_01_Struct *s,
	union LOG_SBG_Status_01_Union u)
{
	s->sbg_time_stamp = (uint32_t)u.sbg_time_stamp;
	s->sbg_main_power_ok = (bool)u.sbg_main_power_ok;
	s->sbg_imu_power_ok = (bool)u.sbg_imu_power_ok;
	s->sbg_gps_power_ok = (bool)u.sbg_gps_power_ok;
	s->sbg_settings_ok = (bool)u.sbg_settings_ok;
	s->sbg_temp_ok = (bool)u.sbg_temp_ok;
	s->sbg_datalogger_ok = (bool)u.sbg_datalogger_ok;
	s->sbg_cpu_ok = (bool)u.sbg_cpu_ok;
}

inline void LOG_SBG_Status_01_StructToUnion(
	union LOG_SBG_Status_01_Union *u,
	struct LOG_SBG_Status_01_Struct s)
{
	u->sbg_time_stamp = (uint64_t)s.sbg_time_stamp;
	u->sbg_main_power_ok = (uint64_t)s.sbg_main_power_ok;
	u->sbg_imu_power_ok = (uint64_t)s.sbg_imu_power_ok;
	u->sbg_gps_power_ok = (uint64_t)s.sbg_gps_power_ok;
	u->sbg_settings_ok = (uint64_t)s.sbg_settings_ok;
	u->sbg_temp_ok = (uint64_t)s.sbg_temp_ok;
	u->sbg_datalogger_ok = (uint64_t)s.sbg_datalogger_ok;
	u->sbg_cpu_ok = (uint64_t)s.sbg_cpu_ok;
}

/* ------------------------ HSC_SBG_Track_Slip_Curve ------------------------ */

inline void HSC_SBG_Track_Slip_Curve_UnionToStruct(
	struct HSC_SBG_Track_Slip_Curve_Struct *s,
	union HSC_SBG_Track_Slip_Curve_Union u)
{
	s->angle_track = (float)(u.angle_track / 0.0001f);
	s->angle_slip = (float)(u.angle_slip / 0.0001f);
	s->curvature_radius = (float)(u.curvature_radius / 0.01f);
	s->track_valid = (bool)u.track_valid;
	s->slip_valid = (bool)u.slip_valid;
	s->curvature_valid = (bool)u.curvature_valid;
}

inline void HSC_SBG_Track_Slip_Curve_StructToUnion(
	union HSC_SBG_Track_Slip_Curve_Union *u,
	struct HSC_SBG_Track_Slip_Curve_Struct s)
{
	u->angle_track = (uint64_t)(s.angle_track / 0.0001f);
	u->angle_slip = (uint64_t)(s.angle_slip / 0.0001f);
	u->curvature_radius = (uint64_t)(s.curvature_radius / 0.01f);
	u->track_valid = (uint64_t)s.track_valid;
	u->slip_valid = (uint64_t)s.slip_valid;
	u->curvature_valid = (uint64_t)s.curvature_valid;
}

/* -------------------------- HSC_SBG_EKF_Vel_Body -------------------------- */

inline void
HSC_SBG_EKF_Vel_Body_UnionToStruct(
	struct HSC_SBG_EKF_Vel_Body_Struct *s,
	union HSC_SBG_EKF_Vel_Body_Union u)
{
	s->velocity_x = (float)(u.velocity_x / 0.01f);
	s->velocity_y = (float)(u.velocity_y / 0.01f);
	s->velocity_z = (float)(u.velocity_z / 0.01f);
}

inline void
HSC_SBG_EKF_Vel_Body_StructToUnion(
	union HSC_SBG_EKF_Vel_Body_Union *u,
	struct HSC_SBG_EKF_Vel_Body_Struct s)
{
	u->velocity_x = (uint64_t)(s.velocity_x / 0.01f);
	u->velocity_y = (uint64_t)(s.velocity_y / 0.01f);
	u->velocity_z = (uint64_t)(s.velocity_z / 0.01f);
}

/* ------------------------------ HSC_SBG_Gyro ------------------------------ */

inline void HSC_SBG_Gyro_UnionToStruct(
	struct HSC_SBG_Gyro_Struct *s,
	union HSC_SBG_Gyro_Union u)
{
	s->gyro_x = (float)(u.gyro_x / 0.001f);
	s->gyro_y = (float)(u.gyro_y / 0.001f);
	s->gyro_z = (float)(u.gyro_z / 0.001f);
}

inline void HSC_SBG_Gyro_StructToUnion(
	union HSC_SBG_Gyro_Union *u,
	struct HSC_SBG_Gyro_Struct s)
{
	u->gyro_x = (uint64_t)(s.gyro_x / 0.001f);
	u->gyro_y = (uint64_t)(s.gyro_y / 0.001f);
	u->gyro_z = (uint64_t)(s.gyro_z / 0.001f);
}

/* ----------------------------- HSC_SBG_Accel ----------------------------- */

inline void HSC_SBG_Accel_UnionToStruct(
	struct HSC_SBG_Accel_Struct *s,
	union HSC_SBG_Accel_Union u)
{
	s->accel_x = (float)(u.accel_x / 0.01f);
	s->accel_y = (float)(u.accel_y / 0.01f);
	s->accel_z = (float)(u.accel_z / 0.01f);
}

inline void HSC_SBG_Accel_StructToUnion(
	union HSC_SBG_Accel_Union *u,
	struct HSC_SBG_Accel_Struct s)
{
	u->accel_x = (uint64_t)(s.accel_x / 0.01f);
	u->accel_y = (uint64_t)(s.accel_y / 0.01f);
	u->accel_z = (uint64_t)(s.accel_z / 0.01f);
}

/* ---------------------------- GW_Battery_Cells ---------------------------- */

inline void GW_Battery_Cells_UnionToStruct(
	struct GW_Battery_Cells_Struct *s,
	union GW_Battery_Cells_Union u)
{
	s->temp_min = (uint8_t)u.temp_min;
	s->temp_avg = (uint8_t)u.temp_avg;
	s->temp_max = (uint8_t)u.temp_max;
	s->voltage_min = (float)(u.voltage_min / 0.001f);
	s->voltage_max = (float)(u.voltage_max / 0.001f);
}

inline void GW_Battery_Cells_StructToUnion(
	union GW_Battery_Cells_Union *u,
	struct GW_Battery_Cells_Struct s)
{
	u->temp_min = (uint64_t)s.temp_min;
	u->temp_avg = (uint64_t)s.temp_avg;
	u->temp_max = (uint64_t)s.temp_max;
	u->voltage_min = (uint64_t)(s.voltage_min / 0.001f);
	u->voltage_max = (uint64_t)(s.voltage_max / 0.001f);
}

/* --------------------------- GW_Battery_Status --------------------------- */

inline void GW_Battery_Status_UnionToStruct(
	struct GW_Battery_Status_Struct *s,
	union GW_Battery_Status_Union u)
{
	s->state = (GW_Battery_Status_State)u.state;
	s->soc_internal = (float)(u.soc_internal / 0.01f);
	s->power = (float)(u.power / 0.01f);
	s->current = (float)(u.current / 0.1f);
}

inline void GW_Battery_Status_StructToUnion(
	union GW_Battery_Status_Union *u,
	struct GW_Battery_Status_Struct s)
{
	u->state = (uint64_t)s.state;
	u->soc_internal = (uint64_t)(s.soc_internal / 0.01f);
	u->power = (uint64_t)(s.power / 0.01f);
	u->current = (uint64_t)(s.current / 0.1f);
}

/* ---------------------------- GW_PE_FrontLeft ---------------------------- */

inline void GW_PE_FrontLeft_UnionToStruct(
	struct GW_PE_FrontLeft_Struct *s,
	union GW_PE_FrontLeft_Union u)
{
	s->temp_motor = (float)(u.temp_motor / 0.1f);
	s->temp_inverter = (float)(u.temp_inverter / 0.1f);
	s->tempigbt = (float)(u.tempigbt / 0.1f);
	s->actual_velocity = (int16_t)u.actual_velocity;
}

inline void GW_PE_FrontLeft_StructToUnion(
	union GW_PE_FrontLeft_Union *u,
	struct GW_PE_FrontLeft_Struct s)
{
	u->temp_motor = (uint64_t)(s.temp_motor / 0.1f);
	u->temp_inverter = (uint64_t)(s.temp_inverter / 0.1f);
	u->tempigbt = (uint64_t)(s.tempigbt / 0.1f);
	u->actual_velocity = (uint64_t)s.actual_velocity;
}

/* ----------------------------- GW_PE_RearLeft ----------------------------- */

inline void GW_PE_RearLeft_UnionToStruct(
	struct GW_PE_RearLeft_Struct *s,
	union GW_PE_RearLeft_Union u)
{
	s->temp_motor = (float)(u.temp_motor / 0.1f);
	s->temp_inverter = (float)(u.temp_inverter / 0.1f);
	s->tempigbt = (float)(u.tempigbt / 0.1f);
	s->actual_velocity = (int16_t)u.actual_velocity;
}

inline void GW_PE_RearLeft_StructToUnion(
	union GW_PE_RearLeft_Union *u,
	struct GW_PE_RearLeft_Struct s)
{
	u->temp_motor = (uint64_t)(s.temp_motor / 0.1f);
	u->temp_inverter = (uint64_t)(s.temp_inverter / 0.1f);
	u->tempigbt = (uint64_t)(s.tempigbt / 0.1f);
	u->actual_velocity = (uint64_t)s.actual_velocity;
}

/* ---------------------------- GW_PE_RearRight ---------------------------- */

inline void GW_PE_RearRight_UnionToStruct(
	struct GW_PE_RearRight_Struct *s,
	union GW_PE_RearRight_Union u)
{
	s->temp_motor = (float)(u.temp_motor / 0.1f);
	s->temp_inverter = (float)(u.temp_inverter / 0.1f);
	s->tempigbt = (float)(u.tempigbt / 0.1f);
	s->actual_velocity = (int16_t)u.actual_velocity;
}

inline void GW_PE_RearRight_StructToUnion(
	union GW_PE_RearRight_Union *u,
	struct GW_PE_RearRight_Struct s)
{
	u->temp_motor = (uint64_t)(s.temp_motor / 0.1f);
	u->temp_inverter = (uint64_t)(s.temp_inverter / 0.1f);
	u->tempigbt = (uint64_t)(s.tempigbt / 0.1f);
	u->actual_velocity = (uint64_t)s.actual_velocity;
}

/* ---------------------------- GW_PE_FrontRight ---------------------------- */

inline void GW_PE_FrontRight_UnionToStruct(
	struct GW_PE_FrontRight_Struct *s,
	union GW_PE_FrontRight_Union u)
{
	s->temp_motor = (float)(u.temp_motor / 0.1f);
	s->temp_inverter = (float)(u.temp_inverter / 0.1f);
	s->tempigbt = (float)(u.tempigbt / 0.1f);
	s->actual_velocity = (int16_t)u.actual_velocity;
}

inline void GW_PE_FrontRight_StructToUnion(
	union GW_PE_FrontRight_Union *u,
	struct GW_PE_FrontRight_Struct s)
{
	u->temp_motor = (uint64_t)(s.temp_motor / 0.1f);
	u->temp_inverter = (uint64_t)(s.temp_inverter / 0.1f);
	u->tempigbt = (uint64_t)(s.tempigbt / 0.1f);
	u->actual_velocity = (uint64_t)s.actual_velocity;
}

/* --------------------------- EXC_BATFAN_Control --------------------------- */

inline void
EXC_BATFAN_Control_UnionToStruct(
	struct EXC_BATFAN_Control_Struct *s,
	union EXC_BATFAN_Control_Union u)
{
	s->fan_request = (uint8_t)u.fan_request;
	s->fan_on = (bool)u.fan_on;
}

inline void
EXC_BATFAN_Control_StructToUnion(
	union EXC_BATFAN_Control_Union *u,
	struct EXC_BATFAN_Control_Struct s)
{
	u->fan_request = (uint64_t)s.fan_request;
	u->fan_on = (uint64_t)s.fan_on;
}

/* ------------------------------ LOG_ASSILEDs ------------------------------ */

inline void LOG_ASSILEDs_UnionToStruct(
	struct LOG_ASSILEDs_Struct *s,
	union LOG_ASSILEDs_Union u)
{
	s->yellow = (bool)u.yellow;
	s->blue = (bool)u.blue;
}

inline void LOG_ASSILEDs_StructToUnion(
	union LOG_ASSILEDs_Union *u,
	struct LOG_ASSILEDs_Struct s)
{
	u->yellow = (uint64_t)s.yellow;
	u->blue = (uint64_t)s.blue;
}

/* ---------------------------- EXC_FAN_Control ---------------------------- */

inline void EXC_FAN_Control_UnionToStruct(
	struct EXC_FAN_Control_Struct *s,
	union EXC_FAN_Control_Union u)
{
	s->fan_request = (uint8_t)u.fan_request;
	s->fan_on = (bool)u.fan_on;
}

inline void EXC_FAN_Control_StructToUnion(
	union EXC_FAN_Control_Union *u,
	struct EXC_FAN_Control_Struct s)
{
	u->fan_request = (uint64_t)s.fan_request;
	u->fan_on = (uint64_t)s.fan_on;
}

/* ---------------------------- EXC_PUMP_Control ---------------------------- */

inline void EXC_PUMP_Control_UnionToStruct(
	struct EXC_PUMP_Control_Struct *s,
	union EXC_PUMP_Control_Union u)
{
	s->pump_request = (uint8_t)u.pump_request;
	s->pump_on = (bool)u.pump_on;
}

inline void EXC_PUMP_Control_StructToUnion(
	union EXC_PUMP_Control_Union *u,
	struct EXC_PUMP_Control_Struct s)
{
	u->pump_request = (uint64_t)s.pump_request;
	u->pump_on = (uint64_t)s.pump_on;
}

/* --------------------------- HSC_Vehicle_Status --------------------------- */

inline void
HSC_Vehicle_Status_UnionToStruct(
	struct HSC_Vehicle_Status_Struct *s,
	union HSC_Vehicle_Status_Union u)
{
	s->state = (HSC_Vehicle_Status_State)u.state;
	s->imd_error = (bool)u.imd_error;
	s->ams_error = (bool)u.ams_error;
	s->gen_scs = (uint8_t)u.gen_scs;
	s->velocity = (float)(u.velocity / 0.5f);
	s->velocity_ms = (float)(u.velocity_ms / 0.001f);
}

inline void
HSC_Vehicle_Status_StructToUnion(
	union HSC_Vehicle_Status_Union *u,
	struct HSC_Vehicle_Status_Struct s)
{
	u->state = (uint64_t)s.state;
	u->imd_error = (uint64_t)s.imd_error;
	u->ams_error = (uint64_t)s.ams_error;
	u->gen_scs = (uint64_t)s.gen_scs;
	u->velocity = (uint64_t)(s.velocity / 0.5f);
	u->velocity_ms = (uint64_t)(s.velocity_ms / 0.001f);
}

/* --------------------------- LSC_Extern_Buttons --------------------------- */

inline void
LSC_Extern_Buttons_UnionToStruct(
	struct LSC_Extern_Buttons_Struct *s,
	union LSC_Extern_Buttons_Union u)
{
	s->tsa = (bool)u.tsa;
	s->gen_scs = (uint8_t)u.gen_scs;
}

inline void
LSC_Extern_Buttons_StructToUnion(
	union LSC_Extern_Buttons_Union *u,
	struct LSC_Extern_Buttons_Struct s)
{
	u->tsa = (uint64_t)s.tsa;
	u->gen_scs = (uint64_t)s.gen_scs;
}

/* ---------------------------- LSC_Dash_Buttons ---------------------------- */

inline void LSC_Dash_Buttons_UnionToStruct(
	struct LSC_Dash_Buttons_Struct *s,
	union LSC_Dash_Buttons_Union u)
{
	s->tsa = (bool)u.tsa;
	s->rtd = (bool)u.rtd;
	s->gen_scs = (uint8_t)u.gen_scs;
}

inline void LSC_Dash_Buttons_StructToUnion(
	union LSC_Dash_Buttons_Union *u,
	struct LSC_Dash_Buttons_Struct s)
{
	u->tsa = (uint64_t)s.tsa;
	u->rtd = (uint64_t)s.rtd;
	u->gen_scs = (uint64_t)s.gen_scs;
}

/* --------------------------- SAF_SmSe_AS_Status --------------------------- */

inline void
SAF_SmSe_AS_Status_UnionToStruct(
	struct SAF_SmSe_AS_Status_Struct *s,
	union SAF_SmSe_AS_Status_Union u)
{
	s->scs_error = (bool)u.scs_error;
	s->message_error = (bool)u.message_error;
	s->output_no_change_error = (bool)u.output_no_change_error;
	s->gen_scs = (uint8_t)u.gen_scs;
}

inline void
SAF_SmSe_AS_Status_StructToUnion(
	union SAF_SmSe_AS_Status_Union *u,
	struct SAF_SmSe_AS_Status_Struct s)
{
	u->scs_error = (uint64_t)s.scs_error;
	u->message_error = (uint64_t)s.message_error;
	u->output_no_change_error = (uint64_t)s.output_no_change_error;
	u->gen_scs = (uint64_t)s.gen_scs;
}

/* ---------------------------- SAF_DASH_Status ---------------------------- */

inline void SAF_DASH_Status_UnionToStruct(
	struct SAF_DASH_Status_Struct *s,
	union SAF_DASH_Status_Union u)
{
	s->scs_error = (bool)u.scs_error;
	s->message_error = (bool)u.message_error;
	s->output_no_change_error = (bool)u.output_no_change_error;
	s->gen_scs = (uint8_t)u.gen_scs;
}

inline void SAF_DASH_Status_StructToUnion(
	union SAF_DASH_Status_Union *u,
	struct SAF_DASH_Status_Struct s)
{
	u->scs_error = (uint64_t)s.scs_error;
	u->message_error = (uint64_t)s.message_error;
	u->output_no_change_error = (uint64_t)s.output_no_change_error;
	u->gen_scs = (uint64_t)s.gen_scs;
}

/* -------------------------- SAF_ZoCo_Rear_Status -------------------------- */

inline void
SAF_ZoCo_Rear_Status_UnionToStruct(
	struct SAF_ZoCo_Rear_Status_Struct *s,
	union SAF_ZoCo_Rear_Status_Union u)
{
	s->scs_error = (bool)u.scs_error;
	s->rtds_error = (bool)u.rtds_error;
	s->brake_light_error = (bool)u.brake_light_error;
	s->message_error = (bool)u.message_error;
	s->gen_scs = (uint8_t)u.gen_scs;
	s->brake_light_state = (bool)u.brake_light_state;
	s->rtds_state = (bool)u.rtds_state;
}

inline void
SAF_ZoCo_Rear_Status_StructToUnion(
	union SAF_ZoCo_Rear_Status_Union *u,
	struct SAF_ZoCo_Rear_Status_Struct s)
{
	u->scs_error = (uint64_t)s.scs_error;
	u->rtds_error = (uint64_t)s.rtds_error;
	u->brake_light_error = (uint64_t)s.brake_light_error;
	u->message_error = (uint64_t)s.message_error;
	u->gen_scs = (uint64_t)s.gen_scs;
	u->brake_light_state = (uint64_t)s.brake_light_state;
	u->rtds_state = (uint64_t)s.rtds_state;
}

/* ------------------------- SAF_ZoCo_Front_Status ------------------------- */

inline void
SAF_ZoCo_Front_Status_UnionToStruct(
	struct SAF_ZoCo_Front_Status_Struct *s,
	union SAF_ZoCo_Front_Status_Union u)
{
	s->scs_error = (bool)u.scs_error;
	s->throttle_lower_error = (bool)u.throttle_lower_error;
	s->throttle_upper_error = (bool)u.throttle_upper_error;
	s->throttle_differential_error = (bool)u.throttle_differential_error;
	s->brake_error = (bool)u.brake_error;
	s->gen_scs = (uint8_t)u.gen_scs;
	s->steering_error = (bool)u.steering_error;
}

inline void
SAF_ZoCo_Front_Status_StructToUnion(
	union SAF_ZoCo_Front_Status_Union *u,
	struct SAF_ZoCo_Front_Status_Struct s)
{
	u->scs_error = (uint64_t)s.scs_error;
	u->throttle_lower_error = (uint64_t)s.throttle_lower_error;
	u->throttle_upper_error = (uint64_t)s.throttle_upper_error;
	u->throttle_differential_error = (uint64_t)s.throttle_differential_error;
	u->brake_error = (uint64_t)s.brake_error;
	u->gen_scs = (uint64_t)s.gen_scs;
	u->steering_error = (uint64_t)s.steering_error;
}

/* ----------------------------- SAF_ECU_Status ----------------------------- */

inline void SAF_ECU_Status_UnionToStruct(
	struct SAF_ECU_Status_Struct *s,
	union SAF_ECU_Status_Union u)
{
	s->scs_error = (bool)u.scs_error;
	s->message_error = (bool)u.message_error;
	s->gen_scs = (uint8_t)u.gen_scs;
}

inline void SAF_ECU_Status_StructToUnion(
	union SAF_ECU_Status_Union *u,
	struct SAF_ECU_Status_Struct s)
{
	u->scs_error = (uint64_t)s.scs_error;
	u->message_error = (uint64_t)s.message_error;
	u->gen_scs = (uint64_t)s.gen_scs;
}

/* ------------------------------ HSC_Steering ------------------------------ */

inline void HSC_Steering_UnionToStruct(
	struct HSC_Steering_Struct *s,
	union HSC_Steering_Union u)
{
	s->steering_wheel_angle = (float)(u.steering_wheel_angle / 0.075f);
	s->steering_angle = (float)(u.steering_angle / 0.075f);
	s->angle_valid = (bool)u.angle_valid;
	s->gen_scs = (uint8_t)u.gen_scs;
}

inline void HSC_Steering_StructToUnion(
	union HSC_Steering_Union *u,
	struct HSC_Steering_Struct s)
{
	u->steering_wheel_angle = (uint64_t)(s.steering_wheel_angle / 0.075f);
	u->steering_angle = (uint64_t)(s.steering_angle / 0.075f);
	u->angle_valid = (uint64_t)s.angle_valid;
	u->gen_scs = (uint64_t)s.gen_scs;
}

/* ---------------------------- HSC_DriverInput ---------------------------- */

inline void HSC_DriverInput_UnionToStruct(
	struct HSC_DriverInput_Struct *s,
	union HSC_DriverInput_Union u)
{
	s->throttle = (float)(u.throttle / 0.002f);
	s->brake_pressed = (bool)u.brake_pressed;
	s->throttle_valid = (bool)u.throttle_valid;
	s->brake_valid = (bool)u.brake_valid;
	s->gen_scs = (uint8_t)u.gen_scs;
}

inline void HSC_DriverInput_StructToUnion(
	union HSC_DriverInput_Union *u,
	struct HSC_DriverInput_Struct s)
{
	u->throttle = (uint64_t)(s.throttle / 0.002f);
	u->brake_pressed = (uint64_t)s.brake_pressed;
	u->throttle_valid = (uint64_t)s.throttle_valid;
	u->brake_valid = (uint64_t)s.brake_valid;
	u->gen_scs = (uint64_t)s.gen_scs;
}

/* ---------------------------- CANO_RES_NMT_EC ---------------------------- */

inline void CANO_RES_NMT_EC_UnionToStruct(
	struct CANO_RES_NMT_EC_Struct *s,
	union CANO_RES_NMT_EC_Union u) {}

inline void CANO_RES_NMT_EC_StructToUnion(
	union CANO_RES_NMT_EC_Union *u,
	struct CANO_RES_NMT_EC_Struct s) {}

/* ----------------------------- CANO_RES_RSDO ----------------------------- */

inline void CANO_RES_RSDO_UnionToStruct(
	struct CANO_RES_RSDO_Struct *s,
	union CANO_RES_RSDO_Union u) {}

inline void CANO_RES_RSDO_StructToUnion(
	union CANO_RES_RSDO_Union *u,
	struct CANO_RES_RSDO_Struct s) {}

/* ----------------------------- CANO_RES_TSDO ----------------------------- */

inline void CANO_RES_TSDO_UnionToStruct(
	struct CANO_RES_TSDO_Struct *s,
	union CANO_RES_TSDO_Union u) {}

inline void CANO_RES_TSDO_StructToUnion(
	union CANO_RES_TSDO_Union *u,
	struct CANO_RES_TSDO_Struct s) {}

/* ---------------------------- DV_FREE_TO_USE_2 ---------------------------- */

inline void DV_FREE_TO_USE_2_UnionToStruct(
	struct DV_FREE_TO_USE_2_Struct *s,
	union DV_FREE_TO_USE_2_Union u) {}

inline void DV_FREE_TO_USE_2_StructToUnion(
	union DV_FREE_TO_USE_2_Union *u,
	struct DV_FREE_TO_USE_2_Struct s) {}

/* ----------------------------- CANO_RES_EMCY ----------------------------- */

inline void CANO_RES_EMCY_UnionToStruct(
	struct CANO_RES_EMCY_Struct *s,
	union CANO_RES_EMCY_Union u) {}

inline void CANO_RES_EMCY_StructToUnion(
	union CANO_RES_EMCY_Union *u,
	struct CANO_RES_EMCY_Struct s) {}

/* ----------------------------- DV_SCS_Errors ----------------------------- */

inline void DV_SCS_Errors_UnionToStruct(
	struct DV_SCS_Errors_Struct *s,
	union DV_SCS_Errors_Union u) {}

inline void DV_SCS_Errors_StructToUnion(
	union DV_SCS_Errors_Union *u,
	struct DV_SCS_Errors_Struct s) {}

/* ----------------------------- DV_AMI_Status ----------------------------- */

inline void DV_AMI_Status_UnionToStruct(
	struct DV_AMI_Status_Struct *s,
	union DV_AMI_Status_Union u)
{
	s->state = (DV_AMI_Status_State)u.state;
	s->gen_scs = (uint8_t)u.gen_scs;
}

inline void DV_AMI_Status_StructToUnion(
	union DV_AMI_Status_Union *u,
	struct DV_AMI_Status_Struct s)
{
	u->state = (uint64_t)s.state;
	u->gen_scs = (uint64_t)s.gen_scs;
}

/* ---------------------------- DV_ASB_Pressure ---------------------------- */

inline void DV_ASB_Pressure_UnionToStruct(
	struct DV_ASB_Pressure_Struct *s,
	union DV_ASB_Pressure_Union u)
{
	s->pressure1 = (float)(u.pressure1 / 4.0f);
	s->pressure2 = (float)(u.pressure2 / 4.0f);
}

inline void DV_ASB_Pressure_StructToUnion(
	union DV_ASB_Pressure_Union *u,
	struct DV_ASB_Pressure_Struct s)
{
	u->pressure1 = (uint64_t)(s.pressure1 / 4.0f);
	u->pressure2 = (uint64_t)(s.pressure2 / 4.0f);
}

/* -------------------------- DV_DrivingDynamics1 -------------------------- */

inline void
DV_DrivingDynamics1_UnionToStruct(
	struct DV_DrivingDynamics1_Struct *s,
	union DV_DrivingDynamics1_Union u)
{
	s->speed_actual = (uint8_t)u.speed_actual;
	s->speed_target = (uint8_t)u.speed_target;
	s->steering_angle_actual = (float)(u.steering_angle_actual / 0.5f);
	s->steering_angle_target = (float)(u.steering_angle_target / 0.5f);
	s->brake_hydr_actual = (uint8_t)u.brake_hydr_actual;
	s->brake_hydr_target = (uint8_t)u.brake_hydr_target;
	s->motor_moment_actual = (int8_t)u.motor_moment_actual;
	s->motor_moment_target = (int8_t)u.motor_moment_target;
}

inline void
DV_DrivingDynamics1_StructToUnion(
	union DV_DrivingDynamics1_Union *u,
	struct DV_DrivingDynamics1_Struct s)
{
	u->speed_actual = (uint64_t)s.speed_actual;
	u->speed_target = (uint64_t)s.speed_target;
	u->steering_angle_actual = (uint64_t)(s.steering_angle_actual / 0.5f);
	u->steering_angle_target = (uint64_t)(s.steering_angle_target / 0.5f);
	u->brake_hydr_actual = (uint64_t)s.brake_hydr_actual;
	u->brake_hydr_target = (uint64_t)s.brake_hydr_target;
	u->motor_moment_actual = (uint64_t)s.motor_moment_actual;
	u->motor_moment_target = (uint64_t)s.motor_moment_target;
}

/* -------------------------- DV_DrivingDynamics2 -------------------------- */

inline void
DV_DrivingDynamics2_UnionToStruct(
	struct DV_DrivingDynamics2_Struct *s,
	union DV_DrivingDynamics2_Union u)
{
	s->acceleration_longitudinal =
	  (float)(u.acceleration_longitudinal / 0.001953125f);
	s->acceleration_lateral = (float)(u.acceleration_lateral / 0.001953125f);
	s->yaw_rate = (float)(u.yaw_rate / 0.0078125f);
}

inline void
DV_DrivingDynamics2_StructToUnion(
	union DV_DrivingDynamics2_Union *u,
	struct DV_DrivingDynamics2_Struct s)
{
	u->acceleration_longitudinal =
	  (uint64_t)(s.acceleration_longitudinal / 0.001953125f);
	u->acceleration_lateral = (uint64_t)(s.acceleration_lateral / 0.001953125f);
	u->yaw_rate = (uint64_t)(s.yaw_rate / 0.0078125f);
}

/* ---------------------------- DV_System_Status ---------------------------- */

inline void DV_System_Status_UnionToStruct(
	struct DV_System_Status_Struct *s,
	union DV_System_Status_Union u)
{
	s->as_state = (DV_System_Status_AS_State)u.as_state;
	s->ebs_state = (uint8_t)u.ebs_state;
	s->ami_state = (uint8_t)u.ami_state;
	s->steering_state = (bool)u.steering_state;
	s->service_brake_state = (uint8_t)u.service_brake_state;
	s->lap_counter = (uint8_t)u.lap_counter;
	s->cones_count_actual = (uint8_t)u.cones_count_actual;
	s->cones_count_all = (uint32_t)u.cones_count_all;
}

inline void DV_System_Status_StructToUnion(
	union DV_System_Status_Union *u,
	struct DV_System_Status_Struct s)
{
	u->as_state = (uint64_t)s.as_state;
	u->ebs_state = (uint64_t)s.ebs_state;
	u->ami_state = (uint64_t)s.ami_state;
	u->steering_state = (uint64_t)s.steering_state;
	u->service_brake_state = (uint64_t)s.service_brake_state;
	u->lap_counter = (uint64_t)s.lap_counter;
	u->cones_count_actual = (uint64_t)s.cones_count_actual;
	u->cones_count_all = (uint64_t)s.cones_count_all;
}

/* ----------------------------- DV_ASB_Status ----------------------------- */

inline void DV_ASB_Status_UnionToStruct(
	struct DV_ASB_Status_Struct *s,
	union DV_ASB_Status_Union u)
{
	s->asms = (bool)u.asms;
	s->ebs_state = (uint8_t)u.ebs_state;
	s->service_brake_state = (uint8_t)u.service_brake_state;
	s->check_sequence = (uint8_t)u.check_sequence;
	s->checkup_complete = (bool)u.checkup_complete;
	s->sdc_closed = (bool)u.sdc_closed;
	s->scs_error = (bool)u.scs_error;
	s->trigger_cause = (uint8_t)u.trigger_cause;
	s->state = (uint8_t)u.state;
	s->gen_scs = (uint8_t)u.gen_scs;
}

inline void DV_ASB_Status_StructToUnion(
	union DV_ASB_Status_Union *u,
	struct DV_ASB_Status_Struct s)
{
	u->asms = (uint64_t)s.asms;
	u->ebs_state = (uint64_t)s.ebs_state;
	u->service_brake_state = (uint64_t)s.service_brake_state;
	u->check_sequence = (uint64_t)s.check_sequence;
	u->checkup_complete = (uint64_t)s.checkup_complete;
	u->sdc_closed = (uint64_t)s.sdc_closed;
	u->scs_error = (uint64_t)s.scs_error;
	u->trigger_cause = (uint64_t)s.trigger_cause;
	u->state = (uint64_t)s.state;
	u->gen_scs = (uint64_t)s.gen_scs;
}

/* ----------------------------- CANO_RES_TPDO4 ----------------------------- */

inline void CANO_RES_TPDO4_UnionToStruct(
	struct CANO_RES_TPDO4_Struct *s,
	union CANO_RES_TPDO4_Union u) {}

inline void CANO_RES_TPDO4_StructToUnion(
	union CANO_RES_TPDO4_Union *u,
	struct CANO_RES_TPDO4_Struct s) {}

/* ----------------------------- CANO_RES_TPDO3 ----------------------------- */

inline void CANO_RES_TPDO3_UnionToStruct(
	struct CANO_RES_TPDO3_Struct *s,
	union CANO_RES_TPDO3_Union u) {}

inline void CANO_RES_TPDO3_StructToUnion(
	union CANO_RES_TPDO3_Union *u,
	struct CANO_RES_TPDO3_Struct s) {}

/* ----------------------------- CANO_RES_TPDO2 ----------------------------- */

inline void CANO_RES_TPDO2_UnionToStruct(
	struct CANO_RES_TPDO2_Struct *s,
	union CANO_RES_TPDO2_Union u) {}

inline void CANO_RES_TPDO2_StructToUnion(
	union CANO_RES_TPDO2_Union *u,
	struct CANO_RES_TPDO2_Struct s) {}

/* ----------------------------- CANO_RES_RPDO3 ----------------------------- */

inline void CANO_RES_RPDO3_UnionToStruct(
	struct CANO_RES_RPDO3_Struct *s,
	union CANO_RES_RPDO3_Union u) {}

inline void CANO_RES_RPDO3_StructToUnion(
	union CANO_RES_RPDO3_Union *u,
	struct CANO_RES_RPDO3_Struct s) {}

/* ----------------------------- CANO_RES_RPDO2 ----------------------------- */

inline void CANO_RES_RPDO2_UnionToStruct(
	struct CANO_RES_RPDO2_Struct *s,
	union CANO_RES_RPDO2_Union u) {}

inline void CANO_RES_RPDO2_StructToUnion(
	union CANO_RES_RPDO2_Union *u,
	struct CANO_RES_RPDO2_Struct s) {}

/* ----------------------------- CANO_RES_RPDO1 ----------------------------- */

inline void CANO_RES_RPDO1_UnionToStruct(
	struct CANO_RES_RPDO1_Struct *s,
	union CANO_RES_RPDO1_Union u) {}

inline void CANO_RES_RPDO1_StructToUnion(
	union CANO_RES_RPDO1_Union *u,
	struct CANO_RES_RPDO1_Struct s) {}

/* ----------------------------- CANO_RES_State ----------------------------- */

inline void CANO_RES_State_UnionToStruct(
	struct CANO_RES_State_Struct *s,
	union CANO_RES_State_Union u)
{
	s->k1_e_stop = (bool)u.k1_e_stop;
	s->k2_switch = (bool)u.k2_switch;
	s->k3_button = (bool)u.k3_button;
	s->link_quality = (uint8_t)u.link_quality;
	s->pre_alarm = (bool)u.pre_alarm;
	s->race_mode = (bool)u.race_mode;
}

inline void CANO_RES_State_StructToUnion(
	union CANO_RES_State_Union *u,
	struct CANO_RES_State_Struct s)
{
	u->k1_e_stop = (uint64_t)s.k1_e_stop;
	u->k2_switch = (uint64_t)s.k2_switch;
	u->k3_button = (uint64_t)s.k3_button;
	u->link_quality = (uint64_t)s.link_quality;
	u->pre_alarm = (uint64_t)s.pre_alarm;
	u->race_mode = (uint64_t)s.race_mode;
}

/* ------------------------------- CANO_TIME ------------------------------- */

inline void CANO_TIME_UnionToStruct(
	struct CANO_TIME_Struct *s,
	union CANO_TIME_Union u) {}

inline void CANO_TIME_StructToUnion(
	union CANO_TIME_Union *u,
	struct CANO_TIME_Struct s) {}

/* ------------------------------- CANO_SYNC ------------------------------- */

inline void CANO_SYNC_UnionToStruct(
	struct CANO_SYNC_Struct *s,
	union CANO_SYNC_Union u) {}

inline void CANO_SYNC_StructToUnion(
	union CANO_SYNC_Union *u,
	struct CANO_SYNC_Struct s) {}

/* ------------------------- CANO_NMT_Node_Control ------------------------- */

inline void
CANO_NMT_Node_Control_UnionToStruct(
	struct CANO_NMT_Node_Control_Struct *s,
	union CANO_NMT_Node_Control_Union u)
{
	s->requested_state = (CANO_NMT_Node_Control_Requested_State)u.requested_state;
	s->addressed_node_id =
	  (CANO_NMT_Node_Control_Addressed_Node_ID)u.addressed_node_id;
}

inline void
CANO_NMT_Node_Control_StructToUnion(
	union CANO_NMT_Node_Control_Union *u,
	struct CANO_NMT_Node_Control_Struct s)
{
	u->requested_state = (uint64_t)s.requested_state;
	u->addressed_node_id = (uint64_t)s.addressed_node_id;
}

/* --------------------------- CAL_SteeringAngle --------------------------- */

inline void CAL_SteeringAngle_UnionToStruct(
	struct CAL_SteeringAngle_Struct *s,
	union CAL_SteeringAngle_Union u)
{
	s->voltage = (uint16_t)u.voltage;
}

inline void CAL_SteeringAngle_StructToUnion(
	union CAL_SteeringAngle_Union *u,
	struct CAL_SteeringAngle_Struct s)
{
	u->voltage = (uint64_t)s.voltage;
}

/* -------------------------------- CAL_APPS -------------------------------- */

inline void CAL_APPS_UnionToStruct(
	struct CAL_APPS_Struct *s,
	union CAL_APPS_Union u)
{
	s->upper_3v3 = (uint16_t)u.upper_3v3;
	s->lower_3v3 = (uint16_t)u.lower_3v3;
	s->upper_5v = (float)(u.upper_5v / 1.22f);
	s->lower_5v = (float)(u.lower_5v / 1.22f);
}

inline void CAL_APPS_StructToUnion(
	union CAL_APPS_Union *u,
	struct CAL_APPS_Struct s)
{
	u->upper_3v3 = (uint64_t)s.upper_3v3;
	u->lower_3v3 = (uint64_t)s.lower_3v3;
	u->upper_5v = (uint64_t)(s.upper_5v / 1.22f);
	u->lower_5v = (uint64_t)(s.lower_5v / 1.22f);
}

/* --------------------------- CAL_BrakePressures --------------------------- */

inline void
CAL_BrakePressures_UnionToStruct(
	struct CAL_BrakePressures_Struct *s,
	union CAL_BrakePressures_Union u)
{
	s->front_3v3 = (uint16_t)u.front_3v3;
	s->rear_3v3 = (uint16_t)u.rear_3v3;
	s->front_5v = (float)(u.front_5v / 1.22f);
	s->rear_5v = (float)(u.rear_5v / 1.22f);
}

inline void
CAL_BrakePressures_StructToUnion(
	union CAL_BrakePressures_Union *u,
	struct CAL_BrakePressures_Struct s)
{
	u->front_3v3 = (uint64_t)s.front_3v3;
	u->rear_3v3 = (uint64_t)s.rear_3v3;
	u->front_5v = (uint64_t)(s.front_5v / 1.22f);
	u->rear_5v = (uint64_t)(s.rear_5v / 1.22f);
}

/* ------------------------- CAL_SpringTravel_Rear ------------------------- */

inline void
CAL_SpringTravel_Rear_UnionToStruct(
	struct CAL_SpringTravel_Rear_Struct *s,
	union CAL_SpringTravel_Rear_Union u)
{
	s->rear_right_converted = (float)(u.rear_right_converted / 0.01f);
	s->rear_left_converted = (float)(u.rear_left_converted / 0.01f);
	s->rear_right_voltage = (uint16_t)u.rear_right_voltage;
	s->rear_left_voltage = (uint16_t)u.rear_left_voltage;
}

inline void
CAL_SpringTravel_Rear_StructToUnion(
	union CAL_SpringTravel_Rear_Union *u,
	struct CAL_SpringTravel_Rear_Struct s)
{
	u->rear_right_converted = (uint64_t)(s.rear_right_converted / 0.01f);
	u->rear_left_converted = (uint64_t)(s.rear_left_converted / 0.01f);
	u->rear_right_voltage = (uint64_t)s.rear_right_voltage;
	u->rear_left_voltage = (uint64_t)s.rear_left_voltage;
}

/* ------------------------- CAL_SpringTravel_Front ------------------------- */

inline void
CAL_SpringTravel_Front_UnionToStruct(
	struct CAL_SpringTravel_Front_Struct *s,
	union CAL_SpringTravel_Front_Union u)
{
	s->front_right_converted = (float)(u.front_right_converted / 0.01f);
	s->front_left_converted = (float)(u.front_left_converted / 0.01f);
	s->front_right_voltage = (uint16_t)u.front_right_voltage;
	s->front_left_voltage = (uint16_t)u.front_left_voltage;
}

inline void
CAL_SpringTravel_Front_StructToUnion(
	union CAL_SpringTravel_Front_Union *u,
	struct CAL_SpringTravel_Front_Struct s)
{
	u->front_right_converted = (uint64_t)(s.front_right_converted / 0.01f);
	u->front_left_converted = (uint64_t)(s.front_left_converted / 0.01f);
	u->front_right_voltage = (uint64_t)s.front_right_voltage;
	u->front_left_voltage = (uint64_t)s.front_left_voltage;
}

/* ------------------------- CAL_CalibrationMaster ------------------------- */

inline void
CAL_CalibrationMaster_UnionToStruct(
	struct CAL_CalibrationMaster_Struct *s,
	union CAL_CalibrationMaster_Union u) {}

inline void
CAL_CalibrationMaster_StructToUnion(
	union CAL_CalibrationMaster_Union *u,
	struct CAL_CalibrationMaster_Struct s) {}

/* ---------------------------- DV_DriveCommand ---------------------------- */

inline void DV_DriveCommand_UnionToStruct(
	struct DV_DriveCommand_Struct *s,
	union DV_DriveCommand_Union u)
{
	s->rtd_request = (bool)u.rtd_request;
	s->ebs_trigger = (bool)u.ebs_trigger;
	s->throttle_command = (float)(u.throttle_command / 0.1f);
	s->brake_command = (float)(u.brake_command / 0.1f);
	s->recu_command = (float)(u.recu_command / 0.1f);
	s->gen_scs = (uint8_t)u.gen_scs;
}

inline void DV_DriveCommand_StructToUnion(
	union DV_DriveCommand_Union *u,
	struct DV_DriveCommand_Struct s)
{
	u->rtd_request = (uint64_t)s.rtd_request;
	u->ebs_trigger = (uint64_t)s.ebs_trigger;
	u->throttle_command = (uint64_t)(s.throttle_command / 0.1f);
	u->brake_command = (uint64_t)(s.brake_command / 0.1f);
	u->recu_command = (uint64_t)(s.recu_command / 0.1f);
	u->gen_scs = (uint64_t)s.gen_scs;
}

/* -------------------------- LOG_WaterTemps_Left -------------------------- */

inline void
LOG_WaterTemps_Left_UnionToStruct(
	struct LOG_WaterTemps_Left_Struct *s,
	union LOG_WaterTemps_Left_Union u)
{
	s->wt_1 = (float)(u.wt_1 / 0.5f);
	s->wt_2 = (float)(u.wt_2 / 0.5f);
	s->wt_3 = (float)(u.wt_3 / 0.5f);
	s->wt_4 = (float)(u.wt_4 / 0.5f);
}

inline void
LOG_WaterTemps_Left_StructToUnion(
	union LOG_WaterTemps_Left_Union *u,
	struct LOG_WaterTemps_Left_Struct s)
{
	u->wt_1 = (uint64_t)(s.wt_1 / 0.5f);
	u->wt_2 = (uint64_t)(s.wt_2 / 0.5f);
	u->wt_3 = (uint64_t)(s.wt_3 / 0.5f);
	u->wt_4 = (uint64_t)(s.wt_4 / 0.5f);
}

/* -------------------------- LOG_WaterTemps_Right -------------------------- */

inline void
LOG_WaterTemps_Right_UnionToStruct(
	struct LOG_WaterTemps_Right_Struct *s,
	union LOG_WaterTemps_Right_Union u)
{
	s->wt_1 = (float)(u.wt_1 / 0.5f);
	s->wt_2 = (float)(u.wt_2 / 0.5f);
	s->wt_3 = (float)(u.wt_3 / 0.5f);
	s->wt_4 = (float)(u.wt_4 / 0.5f);
}

inline void
LOG_WaterTemps_Right_StructToUnion(
	union LOG_WaterTemps_Right_Union *u,
	struct LOG_WaterTemps_Right_Struct s)
{
	u->wt_1 = (uint64_t)(s.wt_1 / 0.5f);
	u->wt_2 = (uint64_t)(s.wt_2 / 0.5f);
	u->wt_3 = (uint64_t)(s.wt_3 / 0.5f);
	u->wt_4 = (uint64_t)(s.wt_4 / 0.5f);
}

/* ------------------------- LOG_SpringTravel_Front ------------------------- */

inline void
LOG_SpringTravel_Front_UnionToStruct(
	struct LOG_SpringTravel_Front_Struct *s,
	union LOG_SpringTravel_Front_Union u)
{
	s->front_left = (float)(u.front_left / 0.01f);
	s->front_right = (float)(u.front_right / 0.01f);
}

inline void
LOG_SpringTravel_Front_StructToUnion(
	union LOG_SpringTravel_Front_Union *u,
	struct LOG_SpringTravel_Front_Struct s)
{
	u->front_left = (uint64_t)(s.front_left / 0.01f);
	u->front_right = (uint64_t)(s.front_right / 0.01f);
}

/* ------------------------- LOG_SpringTravel_Rear ------------------------- */

inline void
LOG_SpringTravel_Rear_UnionToStruct(
	struct LOG_SpringTravel_Rear_Struct *s,
	union LOG_SpringTravel_Rear_Union u)
{
	s->rear_left = (float)(u.rear_left / 0.01f);
	s->rear_right = (float)(u.rear_right / 0.01f);
}

inline void
LOG_SpringTravel_Rear_StructToUnion(
	union LOG_SpringTravel_Rear_Union *u,
	struct LOG_SpringTravel_Rear_Struct s)
{
	u->rear_left = (uint64_t)(s.rear_left / 0.01f);
	u->rear_right = (uint64_t)(s.rear_right / 0.01f);
}

/* --------------------------- LOG_BrakePressures --------------------------- */

inline void
LOG_BrakePressures_UnionToStruct(
	struct LOG_BrakePressures_Struct *s,
	union LOG_BrakePressures_Union u)
{
	s->front = (float)(u.front / 50.0f);
	s->rear = (float)(u.rear / 50.0f);
}

inline void
LOG_BrakePressures_StructToUnion(
	union LOG_BrakePressures_Union *u,
	struct LOG_BrakePressures_Struct s)
{
	u->front = (uint64_t)(s.front / 50.0f);
	u->rear = (uint64_t)(s.rear / 50.0f);
}

/* -------------------------------- LOG_LEM -------------------------------- */

inline void LOG_LEM_UnionToStruct(
	struct LOG_LEM_Struct *s,
	union LOG_LEM_Union u)
{
	s->lv = (uint16_t)u.lv;
}

inline void LOG_LEM_StructToUnion(
	union LOG_LEM_Union *u,
	struct LOG_LEM_Struct s)
{
	u->lv = (uint64_t)s.lv;
}

/* ------------------------------ LOG_DashLEDs ------------------------------ */

inline void LOG_DashLEDs_UnionToStruct(
	struct LOG_DashLEDs_Struct *s,
	union LOG_DashLEDs_Union u)
{
	s->imd = (bool)u.imd;
	s->ams = (bool)u.ams;
}

inline void LOG_DashLEDs_StructToUnion(
	union LOG_DashLEDs_Union *u,
	struct LOG_DashLEDs_Struct s)
{
	u->imd = (uint64_t)s.imd;
	u->ams = (uint64_t)s.ams;
}

/* ------------------------------ LOG_airp_FW ------------------------------ */

inline void LOG_airp_FW_UnionToStruct(
	struct LOG_airp_FW_Struct *s,
	union LOG_airp_FW_Union u)
{
	s->airp1 = (float)(u.airp1 / 2.0f);
	s->airp2 = (float)(u.airp2 / 2.0f);
}

inline void LOG_airp_FW_StructToUnion(
	union LOG_airp_FW_Union *u,
	struct LOG_airp_FW_Struct s)
{
	u->airp1 = (uint64_t)(s.airp1 / 2.0f);
	u->airp2 = (uint64_t)(s.airp2 / 2.0f);
}

/* ------------------------------ LOG_airp_SPL ------------------------------ */

inline void LOG_airp_SPL_UnionToStruct(
	struct LOG_airp_SPL_Struct *s,
	union LOG_airp_SPL_Union u)
{
	s->airp1 = (float)(u.airp1 / 2.0f);
	s->airp2 = (float)(u.airp2 / 2.0f);
	s->airp3 = (float)(u.airp3 / 2.0f);
}

inline void LOG_airp_SPL_StructToUnion(
	union LOG_airp_SPL_Union *u,
	struct LOG_airp_SPL_Struct s)
{
	u->airp1 = (uint64_t)(s.airp1 / 2.0f);
	u->airp2 = (uint64_t)(s.airp2 / 2.0f);
	u->airp3 = (uint64_t)(s.airp3 / 2.0f);
}

/* ------------------------------ LOG_airp_SPR ------------------------------ */

inline void LOG_airp_SPR_UnionToStruct(
	struct LOG_airp_SPR_Struct *s,
	union LOG_airp_SPR_Union u)
{
	s->airp1 = (float)(u.airp1 / 2.0f);
	s->airp2 = (float)(u.airp2 / 2.0f);
	s->airp3 = (float)(u.airp3 / 2.0f);
}

inline void LOG_airp_SPR_StructToUnion(
	union LOG_airp_SPR_Union *u,
	struct LOG_airp_SPR_Struct s)
{
	u->airp1 = (uint64_t)(s.airp1 / 2.0f);
	u->airp2 = (uint64_t)(s.airp2 / 2.0f);
	u->airp3 = (uint64_t)(s.airp3 / 2.0f);
}

/* ------------------------------ LOG_airp_RW ------------------------------ */

inline void LOG_airp_RW_UnionToStruct(
	struct LOG_airp_RW_Struct *s,
	union LOG_airp_RW_Union u)
{
	s->airp1 = (float)(u.airp1 / 2.0f);
	s->airp2 = (float)(u.airp2 / 2.0f);
}

inline void LOG_airp_RW_StructToUnion(
	union LOG_airp_RW_Union *u,
	struct LOG_airp_RW_Struct s)
{
	u->airp1 = (uint64_t)(s.airp1 / 2.0f);
	u->airp2 = (uint64_t)(s.airp2 / 2.0f);
}

/* ---------------------------- LOG_PE_MaxTemps ---------------------------- */

inline void LOG_PE_MaxTemps_UnionToStruct(
	struct LOG_PE_MaxTemps_Struct *s,
	union LOG_PE_MaxTemps_Union u)
{
	s->front = (float)(u.front / 0.6f);
	s->rear = (float)(u.rear / 0.6f);
	s->left = (float)(u.left / 0.6f);
	s->right = (float)(u.right / 0.6f);
	s->usage_front = (float)(u.usage_front / 0.5f);
	s->usage_rear = (float)(u.usage_rear / 0.5f);
	s->usage_left = (float)(u.usage_left / 0.5f);
	s->usage_right = (float)(u.usage_right / 0.5f);
}

inline void LOG_PE_MaxTemps_StructToUnion(
	union LOG_PE_MaxTemps_Union *u,
	struct LOG_PE_MaxTemps_Struct s)
{
	u->front = (uint64_t)(s.front / 0.6f);
	u->rear = (uint64_t)(s.rear / 0.6f);
	u->left = (uint64_t)(s.left / 0.6f);
	u->right = (uint64_t)(s.right / 0.6f);
	u->usage_front = (uint64_t)(s.usage_front / 0.5f);
	u->usage_rear = (uint64_t)(s.usage_rear / 0.5f);
	u->usage_left = (uint64_t)(s.usage_left / 0.5f);
	u->usage_right = (uint64_t)(s.usage_right / 0.5f);
}

/* -------------------------- LOG_EKF_Translation -------------------------- */

inline void
LOG_EKF_Translation_UnionToStruct(
	struct LOG_EKF_Translation_Struct *s,
	union LOG_EKF_Translation_Union u)
{
	s->velocity_vx = (float)(u.velocity_vx / 0.002f);
	s->velocity_vy = (float)(u.velocity_vy / 0.002f);
	s->acceleration_ax = (float)(u.acceleration_ax / 0.002f);
	s->acceleration_ay = (float)(u.acceleration_ay / 0.002f);
}

inline void
LOG_EKF_Translation_StructToUnion(
	union LOG_EKF_Translation_Union *u,
	struct LOG_EKF_Translation_Struct s)
{
	u->velocity_vx = (uint64_t)(s.velocity_vx / 0.002f);
	u->velocity_vy = (uint64_t)(s.velocity_vy / 0.002f);
	u->acceleration_ax = (uint64_t)(s.acceleration_ax / 0.002f);
	u->acceleration_ay = (uint64_t)(s.acceleration_ay / 0.002f);
}

/* ---------------------------- LOG_EKF_Rotation ---------------------------- */

inline void LOG_EKF_Rotation_UnionToStruct(
	struct LOG_EKF_Rotation_Struct *s,
	union LOG_EKF_Rotation_Union u)
{
	s->heading_psi = (float)(u.heading_psi / 0.0003f);
	s->yaw_rate = (float)(u.yaw_rate / 0.00018f);
}

inline void LOG_EKF_Rotation_StructToUnion(
	union LOG_EKF_Rotation_Union *u,
	struct LOG_EKF_Rotation_Struct s)
{
	u->heading_psi = (uint64_t)(s.heading_psi / 0.0003f);
	u->yaw_rate = (uint64_t)(s.yaw_rate / 0.00018f);
}

/* ------------------------------- CANO_TLSS ------------------------------- */

inline void CANO_TLSS_UnionToStruct(
	struct CANO_TLSS_Struct *s,
	union CANO_TLSS_Union u) {}

inline void CANO_TLSS_StructToUnion(
	union CANO_TLSS_Union *u,
	struct CANO_TLSS_Struct s) {}

/* ------------------------------- CANO_RLSS ------------------------------- */

inline void CANO_RLSS_UnionToStruct(
	struct CANO_RLSS_Struct *s,
	union CANO_RLSS_Union u) {}

inline void CANO_RLSS_StructToUnion(
	union CANO_RLSS_Union *u,
	struct CANO_RLSS_Struct s) {}

#pragma GCC diagnostic pop

// END unused variable warnings
