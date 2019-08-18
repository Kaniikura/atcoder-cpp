#include <iostream>

using namespace std;

int a, b, c;

void solve()
{
    int res;
    res = max(c - (a - b), 0);

    cout << res << endl;
}

int main()
{
    cin >> a;
    cin >> b;
    cin >> c;

    solve();
}
