
; void *p_forward_list_remove(p_forward_list_t *list, void *item)

SECTION seg_code_p_forward_list

PUBLIC p_forward_list_remove

EXTERN asm_p_forward_list_remove

p_forward_list_remove:

   pop af
   pop bc
   pop hl
   
   push hl
   push bc
   push af
   
   jp asm_p_forward_list_remove
