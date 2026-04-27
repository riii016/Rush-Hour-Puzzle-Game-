#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// Checks if the current cell is valid or not
bool isValid(int rows, int cols, const vector<vector<char>>& maze, const vector<vector<bool>>& visited, int maze_rows, int maze_cols)
{
    // Checks the bounds
    if(rows >= maze_rows || rows < 0 || cols < 0 || cols >= maze_cols)
    {
        return false;
    }
    // Checks teh already visited cells
    if(visited[rows][cols])
    {
        return false;
    }
    // Checks the wall if its 0 (blocked)
    if(maze[rows][cols] == '0')
    {
        return false;
    }
    return true;
}

// Explores the map recursively using backtracking to collect all treasures and exit
void move(int rows, int cols, int collectedT, const vector<vector<char>>& maze, vector<vector<bool>>& visited, int maze_rows, int maze_cols, int totalTreasure, bool& done)
{
    // Direction arrays for moving up, down, left, right
    int move_rows[4] = {-1, 1, 0, 0};
    int move_col[4] = {0, 0, -1, 1};
    
    // Marking the current cells as visited
    visited[rows][cols] = true;
    bool isPicked = false;

    // Collecting treasures if it is present in the current cell
    if(maze[rows][cols] == 'T')
    {
        collectedT++;
        isPicked = true;
    }

    // Printing the visited cell information
    cout << "visit: (" << rows << "," << cols << ")   treasure: " << collectedT << "/" << totalTreasure << endl;

    // Checking if we reached the exit by collecting all the treasures
    if(rows == maze_rows - 1 && cols == 0)
    {
        if(collectedT == totalTreasure)
        {
            cout << "Congratulation! You win." << endl;
            done = true;
            return;
        }
    }

    // Trying to check all the four directions
    for(int i = 0; i < 4; i++)
    {
        int new_row = rows + move_rows[i];
        int new_col = cols + move_col[i];
        if(isValid(new_row, new_col, maze, visited, maze_rows, maze_cols))
        {
            // Recursive calling
            move(new_row, new_col, collectedT, maze, visited, maze_rows, maze_cols, totalTreasure, done);
        // Stop the exploration if the solution is found
        if(done)
        {
            return;
        }
        }
    }

    // Backtracking by unmarking the current cell so that other paths can use it
    visited[rows][cols] = false;

    // Backtracking by uncollecting the treasures if it was picked up at this cell
    if(isPicked)
        {
            collectedT--;
        }
}

int main() 
{
    // 2D grid for the maze
    vector<vector<char>> maze;
    // Tracks which cell was visited
    vector<vector<bool>> visited;
    int maze_rows, maze_cols;
    int totalTreasure = 0;
    bool done = false;
    string line, filename;

    // Prompting the user for a valid filename and loading the maze
    while(true)
    {
        cout << "Enter filename: ";
        cin >> filename;
        ifstream inFile(filename);
        // If no valid file, then error message
        if(!inFile)
        {
            cout << "Error: File '" << filename << "' not found" << endl;
            continue;
        }
    
        // Parsing each line from the file into the maze
        while(getline(inFile,line))
        {
            vector<char> row;
            stringstream ss(line);
            string value;
            // Reading the space separated lines and storing them as valid maze characters
            while(getline(ss, value, ' '))
            {
                if(value == "0" || value == "1" || value == "T")
                {
                    row.push_back(value[0]);
                }
            }
            if(!row.empty())
            {
                maze.push_back(row);
            }
        }
        break;
    }

    maze_rows = maze.size();
    maze_cols = maze[0].size();

    // Counting the total treasures in maze
    for(int i = 0; i < maze_rows; i++)
    {
        for(int j = 0; j < maze_cols; j++)
        {
            if(maze[i][j] == 'T')
            {
                totalTreasure++;
            }
        }
    }

    // Initializing all the visited grid cells as false
    for(int i = 0; i < maze_rows; i++)
    {
        vector<bool> row;
        for(int j = 0; j < maze_cols; j++)
        {
            row.push_back(false);
        }
        visited.push_back(row);
    }

    // Staring teh recursion from top left corner
    move(0, 0, 0, maze, visited, maze_rows, maze_cols, totalTreasure, done);

    // If valid path not found, then it prints the no exit message
    if(!done)
    {
        cout << "No valid path to exit." << endl;
    }
    return 0;
}