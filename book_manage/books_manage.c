#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//����ͼ������
typedef struct book {
    int id;
    char name[50];
    char writer[20];
} Book;

void add_book(Book books[],int books_number,FILE *fp);

FILE * file_open();

void put_book(int number,FILE *fp,Book books[]);//��ʼ��ͼ��

int Books_number(FILE *fp);//�����ļ���ͼ�����Ŀ

void Menu_book();

void Collect(int books_number,Book books[],FILE *fp);

void delete_book();

void modify_book();

void query_book(int books_number,Book books[]);

void show_book(int books_number,Book *books);

void query_byid(int books_number,Book books[]);

void query_bywriter(int books_number,Book books[]);

void query_bybookname(int books_number,Book books[]);




void Main_book_mana(){

    FILE *fp=file_open();

    int books_number=Books_number(fp);//����ͼ������

    Book books[books_number];//����ͼ������

    put_book(books_number,fp,books);//���鱾��������



    Menu_book();

    Collect(books_number,books,fp);

    fclose(fp);//�ر��ļ�





}

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

void query_book(int books_number,Book books[]){
    int select_mode=0;
    printf("\n\t                        1->ͨ��id                        \t\n"
           "\n\t                        2->ͨ������                        \t\n"
           "\n\t                        3->ͨ������                        \t\n"
    );
    scanf("%d",&select_mode);
    switch (select_mode) {
        case 1:query_byid(books_number,books);
            break;
        case 2:query_bywriter(books_number,books);
            break;
        case 3:query_bybookname(books_number,books);

    }

}

void query_byid(int books_number,Book books[]){
    int id;
    printf("�������鱾��id");
    scanf("%d",&id);
    printf("������ƥ��Ĳ�ѯ�����\n");
    for (int i = 0; i < books_number; ++i) {
        if(books[i].id==id){

            printf("%d %s %s ",books[i].id,books[i].writer,books[i].name);
        }
    }
}

void query_bywriter(int books_number,Book books[]){
    int writer[50];
    printf("�������鱾������");
    scanf("%s",&writer);
    printf("������ƥ��Ĳ�ѯ�����\n");
    for (int i = 0; i < books_number; ++i) {
        if(strcmp(writer,books[i].writer)==0){

            printf("%d %s %s ",books[i].id,books[i].writer,books[i].name);
        }

    }
}

void query_bybookname(int books_number,Book books[]){
    int bookname[20];
    printf("�������鱾������");
    scanf("%s",&bookname);
    printf("������ƥ��Ĳ�ѯ�����\n");

    for (int i = 0; i < books_number; ++i) {
        if(strcmp(bookname,books[i].name)==0){
            printf("%d %s %s ",books[i].id,books[i].writer,books[i].name);
        }

    }

}

void modify_book(){
    printf("������");

}


void delete_book(){
    printf("������");
}

void add_book(Book books[],int books_number,FILE *fp){
    rewind(fp);
    Book addbook;
    printf("������Ҫ��ӵ�����");
    scanf("%s",&addbook.name);
    printf("������Ҫ���ͼ�������");
    scanf("%s",&addbook.writer);
    addbook.id=books[books_number-1].id+1;
    fprintf(fp, "%d %s %s\n", addbook.id, addbook.writer, addbook.name);

}

void Collect(int books_number,Book books[],FILE *fp){
    int Scanf;
    //�ռ��û���ѡ��
    scanf("%d",&Scanf);
    //���벻ͬģ��
    switch (Scanf) {

        case 1:add_book(books,books_number,fp);
            break;
        case 2:delete_book();
            break;
        case 3:modify_book();
            break;
        case 4:query_book(books_number,books);
            break;
        case 5:show_book(books_number,books);
            break;

    }
}

void Menu_book(){

    printf("\n\t##########################��ӭ����ͼ�����ϵͳ##########################\t\n"
           "\n\t                        1->����ͼ��                        \t\n"
           "\n\t                        2->ɾ��ͼ��                        \t\n"
           "\n\t                        3->�޸�ͼ��                        \t\n"
           "\n\t                        4->��ѯͼ��                        \t\n"
           "\n\t                        5->��ʾͼ��                        \t\n"
           "\n\t#######################������ѡ�����########################\t\n"
    );

}

int Books_number(FILE *fp) {

    int flag = 0, file_row = 0, count = 0;
    while (!feof(fp)) {
        flag = fgetc(fp);
        if (flag == '\n')
            count++;
    }
    file_row = count; //�������һ��

    rewind(fp);
    return file_row;
}

void put_book(int number,FILE *fp,Book books[]){


    for (int i = 0; i<number ; i++) {
        fscanf(fp,"%d %s %s",&books[i].id,&books[i].writer,&books[i].name);
    }//���ļ������鱾



}

FILE * file_open(){
    FILE *fp;
    if ((fp = fopen("../book_manage/books.txt", "a+")) == NULL){
        if ((fp = fopen("book_manage/books.txt", "a+")) == NULL){
            printf("�ļ�·��Error!\n");
        }
    }

    return fp;
}





