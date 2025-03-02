#include<bits/stdc++.h>

using namespace std;

const int inf = 0x7f7f7f7f;

typedef pair<int, int> pii;

vector<pii> a(10023);
priority_queue<pii> pq;

int N, M;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> N >> M;
    k = N % (2 * M);
    if(k == 0) k = N;

    for(int i = 1; i <= M; ++i){
        cin >> a[i].first >> a[i].second;
        pq.push({-a[i].first, i});
        pq.push({-a[i].second, i});
    }
    while(--k){
        pq.pop();
        //cout << pq.top().first << " " <<pq.top().second << "\n";
    }
    cout << pq.top().second;
    
    return 0;
}