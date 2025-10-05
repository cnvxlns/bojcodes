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

int ccw(pii p1, pii p2, pii p3) {
    int s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    if(s > 0) 
        return 1;
    else if(s == 0)
        return 0;
    else
        return -1; 
}

void Solve() {
    vpii p(4);
    for(auto &[x, y]: p){
        cin >> x >> y;
    }
    int p0p1 = ccw(p[0], p[1], p[2]) * ccw(p[0], p[1], p[3]);
    int p2p3 = ccw(p[2], p[3], p[0]) * ccw(p[2], p[3], p[1]);

    if(p0p1 == 0 && p2p3 == 0){
        if(p[0] > p[1]){
            swap(p[0], p[1]);
        }
        if(p[2] > p[3]){
            swap(p[2], p[3]);
        }
        cout << (int)((p[2] <= p[1]) && (p[0] <= p[3])) << endl;
    }else{
        cout << (int)((p0p1 <= 0) && (p2p3 <= 0) )<< endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}