#include "studentName.h"

studentName::studentName(string n)
{
    for(int i=0;i<n.size();++i)
        if(n[i]==' ') spaces++;
    if(spaces<2) chk(n),spaces=2;
    name=n;
}

void studentName::print(){
    cout<<"1)";
    for(int i=0,j=2;i<name.size();++i){
        if(name[i]==' ') cout<<endl<<j<<')',j++;
        else cout<<name[i];
    }
    cout<<endl;
}

void studentName::chk(string &n){
    stringstream s(n);
    vector<string>vec;
    string tmp;
    for(int i=0;i<=spaces;++i){
        s>>tmp;
        if(spaces==1 && i==1) n.push_back(' '),n+=tmp;
        if(spaces==0 ) n.push_back(' '),n+=tmp,n.push_back(' '),n+=tmp;

    }
}

void studentName::rplace(int i,int j){
    vector<string>vec;
    string tmp;
    stringstream s(name);
    for(int i=0,j=0;i<=spaces;++i){
        s>>tmp;
        vec.push_back(tmp);
    }
    if(i>0&&j>0 &&i<=vec.size() &&j<=vec.size()){
        swap(vec[i-1],vec[j-1]);
        cout<<"True \n";
        for(string s:vec) cout<<s<<" ";
        cout<<endl;
    }
    else cout<<"False \n";
}
studentName::~studentName()
{
    //dtor
}
