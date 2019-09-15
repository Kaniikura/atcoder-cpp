#include <iostream>
#include <string>
using namespace std;

string s;
bool tf = true;

void solve()
{
    for (int i = 0; i < s.size(); i++)
    {
        if (((i + 1) % 2 == 1) && (s[i] == 'L') || ((i + 1) % 2 == 0) && (s[i] == 'R'))
            tf = false;
    }

    if (tf)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main()
{
    cin >> s;

    solve();
}
