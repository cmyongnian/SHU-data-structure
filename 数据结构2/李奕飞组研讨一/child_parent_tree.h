#pragma once
#ifndef __CHILD_PARENT_TREE_H__
#define __CHILD_PARENT_TREE_H__

#include "child_parent_tree_node.h"					// ����˫�ױ�ʾ�������
#include "assistance.h"

// ����˫�ױ�ʾ����
template <class ElemType>
class ChildParentTree
{
protected:
	//  �������ݳ�Ա:
	ChildParentTreeNode<ElemType>* nodes;			// �洢�����
	int maxSize;									// ����������� 
	int root, num;									// ����λ�ü������

	//	��������:
	void DisplayTWithConcaveShapeHelp(const ChildParentTree<ElemType>& t, int r, int level);
	//�������ʾ����ʾ����levelΪ�������������Ĳ����Ϊ1
	int GenerationHelp(const ChildParentTree<ElemType>& t, int r, int gnr) const;	// �ȸ����������

public:
	//  ���������������ر���ϵͳĬ�Ϸ�������:
	ChildParentTree();								// �޲ι��캯��
	virtual ~ChildParentTree();						// ��������
	ChildParentTree(ElemType items[], int parents[], int r, int n, int size = DEFAULT_SIZE);
	// ��������Ԫ��Ϊitems[],��Ӧ���˫��Ϊparents[],�����λ��Ϊr,������Ϊn����
	int GetRoot() const;							// �������ĸ�
	int GetGen(int i)const;							// ��ȡ����
	Status GetElem(int cur, ElemType& e) const;		// ��e���ؽ��Ԫ��ֵ
	Status SetElem(int cur, const ElemType& e);		// ����cur��ֵ��Ϊe
	Status GetNode(int choice, int cur, ElemType& e) const;		// ��e���ؽ�㸽����Ϣ
	Status SetNode(int choice, int cur, const ElemType& e);		// �����cur�ĸ�����Ϣ����Ϊe
	Status SetGen(int cur, int g);								// ���ô���
	Status InsertChild(int cur, int i, const ElemType& e);							//  My_Insert Ŀǰ����Ϊ˫����cur���洢��˳���ĵ�i�㴦��
	Status OutNode(string nam);														// ����������������ȫ����Ϣ
	Status DeleteMember(const ChildParentTree<ElemType>& t, string nam);			// ɾ��ĳ��ͥ��Ա
	void Generation(const ChildParentTree<ElemType>& t, int gnr)const;				// ���ָ�������ļ����Ա�ͳ�Ա����
	void Search_In(string name);													// ͳһ���ݸ�ʽ��ע���޸�
	void DisplayTWithConcaveShape(const ChildParentTree<ElemType>& t);				// �������ʾ����ʾ��
	void Search_Out(string name);
	void Relation(string nam1, string nam2);
	void Relation(int nam1, int nam2);
	bool Empty() const;								// �ж����Ƿ�Ϊ��
	bool IsParents(int nam1, int nam2, int gap);	// ����������ʵ�ֲ�ѯ��ϵ�Ĺ���
	bool Save();									// �ļ�����
	bool IfExist(string nam)const;					// �ж������Ƿ��Ѵ���
	

	int NodeCount() const;							// �������Ľ�����
	int NodeDegree(int cur) const;					// ���ؽ��cur�Ķ�
	int FirstChild(int cur) const;					// ���ؽ��cur�ĵ�һ������
	int RightSibling(int cur) const;				// ���ؽ��cur�����ֵ�
	int Parent(int cur) const;						// ���ؽ��cur��˫��
	
};



// ����˫�ױ�ʾ�����ʵ�ֲ���
template <class ElemType>
ChildParentTree<ElemType>::ChildParentTree()
// �������������һ������
{
	maxSize = DEFAULT_SIZE;								// �����������
	nodes = new ChildParentTreeNode<ElemType>[maxSize];	// ����洢�ռ�
	root = -1;											// ��ʾ�����ڸ�
	num = 0;											// �����Ľ�����Ϊ0
}

