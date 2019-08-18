#include <iostream>

using namespace std;

int a, b;

void solve()
{
    int res;
    res = max(a + b, max(a - b, a * b));
    cout << res << endl;
}

int main()
{
    cin >> a;
    cin >> b;
    solve();
}