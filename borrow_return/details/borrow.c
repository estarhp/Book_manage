//
// Created by 86139 on 2023/5/4.
//
#include "../borrow_return.h"
#include "malloc.h"
#include "unistd.h"
void showBorrow(Borrow *head){
    for (Borrow *p= head->next; p !=NULL; p= p->next) {
        printf("����ʱ�䣺%s �����ˣ�%d %s %s �����飺%d %s %s\n",
               p->time,
               p->reader.id,
               p->reader.name,
               p->reader.sex,
               p->book.id,
               p->book.writer,
               p->book.name);
    }
    printf("���س���������3");

}

void register_borrow(Borrow *head,Book books[],int books_number,Reader readers[],int readers_number,FILE *fp) {
    Borrow *p = head->next;
    while (p->next != NULL)p=p->next;
    Borrow *q=(Borrow *)malloc(sizeof(Borrow));
    int index_reader = Search_byreaderid(readers_number,readers);
    if (index_reader==-1) {
        printf("���ݿ���û����λ���ߵ���Ϣ��������Ӹö���\n");
        printf("�밴�س�����!!!\n");
        sleep(2);
//        system("cls");
        return;
    }
    q->reader = readers[index_reader];
    int index_book = query_byid(books_number,books);
    if (index_book==-1) {
        printf("���ݿ���û���Ȿͼ�����Ϣ��������Ӹ��鱾\n");
        printf("�밴�س����أ�����\n");
        sleep(2);
//        system("cls");
        return;
    }
    q->book = books[index_book];
    createTime(q->time);
    q->next = NULL;
    p->next = q;

    rewind(fp);//����ָ���ļ���ͷ
    fprintf(fp,"%s %d %s %s %d %s %s\n",q->time,
            q->reader.id,
            q->reader.name,
            q->reader.sex,
            q->book.id,
            q->book.writer,
            q->book.name);
    printf("�س��˳�����");
    sleep(2);



}
