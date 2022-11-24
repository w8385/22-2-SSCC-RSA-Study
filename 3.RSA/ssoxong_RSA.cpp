#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;

bool gcd(int, int);
pair<int, int> genPQ();
int genE(int phi);
int EEA(int e, int phi);
long long ModExp(long long base, long long exp, long long mod);

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int p = genPQ().first;
    int q = genPQ().second;

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = genE(phi);
    int d = EEA(e, phi);

    int plain_message;
    cin >> plain_message;

    long long encrypted = ModExp(plain_message, e, n);
    int decrypted = ModExp(encrypted, d, n);

    cout << "p: " << p << '\n';
    cout << "q: " << q << '\n';
    cout << "e: " << e << '\n';

    cout << "encrypted message: " << encrypted << '\n';
    cout << "decrypted message: " << decrypted << '\n';

}

/********************** Do not fix code above **********************/

bool gcd(int a, int b) {
    for (int i = 2; i <= min(a, b); i++) {
        if (a % i == 0 && b % i == 0) {
            return false;
        }
    }
    return true;
}

pair<int, int> genPQ() {
    bool prime[46340];
    fill(prime + 2, prime + 46340, true);

    for (int i = 2; i * i < 46340; i++) {
        if (not prime[i])
            continue;

        for (int j = 2; i * j < 46340; j++)
            prime[i * j] = false;
    }
    vector<int> pq;
    for (int i = 32768; i < 46340; i++)
        if (prime[i])
            pq.emplace_back(i);

    unsigned seed = std::chrono::system_clock::now()
        .time_since_epoch()
        .count();
    shuffle(pq.begin(), pq.end(), default_random_engine(seed));

    return { pq[0], pq[1] };
}

int genE(int phi) {
    bool prime[46340];
    fill(prime + 2, prime + 46340, true);

    for (int i = 2; i * i < 46340; i++) {
        if (not prime[i])
            continue;

        for (int j = 2; i * j < 46340; j++)
            prime[i * j] = false;
    }
    vector<int> e;
    for (int i = 32768; i < 46340; i++)
        if (prime[i] && gcd(i, phi) == 1)
            e.emplace_back(i);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(e.begin(), e.end(), default_random_engine(seed));

    return e[0];
}

int EEA(int phi, int e) {
    int r1 = e, r2 = phi, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
    int r, s, t, q;
    while (r2) {
        q = r1 / r2;
        // gcd 계산
        r = r1 % r2;
        r1 = r2, r2 = r;

        // s 계산
        s = s1 - q * s2;
        s1 = s2, s2 = s;

        // t 계산
        t = t1 - q * t2;
        t1 = t2, t2 = t;
    }
    r = r1, s = s1, t = t1;

    if (r == 1) {
        if (t < 0) {
            t += e;
        }
        return t;
    }
    else return NULL;
}

long long ModExp(long long a, long long e, long long m) {
    string s = bitset<32>(e).to_string();
    long long res = a;

    res %= m;
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