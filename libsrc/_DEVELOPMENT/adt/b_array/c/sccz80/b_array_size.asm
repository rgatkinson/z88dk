
; size_t b_array_size(b_array_t *a)

SECTION seg_code_b_array

PUBLIC b_array_size

defc b_array_size = asm_b_array_size

INCLUDE "adt/b_array/z80/asm_b_array_size.asm"
