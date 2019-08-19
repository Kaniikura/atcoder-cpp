#include <iostream>
#include <iomanip>
#define MAX_N 100
using namespace std;

int n;
double a[MAX_N];

void solve()
{
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        res += 1 / a[i];
    }

    res = 1 / res;

    cout << setprecision(16) << res << endl;
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
