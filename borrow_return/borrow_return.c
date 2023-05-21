#include "stdio.h"
#include "windows.h"
#include "borrow_return.h"
#include "malloc.h"


void Collect_br(Borrow *bhead,Return *rhead,Book books[],int books_number,Reader readers[],int readers_number,FILE *bfp,FILE *rfp);
int wherex_br();
int wherey_br();
void gotoxy_br(int x, int y);
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


    //br_Menu();
    Collect_br(bhead,rhead,books,books_number,readers,readers_number,bfp,rfp);
        //br_Menu();
// 1.չʾ�����¼��չʾ�����¼
//        showBorrow(bhead);
//        showReturn(rhead);
//2.����Ǽǣ�����Ǽ�

//    register_borrow(bhead,books,books_number,readers,readers_number,bfp);
//    register_return(rhead,books,books_number,readers,readers_number,rfp);
    //�ͷ������ڴ棬��ֹ�ڴ�й¶
    rbclose(bhead,rhead);

    fclose(bfp);
    fclose(rfp);


}
void Collect_br(Borrow *bhead,Return *rhead,Book books[],int books_number,Reader readers[],int readers_number,FILE *bfp,FILE *rfp){
    br_Menu();//��ʾ���ݹ�����Ӳ˵�
    int Scanf;
    scanf("%d",&Scanf );
    getchar();


    //�ռ��û���ѡ��


    //���벻ͬģ��
    while(Scanf)
    {
        switch (Scanf) {
            case 0:
                break;
            case 1:
                showBorrow(bhead);
                break;
            case 2:
                showReturn(rhead);
                break;
            case 3:
                register_borrow(bhead,books,books_number,readers,readers_number,bfp);
                break;
            case 4:
                register_return(rhead,books,books_number,readers,readers_number,rfp);
                break;
            default:
                printf("��������ȷ������\n");
                break;

        }
        //printf("|�밴����������Ӳ˵�|\n");
        fflush(stdin);
        getchar();
        system("cls");
        //�ӿؼ���ȡ�ַ����������;
        br_Menu();
        scanf("%d", &Scanf);
        //getchar();

    }

}


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

 void br_Menu(){

        setbuf(stdout,0);//����

        int x, y;

        //int select;
        system("cls");

        gotoxy_br(24, 5);

        printf("*******��ӭ�����軹����ϵͳ*******");

        gotoxy_br(15, 8);

        printf("*********************���˵�*********************");

        gotoxy_br(15, 9);

        printf("*                  1->չʾ�����¼             *");

        gotoxy_br(15, 10);

        printf("*                  2->չʾ�����¼             *");

        gotoxy_br(15, 11);
        printf("*                  3->����Ǽ�                 *");
        gotoxy_br(15,12);

        printf("*                  4->����Ǽ�                 *");

        gotoxy_br(15,13);
        printf("*                  0->�������˵�               *");
        gotoxy_br(15,14);
        printf("************************************************");

        gotoxy_br(28, 16);

        printf("���������ѡ��(����):[ ]");

        x = wherex_br();

        y = wherey_br();

        gotoxy_br(x - 2, y);


}

