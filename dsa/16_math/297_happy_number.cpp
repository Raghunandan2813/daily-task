/*
 * 297. Happy Number
 * Topic: Math | Difficulty: Easy
 *
 * Repeatedly replace a number by the sum of the squares of its digits. It is
 * happy if this reaches 1, and unhappy if it falls into a cycle.
 *
 * Approach: the sequence is a functional graph, so an unhappy number must loop.
 * Floyd's tortoise and hare detects that loop in O(1) space - no set of seen
 * values is needed. Reaching 1 shows up as both pointers landing on 1.
 *
 * Time: O(log n) per step, few steps   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

static int squareDigitSum(int n) {
    int sum = 0;
    while (n) { int d = n % 10; sum += d * d; n /= 10; }
    return sum;
}

bool isHappy(int n) {
    int slow = n, fast = n;
    do {
        slow = squareDigitSum(slow);
        fast = squareDigitSum(squareDigitSum(fast));
    } while (slow != fast);
    return slow == 1;
}

int main() {
    cout << isHappy(19) << "\n";   // 1
    cout << isHappy(2) << "\n";    // 0
    cout << isHappy(1) << "\n";    // 1
    return 0;
}
