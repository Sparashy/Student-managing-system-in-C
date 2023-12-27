#include "management.h"

extern FILE *fr;
extern FILE *fa;
void add_inf(head h) // �����Ϣ
{
    ptrtonode tmp = h;
    ptrtonode ptr;
    ptr = (ptrtonode)malloc(sizeof(node)); // �����ڵ�
    printf("������������\n");
    scanf("%s", ptr->s.name);
    printf("������id��\n");
id:
    scanf("%s", ptr->s.id);
    while (tmp->next != NULL)
    {
        if (!strcmp(tmp->next->s.id, ptr->s.id))
        {
            printf("���������룬id�ظ�\n");
            goto id;
        }
        if (strlen(ptr->s.id) > 10)
        {
            printf("id����\n");
            goto id;
        }
        tmp = tmp->next;
    }
    printf("������ɼ�����ѧ Ӣ�� ������ƣ���\n");
    scanf("%d %d %d", &ptr->s.math, &ptr->s.english, &ptr->s.Computer_Programming);
    ptr->s.total = ptr->s.math + ptr->s.english + ptr->s.Computer_Programming;
    ptr->s.ave = ptr->s.total / 3.0;
    ptr->next = h->next;
    h->next = ptr;
    system("pause");
}

void delete_inf(head h) // ɾ����Ϣ
{
    ptrtonode tmp = h;
    student stu;
    int flag = 0;
input:
    printf("������id��\n");
    char tmpid[11] = {0};

    scanf("%s", tmpid);
    if (strlen(tmpid) > 10) // ���id�����Ƿ�Ϸ�
    {
        printf("id����\n");
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
        printf("���޴���\n");
    }
    system("pause");
}

void edit_inf(head h) // �޸���Ϣ
{
    ptrtonode tmp = h;
    student* stu;
    int flag = 0;
input:
    printf("������id��\n");
    char tmpid[11] = {0};

    scanf("%s", tmpid);
    if (strlen(tmpid) > 10)
    {
        printf("id����\n");
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
        printf("���޴���\n");
    }
    printf("�������޸ĵ���Ŀ��0.���� 1.id 2.�ɼ���\n");
    int n;
    scanf("%d", &n);
    char tmpname[Mnamelen] = {0};
    switch (n)
    {
    case 0:
        printf("������������\n");

        scanf("%s", tmpname);
        strcpy(stu->name, tmpname);
        break;
    case 1:
        printf("������id:\n");
        scanf("%s", tmpid);
        strcpy(stu->id, tmpid);
        break;
    case 2:
        int k, grade;
    enter:
        printf("�������޸ĵĿ�Ŀ����1.��ѧ 2.Ӣ�� 3.������� 0.�˳���\n");
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

void get_inf(head h) // ������Ϣ
{
    printf("��������ҷ�ʽ����0.�������� 1.id���ң�\n");
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

void show_student(student A) // ��ʾѧ����Ϣ
{
    printf("����:%s\n", A.name);
    printf("id:%s\n", A.id);
    printf("�ɼ�:(��ѧ Ӣ�� �������)\n%d %d %d\n", A.math, A.english, A.Computer_Programming);
    printf("�ܷ�:%d\n", A.total);
    printf("����:%lf\n\n", A.ave);
}

void get_inf_with_name(head h) // ����������
{
    ptrtonode tmp = h;
    student stu;
    int flag = 0;
    printf("������������\n");
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
        printf("���޴���\n");
    }
    system("pause");
}

void get_inf_with_id(head h) // ��id����
{
    ptrtonode tmp = h;
    student stu;
    int flag = 0;
    printf("������id��\n");
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
        printf("���޴���\n");
    }
    system("pause");
}

void show_all_inf(head h) // ��ʾ������Ϣ
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

int show_amount(head h)//��ʾ��¼��ѧ������
{
    int ans = 0;
    while (h->next != NULL)
    {
        ans++;
        h = h->next;
    }
    printf("����%d��ѧ����¼��\n", ans);
    system("pause");
    return ans;
}

void show_ranking(head h)//��ѧ�����ɼ��Ӵ�С�������
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