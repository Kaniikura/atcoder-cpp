#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_V 1000
#define MAX_E 10000
#define INF 10000000
using namespace std;
int V;                            //頂点数
int E;                            //エッジ数
int cost[MAX_V][MAX_V];           //辺のコスト
int d[MAX_V];                     //頂点からの最短距離
bool used[MAX_V];                 //すでに使ったことがあるかのフラグ
int preb[MAX_V];                  //最短路における直前の頂点
int s[MAX_E], t[MAX_E], c[MAX_E]; //入力用

//s番目の頂点から各頂点への最短距離を求める
void dijkstra_keep_track(int s)
{
    fill(d, d + V, INF);
    fill(used, used + V, false);
    fill(preb, preb + V, -1);
    d[s] = 0; //始点は0で初期化

    while (true)
    {
        int v = -1;
        // まだ使われていない頂点のうち頂点が最小のものを探す
        for (int u = 0; u < V; u++)
        {
            if (!used[u] && (v == -1 || d[u] < d[v]))
            {
                v = u;
            }
        }

        if (v == -1)
        { // 更新終了
            break;
        }
        used[v] = true;

        for (int u = 0; u < V; u++)
        {
            if (d[u] > d[v] + cost[v][u])
            {
                d[u] = d[v] + cost[v][u];
                preb[u] = v;
            }
        }
    }
}

vector<int> get_path(int t)
{
    vector<int> path;
    for (; t != -1; t = preb[t]) //tがsになるまでprev[t]を辿っていく
        path.push_back(t);
    // このままだとt->sの順になっているので逆にする
    reverse(path.begin(), path.end());
    return path;
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

    // 例として点Aから点Gへの最短距離を求める
    dijkstra_keep_track(0);
    vector<int> ans;
    ans = get_path(V - 1);
    for (vector<int>::const_iterator i = ans.begin(); i != ans.end(); ++i)
        cout << *i << ' ';
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
