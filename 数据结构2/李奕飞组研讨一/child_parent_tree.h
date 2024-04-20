#pragma once
#ifndef __CHILD_PARENT_TREE_H__
#define __CHILD_PARENT_TREE_H__

#include "child_parent_tree_node.h"					// 孩子双亲表示树结点类
#include "assistance.h"

// 孩子双亲表示树类
template <class ElemType>
class ChildParentTree
{
protected:
	//  树的数据成员:
	ChildParentTreeNode<ElemType>* nodes;			// 存储树结点
	int maxSize;									// 树结点最大个数 
	int root, num;									// 根的位置及结点数

	//	辅助函数:
	void DisplayTWithConcaveShapeHelp(const ChildParentTree<ElemType>& t, int r, int level);
	//按凹入表示法显示树，level为层次数，设根结点的层次数为1
	int GenerationHelp(const ChildParentTree<ElemType>& t, int r, int gnr) const;	// 先根序遍历代数

public:
	//  树方法声明及重载编译系统默认方法声明:
	ChildParentTree();								// 无参构造函数
	virtual ~ChildParentTree();						// 析构函数
	ChildParentTree(ElemType items[], int parents[], int r, int n, int size = DEFAULT_SIZE);
	// 建立数据元素为items[],对应结点双亲为parents[],根结点位置为r,结点个数为n的树
	int GetRoot() const;							// 返回树的根
	int GetGen(int i)const;							// 获取代数
	Status GetElem(int cur, ElemType& e) const;		// 用e返回结点元素值
	Status SetElem(int cur, const ElemType& e);		// 将结cur的值置为e
	Status GetNode(int choice, int cur, ElemType& e) const;		// 用e返回结点附属信息
	Status SetNode(int choice, int cur, const ElemType& e);		// 将结点cur的附属信息设置为e
	Status SetGen(int cur, int g);								// 设置代数
	Status InsertChild(int cur, int i, const ElemType& e);							//  My_Insert 目前功能为双亲是cur，存储在顺序表的第i点处。
	Status OutNode(string nam);														// 根据输入的名字输出全部信息
	Status DeleteMember(const ChildParentTree<ElemType>& t, string nam);			// 删除某家庭成员
	void Generation(const ChildParentTree<ElemType>& t, int gnr)const;				// 输出指定层数的家族成员和成员人数
	void Search_In(string name);													// 统一内容格式后注意修改
	void DisplayTWithConcaveShape(const ChildParentTree<ElemType>& t);				// 按凹入表示法显示树
	void Search_Out(string name);
	void Relation(string nam1, string nam2);
	void Relation(int nam1, int nam2);
	bool Empty() const;								// 判断树是否为空
	bool IsParents(int nam1, int nam2, int gap);	// 以上三函数实现查询关系的功能
	bool Save();									// 文件保存
	bool IfExist(string nam)const;					// 判断名字是否已存在
	

	int NodeCount() const;							// 返回树的结点个数
	int NodeDegree(int cur) const;					// 返回结点cur的度
	int FirstChild(int cur) const;					// 返回结点cur的第一个孩子
	int RightSibling(int cur) const;				// 返回结点cur的右兄弟
	int Parent(int cur) const;						// 返回结点cur的双亲
	
};



// 孩子双亲表示树类的实现部分
template <class ElemType>
ChildParentTree<ElemType>::ChildParentTree()
// 操作结果：构造一个空树
{
	maxSize = DEFAULT_SIZE;								// 树结点最大个数
	nodes = new ChildParentTreeNode<ElemType>[maxSize];	// 分配存储空间
	root = -1;											// 表示不存在根
	num = 0;											// 空树的结点个数为0
}

template <class ElemType>
ChildParentTree<ElemType>::~ChildParentTree()
// 操作结果：释放存储空间
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
	delete[]nodes;										// 释放存储空间
}



template <class ElemType>
int ChildParentTree<ElemType>::GetRoot() const
// 操作结果：返回树的根
{
	return root;
}

