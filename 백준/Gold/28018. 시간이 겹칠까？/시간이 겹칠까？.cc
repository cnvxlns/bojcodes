#include<iostream>
#include<vector>

using namespace std;

int N;

vector<int> a(1000005), q(100100);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i){
        int left, right;
        cin >> left >> right;
        a[left]++;
        a[right + 1]--;
    }
    for(int i = 1; i <= 1000002; ++i){
        a[i] += a[i - 1];
    }
    int query;
    cin >> query;
    for(int i = 0; i < query; ++i){
        cin >> q[i];
    }
    for(int i = 0; i < query; ++i){
        cout << a[q[i]] << "\n";
    }
    return 0;
}