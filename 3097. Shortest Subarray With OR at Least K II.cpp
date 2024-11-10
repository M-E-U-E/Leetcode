
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
    void update(vector<int>& bits, int x, int change)
    {
        // insert or remove element from window, time: O(32)
        for (int i = 0; i < 32; i++)
        {
            if ((x >> i) & 1)
            {
                bits[i] += change;
            }
        }
    }

    int bitsToNum(vector<int>& bits)
    {
        // convert 32-size bits array to integer, time: O(32)
        int result = 0;
        for (int i = 0; i < 32; i++)
        {
            if (bits[i])
            {
                result |= 1 << i;
            }
        }
        return result;
    }

    bool isSpecial(vector<int>& nums, int k, int len)
    {
        // checks if special subarray exists for length len, time: O(n)
        int n = nums.size();
        vector<int> bits(32);
        for (int i = 0; i < n; i++)
        {
            update(bits, nums[i], 1); // insert nums[i] into window
            if (i >= len)
            {
                update(bits, nums[i - len], -1); // remove nums[i - len] from window
            }
            if (i >= len - 1 && bitsToNum(bits) >= k)
            {
                // special subarray found
                return true;
            }
        }
        return false;
    }

public:
    int minimumSubarrayLength(vector<int>& nums, int k)
    {
        int n = nums.size(), start = 1, end = n + 1, mid;
        while (start < end)
        {
            mid = (start + end) / 2;
            if (!isSpecial(nums, k, mid))
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        return start != n + 1 ? start : -1;
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

