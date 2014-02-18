#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//暴力轮询
//O(nm)
bool compare_1(string &a, string &b) {
  for (int i = 0; i < b.length(); i++) {
    int j;
    for (j = 0; (j < a.length()) && (a[j] != b[i]); j++) {
      ;
    }
    if (j > a.length()){
      return false;
    }
  }
  return true;
}

//普通排序(先对两个字符串排序，然后同时对两个字符串轮询)
//O(mlogm)+O(nlogn)+O(m+n), 随字符串增长，该算法效果越来越好
bool compare_2(string &a, string &b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int pa = 0, pb = 0; pb < b.length(); ) {
    while ((pa < a.length()) && (a[pa] < b[pb])) {
      pa++;
    }
    if ((pa >= a.length()) || (a[pa] > b[pb])) {
      return false;
    }
    pb++;
  }
  return true;
}

//计数比较
//O(m+n)
bool compare_3(string &a, string &b) {
  vector<int> have;
  have.resize(26,0);
  for (int i = 0; i < a.length(); i++) {
    ++have[a[i] - 'A'];
  }
  for (int i = 0; i < b.length(); i++) {
    if (have[b[i] - 'A'] == 0){
      return false;
    }
  }
  return true;
}

//巧用hashtable
//O(m+n)
bool compare_4(string &a, string &b) {
  vector<int> hash;
  hash.resize(26, 0);
  int m = 0;
  for (int i = 0; i < b.length(); i++) {
    int x = b[i] - 'A';
    if (hash[x] == 0) {
      hash[x] = 1;
      m++;
    }
  }
  for (int i = 0; i < a.length(); i++) {
    int x = a[i] - 'A';
    if (hash[x] == 1) {
      m--;
      hash[x] = 0;
    }
  }
  return m == 0;
}

//素数相乘
//O(m+n),最好情况O(n), 但容易造成整数溢出(只有理论意义)
bool compare_5(string &a, string &b) {
  const int p[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
  int f = 1;
  for (int i = 0; i < a.length(); i++) {
    int x = p[a[i] - 'A'];
    if (f % x) {
      f *= x;
    }
  }
  for (int i = 0; i < b.length(); i++) {
    int x = p[b[i] - 'A'];
    if (f % x) {
      return false;
    }
  }
  return true;
}

//位运算
//对字符串A, 用位运算(26bit整数表示)计算出一个“签名”， 再用B中的字符到A里面查找。
//"最好的方法",时间复杂度O(n+m), 空间复杂度O(1)
bool compare_6(string &a, string &b) {
  int hash = 0;
  for (int i = 0; i < a.length(); i++) {
    hash |= (1 << (a[i] - 'A'));
  }
  for (int i = 0; i < b.length(); i++) {
    if ((hash & (1 << (b[i] - 'A'))) == 0) {
      return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  return 0;
}