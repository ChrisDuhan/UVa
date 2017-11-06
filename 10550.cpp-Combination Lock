#include <iostream>

using namespace std;

int main()
{
  int s, c1, c2, c3;
  
  while (cin >> s >> c1 >> c2 >> c3 && !(s == 0 && c1 == 0 && c2 == 0 && c3 == 0))
  {
    int deg = 1080;
    deg += (40 + s - c1) % 40 * 9;
    deg += (40 - c1 + c2) % 40 * 9;
    deg += (40 + c2 - c3) % 40 * 9;
    
    cout << deg << endl;
  }
  cout << endl;
  return 0;
}
