#include <iostream>
#include <string>
using namespace std;

string s;

void solve()
{
    string ans;
    if (s == "Sunny")
        ans = "Cloudy";
    else if (s == "Cloudy")
        ans = "Rainy";
    else
        ans = "Sunny";
    cout << ans;
}

int main()
{
    cin >> s;

    solve();
}
