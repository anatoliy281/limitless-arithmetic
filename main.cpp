#include <iostream>
#include <string>

#include <math.h>
#include <vector>
#include <bitset>
#include <cassert>

#include "limitlessint.hpp"

using namespace std;

template <typename T>
int length() {
	T bit {1};
	unsigned int i {0};
	while (bit) {
		bit <<= 1;
		i++;
	}
	return i;
}

template <>
int length<bool>() {
	return 8*sizeof(bool);
}

template <typename T>
string bitRepresantation(T integralNumber) {
	const auto digit_group {8};
	T bit_mask{1};
	const auto len {length<T>()};
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

//void shiftBitsDemo() {
//	unsigned int x {1}, i {0};
//	cout << 0 << "\tshift:\t" << x << "\t\t" << bitRepresantation(x) << endl;
//	while (x) {
//		x <<= 1;
//		cout << ++i << "\tshift:\t" << x << "\t\t" << bitRepresantation(x) << endl;
//	}
//}


//bitset<121> bits;

using Number10 = vector<short>;

void factor2(Number10& number) {
	short one{};
	for (size_t i{}; i < number.size(); ++i) {
		auto& digit {number[i]};
		const auto factored {2*digit};
		digit = factored%10 + one;
		one = factored / 10;
	}
	if (one) {
		number.push_back(1);
	}
}

Number10& power2(Number10& number, size_t n) {
	for (size_t i{2}; i <= n; ++i) {
		factor2(number);
	}
	return number;
}

Number10 add(const Number10& n1, const Number10& n2) {
	assert(n1.size() >= n2.size());
	Number10 res(n1.size());
	short one{};
	size_t i{};
	for (; i < n2.size(); ++i) {
		const auto sum {n1[i] + n2[i] + one};
		res[i] = sum%10;
		one = sum/10;
	}
	for (; i < n1.size(); ++i) {
		const auto sum {one + n1[i]};
		res[i] = sum%10;
		one = sum/10;
	}
	if (one) {
		res.push_back(1);
	}
	return res;
}


ostream& operator<<(ostream& os, Number10 number) {
	const auto bIt {number.rbegin()}, eIt{number.rend()};
	auto it {bIt};
	for (; it != eIt; ++it) {
		os << std::to_string(*it);
	}
	return os;
}


//vector<unsigned int> convert() {
//	const auto sz1 {bits.size()};
//	const auto sz2 {8*sizeof (unsigned int)};
//	const auto sz {1 + sz1 / sz2};
//	vector<unsigned int> res(sz);

//	for (size_t i{}; i < sz1; ++i) {
//		if (bits[i]) {
//			const auto k {i/sz2};
//			const auto ii {i%sz2};
//			res[k] += pow(2, ii);
//		}
//	}

//	return res;
//}


int main()
{
//	shiftBitsDemo();

//	cout << "--- " << length<unsigned int>() << endl;

//	bits.flip();

//	bits[31] = true;

//	cout << bits << endl;

//	Number10 number {1};
//	int i;
//	cout << "pow(2, " << i << ") = " << number << "   " << number.size() << " digits - "  << endl;
//	for (; i < 700; ++i) {
//		factor2(number);
//		cout << "pow(2, " << i+1 << ") = " << number << "   " << number.size() << " digits - "  << endl;
//	}


//	Number10 a {3,1, 2, 1};
//	Number10 b {7, 2, 1};
//	const auto c = add(a, b);

//	cout << c << endl;

//	Number10 m {2};
//	cout << power2(m, 7000) << endl;


////	cout << length<unsigned long long int>() << " " << 8*sizeof(unsigned long long int) << endl;

//	unsigned long long int x {255};
//	cout << bitRepresantation(x) << endl;

	LimitlessInt a(10);

	cout << a.toString() << endl;

	return 0;
}
