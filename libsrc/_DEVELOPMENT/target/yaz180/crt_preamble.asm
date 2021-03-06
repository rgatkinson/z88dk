
IF !(__page_zero_present)

SECTION code_crt_init

    XOR     a               ; Zero Accumulator

                            ; Clear Refresh Control Reg (RCR)
    OUT0    (RCR),a         ; DRAM Refresh Enable (0 Disabled)

                            ; Clear INT/TRAP Control Register (ITC)             
    OUT0    (ITC),a         ; Disable all external interrupts.             

                            ; Set Operation Mode Control Reg (OMCR)
    LD      a,OMCR_M1E      ; Enable M1 for single step, disable 64180 I/O _RD Mode
    OUT0    (OMCR),a        ; X80 Mode (M1 Disabled, IOC Disabled)

                            ; Set PHI = CCR x 2 = 36.864MHz
                            ; if using ZS8180 or Z80182 at High-Speed
    ld      a,CMR_X2        ; Set Hi-Speed flag
    out0    (CMR),a         ; CPU Clock Multiplier Reg (CMR)

                            ; Set CCR = crystal = 18.432MHz
                            ; if using ZS8180 or Z80182 at High-Speed
    ld      a,CCR_XTAL_X2   ; Set Hi-Speed flag
    out0    (CCR),a         ; CPU Control Reg (CCR)

                            ; DMA/Wait Control Reg Set I/O Wait States
    ld      a,DCNTL_MWI0|DCNTL_IWI1
    out0    (DCNTL),a       ; 1 Memory Wait & 3 I/O Wait

                            ; Set Logical RAM Addresses
                            ; $F000-$FFFF RAM   CA1  -> $F.
                            ; $C000-$EFFF RAM   BANK
                            ; $0000-$BFFF Flash BANK -> $.0

    LD      a,$F0           ; Set New Common 1 / Bank Areas for RAM
    OUT0    (CBAR),a

    LD      a,$00           ; Set Common 1 Base Physical $0F000 -> $00
    OUT0    (CBR),a

    LD      a,$00           ; Set Bank Base Physical $00000 -> $00
    OUT0    (BBR),a

                            ; we do 256 ticks per second
    ld      hl, __CPU_CLOCK/__CPU_TIMER_SCALE/256-1 
    out0    (RLDR0L), l
    out0    (RLDR0H), h
                            ; enable down counting and interrupts for PRT0
    ld      a, TCR_TIE0|TCR_TDE0
    out0    (TCR), a        ; using the driver/z180/system_tick.asm

    EXTERN  _asci0_init
    call    _asci0_init     ; initialise the asci0

    EXTERN  _asci1_init
    call    _asci1_init     ; and the asci1 interfaces

ENDIF
