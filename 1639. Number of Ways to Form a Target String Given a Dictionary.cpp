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
//vector<ll> v
//void primeFactors(ll n)
//{
//    // Print the number of 2s that divide n
//    while (n % 2==0)
//    {
//        v.push_back(2);
//        n = n/2;
//    }
//
//    // n must be odd at this point. So we can skip
//    // one element (Note i = i +2)
//    for (ll i = 3; i*i<=n; i = i + 2)
//    {
//        // While i divides n, print i and divide n.
//        while (n % i == 0)
//        {
//            // cout<<i<<ss;
//            v.push_back(i);
//            n = n/i;
//        }
//    }
//
//    //This condition is to handle the case when n
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
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = target.length(), mod = 1e9 + 7;
        vector<long> res(n + 1);
        res[0] = 1;
        for (int i = 0; i < words[0].length(); ++i) {
            vector<int> count(26);
            for (auto& w : words)
                count[w[i] - 'a']++;
            for (int j = n - 1; j >= 0; --j) {
                res[j + 1] += res[j] * count[target[j] - 'a'] % mod;
            }
        }
        return res[n] % mod;
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
