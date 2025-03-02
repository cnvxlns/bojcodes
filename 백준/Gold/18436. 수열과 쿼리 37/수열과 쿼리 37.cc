#include<iostream>
#include<vector>
#include<utility>

using namespace std;

typedef pair<int, int> pii;

const int S = 100100;

vector<pii> tree(S * 4); //{홀, 짝}

int N, M;
int base;

void update(int idx, int val){
    idx += base - 1;
    if(val % 2){
        tree[idx] = {1, 0};
    }else{
        tree[idx] = {0, 1};
    }
    while(idx > 0){
        if(idx % 2){
            tree[idx / 2] = {tree[idx].first + tree[idx - 1].first, tree[idx].second + tree[idx - 1].second};
        }else{
            tree[idx / 2] = {tree[idx].first + tree[idx + 1].first, tree[idx].second + tree[idx + 1].second};
        }
        idx /= 2;
    }
}

int query(int q, int l, int r){
    l += base - 1;
    r += base - 1;
    int ans = 0;
    while(l <= r){
        if(l % 2 == 1){
            if(q == 2){
                ans += tree[l].second;
            }else{
                ans += tree[l].first;
            }
            l++;
        }
        if(r % 2 == 0){
            if(q == 2){
                ans += tree[r].second;
            }else{
                ans += tree[r].first;
            }
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return ans;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(base = 1; base < N; base *= 2);
    for(int i = 0; i < N; ++i){
        int tmp;
        cin >> tmp;
        if(tmp % 2){
            tree[i + base] = {1, 0};
        }else{
            tree[i + base] = {0, 1};
        }
    }
    for(int i = base - 1; i > 0; --i){
        tree[i] = {tree[i * 2].first + tree[i * 2 + 1].first, tree[i * 2].second + tree[i * 2 + 1].second};
    }
    cin >> M;
    while(M--){
        int q, a, b;
        cin >> q >> a >> b;
        if(q == 1){
            update(a, b);
        }else{
            cout << query(q, a, b) << "\n";
        }
    }



    return 0;
}