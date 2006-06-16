
#ifndef _SP1_H
#define _SP1_H

///////////////////////////////////////////////////////////
//                  SPRITE PACK v3.0                     //
//             Sinclair Spectrum Version                 //
//            aralbrec - April / May 2006                //
///////////////////////////////////////////////////////////
//
// This library implicity allocates and deallocates memory
// as needed.  You must provide memory allocation and de-
// allocation functions so that this implicit behaviour can
// occur.
//
// In your C program supply the following two functions:
//
// ( u_malloc must return carry flag set if allocation successful )
// void *u_malloc(uint size) {
//    return(malloc(size));   * lib function malloc sets carry *
// }
//
// ( u_free must ignore addr == 0 )
// void u_free(void *addr) {
//    free(addr);             * lib function free ignores 0 *
// }
//
// If implemented in assembler, use the labels _u_malloc and _u_free
// with HL as the parameter and return value.  XDEF both labels to
// make them globals.
//
// In these examples, C's standard malloc() and free() functions
// have been used to perform the memory allocation, but any
// method can be used.  A better choice is the block memory
// allocator (balloc.lib) as it is quick and is designed for the
// fixed-size block requests this and other libraries make.
//
///////////////////////////////////////////////////////////

#include <rect.h>

#ifndef _T_UCHAR
#define _T_UCHAR
   typedef unsigned char uchar;
#endif

#ifndef _T_UINT
#define _T_UINT
   typedef unsigned int uint;
#endif

///////////////////////////////////////////////////////////
//                  DATA STRUCTURES                      //
///////////////////////////////////////////////////////////

struct sp1_Rect {

   uchar row;
   uchar col;
   uchar width;
   uchar height;

};

struct sp1_update;
struct sp1_ss;
struct sp1_cs;

struct sp1_update {                   // "update structs" Every tile in the display area managed by SP1 is described by one of these

   uchar              nload;          // +0 bit 7 = 1 for invalidated, bit 6 = 1 for removed, bits 5:0 = number of occluding sprites present + 1
   uchar              colour;         // +1 background tile attribute
   uchar              tile;           // +2 background tile character code
   struct sp1_cs     *slist;          // +3 BIG ENDIAN ; list of sprites occupying this tile (MSB = 0 if none) points at struct sp1_cs.attr_mask
   struct sp1_update *ulist;          // +5 BIG ENDIAN ; next update struct in list of update structs queued for draw (MSB = 0 if none)
   uchar             *screen;         // +7 address in display file where this tile is drawn

};

struct sp1_ss {                       // "sprite structs" Every sprite is described by one of these

   uchar              row;            // +0  current y tile-coordinate
   uchar              col;            // +1  current x tile-coordinate
   uchar              width;          // +2  width of sprite in tiles
   uchar              height;         // +3  height of sprite in tiles

   uchar              vrot;           // +4  bit 7 = 1 for 2-byte graphical definition else 1-byte, bits 2:0 = current vertical rotation (0..7)
   uchar              hrot;           // +5  current horizontal rotation (0..7)

   uchar             *frame;          // +6  current sprite frame offset added to graphic pointers

   uchar              res0;           // +8  "LD A,n" opcode
   uchar              e_hrot;         // +9  effective horizontal rotation = MSB of rotation table to use
   uchar              res1;           // +10 "LD BC,nn" opcode
   uint               e_offset;       // +11 effective offset to add to graphic pointers, equals result of vertical rotation + frame addr
   uchar              res2;           // +13 "EX DE,HL" opcode
   uchar              res3;           // +14 "JP (HL)" opcode

   struct sp1_cs     *first;          // +15 BIG ENDIAN ; first struct sp1_cs of this sprite

   uchar              xthresh;        // +17 hrot must be at least this number of pixels for last column of sprite to be drawn (1 default)
   uchar              ythresh;        // +18 vrot must be at least this number of pixels for last row of sprite to be drawn (1 default)
   uchar              nactive;        // +19 number of struct sp1_cs cells on display (written by sp1_MoveSpr*)

};

struct sp1_cs {                       // "char structs" Every sprite is broken into pieces fitting into a tile, each of which is described by one of these

