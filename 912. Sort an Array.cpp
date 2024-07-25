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
//void merge(vector<int>& array, int low, int mid, int high)
//{
//    int n1 = mid - low + 1;
//    int n2 = high - mid;
//    vector<int> left_part(n1), right_part(n2);
//
//    for (int i = 0; i < n1; ++i)
//        left_part[i] = array[low + i];
//    for (int i = 0; i < n2; ++i)
//        right_part[i] = array[mid + 1 + i];
//
//    int p1 = 0, p2 = 0, write_ind = low;
//    while (p1 < n1 && p2 < n2)
//    {
//        if (left_part[p1] <= right_part[p2])
//        {
//            array[write_ind] = left_part[p1++];
//        }
//        else
//        {
//            array[write_ind] = right_part[p2++];
//        }
//        ++write_ind;
//    }
//
//    while (p1 < n1)
//        array[write_ind++] = left_part[p1++];
//
//    while (p2 < n2)
//        array[write_ind++] = right_part[p2++];
//}
//
//void merge_sort(vector<int>& array, int low, int high)
//{
//    if (low >= high)
//        return;
//
//    int mid = low + (high - low) / 2;
//    merge_sort(array, low, mid);
//    merge_sort(array, mid + 1, high);
//    merge(array, low, mid, high);
//}
//
//class Solution
//{
//public:
//    vector<int> sortArray(vector<int>& nums)
//    {
//        merge_sort(nums, 0, nums.size() - 1);
//        return nums;
//    }
//};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    ll t;
//    cin >> t;
//    while(t--)
    {
//        solve();

    }
    return 0;
}
