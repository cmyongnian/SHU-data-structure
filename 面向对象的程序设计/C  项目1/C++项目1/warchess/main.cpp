#include"WarChess.h"
#include<stdlib.h>
#include<cstring>
#include <conio.h>
using namespace std;
int Minion::HP[11];        //��ʼѪ��
int Minion::ATK[11];	   //����
int Minion::VLU[11];       //����
int Buff::HP[11];          //Ѫ��
int Buff::ATK[11];         //�����ӳ�
int Buff::VLU[11];         //����
int Buff::DUR[11];         //�����غ�
int Player::GP,Player::HP,Player::BuyRET,Player::FightRET1,Player::FightRET2;
bool Player::ATOBuyCLS,Player::ATOFightCLS;
int Minion::CHP[11];
int Minion::CATK[11];
int Minion::CVLU[11];
int Buff::CHP[11];
int Buff::CATK[11];
int Buff::CVLU[11];
int Buff::CDUR[11];
int Pause(const char* prompt = "���������������"){
    std::cout << prompt;
	return getch();
}
int main() {
	//std::string filename =("sz.txt"); // �򿪰�������ֵ���ļ�
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
					cout << "���Ѫ��:" << p->GetHP_P() << endl;
					cout << "������Ѫ��:" << robot->GetHP_P() << endl;
					p->Create();
					robot->RobotCreate();
					robot->ShowMinions();
					cout << "���Ѫ��:" << p->GetHP_P() << endl;
					cout << "������Ѫ��:" << robot->GetHP_P() << endl;
					cout<<"\n\n";
					x2 = Fight(*p, *robot);
					if (x2 > 0)p->SetHP_P(p->GetHP_P() - x2);
					else robot->SetHP_P(robot->GetHP_P() + x2);
				}
				if (robot->GetHP_P() <= 0)cout << "��Ӯ������ʤ��\n";
				if (p->GetHP_P() <= 0)cout << "�˻���ʤ\n";
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
					cout << "���1Ѫ��:" << p1->GetHP_P() << endl;
					cout << "���2Ѫ��:" << p2->GetHP_P() << endl;
					cout << "ս����ʼ�������1�Ƚ��в���\n";
					p1->Create();
					cout << "�����������2���в���\n";
					p2->Create();
					cout << "˫��׼����ϣ�ս����ʼ\n\n\n";
					x2 = Fight(*p1, *p2);
					if (x2 > 0)p1->SetHP_P(p1->GetHP_P() - x2);
					else p2->SetHP_P(p2->GetHP_P() + x2);
				}
				if (p1->GetHP_P() <= 0)cout << "���2��ʤ\n";
				if (p2->GetHP_P() <= 0)cout << "���1��ʤ\n";
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
				cout<<"�������þ�������ΪĬ��ֵ\n\n";
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
						cout << "����������4������\n";
						cin >> x2 >> x3 >> x4 >> x5;
						if (x2 < 1 || x2>10) {
							cout << "�����ѡ��һ����Ҫ�޸ĵ��������\n";
							break;
						}
						if (x3 >= 0)Minion::HP[x2] = x3;
						if (x4 >= 0)Minion::ATK[x2] = x4;
						if (x5 >= 0)Minion::VLU[x2] = x5;
						Shop();
						break;
					case 2:
						Shop();
						cout << "����������4������\n";
						cin >> x2 >> x3 >> x4 >> x5;
						if (x2 < 1 || x2>4) {
							cout << "�����ѡ��һ����Ҫ�޸ĵ�Buff����\n";
							break;
						}
						if (x3 >= 0)Buff::HP[x2] = x3;
						if (x4 >= 0)Buff::ATK[x2] = x4;
						if (x5 >= 0)Buff::VLU[x2] = x5;
						Shop();
						break;
					case 3:
						cout << "��ǰ��ҳ�ʼ���:" << Player::GP << endl;
						cout << "��ǰ��ҳ�ʼѪ��:" << Player::HP << endl;
						cin >> x2 >> x3;
						if (x2 >= 0)Player::GP = x2;
						if (x3 >= 0)Player::HP = x3;
						cout << "��ǰ��ҳ�ʼ���:" << Player::GP << endl;
						cout << "��ǰ��ҳ�ʼѪ��:" << Player::HP << endl;
						break;
					}
				}
				WriteF();
				break;
			}
	}
	WriteF();
}
