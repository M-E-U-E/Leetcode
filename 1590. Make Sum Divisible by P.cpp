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
    int minSubarray(vector<int>& nums, int p)
    {
        map<int, int> mp;
        mp[0] = -1;
        int prefix_sum = 0;
        int ans = nums.size();
        int total_sum = 0;
        for(auto val : nums)
        {
            total_sum = (total_sum + val) % p;
        }
        if(total_sum == 0)
        {
            return 0;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            prefix_sum = (prefix_sum + nums[i]) % p;
            int check = (prefix_sum - total_sum + p) % p;
            if(mp.find(check) != mp.end())
            {
                ans = min(ans, i - mp[check]);
            }
            mp[prefix_sum] = i;
        }
        if(ans == nums.size())
        {
            return -1;
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
