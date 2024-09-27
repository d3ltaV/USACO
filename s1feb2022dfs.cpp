#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
vector<vector<int>> preferences;

int dfs(int node, int parent, int target, vector<bool> visited) {
    visited.at(node) = true;
    for (int child : preferences.at(node)) {
        if (!visited.at(child)) {
            if (dfs(child, node, target, visited)) {
                return 1;
            } 
        } else if (child != parent && child == target) {
            return 1;
        }
    }
}
int find(int x, int target) {
    for (int i = 0; i < preferences.at(x).size(); i++) {
        if (preferences.at(x).at(i) == target) {
            return i;
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        preferences.push_back(temp);
        for (int j = 0; j < n; j++) {
            int a;
            scanf("%d", &n);
            preferences.at(i).push_back(a - 1);
            if (a == i + 1) {
                while (j < n) {
                    int b;
                    scanf("%d", &b);
                    j++;
                }
            }
        }

    }
    vector<vector<int>> reachable(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            vector<bool> visited(n, false);
            if (dfs(i, -1, j, visited)) {
                reachable.at(i).at(j) = true;
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        int minIndex = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (preferences.at(i).at(j) == true){ 
                int ind = find(i, j + 1);
                if (ind < minIndex) {
                    minIndex = ind;
                }
            }
        }
        cout << minIndex;
    }
    return 0;
}