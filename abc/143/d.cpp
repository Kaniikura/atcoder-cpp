#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

ll N;
ll L[4000];

void input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> L[i];
}

void solve()
{
    input();
    vector<ll> v(N);
    for (int i = 0; i < N; i++)
        v[i] = L[i + 1];
    sort(v.begin(), v.end());
    ll ans = 0;
    for (ll mid = N - 1; mid >= 0; mid--)
    {
        for (ll low = mid - 1; low >= 0; low--)
        {
            auto itr = lower_bound(v.begin(), v.end(), v[mid] + v[low]);
            ll ng = distance(itr, v.end());
            ans += (N - 1 - mid) - ng;
            //cerr << v[mid] + v[low] << " " << ng << " " << (N-1-mid)-ng << endl;
        }
    }
    cout << ans << endl;
    return;
}

int main()
{
    solve();
    return 0;
}