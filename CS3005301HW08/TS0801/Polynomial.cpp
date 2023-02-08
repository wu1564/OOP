#include "Polynomial.h"

Polynomial::Polynomial()
{
	num = new double;
	*num = 0;
	size = 1;
}

Polynomial::Polynomial(const Polynomial &poly) {
	size = poly.size;
	num = new double[size];
	for (int i = 0; i < size; ++i) {
		num[i] = poly.num[i];
	}
}

Polynomial::Polynomial(double* param, int size) {
	this->size = size;
	num = new double[this->size];
	for (int i = 0; i < this->size; ++i) num[i] = param[i];
}

int Polynomial::mySize() {
	int i;
	for (i = size - 1; i >= 0; --i) if (num[i] != 0) break;
	return (size == 1 || i <= 0) ? 1 : i+1;
}

double evaluate(const Polynomial& poly, const double& var) {
	double result = 0;

	for (int i = 0; i < poly.size; ++i) {
		result += pow(var, i) * poly.num[i];
	}
	return result;
}

Polynomial& Polynomial::operator=(const Polynomial &poly) {
	if (size != poly.size) {
		delete[] num;
		size = poly.size;
		num = new double[size];
	}
	for (int i = 0; i < size; ++i) {
		num[i] = poly.num[i];
	}
	return *this;
}

double& Polynomial::operator[](int index) {
	double* ptr;
	if (index >= size) {
		ptr = num;
		num = new double[index + 1];
		fill(num, num + index + 1,0);
		for (int i = 0; i < size; ++i) num[i] = ptr[i];
		size = index + 1;
		delete[] ptr;
	}
	return num[index];
}

Polynomial Polynomial::operator+(Polynomial& poly) {
	Polynomial result;
	
	result.size = (poly.size > size) ? poly.size : size;
	result.num = new double[result.size];
	fill(result.num, result.num+result.size,0);
	for (int i = 0; i < poly.size; ++i) result.num[i] += poly.num[i];
	for (int i = 0; i < size; ++i) result.num[i] += num[i];
	return result;
}

Polynomial Polynomial::operator-(Polynomial& poly) {
	Polynomial result;
	int i;

	result.size = (poly.size > size) ? poly.size : size;
	result.num = new double[result.size];
	fill(result.num, result.num+result.size, 0);
	for (int i = 0; i < size; ++i) result.num[i] = num[i];
	for (int i = 0; i < poly.size; ++i) result.num[i] -= poly[i];
	return result;
}

Polynomial Polynomial::operator*(Polynomial& poly) {
	Polynomial result;
	int i, outSize, innerSize;

	outSize = mySize()-1;
	innerSize = poly.mySize()-1;
	result.size = outSize + innerSize + 1;
	result.num = new double[result.size];
	fill(result.num, result.num + result.size, 0);
	for (int i = 0; i <= outSize; ++i) {
		for (int j = 0; j <= innerSize; ++j) {
			result.num[i + j] += num[i] * poly.num[j];
		}
	}
	return result;
}

Polynomial operator+(double c, Polynomial &poly) {
	Polynomial result = poly;
	result.num[0] += c;
	return result;
}

Polynomial operator+(Polynomial &poly, double c) {
	Polynomial result = poly;
	result.num[0] += c;
	return result;
}

Polynomial operator-(double c, Polynomial &poly) {
	Polynomial result = poly;
	for (int i = 0; i < result.size; ++i) {
		result.num[i] *= -1;
	}
	result.num[0] += c;
	return result;
}

Polynomial operator-(Polynomial &poly, double c) {
	Polynomial result = poly;
	result.num[0] -= c;
	return result;
}

Polynomial operator*(double constant, Polynomial &poly) {
	Polynomial result = poly;
	for (int i = 0; i < result.size; ++i) {
		result.num[i] *= constant;
	}
	return result;
}

Polynomial operator*(Polynomial &poly, double constant) {
	Polynomial result = poly;
	for (int i = 0; i < poly.size; ++i) {
		result.num[i] *= constant;
	}
	return result;
}

Polynomial ::~Polynomial()
{
	delete [] num;
}
