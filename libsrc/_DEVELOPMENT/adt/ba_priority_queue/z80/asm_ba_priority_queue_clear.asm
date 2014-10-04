
; ===============================================================
; Feb 2014
; ===============================================================
; 
; void ba_priority_queue_clear(ba_priority_queue_t *q)
;
; Clear the queue to empty.
;
; ===============================================================

SECTION seg_code_ba_priority_queue

PUBLIC asm_ba_priority_queue_clear

EXTERN l_zeroword_hl

defc asm_ba_priority_queue_clear = l_zeroword_hl - 4

   ; enter : hl = priority_queue *
   ;
   ; exit  : hl = & priority_queue.size
   ;
   ; uses  : hl
