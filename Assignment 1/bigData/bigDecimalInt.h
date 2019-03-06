#ifndef bigDecimalInt_H
#define bigDecimalInt_H
#include<bits/stdc++.h>
using namespace std;

class bigDecimalInt
{
    public:
        bigDecimalInt(string digit);
        bigDecimalInt(int digit);
        bigDecimalInt();

        bigDecimalInt operator+(bigDecimalInt b);
        bigDecimalInt operator-(bigDecimalInt b);
        void operator=(bigDecimalInt b);
        int siz();
        friend ostream &operator<<(ostream &out,const bigDecimalInt b);
        friend istream &operator>>(istream &in,bigDecimalInt b);

        ~bigDecimalInt();

    private:
        bool valid(string s);
        char sign;
        string num;
        void noExtraZero();
};

#endif // bigDecimalInt_H
