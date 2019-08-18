#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#define MAX_N 100000

using namespace std;

typedef long long ll;
int n;
string s[MAX_N];
unordered_map<string, int> um;

void solve()
{
    ll res = 0, tmp;
    for (int i = 0; i < n; i++)
    {
        sort(s[i].begin(), s[i].end());
        if (um.count(s[i]))
        {
            tmp = um.at(s[i]) + 1;
            um[s[i]] = tmp;
            res += tmp;
        }
        else
        {
            um.emplace(s[i], 0);
        }
    }

    cout << res << endl;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    solve();
}
