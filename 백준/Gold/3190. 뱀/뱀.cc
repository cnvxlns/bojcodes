#include<bits/stdc++.h>

#define Size 130
#define inf 0x3f3f3f3f
#define endl "\n"
#define sp " "
#define int int64_t
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define rep(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)

const int MOD = 1e9 + 7;

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;
using pic = pair<int, char>;
using pci = pair<char, int>;
using tiii = tuple<int, int, int>;
using vpii = vector<pii>;
using vtiii = vector<tiii>;
using vpic = vector<pic>;

pii dxy[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

pii operator+(const pii& a, const pii& b) {
    return {a.first + b.first, a.second + b.second};
}

void Solve(int t___){
    int N;
    int K;
    cin >> N >> K;
    map<pii, bool> apples;
    REP(i, K){
        int row, col;
        cin >> row >> col;
        apples[{row, col}] = true;
    }
    int L;
    cin >> L;
    map<int, char> dir;
    REP(i, L){
        int t;
        char d;
        cin >> t >> d;
        dir[t] = d;
    }
    queue<pii> body;
    set<pii> bodycheck;
    body.push({1, 1});
    int d = 0;
    for(int t = 0; true; ++t){
        pii head = body.back();
        if(dir.find(t) != dir.end()){
            if(dir[t] == 'L'){
                d = (d + 3) % 4;
            }else{
                d = (d + 1) % 4;
            }
        }
        body.push(body.back() + dxy[d]);
        if(body.back().first < 1 || body.back().first > N || body.back().second < 1 || body.back().second > N || bodycheck.find(body.back()) != bodycheck.end()){
            cout << t + 1 << endl;
            break;
        }
        bodycheck.insert(body.back());
        head = body.back();
        if(apples.find({head}) == apples.end()){
            
            bodycheck.erase(body.front());
            body.pop();
        }else{
            apples.erase(body.back());
        }
    }

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