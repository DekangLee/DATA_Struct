#ifndef __AVLTREEH__
#define __AVLTREEH__
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
template <class K, class E>
struct AVLTreeNode
{
    K key;
    E element;
    int height;
    AVLTreeNode<K, E> *leftChild;
    AVLTreeNode<K, E> *rightChild;
    AVLTreeNode()
    {
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }
    AVLTreeNode(const pair<K, E> &value, AVLTreeNode *l, AVLTreeNode *r)
    {
        this->key = value.first;
        this->element = value.second;
        this->leftChild = l;
        this->rightChild = r;
    }
};
template <class K, class E>
class AVLTree
{
public:
    AVLTree()
    {
        this->treeSize = 0;
        this->root = nullptr;
    }
    ~AVLTree()
    {
        postOrder(depose);
        this->root = nullptr;
    }
    bool insert(const pair<K, E> &thePair)
    {
        AVLTreeNode<K, E> *node = insert(this->root, thePair);
        this->treeSize++;
        return node != nullptr;
    }
    AVLTreeNode<K, E> *find(const K &theKey) const;
    void erase(const K &theKey);
    void postOrder(void (*func)(AVLTreeNode<K, E> *))
    {
        AVLTree<K, E>::visit = func;
        postOrder(this->root);
    }
    void preOrder(void (*func)(AVLTreeNode<K, E> *))
    {
        AVLTree<K, E>::visit = func;
        preOrder(this->root);
    }
    void inOrder(void (*func)(AVLTreeNode<K, E> *))
    {
        AVLTree<K, E>::visit = func;
        inOrder(this->root);
    }
    int size()
    {
        return this->treeSize;
    }
    void levelOrder(void (*func)(AVLTreeNode<K, E> *));

private:
    AVLTreeNode<K, E> *leftLeftRotation(AVLTreeNode<K, E> *&k2);

    AVLTreeNode<K, E> *rightRightRotation(AVLTreeNode<K, E> *&k1);

    AVLTreeNode<K, E> *leftRightRotation(AVLTreeNode<K, E> *&k3);

    AVLTreeNode<K, E> *rightLeftRotation(AVLTreeNode<K, E> *&k1);

    int height(AVLTreeNode<K, E> *theNode)
    {
        if (theNode == nullptr)
            return 0;
        int l = height(theNode->leftChild);
        int r = height(theNode->rightChild);
        return l > r ? (++l) : (++r);
    }
    AVLTreeNode<K, E> *insert(AVLTreeNode<K, E> *&node, const pair<K, E> &thePair);

private:
    AVLTreeNode<K, E> *root;
    int treeSize;
    static void postOrder(AVLTreeNode<K, E> *t);
    static void preOrder(AVLTreeNode<K, E> *t);
    static void inOrder(AVLTreeNode<K, E> *t);
    static void (*visit)(AVLTreeNode<K, E> *t);
    static void depose(AVLTreeNode<K, E> *t)
    {
        delete t;
    }
};
template <class K, class E>
void (*AVLTree<K, E>::visit)(AVLTreeNode<K, E> *t) = nullptr;
template <class K, class E>
void AVLTree<K, E>::postOrder(AVLTreeNode<K, E> *t)
{
    if (t == nullptr)
        return;
    postOrder(t->leftChild);
    postOrder(t->rightChild);
    visit(t);
}
template <class K, class E>
void AVLTree<K, E>::preOrder(AVLTreeNode<K, E> *t)
{
    if (t == nullptr)
        return;
    visit(t);
    preOrder(t->leftChild);
    preOrder(t->rightChild);
}
template <class K, class E>
void AVLTree<K, E>::inOrder(AVLTreeNode<K, E> *t)
{
    if (t == nullptr)
        return;
    inOrder(t->leftChild);
    visit(t);
    inOrder(t->rightChild);
}
/* LL：左子树的左边失去平衡(左单旋转)
 *       k2              k1
 *      /  \            /  \
 *     k1   z   ===>   x    k2
 *    /  \                 /  \
 *   x    y               y    z
 */
