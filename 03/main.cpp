#include <iostream>
#include <stdint.h>
using namespace std;

int main() {
    int64_t n = 600851475143L;
    int64_t factor = 2;
    int64_t lastFactor = factor;

    while (factor <= n) {
        if (n % factor == 0) {
            lastFactor = factor;
            int cnt = 0;
            while (n % factor == 0) {
                n /= factor;
                cnt++;
            }
            cout << lastFactor << " x " << cnt << endl;
        }
        factor++;
    }
    cout << lastFactor << endl;
}
