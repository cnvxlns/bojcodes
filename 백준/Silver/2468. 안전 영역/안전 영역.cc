#include<bits/stdc++.h>

#define Size 200
#define inf 0x3f3f3f3f
#define endl "\n"
#define sp " "
#define int int64_t
#define loop(M) for(int _ = 0; _ < M; ++_)

const int MOD = 1e9 + 7;

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

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

int N;
int a[Size][Size];

void DFS(vector<vi> &visited, int k, int i, int j){
    if(i < 0 || i >= N || j < 0 || j >= N){
        return;
    }
    if(visited[i][j]){
        return;
    }
    if(a[i][j] <= k){
        return;
    }else{
        visited[i][j] = 1;
        DFS(visited, k, i + 1, j);
        DFS(visited, k, i, j + 1);
        DFS(visited, k, i - 1, j);
        DFS(visited, k, i, j - 1);
    }
}

void Solve(){
    cin >> N;
    int M = -inf;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin >> a[i][j];
        }
    }
    for(int k = 0; k <= 100; ++k){
        vector<vi> visited(N, vi(N, 0));
        int ans = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(a[i][j] > k && !visited[i][j]){
                    DFS(visited, k, i, j);
                    ans++;
                }
            }
        }
        M = max(M, ans);
    }
    cout << M << endl;
}
