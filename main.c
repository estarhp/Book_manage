#include<stdio.h>
#include "stdlib.h"
#include "book_manage/book_manage.h"
#include "reader_manage/reader_manage.h"
#include "borrow_return/borrow_return.h"
void  ShowMainMenu();
void Collect_operation();

int main(int argc, char const *argv[])
{
    //��ӡ����
    ShowMainMenu();
   //�ռ����������
    Collect_operation();




    return 0;
}
void  ShowMainMenu(){
    system("cls");
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




}
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