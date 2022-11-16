#include <bits/stdc++.h>
using namespace std;

unsigned long long ModExp(unsigned, unsigned, unsigned long long);

int main(){
    unsigned a, e;
    unsigned long long m;
    cin >> a >> e >> m;
    cout << "a = " << a << ", e = " << e << ", m = " << m << '\n';

    unsigned long long res = ModExp(a, e, m);
    cout << "a ^ e mod m = " << res;
}

/********************** Do not fix code above **********************/

unsigned long long ModExp(unsigned a, unsigned e, unsigned long long m){
    string s = bitset<32>(e).to_string();
    unsigned long long res = a;

    /********************* Write code here *********************/
		int pos = 0;
		while (s[pos] == '0')
							pos++

		for(int i=pos+1; i<s.size(); i++){
						res = (res*res) % m;
						if (s[i] == '1')
								res = (res*a) % m;
		}    
    return res;
}