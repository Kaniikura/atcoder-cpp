#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
int n;
int *l = new int[n];

void solve()
{
    ll ans = 0;

    //板が一本になるまでループ
    while (n > 1)
    {
        // 一番短い板2つが二分木の
        // 一番深い葉にくるように取る貪欲法
        int mi1 = 0, mi2 = 1;
        // 一番小さい板をmi1,二番目をmi2とする
        if (l[mi1] > l[mi2])
            swap(mi1, mi2);
        // mi1,mi2を探す
        for (int i = 2; i < n; i++)
        {
            if (l[i] < l[mi1])
            {
                mi2 = mi1;
                mi1 = i;
            }
            else if (l[i] < l[mi2])
            {
                mi2 = i;
            }
        }

        // mi1,mi2を結合して一本にする
        int t = l[mi1] + l[mi2];
        ans += t;

        // t(=mi1+mi2)をl[mi1]に代入し，
        // またl[mi2]を配列の最後に置いて
        // n--;することで探索対象から外す
        if (mi1 == n - 1)
            swap(mi1, mi2);
        l[mi1] = t;
        l[mi2] = l[n - 1];
        n--;
    }
    cout << ans << endl;
}

int main()
{
    //Input
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