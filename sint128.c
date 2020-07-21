#include "uint128.h"
#include "sint128.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

inline void setAddFirst_signed(sint128_t * arg1, const sint128_t * arg2) {
	setAddFirst_unsigned(&arg1->value, &arg2->value);
}

inline void setAdd_signed(sint128_t * sum, const sint128_t * arg1, const sint128_t * arg2) {
	setAdd_unsigned(&sum->value, &arg1->value, &arg2->value);
}

inline sint128_t add_signed(const sint128_t * arg1, const sint128_t * arg2) {
	sint128_t sum = *arg1;
	setAdd_signed(&sum, arg1, arg2);
	return sum;
}

inline void assignValue_signed(sint128_t * number, long long value1, long long value2) {
	assignValue_unsigned(&number->value, (unsigned long long)(value1), (unsigned long long)(value2));
}

inline sint128_t valueOfLLs(long long value1, long long value2) {
	sint128_t new_number;
	assignValue_signed(&new_number, value1, value2);
	return new_number;
}

inline static bool lastBit(const sint128_t * arg) {
	return arg->value.value[1] & 0x8000000000000000;
}

inline bool isLargerThan_signed(const sint128_t * arg1, const sint128_t * arg2) {
	if ((long long)(arg1->value.value[1]) > (long long)(arg2->value.value[1])) {
		return 1;
	}
	else if (arg1->value.value[1] == arg2->value.value[1] && arg1->value.value[0] > arg2->value.value[0]) {
		return 1;
	}
	else {
		return 0;
	}
}

inline bool isSmallerThan_signed(const sint128_t * arg1, const sint128_t * arg2) {
	if ((long long)(arg1->value.value[1]) < (long long)(arg2->value.value[1])) {
		return 1;
	}
	else if (arg1->value.value[1] == arg2->value.value[1] && arg1->value.value[0] < arg2->value.value[0]) {
		return 1;
	}
	else {
		return 0;
	}
}

inline bool isLargerThanOrEqualTo_signed(const sint128_t * arg1, const sint128_t * arg2) {
	return !isSmallerThan_signed(arg1, arg2);
}

inline bool isSmallerThanOrEqualTo_signed(const sint128_t * arg1, const sint128_t * arg2) {
	return !isLargerThan_signed(arg1, arg2);
}

inline bool equals_signed(const sint128_t * arg1, const sint128_t * arg2) {
	return equals_unsigned(&arg1->value, &arg2->value);
}

inline bool notEquals_signed(const sint128_t * arg1, const sint128_t * arg2) {
	return notEquals_unsigned(&arg1->value, &arg2->value);
}

int compare_signed(const sint128_t * arg1, const sint128_t * arg2) {
	if (equals_signed(arg1, arg2)) {
		return 0;
	}
	else if (isLargerThan_signed(arg1, arg2)) {
		return 1;
	}
	else {
		return -1;
	}
}

inline void setSubtractFirst_signed(sint128_t * arg1, const sint128_t * arg2) {
	setSubtractFirst_unsigned(&arg1->value, &arg2->value);
}

inline void setSubtract_signed(sint128_t * diff, const sint128_t * arg1, const sint128_t * arg2) {
	setSubtract_unsigned(&diff->value, &arg1->value, &arg2->value);
}

inline sint128_t subtract_signed(const sint128_t * arg1, const sint128_t * arg2) {
	sint128_t diff;
	setSubtract_signed(&diff, arg1, arg2);
	return diff;
}

inline void setShiftArg_signed(sint128_t * arg, int off) {
	setShiftArg_unsigned(&arg->value, off);
}

inline void setShift_signed(sint128_t * shifted, const sint128_t * arg, int off) {
	setShift_unsigned(&shifted->value, &arg->value, off);
}

sint128_t shift_signed(const sint128_t * arg, int off) {
	sint128_t shifted;
	setShift_signed(&shifted, arg, off);
	return shifted;
}

inline void setBWAnd_signed(sint128_t * and, const sint128_t * arg1, const sint128_t * arg2) {
	setBWAnd_unsigned(&and->value, &arg1->value, &arg2->value);
}

