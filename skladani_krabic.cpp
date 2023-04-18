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


template<class ForwardIt, class T>
ForwardIt lb(ForwardIt first, ForwardIt last, const T& value)
{
    ForwardIt it;
    typename std::iterator_traits<ForwardIt>::difference_type count, step;
    count = std::distance(first, last);
 
    while (count > 0)
    {
        it = first; 
        step = count / 2; 
        std::advance(it, step);
 

        vector<int> x = *it;
        if ((x[0] <= value[0] && x[1] <= value[1] && x[2] <= value[2]) && (x[0] < value[0] || x[1] < value[1] || x[2] < value[2]))
        {
            first = ++it; 
            count -= step + 1; 
        }
        else
            count = step;
    }
    return first;
}


int tst(vector<vector<int>>& v)
{
 
    vector<vector<int>> tail(v.size(), vector<int>(2, 0));
    int length = 1;
 
    tail[0] = v[0];
 
    for (int i = 1; i < v.size(); i++) {
 
        auto b = tail.begin(), e = tail.begin() + length;
        auto it = lb(b, e, v[i]);

        if (it == tail.begin() + length)
            tail[length++] = v[i];
        else
            *it = v[i];
    }
 
    return length;
}

int tst2(vector<vector<int>>& arr)
{
    vector<vector<int>> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        auto it
            = lb(ans.begin(), ans.end(), arr[i]);
        if (it == ans.end()) {
            ans.push_back(arr[i]);
        }
        else {
            *it = arr[i];
        }
    }

    return ans.size();
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;

    vector<vector<int>> boxes(6*N, vector<int>(3));

    int a, b, c;
    for(int i=0; i < 6*N; i=i+6) {
        cin >> a >> b >> c;
        boxes[i][0] = a;
        boxes[i][1] = b;
        boxes[i][2] = c;

        boxes[i+1][0] = a;
        boxes[i+1][1] = c;
        boxes[i+1][2] = b;

        boxes[i+2][0] = b;
        boxes[i+2][1] = a;
        boxes[i+2][2] = c;

        boxes[i+3][0] = b;
        boxes[i+3][1] = c;
        boxes[i+3][2] = a;

        boxes[i+4][0] = c;
        boxes[i+4][1] = a;
        boxes[i+4][2] = b;

        boxes[i+5][0] = c;
        boxes[i+5][1] = b;
        boxes[i+5][2] = a;

    }   
    
    sort(boxes.begin(), boxes.end());

    int ans;
    ans = tst2(boxes);

    return 0;
}