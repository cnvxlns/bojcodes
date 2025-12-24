#include<bits/stdc++.h>

#define int long long
#define Size 200032
#define inf (int)4e18
#define endl "\n"
#define sp " "


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

bool generatable(const vector<bool> &broken, int channel){
    if(channel == 0){
        return !broken[0];
    }
    while(channel > 0){
        //cout << channel % 10 << endl;
        if(broken[channel % 10]){
            return false;
        }
        channel /= 10;
    }
    return true;
}

int cntdigits(int num){
    int cnt = 0;
    if(num == 0){
        return 1;
    }
    while(num > 0){
        cnt++;
        num /= 10;
    }
    return cnt;
}

void Solve(){
    int ch;
    int N;
    cin >> ch >> N;
    vector<bool> broken(10);
    for(auto i = 0; i < N; ++i){
        int tmp;
        cin >> tmp;
        broken[tmp] = true;
    }
    int ans = abs(ch - 100);
    for (int i = 0; i <= 1000000; i++) {
        if(generatable(broken, i)){
            ans = min(ans, cntdigits(i) + abs(ch - i));
        }
    }
    cout << ans << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}