inline void setBWAndFirst_signed(sint128_t * arg1, const sint128_t * arg2) {
	setBWAndFirst_unsigned(&arg1->value, &arg2->value);
}

inline sint128_t bwAnd_signed(const sint128_t * arg1, const sint128_t * arg2) {
	sint128_t bw_and;
	setBWAnd_signed(&bw_and, arg1, arg2);
	return bw_and;
}

inline void setBWOr_signed(sint128_t * or, const sint128_t * arg1, const sint128_t * arg2) {
	setBWOr_unsigned(&or->value, &arg1->value, &arg2->value);
}

inline void setBWOrFirst_signed(sint128_t * arg1, const sint128_t * arg2) {
	setBWOrFirst_unsigned(&arg1->value, &arg2->value);
}

inline sint128_t bwOr_signed(const sint128_t * arg1, const sint128_t * arg2) {
	sint128_t bw_or;
	setBWOr_signed(&bw_or, arg1, arg2);
	return bw_or;
}

inline void setBWXor_signed(sint128_t * xor, const sint128_t * arg1, const sint128_t * arg2) {
	setBWXor_unsigned(&xor->value, &arg1->value, &arg2->value);
}

inline void setBWXorFirst_signed(sint128_t * arg1, const sint128_t * arg2) {
	setBWXorFirst_unsigned(&arg1->value, &arg2->value);
}

inline sint128_t bwXor_signed(const sint128_t * arg1, const sint128_t * arg2) {
	sint128_t xor;
	setBWXor_signed(&xor, arg1, arg2);
	return xor;
}

inline bool isNegative(const sint128_t * arg) {
	return lastBit(arg);
}

inline void setInvertBits_signed(sint128_t * inverted, const sint128_t * arg) {
	setInvertBits_unsigned(&inverted->value, &arg->value);
}

inline void setInvertBitsArg_signed(sint128_t * arg) {
	setInvertBitsArg_unsigned(&arg->value);
}

inline sint128_t invertBits_signed(const sint128_t * arg) {
	sint128_t inverted;
	setInvertBits_signed(&inverted, arg);
	return inverted;
}

inline void setNegative(sint128_t * neg, const sint128_t * arg) {
	setInvertBits_signed(neg, arg);
	neg->value.value[0] += 1;
	neg->value.value[1] += neg->value.value[0] == 0;
}

inline void setNegativeArg(sint128_t * arg) {
	setInvertBitsArg_unsigned(&arg->value);
	arg->value.value[0] += 1;
	arg->value.value[1] += arg->value.value[0] == 0;
}

inline sint128_t negate(const sint128_t * arg) {
	sint128_t neg;
	setNegative(&neg, arg);
	return neg;
}

void setAbs_128(sint128_t * abs, const sint128_t * arg) {
	if (isNegative(arg)) {
		setNegative(abs, arg);
	}
	else {
		*abs = *arg;
	}
}

void setAbsArg_128(sint128_t * arg) {
	if (isNegative(arg)) {
		setNegativeArg(arg);
	}
}

inline sint128_t abs_128(const sint128_t * arg) {
	sint128_t abs;
	setAbs_128(&abs, arg);
	return abs;
}

inline void increment_signed(sint128_t * arg) {
	increment_unsigned(&arg->value);
}

inline void decrement_signed(sint128_t * arg) {
	decrement_unsigned(&arg->value);
}

inline sint128_t postIncrement_signed(sint128_t * arg) {
	sint128_t t = *arg;
	increment_signed(arg);
	return t;
}

inline sint128_t preIncrement_signed(sint128_t * arg) {
	increment_signed(arg);
	return *arg;
}

inline sint128_t postDecrement_signed(sint128_t * arg) {
	sint128_t t = *arg;
	decrement_signed(arg);
	return t;
}

inline sint128_t preDecrement_signed(sint128_t * arg) {
	decrement_signed(arg);
	return *arg;
}

