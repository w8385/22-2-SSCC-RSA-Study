#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>


//#include <bits/stdc++.h>
using namespace std;

unsigned long long ModExp(unsigned, unsigned, unsigned long long);

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

    /********************* Write code here *********************/
    int first_1 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1' && first_1 == 0) {
            first_1 = 1;
            i++;
        }
        if (first_1 == 1) {
            res = (res *res) % m;
            if (s[i] == '1') {
                res = (res * a) % m;
            }
        }
    }

    return res;
}