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
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%.9lf", (double)a / b);
}