#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
typedef long long int ll;
using namespace std;

ll x, y;
ll MOD = 1000000000 + 7;

ll modpow(ll a, ll n, ll mod)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
// mod.m での a の逆元 a ^ { -1 } を計算する
ll modinv(ll a, ll mod)
{
    return modpow(a, mod - 2, mod);
}

ll combi(ll n, ll r)
{
    if (r * 2 > n)
        r = n - r;
    ll ret = 1;
    for (ll i = 1; i <= r; ++i)
    {
        ret = ret * (n - i + 1) % MOD; // *= だと計算結果が間違いになった．なぜ？
        ret = ret * modinv(i, MOD) % MOD;
    }
    return ret;
}

void solve()
{
    ll n, ans, cx, cy;
    if ((x + y) % 3 != 0)
        ans = 0;
    else
    {
        n = (x + y) / 3;
        cx = x - n;
        cy = y - n;
        if (cx < 0 || cy < 0)
            ans = 0;
        else
            ans = combi(n, cx);
    }
    ans %= MOD;
    cout << ans;
}

int main()
{
    cin >> x >> y;

    solve();
}
