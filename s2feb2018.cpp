#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Naive recursion; number of discarded boots
int step(vector<int> tiles, vector<int> depth, vector<int> dist, int pointerTiles, int pointerBoots, int n, int b) {
    if (pointerTiles == n - 1) {
        return 0;
    } 
    if (pointerBoots == b) {
        return INT_MAX;
    }
    int min_discarded = INT_MAX;
    
    // Option 1: Switch boots
    if (tiles[pointerTiles] > depth[pointerBoots]) {
        int temp = 1 + step(tiles, depth, dist, pointerTiles, pointerBoots + 1, n, b);
        min_discarded = min(min_discarded, temp);
    } else {
        for (int i = 1; i <= dist[pointerBoots] && pointerTiles + i < n; i++) {
            if (tiles[pointerTiles + i] <= depth[pointerBoots]) {
                int temp2 = 1 + step(tiles, depth, dist, pointerTiles + i, pointerBoots + 1, n, b);
                min_discarded = min(min_discarded, temp2);
            }
        }
    }
    
    return min_discarded;
}

int main() {
    int n, b;
    cin >> n >> b;

    vector<int> tiles(n);
    vector<int> depth(b);
    vector<int> dist(b);

    for (int i = 0; i < n; i++) {
        cin >> tiles[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> depth[i] >> dist[i];
    }

    int minDiscardedBoots = step(tiles, depth, dist, 0, 0, n, b);
    
    cout << minDiscardedBoots << endl;

    return 0;
}
