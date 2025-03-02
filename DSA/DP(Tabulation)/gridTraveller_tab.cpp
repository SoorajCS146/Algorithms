#include <iostream>
#include <vector>
using namespace std;
/*
    we start in top left corner of an (n * n) grid and move to bottom right corner. 
    We are allowed to move only right and downward.
    How many ways are there to reach our goal ?

*/
/*ERROR FOR 18,18 Integer overflow potentially
*/
class Traveller
{
    public :
        int n;
        
    Traveller(int n)
    {   
        this->n=n;
        
    }
    int waysToTravelInFullGrid(int n)
    {
        return waysToTravelInSpecificGrid(n,n);
    }

    int waysToTravelInSpecificGrid(int m,int n)
    {   
        vector<vector<long long>> vec = vector<vector<long long>>(m+1, vector<long long>(n+1,0));
        vec[1][1]=1;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i+1<=m)vec[i+1][j]+=vec[i][j];
                if(j+1<=n)vec[i][j+1]+=vec[i][j];
            }

        }
        return vec[m][n];
    }

};
int main()
{
    Traveller t1(3);
    cout<<" The total ways to travel are  "<<t1.waysToTravelInSpecificGrid(18,18);
}