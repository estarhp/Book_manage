#include<stdio.h>
#include "stdlib.h"

void  ShowMainMenu(){
    system("cls");

    printf("\n\t##########################��ӭ����##########################\t\n"
                  "\n\t                        1->ͼ�����                         \t\n"
                  "\n\t                        2->���߹���                         \t\n"
                  "\n\t                        3->�軹��Ǽ�                       \t\n"
                  "\n\t#######################������ѡ�����########################\t\n"
                  );




}



int main(int argc, char const *argv[])
{   int Scan_number=0;


    ShowMainMenu();



    scanf("%d",&Scan_number);

    return 0;
}
