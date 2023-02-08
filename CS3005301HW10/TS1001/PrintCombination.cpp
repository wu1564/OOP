#include <vector>
#include <time.h>
#include <algorithm>
#include <fstream>
#include "PrintCombination.h"

using namespace std;
//#define RANDOM
#define RECURSIVE
#ifdef RANDOM

void get_array(vector<int>& new_array, const int* array, bool* num_record_table, const int total, const int grab) {
	int randNum = rand() % total;
	if (num_record_table[randNum]) {
		get_array(new_array, array, num_record_table, total, grab);
		return;
	}
	else {
		num_record_table[randNum] = true;
		new_array.push_back(array[randNum]);
		if (new_array.size() != grab) {
			get_array(new_array, array, num_record_table, total, grab);
			return;
		}
	}
	fill(num_record_table, num_record_table + total, 0);
	sort(new_array.begin(), new_array.end());
}

void PrintCombination(int* array, int total, int grab) {
	vector<int> generate_array;
	vector<vector<int>> record_table;
	bool* num_record_table, new_array_flag = true;
	int totalCombination = 1;
	int num;
	fstream file;
	srand((unsigned)time(0));

	if (grab != 0 && total >= grab) {
		num_record_table = new bool[total];
		fill(num_record_table, num_record_table + total, 0);
		for (int i = total, times = 0; times < total - grab; ++times, --i) totalCombination *= i;
		for (int i = 0; i < total - grab; ++i) totalCombination /= (i + 1);
		for (int times = totalCombination; times > 0;) {
			get_array(generate_array, array, num_record_table, total, grab);
			for (int i = 0; i < record_table.size() && new_array_flag == true; ++i) {
				new_array_flag = false;
				for (int j = 0; j < record_table[i].size(); ++j) {
					if (generate_array[j] != record_table[i][j]) {
						new_array_flag = true;
						break;
					}
				}
			}
			if (new_array_flag) {
				--times;
				record_table.push_back(generate_array);
			}
			generate_array.clear();
			new_array_flag = true;
		}

		for (int i = 0; i < grab; ++i) {
			for (int j = 0; j < totalCombination; ++j) {
				for (int k = 0; k < totalCombination - j - 1; k++) {
					if (record_table[k][i] > record_table[k + 1][i] && (i == 0 || i > 0 && record_table[k + 1][i - 1] == record_table[k][i - 1])) {
						for (int swap_times = 0; swap_times < grab; ++swap_times) {
							int temp = record_table[k][swap_times];
							record_table[k][swap_times] = record_table[k + 1][swap_times];
							record_table[k + 1][swap_times] = temp;
						}
					}
				}
			}
		}

		for (int i = 0; i < record_table.size(); ++i) {
			for (int j = 0; j < record_table[i].size() - 1; ++j) {
				cout << record_table[i][j] << " ";
			}
			cout << record_table[i][record_table[i].size() - 1] << endl;
		}
	}
}

#elif defined(RECURSIVE)

void process(const int* array, int** ptrArray, const int &total, const int &grab) {
	int move = 0, i = 0;
	
	for (i = 0; i < grab; ++i) {
		if (*(ptrArray[i]) == array[total - grab + i]) {
			move++;
		}
	}

	if (move != grab) {
		for (i = 0; i < (grab - 1); i++) cout << *(ptrArray[i]) << " ";
		cout << *(ptrArray[grab - 1]) << endl;
		if (move != 0) {
			ptrArray[grab - 1 - move] += 1;
			for (i = 1; i <= move; ++i) {
				ptrArray[grab-1-move+i] = ptrArray[grab-1-move] + i;
			}
		} else {
			ptrArray[grab - 1] += 1;
		}
		process(array, ptrArray, total, grab);
	} else {
		for (i = 0; i < grab - 1; i++) cout << *(ptrArray[i]) << " ";
		cout << *(ptrArray[grab - 1]) << endl;
	}
}

void PrintCombination(int* array, int total, int grab) {
	int** ptrArray, move;

	ptrArray = new int* [grab];
	for (int i = 0; i < grab; ++i) {
		ptrArray[i] = &array[i];
	}
	process(array, ptrArray, total, grab);
}

#else

int move_check(int *array, int **ptrArray, int total, int grab) {
	int num = 0;
	for (int i = 0; i < grab; ++i) {
		if (*(ptrArray[i]) == array[total-grab+i]) {
			num++;
		}
	}
	return num;
}

void PrintCombination(int* array, int total, int grab) {
	int **ptrArray, move;

	ptrArray = new int* [grab];
	for (int i = 0; i < grab; ++i) {
		ptrArray[i] = &array[i];
	}
	move = move_check(array, ptrArray, total, grab);
	while(move != grab) {
		for (int i = 0; i < grab-1; i++) cout << *(ptrArray[i]) << " ";
		cout << *(ptrArray[grab-1]) << endl;
		if (move != 0) {
			ptrArray[grab-1-move] += 1;
			for (int i = 1; i <= move; ++i) {
				ptrArray[grab-1-move+i] = ptrArray[grab-1-move] + i;
			}
		} else {
			ptrArray[grab-1] += 1;
		}
		move = move_check(array, ptrArray, total, grab);
	}
	for (int i = 0; i < grab-1; i++) cout << *(ptrArray[i]) << " ";
	cout << *(ptrArray[grab - 1]) << endl;
}
#endif
