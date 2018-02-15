// Rachel Crosley and Corey Gray
// kata2
// String Calculator Kata for CS372 from http://www.peterprovost.org/blog/2012/05/02/kata-the-only-way-to-learn-tdd/

#include <string>
#include <sstream>
#include <vector>

#include "catch.hpp"

int stringCalculator(const std::string & input) {
    std::istringstream stream(input);
	std::string token;
	int value = 0;
	std::vector<int> values;
	int sum = 0;

	if (input.empty())
		return 0;

	while (std::getline(stream, token, ',')) {
		stream >> value;
		values.push_back(value);
	}

	for (auto value : values)
		sum += value;

	return sum;
}

TEST_CASE("An empty string returns zero.", "[empty]") {
	REQUIRE(stringCalculator("") == 0);
}

TEST_CASE("single number returns a value", "[one number]") {
    REQUIRE(stringCalculator("1") == 1);
    REQUIRE(stringCalculator("2") == 2);
    REQUIRE(stringCalculator("2000") == 2000);
}

TEST_CASE("Two numbers, comma delimited, returns the sum", "[arithmetic]") {
	REQUIRE(stringCalculator("1,2") == 3);
	REQUIRE(stringCalculator("10,7") == 17);
	REQUIRE(stringCalculator("42,96") == 138);
}

