#include <iostream>
#include <string>

using namespace std;

int main() {
  int c = 0, len = 0, t = 0;
  string s;
  cin >> c;
  while (c != 0) {
    cin >> s;
    len = s.length();
    t = len/c;
    char buffer[t];
    for (int i = 1; i <= c; ++i) {
      s.copy(buffer,t,c*i);
    }



    cin >> c;
  }
  return 0;
}
