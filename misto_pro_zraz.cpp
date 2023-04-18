#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <cmath>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int R; int S; int N;
    cin >> R >> S >> N;
    
    vector<vector<int>> r_array;
    vector<vector<int>> s_array;
    ll sum = 0;

    int r; int s; int n;
    for(int i=0; i < N; i++) {
        cin >> r >> s >> n;
        r_array.push_back(vector{r, n});
        s_array.push_back(vector{s, n});
        sum += n;
    }

    sort(r_array.begin(), r_array.end());
    sort(s_array.begin(), s_array.end());

    sum = sum/2;

    ll t = 0;
    int index = -1;
    while(t <= sum) {
        index++;
        t = t + r_array[index][1];
        
    }

    cout << r_array[index][0] << " ";

    
    t = 0; index = -1;
    while(t <= sum) {
        index++;
        t = t + s_array[index][1];
    }


    cout << s_array[index][0] << "\n";

    return 0;
}