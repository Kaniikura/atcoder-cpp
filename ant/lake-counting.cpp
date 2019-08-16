#include <iostream>
using namespace std;

static const int MAX_N = 100;
static const int MAX_M = 100;
char field[MAX_N][MAX_M];
int n, m;

void dfs(int x, int y)
{
    // 現在いる場所を"."に置き換える
    field[x][y] = '.';

    // 8近傍に対して探索し，
    // 水たまりがあるなら続行，なければ中断
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            int nx = x + dx, ny = y + dy;
            if (0 <= nx && nx < n && 0 <= ny && ny < m && field[nx][ny] == 'W')
            {
                dfs(nx, ny);
            }
        }
    }
}

void solve()
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (field[i][j] == 'W')
            {
                dfs(i, j);
                res++;
            }
        }
    }
    cout << res << endl;
}

int main()
{
    cin >> n >> m;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        for (int j = 0; j < m; j++)
        {
            field[i][j] = tmp[j];
        }
    }
    solve();
}

/* 入力例
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
 */
