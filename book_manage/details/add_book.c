//
// Created by 86139 on 2023/5/3.
//

#include "../book_manage.h"
#include "stdio.h"
#include "string.h"
#include "unistd.h"


int add_book(Book books[],int books_number,FILE *fp){
    fflush(stdin);
    rewind(fp);
    Book addbook;
    printf("������Ҫ��ӵ�����:\n");
    fgets(addbook.name, 50, stdin);

    if (strlen(addbook.name) == 49) {
        printf("�����Ҳ̫���˰ɣ�������");
        sleep(2);
        return -1;
    }

    addbook.name[strcspn(addbook.name, "\n")] = '\0';
//   addbook.name[strlen(addbook.name)-2] = ' ';


    printf("������Ҫ���ͼ�������:\n");

    fgets(addbook.writer, 20, stdin);

    if (strlen(addbook.writer) == 19) {

        printf("�����Ҳ̫���˰ɣ�������");
        sleep(2);
        return -1;
    }

    addbook.writer[strcspn(addbook.writer, "\n")] = '\0';





    addbook.id=books[books_number-1].id+1;
    fprintf(fp, "%d %s %s\n", addbook.id, addbook.writer, addbook.name);
    sleep(2);
    printf("������ӳɹ��µ��鼮�����½���ϵͳʱˢ�����ݣ�\n");

    return 1;
}
