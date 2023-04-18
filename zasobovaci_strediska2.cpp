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


int dfs2(vector<int> adj[], int N, int node, int p, int dist, int hlbky[]) {
    for(int child : adj[node])
    {
        if(child != p) {
            dist = max(dfs2(adj, N, child, node, -1, hlbky) + 1, dist);
        }
    }
    if(dist < 0) {
        dist = 0;
    }
    hlbky[node] = dist;
    return dist;
}



int dfs(vector<int> adj[], int N, int node, int p, int strediska[], int dist, int max_distance, int hlbky[], int najblizsie_centra[])
{
    if(hlbky[node] == max_distance) {
        strediska[node] = 1;
        hlbky[node] = -1;
        najblizsie_centra[node] = 0;
    } else {
        for(int child : adj[node])
        {
            if(child != p) {
                if(hlbky[child] >= max_distance) {
                    int temp = dfs(adj, N, child, node, strediska, -1, max_distance, hlbky, najblizsie_centra);
                    najblizsie_centra[node] = min(temp + 1, najblizsie_centra[node]);
                }
            }
        }
        int var = 0;
        for(int child : adj[node])
        {
            if(child != p) {
                var = max(hlbky[child] + 1, var);
            }
        }
        hlbky[node] = var;
        if(hlbky[node] + najblizsie_centra[node] <= max_distance) {
            hlbky[node] = -1;
        }
        if(hlbky[node] == max_distance) {
            strediska[node] = 1;
            hlbky[node] = -1;
            najblizsie_centra[node] = 0; 
        } else {
            najblizsie_centra[node] = N + 1;
        }
    }
    return najblizsie_centra[node];
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
    int right = N-1;
    int middle = 3;

    int min_remembered = N; 
    vector<int> ans;
    vector<int> temp_ans;
    
    while(left<=right) {
        middle = left+(right-left)/2;

        int strediska[N];
        for(int i = 0; i < N; i++) {
            strediska[i] = 0;
        }
        int hlbky[N];
        for(int i = 0; i < N; i++) {
            hlbky[i] = 0;
        }

        dfs2(adj, N, 0, -1, 0, hlbky);

        int najblizsie_centra[N];
        for(int i = 0; i < N; i++) {
            najblizsie_centra[i] = N + 1;
        }

        najblizsie_centra[0] = dfs(adj, N, 0, -1, strediska, -1, middle, hlbky, najblizsie_centra);
        if(najblizsie_centra[0] == N + 1) {
            strediska[0] = 1;
        }

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