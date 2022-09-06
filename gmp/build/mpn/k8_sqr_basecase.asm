dnl  mpn_sqr_basecase - from x86_64/k8 directory for fat binary.
dnl  Generated by configure - DO NOT EDIT.

define(OPERATION_sqr_basecase)
define(__gmpn_sqr_basecase, __gmpn_sqr_basecase_k8)
define(__gmpn_sqr_basecasec,__gmpn_sqr_basecasec_k8)
define(__gmpn_preinv_sqr_basecase,__gmpn_preinv_sqr_basecase_k8)
define(__gmpn_sqr_basecase_cps,__gmpn_sqr_basecase_cps_k8)

dnl  For k6 and k7 gcd_1 calling their corresponding mpn_modexact_1_odd
ifdef(`__gmpn_modexact_1_odd',,
`define(__gmpn_modexact_1_odd,__gmpn_modexact_1_odd_k8)')

define(MUL_TOOM22_THRESHOLD,28)
define(MUL_TOOM33_THRESHOLD,81)
define(SQR_TOOM2_THRESHOLD,34)
define(SQR_TOOM3_THRESHOLD,114)
define(BMOD_1_TO_MOD_1_THRESHOLD,16)

include(.././mpn/x86_64/k8/sqr_basecase.asm)
