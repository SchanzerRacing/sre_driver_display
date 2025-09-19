/*
 *  This file contains logic functions.
 */
#include <gtk/gtk.h>
#include <stdio.h>
#include <time.h>

#include "headers/sre_can.h"
#include "headers/sre_logic.h"
#include "headers/debug_panel.h"
#include "headers/endurance_panel.h"
#include "headers/vehicleinfo_panel.h"
#include "headers/objects.h"

uint32_t displayCallbackCounter = 0;

uint8_t currentPanel = 0;

GObject *tsa_label_array[4];
GObject *r2d_label_array[4];

GObject *label_tsa_current = NULL;
GObject *label_r2d_current = NULL;

SRE_Pressures *sre_pressures;
SRE_Temperatures *sre_temperatures;
SRE_Battery *sre_battery;
SRE_Power *sre_power;
SRE_Vehicle_info *sre_vehicle_info;
SRE_Switch_States *sre_switches;
SRE_GUI *sre_gui;
SRE_States *sre_state;
SRE_SDC *sre_sdc;
SRE_ECU_Errors *sre_ecu_errors;

SRE_error *vehicle_errors[MAX_ERRORS] = {NULL};

void init_sre_logic()
{
	// This could be completely skipped theoretically?
	// everytime we draw a panel we can just update the pointer to the current panels tsa label?
	// if i'm not mistaken this could be done for all panels that do the same.
	// Keeping this block unused for now for possible further use if panels will be refactored into overlays that get shown and hidden
	// tsa_label_array[0] = NULL;
	// tsa_label_array[1] = NULL;
	// tsa_label_array[2] = NULL;
	// tsa_label_array[3] = NULL;

	// r2d_label_array[0] = NULL;
	// r2d_label_array[1] = NULL;
	// r2d_label_array[2] = NULL;
	// r2d_label_array[3] = NULL;

	// INITIALIZE SRE Structs
	printf("init_sre states\n");
	sre_pressures = (SRE_Pressures *)malloc(sizeof(SRE_Pressures));
	if (sre_pressures == NULL)
	{
		printf("Failed to allocate memory for sre_pressures\n");
		return;
	}
	sre_temperatures = (SRE_Temperatures *)malloc(sizeof(SRE_Temperatures));
	if (sre_temperatures == NULL)
	{
		printf("Failed to allocate memory for sre_temperatures\n");
		return;
	}
	sre_battery = (SRE_Battery *)malloc(sizeof(SRE_Battery));
	if (sre_battery == NULL)
	{
		printf("Failed to allocate memory for sre_battery\n");
		return;
	}
	sre_power = (SRE_Power *)malloc(sizeof(SRE_Power));
	if (sre_power == NULL)
	{
		printf("Failed to allocate memory for sre_power\n");
		return;
	}
	sre_vehicle_info = (SRE_Vehicle_info *)malloc(sizeof(SRE_Vehicle_info));
	if (sre_vehicle_info == NULL)
	{
		printf("Failed to allocate memory for sre_vehicle_info\n");
		return;
	}
	sre_switches = (SRE_Switch_States *)malloc(sizeof(SRE_Switch_States));
	if (sre_switches == NULL)
	{
		printf("Failed to allocate memory for sre_switches\n");
		return;
	}
	sre_gui = (SRE_GUI *)malloc(sizeof(SRE_GUI));
	if (sre_gui == NULL)
	{
		printf("Failed to allocate memory for sre_gui\n");
		return;
	}
	sre_state = (SRE_States *)malloc(sizeof(SRE_States));
	if (sre_state == NULL)
	{
		printf("Failed to allocate memory for sre_state\n");
		return;
	}
	sre_sdc = (SRE_SDC *)malloc(sizeof(SRE_SDC));
	if (sre_sdc == NULL)
	{
		printf("Failed to allocate memory for sre_sdc\n");
		return;
	}
	sre_ecu_errors = (SRE_ECU_Errors *)malloc(sizeof(SRE_ECU_Errors));
	if (sre_ecu_errors == NULL)
	{
		printf("Failed to allocate memory for sre_ecu_errors\n");
		return;
	}

	// Pressures
	sre_pressures->brake_pressure_1 = 0;
	sre_pressures->brake_pressure_2 = 0;
	sre_pressures->asb_pressure_1 = 0;
	sre_pressures->asb_pressure_2 = 0;

	// Temperatures
	sre_temperatures->temp_per = 0;
	sre_temperatures->temp_pef = 0;
	sre_temperatures->temp_motor_fl = 0;
	sre_temperatures->temp_motor_fr = 0;
	sre_temperatures->temp_motor_rl = 0;
	sre_temperatures->temp_motor_rr = 0;

	// Battery
	sre_battery->bat_soc = 10.0;
	sre_battery->bat_temp_max = 53;
	sre_battery->bat_temp_min = 48;
	sre_battery->bat_volt_max = 3.0;
	sre_battery->bat_volt_min = 2.6;

	// Power Measurement
	sre_power->sdc_power = 0;
	sre_power->lv_power = 0;
	sre_power->hv_power = 0;
	sre_power->epos_power = 0;

	// Vehicle Info
	sre_vehicle_info->car_speed = 0;
	sre_vehicle_info->car_speed_gps = 0;
	sre_vehicle_info->car_accel_x = 0;
	sre_vehicle_info->car_accel_z = 0;

	// Switch States
	sre_switches->acu_switch = false;
	sre_switches->asb_switch = false;
	sre_switches->dash_switch = false;
	sre_switches->epos_lc_switch = false;
	sre_switches->fan_l_switch = false;
	sre_switches->fan_r_switch = false;
	sre_switches->sbg_switch = false;
	sre_switches->vcu_switch = false;
	sre_switches->pef_switch = false;
	sre_switches->per_switch = false;
	sre_switches->pumps_switch = false;
	sre_switches->sensors_switch = false;

	// States
	sre_state->car_state = UNDEFINED_C;
	sre_state->bat_state = UNDEFINED_B;
	sre_state->asb_state = UNINITALIZED;
	sre_state->ami_state = MANUAL;
	sre_state->as_state = OFF;
	sre_state->sbs_state = DISENGAGED;
	sre_state->ebs_state = 0;
	sre_state->asb_check_sequence = 0;
	sre_state->asb_trigger_cause = 0;

	// SDC States
	sre_sdc->res = false;
	sre_sdc->motor_fr = false;
	sre_sdc->asb = false;
	sre_sdc->bspd = false;
	sre_sdc->bots = false;
	sre_sdc->motor_fl = false;
	sre_sdc->dash = false;
	sre_sdc->inertia = false;
	sre_sdc->motor_rl = false;
	sre_sdc->mainhoop = false;
	sre_sdc->motor_rr = false;
	sre_sdc->hvd = false;
	sre_sdc->ts_connector = false;
	sre_sdc->tsms = false;

	// ECU Errors
	sre_ecu_errors->temp = false;
	sre_ecu_errors->mt_driver_input = false;
	sre_ecu_errors->mt_zoco_front = false;
	sre_ecu_errors->mt_asb_status = false;
	sre_ecu_errors->mt_steering = false;
	sre_ecu_errors->mt_st_wheel_status = false;
	sre_ecu_errors->mt_zoco_left = false;
	sre_ecu_errors->mt_zoco_right = false;
	sre_ecu_errors->mt_drive_command = false;
	sre_ecu_errors->mt_zoco_rear = false;
	sre_ecu_errors->mt_extern_button = false;
	sre_ecu_errors->mt_saf_fuseboard = false;
	sre_ecu_errors->mt_bat_pcb_info = false;
	sre_ecu_errors->mt_bat_pcb_control = false;
	sre_ecu_errors->mt_bat_pcb_soc = false;
	sre_ecu_errors->mt_temp_pcb_1 = false;
	sre_ecu_errors->mt_temp_pcb_2 = false;
	sre_ecu_errors->mt_temp_pcb_3 = false;
	sre_ecu_errors->mt_temp_pcb_4 = false;
	sre_ecu_errors->mt_temp_pcb_5 = false;
	sre_ecu_errors->mt_temp_pcb_6 = false;
	sre_ecu_errors->mt_lsc_dash_buttons = false;
	sre_ecu_errors->mt_saf_dash_status = false;
	sre_ecu_errors->scs_dash = false;
	sre_ecu_errors->scs_asb_status = false;
	sre_ecu_errors->scs_zoco_front = false;
	sre_ecu_errors->scs_zoco_left = false;
	sre_ecu_errors->scs_zoco_rear = false;
	sre_ecu_errors->scs_zoco_right = false;
	sre_ecu_errors->scs_st_wheel = false;
	sre_ecu_errors->scs_fuseboard = false;

	// Graphical
	sre_gui->tsa_ready = false;
	sre_gui->tsa_active = false;

	sre_gui->r2d_ready = false;
	sre_gui->r2d_active = false;

	sre_gui->error_show = false;
	sre_gui->info_show = false;

	// printf("sre_state batstate: %s\n", BAT_STATE_STR[sre_state->bat_state]);
}

