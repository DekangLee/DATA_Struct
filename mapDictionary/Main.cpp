#include <iostream>
#include <list>
#include <algorithm>
#include "sortedChain.hpp"
#include <bitset>
#include "hashTable.hpp"
#include "hashChain.hpp"
using namespace std;
void test01()
{
    list<int> L1;
    L1.resize(3);
    // cout << "L1.maxSize = " << L1.max_size() << endl;
    list<int> *L2 = new list<int>();
    for (int i = 0; i < 10; i++)
    {
        L1.push_back(i);
    }
    auto _fprint = [](int elem)
    {
        cout << elem << " ";
    };
    // L2->resize(L1.size());
    // L2.assign(L1.begin(), L1.end());
    L2->resize(L1.size());
    copy(L1.begin(), L1.end(), L2->begin());
    for_each(L1.begin(), L1.end(), _fprint);
    cout << endl;
    for_each(L2->begin(), L2->end(), _fprint);
    cout << endl;
    cout << "L1.size = " << L1.size() << endl;
    cout << "L2.size = " << L2->size() << endl;
}
struct A
{
    int intm;
    int &intm1 = intm;
    char charm;
};

void test02()
{
    void (*f)() = test01;
    (*f)();
    sortedChain<int, int> *p;
    cout << sizeof(f) << endl;
    cout << boolalpha << true << endl;
}
void test03()
{
    sortedChain<int, int> schain;
    schain.insert(_make_pair(1, 2));
    schain.insert(_make_pair(2, 3));
    schain.insert(_make_pair(3, 4));
    schain.insert(_make_pair(3, 9));
    for (auto it = schain.begin(); it != schain.end(); it++)
    {
        cout << "first: " << (*it).first << " second: " << (*it).second << endl;
    }
    cout << schain.size() << endl;
    schain.erase(2);
    for (auto it = schain.begin(); it != schain.end(); it++)
    {
        cout << "first: " << (*it).first << " second: " << (*it).second << endl;
    }
    // schain.output();
}
int *p;
void test04()
{
    p = new int[10];
    for (int i = 0; i < 10; i++)
    {
        p[i] = i;
    }
}
void test05()
{
    p[1] = -1;
    cout << bitset<8>(-6) << endl;
    cout << bitset<8>(-2) << endl;
    cout << bitset<8>(-8) << endl;
    unsigned int a = 20;
    // a << 19;  // 是一个表达式 返回值为左移19位的值
    a = a << 1;
    cout << a << endl;
}
void test06()
{
    cout << p[8] << endl;
}
void test07()
{
    hashTable<const char *, int> table1(19);
    const char *name1 = "ldk";
    table1.insert(make_pair(name1, 20));
    hashTable<string, int> table2(299);
    table1.insert(make_pair("lide", 50));
    table1.insert(make_pair("li", 20));
    // cout<<"table1 size = "<<table1.size()<<endl;
    // cout<<"table2 size = "<<table2.size()<<endl;
    table1.insert(make_pair("lidekang213", 24));
    table1.insert(make_pair("lidekang", 23));
    table1["li"] = 2345;
    table1.erase("li");
    // // table1.output();
    // table1["zilidjf"] = 10;
    // table1.output();
    // cout << table1["zls"] << endl;
    // cout << "///////" << endl;
    table1.output();
}
void test08()
{
    hashChain<int, int> hashChain1;
    hashChain1.insert(make_pair(2, 1));
    hashChain1.insert(make_pair(4, 4));
    hashChain1.insert(make_pair(1, -1));
    hashChain1.insert(make_pair(9, 4));
    hashChain1.insert(make_pair(0, 4));
    hashChain1.insert(make_pair(299, -1));
    hashChain1.insert(make_pair(300, -2));
    hashChain1.insert(make_pair(-1, 4));
    hashChain1[9] = 0;
    hashChain1[200] = -1;
    pair<int, int> *res = hashChain1.find(2);
    if (res != nullptr)
    {
        cout << res->first << "," << res->second << endl;
    }
    else
    {
        cout << "未查到" << endl;
    }
    hashChain1.output();
    cout << "table szie = " << hashChain1.size() << endl;
}
int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    // test06();
    // cout << p[1] << endl;
    // test07();
    // int i = int();
    // cout << i << endl;
    test08();
    system("pause");
    return 0;
}