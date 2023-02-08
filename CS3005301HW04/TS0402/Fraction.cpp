#include "Fraction.h"

void Fraction::setNumerator(int nu)
{
	numerator = nu;
}

void Fraction::setDenominator(int de)
{
	denominator = de;
}

void Fraction::getDouble()
{
	double result = (double)numerator / (double)denominator;
	
	if(result - (int)result > 0) {
		cout << setprecision(6) << fixed;
		cout << result << endl;
	} else {
		cout << defaultfloat;
		cout << (int)result << endl;
	}
}

void Fraction::outputReducedFraction()
{
	double res = (double)numerator / (double)denominator;
	int small = (numerator > denominator) ? denominator : numerator;
	int max = 1;

	for (int i = 1; i <= small; ++i) {
		if (denominator % i == 0 && numerator % i == 0) {
			max = i;
		}
	}
	if (res - (int)res == 0) {
		cout << res << endl;
	} else {
		cout << setprecision(6) << fixed;
		cout << numerator / max << "/" << denominator / max << endl;
	}
}
