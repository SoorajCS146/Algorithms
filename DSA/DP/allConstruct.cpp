#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
/* 
    Given a target string and a dictonary, return a list of lists where each inner list represents the set of words
    that can be used to construct the target string.
*/
class AllConstruct
{
    public :
        vector<string> dictionary;
        unordered_map<string,vector<vector<string>>>dp;

    AllConstruct(vector<string> dict)
    {
        dictionary=dict;
    }
    vector<vector<string>> allWays(string target)
    {
        if(dp.find(target)!=dp.end()) return dp[target];
        if(target =="") return {{}};

        vector<vector<string >>result;
        for(auto s:dictionary)
        {
            if(target.find(s)==0)
            {
                string suffix=target.substr(s.length());
                vector<vector<string>>suffixways=allWays(suffix);

                for(auto way:suffixways)
                {
                    way.insert(way.begin(),s);
                    result.push_back(way);
                }

            }
        }
        dp[target]=result;
        return result;
    }
    void showResults(string target)
    {
        vector<vector<string>> res=allWays(target);
        cout<<"All the ways of constructions are:\n";
        for(auto s:res)
        {
            for(auto i:s)
            {
                cout<<i<<" ";
            }
            cout<<"\n";
        }
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
    AllConstruct c1(dict);
    c1.showResults(temp);
}