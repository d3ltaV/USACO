#include <cstdio>
#include <vector>
#include <string>
#include <utility>

using namespace std;

//ADD TIME!!
int main() {
    int n;
    scanf("%d", &n);
    vector<pair<string, pair<int, int>>> vec;
    for (int i = 0; i < n; i++) {
        char s[1];
        int a, b;
        scanf("%s %d %d", s, &a, &b);
        vec.push_back(make_pair(string(s), make_pair(a, b)));
    }
    return 0;
    vector<vector<int>> faceEast;
    vector<vector<int>> faceNorth;
    vector<vector<int>> cows;
    for (int i = 0; i < n; i++) {
        //CASE 1
        if (vec.at(i).first == "E") {
            for (int j = 0; j < n; j++) {
                //SUBCASE 1
                if (vec.at(j).first == "N" && vec.at(j).second.second < vec.at(i).second.second) {
                    //LEFT
                    if (vec.at(j).second.first <= vec.at(i).second.first) {
                        cows[i].push_back(j);
                    } else { //RIGHT
                        if (vec.at(i).second.second - vec.at(j).second.second > 
                        vec.at(j).second.first - vec.at(j).second.first) {
                            cows[i].push_back(j);
                        }
                        // else if (vec.at(i).second.second - vec.at(j).second.second < 
                        // vec.at(i).second.first - vec.at(j).second.first) {
                        //     cows[j].push_back(i);
                        // }
                    }
                //SUBCASE 2
                } else if (vec.at(j).first == "N" && vec.at(j).second.second == vec.at(i).second.second) {
                    //LEFT
                    if (vec.at(j).second.first < vec.at(i).second.first) {
                        cows[i].push_back(j);
                    }
                    //RIGHT
                    // else {
                    //     cows[j].push_back(i);
                    // }
                }
            }
        //CASE 2
        } else {
            for (int j = 0; j < n; j++) {
                //SUBCASE 1
                if (vec.at(j).first == "N" && vec.at(j))
            }
        }
    }
}
// class dsu {
//     public: 
//         dsu(int n) {
//             parent.resize(n);
//             rank.resize(n, 0);
//             for (int i = 0; i < n; i++) {
//                 parent[i] = i;
//             }
//         }
//         int find(int x) {
//             if (parent[x] != x) {
//                 parent[x] = find(parent[x]);
//             }
//             return parent[x];
//         }

//         void unionSets(int x, int y) {
//             int rootX = find(x);
//             int rootY = find(y);

//             if (rootX != rootY) {
//                 if (rank[rootX] > rank[rootY]) {
//                     parent[rootY] = rootX;
//                 } else if (rank[rootX] < rank[rootY]) {
//                     parent[rootX] = rootY;
//                 } else {
//                     parent[rootY] = rootX;
//                     ++rank[rootX];
//                 }
//             }
//         }
//     private:
//         vector<int> parent;
//         vector<int> rank;
// };