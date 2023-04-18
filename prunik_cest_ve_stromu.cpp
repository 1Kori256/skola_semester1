#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


void dfs(vector<int> adj[], int node, int l,
            int p, int lvl[], int par[])
{
    lvl[node] = l;
    par[node] = p;
;
    for(int child : adj[node])
    {
        if(child != p)
        dfs(adj, child, l+1, node, lvl, par);
    }
}

void dfs2(vector<int> adj[], int node, int p, int m_p, int i, int data_top[], int data_index[], vector<int> &rev_p)
{
    data_top[node] = m_p;
    data_index[node] = i;
;   

    for(int child : adj[node])
    {
        if(child != p && rev_p[child] == 0) {
        if(node == m_p) {i++;}
        dfs2(adj, child, node, m_p, i, data_top, data_index, rev_p);}
    }
}

int LCA(int a, int b, int par[], int lvl[])
{ 

   if(lvl[a] > lvl[b])
    swap(a, b);
   
   int diff = lvl[b] - lvl[a];
   while(diff != 0)
   {
      b = par[b];
      diff--;
   }
    
   if(a == b)
    return a;
    
   while(a != b)
    a=par[a], b=par[b];
 
   return a;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, p;
    cin >> n >> p;
    vector<int> adj[n];
 
    int inp1, inp2;
    for(int i = 0; i < n - 1; i++) {
        cin >> inp1 >> inp2;
        adj[inp1].push_back(inp2);
        adj[inp2].push_back(inp1);
    }

    vector<vector<int>> paths(p, vector<int>(2));
    for(int i = 0; i < p; i++) {
        cin >> paths[i][0] >> paths[i][1];
    }

    int lvl[n+1];
    int par[n+1];
   
    dfs(adj, 1, 0, -1, lvl, par);
    
    int a = paths[0][0];
    int b = paths[0][1];
    int lca = LCA(a, b, par, lvl);
   
    vector<int> path;
    while(a != lca)
      path.push_back(a), a = par[a];
    path.push_back(a);
    vector<int> temp;
    while(b != lca)
      temp.push_back(b), b=par[b];
    reverse(temp.begin(), temp.end());
    for(int x : temp)
      path.push_back(x);

    int data_top[n];
    int data_index[n];
    vector<int> rev_path(n, 0);
    for (int pr = 0; pr < path.size(); pr++) {
        rev_path[path[pr]] = pr;
    }
        
    for (int pr = 0; pr < path.size(); pr++) {
        dfs2(adj, path[pr], -1, path[pr], 0, data_top, data_index, rev_path);
    }

    int lft = 0, rght = path.size() - 1;
    int mn, mx;

    for (int i = 1; i < p; i++) {

        mn = min(rev_path[data_top[paths[i][0]]], rev_path[data_top[paths[i][1]]]);
        mx = max(rev_path[data_top[paths[i][0]]], rev_path[data_top[paths[i][1]]]);
        lft = max(lft, mn);
        rght = min(rght, mx);
        if (rev_path[data_top[paths[i][0]]] == rev_path[data_top[paths[i][1]]] && data_index[paths[i][0]] == data_index[paths[i][1]]) {
            cout << "\n";
            return 0;
        }
    }

    vector<int> ans;
    for (int i = lft; i <= rght; i++) {
        ans.push_back(path[i]);
    }
    
    sort(ans.begin(), ans.end());

    bool first = 1;
    for(int i = 0; i < ans.size(); i++) {
        if (!first) {
            cout << " ";
        }
        cout << ans[i];
        first = 0;
    }

    return 0;
}