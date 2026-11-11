#include <iostream>
#include <algorithm>

using namespace std;

int a[8][8];
bool col[8];
bool diag1[15];
bool diag2[15];
int ans = 0;

void dfs(int row, int sum) {
	if (row == 8) {
		ans = max(ans, sum);
		return;
	}
	for (int j = 0;j < 8;j++) {
		int d1 = row - j + 7;
		int d2 = row + j;

		if (col[j] || diag1[d1] || diag2[d2]) {
			continue;
		}
		col[j] = true;
		diag1[d1] = true;
		diag2[d2] = true;

		dfs(row + 1, sum + a[row][j]);

		col[j] = false;
		diag1[d1] = false;
		diag2[d2] = false;
	}
}

int main() {
	int k;
	cin >> k;
	while (k--) {
		for (int i = 0;i < 8;i++) {
			for (int j = 0;j < 8;j++) {
				cin >> a[i][j];
			}
		}
		ans = 0;  
		dfs(0, 0);
		cout << ans << endl;
	}

	return 0;
}