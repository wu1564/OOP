#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

const char* fileName = "name.txt";
int main(void) {
	char buff[20];
	fstream file;
	set<string> list;

	file.open(fileName, ios::in);
	if (!file.is_open()) {
		cout << "Cannot Open File";
		exit(1);
	}
	while (file.getline(buff, sizeof(buff), '\n')) {
		list.insert(buff);
	}
	for (set<string>::iterator it = list.begin(); it != list.end(); ++it) {
		cout << *it << endl;
	}
}