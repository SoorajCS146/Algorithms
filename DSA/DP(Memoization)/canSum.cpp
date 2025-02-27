#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class SumDecider
{
    public :
        vector<int> numbers;
        unordered_map<int,bool>memo;
    SumDecider( vector<int>arr)
    {
        numbers=arr;
    }
    bool sumExists(int targetSum)
    {
        if(targetSum==0) return true;
        if(targetSum<0) return false;
        if(memo.find(targetSum)!=memo.end()) return memo[targetSum];
        for(int i=0;i<this->numbers.size();i++)
        {
            int remainder=targetSum-numbers[i];
            if(sumExists(remainder))
            {
                memo[targetSum]=true; //havent understood this part, i thought since the sumexists it should be memo[remainder]
                return true;
            }

        }
        memo[targetSum]=false;
        return false;
    }
    void showResults(int targetSum)
    {
        if(sumExists(targetSum))
        {
            cout<<"Yes sum is possible";
        }
        else
        {
            cout<<"No the sum is not possible";
        }
    }
};

int main()
{
    int n,temp;
    vector<int>num;
    cout<<"Enter the length of the array:";
    cin>>n;
    cout<<"Enter the values of the array:";
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        num.push_back(temp);
    }
    SumDecider s1(num);
    cout<<"Enter the targetSum to check:";
    cin>>temp;
    s1.showResults(temp);

}