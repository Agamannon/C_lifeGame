#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>

using namespace std;

void show_map(int life_map[][10])
{
    for(int y=9; y>=0; y--)
    {
        for(int x=0; x<10; x++)
        {
            cout<<" "<<life_map[x][y];
        }
        cout<<endl;
    }
}

int main()
{

    int life_map[10][10];
    int x, y;

    // 设置种子
    srand( (unsigned)time(NULL) );

    int n = 100;
    while (n--)
    {
        x = n / 10;
        y = n % 10;
        life_map[x][y] = rand() % 2;//随机生成map，值0，1
        // life_map[x][y] = x*10 + y;
    }
    
    show_map(life_map);

    system("pause");
    return 0;
}