#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

string processSubstring(string sub) {
    string result;
    for (char c : sub) {
        if (!result.empty() && result.back() == c && c != 'c') {
            result.pop_back();
        } else {
            result.push_back(c);
        }
    }
    for (char c : result) {
        
    }
}
int main() {
    string s;
    int q;
    scanf("%s", s);
    scanf("%d", q);
    vector<pair<int, int>> queries;
    for (int i = 0; i < q; i++) {
        int a, b;
        scanf("%d %d", a, b);
        a -= 1;
        b -= 1;
        queries.push_back(make_pair(a, b));
    }
    for (int i = 0; i < q; i++) {
        int len = queries.at(i).second - queries.at(i).first + 1;
        string sub = s.substr(queries.at(i).first, len);

    }
}