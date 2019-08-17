#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int *k = new int[n];
int *kk = new int[n * n]; //２つで作れる数を格納する配列

bool binary_search(int x)
{
    // 探索範囲は 区間[l,r)
    int l = 0, r = n * n;

    // 見つかるor何もなくなるまで繰り返す
    while (r - l >= 1)
    {
        int i = (l + r) / 2;
        if (kk[i] == x)
            return true;
        // 右区間を探しに行く
        else if (kk[i] < x)
            l = i + 1;
        // 左区間を探しに行く
        else
            r = i;
    }

    // 見つからなかった
    return false;
}

void solve()
{
    // k[c] + k[d]の取りうる数を列挙
    for (int c = 0; c < n; c++)
    {
        for (int d = 0; d < n; d++)
        {
            kk[c * n + d] = k[c] + k[d];
        }
    }
    //二分探索のためにソート
    sort(kk, kk + n * n);

    bool f = false;
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            if (binary_search(m - k[a] - k[b]))
            {
                f = true;
            }
        }
    }
    if (f)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    //Input
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }

    solve();
}

/* 
入力例１
3
10
1 3 5

入力例２
3
9
1 3 5
*/
