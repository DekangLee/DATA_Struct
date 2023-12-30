// 工厂仿真
// 个工厂有m台机器。工厂的每项任务都需要若干道工序才能完成。每台机器都执行-道工序，不同的机器执行不同的工序。
// 一台机器一旦开始执行一道工序就不会中断，直到该工序完成为止。
#include <iostream>
#include "arrayQueue.hpp"
#include <exception>
using namespace std;
struct task
{
    int machine;
    int time;
    task(int theMachine = 0, int theTime = 0)
    {
        this->machine = theMachine;
        this->time = theTime;
    }
};
struct job
{
    arrayQueue<task> taskQ;
    int length;
    int arrivalTime;
    int id;
    job(int theId = 0)
    {
        this->id = theId;
        this->length = 0;
        this->arrivalTime = 0;
    }
    void addTask(int theMachine, int theTime)
    {
        task theTask(theMachine, theTime);
        taskQ.push(theTask);
    }
    int removeNextTask()
    {
        int theTime = taskQ.front().time;
        taskQ.pop();
        this->length += theTime;
        return theTime;
    }
};
struct machine
{
    arrayQueue<job *> jobQ; // 本机器的等待处理的任务队列
    int changeTime;         // 本机器转换时间
    int totalWait;          // 本机器的总体延时
    int numTasks;           // 本机器处理的工序数量
    job *activeJob;         // 本机器当前处理的任务
    machine()
    {
        this->totalWait = 0;
        this->numTasks = 0;
        this->activeJob = nullptr;
    }
};
class eventList
{
public:
    eventList(int theNumMachines, int theLargeTime)
    {
        // 为m台机器，初始化其完成时间
        if (theNumMachines < 1)
        {
            throw illegalParameterValue("number of machines must be > 1!");
            this->numMachines = theNumMachines;
            this->finishTime = new int[this->numMachines + 1];
            for (int i = 1; i <= this->numMachines; i++)
            {
                this->finishTime[i] = theLargeTime;
            }
        }
    }
    ~eventList()
    {
        if (this->finishTime != nullptr)
        {
            delete[] this->finishTime;
            this->finishTime = nullptr;
        }
    }
    int nextEventMachine()
    {
        // 返回值是处理下一项工序的机器
        int p = 1;
        int t = this->finishTime[1];
        for (int i = 2; i <= this->numMachines; i++)
        {
            if (finishTime[i] < t)
            {
                // 机器i完成时间更早
                p = i;
                t = finishTime[i];
            }
        }
        return p;
    }
    int nextEventTime(int theMachine)
    {
        return this->finishTime[theMachine];
    }
    void setFinishTime(int theMachine, int theTime)
    {
        finishTime[theMachine] = theTime;
    }

private:
    int *finishTime; // 完成时数组
    int numMachines; // 机器数量
};
// 全局变量
int timeNow;           // 当前时间
int numMachines = 3;       // 机器数量
int numJobs;           // 任务数量
int largeTime = 10000; // 在这个时间之前所有机器有已经完成工序
// 事件表指针
eventList *eList = new eventList(numMachines, largeTime);
machine *mArray = new machine[numMachines + 1]; // 机器数组
void inputData()
{
    // 输入工厂数据
    cout << "Enter number of machines and jobs" << endl;
    cin>> numJobs;
    if (numMachines < 1 || numJobs < 1)
    {
        throw illegalInputData("number of machines or jobs is invalid!");
    }
    cout << "Enter change-over times for machines" << endl;
    int ct;
    for (int j = 1; j <= numMachines; j++)
    {
        cin >> ct;
        if (ct < 0)
        {
            throw illegalInputData("change-over time must be > 0");
        }
        mArray[j].changeTime = ct;
    }
    // 输入任务
    job *theJob;
    int numTasks, firstMachine, theMachine, theTaskTime;
    for (int i = 1; i <= numJobs; i++)
    {
        cout << "Enter number of tasks for job " << i << endl;
        cin >> numTasks;
        firstMachine = 0;
        if (numTasks < 1)
            throw illegalInputData("each job must have > 1 task");
        // 生成任务
        theJob = new job(i);
        cout << "Enter the tasks (machine,time) in process order" << endl;
        for (int j = 1; j <= numTasks; j++)
        {
            cin >> theMachine >> theTaskTime;
            if (theMachine < 1 || theMachine > numMachines || theTaskTime < 1)
                throw illegalInputData("invalid machine number or task time");
            if (j == 1)
            {
                firstMachine = theMachine; // 处理任务的第一台机器
            }
            theJob->addTask(theMachine, theTaskTime);
        }
        mArray[firstMachine].jobQ.push(theJob);
    }
}
job *changeState(int theMachine)
{
    // 机器theMachine上的工序完成了，调度下一道工序
    // 返回值是机器theMachine上刚刚完成的任务
    job *lastJob;
    if (mArray[theMachine].activeJob == nullptr)
    {
        // 处于空闲或者转换状态
        cout<<"theMachine: "<<theMachine<<endl;
        lastJob = nullptr;
        if (mArray[theMachine].jobQ.empty())
        {
            eList->setFinishTime(theMachine, largeTime);
            cout<<"theMachine: "<<theMachine<<endl;
        }
        else
        {
            // 从队列中提取任务，在机器上执行
            mArray[theMachine].activeJob = mArray[theMachine].jobQ.front();
            mArray[theMachine].jobQ.pop();
            mArray[theMachine].totalWait += timeNow - mArray[theMachine].activeJob->arrivalTime;
            mArray[theMachine].numTasks++;
            int t = mArray[theMachine].activeJob->removeNextTask();
            eList->setFinishTime(theMachine, timeNow + t);
        }
    }
    else
    {
        cout<<"theMachine: "<<theMachine<<endl;
        // 在机器theMachine上刚完成一道工序
        // 设置转换时间
        lastJob = mArray[theMachine].activeJob;
        mArray[theMachine].activeJob = nullptr;
        eList->setFinishTime(theMachine, timeNow + mArray[theMachine].changeTime);
    }
    return lastJob;
}
void startShop()
{
    for (int p = 1; p <= numMachines; p++)
    {
        changeState(p);
    }
}
bool moveToNextMachine(job *theJob)
{
    // 调度任务theJob到执行其下一道工序的机器
    // 如果任务已经完成，则返回false
    if (theJob->taskQ.empty())
    {
        // 没有下一道工序
        cout << "Job " << theJob->id << " has completed at "
             << timeNow << " Total wait was " << (timeNow - theJob->length) << endl;
        return false;
    }
    else
    {
        // 任务theJob有下一道工序
        // 确定执行的机器
        int p = theJob->taskQ.front().machine;
        mArray[p].jobQ.push(theJob);
        theJob->arrivalTime = timeNow;
        // 如果机器p空闲，这改变它的状态
        if (eList->nextEventTime(p) == largeTime)
        {
            // 机器空闲
            changeState(p);
        }
        return true;
    }
}
void simulate()
{
    // 处理所有未处理的任务
    while (numJobs > 0)
    {
        // 至少有一个任务未处理
        int nextToFinish = eList->nextEventMachine();
        timeNow = eList->nextEventTime(nextToFinish);
        // 改变机器nextToFinish上的任务
        job *theJob = changeState(nextToFinish);
        // 把任务theJob调度到下一台
        // 如果任务theJob完成,则减少任务数
        if (theJob != nullptr && !moveToNextMachine(theJob))
            numJobs--;
    }
}
void outputStatistics()
{
    // 输出每台机器上的等待时间
    cout << "Finish time = " << timeNow << endl;
    for (int p = 1; p <= numMachines; p++)
    {
        cout << "machine " << p << " completed " << mArray[p].numTasks << " tasks" << endl;
        cout << "The total wait time was " << mArray[p].totalWait << endl;
        cout << endl;
    }
}
int main()
{
    try
    {
        inputData();        // 获取机器和任务的数据
        startShop();        // 装入初始任务
        simulate();         // 执行所有任务
        outputStatistics(); // 输出在每台机器上的等待时间
    }
    catch (illegalParameterValue &e)
    {
        e.outputMessage();
    }
    system("pause");
    return 0;
}