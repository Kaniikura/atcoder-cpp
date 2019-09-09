#include <iostream>
#include <algorithm>
#define MAX_V 1000
#define MAX_E 10000
#define INF 10000000
using namespace std;
int V;                            //頂点数
int E;                            //エッジ数
int s[MAX_E], t[MAX_E], c[MAX_E]; //入力用

// (u, v)を張る辺
struct edge
{
    int u, v, cost;
};
edge es[MAX_E];

// UnionFind木
struct UnionFind
{
    int par[MAX_V];  // 親
    int rank[MAX_V]; // 木の深さ

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

// 辺の重みを比較する関数
bool comp(const edge &e1, const edge &e2)
{
    return e1.cost < e2.cost;
}

// 最小全域木のコストを求める
int kruskal()
{
    sort(es, es + E, comp);
    // Union-Find木を初期化
    UnionFind tree(V);
    int res = 0;
    for (int i = 0; i < E; i++)
    {
        edge e = es[i];
        if (!tree.same(e.u, e.v))
        {
            tree.unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

void solve()
{
    for (int i = 0; i < E; i++)
    {
        es[i].u = s[i];
        es[i].v = t[i];
        es[i].cost = c[i];
    }

    // 最小全域木のコスト
    cout << kruskal() << endl;
}

int main()
{
    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        cin >> s[i] >> t[i] >> c[i];
    }

    solve();
}

/* 入力例
7
9
0 1 1
1 2 2
1 4 10
2 3 3
2 5 7
3 5 1
3 6 5
4 5 5
5 6 8

答え 17
*/
