#include<cstdio>

using namespace std;

int cache[35][35];

int dp(int n, int m){
    int ret = 0;
    if(m < 1){
        return 0;
    }
    if(n == 1){
        return m;
    }
    if(n > m){
        return 0;
    }
    if(m == 1){
        return 1;
    }
    if(cache[n][m]){
        return cache[n][m];
    }
    
    for(int i = 1; i < m; ++i){
        ret += dp(n - 1, m - i);
    }
    return cache[n][m] = ret;
}

int main(){
    int T;
    scanf("%d", &T);
    cache[1][1] = 1;
    while(T--){
        int n, m;
        scanf("%d%d", &n,  &m);
        printf("%d\n", dp(n, m));
    }




    return 0;
}