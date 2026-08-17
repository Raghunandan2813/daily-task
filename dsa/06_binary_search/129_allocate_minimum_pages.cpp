/*
 * 129. Allocate Minimum Number of Pages
 * Topic: Binary Search | Difficulty: Hard
 *
 * Distribute books (in order) among m students so that the maximum number of
 * pages any student reads is minimised. Every student must get at least one book.
 *
 * Approach: binary search on the answer between the largest single book and the
 * total. A greedy check counts how many students a candidate limit requires.
 *
 * Time: O(n log(total pages))   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

static int studentsNeeded(const vector<int>& books, long long limit) {
    int students = 1;
    long long load = 0;
    for (int p : books) {
        if (load + p > limit) { ++students; load = 0; }
        load += p;
    }
    return students;
}

int allocateBooks(const vector<int>& books, int m) {
    if ((int)books.size() < m) return -1;            // not enough books
    long long lo = *max_element(books.begin(), books.end());
    long long hi = accumulate(books.begin(), books.end(), 0LL);
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (studentsNeeded(books, mid) <= m) hi = mid;
        else lo = mid + 1;
    }
    return (int)lo;
}

int main() {
    cout << allocateBooks({12, 34, 67, 90}, 2) << "\n";   // 113
    cout << allocateBooks({10, 20, 30, 40}, 2) << "\n";   // 60
    cout << allocateBooks({10, 20}, 3) << "\n";           // -1
    return 0;
}
