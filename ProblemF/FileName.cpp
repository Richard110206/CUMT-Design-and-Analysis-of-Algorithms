/*
#include <iostream>
#include <cmath>

using namespace std;
 
const int mod = 100000007;

long long LongPow(int x) {
	long long ans = 0;
	for (int i = 1; i <= x; ++i)
		ans += (int)pow(i, i) % mod;
	return (ans+1) % mod;
}

int main() {
	int n;
	while (cin >> n) {
		cout << LongPow(n) << endl;
	}
	return 0;
}
*/

#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 100000007;
const int MAX = 25000;

ll qpow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll pre[MAX + 5];

void init() {
    pre[0] = 0;
    for (int i = 1; i <= MAX; ++i) {
        ll term = qpow(i, i, MOD);
        pre[i] = (pre[i - 1] + term) % MOD;
    }
}

int main() {
    init();
    int x;
    while (cin >> x) {
        cout << (pre[x] + 1) % MOD << endl;
    }
    return 0;
}