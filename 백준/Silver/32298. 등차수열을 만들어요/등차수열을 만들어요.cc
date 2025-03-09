#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_N = 2000001;

vector<bool> sieve(int limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<bool> is_prime = sieve(MAX_N);

    for (int i = 1; i < MAX_N; i++) {
        vector<int> arr;
        bool is_all_composite = true;

        for (int j = 0; j < n; j++) {
            int num = i + j * m;
            if (is_prime[num]) {
                is_all_composite = false;
                break;
            }
            arr.push_back(num);
        }

        if (is_all_composite) {
            for (int num : arr) {
                cout << num << " ";
            }
            cout << "\n";
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}
