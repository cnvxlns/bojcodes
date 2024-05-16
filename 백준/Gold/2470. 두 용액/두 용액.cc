#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> a(100200);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i <= N; ++i){
        cin >> a[i];
    }
    sort(&a[0], &a[0] + N);
    int min = 0x7f7f7f7f;
    int ansx;
    int ansy;
    for(int i = 0; i < N; ++i){
        int l = i + 1, r = N - 1;
        while(l <= r){
            int mid = l + r;
            mid /= 2;
            int sum = a[i] + a[mid];
            if(abs(sum) < min){
                min = abs(sum);
                ansx = a[i];
                ansy = a[mid];
            }
            if(sum < 0){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
    }
    cout << ansx << " " << ansy;
    return 0;
}