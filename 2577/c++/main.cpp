#include <algorithm>
#include <limits>
#include <utility>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

using Position = pair<int,int>;

void print_map(const map<Position,int>& mp)
{
    cout << "{";
    for (const auto& [k,v]: mp)
    {
        cout << "(" << k.first << "," << k.second << "):" << v << ",";
    }
    cout << "}\n";
}

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        
        // If it's impossible you know it at the start, else you can go back and forth
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        std::map<Position,int> unvisited;
        
        for (std::size_t i = 0; i < grid.size(); ++i)
            for (std::size_t j =0 ; j < grid[0].size(); ++j)
                unvisited[Position(i,j)] = std::numeric_limits<int>::max();

        unvisited[Position(0,0)] = 0;

        auto min = std::min_element(unvisited.begin(),unvisited.end(),
                [&](const auto& a, const auto& b){return a.second < b.second; });

        while((min->first) != Position(int(grid.size()-1), int(grid[0].size()-1)))
        {
            // cout << "---" << "\n";
            // cout << min->first.first << " " << min->first.second << "\n";
            // cout << min->second << "\n";
            // cout << "nei" << "\n";
            for(const auto nei: neigh(min->first,grid))
            {
                if (unvisited.count(nei))
                {
                    
                    // cout << nei.first << " " << nei.second << "\n";
                    int nei_dist = min->second + 1;
                    int min_time = grid[nei.first][nei.second]; 
                    if(nei_dist < min_time) // minimum time to reach the node
                    {
                        if ((min_time - min->second)%2 == 0)
                            nei_dist = min_time + 1; //go back and forth until I can go on it
                        else
                            nei_dist = min_time;
                    }
                        
                    if (nei_dist < unvisited[Position(nei.first,nei.second)])
                    {
                        // cout << "updating value for (" << nei.first << "," << nei.second << ") to " << nei_dist << "\n"; 
                        unvisited[Position(nei.first,nei.second)] = nei_dist;
                    }
                }
            }

            // Remove current element from unvisited
            // print_map(unvisited);
            unvisited.erase(unvisited.find(min->first));

            min = std::min_element(unvisited.begin(),unvisited.end(),
                [&](const auto& a, const auto& b){return a.second < b.second; });
        }

        return min->second;
        
    }

    vector<Position> neigh(Position s, vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<Position> mp;

        if (s.first == n-1){
            if (s.second == m - 1)
            {
                mp.push_back(Position(s.first-1, s.second));
                mp.push_back(Position(s.first, s.second-1));
            }
            else {
                mp.push_back(Position(s.first, s.second + 1));
                mp.push_back(Position(s.first-1, s.second));
                if (s.second > 0)
                    mp.push_back(Position(s.first, s.second - 1));
            }
        }
        else if (s.second == m-1)
        {
            if (s.first > 0)
                mp.push_back(Position(s.first-1, s.second));
            mp.push_back(Position(s.first+1, s.second));
            mp.push_back(Position(s.first, s.second-1));
        }
        else {
            if (s.first > 0)
                mp.push_back(Position(s.first-1,s.second));
            if (s.second > 0)
                mp.push_back(Position(s.first,s.second - 1));
            mp.push_back(Position(s.first + 1, s.second));
            mp.push_back(Position(s.first, s.second + 1));
        }

        return mp;
    } 
};