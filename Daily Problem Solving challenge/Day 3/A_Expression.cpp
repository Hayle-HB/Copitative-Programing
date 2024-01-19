#include <iostream>
#include <algorithm>

using namespace std;

int findMax(int a, int b, int c)
{
  return max(
      {a + b + c,
       a * b * c,
       a + (b * c),
       (a + b) * c,
       a * (b + c),
       (a * b) + c});
}
int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  cout << findMax(a, b, c) << endl;
  return 0;
}
