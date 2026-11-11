#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n, 0);

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	cout << arr[k-1];

	return 0;
}