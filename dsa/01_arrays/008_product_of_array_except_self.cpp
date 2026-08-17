/*
 * 008. Product of Array Except Self
 * Topic: Arrays | Difficulty: Medium
 *
 * Return an array where out[i] is the product of every element except nums[i].
 * Division is not allowed.
 *
 * Approach: out[i] = (product of everything left of i) * (product right of i).
 * Fill out with prefix products in one pass, then multiply in suffix products on
 * the way back using a single running variable.
 *
 * Time: O(n)   Space: O(1) extra (output not counted)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(const vector<int>& nums) {
    int n = nums.size();
    vector<int> out(n, 1);
    for (int i = 1; i < n; ++i) out[i] = out[i - 1] * nums[i - 1];
    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
        out[i] *= suffix;
        suffix *= nums[i];
    }
    return out;
}

int main() {
    for (int x : productExceptSelf({1, 2, 3, 4})) cout << x << " ";
    cout << "\n";   // 24 12 8 6
    return 0;
}
