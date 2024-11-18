#include<cstdio>
#include<vector>

using namespace std;

vector<int> arr(1010);
int cache[1001][2][1001];


int N;
int inf = 0x7f7f7f7f;

int max(int a, int b){
    if(a < b){
        return b;
    }else{
        return a;
    }
}

int dp(int index, int updown, int prev){ //updown == 1 : up
    if(index >= N){
        return 0;
    }
    if(cache[index][updown][prev]){
        return cache[index][updown][prev];
    }
    if(updown == 1){
        if(prev < arr[index]){
            return cache[index][updown][prev] = max(dp(index + 1, 1, arr[index]) + 1, dp(index + 1, 1, prev));
        }else if(prev > arr[index]){
            return cache[index][updown][prev] = max(dp(index + 1, 0, arr[index]) + 1, dp(index + 1, 1, prev));
        }else{
            return -inf;
        }
    }else{
        if(prev == arr[index]){
            return -inf;
        }else if(prev > arr[index]){
            return cache[index][updown][prev] = max(dp(index + 1, 0, arr[index]) + 1, dp(index + 1, 0, prev)); 
        }else{
            return cache[index][updown][prev] = dp(index + 1, 0, prev);
        }
    }
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &arr[i]);
    }
    printf("%d", dp(0, 1, 0));
    return 0;
}