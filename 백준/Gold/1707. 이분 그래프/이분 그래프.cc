#include<bits/stdc++.h>

using namespace std;

int K;
int V, E;
int flag;
 
void dfs(vector<vector<int>>& G, vector<int>& visited, int cur, int val){
    //cout << cur << "\n";
    
    if(visited[cur] == val){
        //cout << "!!!!" << "\n";
        return ;
    }
    if(visited[cur] == -val){
        //cout << "!!!!" << "\n";
        flag = 1;
        return ;
    }
    visited[cur] = val;
    for(auto i: G[cur]){
        dfs(G, visited, i, -val);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> K;
    while(K--){
        vector<vector<int>> G(20020);
        vector<int> visited(20020);
        cin >> V >> E;
        for(int i = 0; i < E; ++i){
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i = 1; i <= V; ++i){
            if(!visited[i])
                dfs(G, visited, i, 1);
        }
        if(flag){
            cout << "NO" << "\n";
            flag = 0;
        }else{
            cout << "YES" << "\n";
        }
    }
    return 0;
}