void setMultiply_signed(sint128_t * prod, const sint128_t * arg1, const sint128_t * arg2) {
	sint128_t abs1;
	sint128_t abs2;
	setAbs_128(&abs1, arg1);
	setAbs_128(&abs2, arg2);
	setMultiply_unsigned(&prod->value, &abs1.value, &abs2.value);
	if (isNegative(arg1) != isNegative(arg2)) {
		setNegativeArg(prod);
	}
}

void setMultiplyFirst_signed(sint128_t * arg1, const sint128_t * arg2) {
	sint128_t abs;
	setAbs_128(&abs, arg2);
	bool neg = isNegative(arg1);
	setAbsArg_128(arg1);
	setMultiplyFirst_unsigned(&arg1->value, &abs.value);
	if (isNegative(arg2) != neg) {
		setNegativeArg(arg1);
	}
}

inline sint128_t multiply_signed(const sint128_t * arg1, const sint128_t * arg2) {
	sint128_t prod;
	setMultiply_signed(&prod, arg1, arg2);
	return prod;
}

/*void setDivide_signed(sint128_t * q, const sint128_t * arg1, const sint128_t * arg2) {
	sint128_t abs1;
	sint128_t abs2;
	setAbs_128(&abs1, arg1);
	setAbs_128(&abs2, arg2);
	setDivide_unsigned(&q->value, &abs1.value, &abs2.value);
	if (isNegative(arg1) != isNegative(arg2)) {
		setNegativeArg(q);
	}
}

void setDivideFirst_signed(sint128_t * arg1, const sint128_t * arg2) {
	sint128_t abs;
	setAbs_128(&abs, arg2);
	bool neg = isNegative(arg1);
	setAbsArg_128(arg1);
	setDivideFirst_unsigned(&arg1->value, &abs.value);
	if (isNegative(arg2) != neg) {
		setNegativeArg(arg1);
	}
}

inline sint128_t divide_signed(const sint128_t * arg1, const sint128_t * arg2) {
	sint128_t q;
	setDivide_signed(&q, arg1, arg2);
	return q;
}*/

inline sint128_t fibonacci_signed(unsigned int f) {
	sint128_t fibonacci;
	fibonacci.value = fibonacci_unsigned(f);
	return fibonacci;
}

inline sint128_t factorial_signed(unsigned int f) {
	sint128_t factorial;
	factorial.value = factorial_unsigned(f);
	return factorial;
}

inline unsigned int getBitLength_signed(const sint128_t * arg, bool twoscomplement) {
	if (twoscomplement) {
		return getBitLength_unsigned(&arg->value);
	}
	else {
		sint128_t n = negate(arg);
		return getBitLength_unsigned(&n.value);
	}
}

inline bool getDigit_signed(const sint128_t * arg, unsigned int d, bool twoscomplement) {
	if (twoscomplement) {
		return getDigit_unsigned(&arg->value, d);
	}
	else {
		if (!isNegative(arg)) {
			return getDigit_unsigned(&arg->value, d);
		}
		else {
			sint128_t absArg = negate(arg);
			return getDigit_unsigned(&absArg.value, d);
		}
	}
}

char * toBinaryString_signed(const sint128_t * arg, bool twoscomplement) {
	if (!isNegative(arg)) {
		return toBinaryString_unsigned(&arg->value);
	}
	else {
		if (twoscomplement) {
			return toBinaryString_unsigned(&arg->value);
		}
		else {
			unsigned int l = getBitLength_signed(arg, 0);
			if (l == 0) {
				return "0";
			}

			char * val = (char *)(malloc(l + 2));

			val[0] = '-';
			val[l + 1] = '\0';
			for (unsigned int i = l; i > 0; --i) {
				if (getDigit_signed(arg, i - 1, 0)) {
					val[l - i + 1] = '1';
				}
				else {
					val[l - i + 1] = '0';
				}
			}
			return val;
		}
	}
}

inline void print_signed(const sint128_t * arg, bool twoscomplement, bool breakBefore, bool breakAfter) {
	if (breakBefore) {
		printf("\n");
	}
	printf(toBinaryString_signed(arg, twoscomplement));

	if (breakAfter) {
		printf("\n");
	}
}
