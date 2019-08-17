#include <iostream>
#define MAX_N 100
#define MAX_W 100

using namespace std;

int n;
int *w = new int[n];
int *v = new int[n];
int W;
int dp[MAX_N + 1][MAX_W + 1]; // DPテーブル

void solve()
{
    // DPテーブルは0で初期化されている
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= W; j++)
        {
            if (j < w[i])
            {
                dp[i][j] = dp[i + 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[0][W] << endl;
}

int main()
{
    //Input
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> W;

    solve();
}

/* 
入力例
4
2 1 3 2
3 2 4 2
5
*/