gboolean sre_run_display()
{
	displayCallbackCounter += 1;
	if ((displayCallbackCounter % 10) == 0)
	{
		// printf("sre_run_display, %d\n", displayCallbackCounter);
	}

	tsa_logic();
	r2d_logic();

	error_logic();
	error_label_update();
	error_panel_update();

	info_logic();

#if USE_CAN
	// Gathers all the data from the CAN messages and updates the states
	state_update();
#endif

	// Updates the graphical elements
	graphical_update();

	// Updates the labels
	label_update();

	return G_SOURCE_CONTINUE;
}

void state_update()
{
	// printf("state_update\n");
	// PRESSURES
	sre_pressures->brake_pressure_1 = LOG_BrakePressures.front;
	sre_pressures->brake_pressure_2 = LOG_BrakePressures.rear;
	sre_pressures->asb_pressure_1 = DV_ASB_Pressure.pressure_1;
	sre_pressures->asb_pressure_2 = DV_ASB_Pressure.pressure_2;

	// TEMPERATURES
	if (GW_PE_RearRight.temp_igbt > GW_PE_RearLeft.temp_igbt)
	{
		sre_temperatures->temp_per = GW_PE_RearRight.temp_igbt;
	}
	else
	{
		sre_temperatures->temp_per = GW_PE_RearLeft.temp_igbt;
	}

	if (GW_PE_FrontRight.temp_igbt > GW_PE_FrontLeft.temp_igbt)
	{
		sre_temperatures->temp_pef = GW_PE_FrontRight.temp_igbt;
	}
	else
	{
		sre_temperatures->temp_pef = GW_PE_FrontLeft.temp_igbt;
	}

	sre_temperatures->temp_motor_fl = GW_PE_FrontLeft.temp_motor;
	sre_temperatures->temp_motor_fr = GW_PE_FrontRight.temp_motor;
	sre_temperatures->temp_motor_rl = GW_PE_RearLeft.temp_motor;
	sre_temperatures->temp_motor_rr = GW_PE_RearRight.temp_motor;

	// BATTERY
	sre_battery->bat_soc = GW_Battery_Status.soc_internal;
	sre_battery->bat_temp_max = GW_Battery_Cells.temp_max;
	sre_battery->bat_temp_min = GW_Battery_Cells.temp_min;
	sre_battery->bat_volt_max = GW_Battery_Cells.voltage_max;
	sre_battery->bat_volt_min = GW_Battery_Cells.voltage_min;

	// POWER MEASUREMENT
	sre_power->sdc_power = LOG_Fuse_Currents.sdc_current;
	sre_power->lv_power = LOG_LEM.lv;
	sre_power->hv_power = GW_Battery_Status.power;
	sre_power->epos_power = LOG_Fuse_Currents.epos_current;

	// VEHICLE INFO
	sre_vehicle_info->car_speed = HSC_Vehicle_Status.velocity_ms;
	sre_vehicle_info->car_speed_gps = HSC_SBG_EKF_VEL_BODY.velocity_x;
	sre_vehicle_info->car_accel_x = HSC_SBG_ACCEL.accel_x;
	sre_vehicle_info->car_accel_y = HSC_SBG_ACCEL.accel_y;
	sre_vehicle_info->car_accel_z = HSC_SBG_ACCEL.accel_z;

	// Switches
	sre_switches->acu_switch = PARC_FUSE_States.fb_acu;
	sre_switches->asb_switch = PARC_FUSE_States.fb_asb;
	sre_switches->dash_switch = PARC_FUSE_States.fb_dash;
	sre_switches->epos_lc_switch = PARC_FUSE_States.fb_epos;
	sre_switches->fan_l_switch = PARC_FUSE_States.fb_fan_l;
	sre_switches->fan_r_switch = PARC_FUSE_States.fb_fan_r;
	sre_switches->sbg_switch = PARC_FUSE_States.fb_gps;
	sre_switches->vcu_switch = PARC_FUSE_States.fb_vcu;
	sre_switches->pef_switch = PARC_FUSE_States.fb_pef;
	sre_switches->per_switch = PARC_FUSE_States.fb_per;
	sre_switches->pumps_switch = PARC_FUSE_States.fb_pumps;
	sre_switches->sensors_switch = PARC_FUSE_States.fb_sensors;

	// STATES
	sre_state->car_state = HSC_Vehicle_Status.state;
	sre_state->bat_state = GW_Battery_Status.state;
	sre_state->as_state = DV_System_Status.as_state;
	sre_state->ami_state = DV_AMI_Status.state;
	sre_state->asb_state = DV_ASB_Status.state;
	sre_state->sbs_state = DV_ASB_Status.service_brake_state;
	sre_state->ebs_state = DV_ASB_Status.ebs_state;
	sre_state->asb_checkup_complete = DV_ASB_Status.checkup_complete;
	sre_state->asb_check_sequence = DV_ASB_Status.check_sequence;
	sre_state->asb_trigger_cause = DV_ASB_Status.trigger_cause;

	// Fuses
	sre_sdc->res = LOG_SDC.sdc_res;
	sre_sdc->motor_fr = LOG_SDC.sdc_fr;
	sre_sdc->asb = LOG_SDC.sdc_asb;
	sre_sdc->bspd = LOG_SDC.sdc_bspd;
	sre_sdc->bots = LOG_SDC.sdc_bots;
	sre_sdc->motor_fl = LOG_SDC.sdc_fl;
	sre_sdc->dash = LOG_SDC.sdc_dash;
	sre_sdc->inertia = LOG_SDC.sdc_inertia;
	sre_sdc->motor_rl = LOG_SDC.sdc_rl;
	sre_sdc->mainhoop = LOG_SDC.sdc_tsal;
	sre_sdc->motor_rr = LOG_SDC.sdc_rr;
	sre_sdc->hvd = LOG_SDC.sdc_hvd;
	sre_sdc->ts_connector = LOG_SDC.sdc_ts_connector;
	sre_sdc->tsms = LOG_SDC.sdc_tsms;

	// ECU Errors
	sre_ecu_errors->temp = LOG_ECU_Errors.temp;
	sre_ecu_errors->mt_driver_input = LOG_ECU_Errors.mt_driver_input;
	sre_ecu_errors->mt_zoco_front = LOG_ECU_Errors.mt_zoco_front;
	sre_ecu_errors->mt_asb_status = LOG_ECU_Errors.mt_asb_status;
	sre_ecu_errors->mt_steering = LOG_ECU_Errors.mt_steering;
	sre_ecu_errors->mt_st_wheel_status = LOG_ECU_Errors.mt_st_wheel_status;
	sre_ecu_errors->mt_zoco_left = LOG_ECU_Errors.mt_zoco_left;
	sre_ecu_errors->mt_zoco_right = LOG_ECU_Errors.mt_zoco_right;
	sre_ecu_errors->mt_drive_command = LOG_ECU_Errors.mt_drive_command;
	sre_ecu_errors->mt_zoco_rear = LOG_ECU_Errors.mt_zoco_rear;
	sre_ecu_errors->mt_extern_button = LOG_ECU_Errors.mt_extern_button;
	sre_ecu_errors->mt_saf_fuseboard = LOG_ECU_Errors.mt_saf_fuseboard;
	sre_ecu_errors->mt_bat_pcb_info = LOG_ECU_Errors.mt_bat_pcb_info;
	sre_ecu_errors->mt_bat_pcb_control = LOG_ECU_Errors.mt_bat_pcb_control;
	sre_ecu_errors->mt_bat_pcb_soc = LOG_ECU_Errors.mt_bat_pcb_soc;
	sre_ecu_errors->mt_temp_pcb_1 = LOG_ECU_Errors.mt_temp_pcb_1;
	sre_ecu_errors->mt_temp_pcb_2 = LOG_ECU_Errors.mt_temp_pcb_2;
	sre_ecu_errors->mt_temp_pcb_3 = LOG_ECU_Errors.mt_temp_pcb_3;
	sre_ecu_errors->mt_temp_pcb_4 = LOG_ECU_Errors.mt_temp_pcb_4;
	sre_ecu_errors->mt_temp_pcb_5 = LOG_ECU_Errors.mt_temp_pcb_5;
	sre_ecu_errors->mt_temp_pcb_6 = LOG_ECU_Errors.mt_temp_pcb_6;
	sre_ecu_errors->mt_lsc_dash_buttons = LOG_ECU_Errors.mt_lsc_dash_buttons;
	sre_ecu_errors->mt_saf_dash_status = LOG_ECU_Errors.mt_saf_dash_status;
	sre_ecu_errors->scs_dash = LOG_ECU_Errors.scs_dash;
	sre_ecu_errors->scs_asb_status = LOG_ECU_Errors.scs_asb_status;
	sre_ecu_errors->scs_zoco_front = LOG_ECU_Errors.scs_zoco_front;
	sre_ecu_errors->scs_zoco_left = LOG_ECU_Errors.scs_zoco_left;
	sre_ecu_errors->scs_zoco_rear = LOG_ECU_Errors.scs_zoco_rear;
	sre_ecu_errors->scs_zoco_right = LOG_ECU_Errors.scs_zoco_right;
	sre_ecu_errors->scs_st_wheel = LOG_ECU_Errors.scs_st_wheel;
	sre_ecu_errors->scs_fuseboard = LOG_ECU_Errors.scs_fuseboard;
}

