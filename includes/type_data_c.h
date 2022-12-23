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

#define true	1
#define false	0

#ifndef NULL
#define NULL    0
#endif
#define null    NULL

#define start                   {
#define START start
#define end                     }
#define END   end


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

typedef ui8   BYTE;  // 8  bits = 1 Bytes (db)
typedef ui16  WORD;  // 16 bits = 2 Bytes (dw)
typedef ui32  DWORD; // 32 bits = 4 Bytes (dd)
typedef ui64  QWORD; // 64 bits = 8 Bytes (dq)

typedef BYTE   db;   // 8  bits = 1 Bytes
typedef WORD   dw;   // 16 bits = 2 Bytes
typedef DWORD  dd;   // 32 bits = 4 Bytes
typedef QWORD  dq;   // 64 bits = 8 Bytes


typedef struct _int8_t {
    i8        _int8_t:8;
} _int8_t;  // (db)
typedef struct _uint8_t {
    BYTE      _uint8_t:8;
} _uint8_t; // (db)
typedef struct _int16_t {
    i16       _int16_t:16;
} _int16_t; // (dw)
typedef struct _uint16_t {
    WORD      _uint16_t:16;
} _uint16_t; // (dw)
typedef struct _int32_t {
    i32       _int32_t:32;
} _int32_t; // (dd)
typedef struct _uint32_t {
    DWORD     _uint32_t:32;
} _uint32_t; // (dd)
typedef struct _int64_t {
    i64       _int64_t:64;
} _int64_t; // (dq)
typedef struct _uint64_t {
    QWORD     _uint64_t:64;
} _uint64_t; // (dq)



#endif