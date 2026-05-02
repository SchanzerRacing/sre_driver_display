
#ifndef PARAMETERS_PANEL_H
#define PARAMETERS_PANEL_H

#include <gtk/gtk.h>

GtkWidget *create_parameters_panel();
void update_parameters_panel();

extern GtkBuilder *builder_parameters_panel;

// ECU Settings — PARS (set values)
extern GObject *info_pars_max_torque;
extern GObject *info_pars_max_power;
extern GObject *info_pars_recu;
extern GObject *info_pars_recu_pct;
extern GObject *info_pars_tv;
extern GObject *info_pars_dyn_torque;
extern GObject *info_pars_torque_limit;
extern GObject *info_pars_launch_ctrl;
extern GObject *info_pars_opd;
extern GObject *info_pars_spd_limit;
extern GObject *info_pars_max_speed;
extern GObject *info_pars_acc_dross;

// ECU Settings — PARC (current values)
extern GObject *info_parc_max_torque;
extern GObject *info_parc_max_power;
extern GObject *info_parc_recu;
extern GObject *info_parc_recu_pct;
extern GObject *info_parc_tv;
extern GObject *info_parc_dyn_torque;
extern GObject *info_parc_torque_limit;
extern GObject *info_parc_launch_ctrl;
extern GObject *info_parc_opd;
extern GObject *info_parc_spd_limit;
extern GObject *info_parc_max_speed;
extern GObject *info_parc_acc_dross;

// Signal light + TSA/R2D
extern GObject *label_change_params_widget;
extern GObject *label_tsa_params;
extern GObject *label_r2d_params;

#endif
