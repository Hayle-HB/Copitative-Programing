#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;


int max_substring_with_no_repeat_char(string str){
    unordered_map<char, int> IndexMap;
    int maxLen = 0;
    int start = 0;

    for (int end =0; end < str.length(); end++){
        if(IndexMap.find(str[end]) != IndexMap.end()){
            start = max(IndexMap[str[end]], start);
        }
        IndexMap[str[end]] = end;
        maxLen = max(maxLen, end-start+1);
    }
    return maxLen;
}


int main(){

    string str = "aathisabbb";
    cout << "Max Len: " << max_substring_with_no_repeat_char(str);


    return 0;
}