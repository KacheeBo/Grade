#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "decsSort.h"
#include "fileMerge.h"
#include "fileStore.h"
#include "score.h"
//#include "search.h"
#include "student.h"

void search(char *name)//按姓名查找
{
    gradelist f=firead("3.txt");
    Student *p=f;
    while(p->next!=NULL)
    {
        if(strcmp(name,p->sname)==0)
        {
            printf("%5s %2d %d %d %d\n",p->sname,p->sno,p->chinese,p->math,p->english);
            return;
        }
        p=p->next;
    }

    printf("查无此人，请重新输入要查找的信息！\n");
}
void search2(char *name){
    gradelist f3=firead("3.txt");
    Student *p=f3;
    int n=0;
    while(p->next!=NULL){
        n++;
        p=p->next;
    }
     typedef struct Stu{
        char sname[20];
        int sno;
        int chinese;
        int math;
        int english; //新加入总分，方便计算
    }gradeFlag;
    //排序结构数组，方便输出

    typedef struct grade{
        gradeFlag g[500];
    }gradeTable;
    gradeTable T;
    p=f3;

    int i,flag=0;
    for(i=1;i<=n;i++){
            //出现数据类型匹配错误
        strcpy(T.g[i].sname,p->sname);
        T.g[i].sno=p->sno;
        T.g[i].chinese=p->chinese;
        T.g[i].math=p->math;
        T.g[i].english=p->english;
        p=p->next;
    }

    for(i=0;i<n;i++)
    {
        if(strcmp(T.g[i].sname,name)==0)
        {
            printf("%5s %2d %d %d %d\n",T.g[i].sname,T.g[i].sno,T.g[i].chinese,T.g[i].math,T.g[i].english);
            flag=1;
            return;
        }

    }
    if(flag==0){
        printf("查无此人，请重新输入要查找的信息！\n");
    }

}
#endif // SEARCH_H_INCLUDED
