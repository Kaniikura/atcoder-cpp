# c++のためのスニペット集
## 入出力系
グローバル変数で定義してmainで読み込むやり方が便利<br>
すべてのコードは先頭の#include \<iostream\>を省略している
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
int n;
int *a = new int[n];

int main(){
   cin >> n;
   for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
```

#### 文字列
要素数を指定して読み込む
```c++
int n;
char *s = new char[n + 1]; //null文字用に1つ長くとる

int main(){
  cin >> n;
  cin >> s;
}
```
stringを使うver
```c++
using namespace std;
string s;
int main(){
  cin >> s;
}
```
