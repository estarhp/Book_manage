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
    printf("������Ҫ���Ķ��ߵ�������Χ��\n������(���ڵ���1)__��ʼ��\n");
    scanf("%d",&start);
    printf("������(С�ڵ���%d)__������\n",readers_number);
    scanf("%d",&end);


    if (start>end||end>readers_number||start<=0){
        printf("�������ݴ���!!!");
        sleep(2);
        system("cls");
        return;
    }
    printf("����Ϊ����������%d~%d��Χ֮�ڵĶ��ߣ�\n",start,end);


    for (int i = start-1; i < end; ++i) {
        printf("%d %s\n",readers[i].id,readers[i].name);
    }

    printf("5s���Զ��˳�");

    sleep(5);
    system("cls");


}

