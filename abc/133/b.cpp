#include <iostream>
#define MAX_N 10
#define MAX_D 10
using namespace std;
int n, d, x[MAX_N][MAX_D];

void solve()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int norm = 0;
            for (int k = 0; k < d; k++)
            {
                int diff = abs(x[i][k] - x[j][k]);
                norm += diff * diff;
            }
            for (int k = 0; k <= norm; k++)
            {
                if (k * k == norm)
                {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    cin >> n >> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> x[i][j];
        }
    }

    solve();
}
