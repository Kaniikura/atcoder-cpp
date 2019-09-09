#include <iostream>
#define MAX_V 1000
#define MAX_E 10000
#define INF 10000000
using namespace std;
int V;                            //頂点数
int E;                            //エッジ数
int cost[MAX_V][MAX_V];           //cost[u][v]は辺(u,v)のコスト（存在しない場合はINF）
int mincost[MAX_V];               //集合Xからの辺の最小コスト
bool used[MAX_V];                 //頂点iがXに含まれているか
int s[MAX_E], t[MAX_E], c[MAX_E]; //入力用

//s番目の頂点から各頂点への最短距離を求める
int prim()
{
    for (int i = 0; i < V; i++)
    {
        mincost[i] = INF;
        used[i] = false;
    }
    mincost[0] = 0;
    int res = 0;

    while (true)
    {
        int v = -1;
        // Xに属さない頂点のうちXからの辺のコストが最小となる頂点を探す
        for (int u = 0; u < V; u++)
        {
            if (!used[u] && (v == -1 || mincost[u] < mincost[v]))
                v = u;
        }
        if (v == -1)
            break;
        used[v] = true;    // 頂点vをXに追加
        res += mincost[v]; // 辺のコストを加える

        for (int u = 0; u < V; u++)
        {
            // 頂点vに接続されているノードについて最小コストを更新
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    return res;
}

void solve()
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cost[i][j] = INF;
        }
    }
    for (int i = 0; i < E; i++)
    {
        // 無向グラフなので両方向に辺を張る
        cost[s[i]][t[i]] = c[i];
        cost[t[i]][s[i]] = c[i];
    }

    // 最小全域木のコスト
    cout << prim() << endl;
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
