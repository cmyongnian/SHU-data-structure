#include "child_parent_tree.h"
#include <iostream>

// 本研讨存储结构采取的是双亲孩子表示法
// 功能解释 1：初始化家谱树（文件中每一行存储一个人的各种信息，将其读入程序后调用增加结点的接口）
//			2: 显示家谱树（就普通的调用Display函数?）
//			3: 根据代号n，显示第n代人数及其姓名（层序遍历，只输出最后一行?）
//			4: 按照姓名查询，输出成员信息（本人，父母，孩子信息及代数）    *是否应该把代数加到每个人的个人信息中?
//			5：输入两人姓名，确定其关系（。。。）
//			6: 给某人添加孩子（基础的Insert函数）
//			7: 删除某人（后代的归结方法需要询问一下）
//			8: 修改某人的信息（基础的set函数）
// *最后文件流保存的时候还需遍历保存，因此数据文件的存储格式应与某一种遍历模式保持一致

using namespace std;
int main()
{
	cout << "正在载入家族成员信息..." << endl;
	ChildParentTree<string> fam_mem;

	ifstream file_fam;
	file_fam.open("mem.txt");
	if (!file_fam.is_open()) {
		cout << "mem.txt打开失败" << endl;
		return -1;
	}
	else
		cout << "mem.txt打开成功" << endl;
	int fa_num, num, gen;
	string nam, bir, mar, add, sta, dea;
	while (!file_fam.eof())
	{
		file_fam >> fa_num >> num >> nam >> bir >> mar >> add >> sta >> dea >> gen;
		fam_mem.InsertChild(fa_num, num, nam);
		fam_mem.SetNode(2, num, bir);
		fam_mem.SetNode(3, num, mar);
		fam_mem.SetNode(4, num, add);
		fam_mem.SetNode(5, num, sta);
		fam_mem.SetNode(6, num, dea);
		fam_mem.SetGen(num, gen);
	}
	file_fam.close();

	cout << "家庭成员信息载入完成！" << endl;
	system("pause");
	system("cls");

	while (1)
	{
		cout << "——家族管理系统——" << endl;
		cout << "1、显示家谱树" << endl;
		cout << "2、根据代数查询信息" << endl;
		cout << "3、根据姓名查询信息" << endl;
		cout << "4、查询关系" << endl;
		cout << "5、添加孩子信息（请搭配修改信息使用）" << endl;
		cout << "6、删除某人信息" << endl;
		cout << "7、修改某人信息" << endl;
		cout << "8、保存成员信息" << endl;
		cout << "0、退出系统" << endl;
		cout << "请选择..." << endl;
		int flag1, flag2 = 1;
		int Gen,num;
		string Nam, Nam1, Nam2, Bir, Mar, Add, Sta, Dea, Gener;
		cin >> flag1;
		switch (flag1)
		{
		case 0:
			cout << "感谢您的使用！" << endl;
			system("pause");
			return 0;
		case 1:
			fam_mem.DisplayTWithConcaveShape(fam_mem);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "请输入要查询的代数：" << endl;
			cin >> Gen;
			cout << endl;
			fam_mem.Generation(fam_mem, Gen);
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "请输入要查询的姓名：" << endl;
			cin >> Nam;
			if (fam_mem.OutNode(Nam) == SUCCESS);
			else
				cout << "此人不存在于家谱树中" << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "姓名1：";
			cin >> Nam1;
			cout << "姓名2：";
			cin >> Nam2;
			fam_mem.Relation(Nam1, Nam2);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "请输入添加的孩子信息：" << endl;
			cout << "双亲编号：";
			cin >> num;
			cout << "孩子姓名：";
			cin >> Nam;
			if (fam_mem.IfExist(Nam) == 1)
				cout << "该成员已存在" << endl;
			else
				fam_mem.InsertChild(num, fam_mem.NodeCount(), Nam);
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "请输入需删除的姓名：";
			cin >> Nam;
			if (fam_mem.DeleteMember(fam_mem, Nam) == SUCCESS)
				cout << "删除成功" << endl;
			else
				cout << "删除失败" << endl;
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "请输入修改信息：" << endl;
			cout << "序号：";
			cin >> num;
			cout << endl;
			while (flag2 != 0)
			{
				cout << "1、修改姓名" << endl;
				cout << "2、修改出生日期" << endl;
				cout << "3、修改婚姻状况" << endl;
				cout << "4、修改地址" << endl;
				cout << "5、修改目前状态" << endl;
				cout << "6、修改死亡日期" << endl;
				cout << "0、退出修改" << endl;
				cin >> flag2;
				switch (flag2)
				{
				case 1:
					cout << "修改后的姓名：";
					cin >> Nam;
					fam_mem.SetNode(flag2, num, Nam);
					cout << endl << "修改成功";
					break;
				case 2:
					cout << "修改后的出生日期：";
					cin >> Bir;
					fam_mem.SetNode(flag2, num, Bir);
					cout << endl << "修改成功";
					break;
				case 3:
					cout << "修改后的婚姻状况：";
					cin >> Mar;
					fam_mem.SetNode(flag2, num, Mar);
					cout << endl << "修改成功";
					break;
				case 4:
					cout << "修改后的地址：";
					cin >> Add;
					fam_mem.SetNode(flag2, num, Add);
					cout << endl << "修改成功";
					break;
				case 5:
					cout << "修改后的目前状况：";
					cin >> Sta;
					fam_mem.SetNode(flag2, num, Sta);
					cout << endl << "修改成功";
					break;
				case 6:
					cout << "修改后的死亡日期：";
					cin >> Dea;
					fam_mem.SetNode(flag2, num, Dea);
					cout << endl << "修改成功";
					break;
				case 7:
					cout << "修改后的代数：";
					cin >> Gen;
					fam_mem.SetGen(num, Gen);
					cout << endl << "修改成功";
				case 0:
					break;
				default:
					cout << "您的输入有误，请重新输入！" << endl;
					break;
				}
			}
			system("pause");
			system("cls");
			break;
		case 8:
			cout << "正在保存家族成员信息至本地文件..." << endl;
			if (fam_mem.Save())
				cout << "保存成功！" << endl;
			else
				cout << "保存失败！" << endl;
			system("pause");
			system("cls");
			break;
		default:
			cout << "您的输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
