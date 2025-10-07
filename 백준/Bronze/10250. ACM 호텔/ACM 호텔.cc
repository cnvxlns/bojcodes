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

void Solve(){
    int H, W, n;
    scanf("%d%d%d", &H, &W, &n);
    printf("%d%02d\n",  (n - 1) % H + 1, (n - 1) / H + 1);
    
}

int32_t main() {
    //cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--)
        Solve();
    return 0;
}