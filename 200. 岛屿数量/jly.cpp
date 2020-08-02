/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<pair<int, int>>> root;
    int count_;
    pair<int, int> findRoot(int i, int j) {
        int x = root[i][j].first;
        int y = root[i][j].second;
        //cout << "findRoot" << endl;
        //cout << "x=" << x << "y=" << y << endl;
        if (x == 0 && y == 0)
            cout << "print:" << root[0][0].first << " " << root[0][0].second << endl;
        if (x == i && y == j) {
            return root[i][j];
        } else {
            return findRoot(x, y);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        count_ = 0;
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            root.push_back(vector<pair<int, int>>(n, pair<int, int>(-1, -1)));
        }
        //cout << "ini"<< endl;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < n; j++) {
                //cout << i << " " << j << endl;
                //cout << "count:" << count_ << endl;
                if (grid[i][j] == '1') {
                    if (i-1 >= 0 && grid[i-1][j] == '1')
                        root[i][j] = make_pair(i-1, j);
                    else if (j - 1 >= 0 && grid[i][j-1] == '1') {
                        root[i][j] = make_pair(i, j-1);
                    } else {
                        root[i][j] = make_pair(i, j);
                        count_ ++;
                    }
                    
                    if (i-1 >=0 && j-1 >= 0 && grid[i-1][j] == '1' && grid[i][j-1] == '1') {
                        pair<int, int> rootA = findRoot(i, j-1);
                        pair<int, int> rootB = findRoot(i-1, j);
                        if (rootA.first == rootB.first && rootA.second == rootB.second)
                            continue;
                        root[rootA.first][rootA.second] = rootB;
                        count_--;
                    }
                }
            }
        }
        return count_;
    }
};
