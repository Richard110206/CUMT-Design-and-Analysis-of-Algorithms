#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;                          
    if (!s.empty() && s.back() == ',')
        s.pop_back();

    sort(s.begin(), s.end());  

    bool first = true;
    do {
        if (!first) cout << ' ';
        first = false;
        cout << s;
    } while (next_permutation(s.begin(), s.end()));
    cout << endl;

    return 0;
}