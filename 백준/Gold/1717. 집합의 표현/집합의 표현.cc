#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int Find(int a, vector<int>& parent) {
    if (a == parent[a]) {
        return a;
    }
    else {
        return parent[a] = Find(parent[a], parent);
    }
}

void Union(int a, int b, vector<int>& parent) {
    a = Find(a, parent); b = Find(b, parent);
    if (a == b) return;
    else if (a < b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    iota(parent.begin(), parent.end(), 0);

    while(m--) {
        int cmd, a, b;
        cin >> cmd >> a >> b;

        if (cmd == 0) Union(a, b, parent);
        else if (cmd == 1) {
            if (Find(a, parent) == Find(b, parent)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}