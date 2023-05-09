#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "book_manage.h"

void Main_book_mana(){

    FILE *fp=file_open();//���鱾�ļ�

    int books_number=Books_number(fp);//����ͼ������

    Book books[books_number];//����ͼ������

    put_book(books_number,fp,books);//���鱾��������

    Menu_book();

    Collect(books_number,books,fp);

    fclose(fp);//�ر��ļ�

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
        case 3:modify_book_by_id(books_number,books);
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



}
