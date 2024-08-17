
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
    long long maxPoints(vector<vector<int>>& P)
    {
        long long m = P.size(), n = P[0].size();
        vector<long long> pre(n);
        for (int i = 0; i < n; ++i) pre[i] = P[0][i];
        for (int i = 0; i < m - 1; ++i)
        {
            vector<long long> lft(n, 0), rgt(n, 0), cur(n, 0);
            lft[0] = pre[0];
            rgt[n - 1] = pre[n - 1];
            for (int j = 1; j < n; ++j)
            {
                lft[j] = max(lft[j - 1] - 1, pre[j]);
            }
            for (int j = n - 2; j >= 0; --j)
            {
                rgt[j] = max(rgt[j + 1] - 1, pre[j]);
            }
            for (int j = 0; j < n; ++j)
            {
                cur[j] = P[i + 1][j] + max(lft[j], rgt[j]);
            }
            pre = cur;
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans = max(ans, pre[i]);

        }
        return ans;
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