template <class K, class E>
AVLTreeNode<K, E> *AVLTree<K, E>::leftLeftRotation(AVLTreeNode<K, E> *&k2)
{
    AVLTreeNode<K, E> *k1 = k2->leftChild;
    k2->leftChild = k1->rightChild;
    k1->rightChild = k2;
    k2->height = std::max(height(k2->leftChild), height(k2->rightChild)) + 1;
    k1->height = std::max(height(k1->leftChild), k2->height) + 1;
    return k1;
}
/* RR：右子树的右边失去平衡(右单旋转)
 *       k1              k2
 *      /  \            /  \
 *     x   k2   ===>   k1   z
 *        /  \        /  \
 *       y    z      x    y
 */
template <class K, class E>
AVLTreeNode<K, E> *AVLTree<K, E>::rightRightRotation(AVLTreeNode<K, E> *&k1)
{
    AVLTreeNode<K, E> *k2 = k1->rightChild;
    k1->rightChild = k2->leftChild;
    k2->leftChild = k1;
    k1->height = height(k1);
    k2->height = max(height(k2->rightChild), k1->height) + 1;
    return k2;
}
/* LR：左子树的右边失去平衡(左双旋转)
 *       k3               k3               k2
 *      /  \     RR      /  \     LL      /  \
 *     k1   D   ===>   k2    D   ===>   k1    k3
 *    /  \            /  \             /  \  /  \
 *   A    K2         k1   C           A    B C   D
 *       /  \       /  \
 *      B    C     A    B
 */
template <class K, class E>
AVLTreeNode<K, E> *AVLTree<K, E>::leftRightRotation(AVLTreeNode<K, E> *&k3)
{
    k3->leftChild = rightRightRotation(k3->leftChild);
    return leftLeftRotation(k3);
}
/* RL：右子树的左边失去平衡(右双旋转)
 *     k1               k1                K2
 *    /  \      LL     /  \      RR      /  \
 *   A    k3   ===>   A    k2   ===>   k1    K3
 *       /  \             /  \        /  \  /  \
 *      k2   D           B    k3     A    B C   D
 *     /  \                  /   \
 *    B    C                C     D
 */
