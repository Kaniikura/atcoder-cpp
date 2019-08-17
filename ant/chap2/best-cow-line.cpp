#include <iostream>
#include <algorithm>

using namespace std;

int n;
char *s = new char[n + 1];

void solve()
{
    //現在残っている文字列をs[a],s[a+1],...,s[b]とする
    int a = 0, b = n - 1;

    //文字列sと，逆順に並べたs_invとを比較して
    //小さい方の先頭にある文字を取り出す
    while (a <= b)
    {
        bool left = false;
        for (int i = 0; a + i <= b; i++)
        {
            if (s[a + i] < s[b - i])
            {
                left = true;
                break;
            }
            else if (s[a + i] > s[b - i])
            {
                left = false;
                break;
            }
        }
        if (left)
        {
            putchar(s[a++]);
        }
        else
        {
            putchar(s[b--]);
        }
    }
    putchar('\n');
}
int main()
{
    //Input
    cin >> n;
    cin >> s;

    solve();
}

/* 入力例
6
ACDBCB
*/