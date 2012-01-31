;
;       Z88 Graphics Functions - Small C+ stubs
;
;       Written around the Interlogic Standard Library
;
;       Stubs Written by D Morris - 30/9/98
;
;       Color HRG version by Stefano Bodrato
;
;	$Id: cplot.asm,v 1.1 2012-01-31 20:58:07 stefano Exp $
;

;Usage: cplot(int x, int y, int color)



                XLIB    cplot
                LIB     swapgfxbk
                XREF    swapgfxbk1

                LIB     cplotpixel

.cplot
		pop	af
		pop	bc
		pop	de
		pop	hl
		push  hl
		push  de
		push  bc
		push  af
		ld	a,c
		ex af,af

                call    swapgfxbk
                call    cplotpixel
                jp      swapgfxbk1

