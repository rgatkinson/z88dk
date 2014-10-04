
SECTION seg_code_wa_priority_queue

PUBLIC __w_heap_sift_down

EXTERN l_jpix, __w_heap_swap, l_ltu_de_hl, error_znc

__w_heap_sift_down:

   ; assumes 1-based array
   ;
   ; enter : bc = array
   ;         de = start_index in bytes (word_index * 2)
   ;         hl = n * 2 in bytes (number of words in array * 2)
   ;         ix = compare
   ;
   ; exit  : hl = 0
   ;         carry reset
   ;
   ; uses  : af, bc, de, hl

   push hl                     ; save n*2
   
   ld l,e
   ld h,d                      ; hl = parent_index
   
   add hl,hl
   jp c, error_znc - 1
   ex de,hl                    ; de = child_index
   
   add hl,bc
   ex (sp),hl
   
   ; de = child_index (*2)
   ; hl = n (*2)
   ; bc = array
   ; stack = & array[parent_index]
   
while:
   
   ; sifted to the bottom ?
   
   call l_ltu_de_hl
   jr nc, end_while            ; if child_index >= n, exit loop

   ex (sp),hl
   push hl
   push de
   ex de,hl
   
   ; choose smallest child
   
   ; hl = child_index (*2)
   ; de = & array[parent_index]
   ; bc = array
   ; stack = n (*2), & array[parent_index], child_index (*2)
   
   add hl,bc
   
   ld e,l
   ld d,h                      ; de = & array[left_child]
   
   inc hl
   inc hl                      ; hl = & array[right_child]
   
   push bc                     ; save array
   push de                     ; save & array[left_child]
   push ix                     ; save compar

;******************************
IF __SDCC | __SDCC_IX | __SDCC_IY
;******************************

   push hl
   push de
   call l_jpix                 ; (compar)(de = void *left_child, hl = void *right_child) R->L
   ld a,h                      ; a = result
   pop de
   pop hl

;******************************
ELSE
;******************************

   push de
   push hl
   call l_jpix                 ; (compar)(de = void *left_child, hl = void *right_child) L->R
   ld a,h                      ; a = result
   pop hl
   pop de

;******************************
ENDIF
;******************************

   pop ix                      ; ix = compar
   pop de                      ; de = & array[left_child]
   pop bc                      ; bc = array
   
   pop hl                      ; hl = left_child_index (*2)
   
   or a
   jp m, small_child_found

   inc hl
   inc hl                      ; hl = right_child_index (*2)
   
   inc de
   inc de                      ; de = & array[right_child]

small_child_found:

   ex (sp),hl

   ; bc = array
   ; hl = & array[parent_index]
   ; de = & array[child_index]
   ; stack = n (*2), child_index (*2)
   
   ; find out if parent needs to be pushed further down
   
   push bc                     ; save array
   
   push de                     ; save & array[child]
   push hl                     ; save & array[parent]
   push ix                     ; save compar
   
;******************************
IF __SDCC | __SDCC_IX | __SDCC_IY
;******************************

   push hl
   push de
   call l_jpix                 ; (compar)(de = void *child, hl = void *parent) R->L
   ld a,h                      ; a = result
   pop de
   pop hl

;******************************
ELSE
;******************************

   push de
   push hl
   call l_jpix                 ; (compar)(de = void *child, hl = void *parent) L->R
   ld a,h                      ; a = result
   pop hl
   pop de

;******************************
ENDIF
;******************************

   pop ix                      ; ix = compar
   pop de                      ; de = & array[parent]
   pop hl                      ; hl = & array[child]
   
   or a
   jp p, error_znc - 3         ; if array[parent] <= array[child], it's in the right place so return
   
   ; swap(array[child], array[parent])
   
   ; hl = & array[child]
   ; de = & array[parent]
   ; stack = n (*2), child_index (*2), array
   
   call __w_heap_swap
   
   ex de,hl                    ; de = & array[child]
   pop bc                      ; bc = array
   pop hl                      ; hl = child_index (*2)

   ; child becomes parent
   
   add hl,hl                   ; hl = new child_index (*2) = old_child_index (*2) * 2
   jp c, error_znc - 1
   
   ; de = & array[parent]
   ; bc = array
   ; hl = child_index (*2)
   ; stack = n (*2)
   
   ex de,hl
   ex (sp),hl

   ; de = child_index (*2)
   ; hl = n (*2)
   ; bc = array
   ; stack = & array[parent_index]

   jp while

end_while:

   ; child_index >= n
   
   jp nz, error_znc - 1        ; if child_index > n, return
   
   ; there is one last comparison to be made against last item in array
   
   ; de = child_index (*2)
   ; bc = array
   ; stack = & array[parent_index]

   ex de,hl
   add hl,bc                   ; hl = & array[child]
   
   pop de                      ; de = & array[parent]
   ex de,hl
   
   push de                     ; save & array[child]
   push hl                     ; save & array[parent]
   
;******************************
IF __SDCC | __SDCC_IX | __SDCC_IY
;******************************

   push hl
   push de
   call l_jpix                 ; (compar)(de = void *child, hl = void *parent) R->L
   ld a,h                      ; a = result
   pop de
   pop hl

;******************************
ELSE
;******************************

   push de
   push hl
   call l_jpix                 ; (compar)(de = void *child, hl = void *parent) L->R
   ld a,h                      ; a = result
   pop hl
   pop de

;******************************
ENDIF
;******************************

   or a
   jp p, error_znc - 2         ; if array[child] >= array[parent], parent is in right place
   
   ; swap(array[child], array[parent])
   
   pop hl                      ; hl = & array[parent]
   pop de                      ; de = & array[child]
   
   call __w_heap_swap
   
   jp error_znc
