#include <iostream>
#include <queue>
using namespace std;

static const int INF = 100000000;
static const int MAX_N = 100;
static const int MAX_M = 100;

typedef pair<int, int> P;                         //位置
char maze[MAX_N][MAX_M];                          //迷路
int n, m;                                         //迷路のサイズ
int sx, sy;                                       //スタート地点
int gx, gy;                                       //ゴール地点
int d[MAX_N][MAX_M];                              //各地点からゴールまでの距離
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //移動方向

int bfs()
{
    queue<P> que;
    //dをINFで初期化
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            d[i][j] = INF;
        }
    }
    //スタート地点をキューにいれて距離を0にする
    que.push(P(sx, sy));
    d[sx][sy] = 0;

    while (que.size())
    {
        //キューの先頭を取り出す
        P p = que.front();
        que.pop();
        //ゴールを取り出したらやめる
        if (p.first == gx && p.second == gy)
        {
            break;
        }
        //4近傍を探索
        for (int i = 0; i < 4; i++)
        {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            //移動ができるandまだ訪れたことがないならキューに入れる
            if (0 <= nx && nx < n && 0 <= ny && ny < m & maze[nx][ny] != '#' && d[nx][ny] == INF)
            {
                que.push(P(nx, ny));
                //距離を更新
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
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
            maze[i][j] = tmp[j];
            //スタート地点
            if (maze[i][j] == 'S')
            {
                sx = i, sy = j;
            }
            // ゴール地点
            else if (maze[i][j] == 'G')
            {
                gx = i, gy = j;
            }
        }
    }
    int res = bfs();
    cout << res << endl;
}

/* 入力例
10 10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#
*/