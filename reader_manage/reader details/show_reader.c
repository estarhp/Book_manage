//
// Created by Vinci on 2023/5/8.
//
#include "stdio.h"
#include "../reader_manage.h"
#include "windows.h"
#include "unistd.h"
void show_reader(int readers_number,Reader *readers){
    system("cls");
    int start=0,end=0;
    printf("������Ҫ���Ķ��ߵ�������Χ��\n������(1~%d)__��ʼ��\n",readers_number);
    scanf("%d",&start);
    printf("������(1~%d)__������\n",readers_number);
    scanf("%d",&end);


    if (start>end||end>readers_number||start<=0){
        printf("�������ݴ���!!!");
        sleep(2);
        system("cls");
        return;
    }
    printf("����Ϊ����������%d~%d��Χ֮�ڵĶ��ߣ�\n",start,end);


    for (int i = start-1; i < end; ++i) {
    printf("%d %s %s\n",readers[i].id,readers[i].name,readers[i].sex);
    }

    printf("5s���Զ��˳�");

    sleep(5);
    system("cls");


}

