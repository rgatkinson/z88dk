
; int wa_priority_queue_push(wa_priority_queue_t *q, void *item)

SECTION seg_code_wa_priority_queue

PUBLIC wa_priority_queue_push

EXTERN asm_wa_priority_queue_push

wa_priority_queue_push:

   pop af
   pop bc
   pop hl
   
   push hl
   push bc
   push af
   
   jp asm_wa_priority_queue_push
