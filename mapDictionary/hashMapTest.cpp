#include <iostream>
#include <string>
using namespace std;
long threeToLong(string s)
{
    long answer = s.at(0);
    string::iterator it = s.begin() + 1;
    while (it != s.end())
    {
        answer = (answer << 8) + *it;
        // cout << *it << endl;
        it++;
    }
    return answer;
}
int main()
{
    char *ch = new char('0');
    int *a = new int(48);
    // threeToLong(ch);
    // cout << "ans = " << threeToLong(ch) << endl;
    int *p = (int *)ch;
    cout << (int)*ch << endl;
    cout << *(char *)a << endl;
    system("pause");
    return 0;
}