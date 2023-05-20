#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "book_manage.h"

int Main_book_mana(){

    FILE *fp=file_open();//���鱾�ļ�

    int books_number=Books_number(fp);//����ͼ������

    Book books[books_number];//����ͼ������

    put_book(books_number,fp,books);//���鱾��������

    Menu_book();

   int will_reload = Collect(books_number,books,fp);
    if (will_reload == 1){
        fclose(fp);//�ر��ļ�
        return 1;
    }


    fclose(fp);//�ر��ļ�



}

int Collect(int books_number,Book books[],FILE *fp){
    system("cls");
    Menu_book();//��ʾ���ݹ�����Ӳ˵�
    int Scanf;
    scanf("%d",&Scanf );
    getchar();


    //�ռ��û���ѡ��


    //���벻ͬģ��
    while(Scanf)
    {
    switch (Scanf) {
        case 0:
            printf("ллʹ�ã�����");
            return 0;
        case 1:add_book(books,books_number,fp);
            return 1;
        case 2:delete_book(books_number,books);
            return 1;
        case 3:modify_book_by_id(books_number,books);
            break;
        case 4:query_book(books_number,books);
            break;
        case 5:show_book(books_number,books);
            break;
        default:
            printf("��������ȷ������\n");
            break;

    }
        //printf("|�밴����������Ӳ˵�|\n");
        getchar();//�ӿؼ���ȡ�ַ����������;
        system("cls");
        Menu_book();
        fflush(stdin);
        scanf(" %d", &Scanf);
        //getchar();

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

    printf("*********************�Ӳ˵�*********************");

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
//    gotoxy_book(15,14);
//    printf("*                  0->�˳�ϵͳ                  *");
    gotoxy_book(15,14);
    printf("***********************************************");

    gotoxy_book(28, 16);

    printf("���������ѡ��(����):[ ]");

    x = wherex_book();

    y = wherey_book();

    gotoxy_book(x - 2, y);



}
