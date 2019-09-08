#include <iostream>
#include <vector>
#include <queue>
#define MAX_V 1000
#define MAX_E 100000
#define INF 10000000
using namespace std;

int V;                            //頂点数
int E;                            //エッジ数
int d[MAX_V][MAX_V];              //最短距離
int s[MAX_E], t[MAX_E], c[MAX_E]; //入力用

void warshall_floyd()
{
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void solve()
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else
            {
                d[i][j] = INF;
            }
        }
    }
    for (int i = 0; i < E; i++)
    {
        // 無向グラフなので両方向に辺を張る
        d[s[i]][t[i]] = c[i];
        d[t[i]][s[i]] = c[i];
    }

    // 例として点Aから点Gへの最短距離を求める
    warshall_floyd();
    cout << d[0][V - 1] << endl;
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