void label_update()
{
	// printf("label_update\n");
	// DEBUG PANEL
	if (currentPanel == DEBUG)
	{
		// PRESSURES
		char buffer[100];
		sprintf(buffer, "%.0f mBar", sre_pressures->brake_pressure_1);
		gtk_label_set_text(GTK_LABEL(label_brake_pressure_1), buffer);
		sprintf(buffer, "%.0f mBar", sre_pressures->brake_pressure_2);
		gtk_label_set_text(GTK_LABEL(label_brake_pressure_2), buffer);

		sprintf(buffer, "%.0f mBar", sre_pressures->asb_pressure_1);
		gtk_label_set_text(GTK_LABEL(label_asb_pressure_1), buffer);
		sprintf(buffer, "%.0f mBar", sre_pressures->asb_pressure_2);
		gtk_label_set_text(GTK_LABEL(label_asb_pressure_2), buffer);

		// POWER MEASUREMENT
		sprintf(buffer, "%.0f mA", sre_power->sdc_power);
		gtk_label_set_text(GTK_LABEL(label_sdc_power), buffer);
		sprintf(buffer, "%.0f mA", sre_power->lv_power);
		gtk_label_set_text(GTK_LABEL(label_lv_power), buffer);
		sprintf(buffer, "%.1f kW", sre_power->hv_power);
		gtk_label_set_text(GTK_LABEL(label_hv_power), buffer);
		sprintf(buffer, "%.0f mA", sre_power->epos_power);
		gtk_label_set_text(GTK_LABEL(label_epos_power), buffer);

		// STATES
		sprintf(buffer, "%s", CAR_STATE_STR[sre_state->car_state]);
		gtk_label_set_text(GTK_LABEL(label_car_state), buffer);
		sprintf(buffer, "%s", BAT_STATE_STR[sre_state->bat_state]);
		gtk_label_set_text(GTK_LABEL(label_bat_state), buffer);
		sprintf(buffer, "%s", AS_STATE_STR[sre_state->as_state]);
		gtk_label_set_text(GTK_LABEL(label_as_state), buffer);
		sprintf(buffer, "%s", ASB_STATE_STR[sre_state->asb_state]);
		gtk_label_set_text(GTK_LABEL(label_asb_state), buffer);
		sprintf(buffer, "%s", ASB_CHECK_SEQUENCE_STR[sre_state->asb_check_sequence]);
		gtk_label_set_text(GTK_LABEL(label_asb_check_sequence), buffer);
		sprintf(buffer, "%s", ASB_TRIGGER_CAUSE_STR[sre_state->asb_trigger_cause]);
		gtk_label_set_text(GTK_LABEL(label_asb_trigger_cause), buffer);

		// SWITCH STATES
		sprintf(buffer, "%s", sre_switches->acu_switch ? "ON" : "OFF");
		gtk_label_set_text(GTK_LABEL(label_acu_switch_state), buffer);
		sprintf(buffer, "%s", sre_switches->asb_switch ? "ON" : "OFF");
		gtk_label_set_text(GTK_LABEL(label_asb_switch_state), buffer);
		sprintf(buffer, "%s", sre_switches->dash_switch ? "ON" : "OFF");
		gtk_label_set_text(GTK_LABEL(label_dash_switch_state), buffer);
		sprintf(buffer, "%s", sre_switches->epos_lc_switch ? "ON" : "OFF");
		gtk_label_set_text(GTK_LABEL(label_epos_switch_state), buffer);
		sprintf(buffer, "%s", sre_switches->fan_l_switch ? "ON" : "OFF");
		gtk_label_set_text(GTK_LABEL(label_fan_l_switch_state), buffer);
		sprintf(buffer, "%s", sre_switches->fan_r_switch ? "ON" : "OFF");
		gtk_label_set_text(GTK_LABEL(label_fan_r_switch_state), buffer);
		sprintf(buffer, "%s", sre_switches->sbg_switch ? "ON" : "OFF");
		gtk_label_set_text(GTK_LABEL(label_sbg_switch_state), buffer);
		sprintf(buffer, "%s", sre_switches->vcu_switch ? "ON" : "OFF");
		gtk_label_set_text(GTK_LABEL(label_vcu_switch_state), buffer);
		sprintf(buffer, "%s", sre_switches->pef_switch ? "ON" : "OFF");
		gtk_label_set_text(GTK_LABEL(label_pef_switch_state), buffer);
		sprintf(buffer, "%s", sre_switches->per_switch ? "ON" : "OFF");
		gtk_label_set_text(GTK_LABEL(label_per_switch_state), buffer);
		sprintf(buffer, "%s", sre_switches->pumps_switch ? "ON" : "OFF");
		gtk_label_set_text(GTK_LABEL(label_pumps_switch_state), buffer);
		sprintf(buffer, "%s", sre_switches->sensors_switch ? "ON" : "OFF");
		gtk_label_set_text(GTK_LABEL(label_sensors_switch_state), buffer);
	}
	else // ENDURANCE PANEL
		if (currentPanel == ENDURANCE)
		{
			char buffer[100];
			sprintf(buffer, "%s", CAR_STATE_STR[sre_state->car_state]);
			gtk_label_set_text(GTK_LABEL(info_carstate_endu), buffer);

			sprintf(buffer, "%.0f%%", sre_battery->bat_soc);
			gtk_label_set_text(GTK_LABEL(info_bat_soc_endu), buffer);
			if (sre_battery->bat_soc <= CRITICAL_SOC)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_bat_soc_endu), "blink-critical");
			}
			else if (sre_battery->bat_soc <= WARNING_SOC)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_bat_soc_endu), "blink-warning");
			}
			else
			{
				gtk_widget_remove_css_class(GTK_WIDGET(info_bat_soc_endu), "blink-warning");
				gtk_widget_remove_css_class(GTK_WIDGET(info_bat_soc_endu),
																		"blink-critical");
			}

			sprintf(buffer, "%.0f°c", sre_battery->bat_temp_max);
			if (sre_battery->bat_temp_max >= CRITICAL_BAT_TEMP)
			{
				gtk_widget_remove_css_class(GTK_WIDGET(info_bat_temp_max_endu),
																		"blink-warning");
				gtk_widget_add_css_class(GTK_WIDGET(info_bat_temp_max_endu),
																 "blink-critical");
			}
			else if (sre_battery->bat_temp_max >= WARNING_BAT_TEMP)
			{
				gtk_widget_remove_css_class(GTK_WIDGET(info_bat_temp_max_endu),
																		"blink-critical");
				gtk_widget_add_css_class(GTK_WIDGET(info_bat_temp_max_endu),
																 "blink-warning");
			}
			else
			{
				gtk_widget_remove_css_class(GTK_WIDGET(info_bat_temp_max_endu),
																		"blink-warning");
				gtk_widget_remove_css_class(GTK_WIDGET(info_bat_temp_max_endu),
																		"blink-critical");
			}

			gtk_label_set_text(GTK_LABEL(info_bat_temp_max_endu), buffer);

			sprintf(buffer, "%.0f°c", sre_temperatures->temp_pef);
			gtk_label_set_text(GTK_LABEL(info_temp_pef_endu), buffer);
			if (sre_temperatures->temp_pef >= CRITICAL_PE_TEMP)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_temp_pef_endu), "blink-critical");
			}
			else if (sre_temperatures->temp_pef >= WARNING_PE_TEMP)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_temp_pef_endu), "blink-warning");
			}
			else
			{
				gtk_widget_remove_css_class(GTK_WIDGET(info_temp_pef_endu),
																		"blink-warning");
				gtk_widget_remove_css_class(GTK_WIDGET(info_temp_pef_endu),
																		"blink-critical");
			}

			sprintf(buffer, "%.0f°c", sre_temperatures->temp_per);
			gtk_label_set_text(GTK_LABEL(info_temp_per_endu), buffer);
			if (sre_temperatures->temp_per >= CRITICAL_PE_TEMP)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_temp_per_endu), "blink-critical");
			}
			else if (sre_temperatures->temp_per >= WARNING_PE_TEMP)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_temp_per_endu), "blink-warning");
			}
			else
			{
				gtk_widget_remove_css_class(GTK_WIDGET(info_temp_per_endu),
																		"blink-warning");
				gtk_widget_remove_css_class(GTK_WIDGET(info_temp_per_endu),
																		"blink-critical");
			}

			sprintf(buffer, "%.0f°c", sre_temperatures->temp_motor_fl);
			gtk_label_set_text(GTK_LABEL(info_temp_motor_fl_endu), buffer);
			if (sre_temperatures->temp_motor_fl >= CRITICAL_MOTOR_TEMP)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_temp_motor_fl_endu),
																 "blink-critical");
			}
			else if (sre_temperatures->temp_motor_fl >= WARNING_MOTOR_TEMP)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_temp_motor_fl_endu),
																 "blink-warning");
			}
			else
			{
				gtk_widget_remove_css_class(GTK_WIDGET(info_temp_motor_fl_endu),
																		"blink-warning");
				gtk_widget_remove_css_class(GTK_WIDGET(info_temp_motor_fl_endu),
																		"blink-critical");
			}

			sprintf(buffer, "%.0f°c", sre_temperatures->temp_motor_fr);
			gtk_label_set_text(GTK_LABEL(info_temp_motor_fr_endu), buffer);
			if (sre_temperatures->temp_motor_fr >= CRITICAL_MOTOR_TEMP)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_temp_motor_fr_endu),
																 "blink-critical");
			}
			else if (sre_temperatures->temp_motor_fr >= WARNING_MOTOR_TEMP)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_temp_motor_fr_endu),
																 "blink-warning");
			}
			else
			{
				gtk_widget_remove_css_class(GTK_WIDGET(info_temp_motor_fr_endu),
																		"blink-warning");
				gtk_widget_remove_css_class(GTK_WIDGET(info_temp_motor_fr_endu),
																		"blink-critical");
			}

			sprintf(buffer, "%.0f°c", sre_temperatures->temp_motor_rl);
			gtk_label_set_text(GTK_LABEL(info_temp_motor_rl_endu), buffer);
			if (sre_temperatures->temp_motor_rl >= CRITICAL_MOTOR_TEMP)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_temp_motor_rl_endu),
																 "blink-critical");
			}
			else if (sre_temperatures->temp_motor_rl >= WARNING_MOTOR_TEMP)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_temp_motor_rl_endu),
																 "blink-warning");
			}
			else
			{
				gtk_widget_remove_css_class(GTK_WIDGET(info_temp_motor_rl_endu),
																		"blink-warning");
				gtk_widget_remove_css_class(GTK_WIDGET(info_temp_motor_rl_endu),
																		"blink-critical");
			}

			sprintf(buffer, "%.0f°c", sre_temperatures->temp_motor_rr);
			gtk_label_set_text(GTK_LABEL(info_temp_motor_rr_endu), buffer);
			if (sre_temperatures->temp_motor_rr >= CRITICAL_MOTOR_TEMP)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_temp_motor_rr_endu),
																 "blink-critical");
			}
			else if (sre_temperatures->temp_motor_rr >= WARNING_MOTOR_TEMP)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_temp_motor_rr_endu),
																 "blink-warning");
			}
			else
			{
				gtk_widget_remove_css_class(GTK_WIDGET(info_temp_motor_rr_endu),
																		"blink-warning");
				gtk_widget_remove_css_class(GTK_WIDGET(info_temp_motor_rr_endu),
																		"blink-critical");
			}
		}
		else if (currentPanel == VEHICLEINFO)
		{
			char buffer[100];

			// PE TEMPS
			sprintf(buffer, "%.1f°c", sre_temperatures->temp_per);
			gtk_label_set_text(GTK_LABEL(info_temp_per_vehicleinfo), buffer);
			sprintf(buffer, "%.1f°c", sre_temperatures->temp_pef);
			gtk_label_set_text(GTK_LABEL(info_temp_pef_vehicleinfo), buffer);

			// MOTOR TEMPS
			sprintf(buffer, "%.1f°c", sre_temperatures->temp_motor_fl);
			gtk_label_set_text(GTK_LABEL(info_temp_motor_fl_vehicleinfo), buffer);
			sprintf(buffer, "%.1f°c", sre_temperatures->temp_motor_fr);
			gtk_label_set_text(GTK_LABEL(info_temp_motor_fr_vehicleinfo), buffer);
			sprintf(buffer, "%.1f°c", sre_temperatures->temp_motor_rl);
			gtk_label_set_text(GTK_LABEL(info_temp_motor_rl_vehicleinfo), buffer);
			sprintf(buffer, "%.1f°c", sre_temperatures->temp_motor_rr);
			gtk_label_set_text(GTK_LABEL(info_temp_motor_rr_vehicleinfo), buffer);

			// BATTERY
			sprintf(buffer, "%.0f%%", sre_battery->bat_soc);
			gtk_label_set_text(GTK_LABEL(info_bat_soc_vehicleinfo), buffer);
			if (sre_battery->bat_soc <= CRITICAL_SOC)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_bat_soc_vehicleinfo),
																 "blink-critical");
			}
			else if (sre_battery->bat_soc <= WARNING_SOC)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_bat_soc_vehicleinfo),
																 "blink-warning");
			}
			else
			{
				gtk_widget_remove_css_class(GTK_WIDGET(info_bat_soc_vehicleinfo),
																		"blink-warning");
				gtk_widget_remove_css_class(GTK_WIDGET(info_bat_soc_vehicleinfo),
																		"blink-critical");
			}

			sprintf(buffer, "%.0f°c", sre_battery->bat_temp_max);
			gtk_label_set_text(GTK_LABEL(info_bat_temp_max_vehicleinfo), buffer);
			if (sre_battery->bat_temp_max >= CRITICAL_BAT_TEMP)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_bat_temp_max_vehicleinfo),
																 "blink-critical");
			}
			else if (sre_battery->bat_temp_max >= WARNING_BAT_TEMP)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_bat_temp_max_vehicleinfo),
																 "blink-warning");
			}
			else
			{
				gtk_widget_remove_css_class(GTK_WIDGET(info_bat_temp_max_vehicleinfo),
																		"blink-warning");
				gtk_widget_remove_css_class(GTK_WIDGET(info_bat_temp_max_vehicleinfo),
																		"blink-critical");
			}

			sprintf(buffer, "%.0f°c", sre_battery->bat_temp_min);
			gtk_label_set_text(GTK_LABEL(info_bat_temp_min_vehicleinfo), buffer);
			if (sre_battery->bat_temp_min >= CRITICAL_BAT_TEMP)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_bat_temp_min_vehicleinfo),
																 "blink-critical");
			}
			else if (sre_battery->bat_temp_min >= WARNING_BAT_TEMP)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_bat_temp_min_vehicleinfo),
																 "blink-warning");
			}
			else
			{
				gtk_widget_remove_css_class(GTK_WIDGET(info_bat_temp_min_vehicleinfo),
																		"blink-warning");
				gtk_widget_remove_css_class(GTK_WIDGET(info_bat_temp_min_vehicleinfo),
																		"blink-critical");
			}

			sprintf(buffer, "%.2fv", sre_battery->bat_volt_max);
			gtk_label_set_text(GTK_LABEL(info_bat_voltage_max_vehicleinfo), buffer);
			if (sre_battery->bat_volt_max <= CRITICAL_VOLT)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_bat_voltage_max_vehicleinfo),
																 "blink-critical");
			}
			else if (sre_battery->bat_volt_max <= WARNING_VOLT)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_bat_voltage_max_vehicleinfo),
																 "blink-warning");
			}
			else
			{
				gtk_widget_remove_css_class(GTK_WIDGET(info_bat_voltage_max_vehicleinfo),
																		"blink-warning");
				gtk_widget_remove_css_class(GTK_WIDGET(info_bat_voltage_max_vehicleinfo),
																		"blink-critical");
			}

			sprintf(buffer, "%.2fv", sre_battery->bat_volt_min);
			gtk_label_set_text(GTK_LABEL(info_bat_voltage_min_vehicleinfo), buffer);
			if (sre_battery->bat_volt_min <= CRITICAL_VOLT)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_bat_voltage_min_vehicleinfo),
																 "blink-critical");
			}
			else if (sre_battery->bat_volt_min <= WARNING_VOLT)
			{
				gtk_widget_add_css_class(GTK_WIDGET(info_bat_voltage_min_vehicleinfo),
																 "blink-warning");
			}
			else
			{
				gtk_widget_remove_css_class(GTK_WIDGET(info_bat_voltage_min_vehicleinfo),
																		"blink-warning");
				gtk_widget_remove_css_class(GTK_WIDGET(info_bat_voltage_min_vehicleinfo),
																		"blink-critical");
			}

			// POWER MEASUREMENT
			sprintf(buffer, "%.0f", sre_power->hv_power);
			gtk_label_set_text(GTK_LABEL(info_hv_power_vehicleinfo), buffer);

			// VEHICLE INFO
			sprintf(buffer, "%.0f", sre_vehicle_info->car_speed * 3.6);
			gtk_label_set_text(GTK_LABEL(info_car_speed_vehicleinfo), buffer);

			// STATES
			sprintf(buffer, "%s", CAR_STATE_STR[sre_state->car_state]);
			gtk_label_set_text(GTK_LABEL(info_carstate_vehicleinfo), buffer);
		}
}

