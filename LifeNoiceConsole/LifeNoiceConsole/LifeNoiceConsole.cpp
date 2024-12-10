#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

using namespace std;



const int len = 40;
const int height = 40;
string grid[len][height] = {};
bool start = true;
void random()
{
    srand(time(NULL));
    float r = rand();
    srand(r);
    srand(rand());
}
int randCellX()
{
    int xR = rand() % 2 - rand() % 2;
    int yR = rand() % 2 - rand() % 2;
    if (xR == 0)
    {
        randCellX();
    }
    else
    {
        return xR;
    }
    return randCellX();
}
void makeOne()
{
    string screen = "";
    int k = 1;
    for (int x = 0;x < len;x++)
    {
        for (int y = 0;y < height;y++)
        {
            if (grid[x][y] == "")
            {
                grid[x][y] = " ";
            }
            

            if (start)
            {
                grid[len / 2 + 1][height / 2 + 1] = "@";
                start = !start;
            }
            
            if (grid[x][y] != "" && k == 1)
            {
                if (grid[x + 1][y] == "@" || grid[x - 1][y] == "@" || grid[x][y + 1] == "@" || grid[x][y - 1] == "@" ||
                    grid[x + 1][y + 1] == "@" || grid[x + 1][y - 1] == "@" || grid[x - 1][y + 1] == "@" || grid[x - 1][y - 1] == "@")
                {
                    int dogC = 1;
                    for (int cIn = 0;cIn < size(screen);cIn++)
                    {
                        char ch = screen[cIn];
                        if (ch == *"@")
                        {
                            dogC++;
                        }
                    }
                    if (rand() % dogC == 1)
                    {
                        int xR = randCellX();
                        int yR = rand() % 2 - rand() % 2;
                        //cout << x << endl;
                        try
                        {
                            grid[x + xR][y + yR] = "@";
                            k = 0;
                        }
                        catch (const exception& ex)
                        {
                            k = 0;
                        }
                    }
                    
                }
            }

            screen.append(grid[x][y]);
        }
        screen.append("\n");
        
    }
    if (k == 0)
    {
        cout << screen;

        this_thread::sleep_for(chrono::milliseconds(300));
        for (int i = 0;i < 100;i++)
        {
            cout << "\n";
        }
    }
    
    
    
}

int main()
{
    setlocale(LC_ALL, "RU");
    while (true)
    {
        random();   
        makeOne();
    }
    

    return 0;
}