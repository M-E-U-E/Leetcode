
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
//class Solution
//{
//public:
//    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
//    {
//        int INF = (int) 1e6; // INF = n * maxWeight = 100 * 10^4 = 10^6
//        vector<vector<int>> dist = vector(n, vector<int>(n, INF)); // dist[i][j] is the minimum distance from i to j
//        for (int i = 0; i < n; i++) dist[i][i] = 0;
//        for (vector<int>& edge : edges)
//        {
//            int v1 = edge[0], v2 = edge[1], w = edge[2];
//            dist[v1][v2] = dist[v2][v1] = w;
//        }
//
//        // Floyd Warshall's shortest path algorithm
//        for (int k = 0; k < n; k++)
//            for (int i = 0; i < n; i++)
//                for (int j = 0; j < n; j++)
//                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//
//        int minReachable = n, ans = 0;
//        for (int i = 0; i < n; i++)
//        {
//            int reachable = 0;
//            for (int j = 0; j < n; j++)
//                if (dist[i][j] <= distanceThreshold)
//                    reachable++;
//            if (reachable <= minReachable)
//            {
//                minReachable = reachable;
//                ans = i;
//            }
//        }
//        return ans;
//    }
//};
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
