#include <iostream>
using namespace std;
typedef long long ll;

ll n;

void solve()
{
    cout << (n * (n - 1)) / 2 << endl;
}

int main()
{
    cin >> n;

    solve();
}
