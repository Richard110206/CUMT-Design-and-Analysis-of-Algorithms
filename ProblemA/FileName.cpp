#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n;
	long long L;
	cin >> n >> L;
	// 反向思考：代价为两端合并后的长度-->哈夫曼树，每次将最短的两个进行合并
	priority_queue<long long, vector<long long>, greater<long long>>pq;
	for (int i = 0;i < n;i++) {
		long long x;
		cin >> x;
		pq.push(x);
	}
	long long cost = 0;
	while (pq.size() > 1) {
		long long a = pq.top(); pq.pop();
		long long b = pq.top(); pq.pop();
		long long sum = a + b;
		cost += sum;
		pq.push(sum);
	}
	cout << cost;
	return 0; 
}