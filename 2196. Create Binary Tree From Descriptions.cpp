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
//class Solution
//{
//public:
//    TreeNode* createBinaryTree(vector<vector<int>>& descriptions)
//    {
//        unordered_map<int, TreeNode*> getNode;
//        unordered_map<int, bool> isChild;
//        for(auto &v: descriptions)
//        {
//            if(getNode.count(v[0])==0)
//            {
//                TreeNode* par = new TreeNode(v[0]);
//                getNode[v[0]] = par;
//            }
//            if(getNode.count(v[1])==0)
//            {
//                TreeNode* child = new TreeNode(v[1]);
//                getNode[v[1]] = child;
//            }
//            if(v[2]==1) getNode[v[0]]->left = getNode[v[1]];
//            else getNode[v[0]]->right = getNode[v[1]];
//            isChild[v[1]] = true;
//        }
//        TreeNode* ans = NULL;
//        for(auto &v: descriptions)
//        {
//            if(isChild[v[0]] != true)
//            {
//                ans = getNode[v[0]];
//                break;
//            }
//        }
//        return ans;
//    }
//};

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
