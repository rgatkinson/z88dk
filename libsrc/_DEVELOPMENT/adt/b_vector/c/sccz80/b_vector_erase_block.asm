
; size_t b_vector_erase_block(b_vector_t *v, size_t idx, size_t n)

SECTION seg_code_b_vector

PUBLIC b_vector_erase_block

EXTERN b_array_erase_block

defc b_vector_erase_block = b_array_erase_block
