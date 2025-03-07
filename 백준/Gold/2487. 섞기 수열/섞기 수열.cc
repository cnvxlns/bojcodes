#include<bits/stdc++.h>

#define Size 20010
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
    //cin >> t;
    loop(t){
        Solve();
    }
    return 0;
}

vi parent(Size);

int find(int a){
    if(parent[a]==a){
        return a;
    }else{
        return parent[a] = find(parent[a]);
    }    
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b){
        return ;
    }else if(a < b){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
}

int gcd(int a, int b){
    if(a % b){
        return gcd(b, a % b);
    }else{
        return b;
    }
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

void Solve(){
    int N;
    cin >> N;
    vi arr(N + 1);
    for(int i = 1; i <= N; ++i){
        parent[i] = i;
    }
    for(int i = 1; i <= N; ++i){
        cin >> arr[i];
    }
    for(int i = 1; i <= N; ++i){
        Union(i, arr[i]);
    }
    vi freq(N + 1);
    fill(freq.begin(), freq.end(), 0);
    for(int i = 1; i <= N; ++i){
        freq[find(arr[i])]++;
    }
    int ans = 1ll;
    for(int i = 1; i <= N; ++i){
        if(freq[i] > 0){
            ans = lcm(ans, freq[i]);
        }
    }
    cout << ans << endl;
}