//
// Created by 86139 on 2023/5/3.
//
#include "stdio.h"
#include "../book_manage.h"
#include "windows.h"
#include "unistd.h"
void show_book(int books_number,Book *books){
    system("cls");
    int start=0,end=0;
    printf("������Ҫ�����鱾��������Χ��\n������(���ڵ���1)__��ʼ��\n");
    scanf("%d",&start);
    printf("������(С�ڵ���%d)__������\n",books_number);
    scanf("%d",&end);

    if (start>end||end>books_number||start<=0){
        printf("�������ݴ���!!!");
        sleep(2);
        system("cls");
        return;
    }

    printf("����Ϊ�鱾������%d~%d��Χ֮�ڵ�ͼ�飺\n",start,end);

    for (int i = start-1; i < end; ++i) {
        printf("%d %s %s\n",books[i].id,books[i].writer,books[i].name);
    }

    printf("5s���Զ��˳�");

    sleep(5);
    system("cls");



}
