#include <bits/stdc++.h>
using namespace std;

unsigned long long ModExp(unsigned , unsigned , unsigned long long);

int main() {
    unsigned a, e;
    unsigned long long m;
    cin >> a >> e >> m;
    cout << "a = " << a << ", e = " << e << ", m = " << m << '\n';

    unsigned long long res = ModExp(a, e, m);
    cout << "a ^ e mod m = " << res;
}

/********************** Do not fix code above **********************/

unsigned long long ModExp(unsigned a, unsigned e, unsigned long long m) {
    string s = bitset<32>(e).to_string();
    unsigned long long res = a;

    res %= m;//없으면 백준 틀림
    bool inLine = false;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1' && !inLine) {
            inLine = true;
            continue;
        }
        if (inLine) {
            res = (res * res) % m;
            if (s[i] == '1') {
                res = (res * a) % m;
            }
        }
    }
    return res;
}