template <class ElemType>
ChildParentTree<ElemType>::~ChildParentTree()
// ����������ͷŴ洢�ռ�
{
	Node<int>* p;
	for (int n = 0; n < num; n++) {
		p = nodes[n].childLkList;
		while (p != NULL) {
			nodes[n].childLkList = p->next;
			delete p;
			p = nodes[n].childLkList;
		}
	}
	delete[]nodes;										// �ͷŴ洢�ռ�
}



template <class ElemType>
int ChildParentTree<ElemType>::GetRoot() const
// ����������������ĸ�
{
	return root;
}

template <class ElemType>
bool ChildParentTree<ElemType>::Empty() const
// ����������ж����Ƿ�Ϊ��
{
	return num == 0;
}

template <class ElemType>
Status ChildParentTree<ElemType>::GetElem(int cur, ElemType& e) const
// �����������e���ؽ��curԪ��ֵ,��������ڽ��cur,��������NOT_PRESENT,���򷵻�ENTRY_FOUND
{
	if (cur < 0 || cur >= num)		// �����ڽ��cur
		return NOT_PRESENT;			// ����NOT_PRESENT
	else {	                        // ���ڽ��cur
		e = nodes[cur].nam;			// ��e����Ԫ��ֵ
		return ENTRY_FOUND;			// ����ENTRY_FOUND
	}
}

template <class ElemType>
Status ChildParentTree<ElemType>::SetElem(int cur, const ElemType& e)
// �����������������ڽ��cur,�򷵻�FAIL,���򷵻�SUCCESS,�������cur��ֵ����Ϊe
{
	if (cur < 0 || cur >= num)		// �����ڽ��cur
		return FAIL;				// ����FAIL
	else {							// ���ڽ��cur
		nodes[cur].nam = e;			// �����cur��ֵ����Ϊe
		return SUCCESS;	  		    // ����SUCCESS
	}
}

template <class ElemType>
Status ChildParentTree<ElemType>::GetNode(int choice, int cur, ElemType& e) const
// �����������e���ؽ��cur������Ϣ,��������ڽ��cur,��������NOT_PRESENT,���򷵻�ENTRY_FOUND
{
	if (cur < 0 || cur >= num)		// �����ڽ��cur
		return FAIL;
	else {
		switch (choice)
		{
		case 1:e = nodes[cur].nam;	// ��������
			break;
		case 2:e = nodes[cur].bir;	// ��������
			break;
		case 3:e = nodes[cur].mar;	// ���ػ���״̬
			break;
		case 4:e = nodes[cur].add;	// ���ص�ַ
			break;
		case 5:e = nodes[cur].sta;	// ����Ŀǰ״��������������
			break;
		case 6:e = nodes[cur].dea;	// ������������
			break;
		default:cout << "ѡ��������������롣";		// �������뱨��
			break;
		}
		return SUCCESS
	}
}

template <class ElemType>
Status ChildParentTree<ElemType>::SetNode(int choice, int cur, const ElemType& e)
// �����������e�޸Ľ��cur������Ϣ,��������ڽ��cur,��������NOT_PRESENT,���򷵻�ENTRY_FOUND
{
	if (cur < 0 || cur >= num)		// �����ڽ��cur
		return FAIL;
	else {
		switch (choice)
		{
		case 1:nodes[cur].nam = e;	// �޸�����
			break;
		case 2:nodes[cur].bir = e;	// �޸�����
			break;
		case 3:nodes[cur].mar = e;	// �޸Ļ���
			break;
		case 4:nodes[cur].add = e;	// �޸ĵ�ַ
			break;
		case 5:nodes[cur].sta = e;	// �޸�Ŀǰ״��������������
			break;
		case 6:nodes[cur].dea = e;	// �޸���������
			break;
		default:cout << "ѡ��������������롣";		// �������뱨��
			break;
		}
		return SUCCESS;
	}
}

