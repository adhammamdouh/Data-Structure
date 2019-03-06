#include <bits/stdc++.h>

using namespace std;
set<string> contain;
void RecPermute(string soFar, string rest){
    if(rest=="") contain.insert(soFar);
    else
    for(int i=0;i<rest.size();++i){
        string next = soFar+rest[i];
        string remaining=rest.substr(0,i)+rest.substr(i+1);
        RecPermute(next,remaining);
    }
}
void ListPermutations(string s){
    RecPermute("",s);
}
int main()
{
    ListPermutations("makka");
    for(auto res:contain) cout<<res<<endl;
}
