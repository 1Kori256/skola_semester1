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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N; 
    
    vector<vector<int>> prednasky(N);

    for(int i = 0; i < N; i++) {;
        prednasky[i].resize(3);
        cin >> prednasky[i][1] >> prednasky[i][0];
        prednasky[i][2] = i + 1;
    }
    sort(prednasky.begin(), prednasky.end());

    vector<int> ans;
    ans.push_back(0);
    int r1 = prednasky[ans[0]][0];

    for (int i = 1; i < prednasky.size(); i++) {
        int l1 = prednasky[i][1];
        int r2 = prednasky[i][0];
 
        if (l1 > r1) {
            ans.push_back(i);
            r1 = r2;
        }
    }

    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << prednasky[ans[i]][2];
    }

    cout << "\n";

    return 0;
}