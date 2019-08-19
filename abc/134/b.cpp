#include <iostream>

using namespace std;

int n, d;

void solve()
{
    int res, tmp = 2 * d + 1;
    res = (n + tmp - 1) / tmp;
    cout << res << endl;
}

int main()
{
    cin >> n >> d;

    solve();
}