#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> pots(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> pots[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b - 1); //0-indexing
        adj[b].push_back(a - 1);
    }
    vector<int> leaves;
    for (int i = 1; i < n; i++) { //exclude node 1
        if (adj[i].size() == 1) {
            leaves.push_back(i);
        }
    }
    unordered_map<int, int> ancestors;
}