#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("sort.in");
    ofstream fout("sort.out");

    int n;
    fin >> n;
    vector<pair<int, int>> vec(n); 
    for (int i = 0; i < n; i++) {
        fin >> vec[i].first;
        vec[i].second = i;
    }
    sort(vec.begin(), vec.end());

    int max_moo_count = 0;

//maximum number of moves any element made
    for (int i = 0; i < n; i++) {
        max_moo_count = max(max_moo_count, vec[i].second - i);
    }
    fout << max_moo_count + 1 << endl;
    return 0;
}
// #include <iostream>
// #include <fstream>
// #include <vector>

// using namespace std;

// int main() {
//     ifstream fin("sort.in");
//     ofstream fout("sort.out");
//     int n = 0;
//     fin >> n;
//     vector<int> vec(n);
//     for (int i = 0; i < n; i++) {
//         fin >> vec[i];
//     }
//     bool sorted = false;
//     int count = 0;
//     while (!sorted) {
//         sorted = true;
//         count++;
//         for (int i = 0; i < n - 2; i++) {
//             if (vec[i] > vec[i + 1]) {
//                 int temp = vec[i + 1];
//                 vec[i + 1] = vec[i];
//                 vec[i] = temp;
//                 sorted = false;
//             }
//         }
//         fout << count;
//     }
//     return 0;
// }

