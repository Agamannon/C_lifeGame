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
��Ϸ����

�Ӵ�λ_8λ��
1 2 3
4 * 5
6 7 8

������*Ϊ0���Ӵ�λ��1~2λ��*��һ�ֱ�Ϊ1.
(*Ϊ0���Ӵ�λ��3~8λ��*��һ�ֲ���)
������*Ϊ1���Ӵ�λ��1~5λ��*��һ�ֲ��䡣
������*Ϊ1���Ӵ�λ��0��6~8λ��*��һ�ֱ�Ϊ0.
*/

int main()
{

    int life_map[12][12];
    int x, y;

    // ��������
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