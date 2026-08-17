/*
 * 188. K Closest Points to Origin
 * Topic: Heap | Difficulty: Medium
 *
 * Return the k points nearest the origin.
 *
 * Approach: a max-heap of size k keyed on squared distance. The square root is
 * never needed - it is monotone, so comparing squared distances gives the same
 * ordering while staying in integer arithmetic.
 *
 * Time: O(n log k)   Space: O(k)
 */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > kClosest(const vector<vector<int> >& points, int k) {
    priority_queue<pair<long long, int> > heap;         // (dist^2, index), max-heap
    for (int i = 0; i < (int)points.size(); ++i) {
        long long d = (long long)points[i][0] * points[i][0] +
                      (long long)points[i][1] * points[i][1];
        heap.push(make_pair(d, i));
        if ((int)heap.size() > k) heap.pop();           // drop the farthest
    }
    vector<vector<int> > out;
    while (!heap.empty()) { out.push_back(points[heap.top().second]); heap.pop(); }
    return out;
}

int main() {
    vector<vector<int> > pts;
    pts.push_back(vector<int>{1, 3});
    pts.push_back(vector<int>{-2, 2});
    pts.push_back(vector<int>{5, 8});
    pts.push_back(vector<int>{0, 1});
    for (const auto& p : kClosest(pts, 2)) cout << "(" << p[0] << "," << p[1] << ") ";
    cout << "\n";   // (-2,2) (0,1)
    return 0;
}
