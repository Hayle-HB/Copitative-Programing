#include <iostream>

using namespace std;

bool isPlendrome(string str)
{
  for (int i = 0; i < str.length() / 2; i++)
  {
    if (str[i] != str[str.length() - i - 1])
    {
      return false;
    }
  }
  return true;
}
int main()
{

  string str;
  cin >> str;

  if (isPlendrome(str))
  {
    cout << str << " is Plendrome" << endl;
  }
  else
  {
    cout << str << " is not Plendrome" << endl;
  }

  return 0;
}