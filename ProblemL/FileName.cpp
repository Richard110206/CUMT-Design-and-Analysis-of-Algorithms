#include <iostream>
#include <string>
#include <queue>

using namespace std;

int huffmanLength(string s) {
	if (s.empty()) return 0;

	int cnt[26] = { 0 };
	for (char c : s) cnt[c-'a']++;

	int kinds = 0;
	for (int i = 0;i < 26;i++) {
		if (cnt[i] != 0) kinds++;
	}

	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0;i < 26;i++) {
		if (cnt[i] > 0) pq.push(cnt[i]);
	}

		long long total = 0;
		while (pq.size() > 1) {
			long long a = pq.top();
			pq.pop();
			long long b = pq.top();
			pq.pop();
			total += a + b;
			pq.push(a + b);
		}
		return total;
	}

int main() {
	int T;
	cin >> T;
	for (int i = 0;i < T;i++) {
		string s;
		cin >> s;
		cout << huffmanLength(s) << endl;
	}
	return 0;
}
