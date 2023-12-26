#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int compress(vector<char> &chars)
  {
    string answer = "";
    vector<char> answer2;
    int length = chars.size();
    int exist = 1;
    int temp = 0;
    int i = 0;
    int k = 0;
    while (k != length)
    {
      for (i = k; i < length - 1; i++)
      {
        if (chars[i] == chars[i + 1])
        {
          exist++;
        }
        else
        {
          break;
        }
      }

      if (exist == 1)
      {
        answer += chars[k];
        k++;
      }
      else
      {
        answer += chars[k];
        answer += to_string(exist);
        k += exist;
        exist = 1;
      }
    }
    chars = {};
    for (int i = 0; i < answer.length(); i++)
    {
      chars.push_back(answer[i]);
    }
    return answer.size();
  }
};

int main()
{

  int n;
  cin >> n;
  vector<char> chars(n);
  for (int i = 0; i < n; i++)
  {
    cin >> chars[i];
  }
  Solution obj;
  cout << obj.compress(chars) << endl;

  for (char i : chars)
  {
    cout << i << " ";
  }
  return 0;
}