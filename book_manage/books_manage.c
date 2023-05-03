#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"
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
void Collect(int books_number,Book books[],FILE *fp);//�ռ��û���ѡ��
void delete_book(int books_number,Book books[]);//ɾ��
void modify_book(int books_number,Book books[]);
void query_book(int books_number,Book books[]);//��ѯͼ��
void show_book(int books_number,Book *books);//չʾͼ��
int query_byid(int books_number,Book books[]);//ͨ��id
void query_bywriter(int books_number,Book books[]);//ͨ������
void query_bybookname(int books_number,Book books[]);//ͨ������
int wherex_book();
int wherey_book();
void gotoxy_book(int x, int y);
void delete_book_by_id(int books_number,Book books[]);
void delete_book_by_writer(int books_number,Book books[]);
void delete_book_by_name(int books_number,Book books[]);
void modify_book_by_id(int books_number,Book books[]);
void modify_book_by_name(int books_number,Book books[]);
void modify_book_by_writer(int books_number,Book books[]);


void Main_book_mana(){

    FILE *fp=file_open();//���鱾�ļ�

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
    setbuf(stdout,0);//����
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
        case 1:query_byid(books_number,books);
            break;
        case 2:query_bywriter(books_number,books);
            break;
        case 3:query_bybookname(books_number,books);

    }

}

int  query_byid(int books_number,Book books[]){
    int id;
    printf("�������鱾��id");
    scanf("%d",&id);
    printf("������ƥ��Ĳ�ѯ�����\n");
    for (int i = 0; i < books_number; ++i) {
        if(books[i].id==id){
            printf("%d %s %s ",books[i].id,books[i].writer,books[i].name);
            return i;
        }
    }
}

void query_bywriter(int books_number,Book books[]){
    char writer[50];
    printf("�������鱾������");
    scanf("%s",writer);
    printf("������ƥ��Ĳ�ѯ�����\n");
    for (int i = 0; i < books_number; ++i) {
        if(strcmp(writer,books[i].writer)==0){
            printf("%d %s %s ",books[i].id,books[i].writer,books[i].name);
        }

    }
}

void query_bybookname(int books_number,Book books[]){
    char bookname[20];
    printf("�������鱾������");
    scanf("%s",bookname);
    printf("������ƥ��Ĳ�ѯ�����\n");

    for (int i = 0; i < books_number; ++i) {
        if(strcmp(bookname,books[i].name)==0){
            printf("%d %s %s ",books[i].id,books[i].writer,books[i].name);
        }

    }

}

void modify_book(int books_number,Book books[]){

    printf("�������޸��鱾��id");
    int i=query_byid(books_number,books);




}


void delete_book(int books_number,Book books[]){
    int delete_input;
    printf("1 -> ͨ��idɾ��\n"
                  "2 -> ͨ������ɾ��\n"
                  "3 -> ͨ������ɾ��\n");
    scanf("%d",&delete_input);
    switch (delete_input) {
        case 1:
            delete_book_by_id(books_number,books);
            break;
        case 2:
            delete_book_by_name(books_number,books);
            break;
        case 3:
            delete_book_by_writer(books_number,books);
            break;
    }
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
        case 2:delete_book(books_number,books);
            break;
        case 3:modify_book(books_number,books);
            break;
        case 4:query_book(books_number,books);
            break;
        case 5:show_book(books_number,books);
            break;

    }
}
int wherex_book()

{

    CONSOLE_SCREEN_BUFFER_INFO pBuffer;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);

    return (pBuffer.dwCursorPosition.X + 1);

}

//��ȡ����λ��y

int wherey_book()

{

    CONSOLE_SCREEN_BUFFER_INFO pBuffer;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);

    return (pBuffer.dwCursorPosition.Y + 1);

}

//���ù���λ��

void gotoxy_book(int x, int y)

{

    COORD c;

    c.X = x - 1;

    c.Y = y - 1;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

void Menu_book(){

    setbuf(stdout,0);//����

    int x, y;

    //int select;

    gotoxy_book(24, 5);

    printf("********��ӭͼ�����ϵͳ********");

    gotoxy_book(15, 8);

    printf("*********************���˵�*********************");

    gotoxy_book(15, 9);

    printf("*                  1->����ͼ��                 *");

    gotoxy_book(15, 10);

    printf("*                  2->ɾ��ͼ��                 *");

    gotoxy_book(15, 11);

    printf("*                  3->�޸�ͼ��                 *");

    gotoxy_book(15, 12);

    printf("*                  4->��ѯͼ��                 *");

    gotoxy_book(15, 13);

    printf("*                  5->��ʾͼ��                 *");

    gotoxy_book(15, 14);

    printf("************************************************");

    gotoxy_book(28, 16);

    printf("���������ѡ��(����):[ ]");

    x = wherex_book();

    y = wherey_book();

    gotoxy_book(x - 2, y);

    //scanf_s("%d", &select);
    //Collect_operation();


    void Collect(int books_number,Book books[],FILE *fp);
    system("pause");

    //return 0;*/

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

void open_delete_book(int will_delete[],int number,int books_number,Book books[]){
    FILE *fp;
    if ((fp = fopen("../book_manage/books.txt", "w+")) == NULL){
        if ((fp = fopen("book_manage/books.txt", "w+")) == NULL){
            printf("�ļ�·��Error!\n");
        }
    }

    printf("%p",fp);

    rewind(fp);
    for (int j = 0; j < books_number; ++j) {
        int flag=1;
        for (int k = 0; k < number; ++k) {
            if(will_delete[k]==j) flag=0;
        }
        if(flag)
        fprintf(fp,"%d %s %s\n",books[j].id,books[j].writer,books[j].name);
    }
    fclose(fp);

}

void delete_book_by_id(int books_number,Book books[]){
    int number=0;
    int will_delete[10];
    int id;
    printf("�������鱾��id");
    scanf("%d",&id);

    for (int i = 0; i < books_number; ++i) {
        if(books[i].id==id){
            will_delete[number]=i;
            number++;
        }
    }
    open_delete_book(will_delete,number,books_number,books);
}
void delete_book_by_writer(int books_number,Book books[]){
    int number=0;
    int will_delete[10];
    char writer[50];
    printf("�������鱾������");
    scanf("%s",writer);
    for (int i = 0; i < books_number; ++i) {
        if(strcmp(writer,books[i].writer)==0){
            will_delete[number]=i;
           number++;
        }
}
    open_delete_book(will_delete,number,books_number,books);
}
void delete_book_by_name(int books_number,Book books[]){
    int number=0;
    int will_delete[10];
    char bookname[20];
    printf("�������鱾������");
    scanf("%s",bookname);

    for (int i = 0; i < books_number; ++i) {
        if(strcmp(bookname,books[i].name)==0){
            will_delete[number]=i;
           number++;
        }
    }
    open_delete_book(will_delete,number,books_number,books);

}

void modify_book_by_id(int books_number,Book books[]){
    query_byid(books_number,books);
}
//void modify_book_by_name(int books_number,Book books[]){
//    query_bybookname(books_number,books);
//}
//void modify_book_by_writer(int books_number,Book books[]){
//    query_bywriter(books_number,books);
//}





