
; int wa_priority_queue_push_callee(wa_priority_queue_t *q, void *item)

SECTION code_adt_wa_priority_queue

PUBLIC _wa_priority_queue_push_callee

_wa_priority_queue_push_callee:

   pop af
   pop hl
   pop bc
   push af
   
   INCLUDE "adt/wa_priority_queue/z80/asm_wa_priority_queue_push.asm"
