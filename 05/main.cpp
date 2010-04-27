#include <iostream>
#include <vector>
using namespace std;

void sieve(std::vector<int> & primes, int limit) {
    vector<int> naturals(limit+1, 1);
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

void printVector(const std::string & name, const std::vector<int> & v) {
    cout << name << ": ";
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << ", ";
    }
    cout << endl;
}

int main() {
    const int MAX = 20;

    vector<int> primes;
    sieve(primes, MAX);
    printVector("primes", primes);

    vector<int> dividers;
    for (int i = 1; i <= MAX; i++) {
        dividers.push_back(i);
    }
    printVector("dividers", dividers);
    vector<int> lcm;

    vector<int>::iterator primeIt = primes.begin();
    for (; primeIt != primes.end(); ++primeIt) {
        int prime = *primeIt;
        cout << "prime=" << prime << endl;

        bool divide = true;
        while (divide) {
            vector<int>::iterator dividerIt = dividers.begin();
            divide = false;
            for (; dividerIt != dividers.end(); ++dividerIt) {
                int divider = *dividerIt;
                cout << "divider=" << divider << endl;
                if (divider >= prime && divider % prime == 0) {
                    if (divide == false) {
                        divide = true;
                        lcm.push_back(prime);
                    }
                    *dividerIt /= prime;
                }
            }
            printVector("dividers", dividers);
            printVector("lcm", lcm);
        }
    }

    vector<int>::iterator lcmIt = lcm.begin();
    int l = 1;
    for (; lcmIt != lcm.end(); ++lcmIt) {
        l *= *lcmIt;
    }
    cout << l << endl;
}

