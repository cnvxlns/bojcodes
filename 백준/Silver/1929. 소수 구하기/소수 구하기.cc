#include<cstdio>
#include<vector>

using namespace std;

vector<int> arr(1000100);

int main(){
    int M, N;
    scanf("%d%d", &M, &N); //M < N
    arr[1] = 1;
    for(int i = 4; i <= N; ++i){
        for(int j = 2; j * j <= i; ++j){
            if(i % j == 0){
                arr[i] = 1;
                break;
            }
        }
    }
    for(int i = M; i <= N; ++i){
        if(!arr[i]){
            printf("%d\n", i);
        }
    }

    return 0;
}