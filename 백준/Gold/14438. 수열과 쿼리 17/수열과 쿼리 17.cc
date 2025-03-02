#include<iostream>
#include<vector>

using namespace std;

const int S = 100100;
const int inf = 0x7f7f7f7f;

typedef long long llint;

vector<int> tree(S * 4);

int N, M;
int base;

int min(int a, int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

void update(int idx, int val){
    idx += base - 1;
    tree[idx] = val;
    while(idx > 1){
        if(idx % 2){
            tree[idx / 2] = min(tree[idx], tree[idx - 1]);
        }else{
            tree[idx / 2] = min(tree[idx], tree[idx + 1]);
        }
        idx /= 2;
    }
}

int query(int l, int r){
    l += base - 1;
    r += base - 1;
    int ret = inf;
    while(l <= r){
        if(l % 2 == 1){
            ret = min(ret, tree[l]);
            l++;
        }
        if(r % 2 == 0){
            ret = min(ret, tree[r]);
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(base = 1; base < N; base *= 2);
    for(int i = base; i < base * 2; ++i){
        tree[i] = inf;
    }
    for(int i = 0; i < N; ++i){
        cin >> tree[base + i];
    }
    for(int i = base - 1; i > 0; --i){
        tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
    }
    cin >> M;
    while(M--){
        int q, a, b;
        cin >> q >> a >> b;
        if(q == 1){
            update(a, b);
        }
        if(q == 2){
            cout << query(a, b) << "\n";
        }
    }
    return 0;
}