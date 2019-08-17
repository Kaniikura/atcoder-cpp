#include <iostream>

using namespace std;

int n;
int *w = new int[n];
int *v = new int[n];
int W;

// i番目の品物か重さの和がj以下となるように選ぶ
int rec(int i, int j)
{
    int res;
    if (i == n)
    {
        //品物が残っていない
        res = 0;
    }
    else if (j < w[i])
    {
        res = rec(i + 1, j);
    }
    else
    {
        // 入れる場合と入れない場合を両方試す
        res = max(rec(i + 1, j), v[i] + rec(i + 1, j - w[i]));
    }
    return res;
}

void solve()
{
    cout << rec(0, W) << endl;
}
int main()
{
    //Input
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> W;
    solve();
}

/* 
入力例
4
2 1 3 2
3 2 4 2
5
*/
