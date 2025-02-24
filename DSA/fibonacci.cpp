#include <iostream>
#include <vector>
using namespace std;
class Fibonacci
{
    public:
        int number;
        vector<int>vec;
    Fibonacci(int n)
    {
        number=n;
        vec=vector<int>(n+1,-1);

    }
    int findFibonacci(int n)
    {   if(n<=1) return n;
        if(vec[n]!=-1) return vec[n];
        vec[n]=findFibonacci(n-1)+findFibonacci(n-2);
        return vec[n];
    }   
    void showFibonacci()
    {
        cout<<"Fibonacci of "<<this->number<<"is "<<this->findFibonacci(this->number);
    }
};
int main()
{
    int n;
    cout<<"Enter the number to find the fibonacci of :";
    cin>>n;
    Fibonacci fib(n);
    fib.showFibonacci();
    
}