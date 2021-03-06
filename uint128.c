#include "uint128.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

inline void setAddFirst_unsigned(uint128_t * arg1, const uint128_t * arg2) {
	arg1->value[0] += arg2->value[0];
	arg1->value[1] += arg1->value[0] < arg2->value[0];
	arg1->value[1] += arg2->value[1];
}

inline void setAdd_unsigned(uint128_t * sum, const uint128_t * arg1, const uint128_t * arg2) {
	sum->value[0] = arg1->value[0] + arg2->value[0];
	sum->value[1] = arg1->value[1] + arg2->value[1];
	sum->value[1] += sum->value[0] < arg1->value[0];
}

inline uint128_t add_unsigned(const uint128_t * arg1, const uint128_t * arg2) {
	uint128_t sum;
	setAdd_unsigned(&sum, arg1, arg2);
	return sum;
}

inline void increment_unsigned(uint128_t * arg) {
	++arg->value[0];
	arg->value[1] += arg->value[0] == 0;
}

inline void decrement_unsigned(uint128_t * arg) {
	--arg->value[0];
	arg->value[1] -= arg->value[0] == 0xffffffffffffffff;
}

inline uint128_t postIncrement_unsigned(uint128_t * arg) {
	uint128_t t = *arg;
	increment_unsigned(arg);
	return t;
}

inline uint128_t preIncrement_unsigned(uint128_t * arg) {
	increment_unsigned(arg);
	return *arg;
}

inline uint128_t postDecrement_unsigned(uint128_t * arg) {
	uint128_t t = *arg;
	decrement_unsigned(arg);
	return t;
}

inline uint128_t preDecrement_unsigned(uint128_t * arg) {
	decrement_unsigned(arg);
	return *arg;
}

inline void assignValue_unsigned(uint128_t * number, uint64_t value1, uint64_t value2) {
	number->value[0] = value1;
	number->value[1] = value2;
}

inline uint128_t valueOfui64s(uint64_t value1, uint64_t value2) {
	uint128_t number;
	assignValue_unsigned(&number, value1, value2);
	return number;
}

inline uint64_t toui64(const uint128_t * arg) {
	return arg->value[0];
}

inline bool isLargerThan_unsigned(const uint128_t * arg1, const uint128_t * arg2) {
	return arg1->value[1] > arg2->value[1] || (arg1->value[1] == arg2->value[1] && arg1->value[0] > arg2->value[0]);
}

inline bool isSmallerThan_unsigned(const uint128_t * arg1, const uint128_t * arg2) {
	return arg1->value[1] < arg2->value[1] || (arg1->value[1] == arg2->value[1] && arg1->value[0] < arg2->value[0]);
}

inline bool isLargerThanOrEqualTo_unsigned(const uint128_t * arg1, const uint128_t * arg2) {
	return !isSmallerThan_unsigned(arg1, arg2);
}

inline bool isSmallerThanOrEqualTo_unsigned(const uint128_t * arg1, const uint128_t * arg2) {
	return !isLargerThan_unsigned(arg1, arg2);
}

inline bool equals_unsigned(const uint128_t * arg1, const uint128_t * arg2) {
	return arg1->value[1] == arg2->value[1] && arg1->value[0] == arg2->value[0];
}

inline bool notEquals_unsigned(const uint128_t * arg1, const uint128_t * arg2) {
	return !equals_unsigned(arg1, arg2);
}

int compare_unsigned(const uint128_t * arg1, const uint128_t * arg2) {
	if (equals_unsigned(arg1, arg2)) {
		return 0;
	}
	else if (isLargerThan_unsigned(arg1, arg2)) {
		return 1;
	}
	else {
		return -1;
	}
}

inline void setSubtractFirst_unsigned(uint128_t * arg1, const uint128_t * arg2) {
	arg1->value[1] -= arg1->value[0] < arg2->value[0];
	arg1->value[0] -= arg2->value[0];
	arg1->value[1] -= arg2->value[1];
}

inline void setSubtract_unsigned(uint128_t * diff, const uint128_t * arg1, const uint128_t * arg2) {
	diff->value[0] = arg1->value[0] - arg2->value[0];
	diff->value[1] = arg1->value[1] - arg2->value[1];
	diff->value[1] -= arg1->value[0] < arg2->value[0];
}

