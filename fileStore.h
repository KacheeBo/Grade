#ifndef FILESTORE_H_INCLUDED
#define FILESTORE_H_INCLUDED
#include "decsSort.h"
#include "fileMerge.h"
//#include "fileStore.h"
#include "score.h"
#include "search.h"
#include "student.h"
void bu_kao()//��ȡ���Ƴɼ����в�����ѧ����������һ�����ļ�4.txt
{
    FILE *fp;
    if((fp=fopen("4.txt","w+"))==NULL){
        printf("�������ļ�ʧ��");
        exit(0);//�����˳�
    }
    gradelist file3=firead("3.txt");//���ļ�3.txt����
    Student *p=file3;
    printf("����ѧ������");
    fprintf(fp,"%s",bt);
    while(p->next!=NULL){
        if((p->chinese)<60||(p->math)<60||(p->english)<60){
            fprintf(fp,"%6s %2d %d %d %d\n",p->sname,p->sno,p->chinese,p->math,p->english);
        }
        p=p->next;
    }
    if(fclose(fp)){
        printf("���ܹر��ļ�!\n");
        exit(0);
    }
}

#endif // FILESTORE_H_INCLUDED
