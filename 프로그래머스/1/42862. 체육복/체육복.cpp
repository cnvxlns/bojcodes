#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> c(n + 1, 1);
    for (const auto &l : lost) {
        c[l]--;
    }
    for (const auto &r : reserve) {
        c[r]++;
    }
    for (int i = 1; i <= n; i++) {
        if (c[i] == 0) {
            if (i > 1 && c[i - 1] == 2) {
                c[i - 1]--;
                c[i]++;
            }
            else if (i < n && c[i + 1] == 2) {
                c[i + 1]--;
                c[i]++;
            }
        }
    }

    auto answer = count_if(c.begin(), c.end(), [=](int n){
        return n >= 1;
    });
    
    return answer - 1;
}