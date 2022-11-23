#include <bits/stdc++.h>
using namespace std;

pair<int, int> genPQ();
int genE(int phi);
int EEA(int e, int phi);
long long ModExp(long long base, long long exp, long long mod);

int main(){
    int p = genPQ().first;
    int q = genPQ().second;

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = genE(phi);
    int d = EEA(e, phi);

    int plain_message;
    cin >> plain_message;

    long long encrypted = ExpMod(plain_message, e, n);
    int decrypted = ExpMod(encrypted, d, n);

    cout << "p: " << p << '\n';
    cout << "q: " << q << '\n';
    cout << "e: " << e << '\n';
    cout << "encrypted message: " << encrypted << '\n';
    cout << "decrypted message: " << decrypted << '\n';
}

/********************** Do not fix code above **********************/

pair<int, int> genPQ(){
    bool prime[46340];
    // TODO: Sieve
    // Make the value of the primary index 'true'

    vector<int> pq;
    for(int i = 32768; i < 46340; i++)
        if(prime[i])
            pq.emplace_back(i);

    unsigned seed = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle(pq.begin(), pq.end(), default_random_engine(seed));
    
    return {pq[0], pq[1]};
}

int genE(int phi){
    bool prime[46340];
    // TODO: Sieve
    // Make the value of the primary index 'true'

    vector<int> e;
    for(int i = 32768; i < 46340; i++)
        if(prime[i] && gcd(i, phi) == 1)
            e.emplace_back(i);

    unsigned seed = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle(e.begin(), e.end(), default_random_engine(seed));

    return e[0];
}

int EEA(int e, int phi) {
    // TODO: Extended Euclidean Algorithm
    // calculate d, that d = e^-1 mod(phi)
    // return d
}

long long ModExp(long long base, long long exp, long long mod){
    // TODO: Modular Exponentiation
    // use your ModExp.cpp code
}
