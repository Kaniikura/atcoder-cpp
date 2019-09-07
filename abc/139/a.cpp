#include <iostream>
#include <string>
using namespace std;

string s, t;

void solve()
{
    int n = 3;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == t[i])
        {
            ans++;
        }
    }
    cout << ans << endl;
}

int main()
{
    cin >> s >> t;

    solve();
}
