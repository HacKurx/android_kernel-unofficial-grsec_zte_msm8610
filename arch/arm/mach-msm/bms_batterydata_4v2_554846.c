/********************************************************************
who: ZTEBSP doumingming
when: 20131223
what: add bms battery data for 554846 battery cells
notice: there is a macro for every battery data, 
        eg: CONFIG_BATT_ZTE_4V2_554846
********************************************************************/
#include <linux/batterydata-lib.h>

static struct single_row_lut fcc_temp = {
	.x		= {-20, 0, 25, 40, 60},
	.y		= {1512, 1499, 1507, 1507, 1505},
	.cols	= 5
};

static struct single_row_lut fcc_sf = {
	.x		= {0},
	.y		= {100},
	.cols	= 1
};

static struct sf_lut rbatt_sf = {
	.rows		= 31,
	.cols		= 5,
	.row_entries		= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 16, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.sf		= {
				{552, 196, 100, 87, 81},
				{554, 197, 100, 87, 81},
				{566, 206, 104, 89, 83},
				{568, 210, 108, 93, 84},
				{564, 208, 114, 96, 87},
				{568, 201, 120, 100, 90},
				{572, 195, 127, 105, 94},
				{579, 193, 128, 112, 98},
				{588, 192, 114, 103, 95},
				{600, 194, 104, 91, 87},
				{613, 195, 102, 90, 84},
				{631, 197, 105, 93, 87},
				{661, 200, 107, 97, 90},
				{704, 203, 109, 99, 94},
				{773, 209, 112, 97, 91},
				{886, 213, 109, 93, 87},
				{990, 211, 108, 93, 88},
				{944, 202, 102, 91, 86},
				{1109, 205, 101, 88, 84},
				{1326, 218, 102, 90, 86},
				{1492, 230, 105, 91, 88},
				{1705, 247, 108, 94, 90},
				{1997, 274, 111, 97, 91},
				{2375, 316, 115, 99, 91},
				{2931, 372, 115, 98, 90},
				{3829, 464, 114, 96, 90},
				{5225, 640, 119, 100, 94},
				{7576, 934, 130, 107, 100},
				{12500, 1548, 155, 120, 105},
				{33935, 6081, 938, 572, 525},
				{141631, 137251, 98584, 82941, 56616}
	}
};
static struct pc_temp_ocv_lut pc_temp_ocv = {
	.rows		= 31,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 16, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.ocv		= {
				{4183, 4164, 4175, 4172, 4166},
				{4114, 4109, 4114, 4112, 4109},
				{4063, 4065, 4069, 4066, 4062},
				{4000, 4013, 4025, 4024, 4021},
				{3949, 3969, 3987, 3986, 3982},
				{3915, 3931, 3954, 3952, 3948},
				{3884, 3896, 3923, 3921, 3917},
				{3854, 3866, 3892, 3893, 3889},
				{3827, 3841, 3855, 3857, 3855},
				{3804, 3820, 3825, 3825, 3823},
				{3784, 3802, 3806, 3805, 3802},
				{3769, 3786, 3791, 3790, 3788},
				{3758, 3775, 3779, 3779, 3776},
				{3748, 3766, 3771, 3770, 3766},
				{3739, 3758, 3764, 3758, 3750},
				{3729, 3746, 3749, 3741, 3727},
				{3717, 3728, 3731, 3722, 3708},
				{3705, 3712, 3710, 3701, 3687},
				{3690, 3700, 3688, 3680, 3667},
				{3677, 3693, 3682, 3674, 3662},
				{3669, 3690, 3680, 3673, 3660},
				{3659, 3686, 3678, 3670, 3659},
				{3647, 3680, 3675, 3667, 3655},
				{3631, 3672, 3670, 3662, 3648},
				{3609, 3653, 3654, 3645, 3629},
				{3579, 3618, 3619, 3610, 3592},
				{3537, 3569, 3569, 3561, 3543},
				{3477, 3504, 3506, 3499, 3483},
				{3384, 3416, 3424, 3417, 3399},
				{3250, 3293, 3293, 3280, 3262},
				{3000, 3000, 3000, 3000, 3000}
	}
};


struct bms_battery_data ZTE_4v2_554846_data = {
	.fcc				= 1400,
	.fcc_temp_lut			= &fcc_temp,
	.fcc_sf_lut				= &fcc_sf,
	.pc_temp_ocv_lut		= &pc_temp_ocv,
	.rbatt_sf_lut			= &rbatt_sf,
	.default_rbatt_mohm	= 172
};
