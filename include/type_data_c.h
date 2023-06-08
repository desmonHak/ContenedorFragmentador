#ifndef _TYPE_DATA_C_H
#define _TYPE_DATA_C_H	1

typedef signed char              i8;
typedef unsigned char           ui8;
typedef signed short int        i16;
typedef unsigned short int     ui16;
typedef signed int              i32;
typedef unsigned int           ui32;
typedef signed long long int    i64;
typedef unsigned long long int ui64;

    #define  BITS8_MIN 0x00
    #define BITS16_MIN 0x0000
    #define BITS32_MIN 0x00000000
    #define BITS64_MIN 0x0000000000000000

    #define  BITS8_MAX 0xff
    #define BITS16_MAX 0xffff
    #define BITS32_MAX 0xffffffff
    #define BITS64_MAX 0xffffffffffffffff


    typedef enum {false, true} bool;
	#ifndef FALSE
	#   define FALSE               false
	#endif

	#ifndef TRUE
	#   define TRUE                true
	#endif

    #ifndef NULL
	#   ifdef __cplusplus
	#       define NULL    0
	#   else
	#       define NULL    ((void *)0)
	#   endif
	#endif

    #define null    NULL


#define and	                    &&
#define AND	    and
#define and_eq	                &=
#define AND_EQ	and_eq
#define bitAnd	                &
#define BITAND	bitAnd
#define bitOr	                |
#define BITOR	bitOr
#define compl	                ~
#define COMPL	compl
#define not	                    !
#define NOT	    not
#define not_eq	                !=
#define NOT_EQ	not_eq
#define or                      ||
#define OR      or
#define or_eq	                |=
#define OR_EQ	or_eq
#define xor  	                ^
#define XOR  	xor
#define xor_eq	                ^=
#define XOR_EQ	xor_eq
#define BitShitfRight           >>
#define BitShitLeft             <<
#define equalsThan              ==
#define differentThan           !=
#define lessThan                <
#define lessThanorEqualsTo      <=
#define greaterThan             >
#define greaterThanOrEqualsTo   >=


    #ifndef WIN32
        #ifndef _WINSCARD_H_
            #ifndef _BYTE_
                #define _BYTE_
                //#pragma GCC poison BYTE
                typedef ui8   BYTE;  // 8  bits = 1 Bytes (db)
            #endif

            #ifndef _WORD_
                #define _WORD_
                //#pragma GCC poison WORD
                typedef ui16  WORD;  // 16 bits = 2 Bytes (dw)
            #endif

            #ifndef _DWORD_
                #define _DWORD_
                //#pragma GCC poison DWORD
                typedef ui32  DWORD; // 32 bits = 4 Bytes (dd)
            #endif

            #ifndef _QWORD_
                #define _QWORD_
                //#pragma GCC poison QWORD
                typedef ui64  QWORD; // 64 bits = 8 Bytes (dq)
            #endif
        #endif
    #endif 

    #if WIN32
	#   include "windows.h"
    #else 
    typedef i8   INT8;
	typedef ui8   UINT8;
	typedef i16   INT16;
	typedef ui16  UINT16;
	typedef ui32  UINT32;
	typedef i32   INT32;
	typedef char  CHAR;
	typedef short SHORT;
	typedef long  LONG;
	typedef int   INT;
	typedef unsigned int UINT;
	//typedef unsigned long DWORD;
	//typedef unsigned char BYTE;
	//typedef unsigned short WORD;
	typedef float FLOAT;
	typedef double DOUBLE;
    #endif

    typedef ui8   db;   // 8  bits = 1 Bytes
    typedef ui16  dw;   // 16 bits = 2 Bytes
    typedef ui32  dd;   // 32 bits = 4 Bytes
    typedef ui64  dq;   // 64 bits = 8 Bytes


    typedef struct _int8_t {
        i8        _int8_t:8;
    } _int8_t;  // (db)
    typedef struct _uint8_t {
        db      _uint8_t:8;
    } _uint8_t; // (db)
    typedef struct _int16_t {
        i16       _int16_t:16;
    } _int16_t; // (dw)
    typedef struct _uint16_t {
        dw      _uint16_t:16;
    } _uint16_t; // (dw)
    typedef struct _int32_t {
        i32       _int32_t:32;
    } _int32_t; // (dd)
    typedef struct _uint32_t {
        dd     _uint32_t:32;
    } _uint32_t; // (dd)
    typedef struct _int64_t {
        i64       _int64_t:64;
    } _int64_t; // (dq)
    typedef struct _uint64_t {
        dq     _uint64_t:64;
    } _uint64_t; // (dq)

#define UI8(value)  (_uint8_t)  {value}
#define UI16(value) (_uint16_t) {value}
#define UI32(value) (_uint32_t) {value}
#define UI64(value) (_uint64_t) {value}
#define I8(value)   (_int8_t)   {value}
#define I16(value)  (_int16_)   {value}
#define I32(value)  (_int32_)   {value}
#define I64(value)  (_int64_)   {value}

typedef enum type_data {
    _ui8, 
    _ui16, 
    _ui32, 
    _ui64,
    null_ptr,
    _i8,
    _i16, 
    _i32, 
    _i64, 
} type_data;

typedef union multi_type
{
    ui8  uint8_t;
    ui16 uint16_t;
    ui32 uint32_t;
    ui64 uint64_t;
    void *null_ptr;
    i8   int8_t;
    i16  int16_t;
    i32  int32_t;
    i64  int64_t;
} multi_type;

    #pragma GCC diagnostic ignored "-Wunknown-pragmas"
    #ifndef VarPoint_define
        #pragma anon_struct on
        #define VarPoint_define(type_data, name) struct  { \
            type_data* pointer; \
            _uint32_t size; \
        } name; 
        #pragma anon_struct off
    #endif

#endif