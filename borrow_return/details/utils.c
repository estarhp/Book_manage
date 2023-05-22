//
// Created by 86139 on 2023/5/16.
//
#include <stdio.h>
#include <time.h>
#include "string.h"
#include "malloc.h"
#include "../borrow_return.h"


void createTime(char time_str[]) {
    time_t raw_time;
    struct tm* time_info;

    // ��ȡ��ǰʱ���
    time(&raw_time);

    // ��ʱ���ת��Ϊ����ʱ��
    time_info = localtime(&raw_time);

    strftime(time_str, 20, "%Y-%m-%d-%H:%M:%S", time_info);  // ʹ�ù̶���С�Ļ�����

}

void rbclose(Borrow *bhead,Return *rhead){
    Borrow *q = NULL;
    for (Borrow *p = bhead; p!=NULL; q=p,p=p->next) {
        free(q);
    }
    free(q);

    Return *t = NULL;
    for (Return *p = rhead; p!=NULL; t = p ,p=p->next) {
        free(t);
    }

    free(t);
}

