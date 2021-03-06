#ifndef UINT128_H
#define UINT128_H

#include <stdbool.h>
#include <inttypes.h>

typedef struct {
	uint64_t value[2];
} uint128_t;

typedef uint128_t* uint128_ptr_t;

extern void setAddFirst_unsigned(uint128_t *, const uint128_t *);

extern void setAdd_unsigned(uint128_t *, const uint128_t *, const uint128_t *);

extern uint128_t add_unsigned(const uint128_t *, const uint128_t *);

extern void increment_unsigned(uint128_t *);

extern void decrement_unsigned(uint128_t *);

extern uint128_t postIncrement_unsigned(uint128_t *);

extern uint128_t preIncrement_unsigned(uint128_t *);

extern uint128_t postDecrement_unsigned(uint128_t *);

extern uint128_t preDecrement_unsigned(uint128_t *);

extern void assignValue_unsigned(uint128_t *, uint64_t, uint64_t);

extern uint128_t valueOfui64s(uint64_t, uint64_t);

extern uint64_t toui64(const uint128_t *);

extern bool isLargerThan_unsigned(const uint128_t *, const uint128_t *);

extern bool isSmallerThan_unsigned(const uint128_t *, const uint128_t *);

extern bool isLargerThanOrEqualTo_unsigned(const uint128_t *, const uint128_t *);

extern bool isSmallerThanOrEqualTo_unsigned(const uint128_t *, const uint128_t *);

extern bool equals_unsigned(const uint128_t *, const uint128_t *);

extern bool notEquals_unsigned(const uint128_t *, const uint128_t *);

extern int compare_unsigned(const uint128_t *, const uint128_t *);

extern void setSubtractFirst_unsigned(uint128_t *, const uint128_t *);

extern void setSubtract_unsigned(uint128_t *, const uint128_t *, const uint128_t *);

extern uint128_t subtract_unsigned(const uint128_t *, const uint128_t *);

extern void setShiftArg_unsigned(uint128_t *, int);

extern void setShift_unsigned(uint128_t *, const uint128_t *, int);

extern uint128_t shift_unsigned(const uint128_t *, int);

extern void setRotate_unsigned(uint128_t *, const uint128_t *, int);

extern void setRotateArg_unsigned(uint128_t *, int);

extern uint128_t rotate_unsigned(const uint128_t *, int);

extern void setBWAnd_unsigned(uint128_t *, const uint128_t *, const uint128_t *);

extern void setBWAndFirst_unsigned(uint128_t *, const uint128_t *);

extern uint128_t bwAnd_unsigned(const uint128_t *, const uint128_t *);

extern void setBWOr_unsigned(uint128_t *, const uint128_t *, const uint128_t *);

extern void setBWOrFirst_unsigned(uint128_t *, const uint128_t *);

extern uint128_t bwOr_unsigned(const uint128_t *, const uint128_t *);

extern void setBWXor_unsigned(uint128_t *, const uint128_t *, const uint128_t *);

extern void setBWXorFirst_unsigned(uint128_t *, const uint128_t *);

extern uint128_t bwXor_unsigned(const uint128_t *, const uint128_t *);

extern bool getDigit_unsigned(const uint128_t *, unsigned int);

extern void setDigitArg_unsigned(uint128_t *, unsigned int, bool);

extern void setDigit_unsigned(uint128_t * set, const uint128_t *, unsigned int, bool);

extern unsigned int getBitLength_unsigned(const uint128_t *);

extern void setMultiply_unsigned(uint128_t * prod, const uint128_t *, const uint128_t *);

extern void setMultiplyFirst_unsigned(uint128_t *, const uint128_t *);

extern uint128_t multiply_unsigned(const uint128_t *, const uint128_t *);

extern void print_unsigned(const uint128_t *, bool, bool);

extern char * toBinaryString_unsigned(const uint128_t *);

extern void setInvertBits_unsigned(uint128_t *, const uint128_t *);

extern void setInvertBitsArg_unsigned(uint128_t *);

extern uint128_t invertBits_unsigned(const uint128_t *);

/*extern void setDivide_unsigned(uint128_t *, const uint128_t *, const uint128_t *);

extern void setDivideFirst_unsigned(uint128_t *, const uint128_t *);

extern uint128_t divide_unsigned(const uint128_t *, const uint128_t *);*/

extern uint128_t fibonacci_unsigned(unsigned int);

extern uint128_t factorial_unsigned(unsigned int);

extern void printHex_unsigned(const uint128_t *, bool, bool);

#endif
