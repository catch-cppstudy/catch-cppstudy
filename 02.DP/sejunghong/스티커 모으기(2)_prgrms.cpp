#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp1[100001] = {0,}; //첫번째 스티커 포함
int dp2[100001] = {0,}; //첫버째 스티커 미포함

int solution(vector<int> sticker)
{
    int answer =0;
    
    //사이즈 1일 때
    if(sticker.size() == 1)
       return sticker[0]; 
    //사이즈 2일 때
    else if(sticker.size() == 2)
        return max(sticker[0], sticker[1]);
    
    //초기값
    dp1[0] = sticker[0]; dp1[1] = sticker[1];
    dp2[0] = 0; dp2[1] = sticker[1];
    answer = max(sticker[0], sticker[1]);
    dp1[2] = dp1[0] +  sticker[2];
    dp2[2] = dp2[0] +  sticker[2];
    
    for(int i=3; i<sticker.size(); i++){
        if(i != sticker.size()-1)
            dp1[i] = max(dp1[i-2], dp1[i-3]) + sticker[i];
        dp2[i] = max(dp2[i-2], dp2[i-3]) + sticker[i];
        
        //cout << dp1[i] << " " << dp2[i] << "\n";
        answer = max({answer, dp1[i], dp2[i]});
    }

    return answer;
}
