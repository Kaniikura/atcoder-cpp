#include <iostream>
#include <vector>
#include <queue>
#define MAX_V 5000
#define MAX_E 100000
#define INF 10000000
using namespace std;
struct edge
{
    int to, cost;
};
typedef pair<int, int> P;         // firstは最短距離，secondは頂点の番号
int V;                            // 頂点数
int E;                            // エッジ数
int dist[MAX_V];                  // 最短距離
int dist2[MAX_V];                 // ２番目の最短距離
vector<edge> G[MAX_V];            // グラフの隣接リスト表現
int s[MAX_E], t[MAX_E], c[MAX_E]; // 入力用

// ２番目の最短路の長さを求める
void solve()
{
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする
    priority_queue<P, vector<P>, greater<P>> que;
    fill(dist, dist + V, INF);
    fill(dist2, dist2 + V, INF);

    dist[0] = 0; //始点は0で初期化
    que.push(P(0, 0));
    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second, d = p.first;
        if (dist2[v] < d)
            continue;
        for (int i = 0; i < G[v].size(); i++)
        {
            edge &e = G[v][i];
            int d2 = d + e.cost; // 頂点vへの最短路or２番目の最短路にv->uをつなげたもの
            if (dist[e.to] > d2)
            {
                swap(dist[e.to], d2);
                que.push(P(dist[e.to], e.to)); // 最短路の更新
            }
            if (dist2[e.to] > d2 && dist[e.to] < d2)
            {
                dist2[e.to] = d2;
                que.push(P(dist2[e.to], e.to)); // ２番目の最短路の更新
            }
        }
    }
    cout << dist2[V - 1] << endl;
}

int main()
{
    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        cin >> s[i] >> t[i] >> c[i];
    }

    for (int i = 0; i < E; i++)
    {
        // 無向グラフなので両方向に辺を張る
        edge e;
        e.to = t[i];
        e.cost = c[i];
        G[s[i]].push_back(e);

        e.to = s[i];
        e.cost = c[i];
        G[t[i]].push_back(e);
    }

    solve();
}

/* 入力例
4
4
0 1 100
1 2 250
1 3 200
2 3 100
*/
