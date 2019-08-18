#include <iostream>
#define MAX_N 100
#define MAX_V 100
#define INF 10000000

using namespace std;

int n;
int *w = new int[n];
int *v = new int[n];
int W;
int dp[MAX_N + 1][MAX_N * MAX_V + 1]; // DPテーブル

// 同じ価値に対して最小の重さを計算していく
void solve()
{
    fill(dp[0], dp[0] + MAX_N * MAX_V + 1, INF);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= MAX_N * MAX_V; j++)
        {
            if (j < v[i])
            {
                dp[i + 1][j] = dp[i][j];
            }
            else
            {
                dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
            }
        }
    }
    int res = 0;
    // 重さがW以下のなかで最大のjが答え
    for (int j = 0; j <= MAX_N * MAX_V; j++)
        if (dp[n][j] <= W)
            res = j;
    cout << res << endl;
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