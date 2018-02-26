#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Tree{
    int data;
    struct Tree *left;
    struct Tree *right;
};
//这里的left,right相当于next,即指向下一个

static int count;

void insert(struct Tree ** tree, int val)
{
    if ((*tree) == NULL){
        struct Tree *now = (struct Tree*)malloc(sizeof(struct Tree));
        now->left = now->right = NULL;
        now->data = val;
        *tree = now;
        return ;
    }
    if (val < (*tree)->data){
        insert(&(*tree)->left, val);
    }
    else {
        insert(&(*tree)->right, val);
    }
}

void deltree(struct Tree * tree)
{
    if (tree != NULL){
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

//先序 根，左，右
void print_preorder(struct Tree * tree)
{
    if (tree != NULL){
        printf("%d\n", tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }
}

//中序 左，根，右
void print_inorder(struct Tree * tree)
{
    if (tree != NULL){
        print_inorder(tree->left);
        printf("%d\n", tree->data);
        print_inorder(tree->right);
    }
}

//后序 左，右，根
void print_postorder(struct Tree * tree)
{
    if (tree != NULL){
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n", tree->data);
    }
}

//叶子节点的个数
int leafcount(struct Tree * tree)
{
    if (tree != NULL){
        if (tree->left == NULL && tree->right == NULL){
            count++;
        }
        leafcount(tree->left);
        leafcount(tree->right);
    }
    return count;
}

int treedeep(struct Tree * tree)
{
    int deep=0;
    if (tree != NULL){
        int leftdeep = treedeep(tree->left);
        int rightdeep = treedeep(tree->right);
        if (leftdeep >= rightdeep) deep = leftdeep+1;
        else deep = rightdeep+1;
    }
    return deep;
}

int a[10]={0,9,4,15,6,12,17,2};

int main(int argc, char *argv[])
{
    struct Tree * tree_one;
    tree_one = NULL;

    for (int i=1; i<=7; i++){
        //printf("开始\n");
        insert(&tree_one, a[i]);
    }

    printf("前序输出是\n");
    print_preorder(tree_one);
    printf("中序输出是\n");
    print_inorder(tree_one);
    printf("后序输出是\n");
    print_postorder(tree_one);

    count=0;
    leafcount(tree_one);
    printf("该树的叶子节点个数是%d\n", count);
    printf("该树的深度是%d\n", treedeep(tree_one));

    deltree(tree_one);

    return 0;
}

//参考自https://www.cnblogs.com/landpack/p/4783120.html
