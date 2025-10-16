#include<bits/stdc++.h>

#define int int64_t
#define Size 200032
#define inf 4000000000000000000LL 
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

void Solve() {
    string s;
    getline(cin, s, '\n');
    bool tag = false;
    stack<char> stk;
    for(auto i = 0; i < s.size(); ++i){
        if(s[i] == '<'){
            tag = true;
            while(!stk.empty()){
                cout << stk.top();
                stk.pop();
            }
        }
        if(tag){
            cout << s[i];
        }else if(s[i] != ' '){
            stk.push(s[i]);
        }else{
            while(!stk.empty()){
                cout << stk.top();
                stk.pop();
            }
            cout << sp;
        }
        if(s[i] == '>'){
            tag = false;
        }
    }
    while(!stk.empty()){
        cout << stk.top();
        stk.pop();
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