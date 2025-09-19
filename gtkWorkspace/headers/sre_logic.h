#ifndef SRE_LOGIC_H
#define SRE_LOGIC_H

#include <stdint.h>
#include <stdbool.h>

// whether to use can and disable debugging features (key press debug)
#define USE_CAN 1

// Critical or Warning Values
#define WARNING_BAT_TEMP 48
#define CRITICAL_BAT_TEMP 53
#define WARNING_SOC 15
#define CRITICAL_SOC 10
#define WARNING_VOLT 3.0
#define CRITICAL_VOLT 2.7
#define WARNING_MOTOR_TEMP 60
#define CRITICAL_MOTOR_TEMP 70
#define WARNING_PE_TEMP 60
#define CRITICAL_PE_TEMP 70

// error configuration
#define SHOW_ERRORS 9
#define MAX_ERRORS 32
#define FREE_AFTER 1 // seconds
#define ERROR_TYPE_COUNT 15
#define ERROR_SUB_TYPE_COUNT 32
#define ERROR_PANEL_UPDATE_INT 1 // seconds

// Functions
gboolean sre_run_display();
void graphical_update();
void label_update();
void error_label_update();
void error_panel_update();
void state_update();

void init_sre_logic();

void tsa_logic();
void r2d_logic();

/* ---- PANEL MANAGEMENT ---- */
extern uint8_t currentPanel;

extern GObject *label_tsa_current;
extern GObject *label_r2d_current;

enum PANELS
{
  ENDURANCE,
  DEBUG,
  PARAMETERS,
  VEHICLEINFO,
};

/* -------- VEHICLE ERROR MANAGEMENT ------------ */

// Error struct that contains information about the Error
typedef struct
{
  uint64_t last_seen; // timestamp of last seen in s

  uint16_t error_type;     // General Error Type
  uint16_t sub_error_type; // Specific Error Type

  uint8_t dismissed; // State of dismissal
} SRE_error;

void error_logic();

/// @brief create an sre_error object and returns a pointer to it
/// @param error_type general error type
/// @param sub_error_type specific error type
/// @return pointer to the sre_error object
SRE_error *create_sre_error(uint16_t error_type, uint16_t sub_error_type);

/// @brief Adds the error to the vehicle_error array
/// @param error error to be added
void add_error(SRE_error *error);

/// @brief removes and frees error in vehicle_error array on specific position
/// @param index position of the error in vehicle_error array
void remove_error(uint16_t index);

/// @brief checks if an error exists in the vehicle_error array and returns result
/// @param error_type general error type
/// @param sub_error_type specific error type
/// @return returns pointer to the error if it exists, NULL if it does not
SRE_error *check_if_error_exists(uint16_t error_type, uint16_t sub_error_type);

/// @brief frees all errors in the vehicle_error array
void free_all_errors();

// free array of SRE_error
extern SRE_error *vehicle_errors[MAX_ERRORS];

/* ---- VEHICLE INFO MANAGEMENT --- */

// Utilizing the Error structs for vehicle info as well, since they are similar in structure
// Could be refactored to use a even more generic structure and methods

/// @brief controls the info panel
void info_logic();

/// @brief creates an SRE_error object and returns a pointer to it
/// @param info_type general info type
void add_info(SRE_error *info);

/// @brief removes and frees info in vehicle_info array on specific position
/// @param index positionf of the info in vehicle_info array
void remove_info(uint16_t index);

/// @brief checks if an info object exists in the vehicle_info array and returns result
/// @param info_type general info type
/// @param sub_info_type specific info type
/// @return returns pointer to the info if it exists, NULL if it does not
SRE_error *check_if_info_exists(uint16_t info_type, uint16_t sub_info_type);

// free array of SRE_info
void free_all_infos();

extern SRE_error *vehicle_infos[MAX_ERRORS];

/// @brief calculates and returns the position of the first bit that is 1
/// @param value variable to be checked
/// @return position of the first bit that is 1
uint32_t get_bit_position(uint32_t value);

// STRUCTs

typedef struct
{
  // Pressures
  float brake_pressure_1;
  float brake_pressure_2;
  float asb_pressure_1;
  float asb_pressure_2;
} SRE_Pressures;

