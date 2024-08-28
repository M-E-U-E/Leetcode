
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
private:
    vector<int> islandRoot;
    vector<char> islandStatus;
    int numRows, numCols;

    int findIslandRoot(int x)
    {
        if (islandRoot[x] != x)
        {
            islandRoot[x] = findIslandRoot(islandRoot[x]); // Path compression
        }
        return islandRoot[x];
    }

    void unionIslands(int x, int y)
    {
        int rootX = findIslandRoot(x);
        int rootY = findIslandRoot(y);
        if (rootX != rootY)
        {
            islandRoot[rootY] = rootX;
        }
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        numRows = grid2.size();
        numCols = grid2[0].size();
        int totalCells = numRows * numCols;
        islandRoot.resize(totalCells);
        islandStatus.resize(totalCells, 0);

        iota(islandRoot.begin(), islandRoot.end(), 0);

        for (int row = 0; row < numRows; row++)
        {
            for (int col = 0; col < numCols; col++)
            {
                if (grid2[row][col] == 1)
                {
                    int currentIndex = row * numCols + col;
                    if (col + 1 < numCols && grid2[row][col + 1] == 1)
                    {
                        unionIslands(currentIndex, currentIndex + 1);
                    }
                    if (row + 1 < numRows && grid2[row + 1][col] == 1)
                    {
                        unionIslands(currentIndex, currentIndex + numCols);
                    }
                }
            }
        }

        for (int row = 0; row < numRows; row++)
        {
            for (int col = 0; col < numCols; col++)
            {
                if (grid2[row][col] == 1 && grid1[row][col] == 0)
                {
                    int rootIndex = findIslandRoot(row * numCols + col);
                    islandStatus[rootIndex] = 2;
                }
            }
        }

        int subIslandCount = 0;
        for (int row = 0; row < numRows; row++)
        {
            for (int col = 0; col < numCols; col++)
            {
                if (grid2[row][col] == 1)
                {
                    int rootIndex = findIslandRoot(row * numCols + col);
                    if (islandStatus[rootIndex] == 0)
                    {
                        subIslandCount++;
                        islandStatus[rootIndex] = 1;
                    }
                }
            }
        }

        return subIslandCount;
    }
};

static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}
();
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
