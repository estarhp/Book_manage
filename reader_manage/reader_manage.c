#include "stdio.h"
#include "windows.h"
#include "reader_manage.h"
//hhh
//hhhh
int Main_reader_mana(){
    FILE *fp=name_open();

    int readers_number= Readers_number(fp);//��ö�������

    Reader readers[readers_number];//������������

    put_reader(readers_number,fp,readers);//��������Ϣ��������

    Menu_reader();

    int will_reload = Collect_reader(readers_number,readers,fp);
    if (will_reload == 1){
        fclose(fp);//�ر��ļ�
        return 1;
    }

    fclose(fp);//�ر��ļ�

}
int Collect_reader(int readers_number,Reader readers[],FILE *fp){
    system("cls");
    Menu_reader();
    int Scanf;

    //�ռ��û���ѡ��
    scanf(" %d",&Scanf );
    getchar();
    int success;
    while (Scanf) {
        //���벻ͬģ��
        switch (Scanf) {

            case 1:
                success = add_reader(readers, readers_number, fp);
                if (success !=-1){
                    return 1;
                }
                break;

            case 2:
                delete_reader(readers_number, readers);
                return 1;
            case 3:
                modify_reader_by_id(readers_number, readers);
                break;
            case 4:
                search_reader(readers_number, readers);
                break;
            case 5:
                show_reader(readers_number, readers);
                break;
                default:
                printf("��������ȷ������\n");
                break;

        }
        getchar();//�ӿؼ���ȡ�ַ����������;
        Menu_reader();
        scanf("%d", &Scanf);
    }
}
int wherex_reader()

{

    CONSOLE_SCREEN_BUFFER_INFO pBuffer;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);

    return (pBuffer.dwCursorPosition.X + 1);

}

//��ȡ����λ��y

int wherey_reader()

{

    CONSOLE_SCREEN_BUFFER_INFO pBuffer;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);

    return (pBuffer.dwCursorPosition.Y + 1);

}

//���ù���λ��

void gotoxy_reader(int x, int y)

{

    COORD c;

    c.X = x - 1;

    c.Y = y - 1;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

void Menu_reader(){

    setbuf(stdout,0);//����

    int x, y;

    //int select;

    gotoxy_reader(24, 5);

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

//    gotoxy_reader(15, 14);
//    printf("*                  0->�˳�ϵͳ                  *");
    gotoxy_reader(15, 14);
    printf("**********************************************");

    gotoxy_reader(28, 16);

    printf("���������ѡ��(����):[ ]");

    x = wherex_reader();

    y = wherey_reader();

    gotoxy_reader(x - 2, y);




}

//void modify_reader_by_id(int readers_number,Reader readers[]){
//    int index = Search_byreaderid(readers_number,readers);
//    char newName[20];
//    printf("�������µĶ���");
//    scanf("%s",newName);
//    strcpy(readers[index].name,newName);
//
//    printf("%s",readers[index].name);
//    int will_delete[]={-1};
//    int number=0;
//
//    open_delete_reader(will_delete,number,readers_number,readers);
//
//
//
//}