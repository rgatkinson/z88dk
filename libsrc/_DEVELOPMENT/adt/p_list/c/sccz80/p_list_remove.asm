
; void *p_list_remove(p_list_t *list, void *item)

SECTION seg_code_p_list

PUBLIC p_list_remove

EXTERN asm_p_list_remove

p_list_remove:

   pop af
   pop hl
   pop bc
   
   push bc
   push hl
   push af
   
   jp asm_p_list_remove
