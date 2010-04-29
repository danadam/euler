#include <cmath>
#include <vector>

#include "../Log.h"

using namespace std;

Log LOG("main");

int sieve(int n) {
    int limit = 0;
    if (n >= 7022) {
        limit = (double)n * log(n) + n * (log(log(n)) - 0.9385) + 0.5;
    }
    else if (n >= 6) {
        limit = (double)n * log(n) + n * log(log(n)) + 0.5;
    }
    else {
        limit = 10;
    }
    LOG.debugf("sieve limit=%d", limit);
    int prime = 0;
    int cnt = 0;
    vector<char> naturals(limit+1, 1);
    for (int i = 2; i <= limit; i++) {
        if (naturals[i] == 0) {
            continue;
        }

        cnt++;
        prime = i;
        if (cnt == n) {
            break;
        }

        for (int j = 2*i; j <= limit; j += i) {
            naturals[j] = 0;
        }
    }
    return prime;
}

void run() {
    const int N = 10001;
    int nPrime = sieve(N);
    LOG.debugf("%dth prime is %d", N, nPrime);
}

int main() {
    LOG.debugf("BEGIN");
    run();
    LOG.debugf("END");

    return 0;
}
