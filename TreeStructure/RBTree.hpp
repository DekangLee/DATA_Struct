#ifndef __RBTREEH__
#define __RBTREEH__
#include <iostream>
using namespace std;
typedef enum
{
    RED = 0,
    BLACK
} Color;
template <class K, class E>
struct RBTreeNode
{
    Color color;                  // 红黑树的颜色
    K key;                        // 节点的键
    E value;                      // 节点的值
    RBTreeNode<K, E> *leftChild;  // 左子节点
    RBTreeNode<K, E> *rightChild; // 右子节点
    RBTreeNode<K, E> *parent;     // 父节点
    // int height;                   // 节点的高度
    RBTreeNode()
    {
        leftChild = nullptr;
        rightChild = nullptr;
        parent = nullptr;
        color = RED;
        // height = 0;
    }
    RBTreeNode(const K &theKey, const E &theValue)
    {
        this->color = RED;
        this->key = theKey;
        this->value = theValue;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
        this->parent = nullptr;
        // this->height = 0;
    }
};
template <class K, class E>
class RBTree
{
public:
    RBTree()
    {
        this->Nil = new RBTreeNode<K, E>;
        this->Nil->key = -1;
        this->Nil->color = BLACK;
        this->root = Nil;
    }
    ~RBTree()
    {
        depose(this->root, this->Nil);
        this->root = nullptr;
        if (this->Nil != nullptr)
        {
            delete Nil;
            Nil = nullptr;
        }
    }
    bool insert(const K &theKey, const E &theValue);
    void postOrder(void (*func)(RBTreeNode<K, E> *))
    {
        visit = func;
        this->postOrder(this->root, this->Nil);
    }
    void preOrder(void (*func)(RBTreeNode<K, E> *))
    {
        visit = func;
        this->preOrder(this->root, this->Nil);
    }
    void output()
    {
        order(this->root);
    }
    void order(RBTreeNode<K, E> *node)
    {
        if (node == Nil)
            return;
        cout << "key: " << node->key << "  color: " << node->color << endl;
        cout << "parent: " << node->parent->key << "  left: " << node->leftChild->key << "  right: " << node->rightChild->key << endl;
        if (node->leftChild == Nil)
            cout << "node->leftChild == Nil" << endl;
        if (node->rightChild == Nil)
            cout << "node->rightChild == Nil" << endl;
        order(node->leftChild);
        order(node->rightChild);
    }
    void inOrder(void (*func)(RBTreeNode<K, E> *))
    {
        visit = func;
        this->inOrder(this->root, this->Nil);
    }
    RBTreeNode<K, E> *find(const K &theKey)
    {
        RBTreeNode<K, E> *node = this->root;
        while (node != Nil)
        {
            if (node->key > theKey)
                node = node->leftChild;
            else if (node->key < theKey)
                node = node->rightChild;
            else
                return node;
        }
        return nullptr;
    }
    void erase(const K &theKey);

private:
    RBTreeNode<K, E> *leftLeftRotation(RBTreeNode<K, E> *&k2);
    RBTreeNode<K, E> *rightRightRotation(RBTreeNode<K, E> *&k1);
    RBTreeNode<K, E> *leftRightRotation(RBTreeNode<K, E> *&k3);
    RBTreeNode<K, E> *rightLeftRotation(RBTreeNode<K, E> *&k1);
    RBTreeNode<K, E> *BuyNode(const K &x = K());
    void insertFixUp(RBTreeNode<K, E> *theNode);
    int height(RBTreeNode<K, E> *theNode)
    {
        if (theNode == this->Nil)
            return 0;
        int l = height(theNode->leftChild);
        int r = height(theNode->rightChild);
        return l > r ? (++l) : (++r);
    }
    RBTreeNode<K, E> *maxNode(RBTreeNode<K, E> *theNode);
    RBTreeNode<K, E> *minNode(RBTreeNode<K, E> *theNode);
    // RBTreeNode<K, E> *RrRotation(RBTreeNode<K, E> *theNode);
    // RBTreeNode<K, E> *LlRotation(RBTreeNode<K, E> *theNode);
    void eraseFixup(RBTreeNode<K, E> *theNode);
    RBTreeNode<K, E> *eraseCase1(RBTreeNode<K, E> *theNode);
    RBTreeNode<K, E> *eraseCase2(RBTreeNode<K, E> *theNode);
    RBTreeNode<K, E> *eraseCase3(RBTreeNode<K, E> *theNode);
    RBTreeNode<K, E> *eraseCase4(RBTreeNode<K, E> *theNode);

private:
    RBTreeNode<K, E> *root; // 红黑树根节点
    RBTreeNode<K, E> *Nil;  // 外部节点为黑色空节点
    static void postOrder(RBTreeNode<K, E> *t, RBTreeNode<K, E> *lastNode);
    static void preOrder(RBTreeNode<K, E> *t, RBTreeNode<K, E> *lastNode);
    static void inOrder(RBTreeNode<K, E> *t, RBTreeNode<K, E> *lastNode);
    static void (*visit)(RBTreeNode<K, E> *t);
    void depose(RBTreeNode<K, E> *t, RBTreeNode<K, E> *lastNode)
    {
        if (t == lastNode)
            return;
        depose(t->leftChild, lastNode);
        depose(t->rightChild, lastNode);
        delete t;
    }
};
template <class K, class E>
void (*RBTree<K, E>::visit)(RBTreeNode<K, E> *t) = nullptr;
template <class K, class E>
void RBTree<K, E>::postOrder(RBTreeNode<K, E> *t, RBTreeNode<K, E> *lastNode)
{
    if (t == lastNode)
        return;
    postOrder(t->leftChild, lastNode);
    postOrder(t->rightChild, lastNode);
    visit(t);
}
template <class K, class E>
void RBTree<K, E>::preOrder(RBTreeNode<K, E> *t, RBTreeNode<K, E> *lastNode)
{
    if (t == lastNode)
        return;
    visit(t);
    preOrder(t->leftChild, lastNode);
    preOrder(t->rightChild, lastNode);
}
template <class K, class E>
void RBTree<K, E>::inOrder(RBTreeNode<K, E> *t, RBTreeNode<K, E> *lastNode)
{
    if (t == lastNode)
        return;
    inOrder(t->leftChild, lastNode);
    visit(t);
    inOrder(t->rightChild, lastNode);
}
template <class K, class E>
RBTreeNode<K, E> *RBTree<K, E>::BuyNode(const K &x)
{
    RBTreeNode<K, E> *node = new RBTreeNode<K, E>;
    node->color = RED;
    node->leftChild = node->rightChild = node->parent = this->Nil;
    node->key = x;
    node->value = E();
    return node;
}
template <class K, class E>
bool RBTree<K, E>::insert(const K &theKey, const E &theValue)
{
    RBTreeNode<K, E> *pNode = this->Nil; // 记录父节点
    RBTreeNode<K, E> *node = this->root; // 从根开始查找
    while (node != Nil)
    {
        pNode = node; // 每次记住node的父节点
        if (theKey < node->key)
            node = node->leftChild;
        else if (theKey > node->key)
            node = node->rightChild;
        else
            return false;
    }
    node = BuyNode(theKey);
    node->value = theValue;
    // cout << "pNode Key = " << pNode->key << endl;
    if (pNode == this->Nil) // 要插入的节点为根节点
    {
        this->root = node;
        this->root->parent = this->Nil;
        this->root->color = BLACK;
        root->leftChild = this->Nil;
        root->rightChild = this->Nil;
    }
    else // 如果要插入的节点不是根节点
    {
        if (theKey < pNode->key)
            pNode->leftChild = node;
        if (theKey > pNode->key)
            pNode->rightChild = node;
        node->parent = pNode;
        node->leftChild = this->Nil;
        node->rightChild = this->Nil;
    }
    // node->height = height(node);
    insertFixUp(node);
    return true;
}
template <class K, class E>
void RBTree<K, E>::insertFixUp(RBTreeNode<K, E> *theNode)
{
    // cout<<"-------------------"<<endl;
    RBTreeNode<K, E> *uncle;                                // 父节点的兄弟节点
    RBTreeNode<K, E> *gPNode;                               // 祖节点的父节点
    RBTreeNode<K, E> *gNode;                                // 祖节点
    RBTreeNode<K, E> *newNode;                              // 新的祖节点
    while (theNode != Nil && theNode->parent->color == RED && theNode->color != BLACK) // 父节点的颜色只要是红色就要不断地尝试更改
    {
        gNode = theNode->parent->parent;
        gPNode = gNode->parent;
        if (theNode->parent == gNode->leftChild) // 父节点是祖节点的左子节点
        {
            uncle = gNode->rightChild;
            // cout << "right uncle color: " << uncle->color << endl;
            // cout << "theNode key = " << theNode->key << endl;
            // cout<<"uncle = "<<uncle->key<<endl;
            if (uncle->color == RED) // 该节点为红色只需要重新染色即可
            {
                theNode->parent->color = BLACK;
                uncle->color = BLACK;
                if (gNode != this->root)
                    gNode->color = RED;
                theNode = theNode->parent->parent; // 将指针指向祖节点
            }
            else // uncle节点的颜色为黑色
            {
                if (theNode == theNode->parent->rightChild) // 该节点为父节点的右子节点 LRb型旋转
                {
                    theNode = theNode->parent->parent;    // 将指针指向祖节点
                    newNode = leftRightRotation(theNode); // newNode是新的祖节点
                    if (gPNode == this->Nil)              // 祖节点是根节点
                    {
                        this->root = newNode;
                        this->root->parent = this->Nil;
                    }
                    else
                    {
                        // cout<<"gPNode key = "<<gPNode->key<<endl;
                        if (gNode == gPNode->leftChild)
                            gPNode->leftChild = newNode;
                        else
                            gPNode->rightChild = newNode;
                        newNode->parent = gPNode;
                        // cout<<"newNode = "<<newNode->key<<endl;
                    }
                    theNode = newNode;
                }
                else if (theNode == theNode->parent->leftChild) // 该节点为父节点的右子节点 LLb型旋转
                {
                    // cout << "theNode key = " << theNode->key << endl;
                    theNode = theNode->parent->parent;
                    newNode = leftLeftRotation(theNode);
                    if (gPNode == this->Nil) // 祖节是根节点
                    {
                        this->root = newNode;
                        this->root->parent = this->Nil;
                    }
                    else
                    {
                        if (gNode == gPNode->leftChild)
                            gPNode->leftChild = newNode;
                        else
                            gPNode->rightChild = newNode;
                        newNode->parent = gPNode;
                    }
                    theNode = newNode;
                }
                newNode->color = BLACK;
                newNode->leftChild->color = RED;
                newNode->rightChild->color = RED;
            }
        }
        else if (theNode->parent == gNode->rightChild) // 父节点是祖节点的右子节点
        {
            uncle = gNode->leftChild;
            // cout << "left uncle color: " << uncle->color << "  key: " << uncle->key << endl;
            if (uncle->color == RED) // 该节点为红色只需要重新染色即可
            {
                theNode->parent->color = BLACK;
                uncle->color = BLACK;
                if (gNode != this->root)
                    gNode->color = RED;
                theNode = theNode->parent->parent;
                // cout << "thenode parent key: " << theNode->parent->key << endl;
                // cout << "thenode parent color: " << theNode->parent->color << endl;
            }
            else // uncle节点的颜色为黑色
            {
                if (theNode == theNode->parent->rightChild) // 该节点为父节点的右子节点 RRb型旋转
                {
                    theNode = theNode->parent->parent;
                    // cout << "theNode key = " << theNode->key << endl;
                    newNode = rightRightRotation(theNode);
                    // cout << "newNode key = " << newNode->key << "  color = " << newNode->color << endl;
                    if (gPNode == this->Nil) // 祖节点是根节点
                    {
                        this->root = newNode;
                        this->root->parent = this->Nil;
                    }
                    else
                    {
                        if (gNode == gPNode->leftChild)
                            gPNode->leftChild = newNode;
                        else
                            gPNode->rightChild = newNode;
                        newNode->parent = gPNode;
                    }
                    theNode = newNode;
                    // cout<<"Rr newNode = "<<newNode->key<<endl;
                }
                else if (theNode == theNode->parent->leftChild) // 该节点为父节点的左子节点 RLb型旋转
                {
                    theNode = theNode->parent->parent;
                    newNode = rightLeftRotation(theNode);
                    if (gPNode == this->Nil) // 祖节点是根节点
                    {
                        // cout<<"gPNode key = "<<gPNode->key<<endl;
                        this->root = newNode;
                        this->root->parent = this->Nil;
                    }
                    else
                    {
                        // cout<<"gPNode key = "<<gPNode->key<<endl;
                        if (gNode == gPNode->leftChild)
                            gPNode->leftChild = newNode;
                        else
                            gPNode->rightChild = newNode;
                        newNode->parent = gPNode;
                    }
                    theNode = newNode;
                }
                newNode->color = BLACK;
                newNode->leftChild->color = RED;
                newNode->rightChild->color = RED;
            }
        }
    }
}
/* LLb：左子树的左边失去平衡(左单旋转)
 *       k2              k1
 *      /  \            /  \
 *     k1   z   ===>   k3    k2
 *    /  \                 /  \
 *   k3    y               y    z
 */
