#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
vector<int> solve(vector<vector<int>> bessie, vector<pair<int, int>> biggest, int m, int n) {
        //0 even, 1 odd.
        vector<int> turns;
        int total = 0;
        for (int i = 0; i < m; i++) {
            if (biggest.at(i).first > biggest.at(i).second) {
                turns.push_back(0);
                total += biggest.at(i).first;
            } else {
                turns.push_back(1);
                total += biggest.at(i).second;
            }
        }
        if (total >= n) {
            vector<int> vec = {-1};
            return vec;
        }
        for (int i = 0; i < m; i++) {
            if (turns.at(i) == 1) {
                int tempTotal = total;
                tempTotal -= biggest.at(i).second;
                tempTotal += biggest.at(i).first;
                if (tempTotal < n) {
                    turns.at(i) = 0;
                    total -= biggest.at(i).second;
                    total += biggest.at(i).first;
                }
            }
        }
        return turns;
}
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
        vector<int> turns = solve(bessie, biggest, m, n);
        for (int i = 0; i < m; i++) {
            if (turns.at(i) == 0) {
                printf("Even ");
            } else {
                printf("Odd ");
            }
        }
        printf("\n");

    }
}