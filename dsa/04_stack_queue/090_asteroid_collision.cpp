/*
 * 090. Asteroid Collision
 * Topic: Stack & Queue | Difficulty: Medium
 *
 * Positive values move right, negative move left. On collision the smaller one
 * explodes; equal sizes destroy each other. Return the surviving asteroids.
 *
 * Approach: a stack holding survivors. Only a left-moving asteroid meeting a
 * right-moving one on the stack top collides, so resolve that case in an inner
 * loop and push the newcomer if it survives.
 *
 * Time: O(n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(const vector<int>& asteroids) {
    vector<int> st;
    for (int a : asteroids) {
        bool alive = true;
        while (alive && a < 0 && !st.empty() && st.back() > 0) {
            if (st.back() < -a) st.pop_back();          // top explodes, keep going
            else if (st.back() == -a) { st.pop_back(); alive = false; }
            else alive = false;                          // incoming explodes
        }
        if (alive) st.push_back(a);
    }
    return st;
}

int main() {
    for (int x : asteroidCollision({5, 10, -5})) cout << x << " ";
    cout << "\n";   // 5 10
    for (int x : asteroidCollision({8, -8})) cout << x << " ";
    cout << "\n";   // (empty)
    for (int x : asteroidCollision({10, 2, -5})) cout << x << " ";
    cout << "\n";   // 10
    return 0;
}
