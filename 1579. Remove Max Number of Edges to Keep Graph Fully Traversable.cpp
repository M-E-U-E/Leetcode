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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges)
    {
        class UnionFind
        {
        public:
            vector<int> parent, size;
            int components;
            UnionFind(int n)
            {
                components = n;
                parent.resize(n + 1);
                size.resize(n + 1, 1);
                for (int i = 0; i <= n; ++i)
                {
                    parent[i] = i;
                }
            }

            int find(int x)
            {
                if (parent[x] != x)
                {
                    parent[x] = find(parent[x]);
                }
                return parent[x];
            }

            bool unite(int x, int y)
            {
                int rootX = find(x), rootY = find(y);
                if (rootX == rootY) return false;
                if (size[rootX] < size[rootY]) swap(rootX, rootY);
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                components--;
                return true;
            }

            bool isConnected()
            {
                return components == 1;
            }
        };

        UnionFind alice(n), bob(n);
        int edgesRequired = 0;
        for (const auto& edge : edges)
        {
            if (edge[0] == 3)
            {
                if (alice.unite(edge[1], edge[2]) | bob.unite(edge[1], edge[2]))
                {
                    edgesRequired++;
                }
            }
        }
        for (const auto& edge : edges)
        {
            if (edge[0] == 1)
            {
                if (alice.unite(edge[1], edge[2]))
                {
                    edgesRequired++;
                }
            }
            else if (edge[0] == 2)
            {
                if (bob.unite(edge[1], edge[2]))
                {
                    edgesRequired++;
                }
            }
        }
        if (alice.isConnected() && bob.isConnected())
        {
            return edges.size() - edgesRequired;
        }

        return -1;
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
