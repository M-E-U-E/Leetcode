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
// Use Floyd Warshall's algorithm
class Solution
{
public:
    int D[26][26];
    inline void FW(vector<char>& original, vector<char>& changed, vector<int>& cost)
    {
        fill(&D[0][0], &D[0][0]+26*26, INT_MAX);//Use C++ fill
        const int sz=original.size();
        for (int i=0; i<sz; i++)
        {
            int row=original[i]-'a';
            int col=changed[i]-'a';
            D[row][col]=min(D[row][col], cost[i]);
        }
        for (int i=0; i<26; i++) D[i][i]=0;

        for(int k=0; k<26; k++)
            for(int i=0; i<26; i++)
                for(int j=0; j<26; j++)
                    D[i][j]=min((long long)D[i][j], (long long)D[i][k]+D[k][j]);

    }

    long long minimumCost(string& source, string& target, vector<char>& original, vector<char>& changed, vector<int>& cost)
    {
        FW(original, changed, cost);
        const int n=source.size();
        long long ans=0;
        for(int i=0; i<n; i++)
        {
            int row=source[i]-'a';
            int col=target[i]-'a';
            if (D[row][col]==INT_MAX) return -1;
            ans+=D[row][col];
        }
        return ans;
    }
};
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
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
