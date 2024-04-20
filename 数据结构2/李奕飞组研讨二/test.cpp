#include "AdjMatUndirGra.h"
#include <iostream>

using namespace std;

//注：public中的函数都是可以对外使用的 privated里面的可能需要根据情况改造

int main()
{
	int count = 0;
	pair<int, int> maxnn[100]  ;
	pair<int, int> m;


	cout << "正在载入社交网络信息..." << endl;

	ifstream file_net;
	file_net.open("friend.txt");
	if (!file_net.is_open()) {
		cout << "friend.txt打开失败" << endl;
		return -1;
	}
	else
		cout << "奋力誊写数据中";
	int vexMaxNumt, vexNumt = 0;
	string n1;
	file_net >> vexMaxNumt;
	string *n = new string[vexMaxNumt];
	for (int i = 0; i < vexMaxNumt; i++)
	{
		n[i] = "0";
	}
	file_net >> n1;
	n[vexNumt] = n1;
	vexNumt++;
	while (!file_net.eof())
	{
		file_net >> n1;
		if (SearchName(n, n1))
		{
			n[vexNumt] = n1;
			vexNumt++;
		}
		file_net >> n1;
		if (file_net.eof())
		{
			break;
		}
		file_net >> n1;
		if (SearchName(n, n1))
		{
			n[vexNumt] = n1;
			vexNumt++;
		}
	}
	file_net.close();
	cout << "......" << endl;


	file_net.open("friend.txt");
	if (!file_net.is_open()) {
		cout << "friend.txt打开失败" << endl;
		return -1;
	}
	else
		cout << "friend.txt打开成功!" << endl;
	int vexMaxNum, vexNum = vexNumt, weight;
	string *name = new string[vexNum];
	for (int t = 0; n[t] != "0"; t++)
	{
		name[t] = n[t];
	}
	file_net >> vexMaxNum;
	AdjMatrixUndirGraph net(name, vexNum, vexMaxNum);
	string n2, n3;
	while(!file_net.eof())
	{
		file_net >> n2 >> n3 >> weight;
		if(n2!=n3)
		net.InsertArc(net.Trans(n2), net.Trans(n3), weight);
		
	}
	file_net.close();

	while (1)
	{
		cout << "——社交网络——" << endl;
		cout << "1、显示当前社交网络" << endl;
		cout << "2、查询两人关系链(<-)" << endl;
		cout << "3、增删用户" << endl;
		cout << "4、增删用户关系" << endl;
		cout << "5、查找潜在小团体" << endl;
		cout << "6、寻找最佳信息投放点" << endl;
		cout << "7、小挑战" << endl;
		cout << "8、保存网络信息" << endl;
		cout << "0、退出系统" << endl;
		cout << "请选择..." << endl;
		int choice, C3c, C4c, C4weight, Threshold;
		string Nam1, Nam2, C3Name, C4Name1, C4Name2;
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "感谢您的使用！" << endl;
			return 0;

		case 1:
			net.Display();
			cout << endl;
			system("pause");
			system("cls");
			break;

		case 2:
			cout << "请输入查询用户一：" << endl;
			cin >> Nam1;
			cout << "请输入查询用户二：" << endl;
			cin >> Nam2;
			if (net.IsLegal(Nam1) && net.IsLegal(Nam2))
			{
				if (Nam1 == Nam2)
				{
					cout << "自己和自己要保持和睦哦。" << endl;;
					system("pause");
					system("cls");
				}
				else
				{
					net.DisplayPath(Nam1, Nam2);
					cout << endl;
					system("pause");
					system("cls");
				}
			}
			else
			{
				cout << "该用户不存在。" << endl;
				system("pause");
				system("cls");
			}
			break;

		case 3:
			cout << "——增删用户——" << endl;
			cout << "1、增加用户" << endl;
			cout << "2、删除用户" << endl;
			cout << "请选择..." << endl;
			cin >> C3c;
			switch (C3c)
			{
			case 1:
				cout << "请输入待增加用户名：" << endl;
				cin >> C3Name;
				if (!net.IsLegal(C3Name))
				{
					net.InsertVex(C3Name);
					cout << endl;
					system("pause");
					system("cls");
				}
				else
				{
					cout << "该用户已存在。" << endl;
					system("pause");
					system("cls");
				}
				break;

			case 2:
				cout << "请输入待删除用户名：" << endl;
				cin >> C3Name;
				if (net.IsLegal(C3Name))
				{
					net.DeleteVex(C3Name);
					cout << endl;
					system("pause");
					system("cls");
				}
				else
				{
					cout << "该用户不存在。" << endl;
					system("pause");
					system("cls");
				}
				break;
			}
			break;

		case 4:
			cout << "——增删用户关系——" << endl;
			cout << "1、增加用户关系" << endl;
			cout << "2、删除用户关系" << endl;
			cout << "请选择..." << endl;
			cin >> C4c;
			switch (C4c)
			{
			case 1:
				cout << "请输入待增加用户名一：" << endl;
				cin >> C4Name1;
				cout << "请输入待增加用户名二：" << endl;
				cin >> C4Name2;
				cout << "请输入二者之间的亲密度：" << endl;
				cin >> C4weight;
				if (net.IsLegal(C4Name1) && net.IsLegal(C4Name2))
				{
					net.InsertArc(net.Trans(C4Name1), net.Trans(C4Name2), C4weight);
					cout << endl;
					system("pause");
					system("cls");
				}
				else
				{
					cout << "该用户不存在。" << endl;
					system("pause");
					system("cls");
				}
				break;
			case 2:
				cout << "请输入待删除用户名一：" << endl;
				cin >> C4Name1;
				cout << "请输入待删除用户名二：" << endl;
				cin >> C4Name2;
				if (net.IsLegal(C4Name1) && net.IsLegal(C4Name2))
				{
					net.DeleteArc(net.Trans(C4Name1), net.Trans(C4Name2));
					cout << endl;
					system("pause");
					system("cls");
				}
				else
				{
					cout << "该用户不存在。" << endl;
					system("pause");
					system("cls");
				}
				break;
			}
			break;

		case 5:
			cout << "请输入查找阈值：" << endl;
			cin >> Threshold;
			net.SmallGroup(Threshold);
			cout << endl;
			system("pause");
			system("cls");
			break;

		case 6:
			
			net.Max_Span_Forest(count, maxnn);
			for (int i = 0; i < count; i++) {
				cout << "第" << i + 1 << "个投放人为";
				cout << net.Trans(maxnn[i].second);
				cout << ",最大亲密度为" << maxnn[i].first << endl;
			}
			count = 0;
			system("pause");
			system("cls");
			break;

		case 7:

			
			net.Max_line(m);
			
			cout << "最大权重"<<m.first << endl;
			cout << "开始节点"<<net.Trans(m.second);
			cout << endl;
			system("pause");
			system("cls");
			break;

		case 8:
			cout << "正在保存社交网络信息至本地文件..." << endl;
			if (net.Save())
				cout << "保存成功！" << endl;
			else
				cout << "保存失败！" << endl;
			break;
		//case 9:
		//	net.DisplayFloyd();
		//	system("pause");
		//	system("cls");
		//	break;
		}
	}
}