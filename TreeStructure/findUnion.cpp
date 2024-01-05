// #include <iostream>
// using namespace std;
// // 为实现重量规则设计结构体
// struct unionFindNode
// {
//     int parent; // 若root为真则表示树的重量，否则是父节点的指针
//     bool root;  // 当且仅当是根时，值为真
//     unionFindNode()
//     {
//         parent = 1;
//         root = true;
//     }
// };
// // int *parent;
// unionFindNode *Node;
// // 初始化numberOfElement 颗树，每棵树一个元素
// void initialize(int numberOfElements)
// {
//     // parent = new int[numberOfElements + 1];
//     Node = new unionFindNode[numberOfElements + 1];
//     // for (int e = 1; e <= numberOfElements; ++e)
//     // {
//     //     parent[e] = 0;
//     // }
// }
// // 返回元素的root
// // int find(int theElement)
// // {
// //     while (!Node[theElement].root)
// //     {
// //         theElement = Node[theElement].parent;
// //     }
// //     return theElement;
// // }
// // 利用路径紧缩对查找函数进行改进
// int compactionFind(int theElement)
// {
//     // theRoot最终是树的根
//     int theRoot = theElement;
//     while(!Node[theRoot].root)
//     {
//         theRoot = Node[theElement].parent;
//     }
//     // 紧缩路径从theElement 到theRoot的路径
//     int currentNode = theElement;
//     while(currentNode != theRoot)
//     {
//         int parentNode = Node[currentNode].parent;
//         Node[currentNode].parent = theRoot;   // 移到第二层
//         currentNode = parentNode;    // 移动原来的父节点
//     }
//     return theRoot;
// }
// // 路径分割
// int splitFind(int theElement)
// {
//     int theroot = theElement;
//     while(!Node[theroot].root)
//     {
//         theroot = Node[theElement].parent;
//     }
//     // 路径分割是将查找节点指向其祖节点
//     int currentNode = theElement;
//     while(currentNode != theroot && Node[currentNode].parent != theroot)
//     {
//         int parentNode = Node[currentNode].parent;
//         int grandNode = Node[parentNode].parent;
//         Node[currentNode].parent = grandNode;
//         currentNode = parentNode;
//     }
//     return theroot;
// }
// // 合并两颗其根节点不同的树
// // 引用重量规则
// void unite(int rootA, int rootB)
// {
//     // Node[rootB] = rootA;
//     if (Node[rootA].parent < Node[rootB].parent)
//     {
//         Node[rootB].parent += Node[rootA].parent;
//         Node[rootA].root = false;
//         Node[rootA].parent = rootB;
//     }
//     else
//     {
//         Node[rootA].parent += Node[rootB].parent;
//         Node[rootB].root = false;
//         Node[rootB].parent = rootA;
//     }
// }
// int main()
// {
//     initialize(10);

//     return 0;
// }