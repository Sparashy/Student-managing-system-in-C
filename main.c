#include "management.h"
void show_menu() // 菜单
{
    printf("------------------------------------\n");
    printf("          1. 显示所有信息\n");
    printf("          2. 导入学生信息\n");
    printf("          3. 删除学生信息\n");
    printf("          4. 查询学生信息\n");
    printf("          5. 修改学生信息\n");
    printf("          6. 查看录入数量\n");
    printf("          7. 查看成绩排名\n");
    printf("          0. 退出\n");
    printf("------------------------------------\n");
}
head list; // 链表头
FILE *fa;  // 文件指针
FILE *fr;
FILE *fw;
void initialize()//初始化并读取数据
{
    fa = fopen("data.txt", "a");
    fr = fopen("data.txt", "r");
    list = (head)malloc(sizeof(node)); // 创建表头
    list->next = NULL;

    student tmp;
    while (fread(&tmp, sizeof(student), 1, fr)) // 读取文件并创建链表
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

void free_all(head h) // 释放内存
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
void clear_file()//储存前清空文件
{
    fw = fopen("data.txt", "w");

    fclose(fw);
}
void save(head h)//保存数据到文件
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
int main() // 主函数
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