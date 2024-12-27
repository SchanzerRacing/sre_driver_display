#ifndef SRE_LOGIC_H
#define SRE_LOGIC_H

#include <stdint.h>
#include <stdbool.h>

// Functions

gboolean sre_run_display();
void graphical_update();
void label_update();
void state_update();

void init_sre_state();

void tsa_logic();
void r2d_logic();

// STRUCT
typedef struct {
    int brake_pressure_1;
    int brake_pressure_2;

    int asb_pressure_1;
    int asb_pressure_2;

    int sdc_power;
    int lv_power;
    int hv_power;
    int epos_power;

    bool acu_switch;
    bool asb_switch;
    bool dash_switch;
    bool epos_lc_switch;
    bool fan_l_switch;
    bool fan_r_switch;
    bool sbg_switch;
    bool vcu_switch;
    bool pef_switch;
    bool per_switch;
    bool pumps_switch;
    bool sensors_switch;

    bool tsa_ready;
    bool tsa_active;

    bool r2d_ready;
    bool r2d_active;

    uint8_t car_state;
    uint8_t bat_state;
    uint8_t asb_state;
    uint8_t ami_state;
    uint8_t as_state;
    uint8_t sbs_state;
    uint8_t ebs_state;
    uint8_t asb_check_sequence;
    uint8_t asb_trigger_cause;
} SRE_State;

extern SRE_State* sre_state;

// ENUMS and STRINGS

// ET
enum CAR_STATE {UNDEFINED_C, WAIT_FOR_TSA_C, RTD_OFF, WAIT_FOR_RTD, DRIVE, LC_ON, SCS_ERROR};
static const char* CAR_STATE_STR[] = {"Undefined", "Wait for TSA", "RTD Off", "Wait for RTD", "Drive", "LC On", "SCS Error"};

// HV
enum BAT_STATE {UNDEFINED_B, START, BMS_RESET, SDC_OPEN, WAIT_FOR_TSA_B, TS_STARTUP, TSA, ISO_ERROR, BMS_ERROR, IMD_ERROR, BAT_ERROR};
static const char* BAT_STATE_STR[] = {"Undefined", "Start", "BMS Reset", "SDC Open", "Wait for TSA", "TS Startup", "TSA", "ISO Error", "BMS Error", "IMD Error", "BAT Error"};

// DV
enum ASB_STATE {UNINITALIZED, MV_CHECK, PASSIVE, DV_CHECK, MONITORING, EBS_TRIGGERED};
static const char* ASB_STATE_STR[] = {"Uninitialized", "MV Check", "Passive", "DV Check", "Monitoring", "EBS Triggered"};

enum AMI_STATE {MANUAL, ACCEL, SKIDPAD, TRACKDRIVE, BRAKETEST, INSPECTION, AUTOX};
static const char* AMI_STATE_STR[] = {"Manual", "Accel", "Skidpad", "Trackdrive", "Braketest", "Inspection", "Autox"};

enum AS_STATE {OFF = 1, READY = 2, DRIVING = 3, EMERGENCY_BRAKE = 4, FINISH = 5};
static const char* AS_STATE_STR[] = {"Off", "Ready", "Driving", "Emergency Brake", "Finish"};

enum SERVICE_BRAKE_STATE {DISENGAGED = 1, ENGAGED = 2, AVAILABLE = 3};
static const char* SERVICE_BRAKE_STATE_STR[] = {"Disengaged", "Engaged", "Available"};

enum EBS_STATE {UNAVAILABLE = 1, ARMED = 2, ACTIVATED = 3};
static const char* EBS_STATE_STR[] = {"Unavailable", "Armed", "Activated"};

enum ASB_CHECK_SEQUENCE {WATCHDOG_NOT_TRIGGERING, WATCHDOG_TRIGGERING, ASB_PRESS_OK, BP_BUILT_UP, CLOSE_SDC_WAIT_TSA, DEAC_EBS2, DEAC_EBS1_AC_EBS2, AC_EBS1_AND_2};
static const char* ASB_CHECK_SEQUENCE_STR[] = {"Watchdog not triggering", "Watchdog triggering", "ASB Press OK", "BP built up", "Close SDC wait TSA", "Deac EBS2", "Deac EBS1 Act EBS2", "Act EBS1 and 2"};

enum ASB_TRIGGER_CAUSE { WATCHDOG_ERROR = 1, ASB_PRESSURES_INVALID = 2, BRAKE_PRESSURE_INVALID = 3, EBS1_PRESSURE_LOW = 4, EBS2_PRESSURE_LOW = 5, ASB_PRESSURE_LOW = 6, CAN_SCS_ERROR = 7, EBS_TRIGGERED_BY_AS = 8, RES_SDC_OPEN = 9, SDC_OPEN_ASB = 10, MECHANICALLY_STUCK_ERROR = 11, ASMS_TURNED_OFF_IN_MONITORING = 12};
static const char* ASB_TRIGGER_CAUSE_STR[] = { "Watchdog error", "ASB Pressures invalid", "Brake Pressure invalid", "EBS1 Pressure low", "EBS2 Pressure low", "ASB Pressure low", "CAN / SCS Error", "EBS triggered by AS", "RES SDC open", "SDC open", "Mechanically Stuck Error", "ASMS Turned Off in Monitoring"};

#endif // SRE_LOGIC_H