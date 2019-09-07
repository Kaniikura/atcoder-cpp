#include <iostream>
using namespace std;
#define MAX_N 100
typedef long long ll;

int n;
int a[MAX_N];
int b[MAX_N]; //入力用

void solve()
{
    ll ans = 0;
    // 最初と最後は確定
    ans += b[0];
    ans += b[n - 2];

    int comp = b[0];

    for (int i = 1; i < n - 1; i++)
    {
        if (b[i] < comp)
        {
            ans += b[i];
        }
        else
        {
            ans += comp;
        }

        comp = b[i];
    }

    cout << ans << endl;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> b[i];
    }

    solve();
}
