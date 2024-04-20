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
		cout << "如想要购买随从，请按照 X 0 的格式进行输入，X代表想添加的随从类型\n";
		cout << "如想要购买Buff，请按照 X1 X2 的格式进行输入，X1代表想添加的随从编号,X2代表想要添加的Buff编号\n";
		cout << "*************************************************************************************************\n\n";
    	cout<<"准备阶段，请玩家购买随从和buff\n当前剩余金币:"<<GP_P<<"\n\n";
    	ShowMinions();
        cin>>x1>>x2;
        if(x2==0){
        	if(Buy_Minion(x1)==false){
        		cout<<"金币不足，请重新选择\n";
        		Sleep(Player::BuyRET);
        		continue;
			}
		}
		else{
			if(Buy_Buff(x1,x2)==false){
				cout<<"金币不足或者随从不存在，请重新选择\n";
				Sleep(Player::BuyRET);
				continue;
			}
		}
		REC[++REC[0]]=x1;
        REC[++REC[0]]=x2;
		cout<<"购买成功\n";
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
    cout<<"人机阵容已组成\n";
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
	cout<<"*0  刷新屏幕                                                   *\n";
	cout<<"*1  人机对战                                                   *\n";
	cout<<"*2  双人对战(热座模式)                                         *\n";
	cout<<"*3  游戏设置                                                   *\n";
	cout<<"*4  制作组                                                     *\n";
	cout<<"*5  重置所有设置                                               *\n";
	cout<<"*6  退出游戏                                                   *\n";
	if(c==5)cout<<"*7  开发者选项                                                 *\n";
	cout<<"****************************************************************\n\n\n";
}
void Shop(){
	cout << "***************************************************************" << endl;
	cout << "BUFF菜单：" << endl;
	for (int i = 1; i < 5; i++){
		cout<<setw(10) << "BUFF" << i ;
		cout <<setw(10) << "血量:" << setw(5) <<Buff::HP[i];
		cout <<setw(10) << "攻击加成:" << setw(5) <<Buff::ATK[i];
		cout <<setw(10) << "费用:" << setw(5) <<Buff::VLU[i];
		cout << endl;
	}
	cout << "随从菜单：" << endl;
	for (int j = 1; j < 11; j++){
		cout << setw(11) << "Minion" << j;
		cout << setw(11) << "血量:" <<setw(5) << Minion::HP[j];
		cout << setw(11) <<"攻击:" << setw(5)<< Minion::ATK[j];
		cout << setw(11) <<"费用:" <<setw(5) << Minion::VLU[j];
		cout << endl;
	}
	cout << "**************************************************************\n\n" << endl;
}
void Settings(){
	cout<<"********************************设置****************************\n";
	cout<<"*0 0  返回                                                     *\n";
	cout<<"*1 购买信息停留时长(default=500ms,now="<<Player::BuyRET<<")                     *\n";
	cout<<"*2 随从攻击信息停留时长(default=500ms,now="<<Player::FightRET1<<")                *\n";
	cout<<"*3 战斗回合间隔时长(default=500ms,now="<<Player::FightRET2<<")                    *\n";
	cout<<"*4 购买前是否自动刷新屏幕(default=0,now="<<int(Player::ATOBuyCLS)<<")                     *\n";
	cout<<"*5 战斗回合开始前是否自动刷新屏幕(default=0,now="<<int(Player::ATOFightCLS)<<")             *\n";
	cout<<"****************************************************************\n\n\n";
}
void Thanks(){
	cout<<"**************************制作人员名单**************************\n";
	cout<<"* 组长:杨奕开                                                  *\n";
	cout<<"* 组员:党昊天,文婷,李宗恒                                      *\n";
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
	cout<<"警告！本选项仅供开发使用，擅自改动下述选项可能导致程序出错，如出现任何问题请尝试重置所有设置\n\n";
	for(int i=10;i>=1;i--){
		cout<<i<<endl;
		Sleep(100);
	}
	cout<<"**************************开发人员选项**************************\n";
	cout<<"*0 0  返回                                                     *\n";
	cout<<"*1  修改随从初始数据(依次输入种类、血量、攻击和费用，其中-1表示不做改动)*\n";
	cout<<"*2  修改Buff初始数据(依次输入种类、血量、攻击和费用，其中-1表示不做改动)*\n";
	cout<<"*3  修改玩家初始金币和血量                                     *\n";
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
	int i = -1,j=-1;                        //i为1号玩家上一次进攻的随从，j为2号玩家的~
	int round=1;
	while (x1.h.NumNodes()>0&&x2.h.NumNodes()>0){ //双方必须都至少有一个随从在场
		if(Player::ATOFightCLS)system("cls");
		//cout<<"Round"<<round<<":\n";
		cout<<"P1:";
		x1.ShowMinions();
		cout<<"\nP2:";
		x2.ShowMinions();
		cout<<"\n\n";
		Sleep(Player::FightRET1);
		i++;                                //当前准备进攻的随从序号
		if(i>=x1.h.NumNodes())i=0;                            //如果之前是最后一个随时进攻则要回到第一个
		x1.h.Go(i);
		x2.h.Go(rand()%x2.h.NumNodes());        //从2号玩家的随从里随机挑选一个作为被攻击者
		Node<Minion> at =* x1.h.CurNode();
		Node<Minion>de=*x2.h.CurNode();       //判断攻击者攻击力与被攻击者的血量大小关系（攻击者同时也会承受被攻击者的反击）
		cout<<"P1: "<<i+1<<"->P2: "<<x2.h.CurPos()+1<<" "<<-at.GetData().GetATK_P()<<"\n\n\n";
		Sleep(Player::FightRET2);
		if (at.GetData().GetATK_P()>=de.GetData().GetHP_P())x2.h.DeleteCurNode();             //大于等于就将被攻击随从移除列表
		else x2.h.CurData().SetHP_P(de.GetData().GetHP_P() - at.GetData().GetATK_P());//小于就改变血量
		if (de.GetData().GetATK_P() >= at.GetData().GetHP_P())x1.h.DeleteCurNode();         //反击部分的执行同理
		else x1.h.CurData().SetHP_P(at.GetData().GetHP_P()-de.GetData().GetATK_P());
		if(Player::ATOFightCLS)system("cls");
		cout<<"P1:";
		x1.ShowMinions();
		cout<<"\nP2:";
		x2.ShowMinions();
		cout<<"\n\n";
		Sleep(Player::FightRET1);
		if (x2.h.NumNodes()==0||x1.h.NumNodes()==0)break;                      //此时如果2号玩家没有随从了就没必要进行下去了需要退出循环
		j++;                            //后面2号玩家为进攻者，同上
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
	if(x1.h.NumNodes()==0&&x2.h.NumNodes()==0)return 0;                        //如果双方都没有随从了就是平局，返回0
	if(x1.h.NumNodes()==0)return x2.h.NumNodes();                              //如果1号玩家没有随从了就返回一个正值（2号玩家剩余随从数量），代表一号玩家战败
	else return -x1.h.NumNodes();                                            //反之返回负值代表2号玩家战败
}
bool shuru(const std::string& filename) {
	std::ifstream file("sz.txt"); // 打开包含变量值的文件
	if (!file) {
		std::cout << "无法打开文件" << std::endl;
		return false;
	}
	std::cout << "输入文件正常\n\n";
	for (int i = 0; i <= 10; i++) {
		file >> Minion::HP[i];
	}

	// 从文件中读取Minion的ATK数组值
	for (int i = 0; i <= 10; i++) {
		file >> Minion::ATK[i];
	}

	// 从文件中读取Minion的VLU数组值
	for (int i = 0; i <= 10; i++) {
		file >> Minion::VLU[i];
	}

	// 从文件中读取Buff的HP数组值
	for (int i = 0; i <= 10; i++) {
		file >> Buff::HP[i];
	}

	// 从文件中读取Buff的ATK数组值
	for (int i = 0; i <= 10; i++) {
		file >> Buff::ATK[i];
	}

	// 从文件中读取Buff的VLU数组值
	for (int i = 0; i <= 10; i++) {
		file >> Buff::VLU[i];
	}

	// 从文件中读取Buff的DUR数组值
	for (int i = 0; i <= 10; i++) {
		file >> Buff::DUR[i];
	}
	// 从文件中读取Player的其他变量值
	file >> Player::GP;
	file >> Player::HP;
	file >> Player::BuyRET;
	file >> Player::FightRET1;
	file >> Player::FightRET2;
	file >> Player::ATOBuyCLS;
	file >> Player::ATOFightCLS;

	// 从文件中读取Minion的数组值
	for (int i = 0; i <= 10; i++) {
		file >> Minion::CHP[i];
	}

	for (int i = 0; i <= 10; i++) {
		file >> Minion::CATK[i];
	}

	for (int i = 0; i <= 10; i++) {
		file >> Minion::CVLU[i];
	}

	// 从文件中读取Buff的数组值
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
	file.close(); // 关闭文件
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
		std::cout << "无法打开文件" << fileName << std::endl;
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
		std::cout << "无法打开文件" << fileName << std::endl;
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
