dnl  mpn_submul_1 - from x86_64/atom directory for fat binary.
dnl  Generated by configure - DO NOT EDIT.

define(OPERATION_submul_1)
define(__gmpn_submul_1, __gmpn_submul_1_atom)
define(__gmpn_submul_1c,__gmpn_submul_1c_atom)
define(__gmpn_preinv_submul_1,__gmpn_preinv_submul_1_atom)
define(__gmpn_submul_1_cps,__gmpn_submul_1_cps_atom)

dnl  For k6 and k7 gcd_1 calling their corresponding mpn_modexact_1_odd
ifdef(`__gmpn_modexact_1_odd',,
`define(__gmpn_modexact_1_odd,__gmpn_modexact_1_odd_atom)')

define(MUL_TOOM22_THRESHOLD,12)
define(MUL_TOOM33_THRESHOLD,74)
define(SQR_TOOM2_THRESHOLD,22)
define(SQR_TOOM3_THRESHOLD,73)
define(BMOD_1_TO_MOD_1_THRESHOLD,16)

include(.././mpn/x86_64/atom/aorsmul_1.asm)

