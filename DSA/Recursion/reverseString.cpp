#include <iostream>
#include <string.h>
#include <string>
using namespace std;
class StringReverser
{
    public:
        string word;
    StringReverser(string s)
    {
        this->word=s;
    }
    string reverse_the_string(string word)
    {
        if(word=="")
        {
            return "";
        }
        return reverse_the_string(word.substr(1))+ word[0];
    }
};

int main()
{
    StringReverser s("sooraj");
    string res=s.reverse_the_string(s.word);
    cout<<"Reversed String:"<<res;
    return 0;
}