#include "management.h"
void show_menu() // �˵�
{
    printf("------------------------------------\n");
    printf("          1. ��ʾ������Ϣ\n");
    printf("          2. ����ѧ����Ϣ\n");
    printf("          3. ɾ��ѧ����Ϣ\n");
    printf("          4. ��ѯѧ����Ϣ\n");
    printf("          5. �޸�ѧ����Ϣ\n");
    printf("          6. �鿴¼������\n");
    printf("          7. �鿴�ɼ�����\n");
    printf("          0. �˳�\n");
    printf("------------------------------------\n");
}
head list; // ����ͷ
FILE *fa;  // �ļ�ָ��
FILE *fr;
FILE *fw;
void initialize()//��ʼ������ȡ����
{
    fa = fopen("data.txt", "a");
    fr = fopen("data.txt", "r");
    list = (head)malloc(sizeof(node)); // ������ͷ
    list->next = NULL;

    student tmp;
    while (fread(&tmp, sizeof(student), 1, fr)) // ��ȡ�ļ�����������
    {
        ptrtonode ptr;
        ptr = (ptrtonode)malloc(sizeof(node));
        strcpy(ptr->s.name, tmp.name);
        strcpy(ptr->s.id, tmp.id);
        ptr->s.math = tmp.math;
        ptr->s.english = tmp.english;
        ptr->s.Computer_Programming = tmp.Computer_Programming;
        ptr->s.total = tmp.total;
        ptr->s.ave = tmp.ave;
        ptr->next = list->next;
        list->next = ptr;
    }
    fclose(fr);
}

void free_all(head h) // �ͷ��ڴ�
{
    ptrtonode ptr = h;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        free(h);
        h = ptr;
    }
    free(ptr);
}
void clear_file()//����ǰ����ļ�
{
    fw = fopen("data.txt", "w");

    fclose(fw);
}
void save(head h)//�������ݵ��ļ�
{
    ptrtonode tmp = h;
    clear_file();
    if (tmp->next == NULL)
        return;
    fseek(fa,0,SEEK_SET);
    while (tmp->next != NULL)
    {
        fwrite(&tmp->next->s, sizeof(student), 1, fa);
        tmp=tmp->next;
    }
    fclose(fa);
}
int main() // ������
{
    initialize();
    while (1)
    {
        show_menu();
        int flag = 0;
        scanf("%d", &flag);
        switch (flag)
        {
        case 1:
            show_all_inf(list);
            break;
        case 2:
            add_inf(list);
            break;
        case 3:
            delete_inf(list);
            break;
        case 4:
            get_inf(list);
            break;
        case 5:
            edit_inf(list);
            break;
        case 6:
            show_amount(list);
            break;
        case 7:
            show_ranking(list);
            break;
        case 0:
            save(list);
            free_all(list);
            return 1;
        default:
            break;
        }
    }
    return 0;
}