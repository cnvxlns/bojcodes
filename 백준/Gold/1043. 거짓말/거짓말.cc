#include <bits/stdc++.h>

#define Size 3001020
#define inf 0x3f3f3f3f
#define endl "\n"
#define sp " "
#define loop(M) for(int _ = 0; _ < M; ++_)

using namespace std;

using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
using tiii = tuple<ll, ll, ll>;

const vector<pii> dij = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

vi parent(Size);

int Find(int x) {
    if(parent[x] != x) {
        parent[x] = Find(parent[x]);
    }
    return parent[x];
}

void Union(int a, int b) {
    int rootA = Find(a);
    int rootB = Find(b);
    if(rootA != rootB) {
        parent[rootB] = rootA;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) {
        parent[i] = i;
    }
    int T;
    cin >> T;
    vi truth(T);
    for(auto &i: truth) {
        cin >> i;
    }
    vector<vi> p(M);
    for(int i = 0; i < M; ++i) {
        int partySize;
        cin >> partySize;
        for (int j = 0; j < partySize; ++j) {
            int tmp;
            cin >> tmp;
            p[i].push_back(tmp);
        }
        for (int j = 1; j < partySize; ++j) {
            Union(p[i][0], p[i][j]);
        }
    }
    set<int> S;
    for(auto i : truth) {
        S.insert(Find(i));
    }
    int ans = 0;
    for (const auto& party : p) {
        bool canLie = 1;
        for(auto i: party) {
            if(S.count(Find(i)) > 0) {
                canLie = false;
                break;
            }
        }
        if(canLie) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
