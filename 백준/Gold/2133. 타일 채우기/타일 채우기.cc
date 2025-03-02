#include<cstdio>
#include<vector>

using namespace std;

vector<long long int> cache(35);

int N;

long long int dp(int N){
    if(N < 0){
        return 0;
    }
    if(cache[N]){
        return cache[N];
    }
    if(N % 2){
        return 0;
    }
    long long int ret = dp(N - 2) * 3;
    for(int i = 2; i * 2 <= N; ++i){
        ret += dp(N - 2 * i) * 2;
    }
    return cache[N] = ret;
}

int main(){
    scanf("%d", &N);
    cache[0] = 1;
    cache[2] = 3;
    //cache[4] = 11;
    printf("%lld", dp(N));
    return 0;
}