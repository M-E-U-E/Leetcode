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
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change)
    {
        vector<vector<int>> graph(n);
        for (auto& edge : edges)
        {
            graph[edge[0]-1].push_back(edge[1]-1);
            graph[edge[1]-1].push_back(edge[0]-1);
        }

        int least = -1;
        queue<pair<int, int>> pq;
        pq.emplace(0, 0);
        vector<vector<int>> seen(n);

        while (pq.size())
        {
            auto [t, u] = pq.front();
            pq.pop();
            if (u == n-1)
            {
                if (least == -1) least = t;
                else if (least < t) return t;
            }
            if (t/change & 1) t = (t/change+1)*change;
            t += time;
            for (auto& v : graph[u])
                if (seen[v].empty() or (seen[v].size() == 1 and seen[v][0] != t))
                {
                    seen[v].push_back(t);
                    pq.emplace(t, v);
                }
        }
        return -1;
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
