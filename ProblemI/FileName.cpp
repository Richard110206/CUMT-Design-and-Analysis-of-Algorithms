#include <iostream>
#include <cmath>

using namespace std;

int dp[101];

int main() {
	dp[1] = 1;
	dp[2] = 2;
	int n;
	while (cin >> n) {
		for (int i = 3;i <= n;i++) {
			dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
		}
		cout << dp[n]% 1000000007 << endl;
	}
	
	return 0;
}
