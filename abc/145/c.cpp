#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#define MAX_L 100
using namespace std;

int n;
long double x[MAX_L], y[MAX_L];

void solve()
{
    long double ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans += sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        }
    }

    ans /= double(n);

    cout << fixed << setprecision(10) << ans;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    solve();
}
