#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string xy[1001][1001] = {".",};

    long long min_row = 10000000000, max_row = -10000000000;
    long long min_col = 10000000000, max_col = -10000000000;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    
    vector<pair<long long,long long>> star;
    for(int i=0; i<line.size()-1; i++){
        for(int j=i+1; j<line.size(); j++){
            long long A = line[i][0]; long long B = line[i][1]; long long E = line[i][2];
            long long C = line[j][0]; long long D = line[j][1]; long long F = line[j][2];
            if(A*D - B*C == 0)
                continue;
            //둘 다 정수 일 때
            if((B*F - E*D)%(A*D - B*C) == 0 && (E*C - A*F)%(A*D - B*C) == 0){
                star.push_back(make_pair((B*F - E*D)/(A*D - B*C), (E*C - A*F)/(A*D - B*C)));
            }
        }
    }
    
    for(int i=0; i<star.size(); i++){
        min_row = min(star[i].first, min_row);
        max_row = max(star[i].first, max_row);
        min_col = min(star[i].second, min_col);
        max_col = max(star[i].second, max_col);
    }
    
    for(int i=0; i<star.size(); i++){
        star[i].first -= min_row;
        star[i].second -= max_col;
        xy[abs(star[i].second)][star[i].first] = "*";
    }
    cout << min_row << " " << max_row <<"\n";
    cout << min_col << " " << max_col <<"\n";
    for(int i=0; i<=max_col-min_col; i++){
        string temp = "";
        for(int j=0; j<=max_row-min_row; j++){
            if(xy[i][j] == "*")
                temp += "*";
            else
                temp += ".";
        }
        answer.push_back(temp);
    }
    
    
    return answer;
}
