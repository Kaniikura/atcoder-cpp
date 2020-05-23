#include <iostream>
#define MAX_N 100000
using namespace std;

int h[MAX_N];
int n, k;

void solve()
{
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (h[i] >= k)
        {
            ans++;
        }
    }

    cout << ans;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    solve();
}
