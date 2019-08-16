#include <iostream>
#include <stdlib.h>
using namespace std;

int A;                              //支払額
int C[6];                           //各硬貨の枚数
int V[] = {1, 5, 10, 50, 100, 500}; //各硬貨の価値

void solve()
{
    int ans = 0;
    for (int i = 5; i >= 0; i--)
    {
        int t = min(A / V[i], C[i]);
        A -= t * V[i];
        ans += t;
    }
    cout << ans << endl;
}

int main()
{
    // Input
    cin >> A;
    for (int i = 0; i < 6; i++)
    {
        cin >> C[i];
    }

    solve();
}

/* 入力例
支払い額 A
各硬貨の枚数 C_1, c_5, C_10, C_50, C_100, C_500
620
3 2 1 3 0 2 
 */