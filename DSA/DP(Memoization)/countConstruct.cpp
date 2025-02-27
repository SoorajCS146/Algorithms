#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/*
    Given a target string and dictionary , return the total number of ways the targer string can be constructed from
    the given set of dictionary words where any word can be used multiple times as necessary.
*/
class CountConstruct
{
    public:
        vector<string>dictionary;
        unordered_map<string,int>dp;
    
    CountConstruct(vector<string> dict)
    {
        dictionary=dict;
    }
    int countWays(string target)
    {
        if(dp.find(target)!=dp.end()) return dp[target];
        if(target=="") return 1;
        int totalways=0;
        for(auto s:dictionary)
        {
            if(target.find(s)==0)
            {
                string suffix=target.substr(s.length());
                totalways+=countWays(suffix);
            }
        }
        dp[target]=totalways;
        return totalways;
    }
    void showResults(string target)
    {
        int res=countWays(target);
        cout<<"The number of ways this could be constructed : "<<res;
    }
};

int main()
{
    int n;
    string temp;
    vector<string> dict;
    cout<<"Enter the length of the dictionary:";
    cin>>n;
    cout<<"Enter the words of the dictionary:\n";
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        dict.push_back(temp);
    }
    cout<<"Enter the target string:";
    cin>>temp;
    CountConstruct c1(dict);
    c1.showResults(temp);
}