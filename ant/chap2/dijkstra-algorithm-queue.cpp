#include <iostream>
#include <vector>
#include <queue>
#define MAX_V 1000
#define MAX_E 10000
#define INF 10000000
using namespace std;
struct edge
{
    int to, cost;
};
typedef pair<int, int> P;         //firstは最短距離，secondは頂点の番号
int V;                            //頂点数
int E;                            //エッジ数
int d[MAX_V];                     //頂点からの最短距離
vector<edge> G[MAX_V];            //エッジ
int s[MAX_E], t[MAX_E], c[MAX_E]; //入力用

//s番目の頂点から各頂点への最短距離を求める
void dijkstra(int s)
{
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d + V, INF);

    d[s] = 0; //始点は0で初期化
    que.push(P(0, s));
    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;
        for (int i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

void solve()
{
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

    // 例として点Aから点Gへの最短距離を求める
    dijkstra(0);
    cout << d[V - 1] << endl;
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
10
0 1 2
0 2 5
1 2 4
1 3 6
1 4 10
2 3 2
3 5 1
4 5 3
4 6 5
5 6 9
*/
