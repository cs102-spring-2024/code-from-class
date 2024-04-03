#include <iostream>
#include <vector>
using namespace std;

class CandyPair {
public:
    int _candies;
    string _path;

    CandyPair(int c, string p) {
        _candies = c;
        _path = p;
    }
};

/**
 * @brief Recursive function to find best candy path
 * 
 * TODO: return path itself.
 */
CandyPair find_best_candy_path(vector<vector<int>> grid, int row, int col) {
    int rows = grid.size();
    int cols = grid[0].size();

    // cout << "row and col: " << row << " and " << col << endl;

    // Base case: made it to lower-right corner
    if (row == rows - 1 && col == cols - 1)
        return CandyPair(grid[row][col], "");

    CandyPair choose_down(0, "");
    CandyPair choose_right(0, "");

    if (row != rows - 1) {
        choose_down = find_best_candy_path(grid, row + 1, col);
    }

    if (col != cols - 1) {
        choose_right = find_best_candy_path(grid, row, col + 1);
    }
    
    if (choose_down._candies > choose_right._candies) {
        int candies = choose_down._candies + grid[row][col];
        string path = 'D' + choose_down._path;
        return CandyPair(candies, path);
    }
    else {
        int candies = choose_right._candies + grid[row][col];
        string path = 'R' + choose_right._path;
        return CandyPair(candies, path);
    }

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

    CandyPair best_candy = find_best_candy_path(grid, 0, 0);

    cout << "most candy you can get: " << best_candy._candies << endl;
    cout << "Here's the path to get those candies: " << best_candy._path << endl;

}