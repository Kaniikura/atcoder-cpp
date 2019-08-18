#include <iostream>
#define MAX_N 100000

using namespace std;

int n;
int x[MAX_N];

void solve()
{
    bool f = true;
    int diff;

    if (n == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        for (int i = n - 1; 0 < i; i--)
        {
            diff = x[i] - x[i - 1];
            if (diff <= -2)
            {
                f = false;
                break;
            }
            else if (diff == -1)
            {
                x[i - 1]--;
            }
        }

        if (f)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    solve();
}
