#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
public:
	Polynomial();
	Polynomial(const Polynomial &poly);
	Polynomial(double* param, int size);
	int mySize();
	double& operator[](int index);
	Polynomial& operator=(const Polynomial &poly);
	Polynomial operator+(Polynomial &poly);
	Polynomial operator-(Polynomial &poly);
	Polynomial operator*(Polynomial &poly);
	friend double evaluate(const Polynomial &poly, const double &var);
	friend Polynomial operator+(double c, Polynomial &poly);
	friend Polynomial operator+(Polynomial &poly, double c);
	friend Polynomial operator-(double c, Polynomial &poly);
	friend Polynomial operator-(Polynomial &poly, double c);
	friend Polynomial operator*(double constant, Polynomial &poly);
	friend Polynomial operator*(Polynomial &poly, double constant);
	~Polynomial ();
	
private:
	double* num;
	int size;
};
