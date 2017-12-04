#include <iostream>

using namespace std;

int main()
{
  int repetitions, n, k, p, result;
  cin >> repetitions;
  for (int i = 1; i <= repetitions; ++i)
  {
    cin >> n >> k >> p;
    result = p % n + k;
    if (result > n)
      result = result - n; 
    cout << "Case " << i << ": " << result << endl;
  }
  return 0;
}
