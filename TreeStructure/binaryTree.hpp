#ifndef _BINARYTREE_
#define _BINARYTREE_
template <class T>
class binaryTree
{
public:
    virtual ~binaryTree(){};
     binaryTree(){};
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual void preOrder(void (*)(T *)) = 0;
    virtual void inOrder(void (*)(T *)) = 0;
    virtual void postOrder(void (*)(T *)) = 0;
    virtual void levelOrder(void (*)(T *)) = 0;
};
#endif