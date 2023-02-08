#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

#define LENGTH 1000

void getHighScores(string* name, int* score, int total) {
    int temp;
    string temp_str;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < total - i - 1; ++j) {
            if (score[j] > score[j + 1]) {
                temp = score[j];
                score[j] = score[j + 1];
                score[j + 1] = temp;
                temp_str = name[j];
                name[j] = name[j + 1];
                name[j + 1] = temp_str;
            }
        }
    }
    /*
        for (int i = 0; i < 3; ++i) {
            cout << name[total - i] << endl << score[total - i] << endl;
        }*/
    for (int i = 1; i <= 3; ++i) {
        cout << name[total - i] << endl << score[total - i] << endl;
    }
}


int main(void) {
    ifstream ifs;
    int total = 0;
    char str;
    int score[LENGTH];
    string name[LENGTH];
    string line;

    ifs.open("scores.txt");

    if (!ifs.is_open()) {
        cout << "Failed to open file.\n";
        return 0;
    }

    while (getline(ifs, line)) {
        name[total] = line;
        getline(ifs, line);
        score[total] = atoi(line.c_str());
        total++;
    }

    getHighScores(name, score, total);
    ifs.close();
}
