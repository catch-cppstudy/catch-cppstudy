#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp1[100001]; // 첫번째 원소를 뜯었을 때의 누적 최대치 (뜯은 값. 남은 값x)
int dp2[100001]; // 첫번째 원소를 안뜯었을 때의 누적 최대치 (뜯은 값. 남은 값x)
int solution(vector<int> sticker)
{
    int answer = 0;
    int len = sticker.size() - 1;
    dp1[0] = dp1[1] = sticker[0];
    dp2[0] = 0; dp2[1] = sticker[1];
    
    for(int i = 2; i < len; i++) {
        dp1[i] = max(dp1[i-2] + sticker[i], dp1[i-1]);  // (첫번째 원소를 뜯고 sticker[i]를 뜯었을 때의 누적합, 첫번째 원소 뜯고 sticker[i] 안뜯었을 때 누적합)
        dp2[i] = max(dp2[i-2] + sticker[i], dp2[i-1]);  // (첫번째 원소를 안뜯고 sticker[i]를 뜯었을 때의 누적합, 첫번째 원소 안뜯고 sticker[i] 안뜯었을 때 누적합)
    }
    dp2[len] = max(dp2[len-2] + sticker[len], dp2[len-1]);
    answer = max(dp1[len-1], dp2[len]);
    return answer;
}