   struct sp1_cs     *next_in_spr;    // +0  BIG ENDIAN ; next sprite char within same sprite in row major order (MSB = 0 if none)

   struct sp1_update *update;         // +2  BIG ENDIAN ; tile this sprite char currently occupies (MSB = 0 if none)

   uchar              plane;          // +4  plane sprite occupies, 0 = closest to viewer
   uchar              type;           // +5  bit 7 = 1 occluding, bit 6 = 1 last column, bit 5 = 1 last row, bit 4 = 1 clear pixelbuffer, bits 3:0 draw type
   uchar              attr_mask;      // +6  attribute mask logically ANDed with underlying attribute, default = 0xff for transparent
   uchar              attr;           // +7  sprite colour, logically ORed to form final colour, default = 0 for transparent

   void              *ss_draw;        // +8  struct sp1_ss + 8 bytes ; points at code embedded in sprite struct sp1_ss

   uchar              res0;           // +10 typically "LD HL,nn" opcode
   uchar             *def;            // +11 graphic definition pointer
   uchar              res1;           // +13 typically "LD IX,nn" opcode
   uchar              res2;           // +14
   uchar             *l_def;          // +15 graphic definition pointer for sprite character to left of this one
   uchar              res3;           // +17 typically "CALL nn" opcode
   void              *draw;           // +18 & draw function for this sprite char, depends on sprite type

   struct sp1_cs     *next_in_upd;    // +20 BIG ENDIAN ; & sp1_cs.attr_mask of next sprite occupying the same tile (MSB = 0 if none)
   struct sp1_cs     *prev_in_upd;    // +22 BIG ENDIAN ; & sp1_cs.next_in_upd of previous sprite occupying the same tile

};

struct sp1_ap {                       // "attribute pairs" A struct to hold sprite attribute and mask pairs

   uchar              attr_mask;      // +0 attribute mask logically ANDed with underlying attribute = 0xff for transparent
   uchar              attr;           // +1 sprite colour, logically ORed to form final colour = 0 for transparent

};

struct sp1_tp {                       // "tile pairs" A struct to hold background colour and tile pairs

   uchar              attr;           // +0 colour
   uchar              tile;           // +1 tile code

};

struct sp1_pss {                      // "print string struct" A struct holding print state information

   struct sp1_Rect    *bounds;        // +0 rectangular boundary within which printing will be allowed
   uchar              flags;          // +2 bit 0=invalidate?, 1=xwrap?, 2=yinc?, 3=ywrap?
   uchar              x;              // +3 current x coordinate of cursor with respect to top left corner of bounds
   uchar              y;              // +4 current y coordinate of cursor with respect to top left corner of bounds
   uchar              attr_mask;      // +5 current attribute mask
   uchar              attr;           // +6 current attribute
   struct sp1_update *pos;            // +7 RESERVED struct sp1_update associated with current cursor coordinates
   void              *visit;          // +9 visit function, set to 0 for none
   
};

///////////////////////////////////////////////////////////
//                      SPRITES                          //
///////////////////////////////////////////////////////////

#define SP1_TYPE_OCCLUDE   0x80       // background and sprites underneath will not be drawn
#define SP1_TYPE_BGNDCLR   0x10       // for occluding sprites, clear pixel buffer before draw
#define SP1_TYPE_2BYTE     0x40       // sprite graphic consists of (mask,graph) pairs, valid only in sp1_CreateSpr()
#define SP1_TYPE_1BYTE     0x00       // sprite graphic consists of graph only, valid only in sp1_CreateSpr()

#define SP1_ID_MASK2       1          // masked sprite 2-byte definition (mask,graph) pairs ; sw rotation will use MASK2_NR if no rotation necessary
#define SP1_ID_MASK2_NR    2          // masked sprite 2-byte definition (mask,graph) pairs ; no rotation applied, graphic always drawn at exact tile boundary
#define SP1_ID_MASK2_LB    3          // masked sprite 2-byte definition (mask,graph) pairs ; sw rotation as MASK2 but for left boundary of sprite only
#define SP1_ID_MASK2_RB    4          // masked sprite 2-byte definition (mask,graph) pairs ; sw rotation as MASK2 but for right boundary of sprite only

