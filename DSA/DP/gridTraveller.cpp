#include <iostream>
#include <vector>
using namespace std;
/*
    we start in top left corner of an (n * n) grid and move to bottom right corner. 
    We are allowed to move only right and downward.
    How many ways are there to reach our goal ?

*/
class Traveller
{
    public :
        int n;
        vector<vector<int>> vec;
    Traveller(int n)
    {   
        this->n=n;
        vec = vector<vector<int>>(n, vector<int>(n,-1));
    }
    int waysToTravelInFullGrid(int n)
    {
        return waysToTravelInSpecificGrid(n,n);
    }

    int waysToTravelInSpecificGrid(int m,int n)
    {
        if(m==1 && n==1)
        {
            return 1;
        }
        if(m==0 || n==0)
        {
            return 0;
        }
        if(this->vec[m-1][n-1]!=-1)
        {
            return vec[m-1][n-1];
        }
        vec[m-1][n-1]=waysToTravelInSpecificGrid(m-1,n)+waysToTravelInSpecificGrid(m,n-1);
        return vec[m-1][n-1];
    }

};
int main()
{
    Traveller t1(3);
    cout<<" The total ways to travel are  "<<t1.waysToTravelInSpecificGrid(18,18);
}