typedef struct
{
  uint8_t temp;
  uint8_t mt_driver_input;
  uint8_t mt_zoco_front;
  uint8_t mt_asb_status;
  uint8_t mt_steering;
  uint8_t mt_st_wheel_status;
  uint8_t mt_zoco_left;
  uint8_t mt_zoco_right;
  uint8_t mt_drive_command;
  uint8_t mt_zoco_rear;
  uint8_t mt_extern_button;
  uint8_t mt_saf_fuseboard;
  uint8_t mt_bat_pcb_info;
  uint8_t mt_bat_pcb_control;
  uint8_t mt_bat_pcb_soc;
  uint8_t mt_temp_pcb_1;
  uint8_t mt_temp_pcb_2;
  uint8_t mt_temp_pcb_3;
  uint8_t mt_temp_pcb_4;
  uint8_t mt_temp_pcb_5;
  uint8_t mt_temp_pcb_6;
  uint8_t mt_lsc_dash_buttons;
  uint8_t mt_saf_dash_status;
  uint8_t scs_dash;
  uint8_t scs_asb_status;
  uint8_t scs_zoco_front;
  uint8_t scs_zoco_left;
  uint8_t scs_zoco_rear;
  uint8_t scs_zoco_right;
  uint8_t scs_st_wheel;
  uint8_t scs_fuseboard;
} SRE_ECU_Errors;

typedef struct
{
  // Temperatures
  float temp_per;
  float temp_pef;
  float temp_motor_fl;
  float temp_motor_fr;
  float temp_motor_rl;
  float temp_motor_rr;
} SRE_Temperatures;

typedef struct
{
  // Battery
  float bat_soc;
  float bat_temp_max;
  float bat_temp_min;
  float bat_volt_max;
  float bat_volt_min;
} SRE_Battery;

typedef struct
{
  // Power measurement
  float sdc_power;
  float lv_power;
  float hv_power;
  float epos_power;
} SRE_Power;

typedef struct
{
  // Vehicle Info
  float car_speed;
  float car_speed_gps;
  float car_accel_x;
  float car_accel_y;
  float car_accel_z;
} SRE_Vehicle_info;

typedef struct
{
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
} SRE_Switch_States;

typedef struct
{
  // SDC States
  uint8_t res;
  uint8_t motor_fr;
  uint8_t asb;
  uint8_t bspd;
  uint8_t bots;
  uint8_t motor_fl;
  uint8_t dash;
  uint8_t inertia;
  uint8_t motor_rl;
  uint8_t mainhoop;
  uint8_t motor_rr;
  uint8_t hvd;
  uint8_t ts_connector;
  uint8_t tsms;
} SRE_SDC;

typedef struct
{
  // Graphical
  bool tsa_ready;
  bool tsa_active;

  bool r2d_ready;
  bool r2d_active;

  bool error_show;
  bool info_show;
} SRE_GUI;

typedef struct
{
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
  uint8_t asms_state;
} SRE_States;

extern SRE_Pressures *sre_pressures;
extern SRE_Temperatures *sre_temperatures;
extern SRE_Battery *sre_battery;
extern SRE_Power *sre_power;
extern SRE_Vehicle_info *sre_vehicle_info;
extern SRE_Switch_States *sre_switches;
extern SRE_GUI *sre_gui;
extern SRE_States *sre_state;
extern SRE_SDC *sre_sdc;
extern SRE_ECU_Errors *sre_ecu_errors;

// Ignore unused variable warnings for these as they are only used on a need to use basis
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

enum ECU_ERROR_TYPE
{
  UNDEFINED_SCS,
  TEMP,
  MT_DRIVERINPUT,
  MT_ZOCO_FRONT,
  MT_ASB_STATUS,
  MT_STEERING,
  MT_STWHEEL_STATUS,
  MT_ZOCO_LEFT,
  MT_ZOCO_RIGHT,
  MT_DRIVECOMMAND,
  MT_ZOCO_REAR,
  MT_EXTERN_BUTTON,
  MT_SAF_FUSEBOARD,
  MT_BATPCB_INFO,
  MT_BATPCB_CONTROL,
  MT_BATPCB_SOC,
  MT_TEMPPCB_1,
  MT_TEMPPCB_2,
  MT_TEMPPCB_3,
  MT_TEMPPCB_4,
  MT_TEMPPCB_5,
  MT_TEMPPCB_6,
  MT_LSC_DASH_BUTTONS,
  MT_SAF_DASH_STATUS,
  ECU_SCS_DASH,
  ECU_SCS_ASB_STATUS,
  ECU_SCS_ZOCO_FRONT,
  ECU_SCS_ZOCO_LEFT,
  ECU_SCS_ZOCO_REAR,
  ECU_SCS_ZOCO_RIGHT,
  ECU_SCS_STWHEEL,
  ECU_SCS_FUSEBOARD,
};

