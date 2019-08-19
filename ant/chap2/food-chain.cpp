#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define MAX_K 100000
#define MAX_N 50000
using namespace std;
int n, k;
int T[MAX_K], X[MAX_K], Y[MAX_K];

struct UnionFind
{
    int par[MAX_N];  // 親
    int rank[MAX_N]; // 木の深さ

    // n要素で初期化
    UnionFind(int N)
    {
        for (int i = 0; i < N; i++)
        {
            par[i] = i;
            rank[i] = 0;
        }
    }

    // 木の根を求める
    int find(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }

    // xとyの属する集合を併合
    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;

        if (rank[x] < rank[y])
        {
            par[x] = y;
        }
        else
        {
            par[y] = x;
            if (rank[x] == rank[y])
            {
                rank[x]++;
            }
        }
    }

    // xとyが同じ集合に属するか否か
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};

void solve()
{
    // Union-Find木を初期化
    UnionFind tree(3 * n);
    int ans = 0;

    for (int i = 0; i < k; i++)
    {
        int t = T[i];
        int x = X[i] - 1, y = Y[i] - 1; // 0,...,N-1の範囲にする

        // 番号が不適なため条件が正しくないとき
        if (x < 0 || n <= x || y < 0 || n <= y)
        {
            ans++;
            continue;
        }

        if (t == 1)
        {
            // tは「xとyが同じ」という情報
            if (tree.same(x, y + n) || tree.same(x, 2 * y + n))
            {
                ans++;
            }
            else
            {
                tree.unite(x, y);
                tree.unite(x + n, y + n);
                tree.unite(x + 2 * n, y + 2 * n);
            }
        }
        else
        {
            // tは「xがyを食べる」という情報
            if (tree.same(x, y) || tree.same(x, 2 * y + n))
            {
                ans++;
            }
            else
            {
                tree.unite(x, y + n);
                tree.unite(x + n, y + 2 * n);
                tree.unite(x + 2 * n, y);
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> T[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> X[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> Y[i];
    }

    solve();
}

/* 入力例
100 7
1 2 2 2 1 2 1
101 1 2 3 1 3 5
1 2 3 3 3 1 5
*/
