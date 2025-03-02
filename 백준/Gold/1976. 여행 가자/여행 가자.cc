#include<iostream>
#include<vector>

using namespace std;

int N, M;

vector<int> parent(205), q(1050);

int Find(int x){
    if(x == parent[x]){
        return x;
    }else{
        int p = Find(parent[x]);
        parent[x] = p;
        return p;
    }
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x != y){
        parent[y] = x;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> M;
    for(int i = 1; i <= N; ++i){
        parent[i] = i;
    }
    for(int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            int is_linked;
            cin >> is_linked;
            if(is_linked){
                Union(i, j);
            }
        }
    }
    for(int i = 1; i <= M; ++i){
        cin >> q[i];
    }
    for(int i = 1; i < M; ++i){
        if(Find(q[i]) != Find(q[i + 1])){
            cout << "NO" << "\n";
            return 0;
        }
    }
    cout << "YES" << "\n";
    return 0;
}