void error_label_update()
{
	// printf("error_label_update\n");
	uint8_t label_array_count = 0;

	for (int i = 0; i < ERROR_LABEL_COUNT; i++)
	{
		if (vehicle_errors[i] != NULL)
		{
			char buffer[100];
			// get error type string
			const char *error_type_str =
					ERROR_TYPES_STR[vehicle_errors[i]->error_type];

			// get sub error type string
			const char *sub_error_str = "N/A"; // default if no subtype exists
			if (vehicle_errors[i]->error_type < ERROR_TYPE_COUNT &&
					ERROR_SUB_TYPE_MAP[vehicle_errors[i]->error_type] != NULL &&
					vehicle_errors[i]->sub_error_type < ERROR_SUB_TYPE_COUNT) // avoid out of bounds
			{
				printf("error_type: %d, sub_error_type: %d, time_elapsed: %ld\n",
							 vehicle_errors[i]->error_type, vehicle_errors[i]->sub_error_type,
							 (vehicle_errors[i]->last_seen - (uint64_t)time(NULL)));
				sub_error_str =
						ERROR_SUB_TYPE_MAP[vehicle_errors[i]->error_type][vehicle_errors[i]
																																	->sub_error_type];
			}
			sprintf(buffer, "%s", error_type_str);
			gtk_label_set_text(GTK_LABEL(error_array[label_array_count][0]), buffer);
			sprintf(buffer, "%s", sub_error_str);
			gtk_label_set_text(GTK_LABEL(error_array[label_array_count][1]), buffer);

			label_array_count++;
		}
	}

	for (; label_array_count < ERROR_LABEL_COUNT; label_array_count++)
	{
		gtk_label_set_text(GTK_LABEL(error_array[label_array_count][0]), "");
		gtk_label_set_text(GTK_LABEL(error_array[label_array_count][1]), "");
	}
}

