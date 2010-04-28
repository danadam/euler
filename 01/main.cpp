#include "../Log.h"

int main() {
    Log LOG("main");

    long sum = 0;
//    for (int i = 3; i < 1000; i += 3) {
//        sum += i;
//    }
//    for (int i = 5; i < 1000; i += 5) {
//        sum += i;
//    }
//    LOG.debugf("%ld", sum);

    sum = 0;
    for (int i = 0; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    LOG.debugf("%ld", sum);
}
