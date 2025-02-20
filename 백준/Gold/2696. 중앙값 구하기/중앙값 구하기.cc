#include<bits/stdc++.h>

#define Size 1024
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
    cin >> t;
    loop(t){
        Solve();
    }
    return 0;
}

void Solve(){
    int N;
    cin >> N;
    priority_queue<int> Mheap;
    priority_queue<int, vi, greater<int>> mheap;
    cout << N / 2 + 1 << endl;
    for(int i = 1; i <= N; ++i){
        int t;
        cin >> t;
        if(i == 1){
            Mheap.push(t);
        }else if(i == 2){
            if(t > Mheap.top()){
                mheap.push(t);
            }else{
                mheap.push(Mheap.top());
                Mheap.pop();
                Mheap.push(t);
            }
        }else{
            Mheap.push(t);
            if(mheap.top() < Mheap.top()){
                mheap.push(Mheap.top());
                Mheap.pop();
                if(mheap.size() > Mheap.size()){
                    Mheap.push(mheap.top());
                    mheap.pop();
                }
            }
            if(Mheap.size() - 1 > mheap.size()){
                mheap.push(Mheap.top());
                Mheap.pop();
            }
        }
        if(i % 2)
            cout << Mheap.top() << sp;
        if(i == N){
            cout << endl;
        }
    }
}