void error_panel_update()
{
	// printf("error_panel_update\n");
	uint8_t error_count = 0;
	for (int i = 0; i < MAX_ERRORS; i++)
	{
		if (vehicle_errors[i] != NULL)
		{
			error_count++;
		}
	}

	if (error_count > 0)
	{
		sre_gui->error_show = 1;
	}
	else
	{
		sre_gui->error_show = 0;
	}

	if (sre_gui->error_show)
	{
		gtk_widget_set_visible(GTK_WIDGET(box_error), true);
	}
	else
	{
		gtk_widget_set_visible(GTK_WIDGET(box_error), false);
	}

	// @todo: add cycling error messages
	// cycle error messages
	if (error_count > 0)
	{
		static uint8_t cur_err_ind = 0;
		static uint64_t time_since_last_change = 0;

		if ((uint64_t)time(NULL) - time_since_last_change >= ERROR_PANEL_UPDATE_INT)
		{
			// Find next error that is not NULL
			for (int i = 0; i < MAX_ERRORS; i++)
			{
				cur_err_ind = (cur_err_ind + 1) % MAX_ERRORS;
				if (vehicle_errors[cur_err_ind] != NULL &&
						vehicle_errors[cur_err_ind]->dismissed == 0)
				{
					char buffer[100];
					const char *error_type_str =
							ERROR_TYPES_STR[vehicle_errors[cur_err_ind]->error_type];
					const char *sub_error_str = "N/A"; // default if no subtype exists
					if (vehicle_errors[cur_err_ind]->error_type <
									ERROR_TYPE_COUNT &&
							ERROR_SUB_TYPE_MAP[vehicle_errors[cur_err_ind]->error_type] !=
									NULL &&
							vehicle_errors[cur_err_ind]->sub_error_type <
									ERROR_SUB_TYPE_COUNT) // avoid out of bounds
					{
						sub_error_str =
								ERROR_SUB_TYPE_MAP[vehicle_errors[cur_err_ind]->error_type][vehicle_errors[cur_err_ind]->sub_error_type];
					}
					sprintf(buffer, "%s", error_type_str);
					gtk_label_set_text(GTK_LABEL(info_error_type), buffer);
					sprintf(buffer, "%s", sub_error_str);
					gtk_label_set_text(GTK_LABEL(info_error_message), buffer);
					break;
				}
			}
			// update last update time
			time_since_last_change = (uint64_t)time(NULL);
		}
	}
	else
	{
		gtk_label_set_text(GTK_LABEL(info_error_type), "");
		gtk_label_set_text(GTK_LABEL(info_error_message), "");
	}
}

