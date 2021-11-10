#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    answer = s.size();
    int len = s.size() / 2;
    // 압축 단위: 1 ~ len/2
    for(int i = 1; i <= len; i++) {
        string start = s.substr(0, i);
        int cnt = 1;
        string tmp;
        for(int j = i; j < s.size(); j+=i) 
        {
            if(start != s.substr(j, i)) 
            {
                if (cnt > 1) tmp += to_string(cnt) + start;
                else if(cnt == 1) tmp += start;
                start = s.substr(j, i);
                cnt = 1;
            }
            else 
            {
                cnt++;
            }
        }
        if (cnt > 1) tmp += to_string(cnt) + start;
        else if(cnt == 1) tmp += start;
        answer = min(answer, (int)tmp.size());
    }
    return answer;
}