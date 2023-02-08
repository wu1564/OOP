#include <iostream>
using namespace std;
/*
int main(void) {
	char** map;
	double root;
	int num, index = 0;
	string str;

	while (cin >> str) { 
		if (str.length() == 1) {
			cout << str << endl;
		} else {
			root = sqrt(str.length());
			if (root - (int)root != 0) {
				num = sqrt(str.length()) + 1;
			} else {
				num = (int)root;
			}
			map = (char**)malloc(sizeof(char*) * num);
			for (int i = 0; i < num; ++i) {
				map[i] = (char*)malloc(sizeof(char) * num);
				memset(map[i], '\0', sizeof(char) * num);
			}
			for (int col = 0; col < num; ++col) {
				for (int row = 0; row < num; ++row) {
					if (str[index] == '\0') break;
					map[row][col] = str[index++];
				}
			}
			for (int row = 0; row < num; ++row) {
				for (int col = 0; col < num; ++col) {
					if (map[row][col] == '\0') {
						break;
					}
					cout << map[row][col];
				}
				cout << endl;
			}
			for (int i = 0; i < num; ++i) free(map[i]);
			free(map);
			index = 0;
		}
	}
}
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec{10, 11, 12, 13, 15};
	string n; // input string

	cout << vec.capacity() << endl << vec.size() << endl;
	double square_length;

	/*
	while (cin >> n)
	{
		square_length = ceil(sqrt(n.size()));
		//width = n.size() / sqrt(n.size());
		//cout << n.size() << endl;
		for (int i = 0; i < square_length; i++)
		{
			for (int j = 0; j < square_length; j++)
			{
				if (int(i + j * square_length) < n.size())
					//cout << int(i + j * square_length) << " ";
					cout << n[i + j * square_length];
			}
			cout << endl;
		}
	}
	return 0;
	*/
}
