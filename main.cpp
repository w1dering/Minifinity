#include <iostream>
#include <raylib.h>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<char>> makeGrid();

int main()
{
    const int screenWidth = 500;
    const int screenHeight = 500;
    InitWindow(screenWidth, screenHeight, "minifinity");

    SetTargetFPS(60);
    vector<vector<char>> grid = makeGrid();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

vector<vector<char>> makeGrid()
{
    int width = rand() % 3 + 4;
    int height = rand() % 3 + 4;
    vector<vector<char>> grid;
    for (int i = 0; i < height; i++) // initializes empty 2d vector of height rows and width cols
    {
        grid.push_back({}); // makes vectors
        for (int j = 0; j < width; j++)
        {
            if (rand() % 6 == 0)
            {
                grid[i].push_back('#'); // blocked square
            }
            else
            {
                grid[i].push_back(' '); // empty square
            }
        }
    }

}
