#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<long long> dp;
const long long MOD = 1000000007;

long long num(const string& s) {
    int n = s.length();
    dp.assign(n + 1, 1LL);
    for (int i = 1; i <= n; i++) {
        if (s[i-1] == 'w' || s[i-1] == 'm') {
            return 0;
        }
        dp[i] = dp[i-1];
        if (i > 1 && (s[i-1] == s[i-2]) && (s[i-1] == 'n' || s[i-1] == 'u')) {
            dp[i] = (dp[i] + dp[i-2]) % MOD;
        }
    }
    return dp[n];
}

int main() {
    string s;
    cin >> s;
    long long ans = num(s);
    cout << ans << endl;
    return 0;
}

// #include <vector>
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// using namespace std;
// vector<int> dp;

// int num(string s) {
//     int counter = 0;
//     for (int i = 1; i < s.length(); i++) {
//         char c = s.at(i);
//         if (c == 'w' || c == 'm') {
//             return 0;
//         }
//         if (c == 'n' || c == 'u') {
//             if (s.at(i - 1) == c) {
//                 counter ++;
//                 dp.at(i) = counter * (dp.at(i - counter));
//             } else {
//                 counter = 1;
//             }
//         } else {
//             counter = 1;
//         }
//     }
//     return dp.at(s.length() - 1);
// }
// int main() {
//     string s;
//     cin >> s;
//     dp.assign(s.length(), 1);
//     int ans = num(s);
//     cout << ans;
// }