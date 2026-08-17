/*
 * 292. Sieve of Eratosthenes
 * Topic: Math | Difficulty: Medium
 *
 * List all primes up to n.
 *
 * Approach: mark the multiples of each prime as composite. Two optimisations
 * matter: the outer loop can stop at sqrt(n), because any composite below n has
 * a factor no larger than that; and the inner loop starts at p*p, since every
 * smaller multiple of p was already struck out by a smaller prime factor.
 *
 * Time: O(n log log n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
    vector<bool> isComposite(n + 1, false);
    vector<int> primes;
    for (long long p = 2; p * p <= n; ++p)
        if (!isComposite[p])
            for (long long m = p * p; m <= n; m += p) isComposite[m] = true;
    for (int i = 2; i <= n; ++i) if (!isComposite[i]) primes.push_back(i);
    return primes;
}

int main() {
    for (int p : sieve(50)) cout << p << " ";
    cout << "\n";   // 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47
    cout << "primes below 1000000: " << sieve(1000000).size() << "\n";   // 78498
    return 0;
}
