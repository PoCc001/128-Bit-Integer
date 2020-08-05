#ifndef SINT128_HPP
#define SINT128_HPP

#include <string>
// using the definitions of the operations from sint128.h to just call them in wrapper functions
extern "C" {
	#include "sint128.h"
}
using namespace std;

namespace extint {
	class sint128 {
	private:
		sint128_t v;

	public:
		sint128(sint128_t value) {
			v = value;
		}

		sint128() {
			v = valueOfLLs(0, 0);
		}

		sint128(long long value) {
			v = valueOfLLs(value, 0);
		}

		sint128(long long value1, long long value2) {
			v = valueOfLLs(value1, value2);
		}

		void operator+= (const sint128 &arg) {
			setAddFirst_signed(&this->v, &arg.v);
		}

		sint128 operator+ (const sint128 &arg) {
			return add_signed(&this->v, &arg.v);
		}

		void operator-= (const sint128 &arg) {
			setSubtractFirst_signed(&this->v, &arg.v);
		}

		sint128 operator- (const sint128 &arg) {
			return subtract_signed(&this->v, &arg.v);
		}

		void operator*= (const sint128 &arg) {
			setMultiplyFirst_signed(&this->v, &arg.v);
		}

		sint128 operator* (const sint128 &arg) {
			return multiply_signed(&this->v, &arg.v);
		}

		void operator<<= (int shift) {
			setShiftArg_signed(&this->v, shift);
		}

		sint128 operator<< (int shift) {
			return shift_signed(&this->v, shift);
		}

		void operator>>= (int shift) {
			setShiftArg_signed(&this->v, -shift);
		}

		sint128 operator>> (int shift) {
			return shift_signed(&this->v, -shift);
		}

		bool operator== (const sint128 &arg) {
			return equals_signed(&this->v, &arg.v);
		}

		bool operator!= (const sint128 &arg) {
			return notEquals_signed(&this->v, &arg.v);
		}

		bool operator> (const sint128 &arg) {
			return isLargerThan_signed(&this->v, &arg.v);
		}

		bool operator< (const sint128 &arg) {
			return isSmallerThan_signed(&this->v, &arg.v);
		}

		bool operator>= (const sint128 &arg) {
			return isLargerThanOrEqualTo_signed(&this->v, &arg.v);
		}

		bool operator<= (const sint128 &arg) {
			return isSmallerThanOrEqualTo_signed(&this->v, &arg.v);
		}

		void operator&= (const sint128 &arg) {
			setBWAndFirst_signed(&this->v, &arg.v);
		}

		sint128 operator& (const sint128 &arg) {
			return bwAnd_signed(&this->v, &arg.v);
		}

		void operator|= (const sint128 &arg) {
			setBWOrFirst_signed(&this->v, &arg.v);
		}

		sint128 operator| (const sint128 &arg) {
			return bwOr_signed(&this->v, &arg.v);
		}

		void operator^= (const sint128 &arg) {
			setBWXorFirst_signed(&this->v, &arg.v);
		}

		sint128 operator^ (const sint128 &arg) {
			return bwXor_signed(&this->v, &arg.v);
		}

		sint128 operator++ () {
			return postIncrement_signed(&this->v);
		}

		sint128& operator++ (int) {
			++this->v.value.value[0];
			this->v.value.value[1] += this->v.value.value[0] == 0ULL;
			return *this;
		}

		sint128 operator-- () {
			return postDecrement_signed(&this->v);
		}

		sint128& operator-- (int) {
			--this->v.value.value[0];
			this->v.value.value[1] -= this->v.value.value[0] == 0xffffffffffffffffULL;
			return *this;
		}

		sint128 operator~ () {
			return invertBits_signed(&this->v);
		}

		string toBinaryString(bool twoscomplement) {
			return toBinaryString_signed(&this->v, twoscomplement);
		}

		string toBinaryString() {
			return toBinaryString_signed(&this->v, 0);
		}

		void printBinary(bool twoscomplement, bool breakBefore, bool breakAfter) {
			print_signed(&this->v, twoscomplement, breakBefore, breakAfter);
		}

		void printBinary(bool breakBefore, bool breakAfter) {
			print_signed(&this->v, 0, breakBefore, breakAfter);
		}

		void printBinary() {
			print_signed(&this->v, 0, 0, 1);
		}

		void printHex(bool twoscomplement, bool breakBefore, bool breakAfter) {
			printHex_signed(&this->v, twoscomplement, breakBefore, breakAfter);
		}

		void printHex(bool breakBefore, bool breakAfter) {
			printHex_signed(&this->v, 0, breakBefore, breakAfter);
		}

		void printHex() {
			printHex_signed(&this->v, 0, 0, 1);
		}
	};
}

#endif
