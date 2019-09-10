#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_V 20000
#define MAX_R 50000
#define INF 10000000
using namespace std;
// (u, v)を張る辺
struct edge
{
    int u, v, cost;
};
edge es[MAX_R];

int N, M;                         // 男女の人数
int V;                            // 頂点数
int R;                            // エッジ数
int dist[MAX_V];                  // 最短距離
int dist2[MAX_V];                 // ２番目の最短距離
vector<edge> G[MAX_V];            // グラフの隣接リスト表現
int x[MAX_R], y[MAX_R], d[MAX_R]; // 入力用

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
    sort(es, es + R, comp);
    // Union-Find木を初期化
    UnionFind tree(V);
    int res = 0;
    for (int i = 0; i < R; i++)
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
    V = N + M;
    for (int i = 0; i < R; i++)
    {
        es[i] = (edge){x[i], N + y[i], -d[i]};
    }

    // 最小全域木のコスト
    cout << 10000 * V + kruskal() << endl;
}

int main()
{
    cin >> N >> M >> R;

    for (int i = 0; i < R; i++)
    {
        cin >> x[i] >> y[i] >> d[i];
    }

    solve();
}

/* 入力例
5 5 8
4 3 6831
1 3 4583
0 0 6592
0 1 3063
3 3 4975
1 3 2049
4 2 2104
2 2 781

答え 71071
*/
