#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution{
  public:
      bool isValidSudoku(vector<vector<string>> sudo){
              vector<string> test_raw;
      vector<string> test_col;

      for(int i =0;  i < 9; i++){
        
        for(int j = 0; j < 9; j++){
          if(sudo[i][j] >= "0" && sudo[i][j] <= "9"){
          test_raw.push_back(sudo[i][j]);
          }

          if(sudo[i][j] >= "0" && sudo[i][j] <= "9"){
          test_raw.push_back(sudo[i][j]);
          }
          if(sudo[j][i] >= "0" && sudo[j][i] <= "9"){
          test_col.push_back(sudo[j][i]);
          }

        }

          cout << "Raw : ";
          printEach(test_raw); 
          cout << endl;
          printEach(test_col);
        if(!valid_elements(test_raw)){
          return false;
          break;
        }

        if(!valid_elements(test_col)){
          return false;
          break;
            }
        test_col = {};
        test_raw = {};
      }
      }


    bool valid_elements(vector<string> elements){
        for (int i = 0; i < elements.size(); i++){
          for(int j = i + 1; j < elements.size(); j++){
            if( elements[i] == elements[j]){
              return false;
            }
          }
        }
        return true;
    }

    void printEach(vector<string> str){
      for(string s: str){
        cout << s << "  ";
      }
      cout << endl;
    }


};



int main(){

  vector<vector<string>> sudoku = {
    {"5","3",".",        ".","7",".",        ".",".","."},
    {"6",".",".",        "1","9","5",        ".",".","."},
    {".","9","8",        ".",".",".",        ".","6","."},

    {"8",".",".",        ".","6",".",        ".",".","3"},
    {"4",".",".",        "8",".","3",        ".",".","1"},
    {"7",".",".",        ".","2",".",        ".",".","6"},

    {".","6",".",        ".",".",".",        "2","8","."},
    {".",".",".",        "4","1","9",        ".",".","5"},
    {".",".",".",        ".","8",".",        ".","7","9"}
    };


  bool isSudoku = Solution().isValidSudoku(sudoku);

  cout << isSudoku;














}