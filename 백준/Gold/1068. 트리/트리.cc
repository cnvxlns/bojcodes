#include<bits/stdc++.h>

#define Size 300
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

int N, R;
int ans;

int dfs(vector<vi> &Tree, ll x){
    if(x == R){
        return -1;
    }
    if(Tree[x].size() == 0){
        ans++;
        return 0;
    }
    for(auto i: Tree[x]){
        int tmp = dfs(Tree, i);
        if(tmp == -1 && Tree[x].size() == 1){
            ans++;
        }
    }
    return 0;
}

void Solve(){
    int root = 0;
    cin >> N;
    vector<vi> Tree(N);
    for(int i = 0; i < N; ++i){
        int x;
        cin >> x;
        if(x != -1){
            Tree[x].push_back(i);
        }else{
            root = i;
        }
    }
    cin >> R;
    dfs(Tree, root);
    cout << ans << endl;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    Solve();
    return 0;
}