/*
 * 203. Flood Fill
 * Topic: Graphs | Difficulty: Easy
 *
 * Recolour the connected region containing a starting pixel, like a paint bucket
 * tool.
 *
 * Approach: DFS from the seed, recolouring cells that still hold the original
 * colour. Bailing out early when the new colour equals the old one is what
 * prevents infinite recursion, since the "already recoloured" test would never
 * fire.
 *
 * Time: O(m * n)   Space: O(m * n) recursion worst case
 */
#include <bits/stdc++.h>
using namespace std;

static void fill(vector<vector<int> >& img, int r, int c, int from, int to) {
    if (r < 0 || c < 0 || r >= (int)img.size() || c >= (int)img[0].size()) return;
    if (img[r][c] != from) return;
    img[r][c] = to;
    fill(img, r + 1, c, from, to);
    fill(img, r - 1, c, from, to);
    fill(img, r, c + 1, from, to);
    fill(img, r, c - 1, from, to);
}

vector<vector<int> > floodFill(vector<vector<int> > image, int sr, int sc, int color) {
    if (image[sr][sc] != color) fill(image, sr, sc, image[sr][sc], color);
    return image;
}

int main() {
    vector<vector<int> > img = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    for (const auto& row : floodFill(img, 1, 1, 2)) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
    // 2 2 2 / 2 2 0 / 2 0 1
    return 0;
}