inline uint128_t subtract_unsigned(const uint128_t * arg1, const uint128_t * arg2) {
	uint128_t diff;
	setSubtract_unsigned(&diff, arg1, arg2);
	return diff;
}

inline static void setShiftOneLeftArg_unsigned(uint128_t * arg) {
	arg->value[1] <<= 1;
	if (arg->value[0] >= 0x8000000000000000) {
		arg->value[1] += 1;
	}
	arg->value[0] <<= 1;
}

inline static void setShiftOneRightArg_unsigned(uint128_t * arg) {
	arg->value[0] >>= 1;
	if (arg->value[1] & 1) {
		arg->value[1] += 0x8000000000000000;
	}
	arg->value[1] >>= 1;
}

inline static void setShiftOneLeft_unsigned(uint128_t * shifted, const uint128_t * arg) {
	shifted->value[1] = arg->value[1] << 1;
	if (arg->value[0] >= 0x8000000000000000) {
		shifted->value[1] += 1;
	}
	shifted->value[0] = arg->value[0] << 1;
}

inline static void setShiftOneRight_unsigned(uint128_t * shifted, const uint128_t * arg) {
	shifted->value[1] = arg->value[1] >> 1;
	shifted->value[0] = arg->value[0] >> 1;
	if (arg->value[1] & 1) {
		shifted->value[1] += 0x8000000000000000;
	}
}

void setShiftArg_unsigned(uint128_t * arg, int off) {
	if (off == 0) {
		return;
	}
	else if (off > 128 || off < -128) {
		arg->value[0] = 0ULL;
		arg->value[1] = 0ULL;
		return;
	}

	if (off > 0) {
		if (off < 64) {
			uint64_t left_mask = ~((1ULL << off) - 1);
			arg->value[1] <<= off;
			arg->value[1] |= (arg->value[0] & left_mask) >> off;
			arg->value[0] <<= off;
		}
		else {
			off &= 0x3f;
			arg->value[1] = arg->value[0];
			arg->value[0] = 0ULL;
			arg->value[1] <<= off;
		}
	}
	else {
		off = -off;
		if (off < 64) {
			uint64_t right_mask = (1ULL << off) - 1;
			arg->value[0] >>= off;
			arg->value[0] |= (arg->value[1] & right_mask) << (64 - off);
			arg->value[1] >>= off;
		}
		else {
			off &= 0x3f;
			arg->value[0] = arg->value[1];
			arg->value[1] = 0ULL;
			arg->value[0] >>= off;
		}
	}
}

inline void setShift_unsigned(uint128_t * shifted, const uint128_t * arg, int off) {
	if (off == 0) {
		*shifted = *arg;
		return;
	}
	else if (off > 128 || off < -128) {
		shifted->value[0] = 0;
		shifted->value[1] = 0;
		return;
	}

	if (off > 0) {
		if (off < 64) {
			uint64_t left_mask = ~((1ULL << off) - 1);
			shifted->value[1] = arg->value[1] << off;
			shifted->value[1] = arg->value[1] | ((arg->value[0] & left_mask) >> off);
			shifted->value[0] = arg->value[0] << off;
		}
		else {
			off &= 0x3f;
			shifted->value[1] = arg->value[0];
			shifted->value[0] = 0ULL;
			shifted->value[1] <<= off;
		}
	}
	else {
		off = -off;
		if (off < 64) {
			uint64_t right_mask = (1ULL << off) - 1;
			shifted->value[0] = arg->value[0] >> off;
			shifted->value[0] = arg->value[0] | ((arg->value[1] & right_mask) << (64 - off));
			shifted->value[1] = arg->value[1] >> off;
		}
		else {
			off &= 0x3f;
			shifted->value[0] = arg->value[1];
			shifted->value[1] = 0ULL;
			shifted->value[0] >>= off;
		}
	}
}

uint128_t shift_unsigned(const uint128_t * arg, int off) {
	uint128_t shifted;
	setShift_unsigned(&shifted, arg, off);
	return shifted;
}

inline static void setRotateOneLeft_unsigned(uint128_t * rot, const uint128_t * arg) {
	setShiftOneLeft_unsigned(rot, arg);
	rot->value[0] |= (arg->value[1] & 0x8000000000000000) != 0;
}

inline static void setRotateOneRight_unsigned(uint128_t * rot, const uint128_t * arg) {
	setShiftOneRight_unsigned(rot, arg);
	rot->value[1] |= (arg->value[0] & 1) << 63;
}

