#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>

int R[26], C[26];
using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m) {
		for (int i = 0;i < n;i++) {
			char ch;
			int r, c;
			cin >> ch >> r >> c;
			R[ch - 'A'] = r;
			C[ch - 'A'] = c;
		}
		while (m--) {
			string s;
			cin >> s;

			int len = s.size();
			bool valid = true;

			for (int i = 0;i < len - 1;i++) {
				if (C[s[i] - 'A'] != R[s[i+1] - 'A']) {
					valid = false;
					break;
				}
			}
			if (!valid) {
				cout << "MengMengDa" << endl;
				continue;
			}
			vector<int> p(len + 1);
			p[0] = R[s[0] - 'A'];

			for (int i = 0;i < len;i++) {
				p[i + 1] = C[s[i] - 'A'];
			}
			vector<vector<long long>> dp(len, vector<long long>(len, 0));

			for (int l = 2;l <= len;l++) {
				for (int i = 0;i + l <= len;i++) {
					int j = i + l - 1;
					dp[i][j] = LLONG_MAX;

					for (int k = i;k < j;k++) {
						long long cost = dp[i][k] + dp[k + 1][j] + 1LL * p[i] * p[k + 1] * p[j + 1];
						dp[i][j] = min(dp[i][j], cost);
					}
				}
			}
			cout << dp[0][len - 1] << endl;
		}
	}

	return 0;

}