#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

using ll = long long;

int n;
ll ans = 0;
vector<pair<int, int>> cows;

/** returns the maximum area saved by testing splits along cows[i].first */
ll search() {
	sort(cows.begin(), cows.end());

	vector<pair<int, int>> pref(n), suf(n);

	// returns updated min/maxs when considering a new coordinate
	auto upd = [](pair<int, int> a, int b) -> pair<int, int> {
		return {min(a.first, b), max(a.second, b)};
	};

	// compute prefix/suffix minimums and maximums
	pref[0] = {cows[0].second, cows[0].second};
	for (int i = 1; i < n; ++i) { pref[i] = upd(pref[i - 1], cows[i].second); }

	suf[n - 1] = {cows[n - 1].second, cows[n - 1].second};
	for (int i = n - 2; i >= 0; i--) {
		suf[i] = upd(suf[i + 1], cows[i].second);
	}

	// initial area with one enclosure
	ll area = (ll)(cows.back().first - cows.front().first) *
	          (pref.back().second - pref.back().first);

	ll best = LLONG_MAX;
	for (int i = 0; i < n - 1; i++) {
		// if it's possible to split
		if (cows[i].first != cows[i + 1].first) {
			ll first_rect = (ll)(cows[i].first - cows[0].first) *
			                (pref[i].second - pref[i].first);
			ll second_rect = (ll)(cows.back().first - cows[i + 1].first) *
			                 (suf[i + 1].second - suf[i + 1].first);

			best = min(best, first_rect + second_rect);
		}
	}

	return area - best;
}

int main() {
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);

	cin >> n;
	cows.resize(n);

	for (pair<int, int> &cow : cows) { cin >> cow.first >> cow.second; }

	// try all splits on x axis
	ans = max(ans, search());

	for (pair<int, int> &cow : cows) { swap(cow.first, cow.second); }

	// try all splits on y axis
	ans = max(ans, search());

	cout << ans << endl;
}
//Right idea with computing veritcal and horizontal rectangles. if 0, answer is 0.
// #include <fstream>
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// using namespace std;
// int computeLoss(int area1, int area2, int total) {
//     return (total - (area1 + area2));
// }
// int computeArea(int var1, int var2, int constant) {
//     int temp = abs(var2 - var1);
//     return constant * temp;
// }
// pair<pair<int, int>, pair<int, int>> largestCowGap(vector<pair<int, int>> locations, int which) {
//     int maxGap = INT_MIN;
//     int firstLoc, secondLoc, firstInd, secondInd;
//     // zero for vertical (second), one for horizontal (first)
//     if (which == 0) {
//         for (int i = 0; i < locations.size() - 1; i++) {
//             int tempSize = locations.at(i + 1).second - locations.at(i).second; 
//             if (tempSize > maxGap) {
//                 maxGap = tempSize;
//                 firstInd = i;
//                 secondInd = i + 1;
//                 firstLoc = locations.at(i).second;
//                 secondLoc = locations.at(i + 1).second;
//             }
//         }
//     } else {
//         for (int i = 0; i < locations.size() - 1; i++) {
//             int tempSize = locations.at(i + 1).first - locations.at(i).first; 
//             if (tempSize > maxGap) {
//                 maxGap = tempSize;
//                 firstInd = i;
//                 secondInd = i + 1;
//                 firstLoc = locations.at(i).first;
//                 secondLoc = locations.at(i + 1).first;
//             }
//         }
//     }
//     pair<pair<int, int>, pair<int, int>> ret;
//     ret.first = make_pair(firstInd, secondInd);
//     ret.second = make_pair(firstLoc, secondLoc);
//     return ret;
// }

// int main() {
//     ifstream fin("split.in");
//     ofstream fout("split.out");
//     int n;
//     vector<pair<int, int>> locations;
//     fin >> n;
//     int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
//     for (int i = 0; i < n; i++) {
//         int temp1, temp2;
//         fin >> temp1 >> temp2;
//         locations.push_back(make_pair(temp1, temp2));
//         if (temp1 >= maxX) {
//             maxX = temp1;
//         }
//         if (temp1 < minX) {
//             minX = temp1;
//         }
//         if (temp2 >= maxY) {
//             maxY = temp2;
//         }
//         if (temp2 < minY) {
//             minY = temp2;
//         }
//     }
//     int width = abs(maxX - minX);
//     int height = abs(maxY - minY);
//     int total = width * height;

//     vector<int> verticals;
//     vector<int> horizontals;
//     //Find verticals
//     for (int i = minX; i <= maxX; i++) {
//         bool cowPresent = false;
//         for (int j = 0; j < n; j++) {
//             if (locations.at(j).first == i) {
//                 cowPresent = true;
//                 break;
//             }
//         }
//         if (!cowPresent) {
//             verticals.push_back(i);
//         }
//     }
//     for (int i = minY; i <= maxY; i++) {
//         bool cowPresent = false;
//         for (int j = 0; i < n; j++) {
//             if (locations.at(j).first == i) {
//                 cowPresent = true;
//                 break;
//             }
//         }
//         if (!cowPresent) {
//             horizontals.push_back(i);
//         }
//     }
//     vector<pair<int, int>> v; //aggregate rectangles
//     vector<pair<int, int>> h;
//     for (int i = 0; i < verticals.size() - 1; i++) {
//         int tempx2 = verticals.at(i);
//         while (verticals.at(i) + 1 == verticals.at(i + 1)) {
//             tempx2 = verticals.at(i + 1);
//         }
//         v.push_back(make_pair(verticals.at(i), tempx2));
//     }
//     //Find horizontals

//     for (int i = 0; i < horizontals.size(); i++) {
//         int tempy2 = horizontals.at(i);
//         while (horizontals.at(i) + 1 == horizontals.at(i)) {
//             tempy2 = horizontals.at(i + 1);
//         }
//         h.push_back(make_pair(i, tempy2));
//     }

//     if (v.size() == 0 && h.size() == 0) {
//         fout << 0;
//     } else {
//         vector<int> areaV;
//         vector<int> areaH;
//         int maxV = INT_MIN, maxH = INT_MIN;
//         int indV = 0, indH = 0;
//         for (int i = 0; i < h.size(); i++) {
//             int size = computeArea(h.at(i).first, h.at(i).second, width);
//             if (size > maxH) {
//                 maxH = size;
//                 indH = i;
//             }
//             areaH.push_back(size);
//         } 
//         for (int i = 0; i < v.size(); i++) {
//             int size = computeArea(v.at(i).first, v.at(i).second, height);
//             if (size > maxV) {
//                 maxV = size;
//                 indV = i;
//             }
//             areaV.push_back(size);
//         }
//         //0 for vertical, 1 for horizontal, 2 for equal
//         int big;
//         if (maxV > maxH) {
//             big = 0;
//         } else if (maxH > maxV) {
//             big = 1;
//         } else {
//             big = 2;
//         }
//         //Compute gaps between the "blanks without cows"
//         if (big == 1) {
//             sort(locations.begin(), locations.end(), [](const pair<int, int>& a, const pair<int, int> & b) {
//                 return (a.first < b.first);
//             });
//             pair<pair<int, int>, pair<int, int>> bigGap = largestCowGap(locations, 1);
//             for (int i = 0; i < areaH.size(); i++) {
//                 if (h.at(i) )
//             }

//         }
        
//     }
// }

