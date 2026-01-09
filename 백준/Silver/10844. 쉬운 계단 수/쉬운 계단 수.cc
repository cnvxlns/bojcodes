#include<cstdio>

using namespace std;

const int inf = 0x7f7f7f7f;
const int mod = 1000000000;

long long int cache[15][105];

long long int dp(int digit_num, int length){
    if (cache[digit_num][length]){
        return cache[digit_num][length];
    }
    if(digit_num == 0){
        return dp(1, length - 1);
    }
    if(digit_num == 9){
        return dp(8, length - 1);
    }
    if (length == 0){
        return 1;
    }
    cache[digit_num][length] = (dp(digit_num + 1, length - 1) % mod) + (dp(digit_num - 1, length - 1) % mod);
    return cache[digit_num][length] % mod;
}

int main(){
    int N;
    long long int ans = 0;
    ans = 0;
    scanf("%d", &N);
    for (int i = 1; i <= 9; ++i){
        cache[i][1] = 1;
    }
    for (int i = 1; i <= 9; ++i){
        ans += (dp(i, N)) % mod;
        ans %= mod;
    }
    printf("%lld\n", ans % mod);
    return 0;
}