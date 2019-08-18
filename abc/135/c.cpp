#include <iostream>
#include <algorithm>
#define MAX_N 100000

typedef long long ll;
using namespace std;

int n;
ll a[MAX_N + 1], b[MAX_N];

void solve()
{
    ll res = 0, tmp = 0;
    for (int i = 0; i < n; i++)
    {
        // i番目の勇者が余力を残さないとき
        if (a[i] >= (b[i] + tmp))
        {
            res += b[i] + tmp;
            tmp = 0; // i+1番目に助太刀できない
        }
        else
        {
            res += a[i];
            tmp = min(b[i], min(a[i + 1], b[i] + tmp - a[i]));
        }
    }
    // n+1番目の街はn番目の勇者の余力で倒す
    res += tmp;

    cout << res << endl;
}

int main()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    solve();
}
