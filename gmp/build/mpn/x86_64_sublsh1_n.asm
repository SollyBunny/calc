dnl  mpn_sublsh1_n - from x86_64 directory for fat binary.
dnl  Generated by configure - DO NOT EDIT.

define(OPERATION_sublsh1_n)
define(__gmpn_sublsh1_n, __gmpn_sublsh1_n_x86_64)
define(__gmpn_sublsh1_nc,__gmpn_sublsh1_nc_x86_64)
define(__gmpn_preinv_sublsh1_n,__gmpn_preinv_sublsh1_n_x86_64)
define(__gmpn_sublsh1_n_cps,__gmpn_sublsh1_n_cps_x86_64)

dnl  For k6 and k7 gcd_1 calling their corresponding mpn_modexact_1_odd
ifdef(`__gmpn_modexact_1_odd',,
`define(__gmpn_modexact_1_odd,__gmpn_modexact_1_odd_x86_64)')

define(MUL_TOOM22_THRESHOLD,27)
define(MUL_TOOM33_THRESHOLD,81)
define(SQR_TOOM2_THRESHOLD,36)
define(SQR_TOOM3_THRESHOLD,117)
define(BMOD_1_TO_MOD_1_THRESHOLD,15)

include(.././mpn/x86_64/sublsh1_n.asm)

