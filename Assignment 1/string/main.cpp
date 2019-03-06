#include <iostream>
#include "studentName.h"

using namespace std;

int main()
{
    studentName s1("ahmed mohamed sayed");
    s1.print();
    s1.rplace(1,3);
    cout<<endl;
    studentName s2("sara ahmed");
    s2.print();
    s2.rplace(0,2);
    cout<<endl;
    studentName s3("khaled");
    s3.print();
    s3.rplace(4,5);
    cout<<endl;
    studentName s4("aya ali ahmed sayed");
    s4.print();
    s4.rplace(3,4);
    cout<<endl;
    studentName s5("Abdulrahman okasha");
    s5.print();
    s5.rplace(1,2);
    cout<<endl;

}
