#include <iostream>

using namespace std;

int n;
int *a = new int[n];
int *dp = new int[n]; // DPテーブル

void solve()
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        // 初期値は１
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            // dp[i]は最後がa[i]であるようなISの長さを表す
            // a[j]<a[i]であるようなdp[j]に1を足したものの中で
            // 最大の値にdp[i]を更新していく
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
}

int main()
{
    //Input
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    solve();
}

/* 入力例
5
4 2 3 1 5
*/