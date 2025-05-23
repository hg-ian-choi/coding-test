#include <vector>
using namespace std;

class IslandPerimeter {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.at(i).size(); j++) {
                if (grid.at(i).at(j)) {
                    cnt += 4;
                    if (i > 0 && grid.at(i - 1).at(j)) {
                        cnt -= 2;
                    }
                    if (j > 0 && grid.at(i).at(j - 1)) {
                        cnt -= 2;
                    }
                }
            }
        }
        return cnt;
    }


    // Solution
    int solution(vector<vector<int>> &grid) {
        int count = 0, repeat = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    count++;
                    if (i != 0 && grid[i - 1][j] == 1) {
                        repeat++;
                    }
                    if (j != 0 && grid[i][j - 1] == 1) {
                        repeat++;
                    }
                }
            }
        }
        return 4 * count - repeat * 2;
    }
};
