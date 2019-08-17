#include <iostream>
#define MAX_N 100
#define MAX_M 100

using namespace std;

int n, m;
char *s = new char[n + 1], *t = new char[m + 1];
int dp[MAX_N + 1][MAX_M + 1];

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i] == t[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    cout << dp[n][m] << endl;
}
int main()
{
    cin >> n;
    cin >> m;
    cin >> s;
    cin >> t;

    solve();
}

/* 入力例
4
4 
abcd
becd
*/