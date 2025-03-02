#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> T(10010);

int n;

pii dfs(int cur, int prev){
    pii ret = {cur, 0};
    for(auto i: T[cur]){
        if(i.first != prev){
            pii d = dfs(i.first, cur);
            int newdist = i.second + d.second;
            int newnode = d.first;
            if(ret.second < newdist){
                ret = {newnode, newdist};
            }
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        T[a].push_back({b, w});
        T[b].push_back({a, w});
    }
    int deepnode = dfs(1, 0).first;
    cout << dfs(deepnode, 0).second;
    return 0;
}