#include "header.h"
typedef struct node
{
    int x;
    struct node *next;
    struct node *prev;
} node;
void PushBack(node **head, node **tale, int zn)
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
    int zn;
    node *Q;
    if ((*tale) == NULL)
        return err;
    zn = (*tale)->x;
    Q = (*tale);
    (*tale) = (*tale)->prev;
    free(Q);
    if ((*tale) == NULL)
        (*head) = NULL;
    return zn;
}
int PopFront(node **head, node **tale)
{
    int zn;
    node *Q;
    if ((*head) == NULL)
        return err;
    zn = (*head)->x;
    Q = (*head);
    (*head) = (*head)->next;
    free(Q);
    if ((*head) == NULL)
        (*tale) = NULL;
    return zn;
}
int problem1()
{
    node *masHead[100000], *masTale[100000], *ansHead, *ansTale;
    int fminus = false,del,flag,i;
    char c,s[10000];
    printf("Enter big integer in 10 number system\n");
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
    scanf ("%s",s);
    del = stod(s);
    if (del < 2 || del > 10 || del==err)
    {
        printf("Invalid data\n");
        return 0;
    }
    flag = true;
    i = 0;
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
