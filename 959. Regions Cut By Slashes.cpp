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
    vector<int> parent;
    vector<int> rank;
    int count;
public:
    int regionsBySlashes(vector<string>& grid)
    {
        int n = grid.size();
        int dots = n + 1;
        parent.resize(dots * dots);
        rank.resize(dots * dots, 1);
        count = 0;
        for (int i = 0; i < parent.size(); ++i)
        {
            parent[i] = i;
        }
        for (int i = 0; i < dots; ++i)
        {
            for (int j = 0; j < dots; ++j)
            {
                if (i == 0 || j == 0 || i == n || j == n)
                {
                    int cell = i * dots + j;
                    unionSets(0, cell);
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '\\')
                {
                    int cell1 = i * dots + j;
                    int cell2 = (i + 1) * dots + (j + 1);
                    unionSets(cell1, cell2);
                }
                else if (grid[i][j] == '/')
                {
                    int cell1 = (i + 1) * dots + j;
                    int cell2 = i * dots + (j + 1);
                    unionSets(cell1, cell2);
                }
            }
        }

        return count;
    }
private:
    void unionSets(int a, int b)
    {
        int parentA = find(a);
        int parentB = find(b);
        if (parentA == parentB)
        {
            count++;
        }
        else
        {
            if (rank[parentA] > rank[parentB])
            {
                parent[parentB] = parentA;
            }
            else if (rank[parentA] < rank[parentB])
            {
                parent[parentA] = parentB;
            }
            else
            {
                parent[parentB] = parentA;
                rank[parentA]++;
            }
        }
    }
    int find(int a)
    {
        if (parent[a] == a)
        {
            return a;
        }
        return parent[a] = find(parent[a]);
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
