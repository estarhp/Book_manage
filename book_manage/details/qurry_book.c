//
// Created by 86139 on 2023/5/3.
//
#include "../book_manage.h"
#include "stdio.h"
#include "string.h"
#include "windows.h"
#include "unistd.h"
void query_book(int books_number,Book books[]){
    setbuf(stdout,0);//����

    system("cls");
    int select_mode=0;
    int x,y;
    gotoxy_book(2000, 5);
    printf("\n\t                        1->ͨ��id                         \t\n");
    gotoxy_book(2001, 6);
    printf("\n\t                        2->ͨ������                        \t\n");
    gotoxy_book(2002, 7);
    printf("\n\t                        3->ͨ������                        \t\n");
    gotoxy_book(2003, 8);
    printf("\n\t                      ���������ѡ�����֣���                \n\t");
    x = wherex_book();

    y = wherey_book();

    gotoxy_book(x - 2, y);
    //system("pause");
    scanf("%d",&select_mode);

    switch (select_mode) {
        case 1:
           query_byid(books_number,books);
            break;
        case 2:query_bywriter(books_number,books);
            break;
        case 3:query_bybookname(books_number,books);

    }
    sleep(2);
    system("cls");

}

int  query_byid(int books_number,Book books[]){
    int id;
    printf("�������鱾��id:\n");
    int  right = scanf("%d",&id);
    if (right == 0){
        printf("������󣡣���");
        return -1;
    }


    for (int i = 0; i < books_number; i++) {
        if(books[i].id==id){
            printf("������ƥ��Ĳ�ѯ�����\n");
            printf("%d %s %s \n",books[i].id,books[i].writer,books[i].name);
            return i;
        }

    }
    printf("û�з���Ҫ����飡\n��");
    return -1;
}

void query_bywriter(int books_number,Book books[]){
    char writer[50];
    int flag= 1;
    printf("�������鱾������:\n");
    scanf("%s",writer);
    printf("������ƥ��Ĳ�ѯ�����\n");
    for (int i = 0; i < books_number; ++i) {
        if(strcmp(writer,books[i].writer)==0){

            printf("%d %s %s\n",books[i].id,books[i].writer,books[i].name);
            flag=0;
        }

    }
    if (flag){
        printf("��(û���ҵ�����Ҫ�����)");
    }
}

void query_bybookname(int books_number,Book books[]){
    char bookname[20];
    int flag = 1;
    printf("�������鱾������:\n");
    scanf("%s",bookname);
    printf("������ƥ��Ĳ�ѯ�����\n");

    for (int i = 0; i < books_number; ++i) {
        if(strcmp(bookname,books[i].name)==0){
            printf("%d %s %s\n",books[i].id,books[i].writer,books[i].name);
            flag = 0;
        }


    }
    if (flag){
        printf("��(û���ҵ�����Ҫ�����)");
    }

}

