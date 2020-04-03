#include "header.h"
typedef struct node
{
    int x;
    struct node *left;
    struct node *right;
} node;
int ans[1000] = {0};
int PushNode(int x, node *P, int i)
{
    if (P == NULL)
    {
        return 1;
    }
    else if (P->x > x)
    {
        int res = PushNode(x, P->left, i+1);
        if (res == err)
            return err;
        if (res == 1)
        {
            node *Q = (node *)malloc(sizeof(node));
            Q->x = x;
            Q->left = Q->right = NULL;
            P->left = Q;
            ans[i+1]++;
        }
        return res + 1;
    }
    else if (P->x < x)
    {
        int res = PushNode(x, P->right, i+1);
        if (res == err)
            return err;
        if (res == 1)
        {
            node *Q = (node *)malloc(sizeof(node));
            Q->x = x;
            Q->left = Q->right = NULL;
            P->right = Q;
            ans[i+1]++;
        }
        return res + 1;
    }
    else
        return err;
}
int problem2()
{
    char s[10000];
    int i;
    node *root = NULL;// = (node *)malloc(sizeof(node));
    // root->left = NULL;
    // root->right = NULL;
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("The file was not opened");
        return 0;
    }
    while (true)
    {
        fscanf(fp, "%s", s);
        if (s[0] == ' ')
            break;
        int k = stod(s);
        if (k == err)
        {
            printf("Invalid data in file");
            return 0;
        }
        int res = PushNode(k, root, 0);
        if (res == err)
        {
            printf("Dublicate element");
            return 0;
        }
        else
        if (res==1)
        {
            root = (node *)malloc(sizeof(node));
            root->x = k;
            root->left = NULL;
            root->right = NULL;
            ans[0] = 1;
        }
        
        s[0] = ' ';
    }

    i = 0;
    while (ans[i] != 0)
    {
        printf("Level %d has %d nodes\n", i, ans[i]);
        i++;
    }
    //LeftOrder(root);
    fclose(fp);
}