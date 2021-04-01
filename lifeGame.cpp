#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

/*
��Ϸ����
------------------------------
V0.1

�Ӵ�λ_8λ��
1 2 3
4 * 5
6 7 8

������*Ϊ0���Ӵ�λ��1~2λ��*��һ�ֱ�Ϊ1.
(*Ϊ0���Ӵ�λ��0��3~8λ��*��һ�ֲ���)
������*Ϊ1���Ӵ�λ��1~5λ��*��һ�ֲ��䡣
������*Ϊ1���Ӵ�λ��0��6~8λ��*��һ�ֱ�Ϊ0.

--------------------------------
V0.2

���˿ڹ��١����κλ�ϸ��������ھ�����2������������
�����������κλ�ϸ��������ھ�Ϊ2����3����������
���˿ڹ��ࡱ���κλ�ϸ��������ھӴ���3������������
����ֳ�����κ���ϸ��������ھ�Ϊ2��3������������

*/

using namespace std;

// map real length
#define mr_length 40
// map���ĳ��ֳ�ʼ�����ķ�Χ
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
    //���ð˸��Ӵ�λ
    int *left, *left_top, *top, *right_top, *right, *right_under, *under, *left_under;
    left = point - 1;
    right = point + 1;
    top = point - mr_length;
    left_top = top - 1;
    right_top = top + 1;
    under = point + mr_length;
    left_under = under - 1;
    right_under = under + 1;

    // //use rough(�ֱ���) method to count the touch alive count
    // int touch_alive_count = 0;
    // if(*left == 1)  // ֱ�� if(*left)����Ӧ���а�
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

    //����һЩ�ķ���
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

    // ��������
    srand( (unsigned)time(NULL) );

    //��ʼ����ͼ
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
    //����map

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