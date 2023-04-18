#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <queue>
#include <map>
typedef long long ll;
using namespace std;


pair<int, int> dfs(vector<int> adj[], int N, int node, int p, int strediska[], int dist, int max_distance)
{
    int najblizsie_centrum = N + 1;
    for(int child : adj[node])
    {
        if(child != p) {
            pair<int, int> data = dfs(adj, N, child, node, strediska, 0, max_distance);
            dist = max(data.first + 1, dist);
            najblizsie_centrum = min(data.second + 1, najblizsie_centrum);
        }
    }

    if(dist >= max_distance) {
        strediska[node] = 1;
        dist = -1;
        najblizsie_centrum = 0;
    }

    if(dist + najblizsie_centrum <= max_distance) {
        dist = -1;
    } 

    return {dist, najblizsie_centrum};
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N; int S;
    cin >> N >> S;
    vector<int> adj[N];
 
    int inp1, inp2;
    for(int i = 0; i < N - 1; i++) {
        cin >> inp1 >> inp2;
        adj[inp1].push_back(inp2);
        adj[inp2].push_back(inp1);
    }

    int left = 0;
    int right = N+1;
    int middle = 0;

    int strediska[N] = { 0 };
    dfs(adj, N, 0, -1, strediska, -1, middle);

    int min_remembered = N; 
    vector<int> ans;
    vector<int> temp_ans;
    while(left<=right) {
        middle = left+(right-left)/2;

        int strediska[N] = { 0 };
        dfs(adj, N, 0, -1, strediska, 0, middle);
        int count = 0;
        
        temp_ans.clear();
        for(int i = 0; i < N; i++) {
            if(strediska[i] == 1) {
                count++;
                temp_ans.push_back(i);
            }
        }

        if(count > S) {
            left = middle + 1;
        } else {
            if(min_remembered > middle) {
                min_remembered = middle;
                ans = temp_ans;
            }
            right = middle - 1;
        }
    }
    
    cout << min_remembered << " " << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}