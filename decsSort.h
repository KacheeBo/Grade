#ifndef DECSSORT_H_INCLUDED
#define DECSSORT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
//#include "decsSort.h"
#include "fileMerge.h"
#include "fileStore.h"
#include "score.h"
#include "search.h"
#include "student.h"
//方法1：选择排序
void selectSort(){
    //一、对文件进行处理 找出文件3的地址
    char *ad3="3.txt";

    //将文件3的内容存入结构f3中
    gradelist f3=firead(ad3);
    Student *p=f3;

    //将文件3内容清空
    //先将文件3删除 使用remove函数
    if(remove("3.txt")){
        printf("删除失败");
        exit(0);
    }
    FILE *fp;
    //再新建文件3
    if((fp=fopen("3.txt","w+"))==NULL){
        printf("新建失败");
        exit(0);
    }

    //文件3标题
    fprintf(fp,"%s",bt);

    //计算学生个数
    int stucnt=0;
    while(p->next!=NULL){
        stucnt++;
        p=p->next;
    }

    //二、建立局部结构体方便计算,用数组需要大量数组存储数据
    //存储数据
    typedef struct Stu{
        char sname[20];
        int sno;
        int chinese;
        int math;
        int english;
        int totalscore;  //新加入总分，方便计算
    }gradeFlag;
    //排序结构数组，方便输出
    typedef struct grade{
        gradeFlag g[500];
    }gradeTable;
    gradeTable T; //设置T整体结构数组
    p=f3;
    //将数据放入T结构数组中
    int i;
    for(i=1;i<=stucnt;i++,p=p->next){
            //出现数据类型匹配错误
        strcpy(T.g[i].sname,p->sname);
        T.g[i].sno=p->sno;
        T.g[i].chinese=p->chinese;
        T.g[i].math=p->math;
        T.g[i].english=p->english;
        T.g[i].totalscore=p->chinese+p->math+p->english;

    }

    //三、开始排序(选择排序)
    int maxx=0;  //用来记住最大数字的位置下表标
    int t,j,w;  //循环计数
    //int len=sizeof(T.g)/sizeof(T.g[0]);
    int temp=stucnt+1;
    for(i=0;i<stucnt;i++){
        maxx=i;
        for(j=i+1;j<=stucnt;j++){
            if(T.g[j].totalscore>T.g[maxx].totalscore){
                    maxx=j;
            }
        }
        if(maxx!=i){
            T.g[temp]=T.g[i];
            T.g[i]=T.g[maxx];
            T.g[maxx]=T.g[temp];
        }

    }

    //数据写入文件
    //fprintf(fp,"%s",bt);
    for(w=0;w<stucnt+1;w++){
        fprintf(fp,"%5s %2d %d %d %d\n",T.g[w].sname,T.g[w].sno,
                  T.g[w].chinese,T.g[w].math,T.g[w].english);

    }
     if(fclose(fp)){
        printf("不能关闭文件!\n");
        exit(0);
    }

}

//方法2：冒泡排序
void bubbleSort(){
    //一、对文件进行处理 找出文件3的地址
    char *ad3="3.txt";

    //将文件3的内容存入结构f3中
    gradelist f3=firead(ad3);
    Student *p=f3;

    //将文件3内容清空
    //先将文件3删除 使用remove函数
    if(remove("3.txt")){
        printf("删除失败");
        exit(0);
    }
    FILE *fp;
    //再新建文件3
    if((fp=fopen("3.txt","w+"))==NULL){
        printf("新建失败");
        exit(0);
    }

    //文件3标题
    fprintf(fp,"%s",bt);

    //计算学生个数
    int stucnt=0;
    while(p->next!=NULL){
        stucnt++;
        p=p->next;
    }

    //二、建立局部结构体方便计算,用数组需要大量数组存储数据
    //存储数据
    typedef struct Stu{
        char sname[20];
        int sno;
        int chinese;
        int math;
        int english;
        int totalscore;  //新加入总分，方便计算
    }gradeFlag;
    //排序结构数组，方便输出
    typedef struct grade{
        gradeFlag g[500];
    }gradeTable;
    gradeTable T; //设置T整体结构数组
    p=f3;
    //将数据放入T结构数组中
    int i;
    for(i=1;i<=stucnt;i++){
            //出现数据类型匹配错误
        strcpy(T.g[i].sname,p->sname);
        T.g[i].sno=p->sno;
        T.g[i].chinese=p->chinese;
        T.g[i].math=p->math;
        T.g[i].english=p->english;
        T.g[i].totalscore=p->chinese+p->math+p->english;
        p=p->next;
    }

    int flag,nflag, tmp=stucnt+1;
    flag=stucnt;
    do{
        nflag = 0;
        for(i = 0; i < stucnt - 1; i++){
            if(T.g[i].totalscore > T.g[i+1].totalscore){
                T.g[tmp] = T.g[i];
                T.g[i]= T.g[i+1];
                T.g[i+1] = T.g[tmp];
                nflag = i + 1;
            }
        }
        stucnt = nflag;
    }while(nflag);
    int w;
    for(w=flag-1;w>=0;w--){
        fprintf(fp,"%5s %2d %d %d %d\n",T.g[w].sname,T.g[w].sno,
                  T.g[w].chinese,T.g[w].math,T.g[w].english);

    }
     if(fclose(fp)){
        printf("不能关闭文件!\n");
        exit(0);
    }
}
#endif // DECSSORT_H_INCLUDED
