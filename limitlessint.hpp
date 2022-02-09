#ifndef LIMITLESSINT_HPP
#define LIMITLESSINT_HPP

#include <vector>
#include <deque>
#include <string>

using Int = unsigned long long int;
using Pos = unsigned short;



class LimitlessInt
{
	static constexpr auto WORD_WIDTH {8*sizeof(Int)};
	std::deque<Int> digits;

public:
	void power(Int n);
	void powerTwo(Pos n = 1);
	void powerWord(Int n = 1);
	void addTwoPowered(Pos n);
	Int lastBits(Int word, Pos len);

	std::string bitRepresantation(Int integralNumber) const;

public:
	LimitlessInt() = default;
	LimitlessInt(const LimitlessInt& limitless) = default;
	LimitlessInt(Int n);
	LimitlessInt& operator=(const LimitlessInt& limitless) = default;
	~LimitlessInt() = default;

	std::string toString() const;
};

#endif // LIMITLESSINT_HPP
