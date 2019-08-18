#include <iostream>
#include <cstring>
#define MAX_N 100
#define MAX_K 100000

using namespace std;

int n;
int *a = new int[n];
int *m = new int[n];
int K;
int dp[MAX_K + 1]; // DPテーブル

void solve()
{
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            if (dp[j] >= 0)
            {
                dp[j] = m[i];
            }
            else if (j < a[i] || dp[j - a[i]] <= 0)
            {
                dp[j] = -1;
            }
            else
            {
                dp[j] = dp[j - a[i]] - 1;
            }
        }
    }
    if (dp[K] >= 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    //Input
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    cin >> K;

    solve();
}

/* 入力例
3
3 5 8
3 2 2
17
*/