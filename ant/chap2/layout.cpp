#include <iostream>
#include <vector>
#define MAX_N 1000
#define MAX_ML 10000
#define MAX_MD 10000
#define INF 10000000
using namespace std;
// 入力
int N, ML, MD;
int AL[MAX_ML], BL[MAX_ML], DL[MAX_ML];
int AD[MAX_MD], BD[MAX_MD], DD[MAX_MD];

int d[MAX_N]; // 最短距離
bool updated; // 更新されたか

void update(int &x, int y)
{
    if (x > y)
    {
        x = y;
        updated = true;
    }
}

void bellmanford()
{
    for (int k = 0; k < N; k++)
    {
        updated = false;
        // i+1からiへコスト0
        for (int i = 0; i < N - 1; i++)
        {
            if (d[i + 1] < INF)
            {
                update(d[i], d[i + 1]);
            }
        }
        // ALからBLへコストDL
        for (int i = 0; i < ML; i++)
        {
            if (d[AL[i] - 1] < INF)
            {
                update(d[BL[i] - 1], d[AL[i] - 1] + DL[i]);
            }
        }
        // BDからADへコスト-DD
        for (int i = 0; i < MD; i++)
        {
            if (d[BD[i] - 1] < INF)
            {
                update(d[AD[i] - 1], d[BD[i] - 1] - DD[i]);
            }
        }
    }
}

void solve()
{
    // 負閉路チェック
    fill(d, d + N, 0);
    bellmanford();
    if (updated)
    {
        cout << -1 << endl;
        return;
    }

    fill(d, d + N, INF);
    d[0] = 0;
    bellmanford();
    int res = d[N - 1];
    if (res == INF)
        res = -2;
    cout << res << endl;
}

int main()
{
    cin >> N >> ML >> MD;

    for (int i = 0; i < ML; i++)
    {
        cin >> AL[i] >> BL[i] >> DL[i];
    }

    for (int i = 0; i < MD; i++)
    {
        cin >> AD[i] >> BD[i] >> DD[i];
    }

    solve();
}

/* 入力例
4 2 1
1 3 10
2 4 20
2 3 3
*/
