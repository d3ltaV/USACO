#include <cmath>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

//Naive recursion first; number of discarded boots
int step(vector<int> tiles, vector<int> depth, vector<int> dist, int pointerTiles, int pointerBoots, int n, int b) {
    if (pointerTiles == n - 1) {
        return 0;
    } 
    if (pointerBoots == b) {
        return INT_MAX;
    }
    int min_discarded = INT_MAX;
    if (tiles.at(pointerTiles) > depth.at(pointerBoots)) {
        int temp = 1 + step(tiles, depth, dist, pointerTiles, pointerBoots + 1, n, b);
        min_discarded = min(min_discarded, temp);
    }
    for (int i = 1; i <= dist.at(pointerBoots) && pointerTiles + i < n; i++) {
        if (tiles.at(pointerTiles + i <= depth.at(pointerBoots))) {
            int temp2 = step(tiles, depth, dist, pointerTiles + i, pointerBoots + 1, n, b);
            min_discarded = min(min_discarded, temp2);
        }
    }
}   
int main() {
    ifstream fin("snowboots.in");
    ofstream fout("snowboots.out");
    int n, b;
    fin >> n >> b;
    vector<int> tiles;
    vector<int> depth;
    vector<int> dist;
    for (int i = 0; i < n; i++) {
        int a;
        fin >> a;
        tiles.push_back(a);
    }
    for (int i = 0; i < b;) {
        int a, b;
        fin >> a >> b;
        depth.push_back(a);
        dist.push_back(b);
    }
    int min = step(tiles, depth, dist, 0, 0, n, b);
    fout << min;
}