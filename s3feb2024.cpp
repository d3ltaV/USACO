#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int t;
    scanf("%t", &t);
    while (t-- > 0) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        vector<vector<int>> bessie;
        //first = biggest even, second = biggest odd
        vector<pair<int, int>> biggest;
        for (int i = 0; i < m; i++) {
            vector<int> add;
            bessie.push_back(add);
            biggest.push_back(make_pair(-1, -1));
            for (int j = 0; j < k; j++) {
                int temp;
                scanf("%d", &temp);
                bessie.at(i).push_back(temp);
                if (temp % 2 == 0) {
                    if (temp > biggest.at(i).first) {
                        biggest.at(i).first = temp;
                    }
                } else {
                    if (temp > biggest.at(i).second) {
                        biggest.at(i).second = temp;
                    }
                }
            }
        }
        //0 even, 1 odd.
        vector<int> turns;
        for (int i = 0; i < m; i++) {
            if (biggest.at(i).first > biggest.at(i).second) {
                turns.push_back(0);
            } else {
                turns.push_back(1);
            }
        }
        for (int i = 0; i < m; i++) {
            
        }
    }
}