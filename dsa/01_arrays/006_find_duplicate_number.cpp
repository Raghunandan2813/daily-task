/*
 * 006. Find the Duplicate Number
 * Topic: Arrays | Difficulty: Medium
 *
 * An array of n+1 integers where every value is in [1, n]. Exactly one value is
 * repeated. Find it without modifying the array and using O(1) extra space.
 *
 * Approach: treat i -> nums[i] as a linked list. A repeated value means two
 * indices point to the same node, so the list has a cycle whose entrance is the
 * duplicate. Use Floyd's tortoise and hare to find that entrance.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int findDuplicate(const vector<int>& nums) {
    int slow = nums[0], fast = nums[nums[0]];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main() {
    cout << findDuplicate({1, 3, 4, 2, 2}) << "\n";      // 2
    cout << findDuplicate({3, 1, 3, 4, 2}) << "\n";      // 3
    return 0;
}
