#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int len = 2; len <= n; len++) {          
        for (int i = 1; i + len - 1 <= n; i++) { 
            int j = i + len - 1;                    
            dp[i][j] = INT_MAX;
            int total = pre[j] - pre[i - 1];    
            for (int k = i; k < j; k++) {      
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + total);
            }
        }
    }

    cout << dp[1][n] << endl;
    return 0;
}