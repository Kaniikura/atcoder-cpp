#include <iostream>
#include <vector>
#define MAX_V 1000
#define MAX_E 10000
#define INF 10000000
using namespace std;
int V;                            //頂点数
int E;                            //エッジ数
int s[MAX_E], t[MAX_E], c[MAX_E]; //入力用
// 頂点fromから頂点toへのコストcostの辺
struct edge
{
    int from, to, cost;
};
edge es[MAX_E * 2]; //辺
int d[MAX_V];       //ある頂点からの最短距離

//v番目の頂点から各頂点への最短距離を求める
void shortest_path(int v)
{
    for (int i = 0; i < V; i++)
    {
        d[i] = INF; //初期化
    }
    d[v] = 0; //始点は0で初期化
    while (true)
    {
        bool update = false;
        for (int i = 0; i < 2 * E; i++)
        {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost)
            {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if (!update)
            break;
    }
}

void solve()
{
    for (int i = 0; i < E; i++)
    {
        // 無向グラフなので両方向に辺を張る
        es[2 * i].from = s[i];
        es[2 * i].to = t[i];
        es[2 * i].cost = c[i];

        es[2 * i + 1].from = t[i];
        es[2 * i + 1].to = s[i];
        es[2 * i + 1].cost = c[i];
    }

    // 例として点Aから点Gへの最短距離を求める
    shortest_path(0);
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
