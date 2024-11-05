#include <bits/stdc++.h>

#define Size 100100
#define endl "\n"

using namespace std;

int N, M;
vector<vector<int>> G(Size);
vector<int> visited(Size);

int dfs(int curnode, int depth) {
    if (depth >= 5) {
        return 1;
    }
    visited[curnode] = 1;
    for (auto i : G[curnode]) {
        if (!visited[i]) {
            if (dfs(i, depth + 1)) {
                return 1;
            }
        }
    }
    visited[curnode] = 0;
    return 0;
}

void Solve() {
    int flag = 0;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < N; ++i) {
        fill(visited.begin(), visited.begin() + N, 0);
        if (dfs(i, 1)) {
            flag = 1;
            break;
        }
    }
    cout << flag << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    Solve();
    return 0;
}
