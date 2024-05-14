#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool dfs(std::vector<std::vector<char>>& grid, int i, int j, std::vector<std::vector<bool>>& visited) {
        if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || visited[i][j]) {
            return false;
        }

        int rows = grid.size();
        int cols = grid[0].size();
        std::queue<std::pair<int, int>> qu;
        qu.push(std::make_pair(i, j));
        while (!qu.empty()) {
            auto coor = qu.front();
            int coor_i = coor.first;
            int coor_j = coor.second;
            if (coor_j + 1 < cols && grid[coor_i][coor_j + 1] == '1' && !visited[coor_i][coor_j+1]) {
                qu.push(std::make_pair(coor_i, coor_j+1));
                visited[coor_i][coor_j + 1] = true;
            }
            if (coor_j - 1 >= 0 && grid[coor_i][coor_j - 1] == '1' && !visited[coor_i][coor_j-1]) {
                qu.push(std::make_pair(coor_i, coor_j - 1));
                visited[coor_i][coor_j - 1] = true;
            }
            if (coor_i + 1 < rows && grid[coor_i + 1][coor_j] == '1' && !visited[coor_i + 1][coor_j]) {
                qu.push(std::make_pair(coor_i + 1, coor_j));
                visited[coor_i + 1][coor_j] = true;
            }
            if (coor_i - 1 >= 0 && grid[coor_i - 1][coor_j] == '1' && !visited[coor_i - 1][coor_j]) {
                qu.push(std::make_pair(coor_i - 1, coor_j));
                visited[coor_i - 1][coor_j] = true;
            }
            visited[coor_i][coor_j] = true;
            qu.pop();
        }
        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int island_cnt = 0;
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    if (dfs(grid, i, j, visited)) {
                        island_cnt++;
                    }
                    j += 1;
                } 
            }
        }
        return island_cnt;
    }
};