/* SPDX-License-Identifier: GPL-2.0-only */

#include <boot/coreboot_tables.h>
#include <drivers/option/cfr_frontend.h>
#include <intelblocks/cfr.h>
#include <soc/cfr.h>

static const struct sm_object xmp_profile = SM_DECLARE_ENUM({
	.opt_name	= "xmp_profile",
	.ui_name	= "XMP Profile",
	.ui_helptext	= "Enable or disable XMP memory profile",
	.default_value	= 0,
	.values		= (const struct sm_enum_value[]) {
				{ "Default profile",	0	},
				{ "XMP profile 1",		2	},
				{ "XMP profile 2",		3	},
				SM_ENUM_VALUE_END		},
});

/* Memory configuration form */
static struct sm_obj_form memory = {
	.ui_name = "Memory",
	.obj_list = (const struct sm_object *[]) {
		&xmp_profile,
		NULL
	},
};

/* System configuration form - contains graphics and CPU settings */
static struct sm_obj_form system = {
	.ui_name = "System",
	.obj_list = (const struct sm_object *[]) {
		&igd_enabled,
		&igd_dvmt,
		&igd_aperture,
		&hyper_threading,
		&vtd,
		NULL
	},
};

/* Power management configuration form */
static struct sm_obj_form power = {
	.ui_name = "Power",
	.obj_list = (const struct sm_object *[]) {
		&power_on_after_fail,
		NULL
	},
};

/* Root menu structure containing all configuration forms */
static struct sm_obj_form *sm_root[] = {
	&system,
	&memory,
	&power,
	NULL
};

/*
 * mb_cfr_setup_menu - Setup mainboard configuration menu
 * @cfr_root: Pointer to coreboot CFR (Configuration Runtime) structure
 *
 * This function initializes the mainboard-specific configuration menu for
 * the Sophos SG310/SG330 R2. It populates the CFR structure with the setup menu
 * hierarchy containing system and power management options.
 */
void mb_cfr_setup_menu(struct lb_cfr *cfr_root)
{
	cfr_write_setup_menu(cfr_root, sm_root);
}
