#include <iostream>
#include <vector>
#include <limits>
using namespace std;

string longest_downhill_path_helper(vector<vector<int>> grid, int row, int col, int prev_height) {

    // Base case: location not in grid:
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
        return "";

    int curr_height = grid[row][col];

    // Base case 2: if current height is >= previous height:
    if (curr_height >= prev_height)
        return "";

    // Make recursive calls in each direction
    string up_path = 'U' + longest_downhill_path_helper(grid, row - 1, col, curr_height);
    string down_path = 'D' + longest_downhill_path_helper(grid, row + 1, col, curr_height);
    string left_path = 'L' + longest_downhill_path_helper(grid, row, col - 1, curr_height);
    string right_path = 'R' + longest_downhill_path_helper(grid, row, col + 1, curr_height);

    // Pick whichever is longest
    string best_path = "";

    if (down_path.size() > best_path.size())
        best_path = down_path;
    if (left_path.size() > best_path.size())
        best_path = left_path;
    if (right_path.size() > best_path.size())
        best_path = right_path;
    if (up_path.size() > best_path.size())
        best_path = up_path;

    return best_path;
}

string longest_downhill_path(vector<vector<int>> grid, int row, int col) {
    int prev_height = grid[row][col] + 1;
    string result = longest_downhill_path_helper(grid, row, col, prev_height);
    result.pop_back();
    return result;
}

int main() {

    // Read in a grid using a vector of vectors
    int rows, cols, num;
    cin >> rows >> cols;

    int start_row, start_col;
    cin >> start_row >> start_col;

    vector<vector<int>> grid;

    for (int r = 0; r < rows; r++) {
        vector<int> row; // empty by default

        for (int c = 0; c < cols; c++) {
            cin >> num;
            row.push_back(num);
        }

        grid.push_back(row);
    }

    string path = longest_downhill_path(grid, start_row, start_col);

    cout << "Best path: " << path << endl;

}