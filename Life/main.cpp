#include <iostream>
#include <ctime>
#include <stdlib.h>


using namespace std;

bool **square;
int iterations;
long long born, dead, originAlive, alive, squareWidth, squareHeight, invariantAlive = 1, lastAlive;

void initial(bool **&arr, long long width, long long height) {
    arr = new bool *[height];
    for (long long i = 0; i < height; ++i) {
        arr[i] = new bool[width]();
    }
}

void copy_and_free(bool **&purpose, bool **&source, long long width, long long height) {
    delete[] purpose;

    purpose = new bool *[height];
    for (long long i = 0; i < height; ++i) {
        purpose[i] = new bool[width];
        for (long long j = 0; j < width; ++j) {
            purpose[i][j] = source[i][j];
        }
    }
    delete[] source;
}

long long count_neighbours(long long x, long long y) {
    long long result = 0;

    if (y + 1 < squareHeight) {
        if (x + 1 < squareWidth) if (square[y + 1][x + 1]) ++result;
        if (square[y + 1][x]) ++result;
        if (x - 1 >= 0) if (square[y + 1][x - 1]) ++result;
    }
    if (y - 1 >= 0) {
        if (x + 1 < squareWidth) if (square[y - 1][x + 1]) ++result;
        if (square[y - 1][x]) ++result;
        if (x - 1 >= 0) if (square[y - 1][x - 1]) ++result;
    }
    if (x + 1 < squareWidth) if (square[y][x + 1]) ++result;
    if (x - 1 >= 0) if (square[y][x - 1]) ++result;

    return result;
}

void inc_capacity(string side) {
    long long oldWidth = squareWidth, oldHeight = squareHeight;
    long long horizontalShift = 0, verticalShift = 0;

    if (side == "horizont") {
        squareWidth *= 2;
        horizontalShift = squareWidth / 4;
    } else {
        squareHeight *= 2;
        verticalShift = squareHeight / 4;
    }

    bool **tempField;
    initial(tempField, squareWidth, squareHeight);

    for (long long y = 0; y < oldHeight; ++y)
        for (long long x = 0; x < oldWidth; ++x)
            tempField[y + verticalShift][x + horizontalShift] = square[y][x];

    copy_and_free(square, tempField, squareWidth, squareHeight);
}

void check_borders() {
    for (long long y = 0; y < squareHeight; ++y)
        if (square[y][0] || square[y][squareWidth - 1]) {
            inc_capacity("horizont");
            break;
        }

    for (long long x = 0; x < squareWidth; ++x)
        if (square[0][x] || square[squareHeight - 1][x]) {
            inc_capacity("vertical");
            break;
        }
}


void next_iteration() {
    check_borders();

    try {
        bool **tempField;
        initial(tempField, squareWidth, squareHeight);

        alive = 0;

        for (long long y = 0; y < squareHeight; ++y) {
            for (long long x = 0; x < squareWidth; ++x) {
                long long neighbour = count_neighbours(x, y);
                if (square[y][x]) {
                    if (neighbour == 2 || neighbour == 3) {
                        tempField[y][x] = 1;
                        ++alive;
                    } else {
                        ++dead;
                    }
                } else {
                    if (neighbour == 3) {
                        tempField[y][x] = 1;
                        ++alive;
                        ++born;
                    }
                }
            }
        }

        copy_and_free(square, tempField, squareWidth, squareHeight);
    }
    catch (std::bad_alloc) {
    }
}
void output_stats() {
    cout << "Alive cells: " << alive << '.' << endl;
    cout << "Born / Dead: " << born << " / " << dead << endl << endl;
}

void output_main_stats() {
    cout << "Simulation finished." << endl;
    cout << "Inc of population: " << alive - originAlive << " cells." << endl;
    if (invariantAlive != iterations - 1) {
        cout << "Amount of cells hasn't changed from steps #" << invariantAlive << '.' << endl << endl;
    }
}

int main() {
    cout << "Enter width and height of square:" << endl;
    cin >> squareWidth >> squareHeight;
    cout << endl << "Cells:" << endl;
    cin >> originAlive;
    cout << endl << "Amount of steps:" << endl;
    cin >> iterations;

    initial(square, squareWidth, squareHeight);


    srand(time(NULL));
    long long p = 0;
    long long xx, yy;
    while (p < originAlive) {
        long long x = rand() % squareWidth;
        long long y = rand() % squareHeight;
        if (square[y][x] != 1) {
            square[y][x] = 1;
            ++p;
            xx = x;
            yy = y;
        }
    }
    cout << "X = " << xx << endl;
    cout << "Y = " << yy << endl;

    lastAlive = originAlive;
    for (long long i = 1; i <= iterations; ++i) {
        next_iteration();
        if (i % 10 == 0) {
            output_stats();
            born = dead = 0;
        }
        if (lastAlive != alive) {
            lastAlive = alive;
            invariantAlive = i;
        }
        if (alive == 0) break;
    }

    output_main_stats();
    return 0;
}