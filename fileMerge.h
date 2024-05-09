#ifndef FILEMERGE_H_INCLUDED
#define FILEMERGE_H_INCLUDED
#include "decsSort.h"
//#include "fileMerge.h"
#include "fileStore.h"
#include "score.h"
#include "search.h"
#include "student.h"
void link()
{
    char *address1="1.txt",*address2="2.txt",*address3="3.txt";
    gradelist f1=firead(address1), f2=firead(address2);
    FILE *fp;
    if((fp=fopen("3.txt","w+"))==NULL)
    {
        printf("合并文件失败");
        exit(0);
    }
    Student *p1=f1,*p2=f2;
    fprintf(fp,"%s",bt);
    while(p1->next!=NULL)
    {
        fprintf(fp,"%5s %2d %d %d %d\n",p1->sname,p1->sno,p1->chinese,p1->math,p1->english);
        p1=p1->next;
    }
    while(p2->next!=NULL)
    {
        fprintf(fp,"%6s %2d %d %d %d\n",p2->sname,p2->sno,p2->chinese,p2->math,p2->english);
        p2=p2->next;
    }
    if(fclose(fp))
    {
        printf("关闭文件失败");
        exit(0);
    }
}


#endif // FILEMERGE_H_INCLUDED
