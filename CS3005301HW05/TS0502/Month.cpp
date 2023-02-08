#include "Month.h"
#include <sstream>

std::string month_str[12] = {"Jan", "Feb", "Mar",
							 "Apr", "May", "Jun",
							 "Jul", "Aug", "Sep",
	                         "Oct", "Nov", "Dec"};
Month::Month()
{
	month = 1;
}

Month::Month(char first, char second, char third)
{
	std::string str, temp;

	month = 1;
	for (int i = 0; i < 12; ++i) {
		if (str == month_str[i]) {
			month = i + 1;
		}
	}
}

Month::Month(int monthInt)
{
	month = (monthInt < 1 || monthInt > 12) ? 1 : monthInt;
}


Month::~Month()
{
}

void Month::inputInt()
{
	int num;
	std::cin >> num;
	month = (num < 1 || num > 12) ? 1 : num;
}

void Month::inputStr()
{
	std::string in, str;
	for (int i = 0; i < 3; ++i) {
		std::cin >> in;
		str += in;
	}
	month = 1;
	for (int i = 0; i < 12; ++i) {
		if (str == month_str[i]) {
			month = i + 1;
		}
	}
}

void Month::outputInt()
{
	std::cout << month;
}

void Month::outputStr()
{
	std::cout << month_str[month - 1];
}

Month Month::nextMonth()
{
	return (month + 1 < 1 || month + 1 > 12) ? 1 : month + 1;
}
