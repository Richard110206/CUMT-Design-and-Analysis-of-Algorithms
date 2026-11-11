#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int res[100], len = 0;
	while (n > 0) {
		res[len++] = n % 8;
		n /= 8;
	}
	for (int i = len - 1;i >= 0;i--) {
		cout << res[i];
	}
	cout << endl;
	return 0;
}