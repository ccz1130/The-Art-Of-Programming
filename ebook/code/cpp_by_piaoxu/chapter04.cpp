#include <iostream>
#include <algorithm>

#define Pair pair<int, int>

using namespace std;

//代码一
Pair findNum_1(int *s, int n, int x) {
  //sort(s, s+n);   如果数组无序，则先排序，O(n)
  int *begin = s;
  int *end = s + n - 1;
  
  while(begin < end) {   //两头夹逼，或称两个指针两端扫描法，很经典的方法， O(n)
    if (*begin + *end > x) {
      end--;
    }
    else if (*begin + *end < x){
      begin++;
    }
    else {
      return Pair(*begin, *end);
    }
  }
  return Pair(-1, -1);
}

//代码二
bool findNum_2(int data[], unsigned int length, int sum, int& firshNum, int& secondNum) {
  if (length < 1)
    return true;
  int begin = 0;
  int end = length - 1;
  
  while(begin < end) {
    long currentSum = data[begin] + data[end];
    
    if(currentSum == sum) {
      firshNum = data[begin];
      secondNum = data[end];
      return true;
    }
    else if(currentSum > sum)
      end--;
    else
      begin++;
  }
  return false;
}

int main(int argc, char *argv[]) {
  int s[] = {1, 2, 3, 4, 7, 11, 15};
  cout << findNum_1(s, 7, 15).first << " " << findNum_1(s, 7, 15).second << endl;
  
  int firstNum = -1, secondNum = -1;
  cout << findNum_2(s, 7, 15, firstNum, secondNum) << " " << firstNum << " " << secondNum << endl;
  return 0;
}