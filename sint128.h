#ifndef SINT128_H
#define SINT128_H

#include "uint128.h"
#include <stdbool.h>

typedef struct {
	uint128_t value;
} sint128_t;

extern  void setAddFirst_signed(sint128_t *, const sint128_t *);

extern  void setAdd_signed(sint128_t *, const sint128_t *, const sint128_t *);

extern  sint128_t add_signed(const sint128_t *, const sint128_t *);

extern  void assignValue_signed(sint128_t *, long long, long long);

extern  sint128_t valueOfLLs(long long, long long);

extern  long long toLL(const sint128_t *);

extern  bool isLargerThan_signed(const sint128_t *, const sint128_t *);

extern  bool isSmallerThan_signed(const sint128_t *, const sint128_t *);

extern  bool isLargerThanOrEqualTo_signed(const sint128_t *, const sint128_t *);

extern  bool isSmallerThanOrEqualTo_signed(const sint128_t *, const sint128_t *);

extern  bool equals_signed(const sint128_t *, const sint128_t *);

extern  bool notEquals_signed(const sint128_t *, const sint128_t *);

extern int compare_signed(const sint128_t *, const sint128_t *);

extern  void setSubtractFirst_signed(sint128_t *, const sint128_t *);

extern  void setSubtract_signed(sint128_t *, const sint128_t *, const sint128_t *);

extern  sint128_t subtract_signed(const sint128_t *, const sint128_t *);

extern  void setShiftArg_signed(sint128_t *, int);

extern  void setShift_signed(sint128_t *, const sint128_t *, int);

extern sint128_t shift_signed(const sint128_t *, int);

extern  void setRotate_signed(sint128_t *, const sint128_t *, int);

extern  void setRotateArg_signed(sint128_t *, int);

extern sint128_t rotate_signed(const sint128_t *, int);

extern void setBWAnd_signed(sint128_t *, const sint128_t *, const sint128_t *);

extern void setBWAndFirst_signed(sint128_t *, const sint128_t *);

extern sint128_t bwAnd_signed(const sint128_t *, const sint128_t *);

extern void setBWOr_signed(sint128_t *, const sint128_t *, const sint128_t *);

extern  void setBWOrFirst_signed(sint128_t *, const sint128_t *);

extern  sint128_t bwOr_signed(const sint128_t *, const sint128_t *);

extern  void setBWXor_signed(sint128_t *, const sint128_t *, const sint128_t *);

extern  void setBWXorFirst_signed(sint128_t *, const sint128_t *);

extern  sint128_t bwXor_signed(const sint128_t *, const sint128_t *);

extern  bool isNegative(const sint128_t *);

extern  void setInvertBits_signed(sint128_t *, const sint128_t *);

extern  void setInvertBitsArg_signed(sint128_t *);

extern  sint128_t invertBits_signed(const sint128_t *);

extern  void setNegative(sint128_t *, const sint128_t *);

extern  void setNegativeArg(sint128_t *);

extern  sint128_t negate(const sint128_t *);

extern void setAbs_128(sint128_t *, const sint128_t *);

extern void setAbsArg_128(sint128_t *);

extern  void increment_signed(sint128_t *);

extern  void decrement_signed(sint128_t *);

extern  sint128_t postIncrement_signed(sint128_t *);

extern  sint128_t preIncrement_signed(sint128_t *);

extern  sint128_t postDecrement_signed(sint128_t *);

extern  sint128_t preDecrement_signed(sint128_t *);

extern  sint128_t abs_128(const sint128_t *);

extern void setMultiply_signed(sint128_t *, const sint128_t *, const sint128_t *);

extern void setMultiplyFirst_signed(sint128_t *, const sint128_t *);

extern  sint128_t multiply_signed(const sint128_t *, const sint128_t *);

/*extern void setDivide_signed(sint128_t *, const sint128_t *, const sint128_t *);

extern void setDivideFirst_signed(sint128_t *, const sint128_t *);

extern  sint128_t divide_signed(const sint128_t *, const sint128_t *);*/

extern  sint128_t fibonacci_signed(unsigned int);

extern  sint128_t factorial_signed(unsigned int);

extern  unsigned int getBitLength_signed(const sint128_t *, bool);

extern  bool getDigit_signed(const sint128_t *, unsigned int d, bool);

extern char * toBinaryString_signed(const sint128_t *, bool);

extern  void print_signed(const sint128_t *, bool, bool, bool);

extern  void printHex_signed(const sint128_t *, bool, bool, bool);

#endif