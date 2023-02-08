#include "Template.h"

int absoluteValue(char a, char b) {
	return (int)abs(a - b);
}

template<> float absoluteValue(float a, float b) {
	return abs(a - b);
}
template<> double absoluteValue(double a, double b) {
	return abs(a - b);
}

template<> int absoluteValue(int a, int b) {
	return abs(a - b);
}