// #include <iostream>
// #include <ctime>
// using namespace std;
// template <class T>
// class Node
// {
// public:
//     T data;
//     Node<T> *pointer = nullptr;
//     Node()
//     {
//         Node<T> *pointer = nullptr;
//     }
//     Node(const T &data)
//     {
//         this->data = data;
//     }
// };
// template <class T>
// class myList
// {
// public:
//     myList()
//     {
//         this->lenth = 0;
//         head = new Node<T>;
//     }
//     myList(const Node<T> &element)
//     {
//         this->lenth = 0;
//         head = new Node<T>;
//         head->data = element.data;
//         this->lenth++;
//     }
//     ~myList()
//     {

//         Node<T> *temp1 = head;
//         Node<T> *temp2;
//         while (temp1 != nullptr)
//         {
//             temp2 = temp1->pointer;
//             delete temp1;
//             temp1 = temp2;
//         }
//     }
//     void push_back(const Node<T> &element)
//     {
//         if (this->lenth == 0)
//         {
//             // cout<<"if"<<endl;
//             head->data = element.data;
//             head->pointer = nullptr;
//             this->lenth++;
//         }
//         else
//         {

//             // cout<<this->head<<endl;
//             Node<T> *temp = new Node<T>;
//             temp->data = element.data;
//             temp->pointer = nullptr;
//             Node<T> *first = nullptr;
//             Node<T> *next = this->head;
//             // for(int i =0 ;i<this->lenth-1;i++)
//             // {
//             //     temp1 = temp1->pointer;
//             // }
//             while (next != nullptr)
//             {
//                 first = next;
//                 next = first->pointer;
//             }
//             first->pointer = temp;
//             this->lenth++;
//         }
//     }
//     void printList() const
//     {
//         Node<T> *temp = this->head;
//         while (temp != nullptr)
//         {
//             cout << temp->data << "\t";
//             temp = temp->pointer;
//         }
//         cout << endl;
//     }
//     void insert(T element, int _pos)
//     {
//         if (this->lenth == 0)
//         {
//             Node<T> *head = new Node<T>;
//             head->data = element.data;
//             this->lenth++;
//         }
//         else
//         {
//         }
//     }
//     const int size()
//     {
//         return lenth;
//     }

// private:
//     int lenth;
//     Node<T> *head = nullptr;
// };
// void test01()
// {
//     myList<int> list1;
//     // Node<int> data1(1);
//     for (int i = 0; i < 10; i++)
//     {
//         list1.push_back(Node<int>(i));
//     }
//     int lenth = list1.size();
//     list1.printList();
// }
// int main()
// {
//     clock_t start_time, end_time;
//     start_time = clock(); // 获取开始执行时间
//     test01();
//     system("pause");
//     end_time = clock();
//     double Times = (double)(end_time - start_time);
//     return 0;
// }