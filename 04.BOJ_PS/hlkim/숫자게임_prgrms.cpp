#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int aIdx = 0, bIdx = 0;
    // 큰 수 부터 비교
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    while(aIdx < A.size() && bIdx < B.size()) {
        if(A[aIdx] < B[bIdx]) {
            answer += 1;
            aIdx += 1;
            bIdx += 1;
        }
        else
            aIdx += 1;
    }
    return answer;
}