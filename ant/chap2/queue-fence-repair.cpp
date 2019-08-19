#include <iostream>
#include <queue>
#define MAX_N 20000
typedef long long ll;
using namespace std;

int n;
int l[MAX_N];

void solve()
{
    ll ans = 0;
    // 小さいほうから出てくる順位キュー
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 0; i < n; i++)
    {
        que.push(l[i]);
    }

    // 最も小さい板２つを取り出し
    // 長さがその和となる板を新たに追加
    while (que.size() > 1)
    {
        int l1, l2;
        l1 = que.top();
        que.pop();
        l2 = que.top();
        que.pop();

        ans += l1 + l2;
        que.push(l1 + l2);
    }

    cout << ans << endl;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }

    solve();
}

/* 入力例
3
8 5 8
*/
