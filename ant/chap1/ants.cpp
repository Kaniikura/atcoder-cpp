#include <iostream>

using namespace std;

int l;
int n;
int *x = new int[n];

void solve()
{
    // 最小の時間を求める
    int minT = 0;
    for (int i = 0; i < n; i++)
    {
        minT = max(minT, min(x[i], l - x[i]));
    }

    //最大の時間を求める
    int maxT = 0;
    for (int i = 0; i < n; i++)
    {
        maxT = max(maxT, max(x[i], l - x[i]));
    }
    cout << minT << ' ' << maxT << endl;
}
int main()
{
    //Input
    cin >> l;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    solve();
}

/* 入力例
10
3
2 6 7
*/
