//
// Created by Vinci on 2023/5/8.
//
#include "stdio.h"
#include "../reader_manage.h"
#include "string.h"
#include "unistd.h"

int add_reader(Reader readers[],int readers_number,FILE *fp){
    fflush(stdin);
    rewind(fp);
    Reader addreader;
    printf("������Ҫ��ӵĶ�������\n");
    fgets(addreader.name, 12, stdin);

    if (strlen(addreader.name) == 11) {

        printf("�����Ҳ̫���˰ɣ�������");
        sleep(2);
        return -1;
    }

    addreader.name[strcspn(addreader.name, "\n")] = '\0';

    printf("��������ߵ��Ա���/Ů��");

    fgets(addreader.sex, 5, stdin);

    if (strlen(addreader.sex) == 4) {

        printf("�����Ҳ̫���˰ɣ�������");
        sleep(2);
        return -1;
    }

    addreader.sex[strcspn(addreader.sex, "\n")] = '\0';
    if(strcmp(addreader.sex,"��") !=0 && strcmp(addreader.sex , "Ů") !=0 ){
        printf("�����˴�����Ա�!!!!");
        sleep(2);
        return -1;
    }
    addreader.id=readers[readers_number-1].id+1;
    fprintf(fp, "%d %s %s\n", addreader.id, addreader.name,addreader.sex);

    printf("���ѳɹ�����µĶ���!");
    sleep(2);

    return 1;

}