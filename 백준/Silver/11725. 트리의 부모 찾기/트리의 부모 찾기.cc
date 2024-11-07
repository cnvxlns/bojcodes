#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
#define endl "\n";

const int Size = 101000;

#define loop(N) for(int _ = 0; _ <N; ++_)

int N;

void Solve();

vector<vi> G(Size);
vi visited(Size), parent(Size);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

void dfs(int curnode){
    //cout << curnode << endl;
    visited[curnode] = 1;
    int ret = 1;
    for(auto i: G[curnode]){
        if(visited[i]){
            continue;
        }
        parent[i] = curnode;
        dfs(i);
    }
}

void Solve(){
    cin >> N;
    loop(N - 1){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1);
    for(int i = 2; i <= N; ++i){
        cout << parent[i] << endl;
    }
}