static const char *ECU_ERROR_TYPE_STR[] = {
    "Undefined",
    "Temperature",
    "MT Driver Input",
    "MT ZoCo Front",
    "MT ASB Status",
    "MT Steering",
    "MT StWheel Status",
    "MT ZoCo Left",
    "MT ZoCo Right",
    "MT DriveCommand",
    "MT ZoCo Rear",
    "MT Ext Button",
    "MT SAF Fuseboard",
    "MT BatPCB Info",
    "MT BatPCB Control",
    "MT BatPCB SOC",
    "MT TempPCB 1",
    "MT TempPCB 2",
    "MT TempPCB 3",
    "MT TempPCB 4",
    "MT TempPCB 5",
    "MT TempPCB 6",
    "MT Dash Buttons",
    "MT Dash Status",
    "SCS Dash",
    "SCS ASB Status",
    "SCS ZoCo Front",
    "SCS ZoCo Left",
    "SCS ZoCo Rear",
    "SCS ZoCo Right",
    "SCS StWheel",
    "SCS Fuseboard",
};

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
  SDC_ERR,
  SCS_ERR,
};

static const char *ERROR_TYPES_STR[] = {
    "Undefined",
    "VCU",
    "SDC Open",
    "Battery",
    "ASB",
    "SCS ZOCO Front",
    "SCS ZOCO Rear",
    "SCS ZOCO Left",
    "SCS ZOCO Right",
    "SCS Fuseboard",
    "SCS DIO AS",
    "SCS DIO Dash",
    "SCS AIN F1",
    "SDC OPEN",
    "SCS ERROR",
};

enum VCU_ERROR_TYPES
{
  VCU_UNDEFINED,
  VCU_SCS,
  VCU_MSG_ERR,
};