void graphical_update()
{

	// printf("car_state: %s\n", CAR_STATE_STR[sre_state->car_state]);
	// printf("bat_state: %s\n", BAT_STATE_STR[sre_state->bat_state]);

	// printf("currentPanel %d\n", currentPanel);
	if (sre_gui->tsa_ready)
	{
		// gtk_widget_add_css_class(GTK_WIDGET(tsa_label_array[currentPanel]), "blink");
		gtk_widget_add_css_class(GTK_WIDGET(label_tsa_current), "blink");
	}
	else
	{
		// gtk_widget_remove_css_class(GTK_WIDGET(tsa_label_array[currentPanel]), "blink");
		gtk_widget_remove_css_class(GTK_WIDGET(label_tsa_current), "blink");
	}

	if (sre_gui->r2d_ready)
	{
		gtk_widget_add_css_class(GTK_WIDGET(label_r2d_current), "blink");
	}
	else
	{
		gtk_widget_remove_css_class(GTK_WIDGET(label_r2d_current), "blink");
	}

	if (sre_gui->r2d_active)
	{
		gtk_widget_add_css_class(GTK_WIDGET(label_r2d_current), "active");
	}
	else
	{
		gtk_widget_remove_css_class(GTK_WIDGET(label_r2d_current), "active");
	}

	if (sre_gui->tsa_active)
	{
		// gtk_widget_add_css_class(GTK_WIDGET(tsa_label_array[currentPanel]), "active");
		gtk_widget_add_css_class(GTK_WIDGET(label_tsa_current), "active");
	}
	else
	{
		// gtk_widget_remove_css_class(GTK_WIDGET(tsa_label_array[currentPanel]), "active");
		gtk_widget_remove_css_class(GTK_WIDGET(label_tsa_current), "active");
	}

	// printf("error_show: %d\n", sre_state->error_show);
	// printf("info_show: %d\n", sre_state->info_show);
	gtk_widget_set_visible(GTK_WIDGET(box_error), sre_gui->error_show);
	gtk_widget_set_visible(GTK_WIDGET(box_info), sre_gui->info_show);
}

