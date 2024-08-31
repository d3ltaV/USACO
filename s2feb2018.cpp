#include <cmath>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

//Naive recursion first
int step(vector<int> tiles, vector<int> depth, vector<int> dist, int pointerTiles, int pointerBoots, int n, int b) {
    if (pointerTiles == n - 1) {
        return 0;
    } 
    if (tiles.at(pointerTiles) >  )
    for (int i = 0; i < n; i++) {
        return step(tiles, depth, )
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
}