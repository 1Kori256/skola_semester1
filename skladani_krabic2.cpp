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

int getResult(vector<vector<int>> &input)
{
   for(auto& x:input)
   {
       sort(begin(x), end(x));
   }
   input.push_back({0, 0, 0});
   sort(begin(input), end(input));

   int n = input.size();
   int result = 0;
   vector<int> dp(n);
   for(int i = 1 ; i < n ; i++)
   {
       for(int j = 0; j < i ; j++)
       {
           if(input[j][0] <= input[i][0] && input[j][1] <= input[i][1] && input[j][2] <= input[i][2])
           {
               dp[i] = max(dp[i], dp[j] + input[i][2]);
               result = max(result, dp[i]);
           }
       }
   }
   return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    

    int N;
    cin >> N;
    vector<vector<int>> input(N, vector<int>(3));

    int a, b, c;
    for(int i=0; i < N; i++) {
        cin >> a >> b >> c;
        input[i][0] = a;
        input[i][1] = b;
        input[i][2] = c;
    }

    cout << "Total Number of Boxes: " << input.size() << endl;
    cout << "Dimensions of each Box: " << endl;
    for(int i = 0 ; i < input.size() ; i++)
    {
        for(int j = 0 ; j < 2 ; j++)
        {
            cout << input[i][j] << " * ";
        }
        cout << input[i][2] << endl;
    }

    cout << "The Maximum possible Height of the Stack is: " << getResult(input) << endl;

    return 0;
}