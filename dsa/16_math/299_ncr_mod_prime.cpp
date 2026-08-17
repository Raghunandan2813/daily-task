/*
 * 299. nCr Modulo a Prime
 * Topic: Math | Difficulty: Hard
 *
 * Compute the binomial coefficient C(n, r) modulo a prime p.
 *
 * Approach: division is not defined in modular arithmetic, so the factorial
 * formula needs modular inverses. Since p is prime, Fermat's little theorem
 * gives inverse(a) == a^(p-2) mod p. Precomputing factorials and their inverses
 * makes each query O(1) after an O(n) setup.
 *
 * Time: O(n) precomputation, O(1) per query   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

static long long modPow(long long b, long long e, long long m) {
    long long r = 1;
    b %= m;
    while (e > 0) {
        if (e & 1) r = r * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return r;
}

class Binomial {
    vector<long long> fact, invFact;
public:
    explicit Binomial(int maxN) : fact(maxN + 1), invFact(maxN + 1) {
        fact[0] = 1;
        for (int i = 1; i <= maxN; ++i) fact[i] = fact[i - 1] * i % MOD;
        invFact[maxN] = modPow(fact[maxN], MOD - 2, MOD);      // Fermat inverse
        for (int i = maxN; i > 0; --i) invFact[i - 1] = invFact[i] * i % MOD;
    }
    long long nCr(int n, int r) const {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }
};

int main() {
    Binomial b(1000000);
    cout << b.nCr(5, 2) << "\n";          // 10
    cout << b.nCr(10, 5) << "\n";         // 252
    cout << b.nCr(1000000, 500000) << "\n";   // large value mod 1e9+7
    return 0;
}
