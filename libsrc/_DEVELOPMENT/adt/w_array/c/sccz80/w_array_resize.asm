
; int w_array_resize(w_array_t *a, size_t n)

SECTION seg_code_w_array

PUBLIC w_array_resize

EXTERN asm_w_array_resize

w_array_resize:

   pop af
   pop de
   pop hl
   
   push hl
   push de
   push af
   
   jp asm_w_array_resize
