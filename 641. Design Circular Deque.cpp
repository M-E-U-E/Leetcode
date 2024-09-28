
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
class MyCircularDeque
{
private:
    vector<int> buffer;
    int cnt;
    int k;
    int front;
    int rear;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k): buffer(k, 0), cnt(0), k(k), front(k - 1), rear(0)
    {
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
    {
        if (cnt == k)
        {
            return false;
        }
        buffer[front] = value;
        front = (front - 1 + k) % k;
        ++cnt;

        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if (cnt == k)
        {
            return false;
        }
        buffer[rear] = value;
        rear = (rear + 1) % k;
        ++cnt;

        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if (cnt == 0)
        {
            return false;
        }
        front = (front + 1) % k;
        --cnt;

        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
    {
        if (cnt == 0)
        {
            return false;
        }
        rear = (rear - 1 + k) % k;
        --cnt;

        return true;
    }

    /** Get the front item from the deque. */
    int getFront()
    {
        if (cnt == 0)
        {
            return -1;
        }
        return buffer[(front + 1) % k];
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        if (cnt == 0)
        {
            return -1;
        }
        return buffer[(rear - 1 + k) % k];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty()
    {
        return cnt == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull()
    {
        return cnt == k;
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
