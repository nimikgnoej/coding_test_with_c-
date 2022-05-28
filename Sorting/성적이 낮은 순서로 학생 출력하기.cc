#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<pair<string,int>> info;

bool comp(pair<string,int> &cp1, pair<string,int> &cp2){
  return cp1.second < cp2.second;
}

int main() {
  int n;
  cin>>n;
  while(n--){
    string str;
    int score;
    cin>>str>>score;
    info.push_back(make_pair(str,score));
  }

  sort(info.begin(),info.end(),comp);
  for(int i=0;i<info.size();i++){
    cout<<info[i].first<<" ";
  }
}