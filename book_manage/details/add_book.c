//
// Created by 86139 on 2023/5/3.
//

#include "../book_manage.h"
#include "stdio.h"


void add_book(Book books[],int books_number,FILE *fp){
    rewind(fp);
    Book addbook;
    printf("������Ҫ��ӵ�����:\n");
    scanf("%s",&addbook.name);
    printf("������Ҫ���ͼ�������:\n");
    scanf("%s",&addbook.writer);
    addbook.id=books[books_number-1].id+1;
    fprintf(fp, "%d %s %s\n", addbook.id, addbook.writer, addbook.name);
    printf("������ӳɹ��µ��鼮�����½���ϵͳʱˢ�����ݣ�\n");
}
