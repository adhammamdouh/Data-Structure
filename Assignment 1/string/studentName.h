#ifndef STUDENTNAME_H
#define STUDENTNAME_H
#include <bits/stdc++.h>

using namespace std;

class studentName
{
    public:
        studentName(string n);
        void print();
        void rplace(int i,int j);
        ~studentName();

    protected:

    private:
        void chk(string &n);
        int spaces=0;
        string name;
};

#endif // STUDENTNAME_H
