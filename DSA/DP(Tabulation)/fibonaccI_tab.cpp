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
    {   vec[0]=0;
        vec[1]=1;
        for(int i=2;i<n+1;i++)
        {
            vec[i]=vec[i-1]+vec[i-2];
        }
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