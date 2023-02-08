#include <iostream>
#include <vector>
using namespace std;

#define STRUCTURE

#ifdef ALL

void compare(char a, const char b, vector<char>* record, vector<int>* timesTable, bool* result) {
	bool stop = true;

	if (a == b) {
		*result = true;
	}
	else {
		for (int i = 0; i < record[1].size(); ++i) {
			if (record[1][i] == b) stop = false;
		}
	}

	if (!stop) {
		if (*result == false && a != b) {
			for (int i = 0; i < record[0].size(); ++i) {
				if (record[0][i] == a && (*timesTable)[i] == 0) {
					(*timesTable)[i] += 1;
					//cout << a << " " << record[1][i] << " " << b << endl;
					compare(record[1][i], b, record, timesTable, result);
				}
			}
		}
	}
}

void TranslationMachine(string str0, string  str1, vector<char>* pair) {
	vector<int> timesTable;
	bool result;

	for (int i = 0; i < pair[0].size(); ++i) timesTable.push_back(0);
	if (str0 == str1) {
		cout << "yes" << endl;
		return;
	}
	else if (str0.length() != str1.length()) {
		cout << "no" << endl;
		return;
	}

	for (int i = 0; i < str0.length(); ++i) {
		if (str0[i] != str1[i]) {
			result = false;
			compare(str0[i], str1[i], pair, &timesTable, &result);
			if (result) str0[i] = str1[i];
		}
	}
	if (str0 == str1) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
}

int main(void) {
	string str0, str1;
	vector<char> pair[2];
	vector<string> input[2];
	char a, b;
	int m;	// number of pairs
	int n;	// test case number

	while (1) {
		cin >> m >> n;
		while (m--) {
			cin >> a >> b;
			if (a == 0 && b == 0) exit(0);
			pair[0].push_back(a);
			pair[1].push_back(b);
		}

		while (n--) {
			cin >> str0 >> str1;
			input[0].push_back(str0);
			input[1].push_back(str1);
		}

		for (int i = 0; i < input[0].size(); ++i) {
			//Translation Machine
			TranslationMachine(input[0][i], input[1][i], pair);
		}
		pair[0].clear();
		pair[1].clear();
		input[0].clear();
		input[1].clear();
	}

#elif defined(STRUCTURE)

void compare(vector<vector<char>> *recordTable, vector<bool> *processTable, bool *found, char a, char b) {
	bool inside = false;

	//
	//for (int i = 0; i < recordTable->size(); ++i) cout << (*processTable)[i] << " ";
	//cout << endl;

	for (int i = 0; i < recordTable->size(); ++i) {
		for (int j = 1; j < (*recordTable)[i].size(); ++j) {
			if ((*recordTable)[i][j] == b) {
				inside = true;
				break;
			}
		}
	}
	
	if (a == b) {
		*found = true;
	} else if(inside && *found == false) {
		for (int i = 0; i < recordTable->size(); ++i) {
			if ((*processTable)[i] == false && (*recordTable)[i][0] == a) {
				(*processTable)[i] = true;
				for (int j = 1; j < (*recordTable)[i].size(); ++j) {
					//cout << a << "->" << (*recordTable)[i][j] << endl;
					compare(recordTable, processTable, found, (*recordTable)[i][j], b);
				}
			}
		}
	}
}

void TranslateMachine(vector<vector<char>> *recordTable, string input, string target) {
	//cout << "Input : " << input << " Target : " << target << endl;
	
	vector<bool> processTable;
	bool found = false;

	// create processTable
	for (int i = 0; i < (*recordTable).size(); ++i) processTable.push_back(false);
	
	//special
	if (input.length() != target.length()) {
		cout << "no" << endl;
		return;
	} else if (input == target) {
		cout << "yes" << endl;
		return;
	}

	for (int i = 0; i < input.length(); ++ i) {
		found = false;
		compare(recordTable, &processTable, &found, input[i], target[i]);
		for (int i = 0; i < processTable.size(); ++i) processTable[i] = false;
		if (found) input[i] = target[i];
	}

	if (input == target) {
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}
}

int main(void) {
	char pairFir, pairSec;
	vector<char> temp;
	vector<vector<char>> recordTable;
	string inputWord1, inputWord2;
	int pairNum, testCaseNum;
	bool inside = false;
	//
	vector<string> keep;

	while (1) {
		cin >> pairNum >> testCaseNum;

		if (pairNum == 0 && testCaseNum == 0) break;
		while (pairNum--) {
			cin >> pairFir >> pairSec;
			inside = false;
			for (int i = 0; i < recordTable.size(); ++i) {
				if (recordTable[i][0] == pairFir) {
					inside = true;
					recordTable[i].push_back(pairSec);
				}
			}
			if (!inside) {
				temp.push_back(pairFir);
				temp.push_back(pairSec);
				recordTable.push_back(temp);
			}
			temp.clear();
		}

		while (testCaseNum--) {
			cin >> inputWord1;
			keep.push_back(inputWord1);
			cin >> inputWord1;
			keep.push_back(inputWord1);
		}

		for (int i = 0; i < keep.size() - 1; i += 2) {
			TranslateMachine(&recordTable, keep[i], keep[i + 1]);
		}

		// clear all
		for (int i = 0; i < recordTable.size(); ++i) recordTable[i].clear();
		recordTable.clear();
		keep.clear();
	}

	////cout << "Test\n";
	//for (int i = 0; i < recordTable.size(); ++i) {
	//	for (int j = 0; j < recordTable[i].size(); j++)
	//	{
	//		cout << recordTable[i][j] << " ";
	//	}
	//	cout << endl;
	//}

}
#endif // Table

