#include <iostream>
#include <string>
using namespace std;

int main()
{
    string k, c;
    cin >> k >> c;

    string ans = "";

    for (int i = 0; i < c.length(); i++)
    {
        char ch = c[i];
        char key = k[i % k.length()];

        char a = ch;
        char b = key;

        if (a >= 'A' && a <= 'Z')
            a = a - 'A' + 'a';

        if (b >= 'A' && b <= 'Z')
            b = b - 'A' + 'a';

        int x = a - 'a';
        int y = b - 'a';

        int result = (x - y + 26) % 26;

        char plain = result + 'a';

        if (ch >= 'A' && ch <= 'Z')
            plain = plain - 'a' + 'A';

        ans += plain;
    }

    cout << ans << endl;

    return 0;
}