template <class ElemType>
bool ChildParentTree<ElemType>::Empty() const
// 操作结果：判断树是否为空
{
	return num == 0;
}

template <class ElemType>
Status ChildParentTree<ElemType>::GetElem(int cur, ElemType& e) const
// 操作结果：用e返回结点cur元素值,如果不存在结点cur,函数返回NOT_PRESENT,否则返回ENTRY_FOUND
{
	if (cur < 0 || cur >= num)		// 不存在结点cur
		return NOT_PRESENT;			// 返回NOT_PRESENT
	else {	                        // 存在结点cur
		e = nodes[cur].nam;			// 用e返回元素值
		return ENTRY_FOUND;			// 返回ENTRY_FOUND
	}
}

template <class ElemType>
Status ChildParentTree<ElemType>::SetElem(int cur, const ElemType& e)
// 操作结果：如果不存在结点cur,则返回FAIL,否则返回SUCCESS,并将结点cur的值设置为e
{
	if (cur < 0 || cur >= num)		// 不存在结点cur
		return FAIL;				// 返回FAIL
	else {							// 存在结点cur
		nodes[cur].nam = e;			// 将结点cur的值设置为e
		return SUCCESS;	  		    // 返回SUCCESS
	}
}

template <class ElemType>
Status ChildParentTree<ElemType>::GetNode(int choice, int cur, ElemType& e) const
// 操作结果：用e返回结点cur附加信息,如果不存在结点cur,函数返回NOT_PRESENT,否则返回ENTRY_FOUND
{
	if (cur < 0 || cur >= num)		// 不存在结点cur
		return FAIL;
	else {
		switch (choice)
		{
		case 1:e = nodes[cur].nam;	// 返回名字
			break;
		case 2:e = nodes[cur].bir;	// 返回生日
			break;
		case 3:e = nodes[cur].mar;	// 返回婚姻状态
			break;
		case 4:e = nodes[cur].add;	// 返回地址
			break;
		case 5:e = nodes[cur].sta;	// 返回目前状况（包含除名）
			break;
		case 6:e = nodes[cur].dea;	// 返回死亡日期
			break;
		default:cout << "选项错误，请重新输入。";		// 错误输入报错
			break;
		}
		return SUCCESS
	}
}

template <class ElemType>
Status ChildParentTree<ElemType>::SetNode(int choice, int cur, const ElemType& e)
// 操作结果：用e修改结点cur附加信息,如果不存在结点cur,函数返回NOT_PRESENT,否则返回ENTRY_FOUND
{
	if (cur < 0 || cur >= num)		// 不存在结点cur
		return FAIL;
	else {
		switch (choice)
		{
		case 1:nodes[cur].nam = e;	// 修改名字
			break;
		case 2:nodes[cur].bir = e;	// 修改生日
			break;
		case 3:nodes[cur].mar = e;	// 修改婚姻
			break;
		case 4:nodes[cur].add = e;	// 修改地址
			break;
		case 5:nodes[cur].sta = e;	// 修改目前状况（包含除名）
			break;
		case 6:nodes[cur].dea = e;	// 修改死亡日期
			break;
		default:cout << "选项错误，请重新输入。";		// 错误输入报错
			break;
		}
		return SUCCESS;
	}
}

template <class ElemType>
int ChildParentTree<ElemType>::NodeCount() const
// 操作结果：返回树的结点个数
{
	return num;
}

template <class ElemType>
int ChildParentTree<ElemType>::FirstChild(int cur) const
// 操作结果：如cur无孩子,则返回-1,否则返回树结点cur的第一个孩子,
{
	Node<int>* p;
	if (cur < 0 || cur >= num)
		return -1;						// 结点cur不存在,返回-1表示无孩子

	if (nodes[cur].childLkList == NULL)	// 无孩子
		return -1;
	else
		return nodes[cur].childLkList->data;	// 取出第一个孩子
}

