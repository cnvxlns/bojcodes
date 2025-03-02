#include<iostream>
#include<vector>

using namespace std;

int N;

vector<int> parent(300100);

int Find(int a){
    if(a == parent[a]){
        return a;
    }else{
        return Find(parent[a]);
    }
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a == b){
        return ;
    }else{
        if(a < b){
            parent[b] = a;
        }else{
            parent[a] = b;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; ++i){
        parent[i] = i;
    }
    for(int i = 1; i <= N - 2; ++i){
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    int prevparent = parent[1];
    for(int i = 2; i <= N; ++i){
        if(prevparent != Find(i)){
            cout << prevparent << " " <<  parent[i] << "\n";
            break;
        }
    }
    return 0;
}