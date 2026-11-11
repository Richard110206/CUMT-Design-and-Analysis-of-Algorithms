#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        long long k;

        cin >> s >> k;

        k = (k % 26 + 26) % 26;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = 'A' + (s[i] - 'A' - k + 26) % 26;
            }
            else if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = 'a' + (s[i] - 'a' - k + 26) % 26;
            }

        }

        cout << s << endl;
    }

    return 0;
}
