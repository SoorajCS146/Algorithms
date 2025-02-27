#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/* 
    Given a  target string and a dictonary of words(strings) , return true if it is possible to construct the target
    using the words of the dictiornary, they could be repeated, else return false.
*/
class ConstructChecker
{
    public :
    vector<string> dictionary;
    unordered_map<string,bool>mpp;
    ConstructChecker(vector<string>dict)
    {
        dictionary=dict;
    }

    bool canConstruct(string target)
    {
        if(mpp.find(target)!=mpp.end()) return mpp[target];
        if(target=="") 
        {
            return true;
        }
        for(auto s:this->dictionary)
        {   
            if(target.find(s)==0)
            {
                string suffix=target.substr(s.length());
                if(canConstruct(suffix)==true)
                {
                    mpp[target]=true;
                    return true;
                }
            }
        }
        mpp[target]=false;
        return false;
    }
    void showResults(string target)
    {
        if(canConstruct(target))
        {
            cout<<"Yes the target can be constructed out of the dictionary";
        }
        else
        {
            cout<<"No the target can not be constructed out of the given dictionary";
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
    ConstructChecker c1(dict);
    c1.showResults(temp);

}