#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
bool cmp(pair<int,int>a,pair<int,int> b)
{
    if(a.first > b.first)
        return true;
    else if(a.first == b.first and a.second<b.second)
        return true;

    return false;
}
//vector<ll>v;
//void primeFactors(ll n)
//{
//    // Print the number of 2s that divide n
//    while (n % 2 == 0)
//    {
//        v.push_back(2);
//        n = n/2;
//    }
//
//    // n must be odd at this point. So we can skip
//    // one element (Note i = i +2)
//    for (ll i = 3; i*i<=n; i = i + 2)
//    {
//        // While i divides n, print i and divide n
//        while (n % i == 0)
//        {
//            // cout<<i<<ss;
//            v.push_back(i);
//            n = n/i;
//        }
//    }
//
//    // This condition is to handle the case when n
//    // is a prime number greater than 2
//    if (n > 2)
//        v.push_back(n);
//}
const int N = 1e5+10;
bitset <N> vis;
void sieve (void)
{
    for (int i = 2; i * i < N; ++i)
    {
        if (!vis[i])
        {
            for (int j = i * i; j < N; j += i) vis[j] = 1;
        }
    }
}
class Solution
{
public:
    bool magicsquare(vector<vector<int>> &grid, int i, int j)
    {
        if(i + 2 < grid.size() && j+2 < grid[i].size())
        {
            int col1 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
            int col2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
            int col3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
            int row1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
            int row2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
            int row3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
            int diag1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
            int diag2 = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
            if((col1 == col2) &&  (col1 == col3) &&(col1 == row1) &&(col1 == row2) && (col1 == row3) &&(col1 == diag1) &&(col1 == diag2))
            {
                set<int> s({1,2,3,4,5,6,7,8,9});
                for(int k = 0 ; k < 3 ; k++)
                {
                    for(int l = 0; l < 3 ; l++)
                    {
                        s.erase(grid[i + k][j + l]);
                    }
                }
                return s.empty();
            }
        }
        return false;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid)
    {
        int count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size() ; j++)
            {
                if(magicsquare(grid, i, j))
                {
                    count++;
                }
            }
        }
        return count;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
//        solve();

    }
    return 0;
}
