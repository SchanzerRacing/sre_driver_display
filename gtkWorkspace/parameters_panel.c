
#include "headers/parameters_panel.h"
#include "headers/sre_can.h"
#include "headers/sre_logic.h"
#include <gtk/gtk.h>

GtkBuilder *builder_parameters_panel = NULL;

// ECU Settings — PARS (set values)
GObject *info_pars_max_torque    = NULL;
GObject *info_pars_max_power     = NULL;
GObject *info_pars_recu          = NULL;
GObject *info_pars_recu_pct      = NULL;
GObject *info_pars_tv            = NULL;
GObject *info_pars_dyn_torque    = NULL;
GObject *info_pars_torque_limit  = NULL;
GObject *info_pars_launch_ctrl   = NULL;
GObject *info_pars_opd           = NULL;
GObject *info_pars_spd_limit     = NULL;
GObject *info_pars_max_speed     = NULL;
GObject *info_pars_acc_dross     = NULL;

// ECU Settings — PARC (current values)
GObject *info_parc_max_torque    = NULL;
GObject *info_parc_max_power     = NULL;
GObject *info_parc_recu          = NULL;
GObject *info_parc_recu_pct      = NULL;
GObject *info_parc_tv            = NULL;
GObject *info_parc_dyn_torque    = NULL;
GObject *info_parc_torque_limit  = NULL;
GObject *info_parc_launch_ctrl   = NULL;
GObject *info_parc_opd           = NULL;
GObject *info_parc_spd_limit     = NULL;
GObject *info_parc_max_speed     = NULL;
GObject *info_parc_acc_dross     = NULL;

// Signal light + TSA/R2D
GObject *label_change_params_widget = NULL;
GObject *label_tsa_params           = NULL;
GObject *label_r2d_params           = NULL;

static void set_match_class(GObject *pars_w, GObject *parc_w, bool match)
{
  const char *add_cls = match ? "param-match"    : "param-mismatch";
  const char *rem_cls = match ? "param-mismatch" : "param-match";
  gtk_widget_remove_css_class(GTK_WIDGET(pars_w), rem_cls);
  gtk_widget_add_css_class(GTK_WIDGET(pars_w), add_cls);
  gtk_widget_remove_css_class(GTK_WIDGET(parc_w), rem_cls);
  gtk_widget_add_css_class(GTK_WIDGET(parc_w), add_cls);
}

