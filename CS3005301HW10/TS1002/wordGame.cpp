#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const char* fileName = "words.txt";

enum coordinate{
	UPPER = 0,
	UNDER,
	LEFT,
	RIGHT,
	UPPER_LEFT,
	UNDER_LEFT,
	UPPER_RIGHT,
	UNDER_RIGHT
};

bool outOfBound(const int &row, const int &col) {
	return (row >= 4 || col >= 4 || row < 0 || col < 0) ? true : false;
}

void findElement(char **map, const string &str, bool &valid, int row, int col, int strIndex, bool *path_table) {
	if (outOfBound(row, col)) return;
	if (!valid && str[strIndex] == map[row][col] && *(path_table + row * 4 + col) == false) {
		strIndex++;
		*(path_table + row * 4 + col) = true;
		if (strIndex == str.length()) {
			valid = true;
			strIndex = 0;
			return;
		}
		for (int i = UPPER; i <= UNDER_RIGHT; ++i) {
			switch (i) {
				case UPPER:			findElement(map, str, valid, row-1, col, strIndex, path_table); break;
				case UNDER:			findElement(map, str, valid, row+1, col, strIndex, path_table); break;
				case LEFT:			findElement(map, str, valid, row, col-1, strIndex, path_table); break;
				case RIGHT:			findElement(map, str, valid, row, col+1, strIndex, path_table); break;
				case UPPER_LEFT:	findElement(map, str, valid, row-1, col-1, strIndex, path_table); break;
				case UNDER_LEFT:	findElement(map, str, valid, row+1, col-1, strIndex, path_table); break;
				case UPPER_RIGHT:	findElement(map, str, valid, row-1, col+1, strIndex, path_table); break;
				case UNDER_RIGHT:	findElement(map, str, valid, row+1, col+1, strIndex, path_table); break;
				default:	break;
			}
		}
	}
}

bool valid(char **map, string str) {
	bool findFirst = false, valid = false, path_table[4][4] = {false};
	int i, j;
	
	for (i = 0; i < 4 && !findFirst; ++i) {
		for (j = 0; j < 4; ++j) {
			if (str[0] == map[i][j]) {
				findElement(map, str, valid, i, j, 0, &path_table[0][0]);
			}
		}
	}
	return valid;
}

int main() {
	string str;
	fstream file, outputFile;
	char** map;

	map = new char* [4];
	for (int i = 0; i < 4; i++) {
		map[i] = new char[4];
	}

	file.open(fileName, ios_base::in);
	outputFile.open("text.txt", ios_base::out);
	if (!file.is_open() || !outputFile.is_open()) {
		cout << "Cannot Open File";
		exit(1);
	}
	for (int i = 0; i < 4; i++) {
		cin >> str;
		for (int j = 0; j < 4; j++) {
			map[i][j] = str[j];
		}
	}
	while (!file.eof()) {
		file >> str;
		if (valid(map, str)) {
			outputFile << str << endl;
			cout << str << endl;
		}
	}
	outputFile << endl;
	file.close();
	outputFile.close();
}
