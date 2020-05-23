#include <iostream>
#include <vector>
#define ll long long
#define MAX_N 100000
using namespace std;

ll a, b;
vector<ll> ans;

// 最大公約数
ll euclidean_gcd(ll a, ll b)
{
    return b != 0 ? euclidean_gcd(b, a % b) : a;
}

// 試し割り法による素因数分解
// ただし，素数のべき数は計算しない
vector<ll> prime_factorize(ll N)
{
    vector<ll> res;
    for (ll a = 2; a * a <= N; ++a)
    {
        if (N % a != 0)
            continue;
        // 割れる限り割り続ける
        while (N % a == 0)
        {
            N /= a;
        }

        // その結果を push
        res.push_back(a);
    }

    // 最後に残った数について
    if (N != 1)
        res.push_back(N);
    return res;
}

void solve()
{
    ll n = euclidean_gcd(a, b);

    vector<ll> divs = prime_factorize(n);
    divs.push_back(1); // 1は答えに含まれる

    /*
    for (int i = 0; i < divs.size(); i++)
    {
        cout << divs[i] << " ";
    }
    */
    cout << divs.size();
}

int main()
{
    cin >> a >> b;

    solve();
}
