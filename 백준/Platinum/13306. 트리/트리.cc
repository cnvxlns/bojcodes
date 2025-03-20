#include<bits/stdc++.h>

#define Size 130
#define inf 0x3f3f3f3f
#define endl "\n"
#define sp " "
#define int int64_t
#define loop(M) for(int _ = 0; _ < M; ++_)

const int MOD = 1e9 + 7;

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

void Solve();

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    loop(t){
        Solve();
    }
    return 0;
}

vector<int> parent;

int Find(int a){
    if(a == parent[a]){ 
        return a;
    }else{
        return parent[a] = Find(parent[a]);
    }
}

void Union(int a, int b){
    a = Find(a), b = Find(b);
    if(a == b){
        return;
    }else if(a < b){
        parent[b] = a; 
    }else{
        parent[a] = b;
    }
}

void Solve(){
    int N, Q;
    cin >> N >> Q;
    vi p(N + 1);
    parent.resize(N + 1);
    for(int i = 1; i <= N; ++i){
        parent[i] = i;
    }
    for(int i = 2; i <= N; ++i){
        cin >> p[i];
    }
    stack<tiii> query;
    loop(Q + N - 1){
        int q;
        cin >> q;
        if(q == 0){
            int a;
            cin >> a;
            query.push({q, a, 0});
        }
        if(q == 1){
            int a, b;
            cin >> a >> b;
            query.push({q, a, b});
        }
    }
    stack<string> ans;
    while(!query.empty()){
        tiii cur = query.top();
        query.pop();
        if(get<0>(cur) == 0){
            Union(get<1>(cur), p[get<1>(cur)]);
        }
        if(get<0>(cur) == 1){
            if(Find(get<1>(cur)) == Find(get<2>(cur))){
                ans.push("YES\n");
            }else{
                ans.push("NO\n");
            }
        }
    }
    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
}