static const char *VCU_ERROR_TYPES_STR[] = {
    "Undefined",
    "SCS Error",
    "Message Error",
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

static const char *SDC_ERROR_TYPES_STR[] = {
    "Undefined",
    "RES",
    "Motor Front Right",
    "ASB",
    "BSPD",
    "BOTS",
    "Motor Front Left",
    "Dash Button",
    "Inertia Switch",
    "Motor Rear Left",
    "MP TSAL",
    "Motor Rear Right",
    "HVD, BAT CON, TSMS",
    "HVD, BAT CON, TSMS",
    "HVD, BAT CON, TSMS",
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

static const char *BAT_ERROR_TYPES_STR[] = {
    "Undefined",
    "",
    "",
    "SDC Open",
    "",
    "",
    "",
    "ISO Error",
    "BMS Error",
    "IMD Error",
    "General Error",
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

static const char *ASB_ERROR_TYPES_STR[] = {
    "Undefined",
    "Watchdog Error",
    "ASB Pressures Invalid",
    "Brake Pressure Invalid",
    "EBS1 Pressure Low",
    "EBS2 Pressure Low",
    "ASB Pressure Low",
    "CAN / SCS Error",
    "EBS Triggered by AS",
    "RES SDC Open",
    "SDC Open",
    "Mech Stuck Error",
    "ASMS Turned Off",
    "EBS Triggered",
};

// array of pointers to the sub-error arrays
static const char **ERROR_SUB_TYPE_MAP[ERROR_TYPE_COUNT] = {
    NULL,                // UNDEFINED_ERROR
    VCU_ERROR_TYPES_STR, // VCU
    SDC_ERROR_TYPES_STR, // ERR_SDC_OPEN
    BAT_ERROR_TYPES_STR, // BAT_ERR
    ASB_ERROR_TYPES_STR, // ASB_ERROR
    NULL,                // SCS_ZOCO_FRONT
    NULL,                // SCS_ZOCO_REAR
    NULL,                // SCS_ZOCO_LEFT
    NULL,                // SCS_ZOCO_RIGHT
    NULL,                // SCS_FUSEBOARD
    NULL,                // SCS_DIO_AS
    NULL,                // SCS_DIO_DASH
    NULL,                // SCS_AIN_F1
    SDC_ERROR_TYPES_STR, // SDC_ERR
    ECU_ERROR_TYPE_STR,  // SCS_ERR
};

/* ---------- STATE MANAGEMENT ------------------- */

// ET
enum CAR_STATE
{
  UNDEFINED_C,
  WAIT_FOR_TSA_C,
  RTD_OFF,
  WAIT_FOR_RTD,
  DRIVE,
  LC_ON,
  SCS_ERROR
};

static const char *CAR_STATE_STR[] = {
    "Undefined",
    "Wait for TSA",
    "RTD Off",
    "Wait for RTD",
    "Drive",
    "LC On",
    "SCS Error"};

// HV
enum BAT_STATE
{
  UNDEFINED_B,
  START,
  BMS_RESET,
  SDC_OPEN,
  WAIT_FOR_TSA_B,
  TS_STARTUP,
  TSA,
  ISO_ERROR,
  BMS_ERROR,
  IMD_ERROR,
  BAT_ERROR
};
static const char *BAT_STATE_STR[] = {
    "Undefined",
    "Start",
    "BMS Reset",
    "SDC Open",
    "Wait for TSA",
    "TS Startup",
    "TSA",
    "ISO Error",
    "BMS Error",
    "IMD Error",
    "BAT Error"};

// DV
enum ASB_STATE
{
  UNINITALIZED,
  MV_CHECK,
  PASSIVE,
  DV_CHECK,
  MONITORING,
  EBS_TRIGGERED
};

static const char *ASB_STATE_STR[] = {
    "Uninitialized",
    "MV Check",
    "Passive",
    "DV Check",
    "Monitoring",
    "EBS Triggered"};

enum AMI_STATE
{
  MANUAL,
  ACCEL,
  SKIDPAD,
  TRACKDRIVE,
  BRAKETEST,
  INSPECTION,
  AUTOX
};
static const char *AMI_STATE_STR[] = {
    "Manual",
    "Accel",
    "Skidpad",
    "Trackdrive",
    "Braketest",
    "Inspection",
    "Autox"};

enum AS_STATE
{
  OFF = 1,
  READY = 2,
  DRIVING = 3,
  EMERGENCY = 4,
  FINISH = 5
};
static const char *AS_STATE_STR[] = {
    "undefined",
    "Off",
    "Ready",
    "Driving",
    "Emergency",
    "Finish"};

enum SERVICE_BRAKE_STATE
{
  DISENGAGED = 1,
  ENGAGED = 2,
  AVAILABLE = 3
};
static const char *SERVICE_BRAKE_STATE_STR[] = {
    "Disengaged",
    "Engaged",
    "Available"};

enum EBS_STATE
{
  UNAVAILABLE = 1,
  ARMED = 2,
  ACTIVATED = 3
};
static const char *EBS_STATE_STR[] = {
    "Unavailable",
    "Armed",
    "Activated"};

enum ASB_CHECK_SEQUENCE
{
  WATCHDOG_NOT_TRIGGERING,
  WATCHDOG_TRIGGERING,
  ASB_PRESS_OK,
  BP_BUILT_UP,
  CLOSE_SDC_WAIT_TSA,
  DEAC_EBS2,
  DEAC_EBS1_AC_EBS2,
  AC_EBS1_AND_2
};
static const char *ASB_CHECK_SEQUENCE_STR[] = {
    "undefined",
    "Watchdog not triggering",
    "Watchdog triggering",
    "ASB Press OK",
    "BP built up",
    "Close SDC wait TSA",
    "Deac EBS2",
    "Deac EBS1 Act EBS2",
    "Act EBS1 and 2"};

enum ASB_TRIGGER_CAUSE
{
  UNDEFINED = 0,
  WATCHDOG_ERROR = 1,
  ASB_PRESSURES_INVALID = 2,
  BRAKE_PRESSURE_INVALID = 3,
  EBS1_PRESSURE_LOW = 4,
  EBS2_PRESSURE_LOW = 5,
  ASB_PRESSURE_LOW = 6,
  CAN_SCS_ERROR = 7,
  EBS_TRIGGERED_BY_AS = 8,
  RES_SDC_OPEN = 9,
  SDC_OPEN_ASB = 10,
  MECHANICALLY_STUCK_ERROR = 11,
  ASMS_TURNED_OFF_IN_MONITORING = 12
};

static const char *ASB_TRIGGER_CAUSE_STR[] = {
    "undefined",
    "Watchdog error",
    "ASB Pressures invalid",
    "Brake Pressure invalid",
    "EBS1 Pressure low",
    "EBS2 Pressure low",
    "ASB Pressure low",
    "CAN / SCS Error",
    "EBS triggered by AS",
    "RES SDC open",
    "SDC open",
    "Mech Stuck Error",
    "ASMS Turned Off"};
#pragma GCC diagnostic pop

// END unused variable warnings

#endif // SRE_LOGIC_H