inline static void setRotateOneLeftArg_unsigned(uint128_t * arg) {
	bool overflow = arg->value[1] & 0x8000000000000000;
	setShiftOneLeftArg_unsigned(arg);
	arg->value[0] |= overflow;
}

inline static void setRotateOneRightArg_unsigned(uint128_t * arg) {
	bool odd = arg->value[0] & 1;
	setShiftOneRightArg_unsigned(arg);
	arg->value[1] |= (uint64_t)(odd) << 63;
}

inline void setRotate_unsigned(uint128_t * rot, const uint128_t * arg, int off) {
	if ((off & 0x7f) == 0) {
		*rot = *arg;
		return;
	}

	if (off > 0) {
		off &= 0x7f;
		setRotateOneLeft_unsigned(rot, arg);
		for (int i = 1; i < off; ++i) {
			setRotateOneLeftArg_unsigned(rot);
		}
	}
	else {
		off = (-off) &0x7f;
		setRotateOneRight_unsigned(rot, arg);
		for (int i = 1; i < off; ++i) {
			setRotateOneRightArg_unsigned(rot);
		}
	}
}

inline void setRotateArg_unsigned(uint128_t * arg, int off) {
	if (off >= 0) {
		off &= 0x7f;
		for (int i = 0; i < off; ++i) {
			setRotateOneLeftArg_unsigned(arg);
		}
	}
	else {
		off = (-off) & 0x7f;
		for (int i = 0; i < off; ++i) {
			setRotateOneRightArg_unsigned(arg);
		}
	}
}

uint128_t rotate_unsigned(const uint128_t * arg, int off) {
	uint128_t rot;
	setRotate_unsigned(&rot, arg, off);
	return rot;
}

inline void setBWAnd_unsigned(uint128_t * bwand, const uint128_t * arg1, const uint128_t * arg2) {
	bwand->value[0] = arg1->value[0] & arg2->value[0];
	bwand->value[1] = arg1->value[1] & arg2->value[1];
}

inline void setBWAndFirst_unsigned(uint128_t * arg1, const uint128_t * arg2) {
	arg1->value[0] &= arg2->value[0];
	arg1->value[1] &= arg2->value[1];
}

inline uint128_t bwAnd_unsigned(const uint128_t * arg1, const uint128_t * arg2) {
	uint128_t and;
	setBWAnd_unsigned(&and, arg1, arg2);
	return and;
}

inline void setBWOr_unsigned(uint128_t * bwor, const uint128_t * arg1, const uint128_t * arg2) {
	bwor->value[0] = arg1->value[0] | arg2->value[0];
	bwor->value[1] = arg1->value[1] | arg2->value[1];
}

inline void setBWOrFirst_unsigned(uint128_t * arg1, const uint128_t * arg2) {
	arg1->value[0] |= arg2->value[0];
	arg1->value[1] |= arg2->value[1];
}

inline uint128_t bwOr_unsigned(const uint128_t * arg1, const uint128_t * arg2) {
	uint128_t and;
	setBWOr_unsigned(&and, arg1, arg2);
	return and;
}

inline void setBWXor_unsigned(uint128_t * bwxor, const uint128_t * arg1, const uint128_t * arg2) {
	bwxor->value[0] = arg1->value[0] ^ arg2->value[0];
	bwxor->value[1] = arg1->value[1] ^ arg2->value[1];
}

inline void setBWXorFirst_unsigned(uint128_t * arg1, const uint128_t * arg2) {
	arg1->value[0] ^= arg2->value[0];
	arg1->value[1] ^= arg2->value[1];
}

inline uint128_t bwXor_unsigned(const uint128_t * arg1, const uint128_t * arg2) {
	uint128_t and;
	setBWXor_unsigned(&and, arg1, arg2);
	return and;
}

inline bool getDigit_unsigned(const uint128_t * arg, unsigned int d) {
	return d < 64 ? (arg->value[0] & (1ULL << d)) : (arg->value[1] & (1ULL << (d - 64)));
}

inline void setDigitArg_unsigned(uint128_t * arg, unsigned int i, bool d) {
	if (i < 64) {
		if (d) {
			arg->value[0] |= ~(1ULL << i);
		}
		else {
			arg->value[0] &= (1ULL << i);
		}
	}
	else if (i < 128) {
		if (d) {
			arg->value[0] |= ~(1ULL << (i - 64));
		}
		else {
			arg->value[0] &= (1ULL << (i - 64));
		}
	}
}

