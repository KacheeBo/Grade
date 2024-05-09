#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include "decsSort.h"
#include "fileMerge.h"
#include "fileStore.h"
#include "score.h"
#include "search.h"
//#include "student.h"
char bt[500];
typedef struct Student{
    char sname[20];
    int sno;
    int chinese;
    int math;
    int english;
    struct Student *next;
}Student,*gradelist;
gradelist firead(char *ad){
    FILE *fp;

    //�Զ��ļ��ķ�ʽ���ļ�
    fp=fopen(ad,"r");
    //�ļ�Ϊ�����˳�
    if(fp==NULL){
        printf("�ļ��򿪴���");
        exit(0);
    }

    //Ϊ�ļ�����洢�ռ�
    gradelist file=(Student *)malloc(sizeof(Student));
    file ->next =NULL;
    Student *p=file;  //Student�ṹ���ָ�룬��������¼������
    int i=0;
    //վ�ڹ������λ��,��󿴿�����û���ַ�
    while(!feof(fp)){
        //i=0ʱ�����ͷ
        if(i==0){
            fgets(bt,100,fp);//��ָ�������ж�ȡ���ݣ�ÿ�ζ�ȡһ��
        }
        //��������֮ǰ��Ҫ���ſռ䣬��̬�����ڴ�ռ�
        if(i==1){
            (p->next)=(Student *)malloc(sizeof(Student));
            p=p->next;
            p->next=NULL;
        }
        //�������
        fscanf(fp,"%s %d %d %d %d",p->sname,&p->sno,&p->chinese,&p->math,&p->english);
        i=1;//���¿�ʼ����
    }

    //�ر��ļ�
    if(fclose(fp)){
        printf("closs Error!");
        exit(0);
    }
    return file;
}


//��������ʾ����Ļ��
void showFile(gradelist file){
    //gradelist file=(Student *)malloc(sizeof(Student));
    Student *p=file;

    //����ͷ��ӡ����
    printf("%s\n",bt);
    //��ӡ�ɼ���
    while(p->next!=NULL){
        printf("%5s %2d %d %d %d\n",p->sname,p->sno,p->chinese,p->math,p->english);
        p=p->next;
    }
}
#endif // STUDENT_H_INCLUDED