void tsa_logic()
{
	if (sre_state->car_state == WAIT_FOR_TSA_C && sre_state->bat_state == WAIT_FOR_TSA_B)
	{
		sre_gui->tsa_ready = 1;
	}
	else
	{
		sre_gui->tsa_ready = 0;
	}

	if (sre_state->bat_state == TSA)
	{
		sre_gui->tsa_active = 1;
	}
	else
	{
		sre_gui->tsa_active = 0;
	}
}

void r2d_logic()
{
	if (sre_state->car_state == WAIT_FOR_RTD && sre_state->bat_state == TSA)
	{
		sre_gui->r2d_ready = 1;
	}
	else
	{
		sre_gui->r2d_ready = 0;
	}

	if (sre_state->car_state == DRIVE)
	{
		sre_gui->r2d_active = 1;
	}
	else
	{
		sre_gui->r2d_active = 0;
	}
}

/* --- VEHICLE ERROR MANAGMENT --- */

void error_logic()
{
	// if (sre_state->car_state == SCS_ERROR)
	// {
	// 	SRE_error *buff_error = check_if_error_exists(VCU, VCU_SCS);
	// 	if (buff_error == NULL)
	// 	{
	// 		printf("create buffer error, SCS_ERROR\n");
	// 		SRE_error *new_buff_error = create_sre_error(VCU, VCU_SCS);
	// 		add_error(new_buff_error);
	// 	}
	// 	else
	// 	{
	// 		buff_error->last_seen = (uint64_t)time(NULL);
	// 	}
	// }

	if (sre_state->bat_state == ISO_ERROR || sre_state->bat_state == BMS_ERROR || sre_state->bat_state == IMD_ERROR || sre_state->bat_state == BAT_ERROR)
	{
		SRE_error *buff_error = check_if_error_exists(BAT_ERR, sre_state->bat_state);
		if (buff_error == NULL)
		{
			SRE_error *new_buff_error = create_sre_error(BAT_ERR, sre_state->bat_state);
			add_error(new_buff_error);
		}
		else
		{
			buff_error->last_seen = (uint64_t)time(NULL);
		}
	}

	// Fuseboard
	uint8_t sdc_err_nbr = 0;
	if (sre_sdc->res == true)
		sdc_err_nbr = 1;
	else if (sre_sdc->motor_fr == true)
		sdc_err_nbr = 2;
	else if (sre_sdc->asb == true)
		sdc_err_nbr = 3;
	else if (sre_sdc->bspd == true)
		sdc_err_nbr = 4;
	else if (sre_sdc->bots == true)
		sdc_err_nbr = 5;
	else if (sre_sdc->motor_fl == true)
		sdc_err_nbr = 6;
	else if (sre_sdc->dash == true)
		sdc_err_nbr = 7;
	else if (sre_sdc->inertia == true)
		sdc_err_nbr = 8;
	else if (sre_sdc->motor_rl == true)
		sdc_err_nbr = 9;
	else if (sre_sdc->mainhoop == true)
		sdc_err_nbr = 10;
	else if (sre_sdc->motor_rr == true)
		sdc_err_nbr = 11;
	else if (sre_sdc->hvd == true)
		sdc_err_nbr = 12;
	else if (sre_sdc->ts_connector == true)
		sdc_err_nbr = 13;
	else if (sre_sdc->tsms == true)
		sdc_err_nbr = 14;

	// If SDC is open check Fuseboard SDC sensing
	if (sre_state->bat_state == SDC_OPEN)
	{
		printf("sdc_err_nbr: %d\r\n", sdc_err_nbr);
		SRE_error *buff_error = check_if_error_exists(SDC_ERR, sdc_err_nbr);
		if (buff_error == NULL)
		{
			SRE_error *new_buff_error = create_sre_error(SDC_ERR, sdc_err_nbr);
			add_error(new_buff_error);
		}
		else
		{
			buff_error->last_seen = (uint64_t)time(NULL);
		}
	}

	// ECU Errors
	uint8_t ecu_err_nbr = 0;
	if (sre_ecu_errors->temp == true)
		ecu_err_nbr = 1;
	else if (sre_ecu_errors->mt_driver_input == true)
		ecu_err_nbr = 2;
	else if (sre_ecu_errors->mt_zoco_front == true)
		ecu_err_nbr = 3;
	else if (sre_ecu_errors->mt_asb_status == true)
		ecu_err_nbr = 4;
	else if (sre_ecu_errors->mt_steering == true)
		ecu_err_nbr = 5;
	else if (sre_ecu_errors->mt_st_wheel_status == true)
		ecu_err_nbr = 6;
	else if (sre_ecu_errors->mt_zoco_left == true)
		ecu_err_nbr = 7;
	else if (sre_ecu_errors->mt_zoco_right == true)
		ecu_err_nbr = 8;
	else if (sre_ecu_errors->mt_drive_command == true)
		ecu_err_nbr = 9;
	else if (sre_ecu_errors->mt_zoco_rear == true)
		ecu_err_nbr = 10;
	else if (sre_ecu_errors->mt_extern_button == true)
		ecu_err_nbr = 11;
	else if (sre_ecu_errors->mt_saf_fuseboard == true)
		ecu_err_nbr = 12;
	else if (sre_ecu_errors->mt_bat_pcb_info == true)
		ecu_err_nbr = 13;
	else if (sre_ecu_errors->mt_bat_pcb_control == true)
		ecu_err_nbr = 14;
	else if (sre_ecu_errors->mt_bat_pcb_soc == true)
		ecu_err_nbr = 15;
	else if (sre_ecu_errors->mt_temp_pcb_1 == true)
		ecu_err_nbr = 16;
	else if (sre_ecu_errors->mt_temp_pcb_2 == true)
		ecu_err_nbr = 17;
	else if (sre_ecu_errors->mt_temp_pcb_3 == true)
		ecu_err_nbr = 18;
	else if (sre_ecu_errors->mt_temp_pcb_4 == true)
		ecu_err_nbr = 19;
	else if (sre_ecu_errors->mt_temp_pcb_5 == true)
		ecu_err_nbr = 20;
	else if (sre_ecu_errors->mt_temp_pcb_6 == true)
		ecu_err_nbr = 21;
	else if (sre_ecu_errors->mt_lsc_dash_buttons == true)
		ecu_err_nbr = 22;
	else if (sre_ecu_errors->mt_saf_dash_status == true)
		ecu_err_nbr = 23;
	else if (sre_ecu_errors->scs_dash == true)
		ecu_err_nbr = 24;
	else if (sre_ecu_errors->scs_asb_status == true)
		ecu_err_nbr = 25;
	else if (sre_ecu_errors->scs_zoco_front == true)
		ecu_err_nbr = 26;
	else if (sre_ecu_errors->scs_zoco_left == true)
		ecu_err_nbr = 27;
	else if (sre_ecu_errors->scs_zoco_rear == true)
		ecu_err_nbr = 28;
	else if (sre_ecu_errors->scs_zoco_right == true)
		ecu_err_nbr = 29;
	else if (sre_ecu_errors->scs_st_wheel == true)
		ecu_err_nbr = 30;
	else if (sre_ecu_errors->scs_fuseboard == true)
		ecu_err_nbr = 31;

	if (sre_state->car_state == SCS_ERROR)
	{
		printf("ecu_err_nbr: %d\r\n", ecu_err_nbr);
		SRE_error *buff_error = check_if_error_exists(SCS_ERR, ecu_err_nbr);
		if (buff_error == NULL)
		{
			SRE_error *new_buff_error = create_sre_error(SCS_ERR, ecu_err_nbr);
			add_error(new_buff_error);
		}
		else
		{
			buff_error->last_seen = (uint64_t)time(NULL);
		}
	}

	if (sre_state->asb_state == EBS_TRIGGERED && sre_state->asb_trigger_cause == 0)
	{
		SRE_error *buff_error = check_if_error_exists(ASB_ERROR, ASB_EBS_TRIGGERED);
		if (buff_error == NULL)
		{
			SRE_error *new_buff_error = create_sre_error(ASB_ERROR, ASB_EBS_TRIGGERED);
			add_error(new_buff_error);
		}
		else
		{
			buff_error->last_seen = (uint64_t)time(NULL);
		}
	}

	if ((sre_state->asb_state == EBS_TRIGGERED) && (sre_state->asb_trigger_cause != 0))
	{
		SRE_error *buff_error = check_if_error_exists(ASB_ERROR,
																									sre_state->asb_trigger_cause);
		if (buff_error == NULL)
		{
			SRE_error *new_buff_error = create_sre_error(ASB_ERROR,
																									 sre_state->asb_trigger_cause);
			add_error(new_buff_error);
		}
		else
		{
			buff_error->last_seen = (uint64_t)time(NULL);
		}
	}

	// Free old Error Messages
	for (int i = 0; i < MAX_ERRORS; i++)
	{
		if (vehicle_errors[i] != NULL)
		{
			if (vehicle_errors[i]->last_seen + FREE_AFTER <= (uint64_t)time(NULL))
			{
				remove_error(i);
			}
		}
	}
}

