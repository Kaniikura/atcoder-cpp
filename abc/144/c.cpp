#include <iostream>
#include <cmath>
#include <string>
typedef long long ll;
using namespace std;

ll n;

void solve()
{
    ll count;
    count = n - 1;
    for (ll x = 1; x < floor(sqrt(n)) + 1; x++)
    {
        if (n % x == 0)
        {
            ll y = n / x;
            count = min(x + y - 2, count);
        }
    }

    cout << count;
}

int main()
{
    cin >> n;

    solve();
}
