#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

std::string reverse(const std::string & s) {
    std::string result = s;
    reverse(result.begin(), result.end());
    return result;
}

bool isPal(const std::string & s) {
    return s == reverse(s);
}

int main() {

    int maxPal = 0;
    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {
            int m = i * j;
            if (m <= maxPal) {
                break;
            }

            ostringstream oss;
            oss << m;
            if (isPal(oss.str())) {
                maxPal = m;
                break;
            }
        }
    }

    cout << maxPal << endl;
}
