#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define inf 0x7f7f7f7f

int N, p;
int flag;
vector<int> b(5 * 1e5 + 123);

int minb(int p, int n){
    if(p == 1){
        return n;
    }
    return (n - 1) / p + 1;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> p;
    int t = N / p;
    if(N % p){
        t++;
    }
    for(int i = 1; i <= N; ++i){
        cin >> b[i];
        if(b[i] - b[i - 1] >= 2 || b[i] < b[i - 1]){
            flag = 1;
        }
        if(minb(p, i) <= b[i] && b[i] <= t){

        }else{
            flag = 1;
        }
    }
    if (b[N] != t || b[1] != 1){
        flag = 1;
    }
    if(flag){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}