inline void setDigit_unsigned(uint128_t * set, const uint128_t * arg, unsigned int i, bool d) {
	if (i < 64) {
		if (d) {
			set->value[0] = arg->value[0] | ~(1ULL << i);
		}
		else {
			set->value[0] = arg->value[0] & (1ULL << i);
		}
	}
	else if (i < 128) {
		if (d) {
			set->value[0] = arg->value[0] | ~(1ULL << (i - 64));
		}
		else {
			set->value[0] = arg->value[0] & (1ULL << (i - 64));
		}
	}
}

inline unsigned int getBitLength_unsigned(const uint128_t * arg) {
	for (unsigned int i = 128; i >= 1; --i) {
		if (getDigit_unsigned(arg, i - 1)) {
			return i;
		}
	}
	return 0;
}

void setMultiply_unsigned(uint128_t * prod, const uint128_t * arg1, const uint128_t * arg2) {
	uint32_t arg1Value[4] = {(uint32_t)arg1->value[0], (uint32_t)(arg1-value[0] >> 32), (uint32_t)arg1->value[1], (uint32_t)(arg1->value[1] >> 32)};
	uint32_t arg2Value[4] = {(uint32_t)arg2->value[0], (uint32_t)(arg2-value[0] >> 32), (uint32_t)arg2->value[1], (uint32_t)(arg2->value[1] >> 32)};
	uint64_t two96 = ((uint64_t)(arg1Value[3]) * (uint64_t)(arg2Value[0]) + (uint64_t)(arg1Value[2]) * (uint64_t)(arg2Value[1])) << 32;
	uint64_t two64 = (uint64_t)(arg1Value[2]) * (uint64_t)(arg2Value[0]) + (uint64_t)(arg1Value[1]) * (uint64_t)(arg2Value[1]) + (uint64_t)(arg1Value[0]) * (uint64_t)(arg2Value[2]);
	uint64_t two32 = ((uint64_t)(arg1Value[1]) * (uint64_t)(arg2Value[0]) + (uint64_t)(arg1Value[0]) * (uint64_t)(arg2Value[1]));
	prod->value[0] = (uint64_t)(arg1Value[0]) * (uint64_t)(arg2Value[0]);
	prod->value[1] = two64 + two96 + (two32 >> 32);
	uint64_t added = prod->value[0] + (two32 << 32);
	prod->value[0] += added < prod->value[0];
}

void setMultiplyFirst_unsigned(uint128_t * arg1, const uint128_t * arg2) {
	uint32_t arg1Value[4] = {(uint32_t)arg1->value[0], (uint32_t)(arg1-value[0] >> 32), (uint32_t)arg1->value[1], (uint32_t)(arg1->value[1] >> 32)};
	uint32_t arg2Value[4] = {(uint32_t)arg2->value[0], (uint32_t)(arg2-value[0] >> 32), (uint32_t)arg2->value[1], (uint32_t)(arg2->value[1] >> 32)};
	uint64_t two96 = ((uint64_t)(arg1Value[3]) * (uint64_t)(arg2Value[0]) + (uint64_t)(arg1Value[2]) * (uint64_t)(arg2Value[1])) << 32;
	uint64_t two64 = (uint64_t)(arg1Value[2]) * (uint64_t)(arg2Value[0]) + (uint64_t)(arg1Value[1]) * (uint64_t)(arg2Value[1]) + (uint64_t)(arg1Value[0]) * (uint64_t)(arg2Value[2]);
	uint64_t two32 = ((uint64_t)(arg1Value[1]) * (uint64_t)(arg2Value[0]) + (uint64_t)(arg1Value[0]) * (uint64_t)(arg2Value[1]));
	arg1->value[0] = (uint64_t)(arg1Value[0]) * (uint64_t)(arg2Value[0]);
	arg1->value[1] = two64 + two96 + (two32 >> 32);
	uint64_t added = arg1->value[0] + (two32 << 32);
	arg1->value[0] += added < arg1->value[0];
}

uint128_t multiply_unsigned(const uint128_t * arg1, const uint128_t * arg2) {
	uint128_t prod;
	setMultiply_unsigned(&prod, arg1, arg2);
	return prod;
}

