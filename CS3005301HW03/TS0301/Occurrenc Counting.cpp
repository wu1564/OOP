#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void) {
	int inputKey;
	char temp;
	string str;
	map<int, int> record;

	while (getline(cin, str)) {
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] == ' ') {
				inputKey = stoi(str.substr(0, i));
				record[inputKey]++;
				str = (str[i] == ' ') ? str.substr(i + 1, str.length() - i + 1) : str;
				//cout << inputKey << "\t" << str  << "\t" << str.length() << endl;
				i = 0;
			}
		}
		record[stoi(str)]++;
		cout << "N\tcount\n";
		for (map<int, int>::reverse_iterator it = record.rbegin(); it != record.rend(); ++it) {
			cout << it->first << "\t" << it->second << endl;
		}
	}
	
	return 0;
}
