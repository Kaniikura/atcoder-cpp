#include <iostream>
#define MAX_N 100000
using namespace std;

int a[MAX_N];
int p[MAX_N]; // 持ち点
int n, k, q;

void solve()
{
    // 最初に全員Qマイナスする
    for (int i = 0; i < n; i++)
    {
        p[i] = k - q;
    }
    // 正解者に１点加算
    for (int i = 0; i < q; i++)
    {
        p[a[i] - 1]++;
    }

    // 出力
    for (int i = 0; i < n; i++)
    {
        if (p[i] > 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

int main()
{
    cin >> n >> k >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a[i];
    }

    solve();
}
