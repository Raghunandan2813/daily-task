/*
 * 112. Tower of Hanoi
 * Topic: Recursion & Backtracking | Difficulty: Easy
 *
 * Move n disks from a source rod to a destination rod using one auxiliary rod,
 * never placing a larger disk on a smaller one.
 *
 * Approach: the classic three-line recursion - move the top n-1 disks out of the
 * way onto the auxiliary rod, move the largest disk across, then move the n-1
 * disks on top of it. The move count is 2^n - 1, which is provably optimal.
 *
 * Time: O(2^n)   Space: O(n) recursion
 */
#include <bits/stdc++.h>
using namespace std;

long long hanoi(int n, char from, char to, char aux, bool print) {
    if (n == 0) return 0;
    long long moves = hanoi(n - 1, from, aux, to, print);
    if (print) cout << "move disk " << n << ": " << from << " -> " << to << "\n";
    ++moves;
    moves += hanoi(n - 1, aux, to, from, print);
    return moves;
}

int main() {
    cout << "total moves: " << hanoi(3, 'A', 'C', 'B', true) << "\n";   // 7
    cout << "n=10 moves: " << hanoi(10, 'A', 'C', 'B', false) << "\n";  // 1023
    return 0;
}
