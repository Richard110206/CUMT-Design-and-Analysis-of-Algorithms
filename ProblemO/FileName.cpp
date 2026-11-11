#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto& p : a) cin >> p.first >> p.second;

    sort(a.begin(), a.end());

    int L = a[0].first, R = a[0].second;
    int work = 0, idle = 0;

    for (int i = 1; i < n; i++) {
        if (a[i].first <= R) {
            R = max(R, a[i].second);
        }
        else {
            work = max(work, R - L);
            idle = max(idle, a[i].first - R);
            L = a[i].first;
            R = a[i].second;
        }
    }

    work = max(work, R - L);
    cout << work << ' ' << idle;
    return 0;
}