#include "../Log.h"

Log LOG("main");

void run() {
    const int MAX = 100;

    int sumOfSquares = 0;
    int squareOfSums = 0;


    for (int i = 1; i <= MAX; i++)
    {
        sumOfSquares += i*i;
    }

    squareOfSums = MAX / 2 * (1 + MAX);
    squareOfSums *= squareOfSums;

    LOG.debugf("%d - %d = %d", squareOfSums, sumOfSquares, squareOfSums - sumOfSquares);
}

int main() {
    LOG.debugf("BEGIN");
    run();
    LOG.debugf("END");
}
