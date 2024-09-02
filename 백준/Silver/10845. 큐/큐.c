#include<stdio.h>
#include<string.h>

#define inf 0x3f3f3f3f
#define loop(M) for(int _ = 0; _ < M; ++_)

typedef long long ll;
typedef struct _pii{ll first, second;} pii;
typedef struct _tiii{ll first, second, third;} tiii;

const ll Size = 1e6;

const int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};

void Solve();

int main(){
    Solve();
    return 0;
}

void Solve(){
    int N;
    int f = 0;
    int b = 0;
    int Q[10010];
    scanf("%d\n", &N);
    loop(N){
        char cmd[30];
        fgets(cmd, 30, stdin);
        if(cmd[0] == 'p' && cmd[1] == 'u'){
            int x = 0;
            for(int i = 5; cmd[i] != '\n'; ++i){
                x *= 10;
                x += cmd[i] - 48;
            }
            Q[b++] = x;
        }
        if(cmd[0] == 'p' && cmd[1] == 'o'){
            if(f < b){
                printf("%d\n", Q[f++]);
            }else{
                printf("-1\n");
            }
        }
        if(cmd[0] == 's'){
            printf("%d\n", b - f);
        }
        if(cmd[0] == 'e'){
            if(b == f){
                printf("1\n");
            }else{
                printf("0\n");
            }
        }
        if(cmd[0] == 'f'){
            if(f == b){
                printf("-1\n");
            }else{
                printf("%d\n", Q[f]);
            }
        }
        if(cmd[0] == 'b'){
            if(f == b){
                printf("-1\n");
            }else{
                printf("%d\n", Q[b - 1]);
            }
        }
    }
}