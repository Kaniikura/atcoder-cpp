#include <iostream>
#include <string>
using namespace std;

int n;

void solve()
{
    string ans = "No";
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (i * j == n)
                ans = "Yes";
        }
    }

    cout << ans;
}

int main()
{
    cin >> n;

    solve();
}
#include <iostream>
#include <string>
using namespace std;

int n;

void solve()
{
    string ans = "No";
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (i * j == n)
                ans = "Yes";
        }
    }

    cout << ans;
}

int main()
{
    cin >> n;

    solve();
}