//weirdly worded question. you optimize for each cow, without considering other cows!!! dfs for each cow.
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> preference(n, vector<int>(n, -1));
    vector<vector<int>> position(n, vector<int>(n, -1));
    vector<int> pointer(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            scanf("%d", &temp);
            preference[i][j] = temp;
            position[i][temp - 1] = j;
            if (temp == i + 1) {
                pointer[i] = j;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = pointer[i] - 1; j >= 0; j--) {
            int preferred_gift = preference[i][j] - 1;
            int cow_with_preferred_gift = -1;

            for (int k = 0; k < n; k++) {
                if (pointer[k] == position[k][preferred_gift]) {
                    cow_with_preferred_gift = k;
                    break;
                }
            }

            if (cow_with_preferred_gift != -1) {
                if (position[i][preferred_gift] < pointer[i] && 
                    position[cow_with_preferred_gift][preference[cow_with_preferred_gift][pointer[cow_with_preferred_gift]]] < pointer[cow_with_preferred_gift]) {
                    pointer[i] = position[i][preferred_gift];
                    pointer[cow_with_preferred_gift] = position[cow_with_preferred_gift][preference[cow_with_preferred_gift][pointer[cow_with_preferred_gift]] - 1];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", preference[i][pointer[i]]);
    }

    return 0;
}

// #include <cstdio>
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     int n;
//     scanf("%d", &n);
//     vector<vector<int>> preference(n, vector<int>(n));
//     vector<vector<int>> position(n, vector<int>(n));
//     vector<int> pointer(n);

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             int temp;
//             scanf("%d", &temp);
//             preference[i][j] = temp;
//             position[i][temp - 1] = j;
//             if (temp == i + 1) {
//                 pointer[i] = j;
//             }
//         }
//     }

//     for (int i = 0; i < n; i++) {
//         int tempPoint = pointer[i] - 1;
//         while (tempPoint >= 0) {
//             int check = preference[i][tempPoint] - 1;
//             int max = pointer[check];
//             int max2 = pointer[i];

//             if (position[check][preference[i][max2] - 1] < max && 
//                 position[i][preference[check][max] - 1] < max2) {
//                 pointer[i] = tempPoint;
//                 pointer[check] = position[check][preference[i][max2] - 1];
//             }
//             tempPoint--;
//         }
//     }

//     for (int i = 0; i < n; i++) {
//         int pr = preference[i][pointer[i]];
//         printf("%d\n", pr);
//     }

//     return 0;
// }

// // #include <cstdio>
// // #include <iostream>
// // #include <vector>
// // #include <algorithm>
// // #include <climits>
// // #include <cmath>
// // using namespace std;
// // int main() {
// //     int n;
// //     scanf("%d", &n);
// //     vector<vector<int>> preference(n, vector<int>(n, -1));
// //     vector<vector<int>> position(n, vector<int>(n, -1));
// //     vector<int> pointer(n, -1);
// //     for (int i = 0; i < n; i++) {
// //         for (int j = 0; j < n; j++) {
// //             int temp;
// //             scanf("%d", & temp);
// //             preference.at(i).at(j) = temp;
// //             position.at(i).at(temp - 1) = j;
// //             if (temp == i + 1) {
// //                 pointer.at(i) = j;
// //             }
// //         }
// //     }
    
// //     for (int i = 0; i < n; i++) {
// //         cout << pointer.at(i) << " ";
// //     }
// //     cout << "\n";
// //     for (int i = 0; i < n; i++) {
// //         int tempPoint = pointer.at(i) - 1;
// //         cout << "xd" << i << "\n";
// //         while (tempPoint >= 0) {
// //             cout << " hi";
// //             //check is the row of the check; i is row of curr.
// //             //max is the maximum gift of the checker row
// //             int check = preference.at(i).at(tempPoint) - 1;
// //             int max = pointer.at(check); //2
// //             int max2 = pointer.at(i);
// //             // int sw = preference.at(i).at(pointer.at(i)) - 1;
// //             int max2val = preference.at(i).at(max2);
// //             int maxval = preference.at(check).at(max);
// //             int t = position.at(check).at(max2val -1);
// //             int t2 = position.at(i).at(maxval - 1);

// //             // int sw = preference.at(i).at(tempPoint) - 1;
// //             // int last = position.at(check).at(sw);
// //             // int max2 = pointer.at(i);
// //             // int sw2 = preference.at(i).at(max2) - 1;
// //             // int last2 = position.at(i).at(sw2);
// //             // cout << check << " " << max << " " << sw << " " << last << "\n";
// //             // cout << "hiiii"<<  last << " " << max << " " << last2 << " "<< max2 << "\n";
// //             if (t < max && t2 < max2) {
// //                 cout << "hiiii"<<  t << " " << max << " " << t2 << " "<< max2 << "\n";
// //                 pointer.at(i) = t;
// //                 pointer.at(check) = t2;
// //             }
// //             tempPoint--;
// //         }
// //     }
// //     for (int i = 0; i < n; i++) {
// //         int pr = preference.at(i).at(pointer.at(i));
// //         printf("%d", &pr);
// //         if (i != n - 1) {
// //             printf("\n");
// //         }
// //     }

// // }