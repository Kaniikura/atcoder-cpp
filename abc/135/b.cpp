#include <iostream>
#include <algorithm>
#include <memory.h>
#define MAX_N 50

using namespace std;

int n;
int p[MAX_N], p_copy[MAX_N];

void solve()
{
    int count = 0;
    memcpy(p_copy, p, sizeof(p));
    sort(p, p + n);
    for (int i = 0; i < n; i++)
    {
        if (p[i] != p_copy[i])
            count++;
    }
    if (count == 0 || count == 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    solve();
}
