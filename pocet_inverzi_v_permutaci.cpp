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


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

    int ans = 0;
    vector<int> counts(n + 1, 0);

    for(int u = n - 1; u >= 0; u--) {
        int i = v[u];
        while(i) {
            ans += counts[i];
            i -= (i & -i);
        }
        i = v[u] + 1;
        while(i <= n) {
            counts[i] += 1;
            i += (i & -i);
        }
    }

    cout << ans << "\n";

    return 0;
}