#define SP1_ID_LOAD2       5          // load sprite 2-byte definition (mask,graph) pairs mask ignored; sw rotation will use LOAD2_NR if no rotation necessary
#define SP1_ID_LOAD2_NR    6          // load sprite 2-byte definition (mask,graph) pairs mask ignored; no rotation applied, always drawn at exact tile boundary
#define SP1_ID_LOAD2_LB    7          // load sprite 2-byte definition (mask,graph) pairs mask ignored; sw rotation as LOAD2 but for left boundary of sprite only
#define SP1_ID_LOAD2_RB    8          // load sprite 2-byte definition (mask,graph) pairs mask ignored; sw rotation as LOAD2 but for right boundary of sprite only

#define SP1_ID_OR2         9          // or sprite 2-byte definition (mask,graph) pairs mask ignored; sw rotation will use OR2_NR if no rotation necessary
#define SP1_ID_OR2_NR      10         // or sprite 2-byte definition (mask,graph) pairs mask ignored; no rotation applied, always drawn at exact tile boundary
#define SP1_ID_OR2_LB      11         // or sprite 2-byte definition (mask,graph) pairs mask ignored; sw rotation as OR2 but for left boundary of sprite only
#define SP1_ID_OR2_RB      12         // or sprite 2-byte definition (mask,graph) pairs mask ignored; sw rotation as OR2 but for right boundary of sprite only

#define SP1_ID_XOR2        13         // xor sprite 2-byte definition (mask,graph) pairs mask ignored; sw rotation will use XOR2_NR if no rotation necessary
#define SP1_ID_XOR2_NR     14         // xor sprite 2-byte definition (mask,graph) pairs mask ignored; no rotation applied, always drawn at exact tile boundary
#define SP1_ID_XOR2_LB     15         // xor sprite 2-byte definition (mask,graph) pairs mask ignored; sw rotation as XOR2 but for left boundary of sprite only
#define SP1_ID_XOR2_RB     16         // xor sprite 2-byte definition (mask,graph) pairs mask ignored; sw rotation as XOR2 but for right boundary of sprite only

#define SP1_ID_LOAD1       17         // load sprite 1-byte definition graph only no mask; sw rotation will use LOAD1_NR if no rotation necessary
#define SP1_ID_LOAD1_NR    18         // load sprite 1-byte definition graph only no mask; no rotation applied, always drawn at exact tile boundary
#define SP1_ID_LOAD1_LB    19         // load sprite 1-byte definition graph only no mask; sw rotation as LOAD1 but for left boundary of sprite only
#define SP1_ID_LOAD1_RB    20         // load sprite 1-byte definition graph only no mask; sw rotation as LOAD1 but for right boundary of sprite only

#define SP1_ID_OR1         21         // or sprite 1-byte definition graph only no mask; sw rotation will use OR1_NR if no rotation necessary
#define SP1_ID_OR1_NR      22         // or sprite 1-byte definition graph only no mask; no rotation applied, always drawn at exact tile boundary
#define SP1_ID_OR1_LB      23         // or sprite 1-byte definition graph only no mask; sw rotation as OR1 but for left boundary of sprite only
#define SP1_ID_OR1_RB      24         // or sprite 1-byte definition graph only no mask; sw rotation as OR1 but for right boundary of sprite only

#define SP1_ID_XOR1        25         // xor sprite 1-byte definition graph only no mask; sw rotation will use XOR1_NR if no rotation necessary
#define SP1_ID_XOR1_NR     26         // xor sprite 1-byte definition graph only no mask; no rotation applied, always drawn at exact tile boundary
#define SP1_ID_XOR1_LB     27         // xor sprite 1-byte definition graph only no mask; sw rotation as XOR1 but for left boundary of sprite only
#define SP1_ID_XOR1_RB     28         // xor sprite 1-byte definition graph only no mask; sw rotation as XOR1 but for right boundary of sprite only

