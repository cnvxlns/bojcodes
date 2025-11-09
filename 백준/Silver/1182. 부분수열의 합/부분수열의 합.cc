#include<cstdio>
#include<vector>

using namespace std;

vector<int> arr(25);
int N, K;

int main(){
    int cnt = 0;
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; ++i){
        scanf("%d", &arr[i]);
    }
    for(int i = 1; i < (1 << N); ++i){
        int sum = 0;
        for(int j = 0; j < N; ++j){
            if(i & (1 << j)){
                sum += arr[j];
            }
        }
        if(sum == K){
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}