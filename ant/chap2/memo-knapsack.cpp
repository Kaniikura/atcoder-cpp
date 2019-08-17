#include <iostream>
#include <cstring>
#define MAX_N 100
#define MAX_W 100

using namespace std;

int n;
int *w = new int[n];
int *v = new int[n];
int W;
int dp[MAX_N + 1][MAX_W + 1]; // メモ化テーブル

int rec(int i, int j)
{
    if (dp[i][j] >= 0)
    {
        // すでに調べたことがあれば結果を再利用
        return dp[i][j];
    }
    int res;
    if (i == n)
        res = 0;
    else if (j < w[i])
        res = rec(i + 1, j);
    else
        res = max(rec(i + 1, j), v[i] + rec(i + 1, j - w[i]));
    // 結果を保存
    return dp[i][j] = res;
}

void solve()
{
    // まだ調べていないことを表す-1でメモ化テーブルを初期化
    memset(dp, -1, sizeof(dp));
    cout << rec(0, W) << endl;
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
