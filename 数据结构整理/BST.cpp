#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
typedef int ElemType;
typedef struct Node
{
    ElemType key;        //关键字
    struct Node *left;   //左孩子
    struct Node *right;  //右孩子
    struct Node *parent; //父节点
} Node, *PNode;

//插入
void Insert(PNode &root, ElemType key)
{
    //初始化b被插入结点
    PNode p=(PNode)malloc(sizeof(Node));
    p->key = key;
    p->left = NULL;
    p->right = NULL;
    p->parent = NULL;
    //空树
    if(root == NULL)
    {
        root = p;
        return;
    }
    //左孩子
    if(root->left == NULL && root->key > key)
    {
        p->parent = root;
        root->left = p;
        return;
    }
    //右孩子
    if(root->right == NULL && root->key < key)
    {
        p->parent = root;
        root->right = p;
        return;
    }

    //关键值小于此时的节点值，放在左树
    //准备改回迭代的，今晚没成功...
    if(key < root->key)
        Insert(root->left,key);
    else
        Insert(root->right,key);
}

//查找元素,找到返回关键字的结点指针，没找到返回NULL
PNode Search(PNode root, ElemType key)
{
    if(root == NULL || root->key == key)
        return root;

    if(key < root->key) //查找左子树
        return Search(root->left,key);
    else //查找右子树
        return Search(root->right,key);
}

//查找最小关键字,空树时返回NULL
PNode SearchMin(PNode root)
{
    if(root == NULL)
        return root;

    while(root->left != NULL)
        root = root->left;
    return root;
}

//查找最大关键字,空树时返回NULL
PNode SearchMax(PNode root)
{
    if(root == NULL)
        return root;

    while(root->right != NULL) //迭代
        root = root->right;
    return root;
}

//查找前驱
PNode SearchPredecessor(PNode x)
{
    if(x == NULL)  //空
        return x;

    //若存在左孩子，前驱是其左子树中最大的
    if(x->left != NULL)
        return SearchMax(x->left);

    PNode y = x->parent;
    while(y != NULL && x == y->left)
    {
        x = y;
        y = x->parent;
    }
    return y;
}

//查找后继
PNode SearchSuccessor(PNode x)
{
    if(x == NULL)  //空
        return x;

    //若存在右孩子，后继是其右子树中最小的
    if(x->right != NULL)
        return SearchMin(x->right);

    PNode y = x->parent;
    while(y != NULL && x == y->right)
    {
        x = y;
        y = x->parent;
    }
    return y;
}

int DeleteNode(PNode &root,ElemType key)
{
    PNode q;
    //查找到要删除的结点
    PNode p = Search(root, key);

    //没查到此关键字
    if(p == NULL)
        return 0;
    //一共有四种情况，该节点是叶子节点、只有左孩子、只有右孩子、左右孩子都有
    //叶子结点
    if(p->left == NULL && p->right == NULL)
    {
        //只有根节点
        if(p->parent == NULL)
        {
            free(p);
            root = NULL;
        }
        else
        {
            //删除的结点是左孩子
            if(p->parent->left == p)
                p->parent->left = NULL;
            else
                p->parent->right = NULL;
            free(p);
        }
    }

    //左孩子
    else if(p->left != NULL && p->right == NULL)
    {
        p->left->parent = p->parent;
        //如果删除是根结点
        if(p->parent == NULL)
            root = p->left;
        //父节点的左孩子
        else if(p->parent->left == p)
            p->parent->left = p->left;
        else
            p->parent->right = p->left;
        free(p);
    }
    //右孩子
    else if(p->right != NULL && p->left == NULL)
    {
        p->right->parent = p->parent;
        //如果删除是根结点
        if(p->parent == NULL)
            root = p->right;
        //是父节点的左孩子
        else if(p->parent->left == p)
            p->parent->left=p->right;
        else
            p->parent->right=p->right;
        free(p);
    }
    //左右孩子都有
    //该结点的后继结点肯定无左子树
    //删掉后继结点,后继结点的值代替该结点
    else
    {
        //找到要删除结点的后继
        q = SearchSuccessor(p);
        ElemType temp = q->key;    //暂存后继结点的值

        //删除后继结点
        DeleteNode(root, q->key);
        p->key = temp;
    }
    return 1;
}

//创建树
void Create(PNode& root, ElemType *keyArray, int length)
{
    for(int i = 0; i < length; i++)
        Insert(root, keyArray[i]);  //插入
}

int main()
{
    PNode root = NULL;
    ElemType nodeArray[11] = {15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};  //二叉数
    Create(root, nodeArray, 11);  //创建二叉搜索数

    cout<<"该节点的值"<<Search(root,15)->key<<endl;
    cout<<"min = "<<SearchMin(root)->key<<endl;  //最小值
    cout<<"max = "<<SearchMax(root)->key<<endl;  //最大值
    cout<<"前驱"<<SearchPredecessor(root->right->right)->key<<endl;  //前驱
    cout<<"后继"<<SearchSuccessor(root->left->right->right)->key<<endl;  //后继
    DeleteNode(root, 6);
    cout<<"该节点的值"<<Search(root,15)->key<<endl;
    cout<<"min = "<<SearchMin(root)->key<<endl;  //最小值
    cout<<"max = "<<SearchMax(root)->key<<endl;  //最大值
    cout<<"前驱"<<SearchPredecessor(root->left)->key<<endl;  //前驱
    cout<<"后继"<<SearchSuccessor(root->left->right->left)->key<<endl;  //后继

    return 0;
}
