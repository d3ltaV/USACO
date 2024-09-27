#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main() { //all numbers can be consecutive plus ones or plus twos
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int n;
        scanf("%d", &n);
        vector<int> vec;
        for (int i = 0; i < n; i++) {
            int temp;
            scanf("%d", temp);
            // vec.push_back(temp);
            vec[i] = temp;
        }
    }
}
