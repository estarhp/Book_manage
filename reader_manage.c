//���߹���ģ��
//��������
//ɾ��
//�޸�
//��ѯ
//��ʾ
//����������Ϣ
#include "stdio.h"
#include "stdlib.h"
typedef struct reader {
    char id[15];
    char name[12];
    char sex[3];
} Reader;

int Readers_number(FILE *fp);
void put_reader(int number,FILE *fp,Reader readers[]);
FILE * name_open();
int Readers_number(FILE *fp);

void Main_reader_mana(){
    FILE *fp=name_open();

    int readers_number= Readers_number(fp);//�����������

    Reader readers[readers_number];//������������

    put_reader(readers_number,fp,readers);//�����߷�������

    for (int i = 0; i < readers_number; ++i) {
        printf("%s %s %s\n",readers[i].id,readers[i].name,readers[i].sex);
    }
}

int Readers_number(FILE *fp) {

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

FILE * name_open(){
    FILE *fp;

    if ((fp = fopen("../name.txt", "r")) == NULL){
        if ((fp = fopen("name.txt", "r")) == NULL){
            printf("�ļ�·��Error!\n");
        }
    }

    return fp;
}

void put_reader(int number,FILE *fp,Reader readers[]) {
    for (int i = 0; i < number; ++i) {
        fscanf(fp,"%s %s %s",&readers[i].id,&readers[i].name,&readers[i].sex);
    }//���ļ������鱾

    fclose(fp);

}

