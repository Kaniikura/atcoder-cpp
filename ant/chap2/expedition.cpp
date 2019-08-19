#include <iostream>
#include <queue>
#define MAX_N 10000
using namespace std;

int n, l, p;
int a[MAX_N + 1], b[MAX_N + 1];

void solve()
{
    // 末尾にゴールを追加
    a[n] = l;
    b[n] = 0;
    n++;

    // ガソリンスタンドを管理するキュー
    priority_queue<int> que;

    // ans:補給回数, pos:今いる場所，tank:タンクのガソリン量
    int ans = 0, pos = 0, tank = p;

    for (int i = 0; i < n; i++)
    {
        //次に進む距離
        int d = a[i] - pos;

        //十分な量になるまでキューからガソリンを取り出す
        while (tank - d < 0)
        {
            if (que.empty())
            {
                cout << -1 << endl;
                return;
            }
            else
            {
                tank += que.top();
                que.pop();
                ans++;
            }
        }

        tank -= d;
        pos = a[i];
        que.push(b[i]);
    }

    cout << ans << endl;
}

int main()
{
    cin >> n;
    cin >> l;
    cin >> p;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    solve();
}

/* 入力例
4 25 10
10 14 20 21
10 5 2 4
*/
