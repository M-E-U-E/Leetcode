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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//class Solution
//{
//public:
//    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head)
//    {
//        vector<vector<int>> matrix(m, vector<int>(n, -1));
//        int topRow = 0, bottomRow = m - 1, leftColumn = 0, rightColumn = n - 1;
//        while (head)
//        {
//            for (int col = leftColumn; col <= rightColumn && head; ++col)
//            {
//                matrix[topRow][col] = head->val;
//                head = head->next;
//            }
//            topRow++;
//            for (int row = topRow; row <= bottomRow && head; ++row)
//            {
//                matrix[row][rightColumn] = head->val;
//                head = head->next;
//            }
//            rightColumn--;
//            for (int col = rightColumn; col >= leftColumn && head; --col)
//            {
//                matrix[bottomRow][col] = head->val;
//                head = head->next;
//            }
//            bottomRow--;
//            for (int row = bottomRow; row >= topRow && head; --row)
//            {
//                matrix[row][leftColumn] = head->val;
//                head = head->next;
//            }
//            leftColumn++;
//        }
//        return matrix;
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
