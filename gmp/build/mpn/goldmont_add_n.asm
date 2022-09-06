dnl  mpn_add_n - from x86_64/goldmont directory for fat binary.
dnl  Generated by configure - DO NOT EDIT.

define(OPERATION_add_n)
define(__gmpn_add_n, __gmpn_add_n_goldmont)
define(__gmpn_add_nc,__gmpn_add_nc_goldmont)
define(__gmpn_preinv_add_n,__gmpn_preinv_add_n_goldmont)
define(__gmpn_add_n_cps,__gmpn_add_n_cps_goldmont)

dnl  For k6 and k7 gcd_1 calling their corresponding mpn_modexact_1_odd
ifdef(`__gmpn_modexact_1_odd',,
`define(__gmpn_modexact_1_odd,__gmpn_modexact_1_odd_goldmont)')

define(MUL_TOOM22_THRESHOLD,23)
define(MUL_TOOM33_THRESHOLD,65)
define(SQR_TOOM2_THRESHOLD,30)
define(SQR_TOOM3_THRESHOLD,113)
define(BMOD_1_TO_MOD_1_THRESHOLD,19)

include(.././mpn/x86_64/goldmont/aors_n.asm)
