#ifndef SINT128_H
#define SINT128_H

#include "uint128.h"
#include <stdbool.h>

typedef struct signed_int_128 {
	uint128_t value;
} sint128_t;

extern inline void setAddFirst_signed(sint128_t * arg1, const sint128_t * arg2);

extern inline void setAdd_signed(sint128_t * sum, const sint128_t * arg1, const sint128_t * arg2);

extern inline sint128_t add_signed(const sint128_t * arg1, const sint128_t * arg2);

extern inline void assignValue_signed(sint128_t * number, long long value1, long long value2);

extern inline sint128_t valueOfLLs(long long value1, long long value2);

extern inline bool isLargerThan_signed(const sint128_t * arg1, const sint128_t * arg2);

extern inline bool isSmallerThan_signed(const sint128_t * arg1, const sint128_t * arg2);

extern inline bool isLargerThanOrEqualTo_signed(const sint128_t * arg1, const sint128_t * arg2);

extern inline bool isSmallerThanOrEqualTo_signed(const sint128_t * arg1, const sint128_t * arg2);

extern inline bool equals_signed(const sint128_t * arg1, const sint128_t * arg2);

extern inline bool notEquals_signed(const sint128_t * arg1, const sint128_t * arg2);

extern int compare_signed(const sint128_t * arg1, const sint128_t * arg2);

extern inline void setSubtractFirst_signed(sint128_t * arg1, const sint128_t * arg2);

extern inline void setSubtract_signed(sint128_t * diff, const sint128_t * arg1, const sint128_t * arg2);

extern inline sint128_t subtract_signed(const sint128_t * arg1, const sint128_t * arg2);

extern inline void setShiftArg_signed(sint128_t * arg, int off);

extern inline void setShift_signed(sint128_t * shifted, const sint128_t * arg, int off);

extern sint128_t shift_signed(const sint128_t * arg, int off);

extern inline void setBWAnd_signed(sint128_t * and, const sint128_t * arg1, const sint128_t * arg2);

extern  void setBWAndFirst_signed(sint128_t * arg1, const sint128_t * arg2);

extern  sint128_t bwAnd_signed(const sint128_t * arg1, const sint128_t * arg2);

extern inline void setBWOr_signed(sint128_t * or , const sint128_t * arg1, const sint128_t * arg2);

extern inline void setBWOrFirst_signed(sint128_t * arg1, const sint128_t * arg2);

extern inline sint128_t bwOr_signed(const sint128_t * arg1, const sint128_t * arg2);

extern inline void setBWXor_signed(sint128_t * xor, const sint128_t * arg1, const sint128_t * arg2);

extern inline void setBWXorFirst_signed(sint128_t * arg1, const sint128_t * arg2);

extern inline sint128_t bwXor_signed(const sint128_t * arg1, const sint128_t * arg2);

extern inline bool isNegative(const sint128_t * arg);

extern inline void setInvertBits_signed(sint128_t * inverted, const sint128_t * arg);

extern inline void setInvertBitsArg_signed(sint128_t * arg);

extern inline sint128_t invertBits_signed(const sint128_t * arg);

extern inline void setNegative(sint128_t * neg, const sint128_t * arg);

extern inline void setNegativeArg(sint128_t * arg);

extern inline sint128_t negate(const sint128_t * arg);

extern void setAbs_128(sint128_t * abs, const sint128_t * arg);

extern void setAbsArg_128(sint128_t * arg);

extern inline void increment_signed(sint128_t * arg);

extern inline void decrement_signed(sint128_t * arg);

extern inline sint128_t postIncrement_signed(sint128_t * arg);

extern inline sint128_t preIncrement_signed(sint128_t * arg);

extern inline sint128_t postDecrement_signed(sint128_t * arg);

extern inline sint128_t preDecrement_signed(sint128_t * arg);

extern inline sint128_t abs_128(const sint128_t * arg);

extern void setMultiply_signed(sint128_t * prod, const sint128_t * arg1, const sint128_t * arg2);

extern void setMultiplyFirst_signed(sint128_t * arg1, const sint128_t * arg2);

extern inline sint128_t multiply_signed(const sint128_t * arg1, const sint128_t * arg2);

/*extern void setDivide_signed(sint128_t * q, const sint128_t * arg1, const sint128_t * arg2);

extern void setDivideFirst_signed(sint128_t * arg1, const sint128_t * arg2);

extern inline sint128_t divide_signed(const sint128_t * arg1, const sint128_t * arg2);*/

extern inline sint128_t fibonacci_signed(unsigned int f);

extern inline sint128_t factorial_signed(unsigned int f);

#endif
