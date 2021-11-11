#include <string>
#include <vector>
#include <set>

/** 비트마스킹으로 후보키가 될 수 있는 속성인지 확인.
    0001: 학번
    0011: 이름, 학번
    1011: 학년, 이름 학번
    ...
    1111: 학년, 전공, 이름 학번
*/

using namespace std;

//최소성 만족 여부 확인 함수
bool minimal(vector<int> key, int bits)
{
    for (int i = 0; i < key.size(); i++)
    {
        if ((key[i] & bits) == key[i])
            return false;
        //마스크를 씌웠음에도 완전히 같은 값이 나온다면, 최소성 조건에 벗어남.
    }
    return true;
}
int solution(vector<vector<string>> relation)
{
    int row = (int)relation.size();
    int col = (int)relation[0].size();
    vector<int> key; // 후보키로 채택될 수 있는 속성 집합 (비트 값 0 <= 2^(relation[0].size()으로 들어감)

    for (int i = 0; i < (1 << col); i++)
    {                          //전체 비트 수만큼 고려
        set<string> candidate; //후보들 (set으로 저장해서 중복 포함x)
        for (int j = 0; j < row; j++)
        {
            string str = "";
            for (int k = 0; k < col; k++)
            {
                if (i & (1 << k)) // relation[j] 중 i에서 비트가 1인 속성을 탐색
                {
                    str += relation[j][k]; // str에 저장
                }
            }
            candidate.insert(str);

            // candidate에 모든 relation[j]에서 추린 후보키 후보가 있고, 최소성을 만족하는지
            if (candidate.size() == row && minimal(key, i))
                key.push_back(i);
        }
    }
    return key.size();
}