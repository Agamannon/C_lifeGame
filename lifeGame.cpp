#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

/*
游戏规则：
------------------------------
V0.1

接触位_8位：
1 2 3
4 * 5
6 7 8

新生：*为0，接触位有1~2位，*下一轮变为1.
(*为0，接触位有0或3~8位，*下一轮不变)
延续：*为1，接触位有1~5位，*下一轮不变。
死亡：*为1，接触位有0或6~8位，*下一轮变为0.

--------------------------------
V0.2

“人口过少”：任何活细胞如果活邻居少于2个，则死掉。
“正常”：任何活细胞如果活邻居为2个或3个，则继续活。
“人口过多”：任何活细胞如果活邻居大于3个，则死掉。
“繁殖”：任何死细胞如果活邻居为2、3个，则活过来。

*/

using namespace std;

// map real length
#define mr_length 40
// map中心出现初始生命的范围
#define life_init_len 4

void show_map(int life_map[][mr_length])
{
    for(int y = mr_length-2; y >= 1; y--)
    {
        for(int x = 1; x <= mr_length-2; x++)
        {
            if(life_map[y][x])
                cout<<"O";
            else
                cout<<"  ";
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

    // //use rough(粗暴的) method to count the touch alive count
    // int touch_alive_count = 0;
    // if(*left == 1)  // 直接 if(*left)行吗，应该行吧
    //     touch_alive_count++;
    // if(*right == 1)
    //     touch_alive_count++;
    // if(*top == 1)
    //     touch_alive_count++;
    // if(*left_top == 1)
    //     touch_alive_count++;
    // if(*right_top == 1)
    //     touch_alive_count++;
    // if(*under == 1)
    //     touch_alive_count++;
    // if(*left_under == 1)
    //     touch_alive_count++;
    // if(*right_under == 1)
    //     touch_alive_count++;

    //巧妙一些的方法
    int touch_alive_count = *left + *right + *top + *left_top + *right_top + *under + *left_under + *right_under;

    // dead or alive rules

    // // V0.1
    // if(*point) // if *point == 1
    // {
    //     if(touch_alive_count == 0 || touch_alive_count > 5)
    //         *point = 0;
    // }
    // else
    // {
    //     if(touch_alive_count == 1 || touch_alive_count == 2)
    //         *point = 1;
    // }

    // V0.2
    if(*point == 1) // if *point == 1
    {
        if(touch_alive_count < 2 || touch_alive_count > 3)
            *point = 0;
    }
    else
    {
        if(touch_alive_count == 2 || touch_alive_count == 3)
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
    int empty_len = (mr_length - life_init_len)/2;
    for(y = mr_length-1; y >= 0; y--)
    {
        for(x = 0; x <= mr_length-1; x++)
        {
            if((y <= empty_len - 1) || (y >= empty_len + life_init_len))
                life_map[y][x] = 0;
            else if ((x <= empty_len - 1) || (x >= empty_len + life_init_len))
                life_map[y][x] = 0;
            else
                life_map[y][x] = rand()%2;
        }
    }

    //star the game
    //遍历map

    show_map(life_map);
    do
    {
        for(y = mr_length - 2; y >= 1; y--)
        {
            for(x = 1; x <= mr_length - 2; x++)
            {
                DeadorAlive(&life_map[y][x]);
            }
        }
        sleep(2);
        system("cls");
        show_map(life_map);
    } while (1);

    system("pause");
    return 0;
}