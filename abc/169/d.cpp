#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
typedef long long ll;
using namespace std;
const long double PI = (acos(-1));
const long double EPS = 0.0000000001;

ll num;

ll calc_maxn(ll a)
{
    ll i = 1;
    ll count = 0;
    while (a >= i)
    {
        a = a - i;
        i++;
        count++;
    }
    return count;
}

template <typename T>
void PrimeFactors(T n, std::map<T, T> &out)
{
    while (n % 2 == 0)
    {
        ++out[2];
        n = n / 2;
    }

    for (T i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            ++out[i];
            n = n / i;
        }
    }

    if (n > 2)
        ++out[n];
}

void solve()
{
    ll ans = 0;
    map<ll, ll> m;
    PrimeFactors(num, m);

    for (const auto &a : m)
    {
        //cout << a.first << ' ' << a.second << endl;
        ans += calc_maxn(a.second);
    }
    cout << ans;
}

int main()
{
    cin >> num;

    solve();
}
