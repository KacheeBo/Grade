#include <stdio.h>
#include <stdlib.h>
#include "decsSort.h"
#include "fileMerge.h"
#include "fileStore.h"
#include "score.h"
#include "search.h"
#include "student.h"


int main()
{
    printf("*******************************************************\n");
    printf("                   ѧ���ɼ�����ϵͳ                    \n");
    printf("                      2022/6/10                        \n");
    printf("*******************************************************\n");
    printf("                      ��ѡ����                       \n");
    printf(" 1.��ʾ������Ϣ\n 2.�ϲ��ļ�\n 3.������Ҫ������ѧ��\n 4.�ɼ�����\n 5.����ѧ��\n");
    printf("*******************************************************\n");
    system("pause");

    gradelist file1=firead("1.txt");
    gradelist file2=firead("2.txt");

    int choice;
    while(choice!=-1){
    scanf("%d",&choice);
    switch(choice){
    case 1:

        printf("�ɼ���Ϣһ\n");
        showFile(file1);
        printf("*******************************\n");

        printf("�ɼ���Ϣ��\n");
        showFile(file2);
        printf("*******************************\n");
        break;

    case 2:
        //system("pause");
        printf("ʵ�ֶ������ļ����ݽ��кϲ����������ļ�3 \n");
    link();
    printf("�ϲ��ɹ�\n");

    printf("*******************************\n");
    gradelist file3=firead("3.txt");
    showFile(file3);
    printf("*******************************\n");
    break;

    case 3:
        printf("��ȡ�����Ƴɼ����в�����ѧ����������һ�����ļ�4 \n");
    bu_kao();
    //system("pause");
    printf("����ɹ�\n");
    printf("*******************************\n");
    gradelist file4=firead("4.txt");
    showFile(file4);
    printf("*******************************\n");
    break;

    case 4:
        printf("�Ժϲ�����ļ�3.txt�е����ݰ��ֽܷ������� \n");
    printf("����һ ð������\n");
    bubbleSort();
    file3=firead("3.txt");
    printf("������\n");
    printf("*******************************\n");
    showFile(file3);
    printf("*******************************\n");

    printf("������ ѡ������\n");
    selectSort();
    file3=firead("3.txt");
    printf("������\n");
    printf("*******************************\n");
    showFile(file3);
    printf("*******************************\n");
    break;

    case 5:
         printf("����һ��ѧ�����������Ҵ�ѧ����Ϣ����� \n");
    char name1[20];
    printf("������Ҫ���ҵ�ѧ������\n");
    scanf("%s",&name1);
    search(name1);
    printf("*******************************\n");

    printf("����һ��ѧ�����������Ҵ�ѧ����Ϣ����� \n");
    char name2[20];
    printf("������Ҫ���ҵ�ѧ������\n");
    scanf("%s",&name2);
    search2(name2);
    printf("*******************************\n");
    break;

    default:
        break;
    }
    }
    printf("�������\n");

}