template <class ElemType>
int ChildParentTree<ElemType>::NodeCount() const
// ����������������Ľ�����
{
	return num;
}

template <class ElemType>
int ChildParentTree<ElemType>::FirstChild(int cur) const
// �����������cur�޺���,�򷵻�-1,���򷵻������cur�ĵ�һ������,
{
	Node<int>* p;
	if (cur < 0 || cur >= num)
		return -1;						// ���cur������,����-1��ʾ�޺���

	if (nodes[cur].childLkList == NULL)	// �޺���
		return -1;
	else
		return nodes[cur].childLkList->data;	// ȡ����һ������
}

template <class ElemType>
int ChildParentTree<ElemType>::RightSibling(int cur) const
// ���������������cur�����ֵ�,�򷵻�-1,���򷵻�cur�����ֵ�
{
	if (cur < 0 || cur >= num)
		return -1;						// ���cur������,����-1��ʾ�޺���

	int pt = nodes[cur].parent;			// cur��˫��
	Node<int>* p = nodes[pt].childLkList;
	while (p != NULL && p->data != cur)
		p = p->next;
	if (p == NULL || p->next == NULL)
		return -1;						// �������ֵ�
	else
		return p->next->data;			// ��ʾ�����ֵ�
}

template <class ElemType>
int ChildParentTree<ElemType>::Parent(int cur) const
// ������������������cur��˫��
{
	if (cur < 0 || cur >= num)
		return -1;						// ���cur������,����-1��ʾ��˫��
	return nodes[cur].parent;
}

template <class ElemType>
ChildParentTree<ElemType>::ChildParentTree(ElemType items[], int parents[], int r, int n, int size)
// �����������������Ԫ��Ϊitems[],��Ӧ���˫��Ϊparents[],�����λ��Ϊr,������Ϊn����
{
	maxSize = size;													// ��������
	if (n > maxSize)
		throw Error("������̫��!");								// �׳��쳣
	nodes = new ChildParentTreeNode<ElemType>[maxSize];				// ����洢�ռ�
	for (int pos = 0; pos < n; pos++)
	{	// ���ζԽ������Ԫ�ؼ�˫��λ�ý��и�ֵ
		nodes[pos].nam = items[pos];								// ����Ԫ��ֵ
		nodes[pos].parent = parents[pos];							// ˫��λ��
		if (parents[pos] != -1) {
			Node<int>* p, * newnode;
			newnode = new Node<int>(pos, NULL);
			if (nodes[parents[pos]].childLkList == NULL)
				nodes[parents[pos]].childLkList = newnode;
			else {
				p = nodes[parents[pos]].childLkList;
				while (p->next != NULL)
					p = p->next;
				p->next = newnode;
			}
		}
	}
	root = r;														// ��
	num = n;														// ������
}

template <class ElemType>
void ChildParentTree<ElemType>::DisplayTWithConcaveShapeHelp(const ChildParentTree<ElemType>& t, int r, int level)
// ����������������ʾ����ʾ����levelΪ���������������Ĳ����Ϊ1
{
	if (r >= 0 && r < t.NodeCount() && t.nodes[r].sta != "������")
	{	// ���ڽ��r,����ʾr����Ϣ
		cout << endl;												// ��ʾ����	
		for (int i = 0; i < level - 1; i++)
			cout << "      ";										// ȷ���ڵ�level����ʾ���
		ElemType e;
		t.GetElem(r, e);											// ȡ�����r��Ԫ��ֵ
		cout << e;													// ��ʾ���Ԫ��ֵ
		for (int child = t.FirstChild(r); child != -1; child = t.RightSibling(child))
		{	// ������ʾ��������
			DisplayTWithConcaveShapeHelp(t, child, level + 1);
		}
	}
}

