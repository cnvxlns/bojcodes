#include<bits/stdc++.h>

#define Size 200032
#define inf 4e18
#define endl "\n"
#define sp " "
#define int int64_t

const int MOD = 1e9 + 7;

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using pic = pair<int, char>;
using pci = pair<char, int>;
using vpii = vector<pii>;
using vpic = vector<pic>;
using vpci = vector<pci>;
using vtiii = vector<tiii>;

pii operator+(const pii& a, const pii& b) {
    return { a.first + b.first, a.second + b.second };
}
pii operator-(const pii& a, const pii& b) {
    return { a.first - b.first, a.second - b.second };
}

pii dxy[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int N;

void Solve() {
    cin >> N;
    vi a(N);
    for(auto &i: a){
        cin >> i;
    }
    sort(a.begin(), a.end());
    int sum;
    int ansval = inf;
    tiii ans;
    for(auto i = 0; i < N; ++i){
        int lo = i + 1, hi = N - 1;
        while(lo < hi){
            int sum = a[i] + a[lo] + a[hi];
            if(abs(sum) < ansval){
                ansval = abs(sum);
                ans = {i, lo, hi};
            }
            if(sum < 0){
                lo++;
            }else if(sum > 0){
                hi--;
            }else{
                cout << a[i] << sp << a[lo] << sp << a[hi] << endl;
                return ;
            }
        }
    }
    auto [i, j, k] = ans;
    cout << a[i] << sp << a[j] << sp << a[k] << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}