//
// Created by 86139 on 2023/5/3.
//
#include "stdio.h"
#include "../book_manage.h"

void show_book(int books_number,Book *books){
    int start=0,end=0;
    printf("������Ҫ�����鱾��������Χ��\n������__��ʼ��");
    scanf("%d",&start);
    printf("������__������");
    scanf("%d",&end);
    printf("����Ϊ�鱾������%d~%d��Χ֮�ڵ�ͼ�飺\n",start,end);

    for (int i = start; i <= end; ++i) {
        printf("%d %s %s\n",books[i].id,books[i].writer,books[i].name);
    }

}
