#include "PrimeNumber.h"

bool isPrime(int number) {
	if (number == 1 || number == 2) return 1;
	for (int i = 2; i < number; ++i) {
		if (number % i == 0) {
			return 0;
		}
	}
	return 1;
}

int PrimeNumber::get() {
	return value;
}

PrimeNumber::PrimeNumber() {
	value = 1;
}

PrimeNumber::PrimeNumber(int _value) {
	value = _value;
}

PrimeNumber& PrimeNumber::operator++() {
	PrimeNumber &p = *this;
	p.value += 1;
	while (!isPrime(p.value)) {
		p.value += 1;
	}
	return p;
}

PrimeNumber PrimeNumber::operator++(int) {
	PrimeNumber p;
	p.value = value;
	value += 1;
	while (!isPrime(value)) {
		value += 1;
	}
	return p;
}

PrimeNumber& PrimeNumber::operator--() {
	PrimeNumber &p = *this;
	p.value -= 1;
	while (!isPrime(p.value) && p.value != 1) {
		p.value -= 1;
	}
	return p;
}

PrimeNumber PrimeNumber::operator--(int) {
	PrimeNumber p;
	p.value = value;
	value -= 1;
	while (!isPrime(value) && value != 1) {
		value -= 1;
	}
	return p;
}
