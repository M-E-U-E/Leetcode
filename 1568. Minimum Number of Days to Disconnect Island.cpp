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
    int time;
    vector<vector<int>> vis;
    vector<vector<int>> low;
    int d[5] = {0, 1, 0, -1, 0};
    bool arti;

    int minDays(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        arti = false;
        vis = vector<vector<int>>(n, vector<int>(m, 0));
        low = vector<vector<int>>(n, vector<int>(m, 0));
        time = 1;
        bool hasArt = false;
        bool found = false;

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j] == 1)
                {
                    if(found)
                        return 0;
                    found = true;
                    art(i, j, grid, -100, -100);
                }
            }
        }

        if(time == 1)
            return 0;

        if(time == 2)
            return 1;
        if(arti)
            return 1;
        else
            return 2;
    }

    void art(int row, int col, vector<vector<int>>& grid, int parRow, int parCol)
    {
        grid[row][col] = 0;
        vis[row][col] = time;
        low[row][col] = time;
        time++;
        int child = 0;
        for(int i = 0; i < 4; ++i)
        {
            int x = d[i] + row;
            int y = d[i+1] + col;

            if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || (x == parRow && y == parCol) || (vis[x][y] == 0 && grid[x][y] == 0))
                continue;
            if(vis[x][y] == 0)
            {
                child++;
                art(x, y, grid, row, col);
                low[row][col] = min(low[row][col], low[x][y]);
                if(low[x][y] >= vis[row][col] && (parRow != -100 && parCol != -100))
                    arti = true;
            }
            else
            {
                low[row][col] = min(low[row][col], vis[x][y]);
            }
        }

        if(parRow == -100 && parCol == -100 && child > 1)
            arti = true;
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
