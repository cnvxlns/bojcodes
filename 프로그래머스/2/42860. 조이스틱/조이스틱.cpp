#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name){
    vector<int> alpha(26);
    int answer = 0;
    for(auto i = 0; i < 26; ++i){
        alpha[i] = min(i, 26 - i);
    }
    const auto n = name.size();
    auto move = n - 1;
    
    for(auto i = 0; i < name.size(); ++i){
        answer +=  alpha[name[i] - 'A'];
        auto next_idx = i + 1;
        while (next_idx < n && name[next_idx] == 'A'){
            next_idx ++;
        }
        move = min(move, 2 * i + n - next_idx);
        move = min(move, i + 2 * (n - next_idx));
    }
    
    
    
    return answer + move;
}