template <class ElemType>
int ChildParentTree<ElemType>::RightSibling(int cur) const
// 操作结果：如果结点cur无右兄弟,则返回-1,否则返回cur的右兄弟
{
	if (cur < 0 || cur >= num)
		return -1;						// 结点cur不存在,返回-1表示无孩子

	int pt = nodes[cur].parent;			// cur的双亲
	Node<int>* p = nodes[pt].childLkList;
	while (p != NULL && p->data != cur)
		p = p->next;
	if (p == NULL || p->next == NULL)
		return -1;						// 返回右兄弟
	else
		return p->next->data;			// 表示无右兄弟
}

template <class ElemType>
int ChildParentTree<ElemType>::Parent(int cur) const
// 操作结果：返回树结点cur的双亲
{
	if (cur < 0 || cur >= num)
		return -1;						// 结点cur不存在,返回-1表示无双亲
	return nodes[cur].parent;
}

template <class ElemType>
ChildParentTree<ElemType>::ChildParentTree(ElemType items[], int parents[], int r, int n, int size)
// 操作结果：建立数据元素为items[],对应结点双亲为parents[],根结点位置为r,结点个数为n的树
{
	maxSize = size;													// 最大结点个数
	if (n > maxSize)
		throw Error("结点个数太多!");								// 抛出异常
	nodes = new ChildParentTreeNode<ElemType>[maxSize];				// 分配存储空间
	for (int pos = 0; pos < n; pos++)
	{	// 依次对结点数据元素及双亲位置进行赋值
		nodes[pos].nam = items[pos];								// 数据元素值
		nodes[pos].parent = parents[pos];							// 双亲位置
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
	root = r;														// 根
	num = n;														// 结点个数
}

template <class ElemType>
void ChildParentTree<ElemType>::DisplayTWithConcaveShapeHelp(const ChildParentTree<ElemType>& t, int r, int level)
// 操作结果：按凹入表示法显示树，level为层次数，可设根结点的层次数为1
{
	if (r >= 0 && r < t.NodeCount() && t.nodes[r].sta != "不存在")
	{	// 存在结点r,才显示r的信息
		cout << endl;												// 显示新行	
		for (int i = 0; i < level - 1; i++)
			cout << "      ";										// 确保在第level列显示结点
		ElemType e;
		t.GetElem(r, e);											// 取出结点r的元素值
		cout << e;													// 显示结点元素值
		for (int child = t.FirstChild(r); child != -1; child = t.RightSibling(child))
		{	// 依次显示各棵子树
			DisplayTWithConcaveShapeHelp(t, child, level + 1);
		}
	}
}

template <class ElemType>
void ChildParentTree<ElemType>::DisplayTWithConcaveShape(const ChildParentTree<ElemType>& t)
// 操作结果：按凹入表示法显示树
{
	DisplayTWithConcaveShapeHelp(t, t.GetRoot(), 1);				// 调用辅助函数实现按凹入表示法显示树
	cout << endl;													// 换行
}

template <class ElemType>
int ChildParentTree<ElemType>::GenerationHelp(const ChildParentTree<ElemType>& t, int r, int gnr) const	
// 先根序遍历代数
{
	int num = 0;
	if (r >= 0 && r < t.NodeCount())
	{
		int g;
		ElemType e, sta;
		for (r; r <= t.NodeCount(); r++)
		{
			g = t.GetGen(r);
			if (g == gnr && t.nodes[r].sta != "不存在")
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
	cout << endl << "第" << gnr << "代人数为：" << number << endl;
}

template <class ElemType>
Status ChildParentTree<ElemType>::InsertChild(int cur, int i, const ElemType& e) 
{
	if (cur == i||cur==-1) {                                           //构造根节点
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
	nodes[i].gen = nodes[cur].gen + 1;     //代数维护
	num++;

	return SUCCESS;
}

template <class ElemType>
void ChildParentTree<ElemType>::Search_In(string name) {
	for (int i = 0; i < num; i++) {
		if (nodes[i].nam == name) {

			if (nodes[i].parent == -1)
				cout << "家谱未收录父辈" << endl;
			else
				cout << "父辈为" << nodes[nodes[i].parent].nam << endl;
			if (nodes[i].childLkList == NULL)
				cout << "单身贵族";
			else {
				Node<int>* p = nodes[i].childLkList;

				cout << "孩子为";
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
				cout << "家谱未收录父辈" << endl;
			else
				cout << "（原）父辈为" << nodes[nodes[i].parent].nam << endl;
			if (nodes[i].childLkList == NULL)
				cout << "单身贵族";
			else {
				Node<int>* p = nodes[i].childLkList;

				cout << "（原）孩子为";
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
		if (nodes[i].sta == "不存在")
		{
			cout << "姓名：" << nodes[i].nam << " 出生日期：" << nodes[i].bir << " 婚姻状况：" << nodes[i].mar
			<< " 地址：" << nodes[i].add << " 目前状况：已从家谱中移除" << " 死亡日期：" << nodes[i].dea;
			cout << endl;
			Search_Out(nam);
			cout << endl;
		}
			
		else
		{
			cout << "姓名：" << nodes[i].nam << " 出生日期：" << nodes[i].bir << " 婚姻状况：" << nodes[i].mar
			<< " 地址：" << nodes[i].add << " 目前状况：" << nodes[i].sta << " 死亡日期：" << nodes[i].dea;
			cout << endl;
			Search_In(nam);
			cout << endl;
		}
		return SUCCESS;
	}
}

template <class ElemType>
void ChildParentTree<ElemType>::Relation(int nam1, int nam2) {

	int gap = nodes[nam1].gen - nodes[nam2].gen;         //代数越大，辈分越小
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
		cout << "亲兄弟关系";
		else {
			cout << "表兄弟关系";
		}
		  else
		cout << "本人";
		break;
	case 1: if (IsParents(nam1, nam2, gap))
		cout << "父子关系";
		  else
		cout << "叔侄关系";
		break;
	case 2: if (IsParents(nam1, nam2, gap))
		cout << "爷孙关系";
		  else
		cout << "伯孙关系";
		break;
	case 3: if (IsParents(nam1, nam2, gap))
		cout << "曾祖与曾孙";
		  else
		cout << "曾伯祖与侄曾孙";
		break;
	case 4: if (IsParents(nam1, nam2, gap))
		cout << "高祖父与玄孙";
		  else
		cout << "伯高祖父与玄孙";
		break;
	default:
		if (IsParents(nam1, nam2, gap))
			cout << "关系太远，但为直系祖孙关系";
		else
			cout <<"关系太远，但为旁系祖孙关系";
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
		cout << "mem.txt打开失败" << endl;
		return false;
	}
	else
		cout << "mem.txt打开成功" << endl;
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
	cout << "成员信息保存成功" << endl;
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
	if (cur < 0 || cur >= num)		// 不存在结点cur
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
	if (i >= num || i == 0 || nodes[i].sta == "不存在")
		return FAIL;
	else
	{
		cur = i;
		string e = "不存在";
		// 没有孩子，直接返回
		if (FirstChild(cur) == -1)		
		{
			SetNode(5, cur, e);
			return SUCCESS;
		}
		int par = Parent(cur);
		// 没有兄弟，孩子直接继承给长辈
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
		// 找到兄弟中孩子最少的一位，将孩子过继给他
		else
		{
			SetNode(5, cur, e);
			int temp = -2;
			int mchild = maxSize + 1;
			for (int child2 = FirstChild(par); child2 != -1; child2 = RightSibling(child2))		// 找到兄弟中孩子最少的储存在temp中
			{
				if (child2 == cur||nodes[child2].sta=="不存在")
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
		if (nodes[child].sta == "不存在")
		{
			continue;
		}
		d++;
	}
	return d;
}

#endif