void update_parameters_panel()
{
  if (info_parc_max_torque == NULL) return;

  char buf[64];

  // Max Torque (Nm)
  sprintf(buf, "%.1f Nm", PARS_ECU_Settings.max_torque_s);
  gtk_label_set_text(GTK_LABEL(info_pars_max_torque), buf);
  sprintf(buf, "%.1f Nm", PARC_ECU_Settings.max_torque_c);
  gtk_label_set_text(GTK_LABEL(info_parc_max_torque), buf);
  set_match_class(info_pars_max_torque, info_parc_max_torque,
                  PARS_ECU_Settings.max_torque_s == PARC_ECU_Settings.max_torque_c);

  // Max Power (kW)
  sprintf(buf, "%.0f kW", PARS_ECU_Settings.max_power_s / 1000.0f);
  gtk_label_set_text(GTK_LABEL(info_pars_max_power), buf);
  sprintf(buf, "%.0f kW", PARC_ECU_Settings.max_power_c / 1000.0f);
  gtk_label_set_text(GTK_LABEL(info_parc_max_power), buf);
  set_match_class(info_pars_max_power, info_parc_max_power,
                  PARS_ECU_Settings.max_power_s == PARC_ECU_Settings.max_power_c);

  // RECU enable
  gtk_label_set_text(GTK_LABEL(info_pars_recu), PARS_ECU_Settings.enable_recu_s ? "ON" : "OFF");
  gtk_label_set_text(GTK_LABEL(info_parc_recu), PARC_ECU_Settings.enable_recu_c ? "ON" : "OFF");
  set_match_class(info_pars_recu, info_parc_recu,
                  PARS_ECU_Settings.enable_recu_s == PARC_ECU_Settings.enable_recu_c);

  // RECU %
  sprintf(buf, "%.0f%%", PARS_ECU_Settings.recu_percentage_s);
  gtk_label_set_text(GTK_LABEL(info_pars_recu_pct), buf);
  sprintf(buf, "%.0f%%", PARC_ECU_Settings.recu_percentage_c);
  gtk_label_set_text(GTK_LABEL(info_parc_recu_pct), buf);
  set_match_class(info_pars_recu_pct, info_parc_recu_pct,
                  PARS_ECU_Settings.recu_percentage_s == PARC_ECU_Settings.recu_percentage_c);

  // TV
  gtk_label_set_text(GTK_LABEL(info_pars_tv), PARS_ECU_Settings.enable_tv_s ? "ON" : "OFF");
  gtk_label_set_text(GTK_LABEL(info_parc_tv), PARC_ECU_Settings.enable_tv_c ? "ON" : "OFF");
  set_match_class(info_pars_tv, info_parc_tv,
                  PARS_ECU_Settings.enable_tv_s == PARC_ECU_Settings.enable_tv_c);

  // Dynamic Torque
  gtk_label_set_text(GTK_LABEL(info_pars_dyn_torque),
                     PARS_ECU_Settings.enable_dynamic_torque_s ? "ON" : "OFF");
  gtk_label_set_text(GTK_LABEL(info_parc_dyn_torque),
                     PARC_ECU_Settings.enable_dynamic_torque_c ? "ON" : "OFF");
  set_match_class(info_pars_dyn_torque, info_parc_dyn_torque,
                  PARS_ECU_Settings.enable_dynamic_torque_s ==
                  PARC_ECU_Settings.enable_dynamic_torque_c);

  // Torque Limit
  gtk_label_set_text(GTK_LABEL(info_pars_torque_limit),
                     PARS_ECU_Settings.enable_torque_limit_s ? "ON" : "OFF");
  gtk_label_set_text(GTK_LABEL(info_parc_torque_limit),
                     PARC_ECU_Settings.enable_torque_limit_c ? "ON" : "OFF");
  set_match_class(info_pars_torque_limit, info_parc_torque_limit,
                  PARS_ECU_Settings.enable_torque_limit_s ==
                  PARC_ECU_Settings.enable_torque_limit_c);

  // Launch Control
  gtk_label_set_text(GTK_LABEL(info_pars_launch_ctrl),
                     PARS_ECU_Settings.enable_launch_control_s ? "ON" : "OFF");
  gtk_label_set_text(GTK_LABEL(info_parc_launch_ctrl),
                     PARC_ECU_Settings.enable_launch_control_c ? "ON" : "OFF");
  set_match_class(info_pars_launch_ctrl, info_parc_launch_ctrl,
                  PARS_ECU_Settings.enable_launch_control_s ==
                  PARC_ECU_Settings.enable_launch_control_c);

  // OPD
  gtk_label_set_text(GTK_LABEL(info_pars_opd), PARS_ECU_Settings.enable_opd_s ? "ON" : "OFF");
  gtk_label_set_text(GTK_LABEL(info_parc_opd), PARC_ECU_Settings.enable_opd_c ? "ON" : "OFF");
  set_match_class(info_pars_opd, info_parc_opd,
                  PARS_ECU_Settings.enable_opd_s == PARC_ECU_Settings.enable_opd_c);

  // Speed Limit enable
  gtk_label_set_text(GTK_LABEL(info_pars_spd_limit),
                     PARS_ECU_Settings.enable_speed_limit_s ? "ON" : "OFF");
  gtk_label_set_text(GTK_LABEL(info_parc_spd_limit),
                     PARC_ECU_Settings.enable_speed_limit_c ? "ON" : "OFF");
  set_match_class(info_pars_spd_limit, info_parc_spd_limit,
                  PARS_ECU_Settings.enable_speed_limit_s ==
                  PARC_ECU_Settings.enable_speed_limit_c);

  // Max Speed (km/h)
  sprintf(buf, "%.0f km/h", PARS_ECU_Settings.car_control_max_speed_s);
  gtk_label_set_text(GTK_LABEL(info_pars_max_speed), buf);
  sprintf(buf, "%.0f km/h", PARC_ECU_Settings.car_control_max_speed_c);
  gtk_label_set_text(GTK_LABEL(info_parc_max_speed), buf);
  set_match_class(info_pars_max_speed, info_parc_max_speed,
                  PARS_ECU_Settings.car_control_max_speed_s ==
                  PARC_ECU_Settings.car_control_max_speed_c);

  // Acc. Drossel — PARC only, always green
  gtk_label_set_text(GTK_LABEL(info_pars_acc_dross), "-");
  gtk_label_set_text(GTK_LABEL(info_parc_acc_dross),
                     PARC_ECU_Settings.enable_acc_drosselung_c ? "ON" : "OFF");
  set_match_class(info_pars_acc_dross, info_parc_acc_dross, true);

  // Signal light (change_params)
  if (PARS_ECU_Settings.change_params) {
    gtk_widget_remove_css_class(GTK_WIDGET(label_change_params_widget), "signal-off");
    gtk_widget_add_css_class(GTK_WIDGET(label_change_params_widget), "signal-on");
  } else {
    gtk_widget_remove_css_class(GTK_WIDGET(label_change_params_widget), "signal-on");
    gtk_widget_add_css_class(GTK_WIDGET(label_change_params_widget), "signal-off");
  }
}

