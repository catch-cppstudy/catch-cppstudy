#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

vector<string> filename[10001]; // 입력받은 문자열을 문자, 숫자로 나눈다.
int n;
int upperflag[2] = {0, 0};

// [우선순위 3] : 문자 숫가 구분.
void parseStrig(string& s, int idx)
{
  string alpha; 
  string number;
  for(int i = 0; i < s.size(); i++) {

    if(isalpha(s[i])){
      if(!number.empty()) {
        filename[idx].push_back(number);
        number.clear();
      }
      alpha.push_back(s[i]);
    }
    else if (isdigit(s[i])) {
      if(!alpha.empty()) {
        filename[idx].push_back(alpha);
        alpha.clear();
      }
      number.push_back(s[i]);
    }
  }
  if (!number.empty()) filename[idx].push_back(number);
  if (!alpha.empty())  filename[idx].push_back(alpha);
}

int validateHasUpper(char s, int idx) {
  int ret = 0;
  if (isupper(s))
  {
    upperflag[idx] = 1;
    ret = s - 'A';
  }
  else
    ret = s - 'a';
  
  return ret;
}

int getZeroCnt(string s)
{
  int cnt = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '0')
      cnt += 1;
    else
      break;
  }
  return cnt;
}

string getRealCnt(string s)
{
  string num = "";
  int j;
  for (j = 0; j < s.size(); j++)
  {
    if(s[j] != '0') break;
  }
  num = s.substr(j);
  return num;
}

bool naturalSort(vector<string>& a, vector<string>& b) {
  int len = min(a.size(), b.size());
  for(int i = 0; i < len ; i++) {
    string start = a[i];
    string target = b[i];
    // [우선순위 2-1] 숫자-문자 : 숫자가 알파벳 보다 우선한다.
    if (isdigit(start[0]) && isalpha(target[0]))
      return true;
    else if (isalpha(start[0]) && isdigit(target[0]))
      return false;
    // 문자-문자? (첫문자만 비교)
    else if (isalpha(start[0]) && isalpha(target[0]))
    {
      int minLeng = min(start.size(), target.size());
      for(int j = 0; j < minLeng; j++)
      {
        /*  [우선순위 2-2] 알파벳끼리는 대소문자 상관없이 "순번대로" 우선순위를 가지기 때문에, 
            순번(sIdx, tIdx)과 대문자 여부 배열 선언
            (upperflag{ start[j]가 대문자면 1 아니면 0, target[j] ... } )    
        */ 
        memset(upperflag, 0, sizeof(upperflag));
        int sIdx = validateHasUpper(start[j], 0);
        int tIdx = validateHasUpper(target[j], 1);

        if (sIdx < tIdx) return true;
        else if (sIdx > tIdx) return false;
        else
        { 
          // 알파벳 순번이 같으면 대문자 우선
          if (upperflag[0] && !upperflag[1])  // start가 대문자
            return true;
          else if (!upperflag[0] && upperflag[1])
            return false;
        }
      }
    }
    // 숫자-숫자
    else if (isdigit(start[0]) && isdigit(target[0]))
    {
      int zeroCnt1 = getZeroCnt(start);
      int zeroCnt2 = getZeroCnt(target);
      
      string realCnt1 = getRealCnt(start);
      string realCnt2 = getRealCnt(target);
      
      // [우선순위 5] : 숫자가 같을 경우, 숫자 앞의 0의 개수가 적은것이 앞에 옴.
      if(realCnt1 == realCnt2) {
        if (zeroCnt1 < zeroCnt2) return true;
        else if (zeroCnt1 > zeroCnt2) return false;
      }

      else {
        // 자리수 
        if(realCnt1.size() < realCnt2.size())  return true;
        else if(realCnt1.size() > realCnt2.size()) return false;
        // 숫자 비교
        else {
          if(realCnt1 < realCnt2) return true;
          if(realCnt1 > realCnt2) return false;
        }
      }
    }
  
    if(start.size() < target.size())  return true;
    else if(start.size() > target.size())  return false;
  }

  if(a.size() < b.size()) return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    parseStrig(s, i);
  }
  
  sort(filename, filename + n, naturalSort);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < filename[i].size(); j++)
      cout << filename[i][j];
    cout << "\n";
  }
    
  return 0;
}