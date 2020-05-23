#include <iostream>
#define MAX_N 100000
using namespace std;

int d[MAX_N];
int n;

void solve()
{
    int sum = 0;
    int sum_sq = 0;
    int ans;

    for (int i = 0; i < n; i++)
    {
        sum += d[i];
        sum_sq += d[i] * d[i];
    }

    ans = (sum * sum - sum_sq) / 2;

    cout << ans;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    solve();
}
