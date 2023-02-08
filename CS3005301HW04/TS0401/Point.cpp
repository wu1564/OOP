#include "Point.h"

void swap(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void Point::Set(int vertical, int horizontal) {
	Point::vertical = vertical;
	Point::horizontal = horizontal;
}

void Point::Move(int x, int y) {
	vertical += x;
	horizontal += y;
}

// (vertical, horizontal)
void Point::Rotate() {
	int temp;

	swap(vertical, horizontal);
	horizontal *= -1;
}
