#include <iostream>
#include <string>
using namespace std;

int n;

void solve()
{
    double ans;

    double odd_num = (n + 1) / 2;
    ans = odd_num / n;
    cout << ans;
}

int main()
{
    cin >> n;

    solve();
}
