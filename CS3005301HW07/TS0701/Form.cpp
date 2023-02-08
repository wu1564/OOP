#include "Form.h"

vector<string> validWord;
map<char, int> recordInput, compareStr;
map<char, int>::iterator inputPtr, comparePtr;
string str, file_name;
fstream file;

// set input
void Form::SetInputWord(string inputWord) {
	str = inputWord;
}

// process input
void Form::ProcessInputWord() {
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] < 'a') {
			str[i] += 32;
		}
		recordInput[str[i]]++;
	}
}

// set file name
void Form::SetFileName(string fileName) {
	file_name = fileName;
}

// read-in data and compare
void Form::Load_CompareWord() {
	bool valid = true;
	string temp;
	int findIndex;

	file.open(file_name);
	if (!file.is_open()) {
		cout << "Cannot Open File";
		exit(0);
	}

	file >> temp;
	while(!file.eof()) {
		valid = true;
		for (int i = 0; i < temp.length(); ++i) {
			inputPtr = recordInput.find(temp[i]);
			compareStr[temp[i]]++;
			if (inputPtr == recordInput.end() || (compareStr[temp[i]] > inputPtr->second && inputPtr != recordInput.end())) {
				valid = false;
				break;
			}
		}
		if (valid) validWord.push_back(temp);
		file >> temp;
		compareStr.clear();
	}
}

// print answers
void Form::PrintFoundWords() {
	for (int i = 0; i < validWord.size(); ++i) {
		cout << validWord[i] << endl;
	}
}
