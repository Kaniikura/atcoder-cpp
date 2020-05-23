#include <iostream>
#include <string>
using namespace std;

int a, b;

void solve()
{
    int ans;
    ans = max(a - 2 * b, 0);
    cout << ans;
}

int main()
{
    cin >> a >> b;

    solve();
}
