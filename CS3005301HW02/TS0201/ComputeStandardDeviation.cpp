#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
/*
void dynamic_receive_data(int *number, int **array, int **ptr, int input) {
	int i = 0;

	if (*number == 1) {
		**array = input;
	} else {
		*ptr = *array;
		*array = (int*)malloc(sizeof(int) * (*number));
		memset(*array, 0, sizeof(int) * (*number));		
		for (i = 0; i < *number - 1; ++i) {
			(*array)[i] = (*ptr)[i];
		}
		(*array)[*number - 1] = input;
		free(*ptr);
	}
	*number += 1;
}

int main(void) {
	char input;
	string array_str, temp;
	int num = 0, totalNum = 1;
	int* array = NULL, *ptr = NULL;
	double ave = 0, standard = 0;

	input = getchar();
	array = (int*)malloc(sizeof(int));
	while (1) {
		if (input != ' ' && input != '\n') {
			temp.assign(1, input);
			array_str += temp;
		} else {
			num = stoi(array_str);
			array_str = "";
			dynamic_receive_data(&totalNum, &array, &ptr, num);
		}
		if (input == '\n') break;
		input = getchar();
	}
	totalNum -= 1;

	for (int i = 0; i < totalNum; ++i) {
		ave += array[i];
	}
	ave /= totalNum;
	for (int i = 0; i < totalNum; ++i) {
		standard += (array[i] - ave) * (array[i] - ave);
	}
	standard /= totalNum;
	standard = sqrt(standard);
	cout << "Average:" << ave << "\t" << "Standard deviation:" << standard << endl;
}
*/

int main(void) {
	double totalNum, inputNum;
	double* array;
	double ave = 0, standard = 0;

	while(cin >> totalNum) {
		array = new double[totalNum];
		for (int i = 0; i < totalNum; ++i) {
			cin >> inputNum;
			ave += inputNum;
			array[i] = inputNum;
		}
		ave /= totalNum;
		for (int i = 0; i < totalNum; ++i) {
			standard = (array[i] - ave) * (array[i] - ave) + standard;
		}
		standard /= totalNum;
		standard = sqrt(standard);
		cout << "Average:" << ave << "\t" << "Standard deviation:" << standard << endl;
		ave = 0;
		standard = 0;
		delete[] array;
	}
}