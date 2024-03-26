#ifndef _WINNERTREEH_
#define _WINNERTREEH_
template<class T>
class winnerTree
{
public:
    virtual ~winnerTree(){};
    // 用数组theplayer生成赢者树
    virtual void initialize(T *thePlayer, int theNumberOfPlayers) = 0;
    // 返回赢者树的索引
    virtual int winner() const = 0;
    // 在参赛者thePlayer的分数变化后重赛
    virtual void rePlayer(int thePlayer) = 0;
};
#endif