#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*结构体指针*/
struct list{
    int id;  /*每个元素的标识*/
    char data[20]; /* 链表的元素*/ 
    struct list *next;  /* 指向下一个链表的指针*/
}list_head;//创建一个基地址，头部，next为空，当前不为空.

/* 定义链表的头部,静态 */
//static struct list *list_head = NULL;

static int list_id = 0;

/*添加元素*/
static void list_add(struct list **head, struct list *list)
{
    struct list *temp;

    /*刚开始为空，加入头部元素*/
    if (*head == NULL)
    {
        *head = list;
        (*head)->next = NULL;
    }
    else{
        temp = *head;
        while(temp != NULL)
        {
            if (temp->next == NULL)
            {
                temp->next = list;
                temp->next->next = NULL;
            }
            temp = temp->next;
        }
    }
}

static void list_print(struct list **head)
{
    struct list *temp;
    temp = *head;
    printf("list information is \n");
    while (temp != NULL)
    {
        printf("\tlist%d: %s\n", temp->id, temp->data);
        temp = temp->next;
    }
}


/* 删除元素，先看是不是头部元素，不是就一直往下找去*/
static int list_del(struct list **head, int id)
{
    struct list *temp;
    temp = *head;
    if (temp == NULL)
    {
        printf("link is empty!");
        return -1;
    }
    else{
        /* 判断是否是头部的元素*/
        if (id == temp->id)
        {
            *head = temp->next;
            return 0;
        }
        else{
            while(temp->next != NULL)
            {
                if (id == temp->next->id)
                {
                    temp->next = temp->next->next;
                    return 0;
                }
                temp = temp->next;
            }
            return -1;
        }
    }
    return -1;
}

/*修改元素*/
static int list_change(struct list **head, int id, char *content)
{
    struct list *temp;
    temp = *head;

    while(temp != NULL)
    {
        if (id == temp->id)
        {
            strcpy(temp->data, content);
            return 0;
        }
        temp = temp->next;
    }
    return -1;
}
            

int main(int argc, char *argv[])
{
    /*新建链表 其实相当于数组，仅仅是用来暂时存储数据,链表是list_head*/
    struct list *lists = NULL;

    /*相当于给数组分配大小*/
    lists = malloc(sizeof(struct list) * 10);
    if (lists == NULL)
    {
        printf("malloc error!\n");
        return -1;
    }

    for (int i=0; i<10; i++)
    {
        lists[i].id = list_id++;
        /*把字符串写入链表*/
        sprintf(lists[i].data, "data is --%d", i);
        list_add(&list_head, &lists[i]);
    }

    list_print(&list_head);
    
    list_del(&list_head, 0);
    list_del(&list_head, 3);
    list_del(&list_head, 7);
    list_change(&list_head, 4, "change");

    list_print(&list_head);

    return 0;
}
