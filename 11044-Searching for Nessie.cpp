#include <iostream>

using namespace std;

int main()
{
  int testcases, rows, columns, rowmod, colmod, minsonar;
  cin >> testcases;
  for(int i = 0; i < testcases; ++i)
  {
    cin >> rows >> columns;
    rowmod = rows / 3;
    colmod = columns / 3;
    minsonar = rowmod * colmod;
    cout << minsonar << endl;
  }
  return 0;
}
