#include<iostream>

using namespace std;

typedef long long llint;

llint N, K;

const llint mod = 1e9 + 7;

llint power(llint n, llint k){
    if(k == 0){
        return 1;
    }
    if(k == 1){
        return n;
    }
    llint ret = power(n, k / 2) % mod;
    if(k % 2 == 1){
        return ((ret * ret) % mod * n) % mod;
    }else{
        return (ret * ret) % mod;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    llint under = 1;
    for(llint i = K; i >= 1; --i){
        under *= i;
        under %= mod;
    }
    under = power(under, mod - 2) % mod;
    llint upper = 1;
    llint d = N;
    for(llint i = 0; i < K; ++i){
        upper *= d;
        --d;
        upper %= mod;
    }
    cout << ((upper % mod) * (under % mod)) % mod;
    return 0;
}