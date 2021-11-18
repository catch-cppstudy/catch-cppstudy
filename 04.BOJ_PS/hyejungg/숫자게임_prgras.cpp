#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int idx = 0; //같은 i로 비교하면 히든케이스에서 실패
    for (int i = 0; i < B.size(); i++)
    {
        if (A[idx] < B[i])
        {
            // cout << A[idx] << " "  << B[i] << "\n";
            answer++;
            idx++;
        }
    }
    return answer;
}