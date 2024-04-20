#include"WarChess.h"
#include<stdlib.h>
#include<cstring>
#include <conio.h>
using namespace std;
int Minion::HP[11];        //初始血量
int Minion::ATK[11];	   //攻击
int Minion::VLU[11];       //费用
int Buff::HP[11];          //血量
int Buff::ATK[11];         //攻击加成
int Buff::VLU[11];         //费用
int Buff::DUR[11];         //持续回合
int Player::GP,Player::HP,Player::BuyRET,Player::FightRET1,Player::FightRET2;
bool Player::ATOBuyCLS,Player::ATOFightCLS;
int Minion::CHP[11];
int Minion::CATK[11];
int Minion::CVLU[11];
int Buff::CHP[11];
int Buff::CATK[11];
int Buff::CVLU[11];
int Buff::CDUR[11];
int Pause(const char* prompt = "按任意键继续……"){
    std::cout << prompt;
	return getch();
}
int main() {
	//std::string filename =("sz.txt"); // 打开包含变量值的文件
	shuru("sz.txt");
	srand(unsigned(time(NULL)));
	int x1, x2, x3, x4, x5, c = 0;
	bool e1 = true;
	while (e1) {
		bool e2 = true, e3 = true;
		Menu(c);
		cin >> x1;
		if (x1 == 0 && c != 5)c++;
		else if (c != 5)c = 0;
		switch (x1) {
			case 0:
				system("cls");
				continue;
				break;
			case 1:{
				Player *p=new Player;
				Player *robot=new Player;
				p->SetHP_P(Player::HP);
				robot->SetHP_P(Player::HP);
				while (p->GetHP_P() > 0 && robot->GetHP_P() > 0) {
					p->SetGP_P(Player::GP);
					robot->SetGP_P(Player::GP);
					cout << "玩家血量:" << p->GetHP_P() << endl;
					cout << "机器人血量:" << robot->GetHP_P() << endl;
					p->Create();
					robot->RobotCreate();
					robot->ShowMinions();
					cout << "玩家血量:" << p->GetHP_P() << endl;
					cout << "机器人血量:" << robot->GetHP_P() << endl;
					cout<<"\n\n";
					x2 = Fight(*p, *robot);
					if (x2 > 0)p->SetHP_P(p->GetHP_P() - x2);
					else robot->SetHP_P(robot->GetHP_P() + x2);
				}
				if (robot->GetHP_P() <= 0)cout << "你赢得最终胜利\n";
				if (p->GetHP_P() <= 0)cout << "人机获胜\n";
				delete p,robot;
				break;
			}
			case 2:{
				Player *p1=new Player;
				Player *p2=new Player;
				p1->SetHP_P(Player::HP);
				p2->SetHP_P(Player::HP);
				while (p1->GetHP_P() > 0 && p2->GetHP_P()>0) {
					p1->SetGP_P(Player::GP);
					p2->SetGP_P(Player::GP);
					Shop();
					cout << "玩家1血量:" << p1->GetHP_P() << endl;
					cout << "玩家2血量:" << p2->GetHP_P() << endl;
					cout << "战斗开始，请玩家1先进行操作\n";
					p1->Create();
					cout << "接下来由玩家2进行操作\n";
					p2->Create();
					cout << "双方准备完毕，战斗开始\n\n\n";
					x2 = Fight(*p1, *p2);
					if (x2 > 0)p1->SetHP_P(p1->GetHP_P() - x2);
					else p2->SetHP_P(p2->GetHP_P() + x2);
				}
				if (p1->GetHP_P() <= 0)cout << "玩家2获胜\n";
				if (p2->GetHP_P() <= 0)cout << "玩家1获胜\n";
				delete p1,p2;
				break;
			}
			case 3:
				Settings();
				while (e2) {
					cin >> x1 >> x2;
					switch (x1) {
					case 0:
						e2 = false;
						break;
					case 1:
						Player::BuyRET = x2;
						break;
					case 2:
						Player::FightRET1 = x2;
						break;
					case 3:
						Player::FightRET2 = x2;
						break;
					case 4:
						Player::ATOBuyCLS = x2;
						break;
					case 5:
						Player::ATOFightCLS = x2;
						break;
					}
				}
				WriteF();
				break;
			case 4:
				Thanks();
				break;
			case 5:
				ReSet();
				cout<<"所有设置均已重置为默认值\n\n";
				break;
			case 6:
				e1 = false;
				WriteF();
				break;
			case 7:
				if (c != 5)break;
				OP();
				while (e3) {
					cin >> x1;
					switch (x1) {
					case 0:
						e3 = false;
						break;
					case 1:
						Shop();
						cout << "请依次输入4个整数\n";
						cin >> x2 >> x3 >> x4 >> x5;
						if (x2 < 1 || x2>10) {
							cout << "你必须选择一个需要修改的随从类型\n";
							break;
						}
						if (x3 >= 0)Minion::HP[x2] = x3;
						if (x4 >= 0)Minion::ATK[x2] = x4;
						if (x5 >= 0)Minion::VLU[x2] = x5;
						Shop();
						break;
					case 2:
						Shop();
						cout << "请依次输入4个整数\n";
						cin >> x2 >> x3 >> x4 >> x5;
						if (x2 < 1 || x2>4) {
							cout << "你必须选择一个需要修改的Buff类型\n";
							break;
						}
						if (x3 >= 0)Buff::HP[x2] = x3;
						if (x4 >= 0)Buff::ATK[x2] = x4;
						if (x5 >= 0)Buff::VLU[x2] = x5;
						Shop();
						break;
					case 3:
						cout << "当前玩家初始金币:" << Player::GP << endl;
						cout << "当前玩家初始血量:" << Player::HP << endl;
						cin >> x2 >> x3;
						if (x2 >= 0)Player::GP = x2;
						if (x3 >= 0)Player::HP = x3;
						cout << "当前玩家初始金币:" << Player::GP << endl;
						cout << "当前玩家初始血量:" << Player::HP << endl;
						break;
					}
				}
				WriteF();
				break;
			}
	}
	WriteF();
}
