#ifndef UINT128_H
#define UINT128_H

#include <stdbool.h>

typedef struct {
	unsigned long long value[2];
} uint128_t;

extern inline void setAddFirst_unsigned(uint128_t *, const uint128_t *);

extern inline void setAdd_unsigned(uint128_t *, const uint128_t *, const uint128_t *);

extern inline uint128_t add_unsigned(const uint128_t *, const uint128_t *);

extern inline void increment_unsigned(uint128_t *);

extern inline void decrement_unsigned(uint128_t *);

extern inline uint128_t postIncrement_unsigned(uint128_t *);

extern inline uint128_t preIncrement_unsigned(uint128_t *);

extern inline uint128_t postDecrement_unsigned(uint128_t *);

extern inline uint128_t preDecrement_unsigned(uint128_t *);

extern inline void assignValue_unsigned(uint128_t *, unsigned long long, unsigned long long);

extern inline uint128_t valueOfULLs(unsigned long long, unsigned long long);

extern inline unsigned long long toULL(const uint128_t *);

extern inline bool isLargerThan_unsigned(const uint128_t *, const uint128_t *);

extern inline bool isSmallerThan_unsigned(const uint128_t *, const uint128_t *);

extern inline bool isLargerThanOrEqualTo_unsigned(const uint128_t *, const uint128_t *);

extern inline bool isSmallerThanOrEqualTo_unsigned(const uint128_t *, const uint128_t *);

extern inline bool equals_unsigned(const uint128_t *, const uint128_t *);

extern inline bool notEquals_unsigned(const uint128_t *, const uint128_t *);

extern int compare_unsigned(const uint128_t *, const uint128_t *);

extern inline void setSubtractFirst_unsigned(uint128_t *, const uint128_t *);

extern inline void setSubtract_unsigned(uint128_t *, const uint128_t *, const uint128_t *);

extern inline uint128_t subtract_unsigned(const uint128_t *, const uint128_t *);

extern inline void setShiftArg_unsigned(uint128_t *, int);

extern inline void setShift_unsigned(uint128_t *, const uint128_t *, int);

extern uint128_t shift_unsigned(const uint128_t *, int);

extern inline void setRotate_unsigned(uint128_t *, const uint128_t *, int);

extern inline void setRotateArg_unsigned(uint128_t *, int);

extern uint128_t rotate_unsigned(const uint128_t *, int);

extern inline void setBWAnd_unsigned(uint128_t *, const uint128_t *, const uint128_t *);

extern inline void setBWAndFirst_unsigned(uint128_t *, const uint128_t *);

extern inline uint128_t bwAnd_unsigned(const uint128_t *, const uint128_t *);

extern inline void setBWOr_unsigned(uint128_t *, const uint128_t *, const uint128_t *);

extern inline void setBWOrFirst_unsigned(uint128_t *, const uint128_t *);

extern inline uint128_t bwOr_unsigned(const uint128_t *, const uint128_t *);

extern inline void setBWXor_unsigned(uint128_t *, const uint128_t *, const uint128_t *);

extern inline void setBWXorFirst_unsigned(uint128_t *, const uint128_t *);

extern inline uint128_t bwXor_unsigned(const uint128_t *, const uint128_t *);

extern inline bool getDigit_unsigned(const uint128_t *, unsigned int);

extern inline void setDigitArg_unsigned(uint128_t *, unsigned int, bool);

extern inline void setDigit_unsigned(uint128_t * set, const uint128_t *, unsigned int, bool);

extern inline unsigned int getBitLength_unsigned(const uint128_t *);

extern void setMultiply_unsigned(uint128_t * prod, const uint128_t *, const uint128_t *);

extern void setMultiplyFirst_unsigned(uint128_t *, const uint128_t *);

extern uint128_t multiply_unsigned(const uint128_t *, const uint128_t *);

extern inline void print_unsigned(const uint128_t *, bool, bool);

extern char * toBinaryString_unsigned(const uint128_t *);

extern inline void setInvertBits_unsigned(uint128_t *, const uint128_t *);

extern inline void setInvertBitsArg_unsigned(uint128_t *);

extern inline uint128_t invertBits_unsigned(const uint128_t *);

/*extern void setDivide_unsigned(uint128_t *, const uint128_t *, const uint128_t *);

extern void setDivideFirst_unsigned(uint128_t *, const uint128_t *);

extern inline uint128_t divide_unsigned(const uint128_t *, const uint128_t *);*/

extern uint128_t fibonacci_unsigned(unsigned int);

extern uint128_t factorial_unsigned(unsigned int);

extern inline void printHex_unsigned(const uint128_t *, bool, bool);

#endif