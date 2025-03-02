#include<cstdio>
#include<vector>
#include<utility>

using namespace std;

const int inf = 0x7f7f7f7f;

typedef pair<int, int> pii;

int N, base;

vector<pii> tree(4 * 101010);

void update(int i, int v){
    i += base - 1;
    tree[i].first = v;
    while(i >= 1){
        if(i % 2){ //right node
            if(tree[i].first < tree[i - 1].first){
                tree[i / 2] = make_pair(tree[i].first, tree[i].second);
            }else{
                tree[i / 2] = make_pair(tree[i - 1].first, tree[i - 1].second);
            }
        }else{ //left node
            if(tree[i].first <= tree[i + 1].first){
                tree[i / 2] = make_pair(tree[i].first, tree[i].second);
            }else{
                tree[i / 2] = make_pair(tree[i + 1].first, tree[i + 1].second);
            }
        }
        i /= 2;
    }
}

int main(){
    scanf("%d", &N);
    for(base = 1; base <= N; base *= 2);
    for(int i = base; i <= base * 2; ++i){
        tree[i].first = inf;
    }
    for(int i = 0; i < N; ++i){
        int tmp;
        scanf("%d", &tmp);
        tree[base + i] = make_pair(tmp, i + 1);
    }
    for(int i = base - 1; i >= 1; --i){
        if(tree[i * 2].first <= tree[i * 2 + 1].first){
            tree[i] = make_pair(tree[i * 2].first, tree[i * 2].second);
        }else{
            tree[i] = make_pair(tree[i * 2 + 1].first, tree[i * 2 + 1].second);
        }
    }
    /*
    for(int i = 1; i <= N; i *= 2){
        for(int j = 0; j < i; j++){
            printf("%d ", tree[i + j].first);
        }
        printf("\n");
    }
    */
    int M;
    scanf("%d", &M);
    while(M--){
        int query;
        scanf("%d", &query);
        if(query == 1){
            int i, v;
            scanf("%d%d", &i, &v);
            update(i, v);
        }
        if(query == 2){
            printf("%d\n", tree[1].second);
        }
        
    }
    return 0;
}