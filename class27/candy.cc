#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Recursive function to find best candy path
 * 
 * TODO: return path itself.
 */
int find_best_candy_path(vector<vector<int>> grid, int row, int col) {
    int rows = grid.size();
    int cols = grid[0].size();

    // cout << "row and col: " << row << " and " << col << endl;

    // Base case: made it to lower-right corner
    if (row == rows - 1 && col == cols - 1)
        return grid[row][col];

    int choose_down = 0;
    int choose_right = 0;

    if (row != rows - 1) {
        choose_down = find_best_candy_path(grid, row + 1, col);
    }

    if (col != cols - 1) {
        choose_right = find_best_candy_path(grid, row, col + 1);
    }
    
    if (choose_down > choose_right)
        return choose_down + grid[row][col];
    else
        return choose_right + grid[row][col];

}

int main() {

    // Read in a grid using a vector of vectors
    int rows, cols, num;
    cin >> rows >> cols;

    vector<vector<int>> grid;

    for (int r = 0; r < rows; r++) {
        vector<int> row; // empty by default

        for (int c = 0; c < cols; c++) {
            cin >> num;
            row.push_back(num);
        }

        grid.push_back(row);
    }

    // Can access elements in 2D:
    cout << grid[0][2] << endl;
    cout << grid[1][0] << endl;

    int best_candy = find_best_candy_path(grid, 0, 0);

    cout << "most candy you can get: " << best_candy << endl;

}