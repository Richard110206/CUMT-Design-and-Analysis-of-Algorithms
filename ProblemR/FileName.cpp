#include <iostream>

using namespace std;

int main() {
	int dp[31];

	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;

	for (int i = 3;i <= 30;i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	int n;
	while (cin >> n) {
		int total = 1 << n;
		cout << total - dp[n] << endl;
	}
	return 0;
}