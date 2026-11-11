#include <iostream>
#include <string>
#include <algorithm>   
using namespace std;

int dp[2000][2000];

int main() {
	string a, b;
	cin >> a >> b;

	int m = a.size();
	int n = b.size();

	for (int i = 1;i <= m;i++) {
		for (int j = 1;j <= n;j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[m][n];
	return 0;
}