template <class K, class E>
RBTreeNode<K, E> *RBTree<K, E>::leftLeftRotation(RBTreeNode<K, E> *&k2)
{
    RBTreeNode<K, E> *k1 = k2->leftChild;
    // RBTreeNode<K, E> *k3 = k1->leftChild;
    k2->leftChild = k1->rightChild;
    k2->leftChild->parent = k2;
    k1->rightChild = k2;
    k2->parent = k1;
    // k2->height = height(k2);
    // k1->height = height(k1);
    return k1;
}
/* RR：右子树的右边失去平衡(右单旋转)
 *       k1              k2
 *      /  \            /  \
 *     x   k2   ===>   k1   k3
 *        /  \        /  \
 *       y    k3      x    y
 */
template <class K, class E>
RBTreeNode<K, E> *RBTree<K, E>::rightRightRotation(RBTreeNode<K, E> *&k1)
{
    RBTreeNode<K, E> *k2 = k1->rightChild;
    // RBTreeNode<K, E> *k3 = k2->rightChild;
    k1->rightChild = k2->leftChild;
    k1->rightChild->parent = k1;
    k2->leftChild = k1;
    k1->parent = k2;
    // k1->height = height(k1);
    // k2->height = height(k2);
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
RBTreeNode<K, E> *RBTree<K, E>::leftRightRotation(RBTreeNode<K, E> *&k3)
{
    RBTreeNode<K, E> *k1 = k3->leftChild;
    RBTreeNode<K, E> *k2 = k1->rightChild;
    k1->rightChild = k2->leftChild;
    k3->leftChild = k2->rightChild;
    k2->leftChild = k1;
    k2->rightChild = k3;
    k1->parent = k2;
    k3->parent = k2;
    k1->rightChild->parent = k1;
    k3->leftChild->parent = k3;
    // k2->height = height(k2);
    // k1->height = height(k1);
    // k3->height = height(k3);
    return k2;
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
RBTreeNode<K, E> *RBTree<K, E>::rightLeftRotation(RBTreeNode<K, E> *&k1)
{
    RBTreeNode<K, E> *k3 = k1->rightChild;
    RBTreeNode<K, E> *k2 = k3->leftChild;

    k1->rightChild = k2->leftChild;
    k3->leftChild = k2->rightChild;
    k2->leftChild = k1;
    k2->rightChild = k3;
    k3->parent = k2;
    k1->parent = k2;
    k1->rightChild->parent = k1;
    k3->leftChild->parent = k3;
    // k2->height = height(k2);
    // k1->height = height(k1);
    // k3->height = height(k3);
    return k2;
}
template <class K, class E>
RBTreeNode<K, E> *RBTree<K, E>::maxNode(RBTreeNode<K, E> *theNode)
{
    RBTreeNode<K, E> *node = theNode;
    while (theNode != Nil)
    {
        node = theNode;
        theNode = theNode->rightChild;
    }
    return node;
}
template <class K, class E>
RBTreeNode<K, E> *RBTree<K, E>::minNode(RBTreeNode<K, E> *theNode)
{
    RBTreeNode<K, E> *node = theNode;
    while (theNode != Nil)
    {
        node = theNode;
        theNode = theNode->leftChild;
    }
    return node;
}
template <class K, class E>
void RBTree<K, E>::erase(const K &theKey)
{
    RBTreeNode<K, E> *theNode = this->root; // 要查找的节点
    // cout << "the Key = " << theKey << endl;

    while (theNode != Nil && theNode->key != theKey)
    {
        // cout << "find Node = " << theNode->key << endl;
        // if (theNode->leftChild == Nil)
        //     cout << "theNode->leftChild == Nil" << endl;
        // if (theNode->rightChild == Nil)
        //     cout << "theNode->rightChild == Nil" << endl;
        if (theNode->key > theKey)
            theNode = theNode->leftChild;
        else if (theNode->key < theKey)
            theNode = theNode->rightChild;
        // if (theNode == Nil)
        // {
        //     cout << "theNode == Nil" << endl;
        //     break;
        // }
    }
    if (theNode == this->Nil)
        return;
    RBTreeNode<K, E> *delNode = theNode;
    RBTreeNode<K, E> *oNode; // 源节点
    // 这里需要删除theNode节点，可以删除该节点右子节点的最小值，与该节点互换值，但不互换颜色
    while (delNode->leftChild != Nil || delNode->rightChild != Nil)
    {
        oNode = delNode;
        RBTreeNode<K, E> *temp = new RBTreeNode<K, E>(oNode->key, oNode->value);
        if (delNode->rightChild != Nil)
        {
            delNode = minNode(delNode->rightChild);
        }
        else if (delNode->leftChild != Nil)
        {
            delNode = maxNode(delNode->leftChild);
        }
        oNode->key = delNode->key;
        oNode->value = delNode->value;
        delNode->key = temp->key;
        delNode->value = temp->value;
        delete temp;
    }
    // cout << "delNode key: " << delNode->key << endl;

    // delNode就是需要删除的节点, 并且是叶子节点
    eraseFixup(delNode);
    if (delNode == delNode->parent->leftChild)
        delNode->parent->leftChild = Nil;
    else
        delNode->parent->rightChild = Nil;
    // cout << "delNode = " << delNode->key << endl;
    // cout << "pdel = " << delNode->parent->key << endl;
    delete delNode;
}
template <class K, class E>
void RBTree<K, E>::eraseFixup(RBTreeNode<K, E> *theNode)
{
    if (theNode->color == RED) // 此时该节点为叶子结点，直接删除即可,不影响
        return;
    if (theNode == this->root) // 根节点直接删去即可，此时红黑树只有一个根节点
    {
        this->root = Nil;
        return;
    }
    while (theNode != this->root)
    {
        // cout << "theNode = " << theNode->key << endl;
        RBTreeNode<K, E> *pNode = theNode->parent; // 输入节点的父节点
        RBTreeNode<K, E> *bNode;                   // 输入节点的兄弟节点
        if (theNode == pNode->leftChild)
            bNode = pNode->rightChild;
        else
            bNode = pNode->leftChild;
        // cout << "bNode = " << bNode->key << endl;

        if (bNode->color == BLACK) // bNode一定不是外部节点，并且颜色为黑色
        {
            if (bNode->leftChild->color == BLACK && bNode->rightChild->color == BLACK)
            {
                // cout << "case2:theNode = " << theNode->key << endl;
                // cout << "case2:bNode = " << bNode->key << endl;
                // cout << "case2:pNode = " << pNode->key << endl;

                theNode = eraseCase2(theNode);
                if (theNode->parent->color == RED)
                {
                    // cout << "theNode->parent->color = " << theNode->parent->color << endl;
                    theNode->parent->color = BLACK;
                    return;
                }
                else
                {
                    theNode = theNode->parent;
                    // if (theNode == this->root)
                    // {
                    //     cout << "theNode == this->root" << endl;
                    //     cout << "root = " << root->key << endl;
                    //     return;
                    // }
                }
            }
            else
            {
                if (theNode == pNode->leftChild)
                {
                    if (bNode->leftChild->color == RED && bNode->rightChild->color == BLACK)
                        theNode = eraseCase3(theNode);
                    else
                    {
                        // cout << "theNode = " << theNode->key << endl;
                        // cout << "bNode = " << bNode->key << endl;
                        // cout << "pNode = " << pNode->key << endl;
                        theNode = eraseCase4(theNode);
                        return;
                    }
                }
                else
                {
                    if (bNode->leftChild->color == BLACK && bNode->rightChild->color == RED)
                        theNode = eraseCase3(theNode);
                    else
                    {
                        theNode = eraseCase4(theNode);
                        return;
                    }
                }
            }
        }
        else if (bNode->color == RED) // bNode一定不是外部节点，并且颜色为红色,这意味着bNode有两个黑色节点并且不是外部节点
            theNode = eraseCase1(theNode);
    }
    // cout << "pNode key = " << pNode->key << endl;
    // cout << "bNode key = " << bNode->key << endl;
    // 第一种情况，要删的节点为红色节点 可以直接删掉
}
template <class K, class E>
RBTreeNode<K, E> *RBTree<K, E>::eraseCase1(RBTreeNode<K, E> *theNode)
{
    RBTreeNode<K, E> *pNode = theNode->parent;
    RBTreeNode<K, E> *ppNode = pNode->parent;
    // cout << "case1:ppNode = " << ppNode->key << endl;
    // cout << "case1:pNode = " << pNode->key << endl;
    RBTreeNode<K, E> *newNode;
    if (theNode == pNode->leftChild)
    {
        newNode = rightRightRotation(pNode);
        newNode->color = BLACK;
        newNode->leftChild->color = RED;
    }
    else
    {
        newNode = leftLeftRotation(pNode);
        newNode->color = BLACK;
        newNode->rightChild->color = RED;
    }
    newNode->parent = ppNode;
    if (ppNode == Nil)
        this->root = newNode;
    else if (pNode == ppNode->leftChild)
        ppNode->leftChild = newNode;
    else if (pNode == ppNode->rightChild)
        ppNode->rightChild = newNode;
    // cout<<"case1: order"<<endl;
    // this->order(root);
    return theNode;
}
template <class K, class E>
RBTreeNode<K, E> *RBTree<K, E>::eraseCase2(RBTreeNode<K, E> *theNode)
{
    RBTreeNode<K, E> *pNode = theNode->parent;
    if (theNode == pNode->leftChild)
        pNode->rightChild->color = RED;
    else
        pNode->leftChild->color = RED;
    return theNode;
}
template <class K, class E>
RBTreeNode<K, E> *RBTree<K, E>::eraseCase3(RBTreeNode<K, E> *theNode)
{
    RBTreeNode<K, E> *pNode = theNode->parent;
    RBTreeNode<K, E> *newNode;
    if (theNode == pNode->leftChild)
    {
        newNode = leftLeftRotation(pNode->rightChild);
        // cout << "case3:newNode = " << newNode->key << endl;
        pNode->rightChild = newNode;
        newNode->parent = pNode;
        newNode->color = BLACK;
        newNode->rightChild->color = RED;
        // cout << "case3:pNode = " << newNode->parent->key << endl;
        // cout << "case3:ppNode = " << newNode->parent->parent->key << endl;
    }
    else
    {
        newNode = rightRightRotation(pNode->leftChild);
        pNode->leftChild = newNode;
        newNode->parent = pNode;
        newNode->color = BLACK;
        newNode->leftChild->color = RED;
    }
    return theNode;
}
template <class K, class E>
RBTreeNode<K, E> *RBTree<K, E>::eraseCase4(RBTreeNode<K, E> *theNode)
{
    RBTreeNode<K, E> *pNode = theNode->parent;
    RBTreeNode<K, E> *ppNode = pNode->parent;
    RBTreeNode<K, E> *newNode;
    Color pColor = pNode->color;
    if (theNode == pNode->leftChild)
    {
        // cout << "pNode = " << pNode->key << endl;
        // cout << "ppNode = " << ppNode->key << endl;
        newNode = rightRightRotation(pNode);
        // cout << "newNode = " << newNode->key << endl;
    }

    else
        newNode = leftLeftRotation(pNode);
    newNode->rightChild->color = BLACK;
    newNode->leftChild->color = BLACK;
    newNode->color = pColor;
    if (ppNode == Nil)
        this->root = newNode;
    else if (pNode == ppNode->leftChild)
        ppNode->leftChild = newNode;
    else if (pNode == ppNode->rightChild)
        ppNode->rightChild = newNode;
    newNode->parent = ppNode;
    return theNode;
}
#endif