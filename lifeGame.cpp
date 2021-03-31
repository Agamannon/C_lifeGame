#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>

using namespace std;

void show_map(int life_map[][12])
{
    for(int y=10; y>=1; y--)
    {
        for(int x=1; x<11; x++)
        {
            cout<<" "<<life_map[y][x];
        }
        cout<<endl;
    }
}

/*
游戏规则：

接触位_8位：
1 2 3
4 * 5
6 7 8

新生：*为0，接触位有1~2位，*下一轮变为1.
(*为0，接触位有3~8位，*下一轮不变)
延续：*为1，接触位有1~5位，*下一轮不变。
死亡：*为1，接触位有0或6~8位，*下一轮变为0.
*/

int main()
{

    int life_map[12][12];
    int x, y;

    // 设置种子
    srand( (unsigned)time(NULL) );

    for(y=11; y>=0; y--)
    {
        for(x=0; x<12; x++)
        {
            if(y==0||y==11)
                life_map[y][x] = 0;
            else if (x==0||x==11)
                life_map[y][x] = 0;
            else
                life_map[y][x] = rand()%2;
        }
    }    
    
    show_map(life_map);

    system("pause");
    return 0;
}