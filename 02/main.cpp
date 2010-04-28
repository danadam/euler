#include "../Log.h"

int main() {
    Log LOG("main");

    int x1 = 1;
    int x2 = 2;
    int x3 = x1 + x2;
    int sum = x2;
    while (x3 < 4000000) {
        if (x3 % 2 == 0) {
            sum += x3;
        }
        x1 = x2;
        x2 = x3;
        x3 = x1 + x2;
    }

    LOG.debugf("sum = %d", sum);
}
