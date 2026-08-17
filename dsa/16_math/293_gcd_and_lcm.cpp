/*
 * 293. GCD and LCM (Euclid's Algorithm)
 * Topic: Math | Difficulty: Easy
 *
 * Compute the greatest common divisor and least common multiple.
 *
 * Approach: Euclid's algorithm rests on gcd(a, b) == gcd(b, a % b) - any common
 * divisor of a and b also divides their remainder. The LCM follows from
 * a * b == gcd * lcm, and dividing before multiplying keeps the intermediate
 * value from overflowing. The extended version additionally recovers x and y
 * with a*x + b*y == gcd.
 *
 * Time: O(log min(a, b))   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) { long long t = a % b; a = b; b = t; }
    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;                        // divide first: no overflow
}

// Solves a*x + b*y = gcd(a, b).
long long extendedGcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long g = extendedGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main() {
    cout << gcd(48, 18) << "\n";       // 6
    cout << lcm(4, 6) << "\n";         // 12
    long long x, y;
    cout << extendedGcd(30, 20, x, y) << " " << x << " " << y << "\n";   // 10 1 -1
    return 0;
}
