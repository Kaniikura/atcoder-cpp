#include <iostream>
#define MAX_N 100000
using namespace std;

int a[MAX_N];
int b[MAX_N]; // 出席順
int n;

void solve()
{
    for (int i = 0; i < n; i++)
    {
        b[a[i] - 1] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
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
