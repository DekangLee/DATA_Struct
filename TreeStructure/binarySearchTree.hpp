#ifndef _BINARYSEARCHTREEH_
#define _BINARYSEARCHTREEH_
#include "linkedBinaryTree.hpp"
template <class K, class E>
class binarySearchTree : public linkedBinaryTree<pair<K, E>>
{

public:
    typedef pair<K, E> T;

    binarySearchTree()
    {
        this->root = nullptr;
        this->treeSize = 0;
    }
    ~binarySearchTree();
    // 二叉搜索树的查找
    T *find(const K &theKey) const;
    // 二叉搜索树的插入
    void insert(const pair<K, E> &thePair);
    void postOrder(void (*func)(binaryTreeNode<pair<K, E>> *))
    {
        visit = func;
        postOrder(this->root);
    }
    void inOrder(void (*func)(binaryTreeNode<pair<K, E>> *))
    {
        visit = func;
        inOrder(this->root);
    }
    void preOrder(void (*func)(binaryTreeNode<pair<K, E>> *))
    {
        visit = func;
        preOrder(this->root);
    }
    void erase(const K &theKey);
    int size() const
    {
        return this->treeSize;
    }
    int height(binaryTreeNode<pair<K, E>> *theNode);
    int height()
    {
        return this->height(this->root);
    }

private:
    binaryTreeNode<T> *root;
    int treeSize;
    static void (*visit)(binaryTreeNode<pair<K, E>> *);   // 声明访问函数指针
    static void preOrder(binaryTreeNode<pair<K, E>> *t);  // 二叉树前序遍历
    static void inOrder(binaryTreeNode<pair<K, E>> *t);   // 二叉树中序遍历
    static void postOrder(binaryTreeNode<pair<K, E>> *t); // 二叉树后序遍历
    static void dispose(binaryTreeNode<pair<K, E>> *t)    // 析构函数调用
    {
        delete t;
    }
};
template <class K, class E>
void (*binarySearchTree<K, E>::visit)(binaryTreeNode<pair<K, E>> *) = nullptr;
template <class K, class E>
binarySearchTree<K, E>::~binarySearchTree()
{
    this->postOrder(dispose);
    this->root = nullptr;
}
// 返回值为匹配数对的指针
template <class K, class E>
pair<K, E> *binarySearchTree<K, E>::find(const K &theKey) const
{
    // 如果没有匹配输对返回空指针
    // 重根节点开始搜索，寻找关键字为theKey的第一个元素
    binaryTreeNode<pair<K, E>> *p = this->root;
    while (p != nullptr)
    {
        // 检查元素p->element
        if (theKey < p->element.first)
            p = p->leftChild;
        else if (theKey > p->element.first)
            p = p->rightChild;
        else
            return &p->element;
    }
    return nullptr;
}
// 插入thePair,如果存在与其关键字相同的数对则覆盖之
template <class K, class E>
void binarySearchTree<K, E>::insert(const pair<K, E> &thePair)
{
    // 寻找插入位置
    binaryTreeNode<pair<K, E>> *p = this->root;
    binaryTreeNode<pair<K, E>> *pp = nullptr; // pp记录p的父节点
    while (p != nullptr)
    {
        // 检查元素p->element
        pp = p;
        // 将p移到他的一个子节点
        if (thePair.first < p->element.first)
            p = p->leftChild;
        else if (thePair.first > p->element.first)
            p = p->rightChild;
        else
        {
            // 覆盖旧值
            p->element.second = thePair.second;
            return;
        }
    }
    // 为thePair建立一个节点，然后与pp连接
    binaryTreeNode<pair<K, E>> *newNode = new binaryTreeNode<pair<K, E>>(thePair);
    if (root != nullptr)
    {
        if (thePair.first < pp->element.first)
            pp->leftChild = newNode;
        else
            pp->rightChild = newNode;
    }
    else
        this->root = newNode;
    this->treeSize++;
}
template <class K, class E>
void binarySearchTree<K, E>::preOrder(binaryTreeNode<pair<K, E>> *t)
{
    if (t != nullptr)
    {
        binarySearchTree<K, E>::visit(t);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}
template <class K, class E>
void binarySearchTree<K, E>::inOrder(binaryTreeNode<pair<K, E>> *t)
{
    if (t != nullptr)
    {
        inOrder(t->leftChild);
        binarySearchTree<K, E>::visit(t);
        inOrder(t->rightChild);
    }
}
template <class K, class E>
void binarySearchTree<K, E>::postOrder(binaryTreeNode<pair<K, E>> *t)
{
    if (t == nullptr)
        return;
    binarySearchTree<K, E>::postOrder(t->leftChild);
    binarySearchTree<K, E>::postOrder(t->rightChild);
    binarySearchTree<K, E>::visit(t);
}
// 删除关键字为theKey关键字的节点
template <class K, class E>
void binarySearchTree<K, E>::erase(const K &theKey)
{
    // 查找关键字为theKey的节点；
    binaryTreeNode<pair<K, E>> *p = root,
                               *pp = nullptr; // pp为p的父节点
    while (p != nullptr && p->element.first != theKey)
    {
        pp = p;
        if (p->element.first > theKey)
            p = p->leftChild;
        else if (p->element.first < theKey)
            p = p->rightChild;
    }
    // 不存在关键字为theKey的节点
    if (p == nullptr)
        return;
    // 如果p不为空，则将p删除，并且将该位置放置右子树的最小节点，或者左子树的最大节点
    // 以右子树的最小节点为例
    binaryTreeNode<pair<K, E>> *lChild = p->leftChild;
    binaryTreeNode<pair<K, E>> *rChild = p->rightChild;
    if (rChild == nullptr && lChild == nullptr) // 第一种情况，该节点为叶子结点
    {
        cout << "----------------" << endl;
        if (p == this->root)
        {
            // 说明该节点为根节点
            this->root = nullptr;
        }
        else if (pp->leftChild == p)
            pp->leftChild = nullptr;
        else if (pp->rightChild == p)
            pp->rightChild = nullptr; 
    }
    else if (rChild != nullptr && lChild == nullptr) // 第二种情况 ，该节点存在右子树，但不存在左子树
    {
        if (p == this->root)
        {
            this->root = rChild;
        }
        else if (pp->leftChild == p)
            pp->leftChild = rChild;
        else if (pp->rightChild == p)
            pp->rightChild = rChild;
    }
    else if (rChild == nullptr && lChild != nullptr) // 第三种情况， 该节点存在左子树，但不存在右子树
    {
        if (p == this->root)
            this->root = lChild;
        else if (pp->leftChild == p)
            pp->leftChild = lChild;
        else
            pp->rightChild = lChild;
    }
    else if (rChild != nullptr && lChild != nullptr) // 第四种情况，该节点左子树与右子树均不为空
    {
        // 查找右子树最小的节点
        binaryTreeNode<pair<K, E>> *pRChild = nullptr;
        binaryTreeNode<pair<K, E>> *rrChild = rChild;
        while (rrChild->leftChild != nullptr)
        {
            pRChild = rrChild;
            rrChild = rrChild->leftChild;
        }
        // rrchild即为需要查找的节点，将其与pp连接
        if (p == this->root)
            this->root = rrChild;
        else if (pp->leftChild == p)
            pp->leftChild = rrChild;
        else
            pp->rightChild = rrChild;
        if (rChild->leftChild != nullptr)
        {
            pRChild->leftChild = nullptr;
            rrChild->rightChild = rChild;
        }
        rrChild->leftChild = lChild;
    }
    delete p;
    this->treeSize--;
}
template <class K, class E>
int binarySearchTree<K, E>::height(binaryTreeNode<pair<K, E>> *theNode)
{
    if (theNode == nullptr)
        return 0;
    int l = 0;
    int r = 0;
    l = height(theNode->leftChild);
    r = height(theNode->rightChild);
    l++;
    r++;
    return (r > l ? r : l);
}
#endif