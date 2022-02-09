#include <catch2/catch_test_macros.hpp>

#include <iostream>

#include "../limitlessint.hpp"

using namespace std;

TEST_CASE("String represantation", "[repr]") {
	LimitlessInt x(10);
	REQUIRE(x.toString() == "00000000 00000000 00000000 00000000 00000000 00000000 00000000 00001010");

	auto y {x};
//	for (size_t i{}; i < 64; ++i) {
//		x.powerTwo();
//		cout << x.toString() << endl;
//	}

//	y.powerTwo(63);
//	cout << y.toString() << endl;
//	y.powerTwo();
//	cout << y.toString() << endl;

	y.power(66);
	cout << y.toString() << endl;
}
