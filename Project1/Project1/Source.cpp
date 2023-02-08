#include <iostream>
#include <iomanip>      // std::setprecision
using namespace std;
/*
int main(void) {
    unsigned long long time, hour, min, sec;
    cin >> time;
    hour = time / 3600;
    min = time % 3600;
    sec = min % 60;
    min /= 60;
    cout << hour << "hours" << min << "minutes and " << sec << "seconds" << endl;
}
*/

int main(void) {
    double guess, r, n, previous;
    r = 0;
    cin >> n;
    guess = n / 2;
    previous = guess + 1;
    while (previous - guess > 0.01) {
        previous = guess;
        r = n / guess;
        guess = (guess + r) / 2;
    }
    cout << fixed << setprecision(2) << r << endl;
}
