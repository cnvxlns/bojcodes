#include<bits/stdc++.h>

#define Size 20020
#define inf 0x3f3f3f3f
#define endl "\n"

#define loop(M) for(int _ = 0; _ < M; ++_)

using namespace std;

using ll = long long;
using vi = vector<ll>;
using vc = vector<char>;
using pii = pair<ll, ll>;
using tiii = tuple<ll, ll, ll>;
using pqi = priority_queue<ll>;

const vector<pii> dij = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void Solve();

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    Solve();
    return 0;
}

ll N;

void Solve(){
    cin >> N;
    vi a(N);
    stack<ll> stk;
    vi NGE(N);
    for(auto &i: a){
        cin >> i;
    }
    for(auto i = N - 1; i >= 0; --i){
        while(!stk.empty() && stk.top() <= a[i]){
            stk.pop();
        }
        if(stk.empty()){
            NGE[i] = -1;
        }else{
            NGE[i] = stk.top();
        }
        stk.push(a[i]);
    }
    for(auto i: NGE){
        cout << i << " ";
    }
}
