#include <iostream>
#include "chainList.hpp"
#include "arrayList.hpp"
#include "linearList.hpp"
#include "circularList.hpp"
#include "doubleLinkList.hpp"
#include <algorithm>
#include <ctime>
using namespace std;
// 箱子排序
class student
{
public:
    student(){};
    student(int score, char name)
    {
        this->_name = name;
        this->_score = score;
    }
    student(const student &stu)
    {
        this->_score = stu._score;
        this->_name = stu._name;
    }
    int _score;
    char _name;
};
ostream &operator<<(ostream &cout, const student &stu)
{
    cout << "name: " << stu._name << " score: " << stu._score << endl;
    return cout;
}
// 箱子排序
void binsort(chainList<student> &theChain, int range = 5)
{
    chainList<student> *bin = new chainList<student>[range + 1];
    int numberOfElements = theChain.size();
    // cout<<numberOfElements<<endl;
    for (int i = 1; i <= numberOfElements; i++)
    {
        student stu = theChain.get(0);
        theChain.erase(0);
        // cout<<theChain.size()<<endl;
        bin[stu._score].push_back(stu);
    }
    for (int j = range; j >= 0; j--)
    {
        // cout<<"----------"<<endl;
        while (!bin[j].empty())
        {
            student stu = bin[j].get(0);
            bin[j].erase(0);
            theChain.push_back(stu);
        }
    }
    theChain.reverse();
    delete[] bin;
}
void genStudent(chainList<student> &stuList, int number = 10, int range = 5)
{
    srand(time(0));
    string nameSeed = "ABCDEFGHIJKLMN";
    for (int i = 0; i < number; i++)
    {
        char name = nameSeed[i];
        int score = rand() % (range + 1);
        student stu(score, name);
        stuList.push_back(stu);
    }
}
void test01()
{
    chainList<student> L1;
    genStudent(L1);
    cout << L1 << endl;
    binsort(L1);
    cout << "binsort : -----" << endl;
    cout << L1 << endl;
}
// 基数排序
void radixSort(chainList<int> &theChain, int radix = 10)
{
    chainList<int> *bin = new chainList<int>[radix];
    int maxNum = theChain.max();
    int count = 0;
    int base = 1;
    while (maxNum != 0)
    {
        maxNum /= radix;
        base *= radix;
        count++;
    }
    base /= radix;
    cout << "count =  " << count << endl;
    cout << "base = " << base << endl;
    int numberOfElements = theChain.size();
    while (count != 0)
    {
        cout << "count =  " << count << endl;
        for (int i = 1; i <= numberOfElements; i++)
        {
            int num = theChain.get(0);
            int index = num / base;
            index %= radix;
            cout << "index = " << index << endl;
            theChain.erase(0);
            bin[index].push_front(num);
        }
        for (int j = radix - 1; j >= 0; j--)
        {
            while (!bin[j].empty())
            {
                int num = bin[j].get(0);
                bin[j].erase(0);
                theChain.push_front(num);
            }
        }
        cout << "L1:" << theChain << endl;
        base /= radix;
        count--;
    }

    // theChain.reverse();
}
union UNum
{
    int IntNum;
    double DouNum;
};

void test02()
{
    chainList<int> L1;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int num = rand() % 1001;
        L1.push_back(num);
    }
    cout << "L1 : " << L1 << endl;
    radixSort(L1, 1000);
    cout << "L1 : " << L1 << endl;
}
// 该算法选用双头循环链表 解决逆序列还原问题
void test11()
{
    doubleLinkList<int> L1;
    int number;
    for (int i = 0; i < 8; i++)
    {
        cin >> number;
        L1.push_back(number);
    }
    // cout << "L1.size = " << L1.size() << endl;

    doubleLinkList<int> L2;
    doubleLinkList<int>::iterator it = L1.end();
    L2.push_back(L1.size());
    it--;
    for (int i = L1.size() - 1; i >= 1; i--)
    {
        // cout << *it << endl;
        if (*it == 0)
        {

            L2.push_front(i);
            // cout << "front: " << L2 << endl;
        }
        else if (*it == L2.size())
        {
            L2.push_back(i);
            // cout << "back: " << L2 << endl;
        }
        else
        {
            L2.insert(*it, i);
            // cout << "insert: " << L2 << endl;
        }
        it--;
    }
    // L1.push_front(-1);
    cout << L1 << endl;
    cout << L2 << endl;
}
// 提供一种更简便的算法来还原逆序列
void test13()
{
    arrayList<int> L1;
    arrayList<int> L;
    for (int i = 0; i < 8; i++)
    {
        int number;
        cin >> number;
        L1.push_back(number);
        L.push_back(i);
    }
    arrayList<int> L2;
    L2.setSize(L1.size());
    int i = 1;
    for (arrayList<int>::iterator it = L1.begin(); it != L1.end(); it++, i++)
    {
        cout << *it << endl;
        L2.set(L[*it], i);
        L.erase(*it);
        cout << "L1: " << L2 << endl;
    }
    cout << L1 << endl;
    cout << L2 << endl;
}
void test12()
{
    doubleLinkList<int> L1;
    for (int i = 0; i < 10; i++)
    {
        L1.push_front(i + 1);
    }
    L1.insert(0, -1);
    cout << L1 << endl;
}
int main()
{
    // test01();
    // test02();
    // UNum num;
    // num.DouNum = 1.1;
    // num.IntNum = 1;
    // cout << num.IntNum << endl;
    // test03();
    // test04();
    // test05();
    // test06();
    // test07();
    // test08();
    // test09();
    // test10();
    // test11();
    // test12();
    test13();
    system("pause");
    return 0;
}