#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("lemonade.in");
    ofstream fout("lemonade.out");
    int n;
    fin >> n;
    vector<int> weights;
    for (int i = 0; i < n; i++) {
        int temp; 
        fin >> temp;
        weights.push_back(temp);
    }
    sort(weights.begin(), weights.end());
    int p1 = 0;
    int p2 = n;
    int counter = 0;
    while (p1 < p2) {
        p2--;
        counter++;
        while (weights.at(p1) < counter) {
            p1++;
        }
    }
    fout << counter << "\n";
    return 0;
}
// #include <iostream>
// #include <vector>
// #include <algorithm>

// int main() {
//     int n;
//     std::cin >> n;
//     std::vector<int> weights(n);
//     for (int i = 0; i < n; i++) {
//         std::cin >> weights[i];
//     }
//     std::sort(weights.begin(), weights.end());
//     int p1 = 0;
//     int p2 = n;
//     int counter = 0;
//     while (p1 < p2) {
//         p2--;
//         counter++;
//         while (weights.at(p1) < counter) {
//             p1++;
//         }
//     }
//     //printing wrong answer, its n - p2
//     int ans = n - p2;
//     std::cout << p2 << "\n";
//     std::cout << ans << "\n";
//     return 0;
// }
