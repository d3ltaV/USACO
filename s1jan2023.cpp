// //Did not realize other way of saving a move: if complete cycle, then extra character required. if not, then there is a way of doing it without saving a move.
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>


using namespace std;

int fromchar(char c) {
    if (islower(c)) return 26 + c - 'a';
    return c - 'A';
}

int cmap[52];
int indeg[52];
bool vis[52];

int solve(string s1, string s2) {
    if (s1 == s2) {
        return 0;
    }

    fill(cmap, cmap + 52, -1);
    fill(vis, vis + 52, false);
    fill(indeg, indeg + 52, 0);

    int n = s1.length();
    set<int> distinct;   // Set to store distinct destination characters in s2

    for (int i = 0; i < n; i++) {
        int from = fromchar(s1[i]), to = fromchar(s2[i]);
        distinct.insert(to);  

        if (cmap[from] == -1) {
            cmap[from] = to;  
            indeg[to]++;      // Increase the indegree of the 'to' character
        } else if (cmap[from] != to) {
            return -1;        // Invalid case: two different mappings for the same 'from'
        }
    }

    if (distinct.size() == 52) {
        return -1;
    }
    int ans = 0;

    for (int i = 0; i < 52; i++) {
        if (cmap[i] == i) {
            cmap[i] = -1;
        }
    }
    for (int i = 0; i < 52; i++) {
        if (cmap[i] == -1) continue;
        vector<int> cycle;
        bool isPure = true;
        int ci = i;

        while (true) {
            if (cmap[ci] == -1) {
                break;  // End of the chain
            }

            bool isCycle = false;
            for (int j = 0; j < cycle.size(); j++) {
                if (ci == cycle[j]) {
                    isCycle = true;  
                    if (isPure) ans++;  // Only count pure cycles
                    break;
                }
            }

            if (isCycle) break;  
            if (vis[ci]) break;  
            vis[ci] = true;  
            cycle.push_back(ci);  
            ans++;  

            if (indeg[ci] > 1) isPure = false; 

            ci = cmap[ci];  
        }
    }

    return ans; 
}

int main() {
    int t;
    cin >> t;  
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; 
        int result = solve(s1, s2);
        cout << result << endl; 
    }

    return 0;
}

// #include <vector>
// #include <algorithm>
// #include <cstdio>
// #include <iostream>
// #include <cmath>
// #include <cstring>

// using namespace std;

// int checkFirst(const vector<pair<char, vector<char>>>& ct, char target) {
//     for (int i = 0; i < ct.size(); i++) {
//         if (ct[i].first == target) {
//             return i;
//         }
//     }
//     return -1;
// }

// int checkSecond(const vector<pair<char, vector<char>>>& ct, char target, int ind) {
//     for (int i = 0; i < ct[ind].second.size(); i++) {
//         if (ct[ind].second[i] == target) {
//             return i;
//         }
//     }
//     return -1;
// }

// int main() {
//     int t;
//     scanf("%d", &t);
//     while (t-- > 0) {
//         char inp[100001];
//         char out[100001];
//         scanf("%s", inp);
//         scanf("%s", out);
//         vector<pair<char, vector<char>>> ct;
//         bool alphaUpper[26] = {false};
//         bool alphaLower[26] = {false};

//         for (int i = 0; i < strlen(inp); i++) {
//             if (isupper(inp[i])) {
//                 alphaUpper[inp[i] - 'A'] = true;
//             } else if (islower(inp[i])) {
//                 alphaLower[inp[i] - 'a'] = true;
//             }
//         }

//         bool allUpperAndLower = true;
//         bool checkOrder = true;

//         for (int i = 0; i < 26; i++) {
//             if (!alphaUpper[i] && !alphaLower[i]) {
//                 allUpperAndLower = false;
//                 break;
//             }
//         }

//         for (int i = 0; i < strlen(inp); i++) {
//             if (inp[i] != out[i]) {
//                 checkOrder = false;
//                 break;
//             }
//         }

//         if (allUpperAndLower && !checkOrder) {
//             printf("-1\n");
//         } else {
//             for (int i = 0; i < strlen(inp); i++) {
//                 int index = checkFirst(ct, inp[i]);
//                 if (index != -1) {
//                     int secondIndex = checkSecond(ct, out[i], index);
//                     if (secondIndex == -1) {
//                         ct[index].second.push_back(out[i]);
//                     }
//                 } else {
//                     vector<char> newV = {out[i]};
//                     ct.push_back(make_pair(inp[i], newV));
//                 }
//             }

//             // Debugging output
//             for (int i = 0; i < ct.size(); i++) {
//                 printf("(%c: ", ct[i].first);
//                 for (int j = 0; j < ct[i].second.size(); j++) {
//                     printf("%c", ct[i].second[j]);
//                     if (j != ct[i].second.size() - 1) printf(", ");
//                 }
//                 printf(") ");
//             }
//             printf("\n");

//             bool size = true;
//             for (int i = 0; i < ct.size(); i++) {
//                 if (ct[i].second.size() > 1) {
//                     size = false;
//                     break;
//                 }
//             }

//             if (!size) {
//                 printf("-1\n");
//             } else {
//                 double counter = 0;
//                 for (int i = 0; i < ct.size(); i++) {
//                     if (ct[i].first != ct[i].second[0]) {
//                         int temp = checkFirst(ct, ct[i].second[0]);
//                         if (temp != -1) {
//                             if (ct[temp].first == ct[i].second[0] && ct[temp].second[0] == ct[i].first) {
//                                 counter += 1.5;
//                             } else {
//                                 counter += 1;
//                             }
//                         } else {
//                             counter += 1;
//                         }
//                     }
//                 }
//                 printf("%.0f\n", counter);
//             }
//         }
//     }
// }
