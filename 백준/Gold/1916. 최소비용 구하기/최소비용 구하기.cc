#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<functional>

#define inf 0x7f7f7f7f

using namespace std;

typedef pair<int, int> pii;

int N, M;

vector<vector<pii>> G(1004);
vector<int> dist(1004);

void dijkstra(int start){
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        int curdist, curnode;
        curdist = pq.top().first;
        curnode = pq.top().second;
        pq.pop();
        if(dist[curnode] < curdist){
            continue;
        }
        for(auto i: G[curnode]){
            int newdist = i.first + dist[curnode];
            int newnode = i.second;
            if(newdist < dist[newnode]){
                dist[newnode] = newdist;
                pq.push({newdist, newnode});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> M;
    for(int i = 1; i <= N; ++i){
        dist[i] = inf;
    }
    for(int i = 0; i < M; ++i){
        int dep, des, dis;
        cin >> dep >> des >> dis;
        G[dep].push_back({dis, des});
    }
    int start, end;
    cin >> start >> end;
    dijkstra(start);
    cout << dist[end] << "\n";
    return 0;
}