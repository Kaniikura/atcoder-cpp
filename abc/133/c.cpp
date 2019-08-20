#include <iostream>
#define Y 2019
using namespace std;
int l, r, a[Y];

void solve()
{
    int ans = Y - 1;
    int ceil = min(Y - 1, r - l);
    for (int i = 0; i <= ceil; i++)
    {
        a[i] = (l + i) % Y;
    }
    for (int i = 0; i < ceil; i++)
    {

        for (int j = i + 1; j <= ceil; j++)
        {
            ans = min(ans, (a[i] * a[j]) % 2019);
        }
    }

    cout << ans << endl;
}

int main()
{
    cin >> l >> r;

    solve();
}
