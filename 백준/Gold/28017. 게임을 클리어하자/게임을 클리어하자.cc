#include<iostream>
#include<vector>

using namespace std;

const int inf = 0x7f7f7f7f;

int N, M;

int a[505][505];
int cache[505][505];

int dp(int idx, int prev){
    if(idx == N + 1){
        return 0;
    }
    int& r = cache[idx][prev];
    if(r){
        return r;
    }
    int ret = inf;
    for(int i = 1; i <= M; ++i){
        if(i == prev){
            continue;
        }
        ret = min(ret, dp(idx + 1, i) + a[idx][i]);
    }
    return cache[idx][prev] = ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> a[i][j];
        }
    }
    printf("%d", dp(1, 0));

    return 0;
}