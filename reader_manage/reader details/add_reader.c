//
// Created by Vinci on 2023/5/8.
//
#include "stdio.h"
#include "../reader_manage.h"
#include "string.h"

void add_reader(Reader readers[],int readers_number,FILE *fp){
    rewind(fp);
    Reader addreader;
    printf("������Ҫ��ӵĶ�������\n");
    scanf("%s",&addreader.name);
    printf("��������ߵ��Ա���/Ů��");
    scanf("%s",&addreader.sex);
    if(strcmp(addreader.sex,"��") !=0 && strcmp(addreader.sex , "Ů") !=0 ){
        printf("�����˴�����Ա�!!!!");
        return;
    }
    addreader.id=readers[readers_number-1].id+1;
    fprintf(fp, "%d %s %s\n", addreader.id, addreader.name,addreader.sex);
    printf("���ѳɹ�����µĶ���!");

}