#include "LinkList.h"	
int main(void)
{
	LinkList<char> s(10);
	char c;
	int i=2;
	char a = '*';
	while (a != '0') {
		cout << endl;
		cout << "╔════════════════════════════════════╗" << endl;
		cout << "║             静态链表菜单           ║" << endl;
		cout << "╠════════════════════════════════════╣" << endl;
		cout << "║  1. 生成静态链表                   ║" << endl;
		cout << "║  2. 显示静态链表                   ║" << endl;
		cout << "║  3. 取静态链表长度                 ║" << endl;
		cout << "║  4. 设置元素值                     ║" << endl;
		cout << "║  5. 删除元素                       ║" << endl;
		cout << "║  6. 插入元素                       ║" << endl;
		cout << "║  7. 元素定位                       ║" << endl;
		cout << "║  8. 取指定位置元素                 ║" << endl;
		cout << "║  0. 退出                           ║" << endl;
		cout << "╚════════════════════════════════════╝" << endl;
		cout << "请从0~8中选择你要进行的操作：";
		cin >> a;

		switch (a)
		{
		case '1':
			s.Clear();
			cout << endl << "请输入单链表成员c，当输入为 @ 时停止读取" << endl;
			cout << "       （请每次输入一个字符）" << endl;
			cout << "第1个元素为：";
			cin >> c;
			while (c != '@') {
				s.InsertElem(c);
				if (s.GetLength() >= 10)
				{
					cout << "链表已满" << endl;break;
				}
				cout << "第"<<i<<"个元素为：";
				cin >> c;
				i++;
			}
			if (s.GetLength() == 0)
			{
				cout << "链表为空！" << endl;
				return 0;
			}
			break;
		case '2':
			s.Traverse(Write<char>);
			break;
		case '3':
			cout << endl << "单链表的长度为:" << s.GetLength() << endl;
			break;
		case '4':
			cout << endl << "输入位置:";
			cin >> i;
			cout << endl << "输入元素值:";
			cin >> c;
			if (s.SetElem(i, c) == RANGE_ERROR)
				cout << "位置范围错." << endl;
			else
				cout << "设置成功." << endl;
			break;
		case '5':
			cout << endl << "输入位置:";
			cin >> i;
			if (s.DeleteElem(i, c) == RANGE_ERROR)
				cout << "位置范围错." << endl;
			else
				cout << "被删除元素值:" << c << endl;
			break;
		case '6':
			cout << endl << "输入位置:";
			cin >> i;
			cout << endl << "输入元素值:";
			cin >> c;
			if (s.InsertElem(i, c) == RANGE_ERROR)
				cout << "位置范围错." << endl;
			else
				cout << "成功:" << c << endl;
			break;
		case '7':
			cout << endl << "输入元素的值:";
			cin >> c;
			if (s.LocateElem(c) == RANGE_ERROR)
				cout << "元素不存在." << endl;
			else
				cout << "元素" << c << "的序号为：" << s.LocateElem(c) << endl;
			break;
		case '8':
			cout << endl << "输入元素位置:";
			cin >> i;
			if (s.GetElem(i, c) == RANGE_ERROR)
				cout << "元素不存在." << endl;
			else
				cout << "元素:" << c << endl;
			break;
		}
	}
	return 0;              

}