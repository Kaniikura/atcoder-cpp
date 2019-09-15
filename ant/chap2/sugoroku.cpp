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
        y -= (a / b) + x;
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
    int d = extgcd
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