#define SP1_ID_LOAD2_LBIM  29         // load sprite 2-byte definition (mask,graph) pairs mask ignored; sw rotation as LOAD2 but for left boundary of sprite w/ implied mask
#define SP1_ID_LOAD2_RBIM  30         // load sprite 2-byte definition (mask,graph) pairs mask ignored; sw rotation as LOAD2 but for right boundary of sprite w/ implied mask

#define SP1_ID_LOAD1_LBIM  31         // load sprite 1-byte definition graph only no mask; sw rotation as LOAD1 but for left boundary of sprite with implied mask
#define SP1_ID_LOAD1_RBIM  32         // load sprite 1-byte definition graph only no mask; sw rotation as LOAD1 but for right boundary of sprite with implied mask

#define SP1_ID_ATTRONLY    33         // pixels are not drawn, only attrs

#define SP1_AMASK_TRANS    0xff       // attribute mask for a transparent-colour sprite
#define SP1_AMASK_INK      0xf8       // attribute mask for an ink-only sprite
#define SP1_AMASK_PAPER    0xc7       // attribute mask for a paper-only sprite
#define SP1_AMASK_NOFLASH  0x7f       // attribute mask for no-flash
#define SP1_AMASK_NOBRIGHT 0xbf       // attribute mask for no-bright

#define SP1_ATTR_TRANS     0x00       // attribute for a transparent-colour sprite

// void *hook  <->  void [ __FASTCALL__ ] (*hook)(uint count, struct sp1_cs *c)  // if __FASTCALL__ only struct sp1_cs* passed

extern struct sp1_ss      __LIB__  *sp1_CreateSpr(uchar type, uchar height, int graphic, uchar plane);
extern uint               __LIB__   sp1_AddColSpr(struct sp1_ss *s, uchar type, int graphic, uchar plane);
extern void               __LIB__   sp1_MoveSprAbs(struct sp1_ss *s, struct sp1_Rect *clip, uchar *frame, uchar row, uchar col, uchar vrot, uchar hrot);
extern void               __LIB__   sp1_MoveSprRel(struct sp1_ss *s, struct sp1_Rect *clip, uchar *frame, char rel_row, char rel_col, char rel_vrot, char rel_hrot);
extern void               __LIB__   sp1_MoveSprPix(struct sp1_ss *s, struct sp1_Rect *clip, uchar *frame, uint x, uint y);
extern void               __LIB__   sp1_IterateSprChar(struct sp1_ss *s, void *hook);
extern void  __FASTCALL__ __LIB__   sp1_DeleteSpr(struct sp1_ss *s);

extern uchar __FASTCALL__ __LIB__   sp1_SprId2Type(uchar id);
extern void               __LIB__   sp1_ChangeSprType(struct sp1_cs *c, uchar type);

extern void               __LIB__   sp1_GetSprClrAddr(struct sp1_ss *s, uchar **sprdest);
extern void               __LIB__   sp1_PutSprClr(uchar **sprdest, struct sp1_ap *src, uchar n);
extern void               __LIB__   sp1_GetSprClr(uchar **sprsrc, struct sp1_ap *dest, uchar n);

extern void               __LIB__  *sp1_PreShiftSpr(uchar flag, uchar height, uchar width, void *srcframe, void *destframe, uchar rshift);

///////////////////////////////////////////////////////////
//                COLLISION DETECTION                    //
///////////////////////////////////////////////////////////

// These are adapter functions for the rectangles library.
// You must link to the rectangles library during compilation
// if you use these functions "-lrect".

// Collision is detected for non-zero return values
// and carry flag set.

// Notice that each struct_sp1_ss begins with a struct_sp1_Rect,
// meaning a struct_sp1_ss can be used where struct_sp1_Rect
// appears below.

extern int  __LIB__ sp1_IsPtInRect(uchar x, uchar y, struct sp1_Rect *r);
extern int  __LIB__ sp1_IsPt8InRect(uint x, uint y, struct sp1_Rect *r);   // point coords divided by 8
extern int  __LIB__ sp1_IsRectInRect(struct sp1_Rect *r1, struct sp1_Rect *r2);
extern int  __LIB__ sp1_IntersectRect(struct sp1_Rect *r1, struct sp1_Rect *r2, struct sp1_Rect *result);

// straight conversions from struct sp1_Rect to struct r_Rect8/16

