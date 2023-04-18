#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <queue>
#include <map>
typedef long long ll;
using namespace std;


ll LcmOfArray(vector<ll> arr, ll idx){
    if (idx == arr.size()-1){
        return arr[idx];
    }
    ll a = arr[idx];
    ll b = LcmOfArray(arr, idx+1);
    return (a*b/__gcd(a,b));
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    std::ifstream myfile ("pravidla.in");
    ll n;

    if ( myfile.is_open() ) {
        myfile >> n;
    }
        
    vector<ll> m(n+1);
    ll i, j;
    for (ll x = 0; x < n; x++) {
        myfile >> i >> j;
        m[i] = j;
    }    
    
    vector<ll> visited(n+1, 0);
    vector<ll> cycle_lens;
    ll current_cycle = 0;

    for (ll i = 1; i < n + 1; i++) {
        while (visited[i] == 0) {
            current_cycle++;
            visited[i] = 1;
            i = m[i];
        }
        if (current_cycle != 0) {
            cycle_lens.push_back(current_cycle);
            current_cycle = 0;
        }
    }

    cout << LcmOfArray(cycle_lens, 0) << "\n";

    return 0;
}