/*
Description: try all possible patient zero and k, check if it consistent with the data
Notice that possible patient zero, min_k and max_k are independent of each other,
so we can update them independently
*/
#include <bits/stdc++.h>
#define ll long long
#define ar array
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
using namespace std;

struct Shake {
    int x, y, t;
    bool operator<(const Shake& other) const {
        return t < other.t;
    }
};

int main() {
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;

    vector<bool> infected_cows(n);
    for (int i = 0; i < n; i++) {
        infected_cows[i] = (s[i] == '1');
    }

    vector<Shake> handshakes(t);
    for (int i = 0; i < t; i++) {
        cin >> handshakes[i].t >> handshakes[i].x >> handshakes[i].y;
        handshakes[i].x --;
        handshakes[i].y --;
    }

    sort(all(handshakes));

    auto is_consistent = [&](int patient_zero, int k) {
        vector<bool> tmp_infected(n, false);
        tmp_infected[patient_zero] = true;
        vector<int> num_handshakes(n, 0);
        
        for (const Shake& sh : handshakes) {
            if (tmp_infected[sh.x]) num_handshakes[sh.x]++;
            if (tmp_infected[sh.y]) num_handshakes[sh.y]++;
            if (tmp_infected[sh.x] && num_handshakes[sh.x] <= k) tmp_infected[sh.y] = true;
            if (tmp_infected[sh.y] && num_handshakes[sh.y] <= k) tmp_infected[sh.x] = true;
        }
        
        for (int i = 0; i < n; i++) {
            if (tmp_infected[i] != infected_cows[i]) return false;
        }
        
        return true;
    };

    int min_k = t, max_k = -1;
    unordered_set<int> possible_patient_zero;

    for (int patient_zero = 0; patient_zero < n; patient_zero++) {
        for (int k = 0; k <= t; k++) {
            if (is_consistent(patient_zero, k)) {
                possible_patient_zero.insert(patient_zero);
                min_k = min(min_k, k);
                max_k = max(max_k, k);
            }
        }
    }

    cout << possible_patient_zero.size() << " " << min_k << " " 
         << (max_k == t ? "Infinity" : to_string(max_k)) << endl;

    return 0;
}
