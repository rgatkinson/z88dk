
; size_t bv_stack_capacity(bv_stack_t *s)

SECTION seg_code_bv_stack

PUBLIC bv_stack_capacity

defc bv_stack_capacity = asm_bv_stack_capacity

INCLUDE "adt/bv_stack/z80/asm_bv_stack_capacity.asm"
