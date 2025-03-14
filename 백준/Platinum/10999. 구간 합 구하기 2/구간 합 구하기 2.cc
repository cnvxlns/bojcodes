#include<bits/stdc++.h>

#define Size 10020
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
    // cin >> t;
    loop(t){
        Solve();
    }
    return 0;
}

int N, M, K;
vi tree;
vi lazy;
int base;

void init(){
    for(base = 1; base < N; base *= 2);
    tree.assign(base * 2 + 1, 0);
    lazy.assign(base * 2 + 1, 0);
    for(int i = 0; i < N; ++i){
        cin >> tree[i + base];
    }
    for(int i = base - 1; i >= 1; --i){
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
}

void propagate(int node, int start, int end){
    if(lazy[node] == 0){
        return ;
    }
    tree[node] += (end - start + 1) * lazy[node];
    if(start != end){
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int start, int end, int left, int right, int val){
    propagate(node, start, end);
    if(left > end || right < start){
        return ;
    }
    if(left <= start && end <= right){
        lazy[node] += val;
        propagate(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, val);
    update(node * 2 + 1, mid + 1, end, left, right, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int partSum(int node, int start, int end, int left, int right){
    propagate(node, start, end);
    if(right < start || end < left){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    int mid = (start + end) / 2;
    return partSum(node * 2, start, mid, left, right) + partSum(node * 2 + 1, mid + 1, end, left, right);
}

void Solve(){
    cin >> N >> M >> K;
    init();
    loop(M + K){
        int query;
        cin >> query;
        if(query == 1){
            int left, right, val;
            cin >> left >> right >> val;
            update(1, 0, base - 1, left - 1, right - 1, val);
        }
        if(query == 2){
            int left, right;
            cin >> left >> right;
            cout << partSum(1, 0, base - 1, left - 1, right - 1) << endl;
        }
    }
}