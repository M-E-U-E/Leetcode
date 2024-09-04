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
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        unordered_map<string,int>mp;
        for(auto it:obstacles)
        {
            string key = to_string(it[0])+"+"+to_string(it[1]);
            mp[key]++;
        }
        vector<vector<int>>direc = {{-1,0},{0,1},{1,0},{0,-1}};
        int dir = 1;
        int x=0,y=0;
        int mxDist=0;
        for(int it:commands)
        {
            if(it==-2)
            {
                if(dir==0) dir = 3;
                else dir--;
            }
            else if(it==-1)
            {
                dir = (dir+1)%4;
            }
            else
            {
                int k = it;
                for(int i=1; i<=k; i++)
                {
                    int newX = x+direc[dir][0];
                    int newY = y+direc[dir][1];
                    string key = to_string(newX)+"+"+to_string(newY);
                    if(mp.find(key)!=mp.end())
                    {
                        break;
                    }
                    x = newX, y=newY;
                    mxDist = max(mxDist, x*x+y*y);
                }
            }
        }
        return mxDist;
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
