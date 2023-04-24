#include "stdio.h"
#include "stdlib.h"
#include "string.h"
# define MAX_LEN 50
typedef struct reader {
    char id[15];
    char name[12];
    char sex[3];
} Reader;

int Readers_number(FILE *fp);
void put_reader(int number,FILE *fp,Reader readers[]);//��ʼ��
FILE * name_open();
void Menu_reader();
void Collect_reader(int readers_number,Reader readers[],FILE *fp);//�ռ��û���ѡ��
int Readers_number(FILE *fp);
void query_reader(int readers_number,Reader readers[]);//��ѯ����
void show_reader(int readers_number,Reader *readers);//չʾ������Ϣ
void Search_by_id(int readers_number,Reader readers[]);//ͨ��id
void Search_by_name(int readers_number,Reader readers[]);//ͨ����������
void delete_reader();//ɾ��
void modify_reader();//�޸�
void add_reader(Reader readers[],int readers_number,FILE *fp);//����
//�������
void Main_reader_mana(){
    FILE *fp=name_open();

    int readers_number= Readers_number(fp);//��ö�������

    Reader readers[readers_number];//������������

    put_reader(readers_number,fp,readers);//��������Ϣ��������
    //???????
//    for (int i = 0; i < readers_number; ++i) {
//        printf("%s %s %s\n",readers[i].id,readers[i].name,readers[i].sex);
//    }2
    Menu_reader();

    Collect_reader(readers_number,readers,fp);

    fclose(fp);//�ر��ļ�

}
void show_reader(int readers_number,Reader readers[])
{
    int start=0,end=0;
    printf("������Ҫ��ѯ�Ķ��ߵ�������Χ��\n������__��ʼ��");
    scanf("%d",&start);
    printf("������__������");
    scanf("%d",&end);
    printf("����Ϊ����������%d~%d��Χ֮�ڵĶ��ߣ�\n",start,end);

    for (int i = start; i <= end; ++i) {
        printf("%d %s %s\n",readers[i].id,readers[i].name,readers[i].sex);
    }
}
void query_reader(int readers_number,Reader readers[])
{

    int select_mode=0;
    printf("\n\t                        1->ͨ��id                         \t\n");
    printf("\n\t                        2->ͨ������                        \t\n");
    printf("\n\t                        3->ͨ������                        \t\n");
    printf("\n\t                      ���������ѡ�����֣���                \n\t");

    scanf("%d",&select_mode);
    switch (select_mode) {
        case 1:
            Search_by_id(readers_number,readers);
            break;
        case 2:Search_by_name(readers_number,readers);


    }

}
void Search_by_id(int readers_number,Reader readers[])
{
    char id[40];
    printf("��������ߵ�id");
    scanf("%d",&id);
    printf("������ƥ��Ĳ�ѯ�����\n");
    for (int i = 0; i < readers_number; ++i) {
        if(readers[i].id == id){

            printf("%d %s %s ",readers[i].id,readers[i].name,readers[i].sex);
        }
    }

}
void Search_by_name(int readers_number,Reader readers[])
{
    char name[50];
    printf("��������ߵ�����");
    scanf("%s",&name);
    printf("������ƥ��Ĳ�ѯ�����\n");
    for (int i = 0; i < readers_number; ++i) {
        if(strcmp(name,readers[i].name)==0){

            printf("%d %s %s ",readers[i].id,readers[i].sex,readers[i].name);
        }

    }
}
int Readers_number(FILE *fp) {

    int flag = 0, file_row = 0, count = 0;
    while (!feof(fp)) {
        flag = fgetc(fp);
        if (flag == '\n')
            count++;
    }
    file_row = count; //����������˵�������

    rewind(fp);
    return file_row;
}

FILE * name_open(){
    FILE *fp;

    if ((fp = fopen("../reader_manage/name.txt", "r")) == NULL){
        if ((fp = fopen("reader/name.txt", "r")) == NULL){
            printf("???��??Error!\n");
        }
    }

    return fp;
}

void put_reader(int number,FILE *fp,Reader readers[]) {
    for (int i = 0; i < number; ++i) {
        fscanf(fp,"%s %s %s",&readers[i].id,&readers[i].name,&readers[i].sex);
    }//���ļ���������

    fclose(fp);

}
void Collect_reader(int readers_number,Reader readers[],FILE *fp){
    int Scanf;
    //�ռ��û���ѡ��
    scanf("%d",&Scanf);
    //���벻ͬģ��
    switch (Scanf) {

        case 1:add_reader(readers,readers_number,fp);
            break;
        case 2:delete_reader();
            break;
        case 3:modify_reader();
            break;
        case 4:query_reader(readers_number,readers);
            break;
        case 5:show_reader(readers_number,readers);
            break;

    }
}
void Menu_reader(){


    //system("cls");

    //int select;
    //printf("hhhhhhh");
    printf("\n*******************���߹���ϵͳ******************\t\n");
    printf("\n*********************���˵�*********************\t\n");
    printf("\n*                  1->��������                 *\t\n");
    printf("\n*                  2->ɾ������                 *\t\n");
    printf("\n*                  3->�޸Ķ���                 *\t\n");
    printf("\n*                  4->��ѯ����                 *\t\n");
    printf("\n*                  5->��ʾ����                 *\t\n");
    printf("\n***********************************************\t\n");
    printf("\n���������ѡ��(����):\t\n");



    //scanf_s("%d", &select);
    //Collect_operation();


    void Collect_reader(int readers_number,Reader readers[],FILE *fp);
    system("pause");

    //return 0;*/

}