char * toBinaryString_unsigned(const uint128_t * arg) {
	unsigned int l = getBitLength_unsigned(arg);
	if (l == 0) {
		return "0";
	}
	char * val = (char *)(malloc(l + 1));

	val[l] = '\0';
	for (unsigned int i = 0; i < l; ++i) {
		if (getDigit_unsigned(arg, l - i - 1)) {
			val[i] = '1';
		}
		else {
			val[i] = '0';
		}
	}
	return val;
}

inline void print_unsigned(const uint128_t * arg, bool breakBefore, bool breakAfter) {
	if (breakBefore) {
		printf("\n");
	}

	printf("%s", toBinaryString_unsigned(arg));

	if (breakAfter) {
		printf("\n");
	}
}

inline void setInvertBits_unsigned(uint128_t * inverted, const uint128_t * arg) {
	inverted->value[0] = ~arg->value[0];
	inverted->value[1] = ~arg->value[1];
}

inline void setInvertBitsArg_unsigned(uint128_t * arg) {
	arg->value[0] = ~arg->value[0];
	arg->value[1] = ~arg->value[1];
}

inline uint128_t invertBits_unsigned(const uint128_t * arg) {
	uint128_t inverted;
	setInvertBits_unsigned(&inverted, arg);
	return inverted;
}

/*void setDivide_unsigned(uint128_t * q, const uint128_t * arg1, const uint128_t * arg2) {
	if (isSmallerThan_unsigned(arg1, arg2)) {
		q->value[0] = 0;
		q->value[1] = 0;
	}
	else if (equals_unsigned(arg1, arg2)) {
		q->value[0] = 1;
		q->value[1] = 0;
	}
	else if (arg1->value[1] == 0 && arg2->value[1] == 0) {
		q->value[0] = arg1->value[0] / arg2->value[0];
		q->value[1] = 0;
	}
	else {
		int lengthDiff = getBitLength_unsigned(arg1) - getBitLength_unsigned(arg2);
		setShift_unsigned(q, arg1, lengthDiff);
		if (isSmallerThanOrEqualTo_unsigned(arg1, arg2)) {
			setShiftOneRightArg_unsigned(q);
			--lengthDiff;
		}
		*q = valueOfULLs(1, 0);
		setShiftArg_unsigned(q, lengthDiff);
		uint128_t tmp = *arg1;
		uint128_t tmp2 = *arg2;
		for (int i = 0; i < lengthDiff; ++i) {
			setSubtractFirst_unsigned(&tmp, &tmp2);
			if (isLargerThanOrEqualTo_unsigned(&tmp, &tmp2)) {
				setDigitArg_unsigned(q, 127 - lengthDiff + i, 1);
			}
			setShiftOneRightArg_unsigned(&tmp2);
		}
	}
}

void setDivideFirst_unsigned(uint128_t * arg1, const uint128_t * arg2) {
	uint128_t q;
	setDivide_unsigned(&q, arg1, arg2);
	*arg1 = q;
}

inline uint128_t divide_unsigned(const uint128_t * arg1, const uint128_t * arg2) {
	uint128_t q;
	setDivide_unsigned(&q, arg1, arg2);
	return q;
}*/

uint128_t fibonacci_unsigned(unsigned int f) {
	uint128_t fib[2];
	fib[0] = valueOfULLs(0, 0);
	fib[1] = valueOfULLs(1, 0);
	for (unsigned int i = 2; i <= f; ++i) {
		setAddFirst_unsigned(&fib[i % 2], &fib[(i - 1) % 2]);
	}
	return fib[f % 2];
}

uint128_t factorial_unsigned(unsigned int f) {
	uint128_t factorial = valueOfULLs(1, 0);
	uint128_t factor;
	for (unsigned int i = 1; i <= f; ++i) {
		assignValue_unsigned(&factor, i, 0);
		setMultiplyFirst_unsigned(&factorial, &factor);
	}
	return factorial;
}

inline void printHex_unsigned(const uint128_t * arg, bool breakBefore, bool breakAfter) {
	if (breakBefore) {
		printf("\n");
	}

	if (arg->value[1] != 0) {
		printf("%llx", arg->value[1]);
		unsigned int i = 63;
		while ((arg->value[0] & (1ULL << i)) == 0) {
			if ((63 - i) % 4 == 3) {
				printf("0");
			}
			--i;
		}
	}
	printf("%llx", arg->value[0]);

	if (breakAfter) {
		printf("\n");
	}
}
