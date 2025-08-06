#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:


    int closedIsland(vector<vector<int>>& grid) {
        
        vector<vector<bool>> visited;

        for (std::size_t row=0; row < grid.size(); ++row)
        {
            vector<bool> inner_visit;
            for (std::size_t col=0; col< grid[0].size(); ++col)
                inner_visit.push_back(false);

            visited.push_back(inner_visit);
        }
 
        int n_islands = 0;
        
        for (std::size_t row=0; row < grid.size(); ++row){
            for (std::size_t col = 0; col < grid[0].size(); ++col)
            {
                bool res = is_island(row,col,grid,visited);
                if (res){
                    // cout << row << "," << col << " is an island" << std::endl;
                    n_islands += 1;
                }
            }
        }

        return n_islands;
    }

    bool is_island(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited)
    {
        // boundary checking
        // cout << "checking " << i << "," << j << std::endl;

        if(!is_connected(row,col, grid))
            return false;

        // If I have already visited it, it is connected to something else
        if(visited[row][col])
            return false;

        if(grid[row][col] == 1)
            return false;

        visited[row][col] = true;

        bool res = true;

        if(grid[row+1][col] == 0 && visited[row+1][col] == false){
            bool r = is_island(row+1, col, grid, visited);
            res = res && r;
        }
        if(grid[row-1][col] == 0 && visited[row-1][col] == false)
        {
            bool r = is_island(row-1, col, grid, visited);
            res = res && r;
        }
        if(grid[row][col+1] == 0 && visited[row][col+1] == false)
        {
            bool r = is_island(row, col+1, grid, visited);
            res = res && r;
        }
        if(grid[row][col-1] == 0 && visited[row][col-1] == false)
        {
            bool r = is_island(row, col-1, grid, visited);
            res = res && r;
        }
        return res;

    }

    bool is_connected(int row, int col, vector<vector<int>>& grid)
    {
        if (col == grid[0].size()-1)
            return false; // right border
        else if (col == 0)
            return false; //left border
        else if (row == 0)
            return false; //top border
        else if (row == grid.size()-1)
            return false; // bottom border
        else
            return true;
    }
};

void print_grid(vector<vector<int>>& grid)
{
    for (const auto& line: grid){

        for (const auto i: line)
            i ? cout << "*" : cout << " ";

        cout << "\n";
    }


}

int main()
{
    vector<vector<int>> grid = {{0,0,1,1,0,1,0,0,1,0},{1,1,0,1,1,0,1,1,1,0},{1,0,1,1,1,0,0,1,1,0},{0,1,1,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,1,1,0},{0,1,0,1,0,1,0,1,1,1},{1,0,1,0,1,1,0,0,0,1},{1,1,1,1,1,1,0,0,0,0},{1,1,1,0,0,1,0,1,0,1},{1,1,1,0,1,1,0,1,1,0}};
    print_grid(grid);
}

