#ifndef FILESTORE_H_INCLUDED
#define FILESTORE_H_INCLUDED
#include "decsSort.h"
#include "fileMerge.h"
//#include "fileStore.h"
#include "score.h"
#include "search.h"
#include "student.h"
void bu_kao()//抽取三科成绩中有补考的学生并保存在一个新文件4.txt
{
    FILE *fp;
    if((fp=fopen("4.txt","w+"))==NULL){
        printf("建立新文件失败");
        exit(0);//程序退出
    }
    gradelist file3=firead("3.txt");//读文件3.txt内容
    Student *p=file3;
    printf("补考学生名单");
    fprintf(fp,"%s",bt);
    while(p->next!=NULL){
        if((p->chinese)<60||(p->math)<60||(p->english)<60){
            fprintf(fp,"%6s %2d %d %d %d\n",p->sname,p->sno,p->chinese,p->math,p->english);
        }
        p=p->next;
    }
    if(fclose(fp)){
        printf("不能关闭文件!\n");
        exit(0);
    }
}

#endif // FILESTORE_H_INCLUDED