template <class ElemType>
void ChildParentTree<ElemType>::DisplayTWithConcaveShape(const ChildParentTree<ElemType>& t)
// ����������������ʾ����ʾ��
{
	DisplayTWithConcaveShapeHelp(t, t.GetRoot(), 1);				// ���ø�������ʵ�ְ������ʾ����ʾ��
	cout << endl;													// ����
}

template <class ElemType>
int ChildParentTree<ElemType>::GenerationHelp(const ChildParentTree<ElemType>& t, int r, int gnr) const	
// �ȸ����������
{
	int num = 0;
	if (r >= 0 && r < t.NodeCount())
	{
		int g;
		ElemType e, sta;
		for (r; r <= t.NodeCount(); r++)
		{
			g = t.GetGen(r);
			if (g == gnr && t.nodes[r].sta != "������")
			{
				t.GetElem(r, e);
				cout << e << " ";
				num++;
			}
		}
	}
	return num;
}

template <class ElemType>
void ChildParentTree<ElemType>::Generation(const ChildParentTree<ElemType>& t, int gnr) const
{
	int number = 0;
	number = GenerationHelp(t, t.GetRoot(), gnr);
	cout << endl << "��" << gnr << "������Ϊ��" << number << endl;
}

template <class ElemType>
Status ChildParentTree<ElemType>::InsertChild(int cur, int i, const ElemType& e) 
{
	if (cur == i||cur==-1) {                                           //������ڵ�
		nodes[i].parent = -1;
		nodes[i].num = i;
		nodes[i].nam = e;
		root = i;
		num++;
		nodes[i].gen = 1;
		return SUCCESS;
	}

	Node<int>* p = nodes[cur].childLkList;
	if (p == NULL) {
		nodes[cur].childLkList = new Node<int>;
		p = nodes[cur].childLkList;
		p->data = i;

		p->next = NULL;
	}
	else {
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = new Node<int>;
		p = p->next;
		p->data = i;

		p->next = NULL;
	}
	nodes[i].parent = cur;
	nodes[i].num = i;
	nodes[i].nam = e;
	nodes[i].gen = nodes[cur].gen + 1;     //����ά��
	num++;

	return SUCCESS;
}

template <class ElemType>
void ChildParentTree<ElemType>::Search_In(string name) {
	for (int i = 0; i < num; i++) {
		if (nodes[i].nam == name) {

			if (nodes[i].parent == -1)
				cout << "����δ��¼����" << endl;
			else
				cout << "����Ϊ" << nodes[nodes[i].parent].nam << endl;
			if (nodes[i].childLkList == NULL)
				cout << "�������";
			else {
				Node<int>* p = nodes[i].childLkList;

				cout << "����Ϊ";
				while (p != NULL) {
					cout << nodes[p->data].nam << " ";
					p = p->next;
				}
			}
		}
	}
}

template <class ElemType>
void ChildParentTree<ElemType>::Search_Out(string name) {
	for (int i = 0; i < num; i++) {
		if (nodes[i].nam == name) {

			if (nodes[i].parent == -1)
				cout << "����δ��¼����" << endl;
			else
				cout << "��ԭ������Ϊ" << nodes[nodes[i].parent].nam << endl;
			if (nodes[i].childLkList == NULL)
				cout << "�������";
			else {
				Node<int>* p = nodes[i].childLkList;

				cout << "��ԭ������Ϊ";
				while (p != NULL) {
					cout << nodes[p->data].nam << " ";
					p = p->next;
				}
			}
		}
	}
}

