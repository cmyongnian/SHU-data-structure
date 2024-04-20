#include "child_parent_tree.h"
#include <iostream>

// �����ִ洢�ṹ��ȡ����˫�׺��ӱ�ʾ��
// ���ܽ��� 1����ʼ�����������ļ���ÿһ�д洢һ���˵ĸ�����Ϣ�������������������ӽ��Ľӿڣ�
//			2: ��ʾ������������ͨ�ĵ���Display����?��
//			3: ���ݴ���n����ʾ��n�������������������������ֻ������һ��?��
//			4: ����������ѯ�������Ա��Ϣ�����ˣ���ĸ��������Ϣ��������    *�Ƿ�Ӧ�ðѴ����ӵ�ÿ���˵ĸ�����Ϣ��?
//			5����������������ȷ�����ϵ����������
//			6: ��ĳ����Ӻ��ӣ�������Insert������
//			7: ɾ��ĳ�ˣ�����Ĺ�᷽����Ҫѯ��һ�£�
//			8: �޸�ĳ�˵���Ϣ��������set������
// *����ļ��������ʱ����������棬��������ļ��Ĵ洢��ʽӦ��ĳһ�ֱ���ģʽ����һ��

using namespace std;
int main()
{
	cout << "������������Ա��Ϣ..." << endl;
	ChildParentTree<string> fam_mem;

	ifstream file_fam;
	file_fam.open("mem.txt");
	if (!file_fam.is_open()) {
		cout << "mem.txt��ʧ��" << endl;
		return -1;
	}
	else
		cout << "mem.txt�򿪳ɹ�" << endl;
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

	cout << "��ͥ��Ա��Ϣ������ɣ�" << endl;
	system("pause");
	system("cls");

	while (1)
	{
		cout << "�����������ϵͳ����" << endl;
		cout << "1����ʾ������" << endl;
		cout << "2�����ݴ�����ѯ��Ϣ" << endl;
		cout << "3������������ѯ��Ϣ" << endl;
		cout << "4����ѯ��ϵ" << endl;
		cout << "5����Ӻ�����Ϣ��������޸���Ϣʹ�ã�" << endl;
		cout << "6��ɾ��ĳ����Ϣ" << endl;
		cout << "7���޸�ĳ����Ϣ" << endl;
		cout << "8�������Ա��Ϣ" << endl;
		cout << "0���˳�ϵͳ" << endl;
		cout << "��ѡ��..." << endl;
		int flag1, flag2 = 1;
		int Gen,num;
		string Nam, Nam1, Nam2, Bir, Mar, Add, Sta, Dea, Gener;
		cin >> flag1;
		switch (flag1)
		{
		case 0:
			cout << "��л����ʹ�ã�" << endl;
			system("pause");
			return 0;
		case 1:
			fam_mem.DisplayTWithConcaveShape(fam_mem);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "������Ҫ��ѯ�Ĵ�����" << endl;
			cin >> Gen;
			cout << endl;
			fam_mem.Generation(fam_mem, Gen);
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "������Ҫ��ѯ��������" << endl;
			cin >> Nam;
			if (fam_mem.OutNode(Nam) == SUCCESS);
			else
				cout << "���˲������ڼ�������" << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "����1��";
			cin >> Nam1;
			cout << "����2��";
			cin >> Nam2;
			fam_mem.Relation(Nam1, Nam2);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "��������ӵĺ�����Ϣ��" << endl;
			cout << "˫�ױ�ţ�";
			cin >> num;
			cout << "����������";
			cin >> Nam;
			if (fam_mem.IfExist(Nam) == 1)
				cout << "�ó�Ա�Ѵ���" << endl;
			else
				fam_mem.InsertChild(num, fam_mem.NodeCount(), Nam);
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "��������ɾ����������";
			cin >> Nam;
			if (fam_mem.DeleteMember(fam_mem, Nam) == SUCCESS)
				cout << "ɾ���ɹ�" << endl;
			else
				cout << "ɾ��ʧ��" << endl;
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "�������޸���Ϣ��" << endl;
			cout << "��ţ�";
			cin >> num;
			cout << endl;
			while (flag2 != 0)
			{
				cout << "1���޸�����" << endl;
				cout << "2���޸ĳ�������" << endl;
				cout << "3���޸Ļ���״��" << endl;
				cout << "4���޸ĵ�ַ" << endl;
				cout << "5���޸�Ŀǰ״̬" << endl;
				cout << "6���޸���������" << endl;
				cout << "0���˳��޸�" << endl;
				cin >> flag2;
				switch (flag2)
				{
				case 1:
					cout << "�޸ĺ��������";
					cin >> Nam;
					fam_mem.SetNode(flag2, num, Nam);
					cout << endl << "�޸ĳɹ�";
					break;
				case 2:
					cout << "�޸ĺ�ĳ������ڣ�";
					cin >> Bir;
					fam_mem.SetNode(flag2, num, Bir);
					cout << endl << "�޸ĳɹ�";
					break;
				case 3:
					cout << "�޸ĺ�Ļ���״����";
					cin >> Mar;
					fam_mem.SetNode(flag2, num, Mar);
					cout << endl << "�޸ĳɹ�";
					break;
				case 4:
					cout << "�޸ĺ�ĵ�ַ��";
					cin >> Add;
					fam_mem.SetNode(flag2, num, Add);
					cout << endl << "�޸ĳɹ�";
					break;
				case 5:
					cout << "�޸ĺ��Ŀǰ״����";
					cin >> Sta;
					fam_mem.SetNode(flag2, num, Sta);
					cout << endl << "�޸ĳɹ�";
					break;
				case 6:
					cout << "�޸ĺ���������ڣ�";
					cin >> Dea;
					fam_mem.SetNode(flag2, num, Dea);
					cout << endl << "�޸ĳɹ�";
					break;
				case 7:
					cout << "�޸ĺ�Ĵ�����";
					cin >> Gen;
					fam_mem.SetGen(num, Gen);
					cout << endl << "�޸ĳɹ�";
				case 0:
					break;
				default:
					cout << "���������������������룡" << endl;
					break;
				}
			}
			system("pause");
			system("cls");
			break;
		case 8:
			cout << "���ڱ�������Ա��Ϣ�������ļ�..." << endl;
			if (fam_mem.Save())
				cout << "����ɹ���" << endl;
			else
				cout << "����ʧ�ܣ�" << endl;
			system("pause");
			system("cls");
			break;
		default:
			cout << "���������������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
