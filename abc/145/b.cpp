#include <iostream>
#include <string>
using namespace std;

int n;
string s;

void solve()
{
    string ans = "No";
    if (n % 2 == 0)
    {
        if (s.substr(0, n / 2) == s.substr(n / 2, n / 2))
            ans = "Yes";
    }

    cout << ans;
}

int main()
{
    cin >> n >> s;

    solve();
}