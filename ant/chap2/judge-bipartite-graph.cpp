#include <iostream>
#include <vector>
#define MAX_V 1000
#define MAX_K 10000
using namespace std;
vector<int> G[MAX_V]; //グラフ
int V;                //頂点数
int k;
int s[MAX_K], t[MAX_K];

int color[MAX_V]; //頂点の色

bool dfs(int v, int c)
{
    color[v] = c; //頂点vを色cで塗る
    for (int i = 0; i < G[v].size(); i++)
    {
        // 隣接している頂点が同じ色ならfalse
        if (color[G[v][i]] == c)
            return false;
        // 隣接している頂点が塗られていないとき-cで塗る
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c))
            return false;
    }
    // vとvに隣接する全ての頂点を塗れたらtrue
    return true;
}
void solve()
{
    for (int i = 0; i < k; i++)
    {
        // 無向グラフなので両方向に辺を張る
        G[s[i]].push_back(t[i]);
        G[t[i]].push_back(s[i]);
    }
    for (int i = 0; i < V; i++)
    {
        if (color[i] == 0)
        {
            // まだ頂点iが塗られていなければ1で塗る
            if (!dfs(i, 1))
            {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
}

int main()
{
    cin >> V >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> s[i] >> t[i];
    }

    solve();
}

/* 入力例
その１
3
3
0 1
1 2
2 0

その２
4
4
0 1
1 2
2 3
3 0
*/
