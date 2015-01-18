/* generated by dev/build_tokens.pl */
#pragma once

/* Scan token IDs */
#define _TK_END             0    /* ""         */
#define _TK_NIL             1    /* ""         */
#define _TK_INVALID         2    /* ""         */
#define _TK_NAME            3    /* ""         */
#define _TK_LABEL           4    /* ""         */
#define _TK_NUMBER          5    /* ""         */
#define _TK_STRING          6    /* ""         */
#define _TK_TERN_COND       7    /* ""         */
#define _TK_ASMPC           8    /* "ASMPC"    */
#define _TK_IF_STMT         9    /* ""         */
#define _TK_ELSE_STMT      10    /* ""         */
#define _TK_ENDIF_STMT     11    /* ""         */
#define _TK_NEWLINE        12    /* "\n"       */
#define _TK_LOG_NOT        13    /* "!"        */
#define _TK_CONST_EXPR     14    /* "#"        */
#define _TK_MOD            15    /* "%"        */
#define _TK_BIN_AND        16    /* "&"        */
#define _TK_LOG_AND        17    /* "&&"       */
#define _TK_LPAREN         18    /* "("        */
#define _TK_RPAREN         19    /* ")"        */
#define _TK_MULTIPLY       20    /* "*"        */
#define _TK_PLUS           21    /* "+"        */
#define _TK_COMMA          22    /* ","        */
#define _TK_MINUS          23    /* "-"        */
#define _TK_DOT            24    /* "."        */
#define _TK_DIVIDE         25    /* "/"        */
#define _TK_COLON          26    /* ":"        */
#define _TK_LESS           27    /* "<"        */
#define _TK_LEFT_SHIFT     28    /* "<<"       */
#define _TK_LESS_EQ        29    /* "<="       */
#define _TK_NOT_EQ         30    /* "<>"       */
#define _TK_EQUAL          31    /* "="        */
#define _TK_GREATER        32    /* ">"        */
#define _TK_RIGHT_SHIFT    33    /* ">>"       */
#define _TK_GREATER_EQ     34    /* ">="       */
#define _TK_QUESTION       35    /* "?"        */
#define _TK_LSQUARE        36    /* "["        */
#define _TK_RSQUARE        37    /* "]"        */
#define _TK_BIN_XOR        38    /* "^"        */
#define _TK_POWER          39    /* "**"       */
#define _TK_LCURLY         40    /* "{"        */
#define _TK_BIN_OR         41    /* "|"        */
#define _TK_LOG_OR         42    /* "||"       */
#define _TK_RCURLY         43    /* "}"        */
#define _TK_BIN_NOT        44    /* "~"        */
#define _TK_NZ             45    /* "NZ"       */
#define _TK_Z              46    /* "Z"        */
#define _TK_NC             47    /* "NC"       */
#define _TK_C              48    /* "C"        */
#define _TK_PO             49    /* "PO"       */
#define _TK_PE             50    /* "PE"       */
#define _TK_P              51    /* "P"        */
#define _TK_M              52    /* "M"        */
#define _TK_B              53    /* "B"        */
#define _TK_D              54    /* "D"        */
#define _TK_E              55    /* "E"        */
#define _TK_H              56    /* "H"        */
#define _TK_IXH            57    /* "IXH"      */
#define _TK_IYH            58    /* "IYH"      */
#define _TK_L              59    /* "L"        */
#define _TK_IXL            60    /* "IXL"      */
#define _TK_IYL            61    /* "IYL"      */
#define _TK_A              62    /* "A"        */
#define _TK_F              63    /* "F"        */
#define _TK_I              64    /* "I"        */
#define _TK_IIR            65    /* "IIR"      */
#define _TK_R              66    /* "R"        */
#define _TK_EIR            67    /* "EIR"      */
#define _TK_IND_C          68    /* "(C)"      */
#define _TK_BC             69    /* "BC"       */
#define _TK_DE             70    /* "DE"       */
#define _TK_HL             71    /* "HL"       */
#define _TK_IX             72    /* "IX"       */
#define _TK_IY             73    /* "IY"       */
#define _TK_AF             74    /* "AF"       */
#define _TK_SP             75    /* "SP"       */
#define _TK_AF1            76    /* "AF'"      */
#define _TK_IND_BC         77    /* "(BC)"     */
#define _TK_IND_DE         78    /* "(DE)"     */
#define _TK_IND_HL         79    /* "(HL)"     */
#define _TK_IND_IX         80    /* "(IX"      */
#define _TK_IND_IY         81    /* "(IY"      */
#define _TK_IND_SP         82    /* "(SP)"     */
#define _TK_DEFGROUP       83    /* "DEFGROUP" */
#define _TK_DEFS           84    /* "DEFS"     */
#define _TK_DEFVARS        85    /* "DEFVARS"  */
#define _TK_INCLUDE        86    /* "INCLUDE"  */
#define _TK_ORG            87    /* "ORG"      */
#define _TK_SECTION        88    /* "SECTION"  */
#define _TK_DS_B           89    /* "DS.B"     */
#define _TK_DS_W           90    /* "DS.W"     */
#define _TK_DS_P           91    /* "DS.P"     */
#define _TK_DS_L           92    /* "DS.L"     */
#define _TK_ADC            93    /* "ADC"      */
#define _TK_ADD            94    /* "ADD"      */
#define _TK_AND            95    /* "AND"      */
#define _TK_BIT            96    /* "BIT"      */
#define _TK_CALL           97    /* "CALL"     */
#define _TK_CCF            98    /* "CCF"      */
#define _TK_CP             99    /* "CP"       */
#define _TK_CPD           100    /* "CPD"      */
#define _TK_CPDR          101    /* "CPDR"     */
#define _TK_CPI           102    /* "CPI"      */
#define _TK_CPIR          103    /* "CPIR"     */
#define _TK_CPL           104    /* "CPL"      */
#define _TK_DAA           105    /* "DAA"      */
#define _TK_DEC           106    /* "DEC"      */
#define _TK_DI            107    /* "DI"       */
#define _TK_DJNZ          108    /* "DJNZ"     */
#define _TK_EI            109    /* "EI"       */
#define _TK_EX            110    /* "EX"       */
#define _TK_EXX           111    /* "EXX"      */
#define _TK_HALT          112    /* "HALT"     */
#define _TK_IM            113    /* "IM"       */
#define _TK_IN            114    /* "IN"       */
#define _TK_INC           115    /* "INC"      */
#define _TK_IND           116    /* "IND"      */
#define _TK_INDR          117    /* "INDR"     */
#define _TK_INI           118    /* "INI"      */
#define _TK_INIR          119    /* "INIR"     */
#define _TK_JP            120    /* "JP"       */
#define _TK_JR            121    /* "JR"       */
#define _TK_LD            122    /* "LD"       */
#define _TK_LDD           123    /* "LDD"      */
#define _TK_LDDR          124    /* "LDDR"     */
#define _TK_LDI           125    /* "LDI"      */
#define _TK_LDIR          126    /* "LDIR"     */
#define _TK_NEG           127    /* "NEG"      */
#define _TK_NOP           128    /* "NOP"      */
#define _TK_OR            129    /* "OR"       */
#define _TK_OTDR          130    /* "OTDR"     */
#define _TK_OTIR          131    /* "OTIR"     */
#define _TK_OUT           132    /* "OUT"      */
#define _TK_OUTD          133    /* "OUTD"     */
#define _TK_OUTI          134    /* "OUTI"     */
#define _TK_POP           135    /* "POP"      */
#define _TK_PUSH          136    /* "PUSH"     */
#define _TK_RES           137    /* "RES"      */
#define _TK_RET           138    /* "RET"      */
#define _TK_RETI          139    /* "RETI"     */
#define _TK_RETN          140    /* "RETN"     */
#define _TK_RL            141    /* "RL"       */
#define _TK_RLA           142    /* "RLA"      */
#define _TK_RLC           143    /* "RLC"      */
#define _TK_RLCA          144    /* "RLCA"     */
#define _TK_RLD           145    /* "RLD"      */
#define _TK_RR            146    /* "RR"       */
#define _TK_RRA           147    /* "RRA"      */
#define _TK_RRC           148    /* "RRC"      */
#define _TK_RRCA          149    /* "RRCA"     */
#define _TK_RRD           150    /* "RRD"      */
#define _TK_RST           151    /* "RST"      */
#define _TK_SBC           152    /* "SBC"      */
#define _TK_SCF           153    /* "SCF"      */
#define _TK_SET           154    /* "SET"      */
#define _TK_SLA           155    /* "SLA"      */
#define _TK_SLL           156    /* "SLL"      */
#define _TK_SRA           157    /* "SRA"      */
#define _TK_SRL           158    /* "SRL"      */
#define _TK_SUB           159    /* "SUB"      */
#define _TK_XOR           160    /* "XOR"      */

