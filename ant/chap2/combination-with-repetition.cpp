#include <iostream>
#define MAX_N 1000
#define MAX_M 1000

using namespace std;

int n, m;
int *a = new int[n];
int M;
int dp[MAX_N + 1][MAX_M + 1];

void solve()
{
    // 1つも選ばないとき
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            /* 
            i番目までの品物からj個選ぶ場合の数は，i-1番目までからj-k個選んで
            i番目をk個選ぶことをk=0,1,...,min(a[i],j)について考えその総和をとることで
            求められる．ただしこの方法は，３重for文となり計算量が大きい．
            しかしここで，この総和を計算する部分にi番目までの品物からj-1個選ぶ場合の数が
            含まれていることに注目するとdp[i+1][j]の計算にd[i+1][j-1]を再利用できる．
            すなわち，i-1番目までからj-k-1個選んでi番目をk個選ぶことを
            k=0,1,...,min(a[i],j-1)について考えたものについて，(1) 全体としてj個選ぶが
            i番目は含めないときを足して，(2) 全体としてj-1-a[i]個選んだ場合(i番目を
            a[i]個選んでもj個に届かない場合)を引くと漸化式が得られる．
            */
            if (j - 1 - a[i] >= 0)
            {
                (dp[i + 1][j] = dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + M) % M;
            }
            else
            {
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M;
            }
        }
    }
    cout << dp[n][m] << endl;
}

int main()
{
    //Input
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> M;

    solve();
}

/* 入力例
3
3
1 2 3
10000
*/