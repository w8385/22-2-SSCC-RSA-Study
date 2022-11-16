#include <bits/stdc++.h>
using namespace std;

unsigned long long ModExp(unsigned, unsigned, unsigned long long);

int main() {
    unsigned a, e;
    unsigned long long m;
    cin >> a >> e >> m;
    cout << "a = " << a << ", e = " << e << ", m = " << m << '\n';

    unsigned long long res = ModExp(a, e, m);
    cout << "a ^ e mod m = " << res;

    return 0;
}

/********************** Do not fix code above **********************/

unsigned long long ModExp(unsigned a, unsigned e, unsigned long long m) {
    string s = bitset<32>(e).to_string();
    unsigned long long res = a;

    int resStart = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 1) {
            resStart = i + 1;
            break;
        }
    }
    for (int j = resStart; j < s.size(); j++) {
        res = (unsigned) pow(res, 2) % m;
        if (s[j] = '1')
            res = (unsigned)(res * a) % m;
    }

    return res;
}