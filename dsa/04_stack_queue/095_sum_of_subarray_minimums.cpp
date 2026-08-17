/*
 * 095. Sum of Subarray Minimums
 * Topic: Stack & Queue | Difficulty: Medium
 *
 * Sum the minimum of every contiguous subarray, modulo 1e9+7.
 *
 * Approach: count each element's contribution. For arr[i], let L be the number
 * of choices for a left endpoint where arr[i] is still the minimum and R the
 * same on the right; then arr[i] is the minimum of exactly L*R subarrays.
 * Monotonic stacks find those spans, with strict on one side and non-strict on
 * the other so equal values are not double counted.
 *
 * Time: O(n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

int sumSubarrayMins(const vector<int>& arr) {
    const long long MOD = 1000000007LL;
    int n = arr.size();
    vector<int> left(n), right(n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {                  // strictly greater on the left
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
        left[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; --i) {             // greater or equal on the right
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        right[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }
    long long total = 0;
    for (int i = 0; i < n; ++i)
        total = (total + (long long)arr[i] * left[i] % MOD * right[i]) % MOD;
    return (int)total;
}

int main() {
    cout << sumSubarrayMins({3, 1, 2, 4}) << "\n";           // 17
    cout << sumSubarrayMins({11, 81, 94, 43, 3}) << "\n";    // 444
    return 0;
}
