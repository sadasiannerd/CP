#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;

#define isValid(a) ((a >= 0 && a <= 6)? 1 : 0)

#define down 0
#define up 1
#define right 2
#define left 3

bool vis[7][7];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

string s;

ll solve(int pos, int x, int y){
    if(pos == 48) return ((x == 6 && y == 0)?1:0);

    if(x == 6 && y == 0) return 0;

    if(vis[x][y]) return 0;

    vector<bool> visited(4, -1);
    for(int k = 0; k < 4; k ++)
        if(isValid(x + dx[k]) && isValid(y + dy[k]))
            visited[k] = vis[x + dx[k]][y + dy[k]];
    if(!visited[left] && !visited[right] && visited[up] && visited[down]) return 0;

    if(!visited[up] && !visited[down] && visited[left] && visited[right]) return 0;

    if(isValid(x + dx[up]) && isValid(y + dy[right]) && !visited[right] & !visited[up] && vis[x + dx[up]][y + dy[right]]) return 0;

    if(isValid(x + dx[down]) && isValid(y + dy[right]) && !visited[right] & !visited[down] && vis[x + dx[down]][y + dy[right]]) return 0;

    if(isValid(x + dx[up]) && isValid(y + dy[left]) && !visited[left] & !visited[up] && vis[x + dx[up]][y + dy[left]]) return 0;

    if(isValid(x + dx[down]) && isValid(y + dy[left]) && !visited[left] & !visited[down] && vis[x + dx[left]][y + dy[down]]) return 0;

    vis[x][y] = 1;

    ll numPaths = 0;

    if(s[pos] == '?'){
        for(int k = 0; k < 4; k ++){
            if(isValid(x + dx[k]) && isValid(y + dy[k])) numPaths += solve(pos + 1, x + dx[k], y + dy[k]);
        }
    }else{
        if(s[pos] == 'D') if(isValid(x + dx[down]) && isValid(y + dy[down])) numPaths += solve(pos + 1, x + dx[down], y + dy[down]);
        if(s[pos] == 'U') if(isValid(x + dx[up]) && isValid(y + dy[up])) numPaths += solve(pos + 1, x + dx[up], y + dy[up]);
        if(s[pos] == 'L') if(isValid(x + dx[left]) && isValid(y + dy[left])) numPaths += solve(pos + 1, x + dx[left], y + dy[left]);
        if(s[pos] == 'R') if(isValid(x + dx[right]) && isValid(y + dy[right]))numPaths += solve(pos + 1, x + dx[right], y + dy[right]);
    }

    vis[x][y] = 0;

    return numPaths;


}

int main(){
 cin >> s;
 cout << solve(0, 0, 0) << endl;

}
