//
// Created by Vinci on 2023/5/8.
//
#include "stdio.h"
#include "../reader_manage.h"

void add_reader(Reader readers[],int readers_number,FILE *fp){
    rewind(fp);
    Reader addreader;
    printf("������Ҫ��ӵĶ�������\n");
    scanf("%s",&addreader.name);
    addreader.id=readers[readers_number-1].id+1;
    fprintf(fp, "%d %s\n", addreader.id, addreader.name);
    printf("���ѳɹ�����µĶ���!");

}