#include <bits/stdc++.h>
#define ll long long
#define spc " "
#define F first
#define S second
const ll mod = 1e9 + 7;
using namespace std;

void solve(){
    int N, K; cin >> N >> K;

    vector<pair<int,int>> Instructions(K);
    for(int i = 0; i < K; i ++){
        int A, B; cin >> A >> B;
        Instructions[i].F = A - 1;
        Instructions[i].S = B - 1;
    }

    vector<int> diff_arr(N);
    for(int i = 0; i < N; i ++) diff_arr[i] = 0;

    for(auto &Instruction: Instructions){
        diff_arr[Instruction.F] += 1;
        diff_arr[Instruction.S + 1] -= 1;
    }

    vector<int> stacks(N);
    stacks[0] = diff_arr[0];
    for(int i = 1; i < N; i ++)
        stacks[i] = stacks[i - 1] + diff_arr[i];


    sort(stacks.begin(), stacks.end());

    cout << stacks[N / 2] << endl;



}

int main(){

 solve();

}
