#include <sys/time.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
  vector<int> v;
  for (int i = 1; i <= 1000000; i++) {
    v.push_back(i);
  }
  struct timeval tv;
  gettimeofday(&tv, NULL); 
  cout << "time is " << tv.tv_sec << ":" << tv.tv_usec << endl;
  size_t size = v.size();
  int a = 0;
  for (size_t i = 0; i < size; i++) {
    a = v[i];
  }
  cout << "a:" << a << endl;
  gettimeofday(&tv, NULL); 
  cout << "time is " << tv.tv_sec << ":" << tv.tv_usec << endl;
  a = 0;
  for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
    a = *iter;
  }
  cout << "a:" << a << endl;
  gettimeofday(&tv, NULL); 
  cout << "time is " << tv.tv_sec << ":" << tv.tv_usec << endl;
  a = 0;
  for (auto iter = v.cbegin(); iter != v.cend(); iter++) {
    a = *iter;
  }
  cout << "a:" << a << endl;
  gettimeofday(&tv, NULL); 
  cout << "time is " << tv.tv_sec << ":" << tv.tv_usec << endl;
  
  return 0;
}
