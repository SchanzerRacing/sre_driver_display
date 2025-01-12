#ifndef SRE_LOGIC_H
#define SRE_LOGIC_H

#include <stdint.h>
#include <stdbool.h>

// Functions
gboolean sre_run_display();
void graphical_update();
void label_update();
void state_update();

void init_sre_logic();

void tsa_logic();
void r2d_logic();



/* ---- VEHICLE INFO MANAGEMENT --- */

void info_logic();

/// @brief calculates and returns the position of the first bit that is 1
/// @param value variable to be checked
/// @return position of the first bit that is 1
uint32_t get_bit_position(uint32_t value);

/* -------- VEHICLE ERROR MANAGEMENT ------------ */

// array of errors
#define SHOW_ERRORS 9
#define MAX_ERRORS 32

// Error struct that contains information about the Error
typedef struct {
    uint64_t last_seen;      // timestamp of last seen in s

    uint16_t error_type;      // General Error Type
    uint16_t sub_error_type;  // Specific Error Type

    uint8_t dismissed;        // State of dismissal
} SRE_error;

void error_logic();

/// @brief create an sre_error object and returns a pointer to it
/// @param error_type general error type
/// @param sub_error_type specific error type
/// @return pointer to the sre_error object
SRE_error* create_sre_error(uint16_t error_type, uint16_t sub_error_type);

/// @brief Adds the error to the vehicle_errors array
/// @param error error to be added
void add_error(SRE_error* error);

/// @brief removes and frees error in vehicle_array on specific position
/// @param index position of the error in vehicle_array
void remove_error(uint16_t index);

/// @brief checks if an error exists in the vehicle_error array and returns result
/// @param error_type general error type
/// @param sub_error_type specific error type
/// @return returns pointer to the error if it exists, NULL if it does not
SRE_error* check_if_error_exists(uint16_t error_type, uint16_t sub_error_type);

/// @brief frees all errors in the vehicle_error array
void free_all_errors();

// array of SRE_error
extern SRE_error* vehicle_errors[MAX_ERRORS];

enum ERROR_TYPES 
{
    UNDEFINED_ERROR = 0,
    VCU,
    ERR_SDC_OPEN,
    BAT_ERR,
    ASB_ERROR,
    SCS_ZOCO_FRONT,
    SCS_ZOCO_REAR,
    SCS_ZOCO_LEFT,
    SCS_ZOCO_RIGHT,
    SCS_FUSEBOARD,
    SCS_DIO_AS,
    SCS_DIO_DASH,
    SCS_AIN_F1,
};

enum VCU_ERROR_TYPES
{
    VCU_UNDEFINED,
    VCU_SCS,
    VCU_MSG_ERR,
};

enum SDC_ERROR_TYPES
{
    SDC_UNDEFINED,
    SDC_RES,
    SDC_FR,
    SDC_ASB,
    SDC_BSPD,
    SDC_BOTS,
    SDC_FL,
    SDC_DASH,
    SDC_INERTIA,
    SDC_RL,
    SDC_TSAL,
    SDC_RR,
    SDC_HVD,
    SDC_TS_CONNECTOR,
    SDC_TSMS,
};

enum BAT_ERROR_TYPES
{
    BAT_UNDEFINED,
    BAT_SDC_OPEN = 3,
    BAT_ISO = 7,
    BAT_BMS = 8,
    BAT_IMD = 9,
    BAT_GENERAL = 10,
};

enum ASB_ERROR_TYPES
{
    ASB_UNDEFINED,
    ASB_WATCHDOG_ERROR,
    ASB_ASB_P_INVALID,
    ASB_BP_INVALID,
    ASB_EBS1_LOW,
    ASB_EBS2_LOW,
    ASB_ASB_P_LOW,
    ASB_CAN,
    ASB_EBS_TRIGGERED_BY_AS,
    ASB_RES_SDC,
    ASB_SDC,
    ASB_MECH_STUCK,
    ASB_ASMS_TURNED_OFF,
    ASB_EBS_TRIGGERED,
};



/* ---------- STATE MANAGEMENT ------------------- */

// TODO: Refactor this to single structs (switches, states, powers, Errors etc)
// STRUCT
typedef struct {

    // Pressures
    int brake_pressure_1;
    int brake_pressure_2;

    int asb_pressure_1;
    int asb_pressure_2;

    // Power measurement
    int sdc_power;
    int lv_power;
    int hv_power;
    int epos_power;


    // Switch States
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

    // States
    uint8_t car_state;
    uint16_t bat_state;
    uint8_t as_state;
    uint8_t ami_state;
    uint8_t asb_state;
    uint8_t sbs_state;
    uint8_t ebs_state;
    uint8_t asb_checkup_complete;
    uint8_t asb_check_sequence;
    uint16_t asb_trigger_cause;

    // Graphical 
    bool tsa_ready;
    bool tsa_active;

    bool r2d_ready;
    bool r2d_active;

    bool error_show;
    bool info_show;

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

enum AS_STATE {OFF = 1, READY = 2, DRIVING = 3, EMERGENCY = 4, FINISH = 5};
static const char* AS_STATE_STR[] = {"Off", "Ready", "Driving", "Emergency", "Finish"};

enum SERVICE_BRAKE_STATE {DISENGAGED = 1, ENGAGED = 2, AVAILABLE = 3};
static const char* SERVICE_BRAKE_STATE_STR[] = {"Disengaged", "Engaged", "Available"};

enum EBS_STATE {UNAVAILABLE = 1, ARMED = 2, ACTIVATED = 3};
static const char* EBS_STATE_STR[] = {"Unavailable", "Armed", "Activated"};

enum ASB_CHECK_SEQUENCE {WATCHDOG_NOT_TRIGGERING, WATCHDOG_TRIGGERING, ASB_PRESS_OK, BP_BUILT_UP, CLOSE_SDC_WAIT_TSA, DEAC_EBS2, DEAC_EBS1_AC_EBS2, AC_EBS1_AND_2};
static const char* ASB_CHECK_SEQUENCE_STR[] = {"Watchdog not triggering", "Watchdog triggering", "ASB Press OK", "BP built up", "Close SDC wait TSA", "Deac EBS2", "Deac EBS1 Act EBS2", "Act EBS1 and 2"};

enum ASB_TRIGGER_CAUSE { WATCHDOG_ERROR = 1, ASB_PRESSURES_INVALID = 2, BRAKE_PRESSURE_INVALID = 3, EBS1_PRESSURE_LOW = 4, EBS2_PRESSURE_LOW = 5, ASB_PRESSURE_LOW = 6, CAN_SCS_ERROR = 7, EBS_TRIGGERED_BY_AS = 8, RES_SDC_OPEN = 9, SDC_OPEN_ASB = 10, MECHANICALLY_STUCK_ERROR = 11, ASMS_TURNED_OFF_IN_MONITORING = 12};
static const char* ASB_TRIGGER_CAUSE_STR[] = { "Watchdog error", "ASB Pressures invalid", "Brake Pressure invalid", "EBS1 Pressure low", "EBS2 Pressure low", "ASB Pressure low", "CAN / SCS Error", "EBS triggered by AS", "RES SDC open", "SDC open", "Mechanically Stuck Error", "ASMS Turned Off in Monitoring"};

#endif // SRE_LOGIC_H