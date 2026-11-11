#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int main() {
	const int INF = 0x3f3f3f3f;
	int cost[11];
	for (int i = 1;i <= 10;i++) {
		cin >> cost[i];
	}
	int n;
	cin >> n;

	vector<int> dp(n + 1, INF);

	dp[0] = 0;

	for (int i = 1;i <= n;i++) {
		for (int k = 1;k <= 10 && k <= i;k++) {
			dp[i] = min(dp[i], dp[i - k] + cost[k]);
		}
	}
	cout << dp[n] << endl;
	return 0;
}