#ifndef UINT128_H
#define UINT128_H

#include <stdbool.h>

/*#ifdef WIN64
#define OS_TYPE 0
#elif defined(WIN32)
#define OS_TYPE 1
#else
#define OS_TYPE 2
#endif */

//#pragma pack(1)
typedef struct unsigned_int_128 {
	unsigned long long value[2];
} uint128_t;

extern inline void setAddFirst_unsigned(uint128_t * arg1, const uint128_t * arg2);

extern inline void setAdd_unsigned(uint128_t * sum, const uint128_t * arg1, const uint128_t * arg2);

extern inline uint128_t add_unsigned(const uint128_t * arg1, const uint128_t * arg2);

extern inline void increment_unsigned(uint128_t * arg);

extern inline void decrement_unsigned(uint128_t * arg);

extern inline uint128_t postIncrement_unsigned(uint128_t * arg);

extern inline uint128_t preIncrement_unsigned(uint128_t * arg);

extern inline uint128_t postDecrement_unsigned(uint128_t * arg);

extern inline uint128_t preDecrement_unsigned(uint128_t * arg);

extern inline void assignValue_unsigned(uint128_t * number, unsigned long long value1, unsigned long long value2);

extern inline uint128_t valueOfULLs(unsigned long long value1, unsigned long long value2);

extern inline bool isLargerThan_unsigned(const uint128_t * arg1, const uint128_t * arg2);

extern inline bool isSmallerThan_unsigned(const uint128_t * arg1, const uint128_t * arg2);

extern inline bool isLargerThanOrEqualTo_unsigned(const uint128_t * arg1, const uint128_t * arg2);

extern inline bool isSmallerThanOrEqualTo_unsigned(const uint128_t * arg1, const uint128_t * arg2);

extern inline bool equals_unsigned(const uint128_t * arg1, const uint128_t * arg2);

extern inline bool notEquals_unsigned(const uint128_t * arg1, const uint128_t * arg2);

extern char compare_unsigned(const uint128_t * arg1, const uint128_t * arg2);

extern inline void setSubtractFirst_unsigned(uint128_t * arg1, const uint128_t * arg2);

extern inline void setSubtract_unsigned(uint128_t * diff, const uint128_t * arg1, const uint128_t * arg2);

extern inline uint128_t subtract_unsigned(const uint128_t * arg1, const uint128_t * arg2);

extern inline void setShiftArg_unsigned(uint128_t * arg, int off);

extern inline void setShift_unsigned(uint128_t * shifted, const uint128_t * arg, int off);

extern uint128_t shift_unsigned(const uint128_t * arg, int off);

extern inline void setBWAnd_unsigned(uint128_t * and, const uint128_t * arg1, const uint128_t * arg2);

extern inline void setBWAndFirst_unsigned(uint128_t * arg1, const uint128_t * arg2);

extern inline uint128_t bwAnd_unsigned(const uint128_t * arg1, const uint128_t * arg2);

extern inline void setBWOr_unsigned(uint128_t * bwOr, const uint128_t * arg1, const uint128_t * arg2);

extern inline void setBWOrFirst_unsigned(uint128_t * arg1, const uint128_t * arg2);

extern inline uint128_t bwOr_unsigned(const uint128_t * arg1, const uint128_t * arg2);

extern inline void setBWXor_unsigned(uint128_t * bwXor, const uint128_t * arg1, const uint128_t * arg2);

extern inline void setBWXorFirst_unsigned(uint128_t * arg1, const uint128_t * arg2);

extern inline uint128_t bwXor_unsigned(const uint128_t * arg1, const uint128_t * arg2);

extern inline bool getDigit_unsigned(const uint128_t * arg, unsigned int d);

extern inline void setDigitArg_unsigned(uint128_t * arg, unsigned int i, bool d);

extern inline void setDigit_unsigned(uint128_t * set, const uint128_t * arg, unsigned int i, bool d);

extern inline unsigned int getBitLength_unsigned(const uint128_t * arg);

extern void setMultiply_unsigned(uint128_t * prod, const uint128_t * arg1, const uint128_t * arg2);

extern void setMultiplyFirst_unsigned(uint128_t * arg1, const uint128_t * arg2);

extern uint128_t multiply_unsigned(const uint128_t * arg1, const uint128_t * arg2);

extern void print_unsigned(const uint128_t * arg, bool breakBefore, bool breakAfter);

extern char * toBinaryString_unsigned(const uint128_t * arg);

extern inline void setInvertBits_unsigned(uint128_t * inverted, const uint128_t * arg);

extern inline void setInvertBitsArg_unsigned(uint128_t * arg);

extern inline uint128_t invertBits_unsigned(const uint128_t * arg);

/*extern void setDivide_unsigned(uint128_t * q, const uint128_t * arg1, const uint128_t * arg2);

extern void setDivideFirst_unsigned(uint128_t * arg1, const uint128_t * arg2);

extern inline uint128_t divide_unsigned(const uint128_t * arg1, const uint128_t * arg2);*/

extern uint128_t fibonacci_unsigned(unsigned int f);

extern uint128_t factorial_unsigned(unsigned int f);

#endif