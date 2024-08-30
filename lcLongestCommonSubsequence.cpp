//DP: this is naive recursive solution;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int lcs(string string1, string string2, int m, int n, vector<vector<int>> memo) {
    if (m == 0 || n == 0) {
        return 0;
    } else if (memo[m - 1][n - 1] != -1) {
        return (memo[m - 1][n - 1]);
    }
    else if (string1[m] == string2[n]) {
        memo[m - 1][n - 1] = 1 + lcs(string1, string2, m - 1, n -1, memo);
        return memo[m - 1][n - 1];
    } else {
        memo[m - 1][n - 1] = max(lcs(string1, string2, m - 1, n, memo), lcs(string1, string2, m, n - 1, memo)); 
        return memo[m - 1][n - 1];
    } 
}
int main() {
    string string1, string2;
    cin >> string1 >> string2;
    int m = string1.length();
    int n = string2.length();

    vector<vector<int>> memo(m, vector<int>(n, -1));
    int res = lcs(string1, string2, m, n, memo);
    cout << res;
}



