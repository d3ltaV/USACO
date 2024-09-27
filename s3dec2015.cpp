#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");
    int n, q;
    fin >> n >> q;
    vector<int> id;
    vector<pair<int, int>> queries;
    for (int i = 0; i < n; i++) {
        int a;
        fin >> a;
        id.push_back(a);
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        fin >> a >> b;
        queries.push_back(make_pair(a, b));
    }
    //Brute force or prefix sums
    vector<vector<int>> pre;
    int h = 0, g = 0, j = 0;
    for (int i = 0; i < n; i++) {
        if (id.at(i) == 1) {
            h++;
        } else if (id.at(i) == 2) {
            g++;
        } else {
            j++;
        }
        vector<int> temp = {h, g, j};
        pre.push_back(temp);
    }
    vector<vector<int>> track;

    for (int i = 0; i < n; i++) {
        if (id.at(i) == 1) {
            vector<int> temp = {1, 0, 0};
            track.push_back(temp);
        } else if (id.at(i) == 2) {
            vector<int> temp = {0, 1, 0};
            track.push_back(temp);
        } else {
            vector<int> temp = {0, 0, 1};
            track.push_back(temp);
        }
    }
    for (int i = 0; i < q; i++) {
        int a = queries.at(i).first - 1;
        int b = queries.at(i).second - 1;
        int ans1 = pre.at(b).at(0) - pre.at(a).at(0) + track.at(a).at(0);
        int ans2 = pre.at(b).at(1) - pre.at(a).at(1) + track.at(a).at(1);
        int ans3 = pre.at(b).at(2) - pre.at(a).at(2) + track.at(a).at(2);
        fout << ans1 << " " << ans2 << " " << ans3 << "\n";
    }
}
