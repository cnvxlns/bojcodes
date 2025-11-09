#include<bits/stdc++.h>

#define int int64_t
#define Size 200032
#define inf (int)4e18
#define endl "\n"
#define sp " "

#define pcll(x) __builtin_popcountll(x)

const int MOD = 1e9 + 7;

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using pic = pair<int, char>;
using pci = pair<char, int>;
using vpii = vector<pii>;
using vpic = vector<pic>;
using vpci = vector<pci>;
using vtiii = vector<tiii>;

pii operator+(const pii& a, const pii& b) {
    return { a.first + b.first, a.second + b.second };
}
pii operator-(const pii& a, const pii& b) {
    return { a.first - b.first, a.second - b.second };
}

pii dxy[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int N, K;
int required;
vi words;
int ans;

void dfs(int idx, int cnt, int learned) {
    if (cnt == K - 5) {
        int partans= 0;
        for (int word_mask : words) {
            if ((word_mask & ~learned) == 0) {
                partans++;
            }
        }
        ans = max(ans, partans);
        return;
    }
    if (idx == 21) {
        return;
    }
    int i = 0;
    int tempidx = idx;
    while(true){
        if(!((required >> i) & 1)) {
            if(tempidx == 0) break;
            tempidx--;
        }
        i++;
    }

    dfs(idx + 1, cnt + 1, learned | (1 << i));
    dfs(idx + 1, cnt, learned);
}

void Solve(){
    cin >> N >> K;
    words.assign(N, 0);
    if(K < 5){
        cout << 0 << endl;
        return ;
    }
    if(K == 26){
        cout << N << endl;
        return ;
    }
    string s = "antatica";
    
    for(auto i: s){
        required |= (1 << (i - 'a'));
    }
    for(auto i = 0; i < N; ++i){
        string input;
        cin >> input;
        for(auto j: input){
            words[i] |= (1 << (j - 'a'));
        }
    }
    dfs(0, 0, required);
    cout << ans << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}