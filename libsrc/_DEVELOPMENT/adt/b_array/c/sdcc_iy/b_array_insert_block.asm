
; void *b_array_insert_block(b_array_t *a, size_t idx, size_t n)

SECTION seg_code_b_array

PUBLIC _b_array_insert_block

_b_array_insert_block:

   pop af
   pop hl
   pop bc
   pop de
   
   push de
   push bc
   push hl
   push af
   
   INCLUDE "adt/b_array/z80/asm_b_array_insert_block.asm"
