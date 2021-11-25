#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 10000000001

vector<string> solution(vector<vector<int>> line)
{
    vector<pair<long long, long long>> spot;

    long long maxX = -10000000000, minX = 10000000000, maxY = -10000000000, minY = 10000000000; // min값 -1 -> -100001 이것도 오류. //정답은 1,000 * 1,000 크기 이내에서 표현라서 최대한 많이 ...

    //교점 구해
    for (int i = 0; i < line.size(); i++)
    {
        for (int j = i + 1; j < line.size(); j++)
        {
            long long A = line[i][0], B = line[i][1], E = line[i][2];
            long long C = line[j][0], D = line[j][1], F = line[j][2];

            long long xM = (B * F) - (E * D);
            long long yM = (E * C) - (A * F);

            long long m = (A * D) - (B * C);

            if (m == 0) // 0은 평행한다고 봄
                continue;

            if ((xM % m != 0) || (yM % m != 0)) //정수만 쓸꺼니까
                continue;

            long long x = xM / m;
            long long y = yM / m;

            minX = min(x, minX);
            minY = min(y, minY);
            maxX = max(x, maxX);
            maxY = max(y, maxY);

            spot.push_back({x, y});
        }
    }
    // cout << "가로길이 : " << maxX - minX + 1 << " 세로길이 : " << maxY - minY + 1 << "\n";
    string row = string(maxX - minX + 1, '.');
    vector<string> answer(maxY - minY + 1, row);

    for (auto s : spot)
        // cout << abs(s.second - maxY) << " " << abs(s.first - minX) << "\n";
        // answer[abs(s.first - minX)][abs(s.second - maxY)] = '*';
        answer[abs(s.second - maxY)][abs(s.first - minX)] = '*';

    return answer;
}