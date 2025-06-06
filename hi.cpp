#include<iostream>
using namespace std;

int getTrib(int n) {
  if (n == 0 || n==1)
    return 0;

  if (n == 2)
    return 1;

  return getTrib(n - 1) + getTrib(n - 2) + getTrib(n - 3);
}

int main() {

  int n;
  cin >> n;

  cout << getTrib(n);
}