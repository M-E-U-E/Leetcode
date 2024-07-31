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
//#include <vector>
//#include <algorithm>
//#include <climits>
//
//class Solution {
//public:
//    int minHeightShelves(std::vector<std::vector<int>>& books, int shelfWidth) {
//        return arrangeBooks(books, shelfWidth);
//    }
//
//private:
//    int arrangeBooks(std::vector<std::vector<int>>& books, int maxShelfWidth) {
//        std::vector<int> minHeights(books.size() + 1, INT_MAX);
//        minHeights[0] = 0;
//
//        for (int bookIndex = 1; bookIndex <= books.size(); bookIndex++) {
//            int currentShelfHeight = 0;
//            int currentShelfWidth = 0;
//
//            for (int lastBook = bookIndex - 1; lastBook >= 0; lastBook--) {
//                int currentBookThickness = books[lastBook][0];
//                int currentBookHeight = books[lastBook][1];
//
//                if (currentShelfWidth + currentBookThickness > maxShelfWidth) {
//                    break;
//                }
//
//                currentShelfWidth += currentBookThickness;
//                currentShelfHeight = std::max(currentShelfHeight, currentBookHeight);
//
//                int currentArrangementHeight = minHeights[lastBook] + currentShelfHeight;
//                minHeights[bookIndex] = std::min(minHeights[bookIndex], currentArrangementHeight);
//            }
//        }
//
//        return minHeights[books.size()];
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
