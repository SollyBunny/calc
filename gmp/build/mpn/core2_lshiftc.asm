dnl  mpn_lshiftc - from x86_64/core2 directory for fat binary.
dnl  Generated by configure - DO NOT EDIT.

define(OPERATION_lshiftc)
define(__gmpn_lshiftc, __gmpn_lshiftc_core2)
define(__gmpn_lshiftcc,__gmpn_lshiftcc_core2)
define(__gmpn_preinv_lshiftc,__gmpn_preinv_lshiftc_core2)
define(__gmpn_lshiftc_cps,__gmpn_lshiftc_cps_core2)

dnl  For k6 and k7 gcd_1 calling their corresponding mpn_modexact_1_odd
ifdef(`__gmpn_modexact_1_odd',,
`define(__gmpn_modexact_1_odd,__gmpn_modexact_1_odd_core2)')

define(MUL_TOOM22_THRESHOLD,24)
define(MUL_TOOM33_THRESHOLD,65)
define(SQR_TOOM2_THRESHOLD,28)
define(SQR_TOOM3_THRESHOLD,102)
define(BMOD_1_TO_MOD_1_THRESHOLD,26)

include(.././mpn/x86_64/core2/lshiftc.asm)

