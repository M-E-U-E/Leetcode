
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
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target)
    {
        vector<vector<pair<int, int>>> adjacencyList(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int nodeA = edges[i][0], nodeB = edges[i][1];
            adjacencyList[nodeA].emplace_back(nodeB, i);
            adjacencyList[nodeB].emplace_back(nodeA, i);
        }

        vector<vector<int>> distances(n, vector<int>(2, INT_MAX));
        distances[source][0] = distances[source][1] = 0;

        runDijkstra(adjacencyList, edges, distances, source, 0, 0);
        int difference = target - distances[destination][0];
        if (difference < 0) return {};
        runDijkstra(adjacencyList, edges, distances, source, difference, 1);
        if (distances[destination][1] < target) return {};

        for (auto& edge : edges)
        {
            if (edge[2] == -1) edge[2] = 1;
        }
        return edges;
    }

private:
    void runDijkstra(const vector<vector<pair<int, int>>>& adjacencyList, vector<vector<int>>& edges, vector<vector<int>>& distances, int source, int difference, int run)
    {
        int n = adjacencyList.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> priorityQueue;
        priorityQueue.push({0, source});
        distances[source][run] = 0;

        while (!priorityQueue.empty())
        {
            auto [currentDistance, currentNode] = priorityQueue.top();
            priorityQueue.pop();

            if (currentDistance > distances[currentNode][run]) continue;

            for (auto& neighbor : adjacencyList[currentNode])
            {
                int nextNode = neighbor.first, edgeIndex = neighbor.second;
                int weight = edges[edgeIndex][2];

                if (weight == -1) weight = 1;

                if (run == 1 && edges[edgeIndex][2] == -1)
                {
                    int newWeight = difference + distances[nextNode][0] - distances[currentNode][1];
                    if (newWeight > weight)
                    {
                        edges[edgeIndex][2] = weight = newWeight;
                    }
                }

                if (distances[nextNode][run] > distances[currentNode][run] + weight)
                {
                    distances[nextNode][run] = distances[currentNode][run] + weight;
                    priorityQueue.push({distances[nextNode][run], nextNode});
                }
            }
        }
    }
};
static const auto mynameisbarryallen = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}
();
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
