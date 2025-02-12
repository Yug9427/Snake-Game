#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>

using namespace std;

enum eDirection { STOP, LEFT, RIGHT, UP, DOWN };

class SnakeGame {
private:
    bool gameOver;
    const int width = 20;
    const int height = 20;
    int x, y, fruitX, fruitY, score;
    vector<int> tailX, tailY;
    eDirection dir;
    
public:
    SnakeGame() {
        Setup();
    }

    void Setup() {
        gameOver = false;
        dir = STOP;
        x = width / 2;
        y = height / 2;
        fruitX = rand() % width;
        fruitY = rand() % height;
        score = 0;
        tailX.clear();
        tailY.clear();
    }

    void Draw() {
        COORD cursorPos = { 0, 0 };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);

        for (int i = 0; i < width + 2; i++) cout << "-";
        cout << endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0) cout << "|";
                if (i == y && j == x)
                    cout << "O";
                else if (i == fruitY && j == fruitX)
                    cout << "F";
                else {
                    bool print = false;
                    for (size_t k = 0; k < tailX.size(); k++) {
                        if (tailX[k] == j && tailY[k] == i) {
                            cout << "o";
                            print = true;
                        }
                    }
                    if (!print) cout << " ";
                }
                if (j == width - 1) cout << "|";
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; i++) cout << "-";
        cout << endl;

        cout << "Score: " << score << endl;
    }

    void Input() {
        if (_kbhit()) {
            switch (_getch()) {
            case 'a':
                if (dir != RIGHT) dir = LEFT;
                break;
            case 'd':
                if (dir != LEFT) dir = RIGHT;
                break;
            case 'w':
                if (dir != DOWN) dir = UP;
                break;
            case 's':
                if (dir != UP) dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
            }
        }
    }

    void Logic() {
        int prevX = (tailX.empty()) ? x : tailX[0];
        int prevY = (tailY.empty()) ? y : tailY[0];
        int prev2X, prev2Y;

        if (!tailX.empty()) {
            tailX.insert(tailX.begin(), x);
            tailY.insert(tailY.begin(), y);
            tailX.pop_back();
            tailY.pop_back();
        }

        switch (dir) {
        case LEFT:  x--; break;
        case RIGHT: x++; break;
        case UP:    y--; break;
        case DOWN:  y++; break;
        default:    break;
        }

        if (x < 0 || x >= width || y < 0 || y >= height)
            gameOver = true;

        for (size_t i = 0; i < tailX.size(); i++)
            if (tailX[i] == x && tailY[i] == y)
                gameOver = true;

        if (x == fruitX && y == fruitY) {
            score += 10;
            fruitX = rand() % width;
            fruitY = rand() % height;
            tailX.push_back(prevX);
            tailY.push_back(prevY);
        }
    }

    void GameLoop() {
        while (!gameOver) {
            Draw();
            Input();
            Logic();
            Sleep(100); // Adjust game speed here
        }
    }
};

int main() {
    SnakeGame game;
    game.GameLoop();
    return 0;
}
