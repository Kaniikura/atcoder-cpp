#include <iostream>
using namespace std;
#define MAX_N 1000
// 入力
int h, w, a, b;
int ans[MAX_N][MAX_N];

void solve()
{
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
        {
            ans[i][j] = 1;
        }
    }
    for (int i = b; i < h; i++)
    {
        for (int j = a; j < w; j++)
        {
            ans[i][j] = 1;
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

int main()
{
    cin >> h >> w >> a >> b;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            ans[i][j] = 0;
        }
    }

    solve();
}
