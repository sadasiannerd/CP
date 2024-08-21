#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;

void Move(int x, int src, int dst, int buff){
    if(x == 1){
        cout << src << spc << dst << endl;
        return;
    }
    if(x == 2){
        cout << src << spc << buff << endl;
        cout << src << spc << dst << endl;
        cout << buff << spc << dst << endl;
        return;
    }
    Move(x - 1, src, buff, dst);
    Move(1, src, dst, buff);
    Move(x - 1, buff, dst, src);

}

int main(){

 int n;
 cin >> n;

 cout << (1 << n) - 1 << endl;

 Move(n, 1, 3, 2);

}
