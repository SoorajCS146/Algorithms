#include <iostream>
#include <vector>
/* print all the subsequences whose sum is equal to K*/
using namespace std;
void printerRecursive(int ind,vector<int>&ds,vector<int>&arr,int sum,int k)
{
   
    if(ind>=arr.size())
    {
        if(sum==k)
        {
            for(auto it:ds)
            {
                cout<<it<<" ";
            }
            cout<<"\n";
        }
        return ;
    }
    sum+=arr[ind];
    ds.push_back(arr[ind]);
    printerRecursive(ind+1,ds,arr,sum,k);
    sum-=arr[ind];
    ds.pop_back();
    printerRecursive(ind+1,ds,arr,sum,k);
}
/*What if we want to  print only one subsequence and not all, thereby reducing the stack callspace, using boolean as 
return value and when we reach base case return true or false also put the nested recursive calls in a if condition*/
bool printerOnlyOne(int ind,vector<int>&ds,vector<int>&arr,int sum,int k)
{
    if(ind>=arr.size())
    {
        if(sum==k)
        {
            for(auto it:ds)
            {
                cout<<it<<" ";
            }
            cout<<"\n";
            return true;
        }
        return false;
    }
    sum+=arr[ind];
    ds.push_back(arr[ind]);
    if(printerOnlyOne(ind+1,ds,arr,sum,k)==true) return true;
    sum-=arr[ind];
    ds.pop_back();
    if(printerOnlyOne(ind+1,ds,arr,sum,k)==true) return true;
    return false;
}

/* What if we need to cound the number of subsequences whose sum is K
        Go to base case return 1 if satisfied, 0 otherwise
        l=f(),r=f() then return l+r;
*/
int countSubsequences(int ind,vector<int>&arr,int sum,int k)
{
    if(ind>=arr.size())
    {
        if(sum==k)
        {
            return 1;
        }
        return 0;
    }
    sum+=arr[ind];
    int l=countSubsequences(ind+1,arr,sum,k);
    sum-=arr[ind];
    int r=countSubsequences(ind+1,arr,sum,k);
    return l+r;
    
}
int main()
{
    vector<int>arr={2,1,3,6,7};
    vector<int>ds={};
    //printerRecursive(0,ds,arr,0,7);
    // printerOnlyOne(0,ds,arr,0,7);
    cout<<countSubsequences(0,arr,0,7);
}