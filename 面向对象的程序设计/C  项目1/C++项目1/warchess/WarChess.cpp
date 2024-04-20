#include"WarChess.h"
#include<iomanip>
using namespace std;
Buff::Buff(int kind, int DUR_P):kind(kind),DUR_P(DUR_P){}
int Buff::GetKind() const{
	return kind;
}
void Buff::SetDUR_P(const int &x){
	DUR_P=x;
}
void Buff::SetKind(const int& x){
	 kind=x;
}
Minion::Minion(int kind, int HP_P, int ATK_P):kind(kind),HP_P(HP_P),ATK_P(ATK_P){}
int Minion::GetKind() const{
	return kind;
}
int Minion::GetHP_P() const{
	return HP_P;
}
int Minion::GetATK_P() const{
	return ATK_P;
}
LinkList<Buff>& Minion::GetHead(){
	return h;
}
void Minion::SetKind(const int &x){
	kind=x;
}
void Minion::SetHP_P(const int &x){
	HP_P=x;
}
void Minion::SetATK_P(const int &x){
	ATK_P=x;
}
void Minion::LoadBuff(){
	for (int i = 0; i < h.NumNodes(); i++) {
		h.Go(i);
		ATK_P+=Buff::ATK[h.CurData().GetKind()];
		HP_P+=Buff::HP[h.CurData().GetKind()];
	}
}
Player::Player(int HP_P, int gP_P):HP_P(HP),GP_P(GP){REC[0]=0;}
int Player::GetHP_P() const{
	return HP_P;
}
int Player::GetGP_P() const{
	return GP_P;
}
int Player::GetNumREC() const{
	return REC[0];
}
LinkList<Minion>& Player::GetHead(){
	return h;
}
void Player::SetHP_P(const int &x){
	HP_P=x;
}
void Player::SetGP_P(const int &x){
	GP_P=x;
}
bool Player::Buy_Minion(const int x1){
        if(Minion::VLU[x1]>GP_P)return false;
		GP_P-=Minion::VLU[x1];
		Minion *t=new Minion;
		t->SetATK_P(Minion::ATK[x1]);
		t->SetHP_P(Minion::HP[x1]);
		t->SetKind(x1);
		h.Append(*t);
		return true;
}
bool Player::Buy_Buff(const int x1,const int x2){
    if(Buff::VLU[x2]>GP_P||x1>h.NumNodes())return false;
    GP_P-=Buff::VLU[x2];
	Buff *t=new Buff;
	t->SetDUR_P(Buff::DUR[x2]);
	t->SetKind(x2);
	h.Go(x1-1);
	h.CurData().GetHead().Append(*t);
	return true;
}
void Player::Create(){
	int x1,x2;
    while (GetGP_P()>0){
    	if(ATOBuyCLS)system("cls");
    	Shop();
    	cout << "*************************************************************************************************\n";
		cout << "����Ҫ������ӣ��밴�� X 0 �ĸ�ʽ�������룬X��������ӵ��������\n";
		cout << "����Ҫ����Buff���밴�� X1 X2 �ĸ�ʽ�������룬X1��������ӵ���ӱ��,X2������Ҫ��ӵ�Buff���\n";
		cout << "*************************************************************************************************\n\n";
    	cout<<"׼���׶Σ�����ҹ�����Ӻ�buff\n��ǰʣ����:"<<GP_P<<"\n\n";
    	ShowMinions();
        cin>>x1>>x2;
        if(x2==0){
        	if(Buy_Minion(x1)==false){
        		cout<<"��Ҳ��㣬������ѡ��\n";
        		Sleep(Player::BuyRET);
        		continue;
			}
		}
		else{
			if(Buy_Buff(x1,x2)==false){
				cout<<"��Ҳ��������Ӳ����ڣ�������ѡ��\n";
				Sleep(Player::BuyRET);
				continue;
			}
		}
		REC[++REC[0]]=x1;
        REC[++REC[0]]=x2;
		cout<<"����ɹ�\n";
		Sleep(Player::BuyRET);
    }
}
void Player::RobotCreate(){
    int x1,x2;
    while (GetGP_P()>0){
        x2=rand()%5;
        if(x2==0){
            x1=rand()%10+1;
        	if(Buy_Minion(x1)==false)continue;
		}
		else{
			if(h.NumNodes()==0)continue;
            x1=rand()%h.NumNodes()+1;
			if(Buy_Buff(x1,x2)==false)continue;
		}
		REC[++REC[0]]=x1;
        REC[++REC[0]]=x2;
    }
    cout<<"�˻����������\n";
}
void Player::SetREC(const int x1,const int x2){
	REC[x1]=x2;
}
void Player::ShowMinions(){
	if(h.NumNodes()==0){
		cout<<endl;
		return;
	}
	for(int i=0;i<h.NumNodes();i++){
		h.Go(i);
		cout<<i+1<<"."<<h.CurData().GetKind()<<"("<<h.CurData().GetATK_P()<<","<<h.CurData().GetHP_P()<<")[";
		for (int j = 0; j < h.CurData().GetHead().NumNodes(); j++) {
			h.CurData().GetHead().Go(j);
			cout <<h.CurData().GetHead().CurData().GetKind()<<",";
		}
		cout << "];";
	}
	cout<<endl;
}
void Menu(int c){
	cout<<"***********************WarChess*********************************\n";
	cout<<"*0  ˢ����Ļ                                                   *\n";
	cout<<"*1  �˻���ս                                                   *\n";
	cout<<"*2  ˫�˶�ս(����ģʽ)                                         *\n";
	cout<<"*3  ��Ϸ����                                                   *\n";
	cout<<"*4  ������                                                     *\n";
	cout<<"*5  ������������                                               *\n";
	cout<<"*6  �˳���Ϸ                                                   *\n";
	if(c==5)cout<<"*7  ������ѡ��                                                 *\n";
	cout<<"****************************************************************\n\n\n";
}
void Shop(){
	cout << "***************************************************************" << endl;
	cout << "BUFF�˵���" << endl;
	for (int i = 1; i < 5; i++){
		cout<<setw(10) << "BUFF" << i ;
		cout <<setw(10) << "Ѫ��:" << setw(5) <<Buff::HP[i];
		cout <<setw(10) << "�����ӳ�:" << setw(5) <<Buff::ATK[i];
		cout <<setw(10) << "����:" << setw(5) <<Buff::VLU[i];
		cout << endl;
	}
	cout << "��Ӳ˵���" << endl;
	for (int j = 1; j < 11; j++){
		cout << setw(11) << "Minion" << j;
		cout << setw(11) << "Ѫ��:" <<setw(5) << Minion::HP[j];
		cout << setw(11) <<"����:" << setw(5)<< Minion::ATK[j];
		cout << setw(11) <<"����:" <<setw(5) << Minion::VLU[j];
		cout << endl;
	}
	cout << "**************************************************************\n\n" << endl;
}
void Settings(){
	cout<<"********************************����****************************\n";
	cout<<"*0 0  ����                                                     *\n";
	cout<<"*1 ������Ϣͣ��ʱ��(default=500ms,now="<<Player::BuyRET<<")                     *\n";
	cout<<"*2 ��ӹ�����Ϣͣ��ʱ��(default=500ms,now="<<Player::FightRET1<<")                *\n";
	cout<<"*3 ս���غϼ��ʱ��(default=500ms,now="<<Player::FightRET2<<")                    *\n";
	cout<<"*4 ����ǰ�Ƿ��Զ�ˢ����Ļ(default=0,now="<<int(Player::ATOBuyCLS)<<")                     *\n";
	cout<<"*5 ս���غϿ�ʼǰ�Ƿ��Զ�ˢ����Ļ(default=0,now="<<int(Player::ATOFightCLS)<<")             *\n";
	cout<<"****************************************************************\n\n\n";
}
void Thanks(){
	cout<<"**************************������Ա����**************************\n";
	cout<<"* �鳤:���ȿ�                                                  *\n";
	cout<<"* ��Ա:�����,����,���ں�                                      *\n";
	cout<<"****************************************************************\n\n\n";
	Sleep(5000);
}
void ReSet(){
	for(int i=0;i<=10;i++){
		Minion::HP[i]=Minion::CHP[i];
		Minion::ATK[i]=Minion::CATK[i];
		Minion::VLU[i]=Minion::CVLU[i];
		Buff::HP[i]=Buff::CHP[i];
		Buff::ATK[i]=Buff::CATK[i];
		Buff::VLU[i]=Buff::CVLU[i];
		Buff::DUR[i]=Buff::CDUR[i];
	}
	Player::GP=10;Player::HP=5;Player::BuyRET=500;Player::FightRET1=500;Player::FightRET2=500;
	Player::ATOBuyCLS=false;Player::ATOFightCLS=false;
}
void OP(){
	cout<<"���棡��ѡ���������ʹ�ã����ԸĶ�����ѡ����ܵ��³������������κ������볢��������������\n\n";
	for(int i=10;i>=1;i--){
		cout<<i<<endl;
		Sleep(100);
	}
	cout<<"**************************������Աѡ��**************************\n";
	cout<<"*0 0  ����                                                     *\n";
	cout<<"*1  �޸���ӳ�ʼ����(�����������ࡢѪ���������ͷ��ã�����-1��ʾ�����Ķ�)*\n";
	cout<<"*2  �޸�Buff��ʼ����(�����������ࡢѪ���������ͷ��ã�����-1��ʾ�����Ķ�)*\n";
	cout<<"*3  �޸���ҳ�ʼ��Һ�Ѫ��                                     *\n";
	cout<<"****************************************************************\n\n\n";
}
int Fight(Player x1,Player x2){
	for (int i = 0; i < x1.h.NumNodes(); i++){
		x1.h.Go(i);
		x1.h.CurData().LoadBuff();
	}
	for (int i = 0; i < x2.h.NumNodes(); i++){
		x2.h.Go(i);
		x2.h.CurData().LoadBuff();
	}
	int i = -1,j=-1;                        //iΪ1�������һ�ν�������ӣ�jΪ2����ҵ�~
	int round=1;
	while (x1.h.NumNodes()>0&&x2.h.NumNodes()>0){ //˫�����붼������һ������ڳ�
		if(Player::ATOFightCLS)system("cls");
		//cout<<"Round"<<round<<":\n";
		cout<<"P1:";
		x1.ShowMinions();
		cout<<"\nP2:";
		x2.ShowMinions();
		cout<<"\n\n";
		Sleep(Player::FightRET1);
		i++;                                //��ǰ׼��������������
		if(i>=x1.h.NumNodes())i=0;                            //���֮ǰ�����һ����ʱ������Ҫ�ص���һ��
		x1.h.Go(i);
		x2.h.Go(rand()%x2.h.NumNodes());        //��2����ҵ�����������ѡһ����Ϊ��������
		Node<Minion> at =* x1.h.CurNode();
		Node<Minion>de=*x2.h.CurNode();       //�жϹ����߹������뱻�����ߵ�Ѫ����С��ϵ��������ͬʱҲ����ܱ������ߵķ�����
		cout<<"P1: "<<i+1<<"->P2: "<<x2.h.CurPos()+1<<" "<<-at.GetData().GetATK_P()<<"\n\n\n";
		Sleep(Player::FightRET2);
		if (at.GetData().GetATK_P()>=de.GetData().GetHP_P())x2.h.DeleteCurNode();             //���ڵ��ھͽ�����������Ƴ��б�
		else x2.h.CurData().SetHP_P(de.GetData().GetHP_P() - at.GetData().GetATK_P());//С�ھ͸ı�Ѫ��
		if (de.GetData().GetATK_P() >= at.GetData().GetHP_P())x1.h.DeleteCurNode();         //�������ֵ�ִ��ͬ��
		else x1.h.CurData().SetHP_P(at.GetData().GetHP_P()-de.GetData().GetATK_P());
		if(Player::ATOFightCLS)system("cls");
		cout<<"P1:";
		x1.ShowMinions();
		cout<<"\nP2:";
		x2.ShowMinions();
		cout<<"\n\n";
		Sleep(Player::FightRET1);
		if (x2.h.NumNodes()==0||x1.h.NumNodes()==0)break;                      //��ʱ���2�����û������˾�û��Ҫ������ȥ����Ҫ�˳�ѭ��
		j++;                            //����2�����Ϊ�����ߣ�ͬ��
		if(j>=x2.h.NumNodes())j=0;
		x2.h.Go(j);
		x1.h.Go(rand() % x1.h.NumNodes());
		at = *x2.h.CurNode();
		de =*x1.h.CurNode();
		cout<<"P2: "<<i+1<<"->P1: "<<x2.h.CurPos()+1<<" "<<-at.GetData().GetATK_P()<<"\n\n\n";
		Sleep(Player::FightRET2);
		if (at.GetData().GetATK_P() >= de.GetData().GetHP_P())x1.h.DeleteCurNode();
		else x1.h.CurData().SetHP_P(de.GetData().GetHP_P()-at.GetData().GetATK_P());
		if (de.GetData().GetATK_P() >= at.GetData().GetHP_P())x2.h.DeleteCurNode();
		else x2.h.CurData().SetHP_P(at.GetData().GetHP_P()-de.GetData().GetATK_P());
        round++;
    }
	if(x1.h.NumNodes()==0&&x2.h.NumNodes()==0)return 0;                        //���˫����û������˾���ƽ�֣�����0
	if(x1.h.NumNodes()==0)return x2.h.NumNodes();                              //���1�����û������˾ͷ���һ����ֵ��2�����ʣ�����������������һ�����ս��
	else return -x1.h.NumNodes();                                            //��֮���ظ�ֵ����2�����ս��
}
bool shuru(const std::string& filename) {
	std::ifstream file("sz.txt"); // �򿪰�������ֵ���ļ�
	if (!file) {
		std::cout << "�޷����ļ�" << std::endl;
		return false;
	}
	std::cout << "�����ļ�����\n\n";
	for (int i = 0; i <= 10; i++) {
		file >> Minion::HP[i];
	}

	// ���ļ��ж�ȡMinion��ATK����ֵ
	for (int i = 0; i <= 10; i++) {
		file >> Minion::ATK[i];
	}

	// ���ļ��ж�ȡMinion��VLU����ֵ
	for (int i = 0; i <= 10; i++) {
		file >> Minion::VLU[i];
	}

	// ���ļ��ж�ȡBuff��HP����ֵ
	for (int i = 0; i <= 10; i++) {
		file >> Buff::HP[i];
	}

	// ���ļ��ж�ȡBuff��ATK����ֵ
	for (int i = 0; i <= 10; i++) {
		file >> Buff::ATK[i];
	}

	// ���ļ��ж�ȡBuff��VLU����ֵ
	for (int i = 0; i <= 10; i++) {
		file >> Buff::VLU[i];
	}

	// ���ļ��ж�ȡBuff��DUR����ֵ
	for (int i = 0; i <= 10; i++) {
		file >> Buff::DUR[i];
	}
	// ���ļ��ж�ȡPlayer����������ֵ
	file >> Player::GP;
	file >> Player::HP;
	file >> Player::BuyRET;
	file >> Player::FightRET1;
	file >> Player::FightRET2;
	file >> Player::ATOBuyCLS;
	file >> Player::ATOFightCLS;

	// ���ļ��ж�ȡMinion������ֵ
	for (int i = 0; i <= 10; i++) {
		file >> Minion::CHP[i];
	}

	for (int i = 0; i <= 10; i++) {
		file >> Minion::CATK[i];
	}

	for (int i = 0; i <= 10; i++) {
		file >> Minion::CVLU[i];
	}

	// ���ļ��ж�ȡBuff������ֵ
	for (int i = 0; i <= 10; i++) {
		file >> Buff::CHP[i];
	}

	for (int i = 0; i <= 10; i++) {
		file >> Buff::CATK[i];
	}

	for (int i = 0; i <= 10; i++) {
		file >> Buff::CVLU[i];
	}

	for (int i = 0; i <= 10; i++) {
		file >> Buff::CDUR[i];
	}
	file.close(); // �ر��ļ�
	return true;
}
void shuchu(const int* arr, int size, const std::string& fileName) {
	std::ofstream outputFile ("sz.txt", std::ios_base::app);
		if (outputFile.is_open()) {
			for (int i = 0; i < size; i++) {
				outputFile << arr[i];
				if (i != size - 1) {
					outputFile << " ";
				}
			}
			outputFile << "\n";
			outputFile.close();
	}
	else {
		std::cout << "�޷����ļ�" << fileName << std::endl;
	}
}
void shuchu1(const int&arr, const std::string& fileName) {
	std::ofstream outputFile("sz.txt", std::ios_base::app);
	if (outputFile.is_open()) {
			outputFile << arr;
		outputFile << "\n";
		outputFile.close();
	}
	else {
		std::cout << "�޷����ļ�" << fileName << std::endl;
	}
}
void WriteF(){
	std::ofstream outputFile ("sz.txt", std::ios_base::trunc);
	outputFile.close();
	shuchu(Minion::HP, sizeof(Minion::HP) / sizeof(int), "sc.txt");
	shuchu(Minion::ATK, sizeof(Minion::ATK) / sizeof(int), "sc.txt");
	shuchu(Minion::VLU, sizeof(Minion::VLU) / sizeof(int), "D:/sc.txt");
	shuchu(Buff::HP, sizeof(Buff::HP) / sizeof(int), "sc.txt");
	shuchu(Buff::ATK, sizeof(Buff::ATK) / sizeof(int), "sc.txt");
	shuchu(Buff::VLU, sizeof(Buff::VLU) / sizeof(int), "sc.txt");
	shuchu(Buff::DUR, sizeof(Buff::DUR) / sizeof(int), "sc.txt");
	shuchu1(Player::GP, "sc.txt");
	shuchu1(Player::HP, "sc.txt");
	shuchu1(Player::BuyRET, "sc.txt");
	shuchu1(Player::FightRET1, "sc.txt");
	shuchu1(Player::FightRET2, "sc.txt");
	shuchu1(Player::ATOBuyCLS, "sc.txt");
	shuchu1(Player::ATOFightCLS, "sc.txt");
	shuchu(Minion::CHP, sizeof(Minion::CHP) / sizeof(int), "sc.txt");
	shuchu(Minion::CATK, sizeof(Minion::CATK) / sizeof(int), "sc.txt");
	shuchu(Minion::CVLU, sizeof(Minion::CVLU) / sizeof(int), "sc.txt");
	shuchu(Buff::CHP, sizeof(Buff::CHP) / sizeof(int), "sc.txt");
	shuchu(Buff::CATK, sizeof(Buff::CATK) / sizeof(int), "sc.txt");
	shuchu(Buff::CVLU, sizeof(Buff::CVLU) / sizeof(int), "sc.txt");
	shuchu(Buff::CDUR, sizeof(Buff::CDUR) / sizeof(int), "sc.txt");
}
