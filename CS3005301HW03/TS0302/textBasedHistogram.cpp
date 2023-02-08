#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

int main(void) {
	int inputKey, default_index = 0;
	char temp;
	string str;
	map<int, int> record;
	fstream file, outputFile;

	file.open("grade.txt");
	if (file.is_open() == NULL) {
		cout << "File Cannot open";
		return 0;
	}

	outputFile.open("grades.Output",ios::out | ios::trunc);
	if (outputFile.is_open() == NULL) {
		cout << "File Cannot open";
		return 0;
	}

	while (!file.eof()) {
		file >> inputKey;
		record[inputKey]++;
	}
	
	for (map<int, int>::iterator it = record.begin(); it != record.end(); ++default_index) {
		if (it->first == default_index) {
			outputFile << it->second << " grade(s) of " << it->first << endl;
			++it;
		} else {
			outputFile << "0 grade(s) of " << default_index << endl;
		}	
	}

	file.close();
	outputFile.close();
	return 0;
}
