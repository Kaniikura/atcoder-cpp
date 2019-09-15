#include <iostream>
#include <queue>
#define MAX_N 100000
#define MAX_M 100000
typedef long long ll;
using namespace std;

int n, m;
int a[MAX_N];

void solve()
{
    ll ans = 0;
    // 大きいほうから出てくる順位キュー
    priority_queue<int, vector<int>, less<int>> que;
    for (int i = 0; i < n; i++)
    {
        que.push(a[i]);
    }

    // 最も大きいものを取り出し
    // 2で割った商を切り捨てたものを追加
    for (int i = 0; i < m; i++)
    {
        int p;
        p = que.top();
        que.pop();

        // 割引券を使う
        p /= 2;
        que.push(p);
    }

    while (!que.empty())
    {
        int p;
        p = que.top();
        que.pop();
        ans += p;
    }

    cout << ans << endl;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    solve();
}

/* 入力例
3
8 5 8
*/
