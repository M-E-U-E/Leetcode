#include <iostream>
#include <map>
#include <string>#include<bits/stdc++.h>
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
//const int N = 1e5+10;
//bitset <N> vis;
//void sieve (void)
//{
//    for (int i = 2; i * i < N; ++i)
//    {
//        if (!vis[i])
//        {
//            for (int j = i * i; j < N; j += i) vis[j] = 1;
//        }
//    }
//}
string st;
ll h1,h2,h3,n1,n2,n3,p1,p2,p3,l,r,m,money;
ll  gett(ll x)
{
    ll res,need;
    res = 0;
    need=n1*x;
    if(h1>=need)
    {
        res+=0;
    }
    else
    {
        res+=(need-h1)*p1;
    }

    need = n2*x;
    if(h2>=need)
    {
        res+=0;
    }
    else
    {
        res+=(need-h2)*p2;
    }

    need = n3*x;
    if (h3>=need)
    {
        res+=0;
    }
    else
    {
        res+=(need-h3)*p3;
    }
    return res;
}
void solve()
{
    cin >> st;
    for(int i=0; i<st.size(); i++)
    {
        if (st[i]=='B')n1++;
        else if (st[i]=='S')n2++;
        else if (st[i]=='C')n3++;
    }
    cin >> h1 >> h2 >> h3;
    cin >> p1 >> p2 >> p3;
    cin >> money;
    l=0;
    r=1e14;
    while (l<r)
    {
        m=l+r+1;
        m/=2;
        if (gett(m)>money)
        {
            r=m-1;
        }
        else l=m;
    }
    cout << l << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    ll t;
//    cin >> t;
//    while(t--)
    {
        solve();

    }
    return 0;
}
