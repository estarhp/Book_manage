//
// Created by Vinci on 2023/5/8.
//
#include "stdio.h"
#include "../reader_manage.h"
#include "string.h"
void modify_reader_by_id(int readers_number, Reader  readers[]){
    int index = Search_byreaderid(readers_number,readers);
    if (index == -1){
        printf("û���������Ӵ");
        return;
    }
    char newName[12];
    char newSex[3];
    printf("�������µ�������\n");

    scanf("%s",newName);

    printf("�������µ��Ա�(ѡ����Ů)��\n");

    scanf("%s",newSex);

    if(strcmp(newSex,"��") != 0 && strcmp(newSex,"��") != 0 )
    {
        printf("��������ȷ���Ա𣡣�����");
        return;
    }
    strcpy(readers[index].name,newName);
    strcpy(readers[index].sex,newSex);

    printf("%s,%s",readers[index].name,readers[index].sex);

    int will_delete[]={-1};
    int number=0;

    open_delete_reader(will_delete,number,readers_number,readers);



}