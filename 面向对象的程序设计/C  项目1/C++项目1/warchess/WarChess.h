#ifndef WARCHESS_H
#define WARCHESS_H
#include<iostream>
#include<ctime>
#include<windows.h>
#include"LinkList.h"
using namespace std;
class Buff{
	public:
		Buff(int kind=0,int DUR_P=999);
		int GetKind() const;
		void SetDUR_P(const int &x);
		void SetKind(const int& x);
		static int HP[11],ATK[11],DUR[11],VLU[11],CHP[11],CATK[11],CDUR[11],CVLU[11];//所有Buff类型的血量、攻击加成、持续回合数和费用 
	private:
		int kind,DUR_P;
};
class Minion{
	public:
		Minion(int kind=0,int HP_P=1,int ATK_P=1);
		int GetKind() const;
		int GetHP_P() const;
		int GetATK_P() const;
		LinkList<Buff> &GetHead();
		void SetKind(const int &x);
		void SetHP_P(const int &x);
		void SetATK_P(const int &x);
		void LoadBuff();
		static int HP[11],ATK[11],VLU[11],CHP[11],CATK[11],CVLU[11];//所有随从的初始血量、攻击和费用 
	private:
		int kind,HP_P,ATK_P;//该随从当前的血量和攻击 
		LinkList<Buff>h;
};
class Player{
	public:
		Player(int hP_P=20,int gP_P=10);
		int GetHP_P() const;
		int GetGP_P() const;
		int GetNumREC() const;
		LinkList<Minion>& GetHead();
		void SetHP_P(const int &x);
		void SetGP_P(const int &x);
		bool Buy_Minion(const int x1);
		bool Buy_Buff(const int x1,const int x2=0);
		void Create();
		void RobotCreate();
		void SetREC(const int x1,const int x2);
		void ShowMinions();
		friend int Fight(Player x1,Player x2);
		static int GP,HP,BuyRET,FightRET1,FightRET2;
		static bool ATOBuyCLS,ATOFightCLS;
	private:
		int HP_P,GP_P,REC[1001];//玩家当前剩余血量和金币数量 
		LinkList<Minion>h;
};
void Menu(int c);
void Shop();
void Settings();
void Thanks();
void ReSet();
void OP();
int Fight(Player x1,Player x2);
bool shuru(const std::string& filename);
void shuchu(const int* arr, int size, const std::string& fileName);
void shuchu1(const int&arr, const std::string& fileName);
void WriteF();
#endif
