#include <iostream>
using namespace std;
// 入力
int a, b;

// 拡張ユークリッドの互除法
int extgcd(int a, int b, int &x, int &y)
{
    int d = a;
    if (b != 0)
    {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else
    {
        x = 1;
        y = 0;
    }
    return d;
}

void solve()
{
    int x, y;
    int d = extgcd(a, b, x, y);

    if (d == 1)
    {
        if (x >= 0)
        {
            cout << abs(x) << 0;
        }
        else
        {
            cout << 0 << abs(x);
        }
        if (y >= 0)
        {
            cout << abs(y) << 0 << endl;
        }
        else
        {
            cout << 0 << abs(y) << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    cin >> a >> b;

    solve();
}

/* 入力例
4 11

答え
3 0 0 1
*/
