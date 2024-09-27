// #include <fstream>
// #include <iostream>
// #include <vector>
// #include <cstdio>
// #include <algorithm>
// using namespace std;

// int main() {
//     int k, m, n;
//     scanf("%d %d %d", &k, &m, &n);
//     vector<pair<int, int>> patches;
//     vector<int> cows;
//     int max = INT_MIN;
//     for (int i = 0; i < k; i++) {
//         int a, b;
//         scanf("%d %d", &a, &b);
//         if (a > max) {
//             max = a;
//         }
//         patches.push_back(make_pair(a, b));
//     }
//     for (int i = 0; i < m; i++) {
//         int a;
//         scanf("%d", &a);
//         cows.push_back(a);
//     }
//     vector<int> line(max + 1, -1);
//     for (int i = 0; i < m; i++) {
//         line.at(patches.at(i).first) = patches.at(i).second;
//     }
//     int total = 2 + (m - 2) * 2;
//     vector<int> sums(total, 0);
//     for (int i = 0; i < m; i++) {
//         if (i == 0) {
//             int left = 0; 
//             int right = cows.at(i);
//             while (left <= right) {
//                 if (line.at(left) != -1) {
//                     sums.at(i) += line.at(left);
//                 }
//                 left++;
//             }
//         } else if (i == m - 1) {
//             int left = cows.at(i);
//             int right = max;
//             while (left <= right) {
//                 if (line.at(left) != -1) {
//                     sums.at(i) += line.at(left);
//                 }
//                 left++;
//             }
//         } else {
//             int left = cows.at(i);
//             int right = cows.at(i + 1);
//             int mid = left + (right - left) / 2;
//             int i1 = i * 2 - 1;
//             int i2 = i * 2;
//             while (left <= mid) {
//                 if (line.at(left) != -1) {
//                     sums.at(i1) += line.at(left);
//                 }
//                 left++;
//             }
//             while (mid <= right) {
//                 if (line.at(mid) != -1) {
//                     sums.at(i2) += line.at(mid);
//                 }
//                 mid++;
//             }
//         }
//         for (int i = 0; i < total; i++) {
//             printf("%d ", sums.at(i));
//         }
//         printf("\n");
//         sort(sums.begin(), sums.end());
//         for (int i = 0; i < total; i++) {
//             printf("%d ", sums.at(i));
//         }
//         int ans = 0;
//         printf("\n");
//         for (int i = 0; i < n; i++) {
//             int add = sums.at(sums.size() - 1 - i);
//             // printf("%d ", add);
//             ans += add;
//         }
//         printf("%d", ans);
//     }
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>

// using namespace std;

// int main() {
//     int k, m, n;
//     cin >> k >> m >> n;
    
//     vector<pair<int, int>> patches(k);
//     vector<int> cows(m);
//     int max_pos = INT_MIN;
    
//     // Input grass patches
//     for (int i = 0; i < k; i++) {
//         cin >> patches[i].first >> patches[i].second;
//         if (patches[i].first > max_pos) {
//             max_pos = patches[i].first;
//         }
//     }

//     // Input cow positions
//     for (int i = 0; i < m; i++) {
//         cin >> cows[i];
//     }

//     // Sort cows' positions
//     sort(cows.begin(), cows.end());

//     // Create a line array for grass patches
//     vector<int> line(max_pos + 1, 0);
//     for (const auto& patch : patches) {
//         line[patch.first] = patch.second;
//     }

//     // Calculate the total grass between each cow
//     vector<int> grass_totals;
    
//     for (int i = 0; i < m; i++) {
//         int left = (i == 0) ? 0 : cows[i - 1];
//         int right = (i == m - 1) ? max_pos : cows[i];

//         int sum = 0;
//         for (int pos = left; pos <= right; pos++) {
//             sum += line[pos];
//         }
//         grass_totals.push_back(sum);
//     }

//     // Sort the total grass values and sum the largest `n` values
//     sort(grass_totals.rbegin(), grass_totals.rend());

//     int answer = 0;
//     for (int i = 0; i < n && i < grass_totals.size(); i++) {
//         answer += grass_totals[i];
//     }

//     // Output the result
//     cout << answer << endl;

//     return 0;
// }
