#include "stdio.h"
#include "borrow_return.h"
#include "malloc.h"
#include "../reader_manage/reader_manage.h"
#include "../book_manage/book_manage.h"

void Main_br_mana(){
    Borrow *bhead=NULL;
    Return *rhead=NULL;
    bhead=(Borrow *)malloc(sizeof(Borrow));
    rhead= (Return *)malloc(sizeof (Return));
    bhead -> next =NULL;
    rhead -> next =NULL;


    FILE *bfp= b_file_open();
    FILE *rfp= r_file_open();


    put_borrow(bfp,bhead);
    put_return(rfp,rhead);





    //��ʼ��readerģ��
    FILE *fp1=name_open();

    int readers_number= Readers_number(fp1);//��ö�������

    Reader readers[readers_number];//������������

    put_reader(readers_number,fp1,readers);//��������Ϣ��������

    //��ʼ��bookģ��

    FILE *fp2=file_open();//���鱾�ļ�

    int books_number=Books_number(fp2);//����ͼ������

    Book books[books_number];//����ͼ������

    put_book(books_number,fp2,books);//���鱾��������

    fclose(fp1);//�ر��ļ�
    fclose(fp2);//�ر��ļ�

// 1.չʾ�����¼��չʾ�����¼
    //    showBorrow(bhead);
    //    showReturn(rhead);



//2.����Ǽǣ�����Ǽ�

//    register_borrow(bhead,books,books_number,readers,readers_number,bfp);
//    register_return(rhead,books,books_number,readers,readers_number,rfp);






    //�ͷ������ڴ棬��ֹ�ڴ�й¶
    rbclose(bhead,rhead);

    fclose(bfp);
    fclose(rfp);


}

void br_Menu(){
    int wherex_br()

    {

        CONSOLE_SCREEN_BUFFER_INFO pBuffer;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);

        return (pBuffer.dwCursorPosition.X + 1);

    }

//��ȡ����λ��y

    int wherey_br()

    {

        CONSOLE_SCREEN_BUFFER_INFO pBuffer;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);

        return (pBuffer.dwCursorPosition.Y + 1);

    }

//���ù���λ��

    void gotoxy_br(int x, int y)

    {

        COORD c;

        c.X = x - 1;

        c.Y = y - 1;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

    }

    void Menu_br(){

        setbuf(stdout,0);//����

        int x, y;

        //int select;

        gotoxy_reade(24, 5);

        printf("*******��ӭ�������߹���ϵͳ*******");

        gotoxy_reader(15, 8);

        printf("*********************���˵�*********************");

        gotoxy_reader(15, 9);

        printf("*                  1->��������                 *");

        gotoxy_reader(15, 10);

        printf("*                  2->ɾ������                 *");

        gotoxy_reader(15, 11);

        printf("*                  3->�޸Ķ���                 *");

        gotoxy_reader(15, 12);

        printf("*                  4->��ѯ����                 *");

        gotoxy_reader(15, 13);

        printf("*                  5->��ʾ����                 *");

        gotoxy_reader(15, 14);

        printf("**********************************************");

        gotoxy_reader(28, 16);

        printf("���������ѡ��(����):[ ]");

        x = wherex_reader();

        y = wherey_reader();

        gotoxy_reader(x - 2, y);




    }

};