template<class ElemType>
Status ChildParentTree<ElemType>::OutNode(string nam)
{
	int i;
	for (i = 0; i < num && nodes[i].nam != nam; i++);
	if (i >= num)
		return FAIL;
	else
	{
		if (nodes[i].sta == "������")
		{
			cout << "������" << nodes[i].nam << " �������ڣ�" << nodes[i].bir << " ����״����" << nodes[i].mar
			<< " ��ַ��" << nodes[i].add << " Ŀǰ״�����ѴӼ������Ƴ�" << " �������ڣ�" << nodes[i].dea;
			cout << endl;
			Search_Out(nam);
			cout << endl;
		}
			
		else
		{
			cout << "������" << nodes[i].nam << " �������ڣ�" << nodes[i].bir << " ����״����" << nodes[i].mar
			<< " ��ַ��" << nodes[i].add << " Ŀǰ״����" << nodes[i].sta << " �������ڣ�" << nodes[i].dea;
			cout << endl;
			Search_In(nam);
			cout << endl;
		}
		return SUCCESS;
	}
}

template <class ElemType>
void ChildParentTree<ElemType>::Relation(int nam1, int nam2) {

	int gap = nodes[nam1].gen - nodes[nam2].gen;         //����Խ�󣬱���ԽС
	if (gap < 0)
	{
		int temp = nam1;
		nam1 = nam2;
		nam2 = temp;
		gap = -gap;
	}
	switch (gap)
	{
	case 0: if (IsParents(nam1, nam2, gap))
		if(nodes[nam1].parent == nodes[nam2].parent)
		cout << "���ֵܹ�ϵ";
		else {
			cout << "���ֵܹ�ϵ";
		}
		  else
		cout << "����";
		break;
	case 1: if (IsParents(nam1, nam2, gap))
		cout << "���ӹ�ϵ";
		  else
		cout << "��ֶ��ϵ";
		break;
	case 2: if (IsParents(nam1, nam2, gap))
		cout << "ү���ϵ";
		  else
		cout << "�����ϵ";
		break;
	case 3: if (IsParents(nam1, nam2, gap))
		cout << "����������";
		  else
		cout << "��������ֶ����";
		break;
	case 4: if (IsParents(nam1, nam2, gap))
		cout << "���游������";
		  else
		cout << "�����游������";
		break;
	default:
		if (IsParents(nam1, nam2, gap))
			cout << "��ϵ̫Զ����Ϊֱϵ�����ϵ";
		else
			cout <<"��ϵ̫Զ����Ϊ��ϵ�����ϵ";
		break;
	}

	return;
}
template <class ElemType>
void ChildParentTree<ElemType>::Relation(string nam1, string nam2) {
	int name1, name2;
	for (int i = 0; i < num; i++) {
		if (nodes[i].nam == nam1)
			name1 = i;
		if (nodes[i].nam == nam2)
			name2 = i;
	}
	Relation(name1, name2);
}

template <class ElemType>
bool ChildParentTree<ElemType>::IsParents(int nam1, int nam2, int gap) {
	if (nam1 == nam2) return false;
	if (gap == 0)  return true;
	int adr = nam1;
	for (int i = 0; i < gap; i++) {
		adr = nodes[adr].parent;
	}
	if (adr == nam2)
		return true;
	else return false;
}

template<class ElemType>
bool ChildParentTree<ElemType>::Save()
{
	ofstream file_fam;
	file_fam.open("mem.txt");
	if (!file_fam.is_open())
	{
		cout << "mem.txt��ʧ��" << endl;
		return false;
	}
	else
		cout << "mem.txt�򿪳ɹ�" << endl;
	int i;
	int fa_num, Num, gen;
	ElemType nam, bir, mar, add, sta, dea;
	for (i = 0; i < num - 1; i++)
	{
		fa_num = nodes[i].parent;
		Num = nodes[i].num;
		nam = nodes[i].nam;
		bir = nodes[i].bir;
		mar = nodes[i].mar;
		add = nodes[i].add;
		sta = nodes[i].sta;
		dea = nodes[i].dea;
		gen = nodes[i].gen;
		file_fam << fa_num << '\t' << Num << '\t' << nam << '\t' << bir << '\t' << mar << '\t'
			<< add << '\t' << sta << '\t' << dea << '\t' << gen << endl;
	}
	fa_num = nodes[i].parent;
	Num = nodes[i].num;
	nam = nodes[i].nam; 
	bir = nodes[i].bir;
	mar = nodes[i].mar;
	add = nodes[i].add;
	sta = nodes[i].sta;
	dea = nodes[i].dea;
	gen = nodes[i].gen;
	file_fam << fa_num << '\t' << Num << '\t' << nam << '\t' << bir << '\t' << mar << '\t'
		<< add << '\t' << sta << '\t' << dea << '\t' << gen;
	file_fam.close();
	cout << "��Ա��Ϣ����ɹ�" << endl;
	return true;
}

