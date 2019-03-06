#include "bigDecimalInt.h"

bigDecimalInt::bigDecimalInt(string number){
    while(!valid(number)){
        cout<<"enter valid number : ";
        cin>>number;
    }
    if(number[0]=='-') number.erase(number.begin()),sign='-';
    else sign='+';
    num=number;
}

bool bigDecimalInt::valid(string s){
    for(int i=1;i<s.size();++i)
        if(s[i]<'0' || s[i]>'9') return 0;
    if(s[0]!='-'  &&(s[0]<'0' ||s[0]>'9')) return 0;
    return 1;
}

bigDecimalInt::bigDecimalInt(int number){
    if (number<0) sign='-';
    else sign='+';
    stringstream buffer;
    buffer<<number;
    num=buffer.str();
    if(num[0]=='-') num.erase(num.begin());

}

bigDecimalInt::bigDecimalInt(){

}

void bigDecimalInt::noExtraZero(){
    for(int i=0;i<num.size();++i){
        if(num[i]=='0') num.erase(num.begin()),i--;
        else if(num[i]=='-') continue;
    else break;
    }
}

bigDecimalInt bigDecimalInt::operator+(bigDecimalInt b){
    if(this->sign != b.sign){
        if(this->sign=='-'){
            bigDecimalInt big2=*this;
            big2.sign='+';
            return b-big2;
        }
        if(b.sign=='-'){
            bigDecimalInt big2=b;
            big2.sign='+';
            return *this-big2;
        }
    }
    bigDecimalInt b1,b2,res;
    string data;
    b1=*this;
    b2=b;

    reverse(b1.num.begin(),b1.num.end());
    reverse(b2.num.begin(),b2.num.end());

    for(int i=b1.num.size();i<b2.num.size();++i)
        b1.num[i]='0';
    for(int i=b2.num.size();i<b1.num.size();++i)
        b2.num[i]='0';

    int carry=0,sum=0;
    for(int i=0;i<b1.num.size();++i){
        sum=((b1.num[i]-48)+(b2.num[i]-48)+carry);
        carry=sum/10;
        sum%=10;
        res.num+=char(sum+'0');
    }
    if(carry ==1) res.num+=('1');
    reverse(res.num.begin(),res.num.end());
    res.sign=this->sign;
    return res;
}

bigDecimalInt bigDecimalInt::operator-(bigDecimalInt b){
    if(this->sign != b.sign){
        if (this->sign=='-'){
            bigDecimalInt big2;
            big2=b;
            big2.sign='-';
            return *this+big2;
        }
        if (this->sign!='-'){
            bigDecimalInt big2;
            big2=b;
            big2.sign='+';
            return *this+big2;
        }
    }
    (b.sign=='-')?b.sign='+':b.sign='-';
    bigDecimalInt bigNum,smalNum,res;
    if(b.num==this->num ){
        res.num="0";
        res.sign='+';
        return res;
    }

    this->noExtraZero();
    b.noExtraZero();

    if(b.num.size()>this->num.size()){
        bigNum=b;
        smalNum=*this;

    }
    else if(b.num.size()<this->num.size()){
        bigNum=*this;
        smalNum=b;

    }
    else{
        for(int i=0;i<b.num.size();++i){
            if(b.num[i]>this->num[i]) {
                bigNum=b,smalNum=*this;
                break;
            }
            else if(b.num[i]<this->num[i]) {
                bigNum=*this,smalNum=b;
                break;
            }
        }
       }
    reverse(smalNum.num.begin(),smalNum.num.end());
    reverse(bigNum.num.begin(),bigNum.num.end());


    int i=0;
    for(int j=i;i<smalNum.num.size();++i){
        if(bigNum.num[i]-'0'<smalNum.num[i]-'0'){
            if(bigNum.num[i+1]=='0'){
                while(1){
                    if(bigNum.num[j+1]=='0') bigNum.num[j+1]='9';
                    else {
                        bigNum.num[j+1]-=1;
                        res.num+=((int(bigNum.num[i]-'0')+10-int(smalNum.num[i]-'0'))+'0');
                        break;
                    }
                    ++j;
                }
            }
            else bigNum.num[i+1]-=1,res.num.push_back((int(bigNum.num[i]-'0')+10-int(smalNum.num[i]-'0'))+'0');
        }
        else res.num.push_back((int(bigNum.num[i]-'0')-int(smalNum.num[i]-'0'))+'0');
    }
    for(;i<bigNum.num.size();++i){
        res.num.push_back(bigNum.num[i]);
    }
    reverse(res.num.begin(),res.num.end());
    res.noExtraZero();
    res.sign=bigNum.sign;
    return res;
}

void bigDecimalInt::operator=(bigDecimalInt b){
    sign=b.sign;
    num=b.num;
}

int bigDecimalInt::siz(){
    return num.size();
}

bigDecimalInt::~bigDecimalInt()
{
    //dtor
}
