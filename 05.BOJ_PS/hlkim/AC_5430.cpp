#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t;
  cin >> t;
  while(t--) {
    string action;
    cin >> action;

    int n;
    string str;
    deque<int> dq;
    dq.clear();
    cin >> n >> str;
    string cnt;
    cnt.clear();
    
    for(int i = 1; i < str.size(); i++) {

      if(str[i] >= '0' && str[i] <= '9') {
        cnt += str[i]; 
      }
      else if (str[i] == ',' || i+1 == str.size())
      {
        if(!cnt.empty()) {
          dq.push_back(stoi(cnt));
          cnt.clear();
        }
      }
    }

    bool flag = true;
    bool dFlag = false;
    for(int i = 0; i < action.size(); i++) {
      
      if(action[i] == 'R')  flag = !flag;

      else {
        if(dq.empty()){
          cout << "error\n"; 
          dFlag = true;
          break;
        }
        if(flag) dq.pop_front();
        else dq.pop_back();
      }
    }
    if(!dFlag) {
      if(dq.empty())
        cout << "[]\n";
      else
      {
        cout << "[";
        int len = dq.size();
        if (flag)
        {
          for (int i = 0; i < len - 1; i++)
            cout << dq[i] << ",";
          cout << dq.back() << "]\n";
        }
        else
        {
          for (int i = len - 1; i > 0; i--)
            cout << dq[i] << ",";
          cout << dq.front() << "]\n";
        }
      }
    }
  }
  return 0;
}
