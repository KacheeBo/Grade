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
//����1��ѡ������
void selectSort(){
    //һ�����ļ����д��� �ҳ��ļ�3�ĵ�ַ
    char *ad3="3.txt";

    //���ļ�3�����ݴ���ṹf3��
    gradelist f3=firead(ad3);
    Student *p=f3;

    //���ļ�3�������
    //�Ƚ��ļ�3ɾ�� ʹ��remove����
    if(remove("3.txt")){
        printf("ɾ��ʧ��");
        exit(0);
    }
    FILE *fp;
    //���½��ļ�3
    if((fp=fopen("3.txt","w+"))==NULL){
        printf("�½�ʧ��");
        exit(0);
    }

    //�ļ�3����
    fprintf(fp,"%s",bt);

    //����ѧ������
    int stucnt=0;
    while(p->next!=NULL){
        stucnt++;
        p=p->next;
    }

    //���������ֲ��ṹ�巽�����,��������Ҫ��������洢����
    //�洢����
    typedef struct Stu{
        char sname[20];
        int sno;
        int chinese;
        int math;
        int english;
        int totalscore;  //�¼����ܷ֣��������
    }gradeFlag;
    //����ṹ���飬�������
    typedef struct grade{
        gradeFlag g[500];
    }gradeTable;
    gradeTable T; //����T����ṹ����
    p=f3;
    //�����ݷ���T�ṹ������
    int i;
    for(i=1;i<=stucnt;i++,p=p->next){
            //������������ƥ�����
        strcpy(T.g[i].sname,p->sname);
        T.g[i].sno=p->sno;
        T.g[i].chinese=p->chinese;
        T.g[i].math=p->math;
        T.g[i].english=p->english;
        T.g[i].totalscore=p->chinese+p->math+p->english;

    }

    //������ʼ����(ѡ������)
    int maxx=0;  //������ס������ֵ�λ���±��
    int t,j,w;  //ѭ������
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

    //����д���ļ�
    //fprintf(fp,"%s",bt);
    for(w=0;w<stucnt+1;w++){
        fprintf(fp,"%5s %2d %d %d %d\n",T.g[w].sname,T.g[w].sno,
                  T.g[w].chinese,T.g[w].math,T.g[w].english);

    }
     if(fclose(fp)){
        printf("���ܹر��ļ�!\n");
        exit(0);
    }

}

//����2��ð������
void bubbleSort(){
    //һ�����ļ����д��� �ҳ��ļ�3�ĵ�ַ
    char *ad3="3.txt";

    //���ļ�3�����ݴ���ṹf3��
    gradelist f3=firead(ad3);
    Student *p=f3;

    //���ļ�3�������
    //�Ƚ��ļ�3ɾ�� ʹ��remove����
    if(remove("3.txt")){
        printf("ɾ��ʧ��");
        exit(0);
    }
    FILE *fp;
    //���½��ļ�3
    if((fp=fopen("3.txt","w+"))==NULL){
        printf("�½�ʧ��");
        exit(0);
    }

    //�ļ�3����
    fprintf(fp,"%s",bt);

    //����ѧ������
    int stucnt=0;
    while(p->next!=NULL){
        stucnt++;
        p=p->next;
    }

    //���������ֲ��ṹ�巽�����,��������Ҫ��������洢����
    //�洢����
    typedef struct Stu{
        char sname[20];
        int sno;
        int chinese;
        int math;
        int english;
        int totalscore;  //�¼����ܷ֣��������
    }gradeFlag;
    //����ṹ���飬�������
    typedef struct grade{
        gradeFlag g[500];
    }gradeTable;
    gradeTable T; //����T����ṹ����
    p=f3;
    //�����ݷ���T�ṹ������
    int i;
    for(i=1;i<=stucnt;i++){
            //������������ƥ�����
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
        printf("���ܹر��ļ�!\n");
        exit(0);
    }
}
#endif // DECSSORT_H_INCLUDED