GtkWidget *create_parameters_panel()
{
  GtkWidget *main_params_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

  builder_parameters_panel = gtk_builder_new_from_file("../designs/parameters-panel.ui");
  if (builder_parameters_panel == NULL) {
    g_print("Failed to load parameters panel builder\n");
    return NULL;
  }

  GObject *params_panel = gtk_builder_get_object(builder_parameters_panel, "box_main_params");
  if (params_panel == NULL) {
    g_print("Failed to load parameters panel\n");
    return NULL;
  }

  GtkWidget *parent = gtk_widget_get_parent(GTK_WIDGET(params_panel));
  if (parent != NULL)
    gtk_widget_unparent(GTK_WIDGET(params_panel));

  // Cache PARS value labels
  info_pars_max_torque   = gtk_builder_get_object(builder_parameters_panel, "info_pars_max_torque");
  info_pars_max_power    = gtk_builder_get_object(builder_parameters_panel, "info_pars_max_power");
  info_pars_recu         = gtk_builder_get_object(builder_parameters_panel, "info_pars_recu");
  info_pars_recu_pct     = gtk_builder_get_object(builder_parameters_panel, "info_pars_recu_pct");
  info_pars_tv           = gtk_builder_get_object(builder_parameters_panel, "info_pars_tv");
  info_pars_dyn_torque   = gtk_builder_get_object(builder_parameters_panel, "info_pars_dyn_torque");
  info_pars_torque_limit = gtk_builder_get_object(builder_parameters_panel, "info_pars_torque_limit");
  info_pars_launch_ctrl  = gtk_builder_get_object(builder_parameters_panel, "info_pars_launch_ctrl");
  info_pars_opd          = gtk_builder_get_object(builder_parameters_panel, "info_pars_opd");
  info_pars_spd_limit    = gtk_builder_get_object(builder_parameters_panel, "info_pars_spd_limit");
  info_pars_max_speed    = gtk_builder_get_object(builder_parameters_panel, "info_pars_max_speed");
  info_pars_acc_dross    = gtk_builder_get_object(builder_parameters_panel, "info_pars_acc_dross");

  // Cache PARC value labels
  info_parc_max_torque   = gtk_builder_get_object(builder_parameters_panel, "info_parc_max_torque");
  info_parc_max_power    = gtk_builder_get_object(builder_parameters_panel, "info_parc_max_power");
  info_parc_recu         = gtk_builder_get_object(builder_parameters_panel, "info_parc_recu");
  info_parc_recu_pct     = gtk_builder_get_object(builder_parameters_panel, "info_parc_recu_pct");
  info_parc_tv           = gtk_builder_get_object(builder_parameters_panel, "info_parc_tv");
  info_parc_dyn_torque   = gtk_builder_get_object(builder_parameters_panel, "info_parc_dyn_torque");
  info_parc_torque_limit = gtk_builder_get_object(builder_parameters_panel, "info_parc_torque_limit");
  info_parc_launch_ctrl  = gtk_builder_get_object(builder_parameters_panel, "info_parc_launch_ctrl");
  info_parc_opd          = gtk_builder_get_object(builder_parameters_panel, "info_parc_opd");
  info_parc_spd_limit    = gtk_builder_get_object(builder_parameters_panel, "info_parc_spd_limit");
  info_parc_max_speed    = gtk_builder_get_object(builder_parameters_panel, "info_parc_max_speed");
  info_parc_acc_dross    = gtk_builder_get_object(builder_parameters_panel, "info_parc_acc_dross");

  // Signal light
  label_change_params_widget =
      gtk_builder_get_object(builder_parameters_panel, "label_change_params");

  // TSA / R2D
  label_tsa_params  = gtk_builder_get_object(builder_parameters_panel, "label_tsa_params");
  label_tsa_current = label_tsa_params;
  label_r2d_params  = gtk_builder_get_object(builder_parameters_panel, "label_r2d_params");
  label_r2d_current = label_r2d_params;

  gtk_box_append(GTK_BOX(main_params_box), GTK_WIDGET(params_panel));
  return main_params_box;
}
