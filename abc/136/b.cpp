#include <iostream>

using namespace std;

int n;

void solve()
{
    int d, res = 0;

    for (int i = 1; i <= n; i++)
    {
        d = to_string(i).length(); //桁数
        // 桁数が奇数のとき
        if (d % 2 == 1)
        {
            res++;
        }
    }

    cout << res << endl;
}

int main()
{
    cin >> n;

    solve();
}
