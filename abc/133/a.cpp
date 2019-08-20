#include <iostream>
using namespace std;
int n, a, b;

void solve()
{
    cout << min(a * n, b) << endl;
}

int main()
{
    cin >> n >> a >> b;

    solve();
}