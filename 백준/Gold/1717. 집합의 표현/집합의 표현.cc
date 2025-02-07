#include<iostream>
#include<vector>

using namespace std;

int N, M;

vector<int> parent(1000100);

int Find(int a){
    if(a == parent[a]){
        return a;
    }else{
        return parent[a] = Find(parent[a]);
    }
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a < b){
        parent[b] = a;
    }else{
        parent[a] = b;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        parent[i] = i;
    }
    while(M--){
        int q, a, b;
        cin >> q >> a >> b;
        if(q){
            if(Find(a) == Find(b)){
                cout << "yes" << "\n";
            }else{
                cout << "no" << "\n";
            }
        }else{ 
            Union(a, b);
        }
    }
    return 0;
}