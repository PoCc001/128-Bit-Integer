#ifndef UINT128_HPP
#define UINT128_HPP

#include <string>

// using the definitions of the operations from uint128.h to just call them in wrapper functions
extern "C" {
	#include "uint128.h"
}

namespace extint {
	class uint128 {
	private:
		uint128_t v;

	public:
		uint128(uint128_t value) {
			v = value;
		}

		uint128() {
			v = valueOfULLs(0, 0);
		}

		uint128(uint64_t value) {
			v = valueOfui64s(value, 0);
		}

		uint128(uint64_t value1, uint64_t value2) {
			v = valueOfui64s(value1, value2);
		}

		void operator+= (const uint128 &arg) {
			setAddFirst_unsigned(&this->v, &arg.v);
		}

		uint128 operator+ (const uint128 &arg) {
			return add_unsigned(&this->v, &arg.v);
		}

		void operator-= (const uint128 &arg) {
			setSubtractFirst_unsigned(&this->v, &arg.v);
		}

		uint128 operator- (const uint128 &arg) {
			return subtract_unsigned(&this->v, &arg.v);
		}

		void operator*= (const uint128 &arg) {
			setMultiplyFirst_unsigned(&this->v, &arg.v);
		}

		uint128 operator* (const uint128 &arg) {
			return multiply_unsigned(&this->v, &arg.v);
		}

		void operator<<= (int shift) {
			setShiftArg_unsigned(&this->v, shift);
		}

		uint128 operator<< (int shift) {
			return shift_unsigned(&this->v, shift);
		}

		void operator>>= (int shift) {
			setShiftArg_unsigned(&this->v, -shift);
		}

		uint128 operator>> (int shift) {
			return shift_unsigned(&this->v, -shift);
		}

		bool operator== (const uint128 &arg) {
			return equals_unsigned(&this->v, &arg.v);
		}

		bool operator!= (const uint128 &arg) {
			return notEquals_unsigned(&this->v, &arg.v);
		}

		bool operator> (const uint128 &arg) {
			return isLargerThan_unsigned(&this->v, &arg.v);
		}

		bool operator< (const uint128 &arg) {
			return isSmallerThan_unsigned(&this->v, &arg.v);
		}

		bool operator>= (const uint128 &arg) {
			return isLargerThanOrEqualTo_unsigned(&this->v, &arg.v);
		}

		bool operator<= (const uint128 &arg) {
			return isSmallerThanOrEqualTo_unsigned(&this->v, &arg.v);
		}

		void operator&= (const uint128 &arg) {
			setBWAndFirst_unsigned(&this->v, &arg.v);
		}

		uint128 operator& (const uint128 &arg) {
			return bwAnd_unsigned(&this->v, &arg.v);
		}

		void operator|= (const uint128 &arg) {
			setBWOrFirst_unsigned(&this->v, &arg.v);
		}

		uint128 operator| (const uint128 &arg) {
			return bwOr_unsigned(&this->v, &arg.v);
		}

		void operator^= (const uint128 &arg) {
			setBWXorFirst_unsigned(&this->v, &arg.v);
		}

		uint128 operator^ (const uint128 &arg) {
			return bwXor_unsigned(&this->v, &arg.v);
		}

		uint128 operator++ () {
			return postIncrement_unsigned(&this->v);
		}

		uint128& operator++ (int) {
			++this->v.value[0];
			this->v.value[1] += this->v.value[0] == 0ULL;
			return *this;
		}

		uint128 operator-- () {
			return postDecrement_unsigned(&this->v);
		}

		uint128& operator-- (int) {
			--this->v.value[0];
			this->v.value[1] -= this->v.value[0] == 0xffffffffffffffffULL;
			return *this;
		}

		uint128 operator~ () {
			return invertBits_unsigned(&this->v);
		}

		unsigned int getBitLength() {
			return getBitLength_unsigned(&this->v);
		}

		bool getDigit(unsigned int index) {
			return getDigit_unsigned(&this->v, index);
		}

		void setDigit(unsigned int index, bool d) {
			setDigitArg_unsigned(&this->v, index, d);
		}

		std::string toBinaryString() {
			return toBinaryString_unsigned(&this->v);
		}

		void printBinary(bool breakBefore, bool breakAfter) {
			print_unsigned(&this->v, breakBefore, breakAfter);
		}

		void printBinary() {
			print_unsigned(&this->v, 0, 1);
		}

		void printHex(bool breakBefore, bool breakAfter) {
			printHex_unsigned(&this->v, breakBefore, breakAfter);
		}

		void printHex() {
			printHex_unsigned(&this->v, 0, 1);
		}
	};

	uint128 fibonacci(unsigned int f) {
		return fibonacci_unsigned(f);
	}

	uint128 factorial(unsigned int f) {
		return factorial_unsigned(f);
	}
}

#endif
