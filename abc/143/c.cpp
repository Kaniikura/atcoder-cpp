#include <iostream>
#define MAX_N 100000
using namespace std;

int n;
string s;

void solve()
{
    int ans = 0;
    char prev = '*';

    for (char &c : s)
    {
        if (c != prev)
        {
            ans++;
        }
        prev = c;
    }
    cout << ans;
}

int main()
{
    cin >> n;
    cin >> s;

    solve();
}
