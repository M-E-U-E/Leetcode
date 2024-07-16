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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution
//{
//private:
//    bool findPath(TreeNode* root, int tar, string& path)
//    {
//
//        if(root == nullptr) return false;
//        if(root->val == tar) return true;
//
//        bool left = findPath(root->left,tar,path);
//        if(left)
//        {
//            path += 'L';
//            return true;
//        }
//
//        bool right = findPath(root->right,tar,path);
//        if(right)
//        {
//            path += 'R';
//            return true;
//        }
//
//        return false;
//
//    }
//public:
//    string getDirections(TreeNode* root, int startValue, int destValue)
//    {
//
//        string pathRootToSt = "";
//        findPath(root,startValue,pathRootToSt);
//
//        string pathRootToDt = "";
//        findPath(root,destValue,pathRootToDt);
//
//        int i = pathRootToSt.size() - 1;
//        int j = pathRootToDt.size() - 1;
//
//        while(i>=0 && j>=0 && pathRootToSt[i] == pathRootToDt[j])
//        {
//            pathRootToSt.pop_back();
//            pathRootToDt.pop_back();
//            i--;
//            j--;
//        }
//
//        i = pathRootToSt.size();
//
//        for(int j=0; j<i; j++)
//        {
//            pathRootToSt[j] = 'U';
//        }
//
//        reverse(pathRootToDt.begin(),pathRootToDt.end());
//
//        return pathRootToSt + pathRootToDt;
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
