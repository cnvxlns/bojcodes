#include<bits/stdc++.h>

using namespace std;

using vi = vector<int>;

int main(){
    vi a(9);
    for(auto &i: a){
        cin >> i;
    }
    
    for(auto i = 0; i < (1 << 9); ++i){
        int ans = 0;
        multiset<int> ms;
        if(__builtin_popcount(i) == 7){
            for(auto j = 0; j < 9; ++j){
                if(i & (1 << j)){
                    ans += a[j];
                    ms.insert(a[j]);
                }
            }
            if(ans == 100){
                for(auto i: ms){
                    cout << i << endl;
                }
                return 0;
            }
        }
    }
    return 0;
}