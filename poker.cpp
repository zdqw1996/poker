#include <iostream>
#include <cstdlib>
#include <cstdlio>
#include <string>
#include <ctime>

using namespace std;
class Struct
{
    private:
        char m_type;//牌的花色
        char m_num;//牌的大小
        char p_type[4];//牌的花色选项
        char p_num[13];//牌大小选项
    public:
        Struct()
        {
            p_type[4] = {'♠','♥','♣','♦'};
            p_num[13] = {'A','2','3','4','5','6','7','8','9','o','J','Q','K'}; 
        }
};
class Poker
{
    private:
        Struct m_Poker[52];//存放牌的数组
        int 
        //Struct m_play[4][13]//玩家存放牌的数组

    public:
        Poker();//构造函数

	    void init();//给每张牌赋值

   

};
void Poker:: init()
{
    
    int i, j, n;
    for(i = 0; i < 4; i++)//设置花色
    {
        for(j = 0; j < 13; j++)//设置牌号
        {
            n = i * 13 + j;
            m_Poker[n].m_type = p_type[i];
            m_Poker[n].m_num = p_num[j];
        }
    }
}

class Play:public Poker 
{
    private:
        Struct m_play[4][13];//用一个二维数组来表示四个玩家手中的牌
        
    public:
        Play()
        {
            for(int i = 0; i<4;i++)
            {
                for(int j =0;j< 13; j++)
                {
                     m_play[i][j]= 0;            
                }
            }
        }
        void send();//随机将牌组中的牌发到用户手牌上
        void sort();//为玩家手牌排序
        void show();//显示牌
}
void Play::send()
{
    int rand1;
    srand((unsigned)time(NULL));
    for(int i = 0; i<4;i++)
    {
        for(int j =0;j< 13; j++)
        {
            rand1 = rand() % 52;
            m_play[i][j] = m_poker[rand1];           
        }
    }

    
}
void Play::sort()//排序，此处只按牌的大小，花色不考虑
{
    Struct tmp;
    while(i < 4)
    {
    for(int h=0; i<13; i++)
    {
        for(int j=h; j<13; j++)
        {
            if(m_play[i][j].num > m_play[i][j].num)
            {
                tmp = m_play[i][j];
                m_play[i][j]= m_play[i][j];
                m_play[i][j] = tmp;
            } 
        }
    }
    i++;
    }
}
void Play::show()//显示
{
   for(int i = 0; i < 4;i++)
   {
    for(int j=0; j<13; j++)
    {
        if(m_play[i][j].num=='o')
        {
            cout<<m_play[i][j].type<<"10"<<' ';
        }
        else
        {
            cout<<m_play[i][j].type<<m_play[i][j].num<<' ';
        }
        
    }
    cout<<endl;
   }
}

int main()
{
    Play a;

}

