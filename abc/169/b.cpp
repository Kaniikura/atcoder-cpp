#include <iostream>
#include <string>
using namespace std;
typedef long long int ll;
#define MAX_N 100000

int n;
ll a[MAX_N];

void solve()
{
    ll ans = 1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            ans = 0;
    }
    if (ans != 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (ans > 1000000000000000000 / a[i])
            {
                ans = -1;
                break;
            }
            ans *= a[i];
        }
    }
    cout << ans;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    solve();
}
