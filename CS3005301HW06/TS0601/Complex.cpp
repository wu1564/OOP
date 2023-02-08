#include "Complex.h"

Complex::Complex() {
	realValue = 0;
	imaginaryValue = 0;
}

//~Complex();
Complex::Complex(double r) {
	realValue = r;
	imaginaryValue = 0;
}

//~Complex(double r);
Complex::Complex(double r, double i) {
	realValue = r;
	imaginaryValue = i;
}

//~Complex(double r, double i);
double Complex::real() {
	return realValue;
}
double Complex::imag() {
	return imaginaryValue;
}

double Complex::norm() {
	return sqrt(pow(realValue, 2) + pow(imaginaryValue, 2));
}

// friend 
double real(Complex c) {
	return c.realValue;
}

double imag(Complex c) {
	return c.imaginaryValue;
}

double norm(Complex c) {
	return sqrt(pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
}

Complex Complex::operator+(Complex c) {
	Complex result;
	result.realValue = c.realValue + realValue;
	result.imaginaryValue = c.imaginaryValue + imaginaryValue;
	return result;
}

Complex Complex::operator-(Complex c) {
	Complex result;
	result.realValue = realValue - c.realValue;
	result.imaginaryValue = imaginaryValue - c.imaginaryValue;
	return result;
}

Complex Complex::operator*(Complex c) {
	Complex result;
	result.realValue = realValue * c.realValue - imaginaryValue * c.imaginaryValue;
	result.imaginaryValue = imaginaryValue * c.realValue + realValue * c.imaginaryValue;
	return result;
}

Complex Complex::operator/(Complex c) {
	Complex result;
	double d;
	d = pow(c.realValue, 2) + pow(c.imaginaryValue, 2);
	result.realValue = (realValue * c.realValue + imaginaryValue * c.imaginaryValue) / d;
	result.imaginaryValue = (imaginaryValue * c.realValue - realValue * c.imaginaryValue) / d;
	return result;
}

// friend
Complex operator+(double d, Complex c) {
	Complex result = c;
	result.realValue += d;
	return result;
}

Complex operator-(double d, Complex c) {
	Complex result = c;
	result.realValue = d - c.realValue;
	result.imaginaryValue = -c.imaginaryValue;
	return result;
}

Complex operator*(double d, Complex c) {
	Complex result = c;
	result.realValue *= d;
	result.imaginaryValue *= d;
	return result;
}

Complex operator/(double d, Complex c) {
	Complex result;
	double n = pow(c.realValue, 2) + pow(c.imaginaryValue, 2);
	result.realValue = c.realValue * d / n;
	result.imaginaryValue = (c.imaginaryValue * -d) / n;
	return result;
}

bool operator==(Complex c1, Complex c2) {
	if (c1.realValue == c2.realValue && c1.imaginaryValue == c2.imaginaryValue) {
		return 1;
	}
	return 0;
}

ostream& operator<<(ostream& strm, const Complex& c) {
	strm << c.realValue << " + " << c.imaginaryValue << "*i";
	return strm;
}

istream& operator>>(istream& strm, Complex& c) {
	string str;
	getline(strm, str);
	c.realValue = stoi(str.substr(str.find('=') + 2, str.find('+') - 2 - str.find('=')));
	c.imaginaryValue = stoi(str.substr(str.find('+') + 1, str.find('*') - str.find('+') - 1));
	return strm;
}
