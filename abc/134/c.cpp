#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX_N 200000
#define MAX_A 200000
using namespace std;

int n, a[MAX_N];

void solve()
{
    int ma1 = 0, ma2 = 0; // 最も大きな値２つ
    int count = 0;        // 最大値のカウンター
    for (int i = 0; i < n; i++)
    {
        if (a[i] > ma2)
        {
            if (a[i] > ma1)
            {
                swap(ma1, ma2);
                ma1 = a[i];
                count = 1;
            }
            else if (a[i] == ma1)
            {
                count++;
            }
            else
            {
                ma2 = a[i];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == ma1 && count == 1)
        {
            // a[i]そのものが最大値であるとき
            cout << ma2 << endl;
        }
        else
        {
            cout << ma1 << endl;
        }
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    solve();
}
