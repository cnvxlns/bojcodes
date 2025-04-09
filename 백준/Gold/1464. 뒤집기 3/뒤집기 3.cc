#include<bits/stdc++.h>

#define Size 130
#define inf 0x3f3f3f3f
#define endl "\n"
#define sp " "
#define int int64_t
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define rep(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)

const int MOD = 1e9 + 7;

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;
using pci = pair<char, int>;
using tiii = tuple<int, int, int>;
using vpii = vector<pii>;
using vtiii = vector<tiii>;

//1'000'000'000'000'000'000

void Solve(int t___){
    string s;
    cin >> s;
    deque<char> ans;
    for(const auto &i: s){
        
        if(ans.empty() || ans.back() < i){
            ans.push_front(i);
        }else{
            ans.push_back(i);
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto i: ans){
        cout << i;
    }
    cout << endl;
}


int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    rep(i, 1, t){
        Solve(i);
    }
    return 0;
}