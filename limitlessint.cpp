#include "limitlessint.hpp"
#include <cassert>

using namespace std;

LimitlessInt::LimitlessInt(Int n)
{
	digits.push_back(n);
}

void LimitlessInt::power(Int n)
{
	const auto words_count {n/WORD_WIDTH};
	const auto bits_shift {n%WORD_WIDTH};
	if (words_count) {
		powerWord(words_count);
	}
	if (bits_shift) {
		powerTwo(bits_shift);
	}
}

void LimitlessInt::powerTwo(Pos n)
{
	assert(n < WORD_WIDTH);
	Int last_bits {};
	for (size_t i{}; i < digits.size(); ++i) {
		auto& word {digits[i]};
		auto cur_last_bits {lastBits(word, n)};
		word <<= n;
		word |= last_bits;
		last_bits = cur_last_bits;
	}
	if (last_bits) {
		digits.push_back(last_bits);
	}
}

void LimitlessInt::powerWord(Int n)
{
	for (size_t i{}; i < n; ++i) {
		digits.push_front(0);
	}
}

void LimitlessInt::addTwoPowered(Pos n)
{

}

Int LimitlessInt::lastBits(Int word, Pos len)
{
	assert(len < WORD_WIDTH);
	const auto n {WORD_WIDTH - len};
	const auto last_bits {word >> n};
	return last_bits;
}


string LimitlessInt::toString() const
{
	string res;

	for (size_t i{digits.size()-1}; i != -1; --i) {
		res += ( bitRepresantation(digits[i]) + " ");
	}
	res.erase(res.end() - 1);

	return res;
}


string LimitlessInt::bitRepresantation(Int integralNumber) const {
	const auto digit_group {8};
	Int bit_mask {1};
	const auto len {digit_group*sizeof(Int)};
	auto shiftsCnt {len/digit_group - 1};

	string res(len + shiftsCnt, '0');
	for (int i{len-1}; i >= 0; --i) {
		auto writePos {i+shiftsCnt};
		if ( ((len - 1 - i)%digit_group == 0) && (i != len-1) ) {
			res[writePos] = ' ';
			--writePos;
			--shiftsCnt;
		}
		if (integralNumber & bit_mask) {
			res[writePos] = '1';
		} else {
			res[writePos] = '0';
		}
		integralNumber >>= 1;
	}
	return res;
}
