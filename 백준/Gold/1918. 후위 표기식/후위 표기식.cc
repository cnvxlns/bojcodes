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


void Solve(int t){
    string s;
    cin >> s;
    stack<char> stk;
    for(const auto &i: s){
        if(i == '('){
            stk.push(i);
        }else if(i == ')'){
            while(!stk.empty()){
                if(stk.top() == '('){
                    stk.pop();
                    break;
                }else{
                    cout << stk.top();
                    stk.pop();
                }
            }
        }else if(i == '*' || i == '/'){
            if(stk.empty() || stk.top() == '('){
                stk.push(i);
            }else{
                while(!stk.empty()){
                    auto cur = stk.top();
                    if(cur == '+' || cur == '-'){
                        break;
                    }else{
                        cout << cur;
                        stk.pop();
                    }
                }
                stk.push(i);
            }
        }else if(i == '+' || i == '-'){
            while(!stk.empty()){
                auto cur = stk.top();
                if(cur != '('){
                    cout << cur;
                    stk.pop();
                }else{
                    break;
                }
            }
            stk.push(i);
        }else{
            cout << i;
        }
    }
    while(!stk.empty()){
        cout << stk.top();
        stk.pop();
    }
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

