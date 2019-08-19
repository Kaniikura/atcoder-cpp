#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>

#define MAX_N 50

using namespace std;

int n;
double v[MAX_N];

void solve()
{
    double res = 0;
    // 価値の高い順にソート
    sort(v, v + n, greater<int>());
    for (int i = 1; i <= n; i++)
    {
        // 価値の高いものほど混ぜる回数は少ない
        if (i != n)
            res += v[i - 1] / pow(2, i);
        else
            // 最初は生の具材２つを混ぜる
            res += v[n - 1] / pow(2, n - 1);
    }
    cout << setprecision(16) << res << endl;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    solve();
}
