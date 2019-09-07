#include <iostream>
#include <string>
using namespace std;

int a, b;

void solve()
{
    int num_socket = 1;
    int ans = 0;
    while (num_socket < b)
    {
        num_socket += a - 1;
        ans++;
    }

    cout << ans << endl;
}

int main()
{
    cin >> a >> b;

    solve();
}
