// 1AC, solution using BFS
#include <queue>
using namespace std;

class Solution {
public:
    Solution() {
        d[0][0] = -1;
        d[0][1] = 0;
        d[1][0] = +1;
        d[1][1] = 0;
        d[2][0] = 0;
        d[2][1] = -1;
        d[3][0] = 0;
        d[3][1] = +1;
    }

    int numIslands(vector<vector<char>> &grid) {
        n = grid.size();
        if (n == 0) {
            return 0;
        }
        m = grid[0].size();
        if (m == 0) {
            return 0;
        }
        
        int cc = 0;
        int i, j;
        
        b.resize(n, vector<bool>(m, false));
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                if (grid[i][j] == '1' && !b[i][j]) {
                    BFS(i, j, grid);
                    ++cc;
                }
            }
        }
        b.clear();
        
        return cc;
    }
protected:
    int n, m;
    vector<vector<bool> > b;
    int d[4][2];
    
    void BFS(int x, int y, vector<vector<char> > &grid) {
        queue<int> q;
        int i;
        int x1, y1;
        int p;
        
        q.push(x * m + y);
        b[x][y] = true;
        while (!q.empty()) {
            p = q.front();
            q.pop();
            x = p / m;
            y = p % m;
            for (i = 0; i < 4; ++i) {
                x1 = x + d[i][0];
                y1 = y + d[i][1];
                if (x1 < 0 || x1 > n - 1 || y1 < 0 || y1 > m - 1) {
                    continue;
                }
                if (grid[x1][y1] == '0' || b[x1][y1]) {
                    continue;
                }
                q.push(x1 * m + y1);
                b[x1][y1] = true;
            }
        }
    }
};