//
// Created by Vinci on 2023/5/8.
//
#include "stdio.h"
#include "string.h"
#include "../reader_manage.h"
#include "windows.h"
#include "unistd.h"
void show_reader(int readers_number,Reader *readers){
    system("cls");
    int start=0,end=0;
    printf("������Ҫ���Ķ��ߵ�������Χ��\n������__��ʼ��\n");
    scanf("%d",&start);
    printf("������__������\n");
    scanf("%d",&end);


    if (start<end||end>=readers_number||start<0){
        printf("�������ݴ���!!!");
        sleep(2);
        system("cls");
        return;
    }
    printf("����Ϊ����������%d~%d��Χ֮�ڵĶ��ߣ�\n",start,end);


    for (int i = start; i <= end; ++i) {
        printf("%d %s\n",readers[i].id,readers[i].name);
    }

}

