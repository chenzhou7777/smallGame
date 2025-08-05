#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define random(x) (rand() % x)
using namespace std;

int choose() {
  cout << "请选择难度。1：简单。2: 稍难。3：困难。" << endl;
  int n;
  cin >> n;
  if (n != 1 && n != 2 && n != 3) {
    cout << "输入错误！" << endl;
    choose();
  }
  return n;
}

void game() {
  srand((int)time(0));
  int ans = 0;
  int a = choose();
  switch (a) {
  case 1:
    ans = random(50);
    cout << "请输入 0 到 50 间随机数。" << endl;
    a = 50;
    break;
  case 2:
    ans = random(75);
    cout << "请输入 0 到 75 间随机数。" << endl;
    a = 75;
    break;
  case 3:
    ans = random(100);
    cout << "请输入 0 到 100 间随机数。" << endl;
    a = 100;
    break;
  }
  int n, ci = 0;
  int big = a, small = 0;
  while (1) {
    cin >> n;
    ci++;
    if (n - ans > 15 && n - ans > 0)
      cout << "太大了， 再小点。" << endl;
    if (n - ans <= 15 && n - ans > 0)
      cout << "接近了， 再小点。" << endl;
    if (ans - n > 15 && ans - n > 0)
      cout << "太小了， 再大点。" << endl;
    if (ans - n <= 15 && ans - n > 0)
      cout << "接近了， 再大点。" << endl;
    //
    if (n < big && n > ans)
      big = n;
    else if (n > small && n < ans)
      small = n;
    if (n != ans)
      cout << "正确答案在" << small << "到" << big << "之间" << endl;
    if (n == ans) {
      cout << "恭喜你， 猜对了！您猜了" << ci << "次" << endl;
      if (ci <= 5)
        cout << "您的运气太好了！" << endl;
      else
        cout << "您真棒！" << endl;
      int is;
      cout << "还想再来吗？ 输入 1： 再来一次。 输入 0：结束。" << endl;
      cin >> is;
      if (is == 1) {
        cout << "欢迎回来！" << endl;
        game();
      } else if (is == 0) {
        cout << "欢迎下次再来！" << endl;
        return;
      } else {
        cout << "输入错误！自动退出。" << endl;
        return;
      }
    }
  }
}

void start() {
  cout << "输入 1 ：开始。 输入 0 ：结束。" << endl;
  int n;
  cin >> n;
  if (n == 0) {
    cout << "欢迎下次再来！" << endl;
  } else if (n == 1) {
    game();
  } else {
    cout << "输入错误！" << endl;
    start();
  }
}

int main() {
  cout << "                                                     "
          "欢迎来到猜数游戏！"
       << endl;
  start();
  return 0;
}
