dnl  mpn_submul_1 - from x86_64/goldmont directory for fat binary.
dnl  Generated by configure - DO NOT EDIT.

define(OPERATION_submul_1)
define(__gmpn_submul_1, __gmpn_submul_1_goldmont)
define(__gmpn_submul_1c,__gmpn_submul_1c_goldmont)
define(__gmpn_preinv_submul_1,__gmpn_preinv_submul_1_goldmont)
define(__gmpn_submul_1_cps,__gmpn_submul_1_cps_goldmont)

dnl  For k6 and k7 gcd_1 calling their corresponding mpn_modexact_1_odd
ifdef(`__gmpn_modexact_1_odd',,
`define(__gmpn_modexact_1_odd,__gmpn_modexact_1_odd_goldmont)')

define(MUL_TOOM22_THRESHOLD,23)
define(MUL_TOOM33_THRESHOLD,65)
define(SQR_TOOM2_THRESHOLD,30)
define(SQR_TOOM3_THRESHOLD,113)
define(BMOD_1_TO_MOD_1_THRESHOLD,19)

include(.././mpn/x86_64/goldmont/aorsmul_1.asm)
