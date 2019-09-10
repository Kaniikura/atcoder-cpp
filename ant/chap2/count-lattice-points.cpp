#include <iostream>
using namespace std;
// 入力
int x1, x2, y1, y2;

// ユークリッドの互除法
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve()
{
    int nx = abs(x1 - x2);
    int ny = abs(y1 - y2);
    int res = gcd(nx, ny) - 1;
    cout << res << endl;
}

int main()
{
    cin >> x1 >> y1 >> x2 >> y2;

    solve();
}

/* 入力例
1 11
5 3

答え
3
*/
