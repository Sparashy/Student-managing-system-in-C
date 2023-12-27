#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define Mnamelen 100//最大姓名长度

#ifndef management
#define management
typedef struct student//学生结构体
{
    char name[Mnamelen];
    char id[11];
    int math;
    int english;
    int Computer_Programming;
    int total;
    double ave;
} student;

typedef struct node//链表节点
{
    student s;
    struct node *next;
} node;
typedef struct node* head;
typedef struct node* ptrtonode;
#endif
//函数声明
void add_inf(head h);
void delete_inf(head h);
void edit_inf(head h);
void get_inf(head h);
void get_inf_with_name(head h);
void get_inf_with_id(head h);
void get_inf_with_ranking(head h);
void show_all_inf(head h);
void show_student(student A);
int show_amount(head h);
void show_ranking(head h);