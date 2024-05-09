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
    printf("                   学生成绩管理系统                    \n");
    printf("                      2022/6/10                        \n");
    printf("*******************************************************\n");
    printf("                      请选择功能                       \n");
    printf(" 1.显示已有信息\n 2.合并文件\n 3.查找需要补考的学生\n 4.成绩排序\n 5.查找学生\n");
    printf("*******************************************************\n");
    system("pause");

    gradelist file1=firead("1.txt");
    gradelist file2=firead("2.txt");

    int choice;
    while(choice!=-1){
    scanf("%d",&choice);
    switch(choice){
    case 1:

        printf("成绩信息一\n");
        showFile(file1);
        printf("*******************************\n");

        printf("成绩信息二\n");
        showFile(file2);
        printf("*******************************\n");
        break;

    case 2:
        //system("pause");
        printf("实现对两个文件数据进行合并，生成新文件3 \n");
    link();
    printf("合并成功\n");

    printf("*******************************\n");
    gradelist file3=firead("3.txt");
    showFile(file3);
    printf("*******************************\n");
    break;

    case 3:
        printf("抽取出三科成绩中有补考的学生并保存在一个新文件4 \n");
    bu_kao();
    //system("pause");
    printf("保存成功\n");
    printf("*******************************\n");
    gradelist file4=firead("4.txt");
    showFile(file4);
    printf("*******************************\n");
    break;

    case 4:
        printf("对合并后的文件3.txt中的数据按总分降序排序 \n");
    printf("方法一 冒泡排序\n");
    bubbleSort();
    file3=firead("3.txt");
    printf("已排序\n");
    printf("*******************************\n");
    showFile(file3);
    printf("*******************************\n");

    printf("方法二 选择排序\n");
    selectSort();
    file3=firead("3.txt");
    printf("已排序\n");
    printf("*******************************\n");
    showFile(file3);
    printf("*******************************\n");
    break;

    case 5:
         printf("输入一个学生姓名，查找此学生信息并输出 \n");
    char name1[20];
    printf("请输入要查找的学生姓名\n");
    scanf("%s",&name1);
    search(name1);
    printf("*******************************\n");

    printf("输入一个学生姓名，查找此学生信息并输出 \n");
    char name2[20];
    printf("请输入要查找的学生姓名\n");
    scanf("%s",&name2);
    search2(name2);
    printf("*******************************\n");
    break;

    default:
        break;
    }
    }
    printf("程序结束\n");

}
