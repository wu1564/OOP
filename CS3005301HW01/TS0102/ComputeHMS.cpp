#include <iostream>
using namespace std;

int main(void) {
    unsigned long long time, hour, min, sec;

    while (cin >> time) {
        hour = time / 3600;
        min = time % 3600;
        sec = min % 60;
        min /= 60;
        cout << hour << " hours " << min << " minutes and " << sec << " seconds" << endl;
    }
    return 0;
}
