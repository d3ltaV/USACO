

#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 100010;
int N; // number of cows
int buddy_of[MAXN]; // which cow each points to
int value[MAXN]; // how many times each cow moos

int done[MAXN]; // which ones are already removed
int in_degree[MAXN]; // keep track of in-degree as we process nodes

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> buddy_of[i] >> value[i];
        buddy_of[i]--;
    }
    for (int i = 0; i < N; i++) {
        in_degree[buddy_of[i]]++;
    }
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    long long ans = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        // mark x as done
        done[x] = true;
        // update ans
        ans += value[x];
        in_degree[buddy_of[x]]--;
        if (in_degree[buddy_of[x]] == 0) {
            q.push(buddy_of[x]);
        }
    }
    for (int i = 0; i < N; i++) {
        if (!done[i]) { //if node has an an in degree > 0, it must be a part of a cycle. For every node that has in degree more than 1, one node must have in degree 0 (for every extra in degree). those nodes are removed!
            // found a cycle
            // loop over the cycle
            int start = i, curr = start;
            long long cycle_sum = 0;
            int smallest_value = value[start];
            do {
                cycle_sum += value[curr];
                smallest_value = min(smallest_value, value[curr]);
                done[curr] = true;
                curr = buddy_of[curr]; 
            } while (curr != start);

            ans += cycle_sum;
            ans -= smallest_value;
        }
    }
    cout << ans << "\n";

    return 0;
}

// #include <cstdio>
// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <climits>
// #include <algorithm>
// using namespace std;
// // DSU for all connected components of graph (cycles); for each cycle, add the sum of edges - minimum edge;
// //DSU only works fo undirected graphs; DFS for all cyclic components of graph.
// //Mistake: didn't realize that in degrees could be zero; thought that it was all cycles. If in degree = 0, immediately add to result out degree value because it doesn't affect the cycles.

//this dfs is too slow
// vector<bool> visited;
// pair<int, int> dfs(int node, vector<vector<pair<int, int>>> &adj, int &total, int &min, int parent) {
//     visited[node] = true;
//     for (pair<int, int> child : adj.at(node)) {
//         if (!visited[child.first]) {
//             total += child.second;
//             if (child.second < min) {
//                 min = child.second;
//             }
//             dfs(child.first, adj, total, min, parent);
//         } else if (child.first == parent) {
//             total += child.second;
//             if (child.second < min) {
//                 min = child.second;
//             }
//         }
//     }
//     return make_pair(total, min);
// }
// int main() {
//     int n;
//     int ans = 0;
//     visited.resize(n, false);
//     scanf("%d", &n);
//     vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
//     for (int i = 0; i < n; i++) {
//         int a, b;
//         scanf("%d %d", &a, &b);
//         adj.at(i).push_back(make_pair(a - 1, b));
//     }
//     vector<int> inDegrees(n, 0);
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < adj.at(i).size(); j++) {
//             inDegrees.at(adj.at(i).at(j).first) += 1;
//         }
//     }
///     USE STACKS!!!
//     for (int i = 0; i < n; i++) {
//         if (inDegrees.at(i) == 0) {
//             int a = adj.at(i).at(0).second;
//             ans += a;
//             visited[i] = true;
//             inDegrees.at(adj.at(i).at(0).first) -= 1;
//             if (inDegrees.at(adj.at(i).at(0).first) == 0) {
//                 int b = adj.at(adj.at(i).at(0).first).at(0).f
//             }
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         if (!visited[i]) {
//             int totalWeight = 0;
//             int minEdge = INT_MAX;
//             pair<int, int> result = dfs(i, adj, totalWeight, minEdge, i);
//             // cout << result.first <<" " << result.second << " ";
//             ans += (result.first - result.second);
//         }
//     }
//     printf("%d", ans);
// }