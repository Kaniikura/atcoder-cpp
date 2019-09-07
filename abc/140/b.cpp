#include <iostream>
using namespace std;
#define MAX_N 20

int n;
int a[MAX_N], b[MAX_N], c[MAX_N]; //入力用

void solve()
{
    int pre = -1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += b[a[i] - 1];
        if (a[i] - 1 == pre)
        {
            ans += c[a[i] - 2];
        }

        pre = a[i];
    }

    cout << ans << endl;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> c[i];
    }

    solve();
}
