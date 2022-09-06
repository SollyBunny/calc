dnl  mpn_mul_1 - from x86_64/zen directory for fat binary.
dnl  Generated by configure - DO NOT EDIT.

define(OPERATION_mul_1)
define(__gmpn_mul_1, __gmpn_mul_1_zen)
define(__gmpn_mul_1c,__gmpn_mul_1c_zen)
define(__gmpn_preinv_mul_1,__gmpn_preinv_mul_1_zen)
define(__gmpn_mul_1_cps,__gmpn_mul_1_cps_zen)

dnl  For k6 and k7 gcd_1 calling their corresponding mpn_modexact_1_odd
ifdef(`__gmpn_modexact_1_odd',,
`define(__gmpn_modexact_1_odd,__gmpn_modexact_1_odd_zen)')

define(MUL_TOOM22_THRESHOLD,16)
define(MUL_TOOM33_THRESHOLD,107)
define(SQR_TOOM2_THRESHOLD,32)
define(SQR_TOOM3_THRESHOLD,114)
define(BMOD_1_TO_MOD_1_THRESHOLD,22)

include(.././mpn/x86_64/zen/mul_1.asm)
