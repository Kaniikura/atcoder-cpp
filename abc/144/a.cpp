#include <iostream>
#include <string>
using namespace std;

int a, b;

void solve()
{
    int ans;
    if (a < 10 && b < 10)
    {
        ans = a * b;
    }
    else
        ans = -1;
    cout << ans;
}

int main()
{
    cin >> a >> b;

    solve();
}
