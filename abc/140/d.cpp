#include <iostream>
#include <string>
using namespace std;
#define MAX_N 100
typedef long long ll;

int n, k;
string s;

void solve()
{
    int l_cnt = 0;
    int r_cnt = 0;
    char pre = 'c';
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == pre)
        {
            ans++;
        }
        pre = s[i];
    }

    ans += 2 * k;
    ans = min(ans, n - 1);
    cout << ans;
}

int main()
{
    cin >> n >> k;

    cin >> s;

    solve();
}
