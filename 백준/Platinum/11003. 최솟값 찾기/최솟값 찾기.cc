    #include<iostream>
    #include<vector>

    using namespace std;

    int N, L;
    int base;

    #define S 10000400
    #define inf 0x7f7f7f7f

    vector<int> tree(S * 4);

    int min(int a, int b){
        if(a < b){
            return a;
        }else{
            return b;
        }
    }

    int query(int l, int r){
        l += base - 1;
        r += base - 1;
        int ans = inf;
        while(l <= r){
            if(l % 2 == 1){
                ans = min(ans, tree[l]);
                l++;
            }
            if(r % 2 == 0){
                ans = min(ans, tree[r]);
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
        cin >> N >> L;
        for(base = 1; base < N + L; base *= 2);
        for(int i = base; i < base * 2; ++i){
            tree[i] = inf;
        }
        for(int i = L - 1; i < N + L; ++i){
            cin >> tree[i + base];
        }
        for(int i = base - 1; i > 0; --i){
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        }
        for(int i = 1; i <= N; ++i){
            cout << query(i, i + L - 1) << " ";
        }

        return 0;
    }