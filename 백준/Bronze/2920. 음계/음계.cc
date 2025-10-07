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
    vi a(8);
    for(auto &i :a){
        cin >> i;
    }
    bool as = true, des = true;
    for(auto i = 1; i <= 8; ++i){
        if(i != a[i - 1]){
            as = false;
            break;
        }
    }
    for(auto i = 1; i <= 8; ++i){
        if(9 - i != a[i - 1]){
            des = false;
            break;
        }
    }
    if(as){
        cout << "ascending" << endl;
    }else if(des){
        cout << "descending" << endl;
    }else{
        cout << "mixed" << endl;
    }
}

int32_t main() {
    //cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}