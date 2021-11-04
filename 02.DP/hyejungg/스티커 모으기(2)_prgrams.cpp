#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 점화식 : dp[i] = max(i번째 스티커를 뜯는 경우, i번째 스티커를 뜯지 않는 경우)
 *  -> dp[i] = max(dp[i-1], dp[i-2] + sticker[i])
 */

int solution(vector<int> sticker)
{
    int answer =0;
    int n = sticker.size();
    vector<int> dp(n);
    
    //dp로 i번째 스티커의 최대값을 구하기 위해선 dp[0], dp[1] 초기화 필요
    
    //1. 0번째 인덱스를 뜯은 경우
    cout<< "dp1" << "\n";
    dp[0] = dp[1] = sticker[0];
    for(int i = 2; i < n - 1; i++){ //뜯은 경우, 마지막 스티커에 접근 X
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
        cout << dp[i] << " ";
    }
    answer = dp[n - 2]; //tc33 실패

    //2. 0번째 인덱스를 뜯지 않은 경우
    dp[0] = 0;
    dp[1] = sticker[1];
    cout<< "\ndp2" << "\n";
    for (int i = 2; i < n; i++){ //뜯지 않았으니, 마지막 스티커에 접근 O
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
        cout << dp[i] << " ";
    }
    
    //0번째 인덱스를 뜯은 경우, 안뜯은 경우 중 최대값 비교
    answer = max(answer, dp[n - 1]);
    
    if(sticker.size() == 1) //tc33 실패
        return sticker[0];

    return answer;
}