#include <iostream>
#include <cmath>
#include <string>
typedef long long ll;
using namespace std;

ll a;
double b;

void solve()
{
    ll ans;
    ll x, y, z;
    x = a * ll(b);
    y = a * (ll(floor(b * 10)) % 10);
    z = a * (ll(round(b * 100)) % 10);
    ans = (x * 100 + y * 10 + z) / 100;

    cout << ans << endl;
}

int main()
{
    cin >> a >> b;

    solve();
}
