/*
1.地图设计元素： 空地0 墙壁1 箱子2 目的地3 角色4 角色与目的地重合7 箱子与目的地重合5
2.角色的移动：改变坐标
推箱子规则：人物前方，空地，目的地，箱子及箱子前
3.通关判断
4.跳转关卡
*/

#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<windows.h>

//1.定义多幅地图
int Map[6][8][8] = {
       {
            {1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 3, 1},
            {1, 0, 0, 0, 0, 0, 2, 1},
            {1, 0, 0, 0, 4, 0, 0, 1},
            {1, 0, 0, 0, 0, 2, 0, 1},
            {1, 3, 0, 2, 0, 0, 3, 1},
            {1, 1, 1, 1, 1, 1, 1, 1}
        },
        {
            {1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 3 ,0, 3, 0, 1},
            {1, 0, 2, 0, 0, 2, 0, 1},
            {1, 2, 0, 4, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 1},
            {1, 3, 0, 2, 3, 0, 1, 1},
            {1, 1, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1}
        },
        {
            {1, 1, 1, 1, 1, 1, 1, 1},
            {1, 3, 0, 2, 3, 0, 0, 1},
            {1, 0, 2, 0, 4, 0, 3, 1},
            {1, 0, 2, 0, 0, 2, 0, 1},
            {1, 3, 0, 0, 0, 1, 1, 1},
            {1, 0, 2, 0, 0, 1, 1, 1},
            {1, 1, 1, 1, 3, 0, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1}
        },
        {
            {1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 4, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 2, 0, 1},
            {1, 0, 2, 2, 2, 3, 0, 1},
            {1, 0, 0, 2, 3, 3, 0, 1},
            {1, 0, 0, 2, 3, 3, 0, 1},
            {1, 0, 0, 3, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1}
        },
        {
            {0, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 0, 2, 3, 0, 0, 1},
            {1, 1, 0, 0, 0, 0, 3, 1},
            {1, 0, 2, 3, 0, 2, 0, 1},
            {1, 0, 3, 2, 0, 0, 0, 1},
            {1, 4, 0, 3, 2, 0, 0, 1},
            {1, 1, 1, 0, 0, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1}
        },
        {
            {0, 0, 0, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 3,  4, 0, 1},
            {1, 3, 2, 0, 0, 2, 0, 1},
            {1, 3, 0, 0, 0, 0, 0, 1},
            {1, 3, 0, 2, 0, 1, 0, 1},
            {1, 1, 1, 2, 0, 1, 0, 1},
            {1, 1, 1, 0, 0, 1, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1}
        }
};
int g_level = 0;//g:global全局
int g_boxnum[] = {3,4,5,6,5,4};

//1.函数（画地图）
int i, j;
void DrawMap(int Map[][8][8]) {//void不返回，DrawMap为函数，保存绘制地图，()表无参数，(int MAP[8][8])表接收Map作参数
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            switch (Map[g_level][i][j])
            {
            case 0:printf(" "); break;//空地
            case 1:printf("■"); break;//墙壁■
            case 2:printf("□"); break;//箱子□
            case 3:printf("★"); break;//目的地★
            case 4:printf("♀"); break;//角色♀
            case 5:printf("√"); break;//箱子在目的地
            case 7:printf("♀"); break;//人物在目的地
            }
        }
        printf("\n");
    }
}

