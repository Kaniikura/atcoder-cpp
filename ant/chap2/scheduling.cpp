#include <iostream>
#include <algorithm>

using namespace std;

static const int N_MAX = 100000;
int n;               //仕事数
int *s = new int[n]; // 各仕事の開始時刻
int *t = new int[n]; // 各仕事の終了時刻
pair<int, int> *itv = new pair<int, int>[n];

void solve()
{
    //ソート用にペアを組んでおく
    //終了時刻でソートするためt[i]をfirstにおく
    for (int i = 0; i < n; i++)
    {
        itv[i].first = t[i];
        itv[i].second = s[i];
    }
    sort(itv, itv + n);

    int ans = 0;
    int t_last = 0; //現在最後に選んでいる仕事の終了時刻

    // 貪欲法
    // 選べる仕事で終了時刻が最も早いものを選んでいく
    for (int i = 0; i < n; i++)
    {
        //  終了と開始は重なってはいけない
        if (t_last < itv[i].second)
        {
            ans++;
            t_last = itv[i].first;
        }
    }
    cout << ans << endl;
}

int main()
{
    // Input
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    solve();
}

/* 入力例
5
1 2 4 6 8
3 5 7 9 10
 */
