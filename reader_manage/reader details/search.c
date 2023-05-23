//
// Created by Vinci on 2023/5/8.
//
#include "stdio.h"
#include "string.h"
#include "../reader_manage.h"
#include "windows.h"
#include "unistd.h"
void search_reader(int readers_number,Reader readers[])
{
    fflush(stdin);
    system("cls");
    int select_mode=0;
    printf("\n\t                        1->ͨ��id                         \t\n");
    printf("\n\t                        2->ͨ������                        \t\n");
    printf("\n\t                      ���������ѡ�����֣���                \n\t");

    int right = scanf("%d",&select_mode);
    if (right  == 0){
        printf("������󣡣�");
        sleep(2);
        system("cls");
        return;
    }
    switch (select_mode) {
        case 1:
            Search_byreaderid(readers_number,readers);
            break;
        case 2:Search_byreadername(readers_number,readers);


    }
    sleep(2);
    system("cls");


}
int Search_byreaderid(int readers_number,Reader readers[])
{
    int id;
    printf("��������ߵ�id:\n");
    scanf("%d",&id);
    printf("������ƥ��Ĳ�ѯ�����\n");
    for (int i = 0; i < readers_number; ++i) {
        if(readers[i].id==id){
            printf("%d %s %s\n",readers[i].id,readers[i].sex,readers[i].name);
            return i;
        }

    }
    printf("��(û���ҵ����������Ķ���)\n");
    return -1;



}
void Search_byreadername(int readers_number,Reader readers[])
{
    char readername[14];
    int flag = 1;
    printf("��������ߵ�����:\n");
    fflush(stdin);
    fgets(readername, 14, stdin);

    if (strlen(readername) == 13) {

        printf("�����Ҳ̫���˰ɣ�������");
        sleep(2);
        return;
    }

    readername[strcspn(readername, "\n")] = '\0';
    printf("������ƥ��Ĳ�ѯ�����\n");
    for (int i = 0; i < readers_number; ++i) {
        if(strcmp(readername,readers[i].name)==0){

            printf("%d %s %s\n",readers[i].id,readers[i].sex,readers[i].name);
            flag = 0;
        }



    }
    if(flag)
        printf("��(û���ҵ����������Ķ���)\n");
}