extern void __LIB__ sp1_MakeRect8(struct sp1_Rect *s, struct r_Rect8 *r);
extern void __LIB__ sp1_MakeRect16(struct sp1_Rect *s, struct r_Rect16 *r);

// conversions from struct sp1_ss to struct r_Rect8/16 with character coordinates changed to pixel coordinates
// horizontal and vertical rotation also added to pixel coordinate origin

extern void __LIB__ sp1_MakeRect8Pix(struct sp1_ss *s, struct r_Rect8 *r);
extern void __LIB__ sp1_MakeRect16Pix(struct sp1_ss *s, struct r_Rect16 *r);

///////////////////////////////////////////////////////////
//                       TILES                           //
///////////////////////////////////////////////////////////

#define SP1_RFLAG_TILE          0x01
#define SP1_RFLAG_COLOUR        0x02
#define SP1_RFLAG_SPRITE        0x04

#define SP1_PSSFLAG_INVALIDATE  0x01
#define SP1_PSSFLAG_XWRAP       0x02
#define SP1_PSSFLAG_YINC        0x04
#define SP1_PSSFLAG_YWRAP       0x08

extern void  __LIB__  *sp1_TileEntry(uchar c, uchar *def);

extern void  __LIB__   sp1_PrintAt(uchar row, uchar col, uchar colour, uchar tile);
extern void  __LIB__   sp1_PrintAtInv(uchar row, uchar col, uchar colour, uchar tile);
extern uchar __LIB__   sp1_ScreenStr(uchar row, uchar col);
extern uchar __LIB__   sp1_ScreenAttr(uchar row, uchar col);
extern uint  __LIB__   sp1_Screen(uchar row, uchar col);

extern void  __LIB__   sp1_PrintString(struct sp1_pss *ps, uchar *s);
extern void  __LIB__   sp1_SetPrintPos(struct sp1_pss *ps, uchar row, uchar col);

extern void  __LIB__   sp1_GetTiles(struct sp1_Rect *r, struct sp1_tp *dest);
extern void  __LIB__   sp1_PutTiles(struct sp1_Rect *r, struct sp1_tp *src);
extern void  __LIB__   sp1_PutTilesInv(struct sp1_Rect *r, struct sp1_tp *src);

extern void  __LIB__   sp1_ClearRect(struct sp1_Rect *r, uchar colour, uchar tile, uchar rflag);
extern void  __LIB__   sp1_ClearRectInv(struct sp1_Rect *r, uchar colour, uchar tile, uchar rflag);

///////////////////////////////////////////////////////////
//                      UPDATER                          //
///////////////////////////////////////////////////////////

#define SP1_IFLAG_MAKE_ROTTBL      0x01
#define SP1_IFLAG_OVERWRITE_TILES  0x02
#define SP1_IFLAG_OVERWRITE_DFILE  0x04

// void *hook  <->  void [ __FASTCALL__ ] (*hook)(struct sp1_update *u)

extern void               __LIB__   sp1_Initialize(uchar iflag, uchar *idtypetbl, void *sprdrawtbl, uchar colour, uchar tile);
extern void               __LIB__   sp1_UpdateNow(void);

extern struct sp1_update  __LIB__  *sp1_GetUpdateStruct(uchar row, uchar col);
extern void __FASTCALL__  __LIB__   sp1_InvUpdateStruct(struct sp1_update *u);
extern void __FASTCALL__  __LIB__   sp1_ValUpdateStruct(struct sp1_update *u);
extern void               __LIB__   sp1_IterateUpdateArr(struct sp1_update **ua, void *hook);  // zero terminated array
extern void               __LIB__   sp1_IterateUpdateRect(struct sp1_Rect *r, void *hook);

extern void __FASTCALL__  __LIB__   sp1_Invalidate(struct sp1_Rect *r);
extern void __FASTCALL__  __LIB__   sp1_Validate(struct sp1_Rect *r);

extern void __FASTCALL__  __LIB__   sp1_RemoveUpdateStruct(struct sp1_update *u);
extern void __FASTCALL__  __LIB__   sp1_RestoreUpdateStruct(struct sp1_update *u);

#endif
