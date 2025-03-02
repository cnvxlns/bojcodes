#include<iostream>
#include<vector>

using namespace std;

typedef long long llint;

int N, M, K;
int base;

const int S = 1000004;

vector<llint> tree(S * 4);

void update(llint idx, llint val){
    idx += base - 1;
    tree[idx] = val;
    while(idx > 1){
        if(idx % 2){
            tree[idx / 2] = tree[idx - 1] + tree[idx];
        }else{
            tree[idx / 2] = tree[idx] + tree[idx + 1];
        }
        idx /= 2;
    }
}

llint query(llint left, llint right){
    left += base - 1;
    right += base - 1;
    llint ret = 0; 
    while(left <= right){
        if(left % 2){
            ret += tree[left];
            ++left;
        }
        if(right % 2 == 0){
            ret += tree[right];
            --right;
        }
        left /= 2;
        right /= 2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for(base = 1; base < N; base *= 2);
    for(int i = 0; i < N; ++i){
        cin >> tree[i + base];
    }
    for(int i = base - 1; i >= 1; --i){
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    int Q = M + K;
    while(Q--){
        llint a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            update(b, c);            
        }else{
            cout << query(b, c) << "\n";
        }   
    }
    return 0;
}