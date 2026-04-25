#include<bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using vpii = vector<pii>;

const int inf = 4e18;
const int MOD = 1e9 + 7;

vpii drc = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

pii operator+(pii A, pii B){
    return {A.first + B.first, A.second + B.second};
}
pii operator-(pii A, pii B){
    return {A.first - B.first, A.second - B.second};
}

void init(){
   
}

vector<vector<int>> G;
vector<int> visited;
int a, b;
int flag = false;

void dfs(int cur, int depth){
    if(cur == b){
        cout << depth << endl;
        flag = true;
        return ;
    }
    for(const auto &next: G[cur]){
        if(visited[next] == true){
            continue;
        }
        visited[next] = true;
        dfs(next, depth + 1);
    }
}   

void solve(){
    int N;
    int m;
    cin >> N;
    cin >> a >> b;
    cin >> m;

    G.resize(N + 1);
    visited.resize(N + 1);

    while(m--){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(a, 0);
    if(flag == false){
        cout << -1 << endl;
    }
}

int cnt;

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    init();
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
