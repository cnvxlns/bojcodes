#include<bits/stdc++.h>

using namespace std;

const int inf = 0x7f7f7f7f;

typedef pair<int, int> pii;

int N;

vector<int> a(1e5 + 345);

bool is_possible(int mid){ //mid: num of pages
    int cmp = a[0];
    for(int i = 0; i < N; ++i){
        if(cmp * 2 > a[i]){
            continue;
        }else{
            cmp = a[i];
            mid--;
            if(mid <= 0){
                return 0;
            }
        }
    }
    return 1;
}

int binsearch(int l, int r){
    if(l == r){
        return l;
    }
    int mid = l + r;
    mid /= 2;
    if(is_possible(mid)){
        return binsearch(l, mid);
    }else{
        return binsearch(mid + 1, r);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }
    sort(&a[0], &a[0] + N);
    cout << binsearch(1, 1e6);
    return 0;
}