int main()
{
       //1.做地图：打印
    //DrawMap(Map);调用函数，将Map传入函数//因清屏放入循环中   
    //2、3的循环
    //int count = 0;位置不对，去掉
        while (1) {
        system("cls");//清屏，成动画  system用于执行字符串形式命令，cls即clear screen
        DrawMap(Map);//因清屏，地图要重新打
        int m, n;
        int count = 0;//判断当前任务完成个数，每次需重新算，注意位置
        //2.人物移动：确定角色位置
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {

                if (Map[g_level][i][j] == 4 || Map[g_level][i][j] == 7) break;
            }
            if (Map[g_level][i][j] == 4 || Map[g_level][i][j] == 7) break;
        }
        printf("当前人物坐标(%d,%d)\n", i, j);
        //2.人物移动：从键盘获取字符，储存到input,让人物移动
        char input = _getch();
        //while (getchar() != '\n'); // 不交互时清除缓冲区中的换行符,否则打印两次
        switch (input)
        {
        case'w'://上
            if (Map[g_level][i - 1][j] == 0 || Map[g_level][i - 1][j] == 3)//上方是空地，目的地
            {
                Map[g_level][i - 1][j] += 4;
                Map[g_level][i][j] -= 4;
            }
            else if (Map[g_level][i - 1][j] == 2 || Map[g_level][i - 1][j] == 5)//上方是箱子或箱子在目的地
            {
                if (Map[g_level][i - 2][j] == 0 || Map[g_level][i - 2][j] == 3)//箱子之上
                {
                    Map[g_level][i - 2][j] += 2;
                    Map[g_level][i - 1][j] += 2;
                    Map[g_level][i][j] -= 4;
                }
            }
            break;
        case's'://下
            if (Map[g_level][i + 1][j] == 0 || Map[g_level][i + 1][j] == 3)//下方是空地，目的地
            {
                Map[g_level][i + 1][j] += 4;
                Map[g_level][i][j] -= 4;
            }
            else if (Map[g_level][i + 1][j] == 2 || Map[g_level][i + 1][j] == 5)//下方是箱子或箱子在目的地
            {
                if (Map[g_level][i + 2][j] == 0 || Map[g_level][i + 2][j] == 3)//箱子之下
                {
                    Map[g_level][i + 2][j] += 2;
                    Map[g_level][i + 1][j] += 2;
                    Map[g_level][i][j] -= 4;
                }
            }
            break;
        case'a'://左
            if (Map[g_level][i][j-1] == 0 || Map[g_level][i][j-1] == 3)//左方是空地，目的地
            {
                Map[g_level][i][j-1] += 4;
                Map[g_level][i][j] -= 4;
            }
            else if (Map[g_level][i][j-1] == 2 || Map[g_level][i][j-1] == 5)//左方是箱子或箱子在目的地
            {
                if (Map[g_level][i][j-2] == 0 || Map[g_level][i][j-2] == 3)//箱子之左
                {
                    Map[g_level][i][j - 2] += 2;
                    Map[g_level][i][j - 1] += 2;
                    Map[g_level][i][j] -= 4;
                }
            }
            break;
        case'd'://左
            if (Map[g_level][i][j + 1] == 0 || Map[g_level][i][j + 1] == 3)//左方是空地，目的地
            {
                Map[g_level][i][j + 1] += 4;
                Map[g_level][i][j] -= 4;
            }
            else if (Map[g_level][i][j + 1] == 2 || Map[g_level][i][j + 1] == 5)//左方是箱子或箱子在目的地
            {
                if (Map[g_level][i][j + 2] == 0 || Map[g_level][i][j +2] == 3)//箱子之左
                {
                    Map[g_level][i][j + 2] += 2;
                    Map[g_level][i][j + 1] += 2;
                    Map[g_level][i][j] -= 4;
                }
            }
            break;
        };
              
        //3.是否通关
        for (m = 0; m < 8; m++) {
            for (n = 0; n < 8; n++) {
                if (Map[g_level][m][n] == 5)count++;
            }
        }
        while (count == g_boxnum[g_level]) {
            system("cls");
            DrawMap(Map);
            
                printf("恭喜你通过第%d关。\n", g_level+1);
                Sleep(2000);
                printf("是否进入下一关？（y/n）:\n");
                char choice;
                scanf_s("%c", &choice);
                if (choice == 'y') {
                    g_level++;
                }
                else {
                    printf("游戏结束。\n");
                    break;
                }                         
            if(g_level>=5) {
                printf("恭喜你，全部通关啦！！！\n");
                Sleep(3000);
            }                    
        }
    }    
    return 0;
}