template <class K, class E>
AVLTreeNode<K, E> *AVLTree<K, E>::rightLeftRotation(AVLTreeNode<K, E> *&k1)
{
    k1->rightChild = this->leftLeftRotation(k1->rightChild);
    return this->rightRightRotation(k1);
}
template <class K, class E>
AVLTreeNode<K, E> *AVLTree<K, E>::insert(AVLTreeNode<K, E> *&node, const pair<K, E> &thePair)
{
    if (node == nullptr)
    {
        node = new AVLTreeNode<K, E>(thePair, nullptr, nullptr);
        // cout << "空节点" << endl;
    }
    else if (thePair.first < node->key)
    {
        // cout << node->key << endl;
        node->leftChild = insert(node->leftChild, thePair);
        // 插入节点后AVL树失衡，需要进行相应的调节
        if ((this->height(node->leftChild) - height(node->rightChild)) == 2)
        {
            if (thePair.first < node->leftChild->key)
                node = this->leftLeftRotation(node);
            else
                node = this->leftRightRotation(node);
        }
    }
    else if (thePair.first > node->key)
    {
        // cout << node->key << endl;
        node->rightChild = insert(node->rightChild, thePair);
        if ((height(node->rightChild) - height(node->leftChild)) == 2)
        {
            if (thePair.first > node->rightChild->key)
                node = this->rightRightRotation(node);
            else
                node = this->rightLeftRotation(node);
        }
    }
    // else
    // {
    //     // cout << "添加失败，不能插入key相同的节点" << endl;
    // }
    node->height = max(height(node->leftChild), height(node->rightChild)) + 1;
    return node;
}
template <class K, class E>
void AVLTree<K, E>::levelOrder(void (*func)(AVLTreeNode<K, E> *))
{
    visit = func;
    queue<AVLTreeNode<K, E> *> theQueue;
    if (this->root != nullptr)
        theQueue.push(this->root);
    while (!theQueue.empty())
    {
        AVLTreeNode<K, E> *theNode = theQueue.front();
        if (theNode->leftChild != nullptr)
            theQueue.push(theNode->leftChild);
        if (theNode->rightChild != nullptr)
            theQueue.push(theNode->rightChild);
        AVLTree<K, E>::visit(theNode);
        theQueue.pop();
    }
}
template <class K, class E>
AVLTreeNode<K, E> *AVLTree<K, E>::find(const K &theKey) const
{
    AVLTreeNode<K, E> *theNode = nullptr;
    AVLTreeNode<K, E> *Node = this->root;
    while (Node != nullptr)
    {
        if (Node->key > theKey)
        {
            theNode = Node->leftChild;
            Node = Node->leftChild;
        }
        else if (Node->key < theKey)
        {
            theNode = Node->rightChild;
            Node = Node->rightChild;
        }
        else
        {
            theNode = Node;
            break;
        }
    }
    return theNode;
}
template <class K, class E>
void AVLTree<K, E>::erase(const K &theKey)
{
    // 查找关键字为theKey的节点；
    AVLTreeNode<K, E> *p = root,
                      *pp = nullptr; // pp为p的父节点
    stack<AVLTreeNode<K, E> *> theStack;
    queue<AVLTreeNode<K, E> *> theQueue;
    while (p != nullptr && p->key != theKey)
    {
        pp = p;
        if (p->key > theKey)
        {
            // 将遍历过的节点进行压栈操作
            theStack.push(p);
            p = p->leftChild;
        }
        else if (p->key < theKey)
        {
            theStack.push(p);
            p = p->rightChild;
        }
    }
    // 不存在关键字为theKey的节点
    if (p == nullptr)
        return;
    // 如果p不为空，则将p删除，并且将该位置放置右子树的最小节点，或者左子树的最大节点
    // 以右子树的最小节点为例
    AVLTreeNode<K, E> *lChild = p->leftChild;
    AVLTreeNode<K, E> *rChild = p->rightChild;
    AVLTreeNode<K, E> *pRChild = nullptr;       // 记录rrchild的父节点
    AVLTreeNode<K, E> *rrChild = nullptr;       // 查找p右子树的最小值
    if (rChild == nullptr && lChild == nullptr) // 第一种情况，该节点为叶子结点
    {
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
            this->root = rChild;
        else if (pp->leftChild == p)
            pp->leftChild = rChild;
        else
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
        // theQueue.push(rrChild);
        rrChild = rChild;
        while (rrChild->leftChild != nullptr)
        {
            theQueue.push(rrChild);
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
        // cout << "rrchild = " << rrChild->key << endl;
    }
    delete p;
    this->treeSize--;
    // 如果存在不平衡的节点则需要进行旋转操作
    if (rrChild != nullptr)
        theStack.push(rrChild);
    while (theQueue.size() > 1)
    {
        AVLTreeNode<K, E> *theNode = theQueue.front();
        // cout << "queue Key = " << theNode->key << endl;
        theStack.push(theNode);
        theQueue.pop();
    }
    while (!theStack.empty())
    {
        AVLTreeNode<K, E> *theNode = theStack.top();
        AVLTreeNode<K, E> *newChildNode = nullptr;
        theStack.pop();
        // cout << "theNode key = " << theNode->key << endl;
        if (height(theNode->leftChild) - height(theNode->rightChild) == 2)
        {
            if (height(theNode->leftChild->leftChild) > height(theNode->leftChild->rightChild))
                newChildNode = this->leftLeftRotation(theNode);
            else
                newChildNode = this->leftRightRotation(theNode);
            if (!theStack.empty())
            {
                AVLTreeNode<K, E> *pNode = theStack.top();
                if (theNode == pNode->leftChild)
                    pNode->leftChild = newChildNode;
                else
                    pNode->rightChild = newChildNode;
            }
            else
                this->root = newChildNode;
        }
        if (height(theNode->leftChild) - height(theNode->rightChild) == -2)
        {
            if (height(theNode->rightChild->rightChild) > height(theNode->rightChild->leftChild))
                newChildNode = this->rightRightRotation(theNode);
            else
                newChildNode = this->rightLeftRotation(theNode);
            if (!theStack.empty())
            {
                AVLTreeNode<K, E> *pNode = theStack.top();
                if (theNode == pNode->leftChild)
                    pNode->leftChild = newChildNode;
                else
                    pNode->rightChild = newChildNode;
            }
            else
                this->root = newChildNode;
        }
        theNode->height = max(height(theNode->leftChild), height(theNode->rightChild)) + 1;
    }
}
#endif