//
// Created by Vinci on 2023/5/8.
//
#include "stdio.h"
#include "../reader_manage.h"
#include "string.h"
#include "unistd.h"
void modify_reader_by_id(int readers_number, Reader  readers[]){
    int index = Search_byreaderid(readers_number,readers);
    if (index == -1){
        printf("û���������Ӵ");
        sleep(2);
        return;
    }
    char newName[14];
    char newSex[5];
    printf("�������µ�������\n");

    fflush(stdin);
    fgets(newName, 14, stdin);

    if (strlen(newName) == 13) {

        printf("�����Ҳ̫���˰ɣ�������");
        sleep(2);
        return;
    }

    newName[strcspn(newName, "\n")] = '\0';


    printf("��������ߵ��Ա���/Ů��");
    fflush(stdin);

    fgets(newSex, 5, stdin);

    if (strlen(newSex) == 4) {

        printf("�����Ҳ̫���˰ɣ�������");
        sleep(2);
        return ;
    }

    newSex[strcspn(newSex, "\n")] = '\0';

    if(strcmp(newSex,"��") != 0 && strcmp(newSex,"Ů") != 0 )
    {
        printf("��������ȷ���Ա𣡣�����");
        sleep(2);
        return;
    }
    strcpy(readers[index].name,newName);
    strcpy(readers[index].sex,newSex);

    printf("%s,%s",readers[index].name,readers[index].sex);

    int will_delete[]={-1};
    int number=0;

    open_delete_reader(will_delete,number,readers_number,readers);

    printf("�޸����");
    sleep(2);




}