template<class ElemType>
bool ChildParentTree<ElemType>::IfExist(string nam)const
{
	int i;
	for (i = 0; i < num && nodes[i].nam != nam; i++);
	if (i >= num)
		return false;
	else
		return true;
}


template<class ElemType>
int ChildParentTree<ElemType>::GetGen(int i)const
{
	return nodes[i].gen;
}

template<class ElemType>
Status ChildParentTree<ElemType>::SetGen(int cur, int g)
{
	if (cur < 0 || cur >= num)		// �����ڽ��cur
		return FAIL;
	else
	{
		nodes[cur].gen = g;
		return SUCCESS;
	}
}

template<class ElemType>
Status ChildParentTree<ElemType>::DeleteMember(const ChildParentTree<ElemType>& t, string nam)
{
	int i, cur;
	for (i = 0; i < num && nodes[i].nam != nam; i++);
	if (i >= num || i == 0 || nodes[i].sta == "������")
		return FAIL;
	else
	{
		cur = i;
		string e = "������";
		// û�к��ӣ�ֱ�ӷ���
		if (FirstChild(cur) == -1)		
		{
			SetNode(5, cur, e);
			return SUCCESS;
		}
		int par = Parent(cur);
		// û���ֵܣ�����ֱ�Ӽ̳и�����
		if (NodeDegree(par) == 1)		
		{
			SetNode(5, cur, e);
			for (Node<int>* q = nodes[cur].childLkList; q != NULL; q = q->next)
			{
				nodes[q->data].parent = par;
				Node<int>* p, * newnode;
				p = nodes[par].childLkList;
				if (p == NULL)
				{
					nodes[par].childLkList = new Node<int>(q->data, NULL);
				}
				newnode = new Node<int>(q->data, p->next);
				p->next = newnode;
			}
			return SUCCESS;
		}
		// �ҵ��ֵ��к������ٵ�һλ�������ӹ��̸���
		else
		{
			SetNode(5, cur, e);
			int temp = -2;
			int mchild = maxSize + 1;
			for (int child2 = FirstChild(par); child2 != -1; child2 = RightSibling(child2))		// �ҵ��ֵ��к������ٵĴ�����temp��
			{
				if (child2 == cur||nodes[child2].sta=="������")
				{
					continue;
				}
				if (NodeDegree(child2) < mchild)
				{
					mchild = NodeDegree(child2);
					temp = child2;
				}
			}
			for (Node<int>* q = nodes[cur].childLkList; q != NULL; q = q->next)
			{
				nodes[q->data].parent = temp;
				Node<int>* p, * newnode;
				p = nodes[temp].childLkList;
				if (p == NULL)
				{
					nodes[temp].childLkList = new Node<int>(q->data, NULL);
				}
				else
				{
					newnode = new Node<int>(q->data, p->next);
					p->next = newnode;
				}
			}
			return SUCCESS;
		}
	}
}

template <class ElemType>
int ChildParentTree<ElemType>::NodeDegree(int cur) const
{
	int d = 0;
	for (int child = FirstChild(cur); child != -1; child = RightSibling(child))
	{
		if (nodes[child].sta == "������")
		{
			continue;
		}
		d++;
	}
	return d;
}

#endif