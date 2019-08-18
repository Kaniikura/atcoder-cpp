#include <iostream>

using namespace std;

int a, b;

void solve()
{
    int k;
    if ((a + b) % 2 == 0)
    {
        k = abs((a + b) / 2);
        cout << k << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;
}

int main()
{
    cin >> a;
    cin >> b;

    solve();
}
