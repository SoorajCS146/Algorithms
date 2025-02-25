#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
    Similar to can sum, when a targetsum is given and a numbers is given, we need to return an array combinations 
    that add up to the targetsum. Any valid combination is considered to be the right answer.
*/

class HowSumFinder
{
    public :
        unordered_map<int,vector<int>>mpp;
        vector<int>numbers;
    HowSumFinder(vector<int>num)
    {
        numbers=num;

    }
    vector<int> findArray(int targetSum)
    {
        if(targetSum==0) return vector<int> {};
        if(targetSum<0) return {};
        if(mpp.find(targetSum)!=mpp.end()) return mpp[targetSum];
        for(int i=0;i<this->numbers.size();i++)
        {
            int remainder=targetSum-this->numbers[i];
            vector<int> remArray= findArray(remainder);
            if(targetSum ==this->numbers[i] || !remArray.empty())
            {
                remArray.push_back(this->numbers[i]);
                mpp[targetSum]= remArray;
                return mpp[targetSum];
            }
        }
        mpp[targetSum]={};
        return {};
    }
    void showResultArray(int targetSum)
    {
        vector<int> res=findArray(targetSum);
        if(!res.empty())
        {
            cout<<"The result array is \n";
            for(auto it:res)
            {
                cout<< " "<<it;
            }
        }
        else
        {
            cout<<"TargetSum is not possible from the given array";
        }

    }
};

int main()
{
    vector<int> arr;
    int n,rem;
    cout<<"Enter the lenght of the array: \n";
    cin>>n;
    cout<<"Enter the "<<n<< " elements of the array :\n";
    for(int i=0;i<n;i++)
    {
        cin>>rem;
        arr.push_back(rem);
    }
    HowSumFinder h1(arr);
    cout<<"Enter the target sum:";
    cin>>rem;
    h1.showResultArray(rem);


}