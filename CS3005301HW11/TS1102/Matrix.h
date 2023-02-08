#pragma once
#include <iostream>

class Matrix {
	public:
		Matrix() {
			row = 0;
			column = 0;
		}
		Matrix(int row, int col) {
			this->row = row;
			this->column = col;
			matrix = new int* [row];
			for (int i = 0; i < row; ++i) {
				matrix[i] = new int[column];
				std::fill(matrix[i], matrix[i]+column,0);
			}
		}
		int getRow();
		int getColumn();
		void giveData(int);
		int totalNum();
		void printMatrix();
		int getNum(int, int);
	private:
		int row;
		int column;
		int** matrix;
};
