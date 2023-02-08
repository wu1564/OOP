#include <iostream>
#include <vector>
#include "Matrix.h"

//#define TEST
#ifdef TEST
#include <iostream>
#include <iomanip>

struct A
{
	enum { Rows = 3, Cols = 4 };
	int matrix[Rows][Cols];
	int(&operator [](size_t i))[Cols]
	{
		return matrix[i];
	}
};

int main()
{
	A a;

	for (size_t i = 0; i < a.Rows; i++)
	{
		for (size_t j = 0; j < a.Cols; j++) a[i][j] = a.Cols * i + j;
	}


	for (size_t i = 0; i < a.Rows; i++)
	{
		for (size_t j = 0; j < a.Cols; j++) std::cout << std::setw(2) << a[i][j] << ' ';
		std::cout << std::endl;
	}
}
#else

using namespace std;

void multiply(Matrix &a, Matrix &b) {
	int num = 0;
	if (a.getColumn() != b.getRow()) {
		cout << "Matrix multiplication failed.";
		return;
	}
	for (int row = 0; row < a.getRow(); ++row) {
		for (int col = 0; col < b.getColumn(); ++col) {
			for (int times = 0; times < a.getColumn(); ++times) {
				num += a.getNum(row, times) * b.getNum(times, col);
			}
			cout << num;
			if(col < b.getColumn()-1) cout << " ";
			num = 0;
		}
		cout << endl;
	}
}

int main(void) {
	int row, col;
	
	cin >> row >> col;
	Matrix a(row, col);
	cin >> row >> col;
	Matrix b(row, col);
	for (int i = 0; i < a.totalNum(); ++i) {
		cin >> row;
		a.giveData(row);
	}
	for (int i = 0; i < b.totalNum(); ++i) {
		cin >> row;
		b.giveData(row);
	}
	multiply(a, b);
}

#endif
