
#include <stdio.h>
#include <windows.h>
#include "book_manage/book_manage.h"
#include "reader_manage/reader_manage.h"
#include "borrow_return/borrow_return.h"
#include "unistd.h"
void Main_Muen();
void Collect_operation();

//��λ��ͷ
int wherex()

{

    CONSOLE_SCREEN_BUFFER_INFO pBuffer;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);

    return (pBuffer.dwCursorPosition.X + 1);

}

//��ȡ����λ��y

int wherey()

{

    CONSOLE_SCREEN_BUFFER_INFO pBuffer;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);

    return (pBuffer.dwCursorPosition.Y + 1);

}

//���ù���λ��

void gotoxy(int x, int y)

{

    COORD c;

    c.X = x - 1;

    c.Y = y - 1;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}
void Main_Muen()
{

    setbuf(stdout,0);

    int x, y;

    //int select;

    gotoxy(25, 5);

    printf("********ͼ�����ϵͳ********");

    gotoxy(15, 8);

    printf("*********************���˵�*********************");

    gotoxy(15, 9);

    printf("*                  0->��лʹ��ϵͳ���Զ��رգ� *");

    gotoxy(15, 10);

    printf("*                  1->ͼ�����                 *");

    gotoxy(15, 11);

    printf("*                  2->���߹���                 *");

    gotoxy(15, 12);

    printf("*                  3->�軹��Ǽ�               *");

    gotoxy(15, 13);

    printf("*                  ����->������                *");
    gotoxy(15, 14);

    printf("***********************************************");

    gotoxy(28, 16);



    printf("���������ѡ��(����):[ ]");


    x = wherex();

    y = wherey();

    gotoxy(x - 2, y);

}
int main()

{
    Main_Muen();
    Collect_operation();
    return 0;

}
void Collect_operation() {
    system("cls");
    Main_Muen();
    int Scan_number = 0;
    int will_reload;

    //�ռ��û���ѡ��
    scanf("%d", &Scan_number);
    //���벻ͬģ��
    //getchar();
    while(Scan_number) {
        switch (Scan_number) {
            case 0:
                printf("��лʹ�ø�ϵͳ���Զ��رգ�������");
                break;
            case 1:
               will_reload = Main_book_mana();
                if (will_reload == 1){
                    system("cls");
                    Main_book_mana();
                }
                break;
            case 2:
                will_reload = Main_reader_mana();
                if (will_reload == 1){
                    system("cls");
                    Main_reader_mana();
                }
                break;
            case 3:
                Main_br_mana();
                break;
            default:
                printf("�������������");
                break;

                }


            system("cls");
            Main_Muen();
            //getchar();//�ӿؼ���ȡ�ַ����������;
            scanf("%d", &Scan_number);
            sleep(2);




        }
    }
//hhh