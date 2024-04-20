#include "AdjMatUndirGra.h"
#include <iostream>

using namespace std;

//ע��public�еĺ������ǿ��Զ���ʹ�õ� privated����Ŀ�����Ҫ�����������

int main()
{
	int count = 0;
	pair<int, int> maxnn[100]  ;
	pair<int, int> m;


	cout << "���������罻������Ϣ..." << endl;

	ifstream file_net;
	file_net.open("friend.txt");
	if (!file_net.is_open()) {
		cout << "friend.txt��ʧ��" << endl;
		return -1;
	}
	else
		cout << "������д������";
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
		cout << "friend.txt��ʧ��" << endl;
		return -1;
	}
	else
		cout << "friend.txt�򿪳ɹ�!" << endl;
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
		cout << "�����罻���硪��" << endl;
		cout << "1����ʾ��ǰ�罻����" << endl;
		cout << "2����ѯ���˹�ϵ��(<-)" << endl;
		cout << "3����ɾ�û�" << endl;
		cout << "4����ɾ�û���ϵ" << endl;
		cout << "5������Ǳ��С����" << endl;
		cout << "6��Ѱ�������ϢͶ�ŵ�" << endl;
		cout << "7��С��ս" << endl;
		cout << "8������������Ϣ" << endl;
		cout << "0���˳�ϵͳ" << endl;
		cout << "��ѡ��..." << endl;
		int choice, C3c, C4c, C4weight, Threshold;
		string Nam1, Nam2, C3Name, C4Name1, C4Name2;
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "��л����ʹ�ã�" << endl;
			return 0;

		case 1:
			net.Display();
			cout << endl;
			system("pause");
			system("cls");
			break;

		case 2:
			cout << "�������ѯ�û�һ��" << endl;
			cin >> Nam1;
			cout << "�������ѯ�û�����" << endl;
			cin >> Nam2;
			if (net.IsLegal(Nam1) && net.IsLegal(Nam2))
			{
				if (Nam1 == Nam2)
				{
					cout << "�Լ����Լ�Ҫ���ֺ���Ŷ��" << endl;;
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
				cout << "���û������ڡ�" << endl;
				system("pause");
				system("cls");
			}
			break;

		case 3:
			cout << "������ɾ�û�����" << endl;
			cout << "1�������û�" << endl;
			cout << "2��ɾ���û�" << endl;
			cout << "��ѡ��..." << endl;
			cin >> C3c;
			switch (C3c)
			{
			case 1:
				cout << "������������û�����" << endl;
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
					cout << "���û��Ѵ��ڡ�" << endl;
					system("pause");
					system("cls");
				}
				break;

			case 2:
				cout << "�������ɾ���û�����" << endl;
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
					cout << "���û������ڡ�" << endl;
					system("pause");
					system("cls");
				}
				break;
			}
			break;

		case 4:
			cout << "������ɾ�û���ϵ����" << endl;
			cout << "1�������û���ϵ" << endl;
			cout << "2��ɾ���û���ϵ" << endl;
			cout << "��ѡ��..." << endl;
			cin >> C4c;
			switch (C4c)
			{
			case 1:
				cout << "������������û���һ��" << endl;
				cin >> C4Name1;
				cout << "������������û�������" << endl;
				cin >> C4Name2;
				cout << "���������֮������ܶȣ�" << endl;
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
					cout << "���û������ڡ�" << endl;
					system("pause");
					system("cls");
				}
				break;
			case 2:
				cout << "�������ɾ���û���һ��" << endl;
				cin >> C4Name1;
				cout << "�������ɾ���û�������" << endl;
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
					cout << "���û������ڡ�" << endl;
					system("pause");
					system("cls");
				}
				break;
			}
			break;

		case 5:
			cout << "�����������ֵ��" << endl;
			cin >> Threshold;
			net.SmallGroup(Threshold);
			cout << endl;
			system("pause");
			system("cls");
			break;

		case 6:
			
			net.Max_Span_Forest(count, maxnn);
			for (int i = 0; i < count; i++) {
				cout << "��" << i + 1 << "��Ͷ����Ϊ";
				cout << net.Trans(maxnn[i].second);
				cout << ",������ܶ�Ϊ" << maxnn[i].first << endl;
			}
			count = 0;
			system("pause");
			system("cls");
			break;

		case 7:

			
			net.Max_line(m);
			
			cout << "���Ȩ��"<<m.first << endl;
			cout << "��ʼ�ڵ�"<<net.Trans(m.second);
			cout << endl;
			system("pause");
			system("cls");
			break;

		case 8:
			cout << "���ڱ����罻������Ϣ�������ļ�..." << endl;
			if (net.Save())
				cout << "����ɹ���" << endl;
			else
				cout << "����ʧ�ܣ�" << endl;
			break;
		//case 9:
		//	net.DisplayFloyd();
		//	system("pause");
		//	system("cls");
		//	break;
		}
	}
}