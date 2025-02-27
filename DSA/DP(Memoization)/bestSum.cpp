#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    Given an input of a targetSum and an array of numbers, return the shortest length array of numbers that form 
    the given sum, any element of the array can be used mutliple times and if there are multiple shortest length 
    arrays, We can return any one of them.
*/
class BestSum
{
    public:
        vector<int> numbers;
        unordered_map<int,vector<int>>mpp;
    
    BestSum(vector<int>num)
    {
        numbers =num;
    }

    vector<int> findBestSumArray(int targetSum)
    {
        if(mpp.find(targetSum)!=mpp.end())
        {
            return mpp[targetSum];
        }
        if(targetSum==0) return vector<int>{};
        if(targetSum <0) return {};

        vector<int> shortest={};
        for(int it :numbers)
        {
            int remainder=targetSum-it;
            vector<int> remArray=findBestSumArray(remainder);
            if(targetSum==it || !remArray.empty())
            {
                remArray.push_back(it);
                if(shortest.empty()|| remArray.size()<shortest.size())
                {
                    shortest=remArray;
                }
            }
        }

        mpp[targetSum]=shortest;
        return shortest;
    }
    void showResults(int targetSum)
    {
        vector<int> res=findBestSumArray(targetSum);
        if(!res.empty())
        {
            cout<<"The shortest combination that forms the target sum is :\n";
            for(auto it:res)
            {
                cout<<it<< "  ";
            }
        }
        else
        {
            cout<<"There is no combination that forms the given targetSum";
        }
    }

};
int main()
{
    int n, rem;
    vector<int>res;
    cout<<"Enter the length of the array:";
    cin>>n;
    cout<<"Enter the aray elements:";
    for(int i=0;i<n;i++)
    {
        cin>>rem;
        res.push_back(rem);
    }
    BestSum b1(res);
    cout<<"Enter the target Sum:";
    cin>>rem;
    b1.showResults(rem);
}