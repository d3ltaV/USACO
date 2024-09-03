#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int solve(vector<int> balls, vector<int> closestPrevious) {
    vector<int> dp(balls.size(), 0);
    for (int i = 0; i < balls.size(); i++) {
        if (closestPrevious.at(i) != -1) {
            int temp = i - closestPrevious.at(i) + 1;
            if (closestPrevious.at(i) == 0) {
                dp.at(i) = temp;
            } else if (temp + dp.at(closestPrevious.at(i) - 1) > dp.at(i - 1)) {
                dp.at(i) = temp + dp.at(closestPrevious.at(i) - 1);
            } else {
                dp.at(i) = dp.at(i - 1);
            }
        } else {
            if (i == 0) {
                dp.at(i) = 0;
            } else {
                dp.at(i) = dp.at(i - 1);
            }
        }
    }
    return dp.at(balls.size() - 1);
}

int check(vector<int> arr, int target, int start) {
    for (int i = start; i >= 0; i--) {
        if (arr.at(i) == target){
            return i;
        }
    }
    return -1;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int n;
        scanf("%d", &n);
        vector<int> balls;
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            balls.push_back(a);
        }
        // vector<pair<int, int>> closestPrevious = {make_pair(-1, -1)};
        // for (int i = 0; i < n; i++) {
        //     if (check(closestPrevious, balls.at(i)) == -1) {
        //         closestPrevious.push_back(make_pair(balls.at))
        //     }
        // }
        vector<int> closestPrevious(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            closestPrevious.at(i) = check(balls, balls.at(i), i - 1);
        }
        int ans = solve(balls, closestPrevious);
        cout << ans << "\n";
    }
}