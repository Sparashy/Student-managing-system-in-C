#include "management.h"

extern FILE *fr;
extern FILE *fa;
void add_inf(head h) // 添加信息
{
    ptrtonode tmp = h;
    ptrtonode ptr;
    ptr = (ptrtonode)malloc(sizeof(node)); // 创建节点
    printf("请输入姓名：\n");
    scanf("%s", ptr->s.name);
    printf("请输入id：\n");
id:
    scanf("%s", ptr->s.id);
    while (tmp->next != NULL)
    {
        if (!strcmp(tmp->next->s.id, ptr->s.id))
        {
            printf("请重新输入，id重复\n");
            goto id;
        }
        if (strlen(ptr->s.id) > 10)
        {
            printf("id过长\n");
            goto id;
        }
        tmp = tmp->next;
    }
    printf("请输入成绩（数学 英语 程序设计）：\n");
    scanf("%d %d %d", &ptr->s.math, &ptr->s.english, &ptr->s.Computer_Programming);
    ptr->s.total = ptr->s.math + ptr->s.english + ptr->s.Computer_Programming;
    ptr->s.ave = ptr->s.total / 3.0;
    ptr->next = h->next;
    h->next = ptr;
    system("pause");
}

void delete_inf(head h) // 删除信息
{
    ptrtonode tmp = h;
    student stu;
    int flag = 0;
input:
    printf("请输入id：\n");
    char tmpid[11] = {0};

    scanf("%s", tmpid);
    if (strlen(tmpid) > 10) // 检测id长度是否合法
    {
        printf("id过长\n");
        goto input;
    }
    while (tmp->next != NULL)
    {
        stu = tmp->next->s;
        if (!strcmp(stu.id, tmpid))
        {
            flag = 1;
            break;
        }
        tmp = tmp->next;
    }
    ptrtonode tmp2;
    tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    free(tmp2);
    if (!flag)
    {
        printf("查无此人\n");
    }
    system("pause");
}

void edit_inf(head h) // 修改信息
{
    ptrtonode tmp = h;
    student* stu;
    int flag = 0;
input:
    printf("请输入id：\n");
    char tmpid[11] = {0};

    scanf("%s", tmpid);
    if (strlen(tmpid) > 10)
    {
        printf("id过长\n");
        goto input;
    }
    while (tmp->next != NULL)
    {
        stu = &(tmp->next->s);
        if (!strcmp(stu->id, tmpid))
        {
            flag = 1;
            break;
        }
        tmp = tmp->next;
    }
    if (!flag)
    {
        printf("查无此人\n");
    }
    printf("请输入修改的项目（0.姓名 1.id 2.成绩）\n");
    int n;
    scanf("%d", &n);
    char tmpname[Mnamelen] = {0};
    switch (n)
    {
    case 0:
        printf("请输入姓名：\n");

        scanf("%s", tmpname);
        strcpy(stu->name, tmpname);
        break;
    case 1:
        printf("请输入id:\n");
        scanf("%s", tmpid);
        strcpy(stu->id, tmpid);
        break;
    case 2:
        int k, grade;
    enter:
        printf("请输入修改的科目：（1.数学 2.英语 3.程序设计 0.退出）\n");
        scanf("%d", &k);
        switch (k)
        {

        case 0:
            break;
        case 1:
            scanf("%d", &grade);
            stu->math = grade;
            goto enter;
        case 2:
            scanf("%d", &grade);
            stu->english = grade;
            goto enter;
        case 3:
            scanf("%d", &grade);
            stu->Computer_Programming = grade;
            goto enter;

        default:
            break;
        }

    default:
        break;
    }
    system("pause");
}

void get_inf(head h) // 查找信息
{
    printf("请输入查找方式：（0.姓名查找 1.id查找）\n");
    int flag;
    scanf("%d", &flag);
    switch (flag)
    {
    case 0:
        get_inf_with_name(h);
        break;
    case 1:
        get_inf_with_id(h);
        break;
    default:
        return;
        break;
    }
}

void show_student(student A) // 显示学生信息
{
    printf("姓名:%s\n", A.name);
    printf("id:%s\n", A.id);
    printf("成绩:(数学 英语 程序设计)\n%d %d %d\n", A.math, A.english, A.Computer_Programming);
    printf("总分:%d\n", A.total);
    printf("均分:%lf\n\n", A.ave);
}

void get_inf_with_name(head h) // 以姓名查找
{
    ptrtonode tmp = h;
    student stu;
    int flag = 0;
    printf("请输入姓名：\n");
    char tmpname[Mnamelen] = {0};
    scanf("%s", tmpname);
    while (tmp->next != NULL)
    {
        stu = tmp->next->s;
        if (!strcmp(stu.name, tmpname))
        {
            flag = 1;
            show_student(stu);
        }
        tmp = tmp->next;
    }
    if (!flag)
    {
        printf("查无此人\n");
    }
    system("pause");
}

void get_inf_with_id(head h) // 以id查找
{
    ptrtonode tmp = h;
    student stu;
    int flag = 0;
    printf("请输入id：\n");
    char tmpid[11] = {0};
    scanf("%s", tmpid);
    while (tmp->next != NULL)
    {
        stu = tmp->next->s;
        if (!strcmp(stu.id, tmpid))
        {
            flag = 1;
            show_student(stu);
        }
        tmp = tmp->next;
    }
    if (!flag)
    {
        printf("查无此人\n");
    }
    system("pause");
}

void show_all_inf(head h) // 显示所有信息
{
    ptrtonode tmp = h;
    if (tmp->next == NULL)
        return;
    while (tmp->next != NULL)
    {
        show_student(tmp->next->s);
        tmp = tmp->next;
    }
    system("pause");
}

int show_amount(head h)//显示已录入学生人数
{
    int ans = 0;
    while (h->next != NULL)
    {
        ans++;
        h = h->next;
    }
    printf("共有%d个学生已录入\n", ans);
    system("pause");
    return ans;
}

void show_ranking(head h)//将学生按成绩从大到小排序并输出
{
    int n = show_amount(h);
    if (n == 0)
        return;
    else if (n == 1)
    {
        show_student(h->next->s);
        return;
    }
    ptrtonode pf, pl;
    for (int i = 0; i < n - 1; i++)
    {
        pf = h;
        pl = h->next;
        for (int j = 0; j < n - 1; j++)
        {
            if (pl->s.total < pl->next->s.total)
            {
                pf->next = pl->next;
                ptrtonode tmp = pl->next->next;
                pl->next->next = pl;
                pl->next = tmp;
                pf = pf->next;
            }
            else
            {
                pf = pf->next;
                pl = pl->next;
            }
        }
    }
    show_all_inf(h);
}