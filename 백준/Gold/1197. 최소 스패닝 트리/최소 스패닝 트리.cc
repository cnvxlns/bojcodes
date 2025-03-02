#include<bits/stdc++.h>

#define Size 404
#define inf 0x3f3f3f3f
#define endl "\n"
#define sp " "

#define loop(M) for(int _ = 0; _ < M; ++_)

using namespace std;

using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
using tiii = tuple<ll, ll, ll>;

const vector<pii> dij = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void init(vi &parent, int v, int e){
    for(int i = 1; i <= v; ++i){
        parent[i] = i;
    }
}

ll find(vi &parent, int x){
    if(parent[x] == x){
        return x;
    }else{
        return parent[x] = find(parent, parent[x]);
    }
}

void unionset(vi &parent, int x, int y){
    x = find(parent, x), y = find(parent, y);
    if(x == y){
        return ;
    }else{
        if(x > y){
            parent[x] = y;
        }else{
            parent[y] = x;
        }
    }
}


void Solve(){
    ll V, E, ans = 0;
    cin >> V >> E;
    priority_queue<tiii, vector<tiii>, greater<tiii>> edges;
    vi parent(V + 1);
    init(parent, V, E);
    loop(E){
        int d, a, v;
        cin >> d >> a >> v;
        edges.push({v, a, d});
    }
    while(!edges.empty()){
        int val = get<0> (edges.top());
        int dpt = get<1> (edges.top());
        int arv = get<2> (edges.top());
        edges.pop();
        if(find(parent, dpt) == find(parent, arv)){
            continue;
        }else{
            unionset(parent, dpt, arv);
            ans += val;
        }
    }
    cout << ans << endl;
}



int main(){
    cin.tie(0)->sync_with_stdio(0);
    Solve();
    return 0;
}