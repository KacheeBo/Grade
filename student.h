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

    //以读文件的方式打开文件
    fp=fopen(ad,"r");
    //文件为空则退出
    if(fp==NULL){
        printf("文件打开错误");
        exit(0);
    }

    //为文件申请存储空间
    gradelist file=(Student *)malloc(sizeof(Student));
    file ->next =NULL;
    Student *p=file;  //Student结构体的指针，方便依次录入数据
    int i=0;
    //站在光标所在位置,向后看看还有没有字符
    while(!feof(fp)){
        //i=0时输入表头
        if(i==0){
            fgets(bt,100,fp);//从指定的流中读取数据，每次读取一行
        }
        //存入数据之前需要开放空间，动态申请内存空间
        if(i==1){
            (p->next)=(Student *)malloc(sizeof(Student));
            p=p->next;
            p->next=NULL;
        }
        //存放数据
        fscanf(fp,"%s %d %d %d %d",p->sname,&p->sno,&p->chinese,&p->math,&p->english);
        i=1;//重新开始存入
    }

    //关闭文件
    if(fclose(fp)){
        printf("closs Error!");
        exit(0);
    }
    return file;
}


//将内容显示在屏幕上
void showFile(gradelist file){
    //gradelist file=(Student *)malloc(sizeof(Student));
    Student *p=file;

    //将表头打印出来
    printf("%s\n",bt);
    //打印成绩表
    while(p->next!=NULL){
        printf("%5s %2d %d %d %d\n",p->sname,p->sno,p->chinese,p->math,p->english);
        p=p->next;
    }
}
#endif // STUDENT_H_INCLUDED
