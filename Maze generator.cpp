#include <iostream>

struct Position { int row, col; };

void print_maze(char** maze, const int rows, const int cols) {
    for (int i = 0; i < cols + 2; i++) {
        std::cout << "_";
    }
    std::cout << std::endl;
    for (int i = 0; i < rows; i++) {
        std::cout << "|";
        for (int j = 0; j < cols; j++) {
            std::cout << maze[i][j];
        }
        std::cout << "|" << std::endl;
    }
    for (int i = 0; i < cols + 2; i++) {
        std::cout << "-";
    }
}

void generate_maze(const int rows, const int cols) {
    char** maze = new char* [rows];
    for (int i = 0; i < rows; i++) {
        maze[i] = new char[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze[i][j] = ' ';
        }
    }
    Position start_pos, finish_pos;
    start_pos.row = rand() % rows;
    start_pos.col = rand() % cols;

    while (true) {
        finish_pos.row = rand() % rows;
        finish_pos.col = rand() % cols;
        if (finish_pos.row != start_pos.row && finish_pos.col != start_pos.col) break;
    }
    maze[start_pos.row][start_pos.col] = 's';
        
    int i;
    int row_slide = 0, col_slide = 0;
    Position direction;
    direction.row = start_pos.row; direction.col = start_pos.col;

    for (i = 0; i < 1000; i++) {
        direction.row = start_pos.row; direction.col = start_pos.col;
        row_slide = (rand() % 3 - 1) * 2;
        col_slide = (rand() % 3 - 1) * 2;
        
        direction.row += row_slide;
        direction.col += col_slide;

        if (direction.row < 0 || direction.row >= rows || direction.col < 0 || direction.col > cols) {
            continue;
        }
        start_pos.row = direction.row;
        start_pos.col = direction.col;

        maze[start_pos]
    }

    print_maze(maze, rows, cols);
    std::cout << "\nNum of iterations: " << i;
}

int main()
{
    srand(time(0));
    int rows, cols;
    std::cout << "Enter rows and columns of maze: "; std::cin >> rows >> cols;
    if (rows <= 0 || cols <= 0) {
        std::cout << "rows/columns cannot be less than 0\n";
        return 0;
    }
    
    for (int i = 0; i < 9; i++) {
        std::cout << (rand() % 3 - 1) * 2 << " ";
    }
    std::cout << std::endl;

    generate_maze(rows, cols);

    return 0;
}
