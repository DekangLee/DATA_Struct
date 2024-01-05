#ifndef _MAXHBLTH_
#define _MAXHBLTH_
#include <iostream>
using namespace std;
template <class T>
struct binaryTreeNode
{
    pair<int, T> element;         // 第一个元素为该节点的s值，第二个为element值
    binaryTreeNode *parent;       // 父节点指针
    binaryTreeNode<T> *leftChild, // 左子树指针
        *rightChild;              // 右子树指针
    // binaryTreeNode 的默认构造函数
    binaryTreeNode()
    {
        this->parent = this->leftChild = rightChild = nullptr;
    }
    // binaryTreeNode 的有参构造函数
    binaryTreeNode(const pair<int, T> &theElement)
    {
        this->element.first = theElement.first;
        this->element.second = theElement.second;
        this->parent = this->leftChild = this->rightChild = nullptr;
    }
    // binaryTreeNode 的拷贝构造函数
    binaryTreeNode(const binaryTreeNode<T> &theNode)
    {
        this->element.first = theNode.element.first;
        this->element.second = theNode.element.second;
        this->leftChild = theNode.leftChild;
        this->rightChild = theNode.rightChild;
        this->parent = theNode.parent;
    }
};
template <class T>
class maxHblt
{
public:
    maxHblt(const T &theElement = T());
    ~maxHblt();
    // 该高度优先左高树是否为空
    bool empty() const
    {
        return this->treeSize == 0;
    }
    // 返回左高树的节点数
    int size() const
    {
        return this->treeSize;
    }
    // 返回左高树的根节点的element的值
    T &top() const
    {
        return this->root->element.second;
    }
    void push(const T &theElement);
    void pop();
    void meld(maxHblt<T> &hblt);
    // 成员函数前序遍历
    void preOrder(void (*theVisit)(binaryTreeNode<T> *))
    {
        visit = theVisit;
        preOrder(this->root);
    }
    // 成员函数中序遍历
    void inOrder(void (*theVisit)(binaryTreeNode<T> *))
    {
        visit = theVisit;
        inOrder(this->root);
    }
    // 成员函数后续遍历
    void postOrder(void (*theVisit)(binaryTreeNode<T> *))
    {
        visit = theVisit;
        postOrder(this->root);
    }

private:
    binaryTreeNode<T> *root; // 指向树的根节点
    int treeSize;
    // 合并两颗左高树binaryTreeNode<T> *&x为指针类型的引用
    void meld(binaryTreeNode<T> *&x, binaryTreeNode<T> *&y);
    // 后续遍历删除节点
    void erase(binaryTreeNode<T> *theNode);
    static void (*visit)(binaryTreeNode<T> *);   // 声明访问函数指针
    static void preOrder(binaryTreeNode<T> *t);  // 二叉树前序遍历
    static void inOrder(binaryTreeNode<T> *t);   // 二叉树中序遍历
    static void postOrder(binaryTreeNode<T> *t); // 二叉树后序遍历
    static void dispose(binaryTreeNode<T> *t)    // 析构函数调用
    {
        delete t;
    }
};
template <class T>
void (*maxHblt<T>::visit)(binaryTreeNode<T> *) = nullptr;
template <class T>
// maxHblt的静态前序遍历实现
void maxHblt<T>::preOrder(binaryTreeNode<T> *t)
{
    if (t == nullptr)
        return;
    visit(t);
    preOrder(t->leftChild);
    preOrder(t->rightChild);
}
template <class T>
void maxHblt<T>::inOrder(binaryTreeNode<T> *t)
{
    if (t == nullptr)
        return;
    inOrder(t->leftChild);
    visit(t);
    inOrder(t->rightChild);
}
template <class T>
void maxHblt<T>::postOrder(binaryTreeNode<T> *t)
{
    if (t == nullptr)
        return;
    postOrder(t->leftChild);
    postOrder(t->rightChild);
    visit(t);
}
template <class T>
void maxHblt<T>::meld(binaryTreeNode<T> *&x, binaryTreeNode<T> *&y)
{
    // 合并分别以*x和*y为根的两颗左高树
    // 合并后的左高树一x为根，返回x的指针
    if (y == nullptr) // y为空
        return;
    if (x == nullptr) // x为空
    {
        x = y;
        return;
    }
    // 始终保持x的根节点的值大于y根节点的值，必要时交换x，y的值
    if (x->element.second < y->element.second)
        swap(x, y);
    meld(x->rightChild, y);
    // 如有需要应该交换x的子树，然后设置x->element.first的值(即s值)
    if (x->leftChild == nullptr)
    {
        // 左子树为空，交换子树
        x->leftChild = x->rightChild;
        x->rightChild = nullptr;
        x->element.first = 1;
    }
    else
    {
        // 只有左子树的s值较小时才需要交换
        if (x->leftChild->element.first < x->rightChild->element.first)
            swap(x->leftChild, x->rightChild);
        x->element.first = x->rightChild->element.first + 1;
    }
}
template <class T>
maxHblt<T>::maxHblt(const T &theElement)
{
    // 函数实现不需要再加默认参数
    this->root = new binaryTreeNode<T>(make_pair(1, theElement));
    this->treeSize++;
}
template <class T>
maxHblt<T>::~maxHblt()
{
    if (this->root != nullptr)
    {
        this->erase(this->root);
        this->root = nullptr;
    }
}
template <class T>
void maxHblt<T>::pop()
{
    binaryTreeNode<T> *leftChild = this->root->leftChild;
    binaryTreeNode<T> *rightChild = this->root->rightChild;
    delete this->root;
    // rightChild指针的内容始终比leftChild大，由meld函数原型可知
    this->meld(rightChild, leftChild);
    this->root = rightChild;

    this->treeSize--;
}
template <class T>
void maxHblt<T>::push(const T &theElement)
{
    maxHblt<T> *y = new maxHblt<T>(theElement);
    this->meld(this->root, y->root);
    this->treeSize++;
}
// 合并两颗左高树
template <class T>
void maxHblt<T>::meld(maxHblt<T> &theHblt)
{
    this->meld(this->root, theHblt.root);
    this->treeSize += theHblt.treeSize;
}
template <class T>
void maxHblt<T>::erase(binaryTreeNode<T> *theNode)
{
    if (theNode == nullptr)
        return;
    erase(theNode->leftChild);
    erase(theNode->rightChild);
    delete theNode;
}
#endif