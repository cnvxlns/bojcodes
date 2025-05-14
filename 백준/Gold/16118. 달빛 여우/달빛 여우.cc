#include<bits/stdc++.h>

#define Size 200032
#define inf 0x3f3f3f3f
#define endl "\n"
#define sp " "
#define int int64_t
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define rep(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)

const int MOD = 1e9 + 7;

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using vtiii = vector<tiii>;
using pic = pair<int, char>;
using pci = pair<char, int>;
using vpii = vector<pii>;
using vpic = vector<pic>;
using vpci = vector<pci>;
using vvpii = vector<vpii>;

pii operator+(const pii& a, const pii& b) {
    return {a.first + b.first, a.second + b.second};
}
pii operator-(const pii& a, const pii& b) {
    return {a.first - b.first, a.second - b.second};
}

pii dxy[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<vector<pair<double, int>>> G;

void dijkstra(vi &dist, int V, int K){
    fill(dist.begin(), dist.end(), inf);
    priority_queue<pii, vpii, greater<pii>> pq;
    dist[K] = 0;
    pq.push({0, K});
    while(!pq.empty()){
        auto [curdist, curnode] = pq.top();
        pq.pop();
        if(dist[curnode] < curdist){
            continue;
        }
        for(auto [nextdist, nextnode]: G[curnode]){
            auto newdist = curdist + nextdist;
            if(dist[nextnode] > newdist){
                dist[nextnode] = newdist;
                pq.push({newdist, nextnode});
            }
        }
    }
}

vector<double> dijkstra1(int V, int K){
    vector<double> dist(V + 1, inf);
    dist[K] = 0;
    priority_queue<pii, vpii, greater<pii>> pq;
    pq.push({0, K});
    while(!pq.empty()){
        auto [topdist, topnode] = pq.top(); pq.pop();
        if(dist[topnode] < topdist){
            continue;
        }
        for(const auto &[nextdist, nextnode]: G[topnode]){
            auto newdist = topdist + nextdist;
            if(dist[nextnode] > newdist){
                dist[nextnode] = newdist; 
                pq.push(make_pair(newdist, nextnode));
            }
        }
    }
    return dist;
}

vector<double> dijkstra2(int V, int K){
    vector<vector<double>> dist(V + 1, vector<double>(2, inf));
    dist[K][1] = 0;
    priority_queue<tuple<double, int, bool>, vector<tuple<double, int, bool>>, greater<>> pq;
    pq.push({0, K, true});
    while(!pq.empty()){
        auto [topdist, topnode, run] = pq.top(); pq.pop();
        int run_state = run ? 1 : 0;
        if(dist[topnode][run_state] < topdist){
            continue;
        }
        for(const auto &[nextdist, nextnode]: G[topnode]){
            double newdist = run ? (topdist + nextdist / 2.) : (topdist + nextdist * 2.);
            int next_run_state = !run ? 1 : 0;
            if(dist[nextnode][next_run_state] > newdist){
                dist[nextnode][next_run_state] = newdist;
                pq.push({newdist, nextnode, !run});
            }
        }
    }
    vector<double> result(V + 1);
    result[0] = inf;
    for(int i = 1; i <= V; ++i){
        result[i] = min(dist[i][0], dist[i][1]);
    }
    return result;
}


void Solve(int t___){
    int N, M;
    cin >> N >> M;
    G.resize(N + 1);
    REP(i, M){
        int a, b;
        double c;
        cin >> a >> b >> c;
        G[a].push_back({c, b});
        G[b].push_back({c, a});
    }
    int cnt = 0;
    auto dist1 = dijkstra1(N, 1);
    auto dist2 = dijkstra2(N, 1);
    rep(i, 1, N){
        if(dist1[i] < dist2[i]){
            cnt++;
        }
    }
    cout << cnt << endl;
}

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    rep(i, 1, t){
        Solve(i);
    }
    return 0;
}