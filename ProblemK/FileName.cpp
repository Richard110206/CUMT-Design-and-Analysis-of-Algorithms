/*
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	int M, N;
	while (cin >> M >> N && (M != 0 && N != 0)) {
		vector<int> T(M + 1), V(M + 1);
		vector<vector<double>> dp(M + 2, vector<double>(N + 1, 0));

		for (int i = 1;i <= M;i++) {
			cin >> T[i] >> V[i];
		}

		for (int i = M;i >= 1;i--) {
			for (int j = 0;j <= N;j++) {
				dp[i][j] = dp[i + 1][j];

				if (j >= T[i]) {
					dp[i][j] = max(dp[i][j], dp[i + 1][j - T[i]] + V[i]);
				}
			}
		}
		cout << fixed << setprecision(2) << dp[1][N] << endl;
	}

	return 0;
}
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    int M, N;
    while (cin >> M >> N && (M != 0 && N != 0)) {
        vector<int> T(M + 1), V(M + 1);
        vector<int> id(M + 1);
        vector<double> ratio(M + 1);

        for (int i = 1; i <= M; i++) {
            cin >> T[i] >> V[i];
            ratio[i] = (double)V[i] / T[i];  
            id[i] = i;
        }

        sort(id.begin() + 1, id.end(), [&](int a, int b) {
            return ratio[a] > ratio[b];
            });

        double ans = 0;
        int remain = N;

        for (int k = 1; k <= M; k++) {
            int i = id[k];
            if (remain >= T[i]) {
                ans += V[i];  
                remain -= T[i];
            }
            else {
                ans += (double)V[i] * remain / T[i];
                break;
            }
        }

        cout << fixed << setprecision(2) << ans << endl;
    }

    return 0;
}