#ifndef NO_TOKEN_ENUM

/* Scan token enum */
typedef enum tokid_t
{
    TK_END         = _TK_END        ,    /* =     0, ""         */
    TK_NIL         = _TK_NIL        ,    /* =     1, ""         */
    TK_INVALID     = _TK_INVALID    ,    /* =     2, ""         */
    TK_NAME        = _TK_NAME       ,    /* =     3, ""         */
    TK_LABEL       = _TK_LABEL      ,    /* =     4, ""         */
    TK_NUMBER      = _TK_NUMBER     ,    /* =     5, ""         */
    TK_STRING      = _TK_STRING     ,    /* =     6, ""         */
    TK_TERN_COND   = _TK_TERN_COND  ,    /* =     7, ""         */
    TK_ASMPC       = _TK_ASMPC      ,    /* =     8, "ASMPC"    */
    TK_IF_STMT     = _TK_IF_STMT    ,    /* =     9, ""         */
    TK_ELSE_STMT   = _TK_ELSE_STMT  ,    /* =    10, ""         */
    TK_ENDIF_STMT  = _TK_ENDIF_STMT ,    /* =    11, ""         */
    TK_NEWLINE     = _TK_NEWLINE    ,    /* =    12, "\n"       */
    TK_LOG_NOT     = _TK_LOG_NOT    ,    /* =    13, "!"        */
    TK_CONST_EXPR  = _TK_CONST_EXPR ,    /* =    14, "#"        */
    TK_MOD         = _TK_MOD        ,    /* =    15, "%"        */
    TK_BIN_AND     = _TK_BIN_AND    ,    /* =    16, "&"        */
    TK_LOG_AND     = _TK_LOG_AND    ,    /* =    17, "&&"       */
    TK_LPAREN      = _TK_LPAREN     ,    /* =    18, "("        */
    TK_RPAREN      = _TK_RPAREN     ,    /* =    19, ")"        */
    TK_MULTIPLY    = _TK_MULTIPLY   ,    /* =    20, "*"        */
    TK_PLUS        = _TK_PLUS       ,    /* =    21, "+"        */
    TK_COMMA       = _TK_COMMA      ,    /* =    22, ","        */
    TK_MINUS       = _TK_MINUS      ,    /* =    23, "-"        */
    TK_DOT         = _TK_DOT        ,    /* =    24, "."        */
    TK_DIVIDE      = _TK_DIVIDE     ,    /* =    25, "/"        */
    TK_COLON       = _TK_COLON      ,    /* =    26, ":"        */
    TK_LESS        = _TK_LESS       ,    /* =    27, "<"        */
    TK_LEFT_SHIFT  = _TK_LEFT_SHIFT ,    /* =    28, "<<"       */
    TK_LESS_EQ     = _TK_LESS_EQ    ,    /* =    29, "<="       */
    TK_NOT_EQ      = _TK_NOT_EQ     ,    /* =    30, "<>"       */
    TK_EQUAL       = _TK_EQUAL      ,    /* =    31, "="        */
    TK_GREATER     = _TK_GREATER    ,    /* =    32, ">"        */
    TK_RIGHT_SHIFT = _TK_RIGHT_SHIFT,    /* =    33, ">>"       */
    TK_GREATER_EQ  = _TK_GREATER_EQ ,    /* =    34, ">="       */
    TK_QUESTION    = _TK_QUESTION   ,    /* =    35, "?"        */
    TK_LSQUARE     = _TK_LSQUARE    ,    /* =    36, "["        */
    TK_RSQUARE     = _TK_RSQUARE    ,    /* =    37, "]"        */
    TK_BIN_XOR     = _TK_BIN_XOR    ,    /* =    38, "^"        */
    TK_POWER       = _TK_POWER      ,    /* =    39, "**"       */
    TK_LCURLY      = _TK_LCURLY     ,    /* =    40, "{"        */
    TK_BIN_OR      = _TK_BIN_OR     ,    /* =    41, "|"        */
    TK_LOG_OR      = _TK_LOG_OR     ,    /* =    42, "||"       */
    TK_RCURLY      = _TK_RCURLY     ,    /* =    43, "}"        */
    TK_BIN_NOT     = _TK_BIN_NOT    ,    /* =    44, "~"        */
    TK_NZ          = _TK_NZ         ,    /* =    45, "NZ"       */
    TK_Z           = _TK_Z          ,    /* =    46, "Z"        */
    TK_NC          = _TK_NC         ,    /* =    47, "NC"       */
    TK_C           = _TK_C          ,    /* =    48, "C"        */
    TK_PO          = _TK_PO         ,    /* =    49, "PO"       */
    TK_PE          = _TK_PE         ,    /* =    50, "PE"       */
    TK_P           = _TK_P          ,    /* =    51, "P"        */
    TK_M           = _TK_M          ,    /* =    52, "M"        */
    TK_B           = _TK_B          ,    /* =    53, "B"        */
    TK_D           = _TK_D          ,    /* =    54, "D"        */
    TK_E           = _TK_E          ,    /* =    55, "E"        */
    TK_H           = _TK_H          ,    /* =    56, "H"        */
    TK_IXH         = _TK_IXH        ,    /* =    57, "IXH"      */
    TK_IYH         = _TK_IYH        ,    /* =    58, "IYH"      */
    TK_L           = _TK_L          ,    /* =    59, "L"        */
    TK_IXL         = _TK_IXL        ,    /* =    60, "IXL"      */
    TK_IYL         = _TK_IYL        ,    /* =    61, "IYL"      */
    TK_A           = _TK_A          ,    /* =    62, "A"        */
    TK_F           = _TK_F          ,    /* =    63, "F"        */
    TK_I           = _TK_I          ,    /* =    64, "I"        */
    TK_IIR         = _TK_IIR        ,    /* =    65, "IIR"      */
    TK_R           = _TK_R          ,    /* =    66, "R"        */
    TK_EIR         = _TK_EIR        ,    /* =    67, "EIR"      */
    TK_IND_C       = _TK_IND_C      ,    /* =    68, "(C)"      */
    TK_BC          = _TK_BC         ,    /* =    69, "BC"       */
    TK_DE          = _TK_DE         ,    /* =    70, "DE"       */
    TK_HL          = _TK_HL         ,    /* =    71, "HL"       */
    TK_IX          = _TK_IX         ,    /* =    72, "IX"       */
    TK_IY          = _TK_IY         ,    /* =    73, "IY"       */
    TK_AF          = _TK_AF         ,    /* =    74, "AF"       */
    TK_SP          = _TK_SP         ,    /* =    75, "SP"       */
    TK_AF1         = _TK_AF1        ,    /* =    76, "AF'"      */
    TK_IND_BC      = _TK_IND_BC     ,    /* =    77, "(BC)"     */
    TK_IND_DE      = _TK_IND_DE     ,    /* =    78, "(DE)"     */
    TK_IND_HL      = _TK_IND_HL     ,    /* =    79, "(HL)"     */
    TK_IND_IX      = _TK_IND_IX     ,    /* =    80, "(IX"      */
    TK_IND_IY      = _TK_IND_IY     ,    /* =    81, "(IY"      */
    TK_IND_SP      = _TK_IND_SP     ,    /* =    82, "(SP)"     */
    TK_DEFGROUP    = _TK_DEFGROUP   ,    /* =    83, "DEFGROUP" */
    TK_DEFS        = _TK_DEFS       ,    /* =    84, "DEFS"     */
    TK_DEFVARS     = _TK_DEFVARS    ,    /* =    85, "DEFVARS"  */
    TK_INCLUDE     = _TK_INCLUDE    ,    /* =    86, "INCLUDE"  */
    TK_ORG         = _TK_ORG        ,    /* =    87, "ORG"      */
    TK_SECTION     = _TK_SECTION    ,    /* =    88, "SECTION"  */
    TK_DS_B        = _TK_DS_B       ,    /* =    89, "DS.B"     */
    TK_DS_W        = _TK_DS_W       ,    /* =    90, "DS.W"     */
    TK_DS_P        = _TK_DS_P       ,    /* =    91, "DS.P"     */
    TK_DS_L        = _TK_DS_L       ,    /* =    92, "DS.L"     */
    TK_ADC         = _TK_ADC        ,    /* =    93, "ADC"      */
    TK_ADD         = _TK_ADD        ,    /* =    94, "ADD"      */
    TK_AND         = _TK_AND        ,    /* =    95, "AND"      */
    TK_BIT         = _TK_BIT        ,    /* =    96, "BIT"      */
    TK_CALL        = _TK_CALL       ,    /* =    97, "CALL"     */
    TK_CCF         = _TK_CCF        ,    /* =    98, "CCF"      */
    TK_CP          = _TK_CP         ,    /* =    99, "CP"       */
    TK_CPD         = _TK_CPD        ,    /* =   100, "CPD"      */
    TK_CPDR        = _TK_CPDR       ,    /* =   101, "CPDR"     */
    TK_CPI         = _TK_CPI        ,    /* =   102, "CPI"      */
    TK_CPIR        = _TK_CPIR       ,    /* =   103, "CPIR"     */
    TK_CPL         = _TK_CPL        ,    /* =   104, "CPL"      */
    TK_DAA         = _TK_DAA        ,    /* =   105, "DAA"      */
    TK_DEC         = _TK_DEC        ,    /* =   106, "DEC"      */
    TK_DI          = _TK_DI         ,    /* =   107, "DI"       */
    TK_DJNZ        = _TK_DJNZ       ,    /* =   108, "DJNZ"     */
    TK_EI          = _TK_EI         ,    /* =   109, "EI"       */
    TK_EX          = _TK_EX         ,    /* =   110, "EX"       */
    TK_EXX         = _TK_EXX        ,    /* =   111, "EXX"      */
    TK_HALT        = _TK_HALT       ,    /* =   112, "HALT"     */
    TK_IM          = _TK_IM         ,    /* =   113, "IM"       */
    TK_IN          = _TK_IN         ,    /* =   114, "IN"       */
    TK_INC         = _TK_INC        ,    /* =   115, "INC"      */
    TK_IND         = _TK_IND        ,    /* =   116, "IND"      */
    TK_INDR        = _TK_INDR       ,    /* =   117, "INDR"     */
    TK_INI         = _TK_INI        ,    /* =   118, "INI"      */
    TK_INIR        = _TK_INIR       ,    /* =   119, "INIR"     */
    TK_JP          = _TK_JP         ,    /* =   120, "JP"       */
    TK_JR          = _TK_JR         ,    /* =   121, "JR"       */
    TK_LD          = _TK_LD         ,    /* =   122, "LD"       */
    TK_LDD         = _TK_LDD        ,    /* =   123, "LDD"      */
    TK_LDDR        = _TK_LDDR       ,    /* =   124, "LDDR"     */
    TK_LDI         = _TK_LDI        ,    /* =   125, "LDI"      */
    TK_LDIR        = _TK_LDIR       ,    /* =   126, "LDIR"     */
    TK_NEG         = _TK_NEG        ,    /* =   127, "NEG"      */
    TK_NOP         = _TK_NOP        ,    /* =   128, "NOP"      */
    TK_OR          = _TK_OR         ,    /* =   129, "OR"       */
    TK_OTDR        = _TK_OTDR       ,    /* =   130, "OTDR"     */
    TK_OTIR        = _TK_OTIR       ,    /* =   131, "OTIR"     */
    TK_OUT         = _TK_OUT        ,    /* =   132, "OUT"      */
    TK_OUTD        = _TK_OUTD       ,    /* =   133, "OUTD"     */
    TK_OUTI        = _TK_OUTI       ,    /* =   134, "OUTI"     */
    TK_POP         = _TK_POP        ,    /* =   135, "POP"      */
    TK_PUSH        = _TK_PUSH       ,    /* =   136, "PUSH"     */
    TK_RES         = _TK_RES        ,    /* =   137, "RES"      */
    TK_RET         = _TK_RET        ,    /* =   138, "RET"      */
    TK_RETI        = _TK_RETI       ,    /* =   139, "RETI"     */
    TK_RETN        = _TK_RETN       ,    /* =   140, "RETN"     */
    TK_RL          = _TK_RL         ,    /* =   141, "RL"       */
    TK_RLA         = _TK_RLA        ,    /* =   142, "RLA"      */
    TK_RLC         = _TK_RLC        ,    /* =   143, "RLC"      */
    TK_RLCA        = _TK_RLCA       ,    /* =   144, "RLCA"     */
    TK_RLD         = _TK_RLD        ,    /* =   145, "RLD"      */
    TK_RR          = _TK_RR         ,    /* =   146, "RR"       */
    TK_RRA         = _TK_RRA        ,    /* =   147, "RRA"      */
    TK_RRC         = _TK_RRC        ,    /* =   148, "RRC"      */
    TK_RRCA        = _TK_RRCA       ,    /* =   149, "RRCA"     */
    TK_RRD         = _TK_RRD        ,    /* =   150, "RRD"      */
    TK_RST         = _TK_RST        ,    /* =   151, "RST"      */
    TK_SBC         = _TK_SBC        ,    /* =   152, "SBC"      */
    TK_SCF         = _TK_SCF        ,    /* =   153, "SCF"      */
    TK_SET         = _TK_SET        ,    /* =   154, "SET"      */
    TK_SLA         = _TK_SLA        ,    /* =   155, "SLA"      */
    TK_SLL         = _TK_SLL        ,    /* =   156, "SLL"      */
    TK_SRA         = _TK_SRA        ,    /* =   157, "SRA"      */
    TK_SRL         = _TK_SRL        ,    /* =   158, "SRL"      */
    TK_SUB         = _TK_SUB        ,    /* =   159, "SUB"      */
    TK_XOR         = _TK_XOR        ,    /* =   160, "XOR"      */
} tokid_t;

#endif

