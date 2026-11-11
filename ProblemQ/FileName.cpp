#include <iostream>

using namespace std;

bool used[20];
int path[20];
int n;
int ans;

bool isPrime(int x) {
	if(x<2){
		return false;
	}
	for (int i = 2;i * i <= x;i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

void dfs(int k) {
	if (k > n) {
		if (isPrime(path[n] + path[1])) {
			ans++;
		}
		return;
	}
	for (int i = 2;i <= n;i++) {
		if (used[i]) continue;
		if (!isPrime(path[k - 1] + i)) continue;

		path[k] = i;
		used[i] = true;

		dfs(k + 1);

		used[i] = false;
	}
}
int main() {  
	while (cin >> n) {
		ans = 0;
		for (int i = 1;i <= n;i++) {
			used[i] = false;
		}
		path[1] = 1;
		used[1] = true;
		dfs(2);

		cout << ans << endl;
	}
	return 0;
}