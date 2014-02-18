#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

//暴力移位法
void leftShiftOne(char *s, int n){   //左移一位
  assert(s != NULL);
  char t = s[0];
  for (int i = 1; i < n; i++) {
    s[i - 1] = s[i];
  }
  s[n - 1] = t;
}

void leftShiftM(char *s, int n, int m){  //左移m位
  assert(s != NULL);
  while (m--) {
    leftShiftOne(s, n);
  }
}

//三步翻转
void reverse(char *s, int from, int to){
  while (from < to) {
    char t = s[from];
    s[from++] = s[to];
    s[to--] = t;
  }
}

void leftShift(char *s, int n, int m){
  m %= n;
  reverse(s, 0, m-1);
  reverse(s, m, n-1);
  reverse(s, 0, n-1);
}


int main(int argc, char *argv[]) {
  char str[] = "";
  cin >> str;
  leftShiftM(str, strlen(str), 9);
  cout << str << endl;
  return 0;
}