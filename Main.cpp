#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pots(n, 0);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        pots[i] = temp - 1;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;  
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //leaf nodes
    vector<int> leaves;
    for (int i = 1; i < n; i++) {  //no root
        if (adj[i].size() == 1) {
            leaves.push_back(i);
        }
    }

    unordered_map<int, int> parents;
    vector<vector<int>> ancestors(n);
    queue<int> q;
    vector<bool> visited(n, false);
    visited[0] = true;
    parents[0] = -1;
    q.push(0);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int child : adj[node]) {
            if (!visited[child]) {
                parents[child] = node;
                visited[child] = true;
                q.push(child);
                ancestors[child] = ancestors[node];
                ancestors[child].push_back(node);
            }
        }
    }
    int shortest=leaves.size();
    pots.resize(shortest);
    //for some reason this doens twork even though its the same greedy idea as the solution; the solution just simulates it.
    // Calculate closest pot for each leaf
    vector<int> closest(n, -1);
    for (int i = 0; i < leaves.size(); i++) {
        int leaf = leaves[i];
        if (find(pots.begin(), pots.end(), leaf) != pots.end()) {
            closest[leaf] = leaf;
            pots.erase(find(pots.begin(), pots.end(), leaf));
        } else {
            for (int j = 0; j < ancestors[leaf].size(); j++) {
                if (find(pots.begin(), pots.end(), ancestors[leaf][j]) != pots.end()) {
                    closest[leaf] = ancestors[leaf][j];
                    pots.erase(find(pots.begin(), pots.end(), ancestors[leaf][j]));
                    break;
                }
            }
        }
    }
    set<int> distinct;
    for (int i = 0; i < closest.size(); i++) {
        if (closest[i] != -1) {
            distinct.insert(closest[i]);
        }
    }
    int ans = distinct.size();
    cout << ans;

    return 0;
}
