#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

llint a, b, mod;

llint p(llint a, llint b){
    if(b == 0){
        return 1;
    }
    if(a <= 1){
        return 1;
    }
    llint ret = p(a, b / 2) % mod;
    ret *= ret;
    ret %= mod;
    if(b % 2){
        return (ret * a) % mod;
    }else{
        return ret;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> mod;
    //a %= mod;
    //b %= mod;
    cout << p(a, b) % mod;
    return 0;
}