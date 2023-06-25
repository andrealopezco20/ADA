
#include<iostream>
#include "MyNS.h" 
using namespace std;


long MyNS::factorial(int n)
{
    long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}
// Constructor for class CTest
MyNS::CTest::CTest()
{
    cout<<"Init test"<<endl;
}
void MyNS::CTest::Method1()
{
    cout<<"Hi method 1"<<endl;
}
// More implementation for NS1.h prototypes goes here
