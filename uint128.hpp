#ifndef UINT128_HPP
#define UINT128_HPP

#include <string>

// using the definitions of the operations from uint128.h to just call them in wrapper functions
extern "C" {
	#include "uint128.h"
}
using namespace std;

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

		uint128(unsigned long long value) {
			v = valueOfULLs(value, 0);
		}

		uint128(unsigned long long value1, unsigned long long value2) {
			v = valueOfULLs(value1, value2);
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

		string toBinaryString() {
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
}

#endif