#include <iostream>

using namespace std;

int k, x;

void solve()
{
    // 黒で塗られている可能性のある座標で最大と最小のもの
    int ma, mi;
    ma = x + k - 1;
    mi = x - k + 1;
    for (int i = mi; i <= ma; i++)
    {
        cout << i << ' ';
    }
    cout << endl;
}

int main()
{
    cin >> k;
    cin >> x;
    solve();
}