SRE_error *create_sre_error(uint16_t error_type, uint16_t sub_error_type)
{
	SRE_error *new_error = (SRE_error *)malloc(sizeof(SRE_error));
	if (!new_error)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		return NULL;
	}
	new_error->last_seen = (uint64_t)time(NULL);
	new_error->error_type = error_type;
	new_error->sub_error_type = sub_error_type;
	new_error->dismissed = 0;

	return new_error;
}

void add_error(SRE_error *error)
{
	for (int i = 0; i < MAX_ERRORS; i++)
	{
		if (vehicle_errors[i] == NULL)
		{
			vehicle_errors[i] = error;
			return;
		}
	}
	fprintf(stderr, "Error list full, cannot add new error.\n");
}

void remove_error(uint16_t index)
{
	if (index >= MAX_ERRORS || vehicle_errors[index] == NULL)
	{
		fprintf(stderr, "Invalid index for error removal.\n");
		return;
	}
	free(vehicle_errors[index]);
	vehicle_errors[index] = NULL;
}

SRE_error *check_if_error_exists(uint16_t error_type, uint16_t sub_error_type)
{
	for (int i = 0; i < MAX_ERRORS; i++)
	{
		if (vehicle_errors[i] != NULL && vehicle_errors[i]->error_type == error_type &&
				vehicle_errors[i]->sub_error_type == sub_error_type)
		{
			return vehicle_errors[i];
		}
	}
	return NULL;
}

/* ---- VEHICLE INFO MANAGEMENT ---*/

void info_logic()
{
}

// returns the position of the first bit that is 1
uint32_t get_bit_position(uint32_t value)
{
	for (int i = 0; i < 8; i++)
	{
		if (value & (1 << i))
		{
			return i;
		}
	}
	return 0; // Return -1 if no bit is set
}
