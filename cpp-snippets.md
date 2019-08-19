# c++のためのスニペット集
## 入出力系
グローバル変数で定義してmainで読み込むやり方が便利<br>
すべてのコードは`#include <iostream>`および`using namespace std;`を省略している
### 入力
#### 整数
1文字
```c++
int n;
int main{
  cin >> n;
}
```
要素数を指定して1行で読み込む
```c++
#define MAX_N 100000
int n;
int a[MAX_N];

int main(){
   cin >> n;
   for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
```

#### 文字列
```c++
#define MAX_S 10
int n;
char s[MAX_S + 1]; //null文字用に1つ長くとる

int main(){
  cin >> n;
  cin >> s;
}
```
stringを使うver
```c++
string s;
int main(){
  cin >> s;
}
```

### 出力
桁数を指定
```c++
double res = 0.123456789012345;
cout << setprecision(10) << res << endl; //精度10桁で出力 -> 0.123456789 
```
### 入出力の速度に困ったら
高速化その１ おまじないを書く
```c++
cin.tie(0);
ios::sync_with_stdio(false);
```
高速化その２ endlの代わりに改行文字を使う
```c++
cout << res << "\n";
```
高速化その３ stdioをつかう
```c++
#include <cstdio>
int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", n);
}
```
## データ構造
### Union-Find木
```c++
#define MAX_N 100000
struct UnionFind
{
    int par[MAX_N];  // 親
    int rank[MAX_N]; // 木の深さ

    // n要素で初期化
    UnionFind(int N)
    {
        for (int i = 0; i < N; i++)
        {
            par[i] = i;
            rank[i] = 0;
        }
    }

    // 木の根を求める
    int find(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }

    // xとyの属する集合を併合
    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;

        if (rank[x] < rank[y])
        {
            par[x] = y;
        }
        else
        {
            par[y] = x;
            if (rank[x] == rank[y])
            {
                rank[x]++;
            }
        }
    }

    // xとyが同じ集合に属するか否か
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};
```
