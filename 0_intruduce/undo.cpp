#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <stack>
using namespace std;
const int ROW = 9;
const int COLUM = 9;
typedef vector<vector<int>> ARRAY_INT;
int convertString(const string &s)
{
    vector<int> v;
    for (auto a : s)
    {
        v.push_back(a - 48);
    }
    int number = 0;
    int factor = 1;
    for (auto end = v.end() - 1; end >= v.begin(); end--)
    {
        number += (*end) * factor;
        factor *= 10;
    }
    return number;
}
template <class T>
void print(const T &v)
{
    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
pair<int, int> orientate(int i, int j)
{
    vector<int> v = {3, 6, 9};
    int row = -1, colum = -1;
    for (auto a : v)
    {
        if ((i - a) < 0)
        {
            row = a;
            break;
        }
    }
    for (auto a : v)
    {
        if ((j - a) < 0)
        {
            colum = a;
            break;
        }
    }
    pair<int, int> res = make_pair(row, colum);
    return res;
}
bool tryToSolve(const vector<vector<int>> &v_num, int i, int j, int num)
{
    for (int row = 0; row < ROW; row++)
    {
        if (row != i && v_num[row][j] == num)
        {
            return false;
        }
    }
    for (int colum = 0; colum < ROW; colum++)
    {
        if (colum != j && v_num[i][colum] == num)
        {
            return false;
        }
    }
    pair<int, int> location = orientate(i, j);
    for (int a = location.first - 3; a < location.first; a++)
    {
        for (int b = location.second - 3; b < location.second; b++)
        {
            if (v_num[a][b] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool Isend(const vector<vector<int>> &v_num)
{
    for (auto i : v_num)
    {
        for (auto j : i)
        {
            if (j == 0)
            {
                return false;
            }
        }
    }
    return true;
}
vector<pair<int, int>> Find(ARRAY_INT &v_num)
{
    pair<int, int> res;
    vector<pair<int, int>> v_res;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUM; j++)
        {
            if (v_num[i][j] == 0)
            {
                res = make_pair(i, j);
                v_res.push_back(res);
            }
        }
    }
    return v_res;
}
ARRAY_INT undo(vector<vector<int>> v_num, int row, int colum)
{
    if (Isend(v_num))
    {
        return v_num;
    }
    for (int i = row; i < ROW; i++)
    {
        for (int j = colum; j < COLUM; j++)
        {
            int flag = 0;
            ARRAY_INT v_copy = v_num;
            if (v_num[i][j] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (tryToSolve(v_num, i, j, num))
                    {
                        v_copy[i][j] = num;
                        v_num = undo(v_copy, i, j);
                        // cout << "v_num----------------" << endl;
                        print(v_num);
                    }
                    else
                        flag++;
                }
            }
            if (flag == 9)
            {
                v_num[row][colum] = 0;
                return v_num;
            }
        }
    }
    return v_num;
    //  print(v_num);
}
bool undo(vector<vector<int>> &Data)
{
    stack<int> res;
    vector<pair<int, int>> Position = Find(Data);
    int number = 1;
    int pos = 0;
    while (!Isend(Data))
    {
        // cout << "Position:" << Position[pos].first << "," << Position[pos].second << endl;

        int r = Position[pos].first;
        int c = Position[pos].second;

        while (number <= 9)
        {
            // cout << "tryToSolve:" << tryToSolve(Data, r, c, number) << endl;
            // cout << "number:" << number << endl;
            if (tryToSolve(Data, r, c, number))
            {
                Data[r][c] = number;
                break;
            }
            number++;
        }
        if (number <= 9)
        {
            res.push(number);
            number = 1;
            pos++;
            // cout << "res.top():" << res.top() << endl;
        }
        else
        {
            if(res.empty())
                return false;
            int r = Position[pos].first;
            int c = Position[pos].second;
            Data[r][c] = 0;
            int prenumber = res.top();
            res.pop();
            pos--;
            number = prenumber + 1;
        }
        // cout << "--------------------" << endl;
        // print(Data);
    }
    return true;
}
void test()
{
    ifstream ifs;
    ifs.open("undo3.txt", ios::in);
    vector<vector<int>> v_num;
    string buff;
    v_num.resize(ROW);
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUM; j++)
        {
            ifs >> buff;
            v_num[i].push_back(convertString(buff));
        }
    }
    cout << "The problem is-------------------" << endl;
    print(v_num);
    
    cout << "The result is-------------------" << endl;
    if(!undo(v_num))
        cout<<"数独无解！"<<endl;
    print(v_num);
    // cout << Isend(v_num) << endl;
}
int main()
{
    clock_t start_time, end_time;
    start_time = clock();
    // test();
    // pair<int,int>res(orientate(2, 8));
    // cout <<"row = "<<res.first << " colum = "<<res.second<<endl;
    cout<<(22050*8*600/8.0)/1024<<endl;
    end_time = clock();
    double Times = (double)(end_time - start_time)/CLOCKS_PER_SEC;
    cout << "程序运行" << Times << "s" << endl;
    system("pause");
    return 0;
}