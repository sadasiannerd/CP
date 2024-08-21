#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;
bool flag[8][8];
string s[8];


vector<pair<int, int>> cur;
int numPairs = 0;
int res = 0;

void BackTrack(int i){
    if(i == 8){
        res ++;
        return;
    }
    for(int j = 0; j < 8; j ++){
        if(s[i][j] != '*'){
          bool tmp = false;
          for(const auto& v: cur)
             if(j == v.second || (abs(v.first - i) == abs(v.second - j))) tmp = true;

          if(!tmp){
          cur.push_back(make_pair(i, j));
          BackTrack(i + 1);
          cur.pop_back();
          }

         }
    }
}


int main(){
    for(int i = 0; i < 8; i ++)
        cin >> s[i];

    for(int i = 0; i < 8; i ++)
        for(int j = 0; j < 8; j ++)
            if(s[i][j] == '*') flag[i][j] = true;
            else flag[i][j] = false;

    BackTrack(0);
    cout << res << endl;
}
