//
// Created by 86139 on 2023/5/3.
//

#include "stdio.h"
#include "string.h"
#include "../book_manage.h"
#include "unistd.h"
void modify_book_by_id(int books_number,Book books[]){
    int index = query_byid(books_number,books);
    if (index == -1){
        printf("û���Ȿ��Ӵ��");
        sleep(2);
        return;

    }
    char newName[40];
    char newWriter[20];
    printf("�������µ�����:\n");

    scanf("%s",newName);

    printf("�������µ�������:\n");

    scanf("%s",newWriter);
    strcpy(books[index].name,newName);
    strcpy(books[index].writer ,newWriter);

    printf("%s,%s\n",books[index].name,books[index].writer);

    int will_delete[]={-1};
    int number=0;

    open_delete_book(will_delete,number,books_number,books);
    printf("�޸����");
    sleep(2);


    fflush(stdin);



}


//void modify_book_by_name(int books_number,Book books[]){
//    query_bybookname(books_number,books);
//}
//void modify_book_by_writer(int books_number,Book books[]){
//    query_bywriter(books_number,books);
//}