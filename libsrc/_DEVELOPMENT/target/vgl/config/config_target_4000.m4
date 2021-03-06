divert(-1)

###############################################################
# TARGET USER CONFIGURATION
# rebuild the library if changes are made
#

# Model specific target config for
# V-Tech Genius Leader 4000q / 4004ql

# Announce target
define(`__VGL_4000', 1)

define(`__VGL_4000_KEY_STATUS_ADDRESS', 0xdb00)
define(`__VGL_4000_KEY_CURRENT_ADDRESS', 0xdb01)

define(`__VGL_4000_DISPLAY_COLS', 20)
define(`__VGL_4000_DISPLAY_ROWS', 4)
define(`__VGL_4000_DISPLAY_VRAM_START', 0xdca0)
define(`__VGL_4000_DISPLAY_CONTROL_PORT', 0x0a)
define(`__VGL_4000_DISPLAY_REFRESH_ADDRESS', 0xdcf0)      #0xdcf0...0xdcf3 for each of the 4 rows
define(`__VGL_4000_DISPLAY_CURSOR_MODE_ADDRESS', 0xdcf6)
define(`__VGL_4000_DISPLAY_CURSOR_X_ADDRESS', 0xdcf4)
define(`__VGL_4000_DISPLAY_CURSOR_Y_ADDRESS', 0xdcf5)
define(`__VGL_4000_DISPLAY_CLEAR_ADDRESS', 0xdcf7)        # Can be set to 0 or 1


#
# END OF USER CONFIGURATION
###############################################################

divert(0)

dnl#
dnl# COMPILE TIME CONFIG EXPORT FOR ASSEMBLY LANGUAGE
dnl#

ifdef(`CFG_ASM_PUB',
`
PUBLIC `__VGL_4000'

PUBLIC `__VGL_4000_KEY_STATUS_ADDRESS'
PUBLIC `__VGL_4000_KEY_CURRENT_ADDRESS'

PUBLIC `__VGL_4000_DISPLAY_COLS'
PUBLIC `__VGL_4000_DISPLAY_ROWS'
PUBLIC `__VGL_4000_DISPLAY_VRAM_START'
PUBLIC `__VGL_4000_DISPLAY_CONTROL_PORT'
PUBLIC `__VGL_4000_DISPLAY_REFRESH_ADDRESS'
PUBLIC `__VGL_4000_DISPLAY_CURSOR_MODE_ADDRESS'
PUBLIC `__VGL_4000_DISPLAY_CURSOR_X_ADDRESS'
PUBLIC `__VGL_4000_DISPLAY_CURSOR_Y_ADDRESS'
PUBLIC `__VGL_4000_DISPLAY_CLEAR_ADDRESS'
')

dnl#
dnl# LIBRARY BUILD TIME CONFIG FOR ASSEMBLY LANGUAGE
dnl#

ifdef(`CFG_ASM_DEF',
`
defc `__VGL_4000' = __VGL_4000

defc `__VGL_4000_KEY_STATUS_ADDRESS' = __VGL_4000_KEY_STATUS_ADDRESS
defc `__VGL_4000_KEY_CURRENT_ADDRESS' = __VGL_4000_KEY_CURRENT_ADDRESS

defc `__VGL_4000_DISPLAY_COLS' = __VGL_4000_DISPLAY_COLS
defc `__VGL_4000_DISPLAY_ROWS' = __VGL_4000_DISPLAY_ROWS
defc `__VGL_4000_DISPLAY_VRAM_START' = __VGL_4000_DISPLAY_VRAM_START
defc `__VGL_4000_DISPLAY_CONTROL_PORT' = __VGL_4000_DISPLAY_CONTROL_PORT
defc `__VGL_4000_DISPLAY_REFRESH_ADDRESS' = __VGL_4000_DISPLAY_REFRESH_ADDRESS
defc `__VGL_4000_DISPLAY_CURSOR_MODE_ADDRESS' = __VGL_4000_DISPLAY_CURSOR_MODE_ADDRESS
defc `__VGL_4000_DISPLAY_CURSOR_X_ADDRESS' = __VGL_4000_DISPLAY_CURSOR_X_ADDRESS
defc `__VGL_4000_DISPLAY_CURSOR_Y_ADDRESS' = __VGL_4000_DISPLAY_CURSOR_Y_ADDRESS
defc `__VGL_4000_DISPLAY_CLEAR_ADDRESS' = __VGL_4000_DISPLAY_CLEAR_ADDRESS
')

dnl#
dnl# COMPILE TIME CONFIG EXPORT FOR C
dnl#

ifdef(`CFG_C_DEF',
`
`#undef'  `__VGL_4000'
`#define' `__VGL_4000'  __VGL_4000

`#define' `__VGL_4000_KEY_STATUS_ADDRESS'  __VGL_4000_KEY_STATUS_ADDRESS
`#define' `__VGL_4000_KEY_CURRENT_ADDRESS'  __VGL_4000_KEY_CURRENT_ADDRESS

`#define' `__VGL_4000_DISPLAY_COLS'  __VGL_4000_DISPLAY_COLS
`#define' `__VGL_4000_DISPLAY_ROWS'  __VGL_4000_DISPLAY_ROWS
`#define' `__VGL_4000_DISPLAY_VRAM_START'  __VGL_4000_DISPLAY_VRAM_START
`#define' `__VGL_4000_DISPLAY_CONTROL_PORT'  __VGL_4000_DISPLAY_CONTROL_PORT
`#define' `__VGL_4000_DISPLAY_REFRESH_ADDRESS'  __VGL_4000_DISPLAY_REFRESH_ADDRESS
`#define' `__VGL_4000_DISPLAY_CURSOR_MODE_ADDRESS'  __VGL_4000_DISPLAY_CURSOR_MODE_ADDRESS
`#define' `__VGL_4000_DISPLAY_CURSOR_X_ADDRESS'  __VGL_4000_DISPLAY_CURSOR_X_ADDRESS
`#define' `__VGL_4000_DISPLAY_CURSOR_Y_ADDRESS'  __VGL_4000_DISPLAY_CURSOR_Y_ADDRESS
`#define' `__VGL_4000_DISPLAY_CLEAR_ADDRESS'  __VGL_4000_DISPLAY_CLEAR_ADDRESS
')
