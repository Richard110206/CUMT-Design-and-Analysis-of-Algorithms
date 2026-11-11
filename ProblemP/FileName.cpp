#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string s;
	while (cin >> n >> s) {
		int l = 0,r = n - 1;
		string ans;
		while (l <= r) {
			bool left = false;
			for (int i = 0;i + l <= r;i++) {
				if (s[l + i] < s[r - i]) {
					left = true;
					break;
				}
				else if (s[l + i] > s[r - i]) {
					left = false;
					break;
				}
			}
			if (left) {
				ans += s[l];
				l++;
			}
			else {
				ans += s[r];
				r--;
			}
		}
		cout << ans << endl;
	}
	return 0;
}