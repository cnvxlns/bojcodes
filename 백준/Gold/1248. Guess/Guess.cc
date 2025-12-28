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

int N;
vector<vector<char>> a;

vi ans;

bool validity(int idx){
    int sum = 0;
    for (int i = idx; i >= 1; --i) {
        sum += ans[i];
        if (a[i][idx] == '+' && sum <= 0) return false;
        if (a[i][idx] == '-' && sum >= 0) return false;
        if (a[i][idx] == '0' && sum != 0) return false;
    }
    return true;
}

bool dfs(int idx){
    if(idx == N + 1){
        return true;
    }
    if(a[idx][idx] == '0'){
        ans[idx] = 0;
        if(validity(idx)){
            if(dfs(idx + 1)){
                return true;
            }
        }
        
    }else{
        int sign = a[idx][idx] == '+' ? 1 : -1;
        for(auto val = 1; val <= 10; ++val){
            ans[idx] = val * sign;
            if(validity(idx)){
                if(dfs(idx + 1)){
                    return true;
                } 
            }
        }
    }
    return false;
}

void Solve(){
    cin >> N;
    a.assign(N + 1, vector<char>(N + 1));
    ans.assign(N + 1, 0);
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            a[i][j] = s[cnt++];
        }
    }
    dfs(1);
    for(auto i = 1; i <= N; ++i){
        cout << ans[i] << sp;
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