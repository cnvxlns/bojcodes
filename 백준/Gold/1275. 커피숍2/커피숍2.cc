#include<iostream>
#include<vector>

using namespace std;

typedef long long llint;

const int S = 100100;
const int inf = 0x7f7f7f7f;

vector<llint> tree(4 * S);

int N, M;  
int base;

void update(int a, int b){
    a += base - 1;
    tree[a] = b;
    while(a > 1){
        if(a % 2 == 1){
            tree[a / 2] = tree[a] + tree[a - 1];
        }else{
            tree[a / 2] = tree[a] + tree[a + 1];
        }
        a /= 2;
    }
}

llint query(int l, int r){
    l += base - 1;
    r += base - 1;
    llint ans = 0;
    while(l <= r){
        if(l % 2){
            ans += tree[l];
            l++;
        }
        if(r % 2 == 0){
            ans += tree[r];
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
    cin >> N >> M;
    for(base = 1; base < N; base *= 2);

    for(int i = 0; i < N; ++i){
        cin >> tree[base + i];
    }
    for(int i = base - 1; i > 0; --i){
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    while(M--){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if(x > y){
            int tmp = x;
            x = y;
            y = tmp;
        }
        cout << query(x, y) << "\n";
        update(a, b);
    }
    return 0;
}