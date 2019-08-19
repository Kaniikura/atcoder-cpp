#include <iostream>
#include <string>

using namespace std;

int a;
string s;

void solve()
{
    if (a >= 3200)
        cout << s << endl;
    else
        cout << "red" << endl;
}

int main()
{
    cin >> a;
    cin >> s;

    solve();
}