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
    int maxDistance(vector<int>& position, int m)
    {
        sort(position.begin(), position.end());
        int lo = 1;
        int hi = (position.back() - position[0]) / (m - 1);
        int ans = 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (canWePlace(position, mid, m))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return ans;
    }

private:
    bool canWePlace(const vector<int>& arr, int dist, int balls)
    {
        int countBalls = 1;
        int lastPlaced = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - lastPlaced >= dist)
            {
                countBalls++;
                lastPlaced = arr[i];
            }
            if (countBalls >= balls)
            {
                return true;
            }
        }
        return false;
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
