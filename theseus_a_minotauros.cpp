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
    
    int W; int H;
    cin >> W >> H;
    
    vector<vector<int>> bludisko(H, vector<int> (W));
    vector<int> game_pos(4);
    vector<int> finish_pos(2);

    vector<vector<vector<vector<int>>>> visited(W, vector<vector<vector<int>>>(H, vector<vector<int>>(W, vector<int>(H, 0))));

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> bludisko[i][j];
            if(bludisko[i][j] == 1) {
                game_pos[0] = j;
                game_pos[1] = i;
            }
            if(bludisko[i][j] == 2) {
                game_pos[2] = j;
                game_pos[3] = i;
            }
            if(bludisko[i][j] == 3) {
                finish_pos = {j, i};
            }
        }
    }

    visited[game_pos[0]][game_pos[1]][game_pos[2]][game_pos[3]] = 1;
    string str_start_pos = to_string(game_pos[0] + 1) + " " + to_string(game_pos[1] + 1) + " " + to_string(game_pos[2] + 1) + " " + to_string(game_pos[3] + 1);

    list<vector<int>> queue;
    queue.push_back(game_pos);
    
    vector<int> current_pos;
    vector<int> next_pos;
    vector<int> dir;
    vector<vector<int>> possible_pos(8);

    unordered_map<string, string> parent;

    while(!queue.empty()) {
        current_pos = queue.front();
        queue.pop_front();

        string str_current_pos = to_string(current_pos[0] + 1) + " " + to_string(current_pos[1] + 1) + " " + to_string(current_pos[2] + 1) + " " + to_string(current_pos[3] + 1);

        possible_pos[0] = {current_pos[0] + 1, current_pos[1],     current_pos[2], current_pos[3]};
        possible_pos[1] = {current_pos[0] + 1, current_pos[1] + 1, current_pos[2], current_pos[3]};
        possible_pos[2] = {current_pos[0],     current_pos[1] + 1, current_pos[2], current_pos[3]};
        possible_pos[3] = {current_pos[0] + 1, current_pos[1] - 1, current_pos[2], current_pos[3]};

        possible_pos[4] = {current_pos[0] - 1, current_pos[1]    , current_pos[2], current_pos[3]};
        possible_pos[5] = {current_pos[0] - 1, current_pos[1] - 1, current_pos[2], current_pos[3]};
        possible_pos[6] = {current_pos[0]    , current_pos[1] - 1, current_pos[2], current_pos[3]};
        possible_pos[7] = {current_pos[0] - 1, current_pos[1] + 1, current_pos[2], current_pos[3]};

        for(int j = 0; j < 8; j++) {
            next_pos = possible_pos[j];
            if(next_pos[0] >= W || next_pos[0] < 0 || next_pos[1] >= H || next_pos[1] < 0) {continue;}
            if(bludisko[next_pos[1]][next_pos[0]] != 4) {
                for(int i = 0; i < 2; i++) {
                    if(next_pos[0] > next_pos[2]) {
                        if(next_pos[1] > next_pos[3]) {
                            dir = {1, 1};
                        } else if(next_pos[1] == next_pos[3]) {
                            dir = {1, 0};
                        } else {
                            dir = {1, -1};
                        }
                    } else if(next_pos[0] == next_pos[2]) {
                        if(next_pos[1] > next_pos[3]) {
                            dir = {0, 1};
                        } else if(next_pos[1] == next_pos[3]) {
                            dir = {0, 0};
                        } else {
                            dir = {0, -1};
                        }
                    } else {
                        if(next_pos[1] > next_pos[3]) {
                            dir = {-1, 1};
                        } else if(next_pos[1] == next_pos[3]) {
                            dir = {-1, 0};
                        } else {
                            dir = {-1, -1};
                        }
                    }
                    if(next_pos[2] + dir[0] < W && next_pos[2] + dir[0] >= 0 && next_pos[3] + dir[1] < H && next_pos[3] + dir[1] >= 0) {
                        if(bludisko[next_pos[3] + dir[1]][next_pos[2] + dir[0]] != 4) {
                            next_pos[2] = next_pos[2] + dir[0];
                            next_pos[3] = next_pos[3] + dir[1];
                        }
                    }
                }
                if(visited[next_pos[0]][next_pos[1]][next_pos[2]][next_pos[3]] != 1) {
                    visited[next_pos[0]][next_pos[1]][next_pos[2]][next_pos[3]] = 1;
                    if(next_pos[0] == next_pos[2] && next_pos[1] == next_pos[3]) {continue;}

                    string str_next_pos = to_string(next_pos[0] + 1) + " " + to_string(next_pos[1] + 1) + " " + to_string(next_pos[2] + 1) + " " + to_string(next_pos[3] + 1);
                    parent.insert({str_next_pos, str_current_pos});
                    queue.push_back(next_pos);

                    if(next_pos[0] == finish_pos[0] && next_pos[1] == finish_pos[1]) {
                        vector<string> ans_path;
                        ans_path.push_back(str_next_pos);
                        string str_prev_pos = str_next_pos;
                        while(str_prev_pos != str_start_pos) {
                            ans_path.push_back(parent.at(str_prev_pos));
                            str_prev_pos = parent.at(str_prev_pos);
                        }
                        int n = ans_path.size();
                        cout << n - 1 << "\n";
                        for(int k = n - 2; k >= 0; k--) {
                            cout << ans_path[k] << "\n";
                        }
                        return 0;
                    }
                }
            }
        }
    }

    cout << "-1\n";

    return 0;
}