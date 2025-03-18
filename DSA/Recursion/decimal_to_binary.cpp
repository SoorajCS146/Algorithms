#include <iostream>
#include <string>
#include <string.h>
using namespace std;
string Decimal_to_Binary(int number,string result)
{
    if(number==0)
    {
        return result;
    }
    result=to_string(number%2)+result;
    return Decimal_to_Binary(number/2,result);
}

int main()
{
    cout<<Decimal_to_Binary(20,"");

    return 0;
}