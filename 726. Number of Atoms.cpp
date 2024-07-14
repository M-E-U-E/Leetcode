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
    string countOfAtoms(string formula)
    {
        string output;
        const int n = formula.size();
        int i = 0;
        map<string, int> counts = parseFormula(formula, i);
        for (pair<string, int> p : counts)
        {
            output += p.first;
            if (p.second > 1) output += to_string(p.second);
        }
        return output;
    }
private:
    map<string, int> parseFormula(string& s, int& i)
    {
        map<string, int> counts;
        const int n = s.size();
        while (i < n && s[i] != ')')
        {
            map<string, int> cnts = parseUnit(s, i);
            merge(counts, cnts, 1);
        }
        return counts;
    }
    map<string, int> parseUnit(string& s, int& i)
    {
        map<string, int> counts;
        const int n = s.size();
        if (s[i] == '(')
        {
            map<string, int> cnts = parseFormula(s, ++i);
            int digits = parseDigits(s, ++i);
            merge(counts, cnts, digits);
        }
        else
        {
            int i0 = i++;
            while (i < n && islower(s[i]))
            {
                i++;
            }
            string atom = s.substr(i0, i - i0);
            int digits = parseDigits(s, i);
            counts[atom] += digits;
        }
        return counts;
    }
    int parseDigits(string& s, int& i)
    {
        int i1 = i;
        while (i < s.size() && isdigit(s[i]))
        {
            i++;
        }
        int digits = i == i1 ? 1 : stoi(s.substr(i1, i - i1));
        return digits;
    }
    void merge(map<string, int>& counts, map<string, int>& cnts, int times)
    {
        for (pair<string, int> p : cnts) counts[p.first] += p.second * times;
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
