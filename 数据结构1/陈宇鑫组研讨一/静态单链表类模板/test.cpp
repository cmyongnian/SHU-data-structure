#include "LinkList.h"	
int main(void)
{
	LinkList<char> s(10);
	char c;
	int i=2;
	char a = '*';
	while (a != '0') {
		cout << endl;
		cout << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << endl;
		cout << "�U             ��̬����˵�           �U" << endl;
		cout << "�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g" << endl;
		cout << "�U  1. ���ɾ�̬����                   �U" << endl;
		cout << "�U  2. ��ʾ��̬����                   �U" << endl;
		cout << "�U  3. ȡ��̬������                 �U" << endl;
		cout << "�U  4. ����Ԫ��ֵ                     �U" << endl;
		cout << "�U  5. ɾ��Ԫ��                       �U" << endl;
		cout << "�U  6. ����Ԫ��                       �U" << endl;
		cout << "�U  7. Ԫ�ض�λ                       �U" << endl;
		cout << "�U  8. ȡָ��λ��Ԫ��                 �U" << endl;
		cout << "�U  0. �˳�                           �U" << endl;
		cout << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << endl;
		cout << "���0~8��ѡ����Ҫ���еĲ�����";
		cin >> a;

		switch (a)
		{
		case '1':
			s.Clear();
			cout << endl << "�����뵥�����Աc��������Ϊ @ ʱֹͣ��ȡ" << endl;
			cout << "       ����ÿ������һ���ַ���" << endl;
			cout << "��1��Ԫ��Ϊ��";
			cin >> c;
			while (c != '@') {
				s.InsertElem(c);
				if (s.GetLength() >= 10)
				{
					cout << "��������" << endl;break;
				}
				cout << "��"<<i<<"��Ԫ��Ϊ��";
				cin >> c;
				i++;
			}
			if (s.GetLength() == 0)
			{
				cout << "����Ϊ�գ�" << endl;
				return 0;
			}
			break;
		case '2':
			s.Traverse(Write<char>);
			break;
		case '3':
			cout << endl << "������ĳ���Ϊ:" << s.GetLength() << endl;
			break;
		case '4':
			cout << endl << "����λ��:";
			cin >> i;
			cout << endl << "����Ԫ��ֵ:";
			cin >> c;
			if (s.SetElem(i, c) == RANGE_ERROR)
				cout << "λ�÷�Χ��." << endl;
			else
				cout << "���óɹ�." << endl;
			break;
		case '5':
			cout << endl << "����λ��:";
			cin >> i;
			if (s.DeleteElem(i, c) == RANGE_ERROR)
				cout << "λ�÷�Χ��." << endl;
			else
				cout << "��ɾ��Ԫ��ֵ:" << c << endl;
			break;
		case '6':
			cout << endl << "����λ��:";
			cin >> i;
			cout << endl << "����Ԫ��ֵ:";
			cin >> c;
			if (s.InsertElem(i, c) == RANGE_ERROR)
				cout << "λ�÷�Χ��." << endl;
			else
				cout << "�ɹ�:" << c << endl;
			break;
		case '7':
			cout << endl << "����Ԫ�ص�ֵ:";
			cin >> c;
			if (s.LocateElem(c) == RANGE_ERROR)
				cout << "Ԫ�ز�����." << endl;
			else
				cout << "Ԫ��" << c << "�����Ϊ��" << s.LocateElem(c) << endl;
			break;
		case '8':
			cout << endl << "����Ԫ��λ��:";
			cin >> i;
			if (s.GetElem(i, c) == RANGE_ERROR)
				cout << "Ԫ�ز�����." << endl;
			else
				cout << "Ԫ��:" << c << endl;
			break;
		}
	}
	return 0;              

}