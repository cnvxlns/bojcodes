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
using pqi = priority_queue<int>;
using pqig = priority_queue<int, vi, greater<int>>;
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

vvi sudoku(9, vi(9, 0));

vvi row(9, vi(10, 0)), col(9, vi(10, 0)), square(9, vi(10, 0));

vpii blanks;

/*
row[1][2] = true : 1번열에 2가 있다.
*/

int squarenum(int row, int col){
    /*
    0   1   2
    3   4   5
    6   7   8
    */
    return (row / 3) * 3+ (col / 3) % 3;
}

bool validity(int r, int c, int val){
    if(row[r][val] == 1 || col[c][val] == 1 || square[squarenum(r, c)][val] == 1){
        return false;
    }else{
        return true;
    }
}

bool dfs(int idx){
    if(idx == blanks.size()){
        return true;
    }
    auto [r, c] = blanks[idx];
    rep(val, 1, 9){
        if(validity(r, c, val)){
            row[r][val] = 1;
            col[c][val] = 1;
            square[squarenum(r, c)][val] = 1;
            sudoku[r][c] = val;

            if(dfs(idx + 1)){
                return true;
            }
            row[r][val] = 0;
            col[c][val] = 0;
            square[squarenum(r, c)][val] = 0;
            sudoku[r][c] = 0;
        }
    }
    return false;
}

void Solve() {
    REP(r, 9){
        REP(c, 9){
            scanf("%1d", &sudoku[r][c]);
            if(sudoku[r][c] != 0){
                row[r][sudoku[r][c]] = 1;
                col[c][sudoku[r][c]] = 1;
                square[squarenum(r, c)][sudoku[r][c]] = 1;
            }else{
                blanks.push_back({r, c});
            }        
        }
    }
    dfs(0);
    REP(r, 9){
        REP(c, 9){
            printf("%d", sudoku[r][c]);      
        }
        puts("");
    }
}

int32_t main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    Solve();
    return 0;
}