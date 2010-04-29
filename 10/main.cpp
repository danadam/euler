#include <vector>

#include "../Log.h"

using namespace std;

Log LOG("main");

void sieve(std::vector<int> & primes, int limit) {
    vector<char> naturals(limit+1, 1);
    for (int i = 2; i <= limit; i++) {
        if (naturals[i] == 0) {
            continue;
        }

        primes.push_back(i);

        for (int j = 2*i; j <= limit; j += i) {
            naturals[j] = 0;
        }
    }
}

void run() {
    const int MAX = 2000000;
    vector<int> primes;
    sieve(primes, MAX);
    long sum = 0;
    for (vector<int>::iterator it = primes.begin(); it != primes.end(); ++it) {
        sum += *it;
    }
    LOG.debugf("sum=%ld", sum);
}

int main() {
    LOG.debugf("BEGIN");
    run();
    LOG.debugf("END");
}

