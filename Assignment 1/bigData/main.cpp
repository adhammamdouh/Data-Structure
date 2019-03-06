#include <bits/stdc++.h>
#include "bigDecimalInt.h"

using namespace std;

istream &operator>>(istream &in,bigDecimalInt  b){
    in>>b.num;
    if(b.num[0]=='-'){b.sign='-';b.num.erase(b.num.begin());}
    else b.sign='+';
    return in;
}

ostream &operator<<(ostream &out,const bigDecimalInt b){
    if (b.sign=='-')
        out<<b.sign;
    out<<b.num;
    return out;

}

int main()
{
    bigDecimalInt b("-500"),c=(1),d;
    d=b-c;
    cout<<d<<endl;

     c=b,b=100;
    d=b-c;
    cout<<d<<endl;

    b=100,c=-1;
    d=b+c;
    cout<<d<<endl;

    b=955,c=1;
    d=b+c;
    cout<<d<<" size= "<<d.siz()<<endl;

    b=-228,c=1111;
    d=b+c;
    cout<<d<<endl;
}
