#include<cstdio>
#include<vector>

using namespace std;

const int S = 100100;
const int inf = 0x7f7f7f7f;

vector<int> arr(S), M_tree(4 * S), m_tree(4 * S);

int N, M;
int base;

int MAX(int a, int b){
    if(a < b){
        return b;
    }else {
        return a;
    }
}

int MIN(int a, int b){
    if(a < b){
        return a;
    }else {
        return b;
    }
}

int M_QUERY(int left, int right){
    left += base - 1;
    right += base - 1;
    int res = -inf;
    while(left <= right){
        if(left % 2 == 1){
            res = MAX(res, M_tree[left]);
            left++;
        }
        if(right % 2 == 0){
            res = MAX(res, M_tree[right]);
            right--;
        }
        left /= 2;
        right /= 2;
    }
    return res;
}

int m_QUERY(int left, int right){
    left += base - 1;
    right += base - 1;
    int res = inf;
    while(left <= right){
        if(left % 2 == 1){
            res = MIN(res, m_tree[left]);
            left++;
        }
        if(right % 2 == 0){
            res = MIN(res, m_tree[right]);
            right--;
        }
        left /= 2;
        right /= 2;
    }
    return res;
}


void init(){
    for(base = 1; base <= N; base *= 2);
    for(int i = 0; i < N; ++i){
        M_tree[i + base] = arr[i];
        m_tree[i + base] = arr[i];
    }
    for(int i = base - 1; i >= 1; --i){
        M_tree[i] = MAX(M_tree[2 * i], M_tree[2 * i + 1]);
        m_tree[i] = MIN(m_tree[2 * i], m_tree[2 * i + 1]);
    }
}

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; ++i){
        scanf("%d", &arr[i]);
    }
    init();
    while(M--){
        int left, right;
        scanf("%d%d", &left, &right);
        printf("%d %d\n", m_QUERY(left, right), M_QUERY(left, right));
    }
    return 0;
}