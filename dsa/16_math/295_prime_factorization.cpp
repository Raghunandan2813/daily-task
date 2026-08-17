/*
 * 295. Prime Factorization
 * Topic: Math | Difficulty: Medium
 *
 * Decompose an integer into its prime factors with multiplicities.
 *
 * Approach: divide out each candidate factor from 2 upwards. Trial division only
 * needs to reach sqrt(n), because a number can have at most one prime factor
 * larger than its own square root - whatever remains after the loop is that
 * factor, if any.
 *
 * Time: O(sqrt(n))   Space: O(log n)
 */
#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, int> > primeFactors(long long n) {
    vector<pair<long long, int> > out;
    for (long long p = 2; p * p <= n; ++p) {
        int power = 0;
        while (n % p == 0) { n /= p; ++power; }
        if (power) out.push_back(make_pair(p, power));
    }
    if (n > 1) out.push_back(make_pair(n, 1));       // the leftover large prime
    return out;
}

int main() {
    for (const auto& f : primeFactors(360)) cout << f.first << "^" << f.second << " ";
    cout << "\n";   // 2^3 3^2 5^1
    for (const auto& f : primeFactors(1000000007LL)) cout << f.first << "^" << f.second << " ";
    cout << "\n";   // 1000000007^1 (it is prime)
    return 0;
}
