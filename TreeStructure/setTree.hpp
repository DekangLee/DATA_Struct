#ifndef _SETTREEH_
#define _SETTREEH_
template <class E>
struct setTreeNode
{
    E element;
    setTreeNode<E> *parent; // 父节点指针
    setTreeNode(const E &theElement = E(), setTreeNode<E> *theParent = nullptr)
    {
        this->element = theElement;
        this->parent = theParent;
    }
};
template <class E>
class setTree
{
public:
    setTree()
    {
        this->root = nullptr;
        this->treeSize = 0;
    }
    postOrder(void (*theVisit)(setTreeNode<E> *))
    {
    }

private:
    setTreeNode<T> *root;
    int treeSize;                             // 树的节点个数
    static void (*visit)(setTreeNode<E> *);   // 声明访问函数指针
    static void preOrder(setTreeNode<E> *t);  // 二叉树前序遍历
    static void inOrder(setTreeNode<E> *t);   // 二叉树中序遍历
    static void postOrder(setTreeNode<E> *t); // 二叉树后序遍历
    static void dispose(setTreeNode<E> *t)    // 析构函数调用
    {
        delete t;
    }
};
template <class E>
void (*setTree<E>::visit)(setTreeNode<E> *) = nullptr;
template <class E>
void setTree<E>::preOrder(setTreeNode<E> *t)
{
    // if (t != nullptr)
    // {
    //     setTree<E>::visit(t);
    //     preOrder(t->)
    // }
}
#endif