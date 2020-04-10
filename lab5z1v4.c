#include "header.h"
typedef struct node
{
    int x;
    struct node *next;
    struct node *prev;
} node;
void Pushack(node **head, node **tale, int zn)
{
    node *Q = (node *)malloc(sizeof(node));
    Q->x = zn;
    if ((*head) == NULL)
    {
        Q->next = Q->prev = NULL;
        (*tale) = Q;
        (*head) = Q;
    }
    else
    {
        Q->prev = (*tale);
        Q->next = NULL;
        (*tale)->next = Q;
        (*tale) = Q;
    }
}
int PopBack(node **head, node **tale)
{
    if ((*tale) == NULL)
        return err;
    int zn = (*tale)->x;
    node *Q = (*tale);
    (*tale) = (*tale)->prev;
    free(Q);
    if ((*tale) == NULL)
        (*head) = NULL;
    return zn;
}
// void PushFront(node *head, node *tale, int zn)
// {
//     node *Q = (node *)malloc(sizeof(node));
//     Q->x = zn;
//     if (tale == NULL)
//     {
//         Q->next = Q->prev = NULL;
//         tale = Q;
//         head = Q;
//     }
//     else
//     {
//         Q->next = head;
// Q->prev = NULL;
//         head->prev = Q;
//         head = Q;
//     }
// }
int PopFront(node **head, node **tale)
{
    if ((*head) == NULL)
        return err;
    int zn = (*head)->x;
    node *Q = (*head);
    (*head) = (*head)->next;
    free(Q);
    if ((*head) == NULL)
        (*tale) = NULL;
    return zn;
}
int problem1()
{
    node *masHead[100000], *masTale[100000], *ansHead, *ansTale;
    int fminus = false;
    printf("Enter big integer in 10 number system\n");
    char c;
    scanf("%c", &c);
    if (c == '-')
    {
        fminus = true;
        c = '0';
    }
    while (c != '\r' && c != '\n')
    {
        if (!(c >= '0' && c <= '9'))
        {
            printf("Invalid data\n");
            return 0;
        }
        PushBack(&masHead[0], &masTale[0], c - '0');
        scanf("%c", &c);
    }
    printf("Enter number system\n");
    char s[10000];
    scanf ("%s",s);
    int del = stod(s);
    if (del < 2 || del > 10 || del==err)
    {
        printf("Invalid data\n");
        return 0;
    }
    int flag = true;
    int i = 0;
    while (flag)
    {
        int k = 0;
        flag = false;
        while (masHead[i] != NULL)
        {
            int temp = PopFront(&masHead[i], &masTale[i]);
            if (temp == err)
            {
                printf("Popped empty\n");
                return 0;
            }
            k = k * 10 + temp;
            if (k / del != 0)
                flag = true;
            if (flag)
                PushBack(&masHead[i + 1], &masTale[i + 1], k / del);

            k %= del;
        }
        PushBack(&ansHead, &ansTale, k);
        i++;
    }
    if (fminus) printf ("-");
    while (ansHead != NULL)
        printf("%d", PopBack(&ansHead, &ansTale));
    return 0;
}
