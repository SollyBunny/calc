dnl  mpn_sub_n - from x86_64/coreisbr directory for fat binary.
dnl  Generated by configure - DO NOT EDIT.

define(OPERATION_sub_n)
define(__gmpn_sub_n, __gmpn_sub_n_coreisbr)
define(__gmpn_sub_nc,__gmpn_sub_nc_coreisbr)
define(__gmpn_preinv_sub_n,__gmpn_preinv_sub_n_coreisbr)
define(__gmpn_sub_n_cps,__gmpn_sub_n_cps_coreisbr)

dnl  For k6 and k7 gcd_1 calling their corresponding mpn_modexact_1_odd
ifdef(`__gmpn_modexact_1_odd',,
`define(__gmpn_modexact_1_odd,__gmpn_modexact_1_odd_coreisbr)')

define(MUL_TOOM22_THRESHOLD,20)
define(MUL_TOOM33_THRESHOLD,65)
define(SQR_TOOM2_THRESHOLD,28)
define(SQR_TOOM3_THRESHOLD,93)
define(BMOD_1_TO_MOD_1_THRESHOLD,30)

include(.././mpn/x86_64/coreisbr/aors_n.asm)

