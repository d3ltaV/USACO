//just had no idea how to code the dfs to contain sums and use that to traverse (the two if statements)
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;
const int MAXN = 200005;

struct order_struct {
    int src, dest;
    ll amt;
};
ll haybales[MAXN];
ll hSum[MAXN];
vector<vector<int>> adj;
vector<order_struct> orders;

ll dfs_ord(int node, int p) {
    ll cur_sum = haybales[node];
    for (int child : adj[node]) {
        if (child != p) {
            cur_sum += dfs_ord(child, node);
        }
    }
    hSum[node] = cur_sum;
    return cur_sum;
}
ll dfs(int node, int p) {
    for (int child : adj[node]) {
        if (hSum[child] > 0) {
            dfs(child, node);
        }
    }
    for (int child : adj[node]) {
        if (hSum[child] <= 0) {
            if (hSum[child] < 0) {
                orders.push_back({node, child, -hSum[child]});
            }
            dfs(child, node);
        }
    }
    if (node != 1 && hSum[node] > 0) {
        orders.push_back({node, p, hSum[node]});
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        haybales[i] = temp;
        sum += temp;
    }
    int goal = sum / n;
    for (int i = 1; i <= n; i++) {
        haybales[i] -= goal;
    }
    adj.resize(n + 1);
    for (int i = 0; i < n; i++) {
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    dfs_ord(1, -1);
    dfs(1, -1);
}
