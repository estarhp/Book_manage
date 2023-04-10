#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "book_manage/book_manage.h"
#include "reader_manage/reader_manage.h"
#include "borrow_return/borrow_return.h"
#define N 1024
void Collect_operation();
void printMenu();
void Move(char dir);
//��λ��ͷ
static COORD coord;
void Move(char dir)
{
    COORD originCoord = coord;
    if (dir == 'w' && coord.Y <= 6&& coord.Y > 2)
    {
        coord.Y--;
    }
    else if (dir == 's' && coord.Y < 6 && coord.Y >= 2)
    {
        coord.Y++;
    }

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), originCoord);
    printf("   ");
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("==>");

}
static char menuContent[8][N] = {
        {"********                ͼ�����ϵͳ                ********"},
        {"##########################��ӭ����##########################"},
        {"#                        0->ллʹ��                       #"},
        {"#                        1->ͼ�����                       #"},
        {"#                        2->���߹���                       #"},
        {"#                        3->�軹��Ǽ�                     #"},
        {"#                        ����->������                      #"},
        {"#######################��ѡ�����ֽ���#######################"}
};
void printMenu() {
    //system("cls")
    coord.X = 24;//��
    coord.Y = 0;//��
    for (int i = coord.Y, j = 0; i <= 9; i++)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        coord.Y++;
        printf("%s\n", menuContent[j++]);
    }

    coord.X = 20;
    coord.Y = 2;//�������Ķ���ʼ
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("==>");
}



int main(int argc, char const *argv[])
{
    //��ӡ����
    //ShowMainMenu();
   //�ռ����������


    printMenu();




    while (1)
    {
        if (_kbhit())
        {
            char Direction = _getch();
            if (Direction == 'w' || Direction == 's' || Direction == '1' || Direction == '2' || Direction == '3')
            {
                Move(Direction);
            }
        }
    }
    Collect_operation();
    return 0;


}

/*void  ShowMainMenu() {

    printf("\n\t********                ͼ�����ϵͳ                ********\t\n");
    printf(
            "\n\t##########################��ӭ����##########################\t"
            "\n\t#                        0->ллʹ��                       #\t"
            "\n\t#                        1->ͼ�����                       #\t"
            "\n\t#                        2->���߹���                       #\t"
            "\n\t#                        3->�軹��Ǽ�                     #\t"
            "\n\t#                        ����->������                      #\t"
            "\n\t#######################������ѡ�����########################\t"
    );
}*/
void Collect_operation(){
    int Scan_number=0;

    //�ռ��û���ѡ��
    scanf("%d",&Scan_number);
   //���벻ͬģ��
    switch (Scan_number) {
        case 0:
            printf("ллʹ�ã�");
            break;
        case 1:Main_book_mana();
            break;
        case 2:Main_reader_mana();
            break;
        case 3:Main_br_mana();
            break;
        default:
            printf("�������������");
            break;

    }
}