#include "../Log.h"

Log LOG("main");

void run() {
    // a < b < c
    // a + b + c = 1000
    //   c = 1000 - a - b > b
    //       1000 - a > 2b
    int product = 0;
    int A = 0, B = 0, C = 0;
    int cnt = 0;
    for (int a = 1; a < 999 && product == 0; a++) {
        for (int b = a + 1; 2 * b < 1000 - a && product == 0; b++) {
            cnt ++;
            int c = 1000 - a - b;
            if (a * a + b * b == c * c) {
                A = a; B = b; C = c;
                product = a * b * c;
            }
        }
    }
    LOG.debugf("A=%d, B=%d, C=%d, product=%d, cnt=%d", A, B, C, product, cnt);
}

void run2() {
    // a < b < c
    // a + b + c = 1000
    //   c = 1000 - a - b > b
    //       1000 - a > 2b
    // max: 1000 / 3 = 333.(3)  => a = 332, b = 333, c = 335
    int product = 0;
    int A = 0, B = 0, C = 0;
    int cnt = 0;
    for (int a = 332; a > 0 && product == 0; a--) {
        for (int b = (1000 - a - 0.5) / 2; b > a && product == 0; b--) {
//        for (int b = a + 1; 2 * b < 1000 - a && product == 0; b++) {
            cnt ++;
            int c = 1000 - a - b;
            if (c <= b) {
                LOG.debugf("error");
            }
            if (a * a + b * b == c * c) {
                A = a; B = b; C = c;
                product = a * b * c;
            }
        }
    }
    LOG.debugf("A=%d, B=%d, C=%d, product=%d, cnt=%d", A, B, C, product, cnt);
}

int main() {
    LOG.debugf("BEGIN");
    run2();
    LOG.debugf("END");
}

