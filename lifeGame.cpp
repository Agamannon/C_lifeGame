#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>

/*
游戏规则：

接触位_8位：
1 2 3
4 * 5
6 7 8

新生：*为0，接触位有1~2位，*下一轮变为1.
(*为0，接触位有0或3~8位，*下一轮不变)
延续：*为1，接触位有1~5位，*下一轮不变。
死亡：*为1，接触位有0或6~8位，*下一轮变为0.
*/

using namespace std;

// map real length
#define mr_length 12

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
    cout<<"-------------------------------"<<endl;
}

void DeadorAlive(int* point)
{
    //设置八个接触位
    int *left, *left_top, *top, *right_top, *right, *right_under, *under, *left_under;
    left = point - 1;
    right = point + 1;
    top = point - mr_length;
    left_top = top - 1;
    right_top = top + 1;
    under = point + mr_length;
    left_under = under - 1;
    right_under = under + 1;

    //use rough(粗暴的) method to count the touch alive count
    int touch_alive_count = 0;
    if(*left == 1)  // 直接 if(*left)行吗，应该行吧
        touch_alive_count++;
    if(*right == 1)
        touch_alive_count++;
    if(*top == 1)
        touch_alive_count++;
    if(*left_top == 1)
        touch_alive_count++;
    if(*right_top == 1)
        touch_alive_count++;
    if(*under == 1)
        touch_alive_count++;
    if(*left_under == 1)
        touch_alive_count++;
    if(*right_under == 1)
        touch_alive_count++;

    // dead or alive rules
    if(*point) // if *point == 1
    {
        if(touch_alive_count == 0 || touch_alive_count > 5)
            *point = 0;
    }
    else
    {
        if(touch_alive_count == 1 || touch_alive_count == 2)
            *point = 1;
    }
    //no need to retuen
}

int main()
{

    int life_map[mr_length][mr_length];
    int x, y;

    // 设置种子
    srand( (unsigned)time(NULL) );

    //初始化地图
    for(y = mr_length-1; y >= 0; y--)
    {
        for(x = 0; x <= mr_length-1; x++)
        {
            if(y == 0 || y == mr_length - 1)
                life_map[y][x] = 0;
            else if (x == 0 || x == mr_length -1)
                life_map[y][x] = 0;
            else
                life_map[y][x] = rand()%2;
        }
    }

    //star the game
    //遍历map
    char temp[10];
    show_map(life_map);
    for(y=mr_length - 2; y >= 1; y--)
    {
        for(x = 1; x <= mr_length - 2; x++)
        {
            DeadorAlive(&life_map[y][x]);
            cin>>temp;
            show_map(life_map);
        }
    }
    

    system("pause");
    return 0;
}