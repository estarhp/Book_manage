#include "stdio.h"
//����ͼ������
typedef struct book {
    int id;
    char name[50];
    char writer[20];
} Book;

void add_book();

FILE * file_open();

void init_book(int number,FILE *fp,Book books[]);//��ʼ��ͼ��

int Books_number(FILE *fp);//�����ļ���ͼ�����Ŀ

void Main_book_mana(){

    FILE *fp=file_open();

    int books_number=Books_number(fp);//����ͼ������

    Book books[books_number];//����ͼ������

    init_book(books_number,fp,books);//��ʼ�������鱾��������

    for (int i = 0; i < books_number; ++i) {
        printf("%d %s %s\n",books[i].id,books[i].name,books[i].writer);
    }



}

void add_book(){

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

void init_book(int number,FILE *fp,Book books[]){


    for (int i = 0; i < number; ++i) {
        scanf("%d %s %s",&books[i].id,&books[i].name,&books[i].writer);
    }//���ļ������鱾

    fclose(fp);

}

FILE * file_open(){
    FILE *fp;

    if ((fp = freopen("../books.txt", "r",stdin)) == NULL){
        if ((fp = freopen("../books.txt", "r",stdin)) == NULL){
            printf("�ļ�·��Error!\n");
        }
    }

    return fp;
}





