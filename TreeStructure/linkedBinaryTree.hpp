#ifndef _LINKEDBINARYTREEH_
#define _LINKEDBINARYTREEH_
#include <iostream>
#include <queue>
#include <stack>
#include "binaryTree.hpp"
using namespace std;
template <class T>
struct binaryTreeNode
{
    T element;
    binaryTreeNode<T> *leftChild, // 左子树
        *rightChild;              // 右子树
    binaryTreeNode()
    {
        this->leftChild = rightChild = nullptr;
    }
    binaryTreeNode(const T &theElement)
    {
        this->element = theElement;
        this->leftChild = this->rightChild = nullptr;
    }
    binaryTreeNode(const T &theElement, binaryTreeNode *theLeftChild, binaryTreeNode *theRightChild)
    {
        this->element = theElement;
        this->leftChild = theLeftChild;
        this->rightChild = theRightChild;
    }
};
// 前序遍历迭代器
template <class E>
class preIterator
{
public:
    preIterator(binaryTreeNode<E> *theNode)
    {
        this->nodeStack.push(theNode);
    }
    preIterator(){};
    preIterator(const preIterator<E> &it)
    {
        this->nodeStack = it.nodeStack;
    }
    E &operator*()
    {
        binaryTreeNode<E> *node = this->nodeStack.top();
        return node->element;
    }
    preIterator<E> &operator++();   // 后置递增
    preIterator<E> operator++(int); // 前置递增
    bool isEnd()
    {
        return this->nodeStack.empty();
    }

private:
    stack<binaryTreeNode<E> *> nodeStack;
};
// 二叉树后序遍历迭代器
template <class E>
struct postNode
{
    binaryTreeNode<E> *node;
    bool root;
    postNode(binaryTreeNode<E> *theNode = nullptr, bool theRoot = false)
    {
        this->node = theNode;
        this->root = theRoot;
    }
};
template <class E>
class postIterator
{
public:
    postIterator(binaryTreeNode<E> *theNode)
    {
        this->nodeStack.push(postNode<E>(theNode, true));
    }
    postIterator(){};
    postIterator(const postIterator<E> &it)
    {
        this->nodeStack = it.nodeStack;
    }
    E &operator*()
    {
        binaryTreeNode<E> *node = this->nodeStack.top();
        return node->element;
    }
    postIterator<E> &operator++();   // 后置递增
    postIterator<E> operator++(int); // 前置递增
    bool isEnd()
    {
        return this->nodeStack.empty();
    }

private:
    stack<postNode<E>> nodeStack;
};
template <class E>
class linkedBinaryTree : public binaryTree<binaryTreeNode<E>>
{
public:
    linkedBinaryTree()
    {
        this->root = nullptr;
        this->treeSize = 0;
    }
    linkedBinaryTree(const linkedBinaryTree<E> &tree);
    ~linkedBinaryTree()
    {
        this->erase();
    }
    bool empty() const
    {
        return this->treeSize == 0;
    }
    void preOrder(void (*theVisit)(binaryTreeNode<E> *))
    {
        visit = theVisit;
        preOrder(this->root);
    }
    void inOrder(void (*theVisit)(binaryTreeNode<E> *))
    {
        visit = theVisit;
        inOrder(this->root);
    }
    void postOrder(void (*theVisit)(binaryTreeNode<E> *))
    {
        visit = theVisit;
        postOrder(this->root);
    }
    void levelOrder(void (*theVisit)(binaryTreeNode<E> *));
    void insert(const E &theElement, int n);
    // void insertRight(const E &theElement, int n);
    void erase()
    {
        postOrder(dispose);
        this->root = nullptr;
        this->treeSize = 0;
    }
    int size() const
    {
        return this->treeSize;
    }
    bool compare(const linkedBinaryTree<E> &tree) const;
    int height(binaryTreeNode<E> *t) const;
    int height() const
    {
        return height(this->root);
    }
    typedef preIterator<E> preIterator;
    preIterator begin()
    {
        return preIterator(this->root);
    }

private:
    binaryTreeNode<E> *root;                     // 指向树的根节点
    int treeSize;                                // 树的节点个数
    static void (*visit)(binaryTreeNode<E> *);   // 声明访问函数指针
    static void preOrder(binaryTreeNode<E> *t);  // 二叉树前序遍历
    static void inOrder(binaryTreeNode<E> *t);   // 二叉树中序遍历
    static void postOrder(binaryTreeNode<E> *t); // 二叉树后序遍历
    static void dispose(binaryTreeNode<E> *t)    // 析构函数调用
    {
        delete t;
    }
};
template <class E>
linkedBinaryTree<E>::linkedBinaryTree(const linkedBinaryTree<E> &tree)
{
    this->treeSize = tree.treeSize;
    binaryTreeNode<E> *sourceNode = tree.root;
    if (sourceNode == nullptr)
    {
        // 源二叉树为空直接返回
        this->root = nullptr;
        return;
    }
    this->root = new binaryTreeNode<E>(sourceNode->element);

    binaryTreeNode<E> *targetNode = this->root;

    queue<binaryTreeNode<E> *> sourceQ;
    queue<binaryTreeNode<E> *> targetQ;
    // 根据层次遍历来拷贝构造另一个二叉树
    while (sourceNode != nullptr)
    {
        if (sourceNode->leftChild != nullptr)
        {
            targetNode->leftChild = new binaryTreeNode<E>(sourceNode->leftChild->element);
            sourceQ.push(sourceNode->leftChild);
            targetQ.push(targetNode->leftChild);
        }
        if (sourceNode->rightChild != nullptr)
        {
            targetNode->rightChild = new binaryTreeNode<E>(sourceNode->rightChild->element);
            sourceQ.push(sourceNode->rightChild);
            targetQ.push(targetNode->rightChild);
        }
        if (sourceQ.empty())
            break;
        sourceNode = sourceQ.front();
        targetNode = targetQ.front();
        sourceQ.pop();
        targetQ.pop();
    }
}
template <class E>
void linkedBinaryTree<E>::preOrder(binaryTreeNode<E> *t)
{
    // 前序遍历
    if (t != nullptr)
    {
        linkedBinaryTree<E>::visit(t);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}
template <class E>
void (*linkedBinaryTree<E>::visit)(binaryTreeNode<E> *) = nullptr;
template <class E>
void linkedBinaryTree<E>::inOrder(binaryTreeNode<E> *t)
{
    // 中序遍历
    if (t != nullptr)
    {
        inOrder(t->leftChild);
        linkedBinaryTree<E>::visit(t);
        inOrder(t->rightChild);
    }
}
template <class E>
void linkedBinaryTree<E>::postOrder(binaryTreeNode<E> *t)
{
    // 后序遍历
    if (t != nullptr)
    {
        postOrder(t->leftChild);
        postOrder(t->rightChild);
        linkedBinaryTree<E>::visit(t);
    }
}
template <class E>
void linkedBinaryTree<E>::levelOrder(void (*theVisit)(binaryTreeNode<E> *))
{

    queue<binaryTreeNode<E> *> treeQueue;
    binaryTreeNode<E> *t = this->root;
    while (t != nullptr)
    {
        theVisit(t);
        // 将t的子节点插入队列
        if (t->leftChild != nullptr)
            treeQueue.push(t->leftChild);
        if (t->rightChild != nullptr)
            treeQueue.push(t->rightChild);
        if (treeQueue.empty()) // 若队列为空则访问完毕
            return;
        t = treeQueue.front();
        treeQueue.pop();
    }
}
template <class E>
void linkedBinaryTree<E>::insert(const E &theElement, int n)
{
    if (n == 1)
    {
        if (this->root == nullptr)
        {
            this->root = new binaryTreeNode<E>(theElement);
            this->treeSize++;
        }
        else
            this->root->element = theElement;
    }
    else
    {
        queue<binaryTreeNode<E> *> treeQueue;
        binaryTreeNode<E> *t = this->root;
        std::stack<int> numStack;
        int parentNum = n / 2;
        while (parentNum != 1)
        {
            numStack.push(parentNum);
            parentNum /= 2;
        }
        while (!numStack.empty())
        {
            int num = numStack.top();
            // cout << "num = " << num << endl;
            if (num % 2 == 0)
            {
                t = t->leftChild;
                if (t == nullptr)
                {
                    cout << "存在空父节点！插入失败" << endl;
                    return;
                }
            }
            else
            {
                t = t->rightChild;
                if (t == nullptr)
                {
                    cout << "存在空父节点！插入失败" << endl;
                    return;
                }
            }
            numStack.pop();
        }
        // if (t == nullptr)
        //     cout << "t==nullptr" << endl;
        binaryTreeNode<E> *newNode = new binaryTreeNode<E>(theElement);
        if (n % 2 == 0)
            t->leftChild = newNode;
        else
            t->rightChild = newNode;
        this->treeSize++;
    }
}
template <class E>
bool linkedBinaryTree<E>::compare(const linkedBinaryTree<E> &tree) const
{
    if (this->treeSize != tree.treeSize)
        return false;
    binaryTreeNode<E> *sourceNode = this->root;
    binaryTreeNode<E> *targetNode = tree.root;
    queue<binaryTreeNode<E> *> sourceQ;
    queue<binaryTreeNode<E> *> targetQ;
    while (sourceNode != nullptr)
    {
        if (sourceNode->element != targetNode->element)
            return false;
        if (sourceNode->leftChild != nullptr)
        {
            sourceQ.push(sourceNode->leftChild);
            targetQ.push(targetNode->leftChild);
        }
        if (sourceNode->rightChild != nullptr)
        {
            sourceQ.push(sourceNode->rightChild);
            targetQ.push(targetNode->rightChild);
        }
        if (sourceQ.empty())
            break;
        sourceNode = sourceQ.front();
        targetNode = targetQ.front();
        sourceQ.pop();
        targetQ.pop();
    }
    return true;
}
// 返回根为*t的二叉树高度
template <class E>
int linkedBinaryTree<E>::height(binaryTreeNode<E> *t) const
{
    if (t == nullptr)
        return 0;
    int hl = height(t->leftChild);  // 左树高
    int hr = height(t->rightChild); // 右树高
    if (hl > hr)
        return ++hl;
    else
        return ++hr;
}
template <class E>
preIterator<E> &preIterator<E>::operator++()
{
    binaryTreeNode<E> *node;
    if (this->nodeStack.empty())
        return *this;
    node = this->nodeStack.top();
    this->nodeStack.pop();
    if (node->rightChild != nullptr)
        this->nodeStack.push(node->rightChild);
    if (node->leftChild != nullptr)
        this->nodeStack.push(node->leftChild);

    return *this;
}
template <class E>
preIterator<E> preIterator<E>::operator++(int)
{
    preIterator<E> temp = *this;
    binaryTreeNode<E> *node;
    if (this->nodeStack.empty())
        return *this;
    node = this->nodeStack.top();
    this->nodeStack.pop();
    if (node->rightChild != nullptr)
        this->nodeStack.push(node->rightChild);
    if (node->leftChild != nullptr)
        this->nodeStack.push(node->leftChild);
    return temp;
}
template <class E>
postIterator<E> &postIterator<E>::operator++()
{
    postNode<E> node =this->nodeStack.top();
    
}
#endif