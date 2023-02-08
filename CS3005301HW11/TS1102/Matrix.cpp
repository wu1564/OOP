#include "Matrix.h"

int Matrix::getRow() {
	return row;
}

int Matrix::getColumn() {
	return column;
}

void Matrix::giveData(int number) {
	static int rowCnt = 0, colCnt = 0;

	if (row != 0 && column != 0) {
		matrix[rowCnt][colCnt++] = number;
		if (colCnt == column) {
			++rowCnt;
			colCnt = 0;
		}
		if (rowCnt == row) rowCnt = 0;
	}
}

int Matrix::totalNum() {
	return row * column;
}

void Matrix::printMatrix() {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			std::cout << matrix[i][j] << " ";
		}std::cout << std::endl;
	}
}

int Matrix::getNum(int row, int col) {
	return matrix[row][col];
}
