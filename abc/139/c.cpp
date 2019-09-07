#include <iostream>
#include <string>
using namespace std;
#define MAX_N 100000

int n;
int h[MAX_N];

void solve()
{
    int ans = 0;
    int cnt = 0;
    int pre = 0;

    for (int i = 0; i < n; i++)
    {
        if (pre >= h[i])
        {
            cnt++;
        }
        else
        {
            ans = max(ans, cnt);
            cnt = 0;
        }
        pre = h[i];
    }
    // 最後に最高記録を更新するときもある
    ans = max(ans, cnt);

    cout << ans << endl;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    solve();
}