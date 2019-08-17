#include <iostream>
#include <algorithm>

using namespace std;

int n;
int r;
int *x = new int[n];

void solve()
{
    sort(x, x + n);

    int ans = 0;
    int i = 0;
    while (i < n)
    {
        // sは印を付けられた点から距離rより
        // 離れている点のなかで最も近いもの
        int s = x[i];

        // sから距離rを超えて離れた点まで進む
        while (i < n && x[i] <= s + r)
            i++;

        // pは新しく印をつける点
        int p = x[i - 1];
        // pから距離rを超えて離れた点まで進む
        while (i < n && x[i] <= p + r)
            i++;

        ans++;
    }
    printf("%d\n", ans);
}
int main()
{
    //Input
    cin >> n;
    cin >> r;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    solve();
}

/* 入力例
6
10
1 7 15 20 30 50
*/
