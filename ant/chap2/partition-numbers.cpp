#include <iostream>
#define MAX_N 1000
#define MAX_M 1000

using namespace std;

int n, m;
int M;
int dp[MAX_N + 1][MAX_M + 1];

void solve()
{
    dp[0][0] = 1;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j - i >= 0)
                // nのm分割の要素a_i (i =1,2,...,m)に対して
                // 全てのa_iが1以上のときn-mのm分割からつくることができ(a_i-1を考える)
                // 逆にa_i=0なるiが1つ存在すれば，これはnのm-1分割から作成できる
                dp[i][j] = (dp[i - 1][j] + dp[i][j - i]) % M;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[m][n] << endl;
}

int main()
{
    //Input
    cin >> n;
    cin >> m;
    cin >> M;

    solve();
}

/* 入力例
4
3
10000
*/