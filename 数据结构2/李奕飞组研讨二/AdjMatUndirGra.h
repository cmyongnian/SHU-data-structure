#pragma once
#ifndef __ADJ_MATRIX_UNDIR_GRAPH_H__
#define __ADJ_MATRIX_UNDIR_GRAPH_H__
#include <cstring>
#include"SeqStack.h"
#include<map>	

SeqStack<string> s1;
// 全局的栈变量，功能一中使用
class AdjMatrixUndirGraph
{
protected:
	// 邻接矩阵的数据成员:
	int vexNum, vexMaxNum, arcNum;		// 顶点数目、允许的顶点最大数目和边数
	int **arcs;							// 存放边信息邻接矩阵（存放亲密度）
	string *vertexes;					// 存放顶点信息的数组（存放每个顶点的姓名）
	mutable Status* tag;				// 标志数组
	int* huisu;                         //标志数组，记录路径
	int* huisuout;
	int maxnum,lastnum;
	
	//辅助用函数
	bool IsFriend(string n1, string n2);		 // 判断两人是否为好友
	int FirstAdjVex(int v) const;				 // 返回顶点v的第一个邻接点			 
	int NextAdjVex(int v1, int v2) const;		 // 返回顶点v1的相对于v2的下一个邻接点	
	Status GetTag(int v) const;			         // 返回顶点v的标志		 
	void SetTag(int v, Status val) const;		 // 设置顶点v的标志为val
	bool IsUnicom(string n1, string n2);		 // 判断两顶点是否联通
	void DFS(int v);							 // DFS搜索（无输出）
	void DFSOut(int v);							 // DFS搜索（有输出）
	void DFS_All(int v1, int v2);				 // 所有链路遍历

	//void fuzhi(int* v);
	//int Max_Span_Tree(int v);                  // 返回最大生成树权值
	void myDFS(int v, int n);
	int DFS_huisuout(pair<int, int>& mm);
	void myDFS_out(int v, int n, int maxn);
public:
	int Max_Span_Tree(int v);                    // 返回最大生成树权值
	void Max_Span_Forest( int& count, pair<int, int>* maxnn);      //返回最大生成森林权值
	int DFS_huisu(int v);                        //带回溯的DFS算法
	void Max_line(pair<int, int> &mm);           //最长直线
	

	// 邻接矩阵类型的方法声明:
	AdjMatrixUndirGraph(string es[], int vertexNum, int vertexMaxNum);
	// 以数组es[]为顶点,顶点个数为vertexNum,允许的顶点最大数目为vertexMaxNum,边数为0的无向图
	AdjMatrixUndirGraph(int vertexMaxNum = DEFAULT_SIZE);
	// 构造允许的顶点最大数目为vertexMaxNum,边数为0的无向图
	~AdjMatrixUndirGraph();				// 析构函数

	// 功能函数
	void DisplayPath(string n1, string n2);		 // 若两人非好友，输出所有关系链路
	void DFSTraverse();							 // DFS遍历
	void SmallGroup(int n);						 // 输入亲密度，找出人数大于2的小团体
	void InsertVex(const string& d);			 // 插入元素值为d的顶点		 
	void InsertArc(int v1, int v2, int w);		 // 插入顶点为v1和v2的边			 
	void DeleteVex(const string& d);			 // 删除元素值为d的顶点			 
	void DeleteArc(int v1, int v2);			     // 删除顶点为v1和v2的边
	int Trans(string n)const;					 // 将人名转化为下标
	string Trans(int n)const;					 // 将下标转化为人名
	bool Save();								 // 保存数据到TXT文件
	bool IsLegal(string n);						 // 判断输入的名字是否合法
	void Floyd(int** path, int** dist);			 // 弗洛伊德算法
	//测试用
	int GetWeight(int v0, int v1);				 // 返回v0和v1边的权值
	void Display();								 // 显示邻接矩阵无向图
	void DisplayFloyd();
};


AdjMatrixUndirGraph::AdjMatrixUndirGraph(string es[], int vertexNum, int vertexMaxNum = DEFAULT_SIZE)
{
	if (vertexMaxNum < 0)
		throw Error("允许的顶点最大数目不能为负!");			// 抛出异常

	if (vertexMaxNum < vertexNum)
		throw Error("顶点数目不能大于允许的顶点最大数目!");	// 抛出异常

	vexNum = vertexNum;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;

	vertexes = new string[vexMaxNum];						// 生成生成顶点信息数组
	tag = new Status[vexMaxNum];							// 生成标志数组
	arcs = (int**)new int* [vexMaxNum];						// 生成邻接矩阵
	for (int v = 0; v < vexMaxNum; v++)
		arcs[v] = new int[vexMaxNum];

	for (int v = 0; v < vexNum; v++) {
		vertexes[v] = es[v];
		tag[v] = UNVISITED;
		for (int u = 0; u < vexNum; u++)
			arcs[v][u] = 0;
	}
}


AdjMatrixUndirGraph::AdjMatrixUndirGraph(int vertexMaxNum)
// 操作结果：构造允许顶点的最大数目为vertexMaxNum的空无向图
{
	if (vertexMaxNum < 0)
		throw Error("允许的顶点最大数目不能为负!");

	vexNum = 0;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;

	vertexes = new string[vexMaxNum];						// 生成生成顶点信息数组
	tag = new Status[vexMaxNum];							// 生成标志数组
	arcs = (int**)new int* [vexMaxNum];						// 生成邻接矩阵
	for (int v = 0; v < vexMaxNum; v++)
		arcs[v] = new int[vexMaxNum];
}

AdjMatrixUndirGraph::~AdjMatrixUndirGraph()
// 操作结果：释放对象所占用的空间
{
	delete[]vertexes;										// 释放顶点数据
	delete[]tag;											// 释放标志

	for (int v = 0; v < vexMaxNum; v++)						// 释放邻接矩阵的行
		delete[]arcs[v];
	delete[]arcs;											// 释放邻接矩阵
}

int AdjMatrixUndirGraph::FirstAdjVex(int v) const
// 操作结果：返回顶点v的第1个邻接点的序号		 
{
	if (v < 0 || v >= vexNum)
		throw Error("v不合法!");	// 抛出异常

	for (int u = 0; u < vexNum; u++)
		if (arcs[v][u] != 0)
			return u;

	return -1;						// 返回-1表示无邻接点
}

int AdjMatrixUndirGraph::NextAdjVex(int v1, int v2) const
// 操作结果：返回顶点v1的相对于v2的下一个邻接点			 
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1不合法!");	// 抛出异常
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2不合法!");	// 抛出异常
	if (v1 == v2) throw
		Error("v1不能等于v2!");		// 抛出异常

	for (int u = v2 + 1; u < vexNum; u++)
		if (arcs[v1][u] != 0)
			return u;

	return -1;						// 返回-1表示无下一个邻接点
}

int AdjMatrixUndirGraph::Trans(string n)const
{
	int i;
	for (i = 0; n != vertexes[i]; i++);
	return i;
}

string AdjMatrixUndirGraph::Trans(int n)const
{
	return vertexes[n];
}

Status AdjMatrixUndirGraph::GetTag(int v) const
// 操作结果：返回顶点v的标志		 
{
	if (v < 0 || v >= vexNum)
		throw Error("v不合法!");	// 抛出异常

	return tag[v];
}

void AdjMatrixUndirGraph::SetTag(int v, Status val) const
// 操作结果：设置顶点v的标志为val		 
{
	if (v < 0 || v >= vexNum)
		throw Error("v不合法!");	// 抛出异常

	tag[v] = val;
}

void AdjMatrixUndirGraph::DisplayPath(string n1, string n2)
{
	for (int v = 0; v < vexNum; v++)
		SetTag(v, UNVISITED);					// 对每个顶点设置未访问标志
	if (IsFriend(n1, n2) == true)
		cout << "两人是朋友";
	else if (IsUnicom(n1, n2) == false)
	{
		cout << "这两人间无关系链路";
	}
	else
	{
		for (int v = 0; v < vexNum; v++)
			SetTag(v, UNVISITED);				// 对每个顶点设置未访问标志
		cout << "两人的关系链路为：" << endl;
		DFS_All(Trans(n1), Trans(n2));
	}
}

void AdjMatrixUndirGraph::DFSTraverse()
{
	int v, flag, n = 0;
	for (v = 0; v < vexNum; v++)
		SetTag(v, UNVISITED);
	for (v = 0; v < vexNum; v++)
	{
		flag = 0;
		for (int u = 0; u < vexNum; u++)
			if (arcs[v][u] != 0)
				flag = 1;
		if (GetTag(v) == UNVISITED && flag == 1)
		{
			cout << "小团体" << ++n << "为：" << endl;
			DFSOut(v);
			cout << endl;
		}
	}
}

void AdjMatrixUndirGraph::SmallGroup(int n)
{
	int** Arcs = (int**)new int* [vexNum];
	for (int v = 0; v < vexNum; v++)
		Arcs[v] = new int[vexNum];				// 新创建一个二维数组
	for (int v = 0; v < vexNum; v++)
		for (int u = 0; u < vexNum; u++)
			Arcs[v][u] = arcs[v][u];			// 将原本的边信息保存于新数组中
	for (int v = 0; v < vexNum; v++)
		for (int u = 0; u < vexNum; u++)
		{
			if (arcs[u][v] != 0)
				arcs[v][u] = arcs[u][v];		// 将矩阵的有向存储转化为无向
			if (arcs[v][u] < n)
				arcs[v][u] = 0;					// 小于阈值的边直接置0
		}
	DFSTraverse();
	for (int v = 0; v < vexNum; v++)
		for (int u = 0; u < vexNum; u++)
			arcs[v][u] = Arcs[v][u];
	for (int v = 0; v < vexNum; v++)
		delete[]Arcs[v];
	delete[]Arcs;
}

bool AdjMatrixUndirGraph::IsFriend(string n1, string n2)
{
	int i,j;
	for (i = 0; vertexes[i] != n1; i++);
	for (j = 0; vertexes[j] != n2; j++);
	if (arcs[i][j] != 0)
		return true;
	else
		return false;
}

void AdjMatrixUndirGraph::InsertVex(const string& d)
// 操作结果：插入顶点d			 
{
	if (vexNum == vexMaxNum)
		throw Error("图的顶点数不能超过允许的最大数!");	

	vertexes[vexNum] = d;
	tag[vexNum] = UNVISITED;
	for (int v = 0; v <= vexNum; v++) {
		arcs[vexNum][v] = 0;
		arcs[v][vexNum] = 0;
	}
	vexNum++;
}


void AdjMatrixUndirGraph::InsertArc(int v1, int v2, int w)
// 操作结果：插入依附顶点v1和v2的边			 
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1不合法!");				// 抛出异常
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2不合法!");				// 抛出异常
	if (v1 == v2)
		throw Error("v1不能等于v2!");			// 抛出异常

	//if (arcs[v1][v2] == 0) {					// 原无向图中没有边(v1, v2) 
		arcNum++;
		arcs[v1][v2] = w;
	//	arcs[v2][v1] = w;
	//}
}

void AdjMatrixUndirGraph::DeleteVex(const string& d)
// 操作结果：删除元素为d的顶点			 
{
	int v;
	for (v = 0; v < vexNum; v++)
		if (vertexes[v] == d)
			break;
	if (v == vexNum)
		throw Error("图中不存在要删除的顶点!");	// 抛出异常

	for (int u = 0; u < vexNum; u++)             // 删除与顶点d相关联的边 
		if (arcs[v][u] == 1) {
			arcNum--;
			arcs[v][u] = 0;
			arcs[u][v] = 0;
		}

	vexNum--;
	if (v < vexNum) {
		vertexes[v] = vertexes[vexNum];
		tag[v] = tag[vexNum];
		for (int u = 0; u <= vexNum; u++)
			arcs[v][u] = arcs[vexNum][u];
		for (int u = 0; u <= vexNum; u++)
			arcs[u][v] = arcs[u][vexNum];
	}
}

void AdjMatrixUndirGraph::DeleteArc(int v1, int v2)
// 操作结果：删除依附顶点v1和v2的边			 
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1不合法!");				// 抛出异常
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2不合法!");				// 抛出异常
	if (v1 == v2)
		throw Error("v1不能等于v2!");			// 抛出异常

	if (arcs[v1][v2] != 0) {					// 原无向图存在边(v1, v2)
		arcNum--;
		arcs[v1][v2] = 0;
		arcs[v2][v1] = 0;
	}
	else
	{
		cout << "本就陌生的不能再陌生";
	}
}

bool AdjMatrixUndirGraph::IsUnicom(string n1, string n2)
{
	int i, j;
	i = Trans(n1);
	j = Trans(n2);
	DFS(i);
	if (GetTag(j) == VISITED)
		return true;
	else
		return false;
}

void AdjMatrixUndirGraph::DFS(int v)
{
	SetTag(v, VISITED);						// 设置顶点v已访问标志
	for (int w = FirstAdjVex(v); w != -1; w = NextAdjVex(v, w))
		if (GetTag(w) == UNVISITED)
			DFS(w);							// 从v的尚未访问过的邻接顶点w开始进行深度优先搜索
}

void AdjMatrixUndirGraph::DFSOut(int v)
{
	SetTag(v, VISITED);						// 设置顶点v已访问标志
	cout << vertexes[v] << " ";
	for (int w = FirstAdjVex(v); w != -1; w = NextAdjVex(v, w))
		if (GetTag(w) == UNVISITED)
			DFSOut(w);						// 从v的尚未访问过的邻接顶点w开始进行深度优先搜索
}

void AdjMatrixUndirGraph::DFS_All(int v1, int v2)
{
	if (v1 == v2)
	{
		cout << vertexes[v2]<<"  ";
		s1.Traverse(Write<string>);
		cout << endl;
		return;
	}
	SetTag(v1, VISITED);
	s1.Push(vertexes[v1]);
	for (int w = FirstAdjVex(v1); w != -1; w = NextAdjVex(v1, w))
	{
		if (GetTag(w) == UNVISITED)
			DFS_All(w, v2);
	}
	SetTag(v1, UNVISITED);
	s1.Pop(vertexes[v1]);
}



int AdjMatrixUndirGraph::Max_Span_Tree(int v) {

	int count=0;                                 //  记录总亲密值
	bool flag = true;
	bool* isJoin = new bool[vexNum];

	int* MaxCost = new int[vexNum];
	for (int i = 0; i < vexNum; i++) {
		isJoin[i] = false;
		MaxCost[i] = 0;
	}
	pair<int,int> Each_Max_cost;              //first 为值，second为序号
	Each_Max_cost = make_pair(0, v);
	pair<int, int>Last_pair = make_pair(-1, -1);
	isJoin[v] = true;
	tag[v] = VISITED;
	for (int i = 0; i < vexNum; i++)
	{
		MaxCost[i] = arcs[v][i];
	}
	//初始化prim,接下来开始找最大
	while (flag) {
		Each_Max_cost.first = 0;
		for (int i = 0; i < vexNum; i++)                      //最大边与对应点
			if (isJoin[i]== false && MaxCost[i] > Each_Max_cost.first) {     //没访问过且亲密度最大
				Each_Max_cost.first = MaxCost[i];
				Each_Max_cost.second = i;
			}
	    isJoin[Each_Max_cost.second] = true;
		tag[Each_Max_cost.second] = VISITED;
		count += Each_Max_cost.first;
		for (int i = 0; i < vexNum; i++)
		if(arcs[Each_Max_cost.second][i]>MaxCost[i])
			MaxCost[i] = arcs[Each_Max_cost.second][i];
		if (Each_Max_cost.second == Last_pair.second||Each_Max_cost.first ==0)
			flag = 0;
		else Last_pair = Each_Max_cost;

	}
	return count;


}
void AdjMatrixUndirGraph::Max_Span_Forest(int &count, pair<int, int>* maxnnout) {

	int** Arcs = (int**)new int* [vexNum];
	for (int v = 0; v < vexNum; v++)
		Arcs[v] = new int[vexNum];
	for (int v = 0; v < vexNum; v++)
		for (int u = 0; u < vexNum; u++)
			Arcs[v][u] = arcs[v][u];
	for (int v = 0; v < vexNum; v++)
		for (int u = 0; u < vexNum; u++)
		{
			if (arcs[u][v] != 0&& arcs[v][u]==0)
				arcs[v][u] = arcs[u][v];
			if (arcs[v][u] != 0 && arcs[u][v] == 0)
				arcs[u][v] = arcs[v][u];
			
		}
	 int* tuceng; int m=0; 
	tuceng = new int[vexNum];
	for (int i = 0; i < vexNum; i++) {
		tag[i] = UNVISITED;
		tuceng[i] = -1;
	}
	
	for (int i = 0; i < vexNum; i++) {
		if (tuceng[i] == -1) {
			count++;
			Max_Span_Tree(i);
		}
	for (int j = i-1; j < vexNum; j++)
		if (tag[j] == VISITED && tuceng[j] == -1) {
			tuceng[j] = count;
		}

	}
//	Display();
	for (int v = 0; v < vexNum; v++)
		for (int u = 0; u < vexNum; u++)
			arcs[v][u] = Arcs[v][u];
	for (int v = 0; v < vexNum; v++)
		delete[]Arcs[v];
	delete[]Arcs;
//	Display();
	pair<int, int>* maxnn = nullptr;

	maxnn = new pair<int, int>[count];
	for (int i = 1; i <= count; i++) {
		for (int j = 0; j < vexNum; j++) {
			if (tuceng[j] == i) {
				m = max(m,Max_Span_Tree(j));
				if (m == 0)
					maxnn[i-1].second = j;
			}
				
			if (m > maxnn[i - 1].first) {
				maxnn[i - 1].first = m;
				maxnn[i - 1].second = j;
			}
				

		}
		m = 0;
	}
	for(int i = 0;i<count;i++)
	maxnnout[i] = maxnn[i];
	
	return ;

}
int AdjMatrixUndirGraph::DFS_huisu(int v) {
	if (huisu != NULL)
		delete[]huisu;
	huisu = new int[vexNum];
	
	for (int i = 0; i < vexNum; i++) {
				huisu[i] = vexNum+1;
	}
	huisu[v] = -1;
	 myDFS(v, 1);
	 int ma=maxnum;
	 maxnum = 0;
	 return ma;

}

void AdjMatrixUndirGraph::myDFS(int v, int n) {
	int ans = 0;
	if (n == vexNum) {
		for (int j = v; huisu[j] != -1; j = huisu[j]) {
			ans += arcs[huisu[j]][j];
		}
		maxnum = max(ans, maxnum);

		ans = 0;
	}
	else {
		for (int i = 0; i < vexNum; i++) {
			if (huisu[i] == (vexNum + 1) && arcs[v][i] > 0) {
				huisu[i] = v;
				myDFS(i, n + 1);
				huisu[i] = vexNum + 1;
			}
		}
	}

}
void AdjMatrixUndirGraph::myDFS_out(int v, int n,int maxn) {
	int ans = 0;
	if (n == vexNum) {
		for (int j = v; huisu[j] != -1; j = huisu[j]) {
			ans += arcs[huisu[j]][j];
		}
		if (maxn == ans) {
			for (int i = 0; i < vexNum; i++) {
				huisuout[i] = huisu[i];
				lastnum = v;
			}
		}

		ans = 0;
		
	}
	else {
		for (int i = 0; i < vexNum; i++) {
			if (huisu[i] == (vexNum + 1) && arcs[v][i] > 0) {
				huisu[i] = v;
				myDFS_out(i, n + 1, maxn);
				huisu[i] = vexNum + 1;
			}
		}
	}

}
int AdjMatrixUndirGraph::DFS_huisuout(pair<int, int>& mm) {
	if (mm.first == 0) {
		return 0;
	}
	if (huisu != NULL)
		delete[]huisu;
	if (huisuout != NULL)
		delete[]huisuout;
	huisu = new int[vexNum];
	huisuout = new int[vexNum];

	for (int i = 0; i < vexNum; i++) {
		huisu[i] = vexNum + 1;
	}
	huisu[mm.second] = -1;
	myDFS_out(mm.second, 1,mm.first);
	int ma = maxnum;
	maxnum = 0;
	return 1;
}
void AdjMatrixUndirGraph::Max_line(pair<int, int>& mm) {
	mm.first = 0;
	mm.second = 0;
	int nn=0,sta;
	for (int i = 0; i < vexNum; i++) {
		nn=DFS_huisu(i);
		if (nn > mm.first) {
			mm.first = nn;
			mm.second = i;
		}
	}
	sta=DFS_huisuout(mm);
	if (sta == 0) 
	{
		cout << "无联通路径" << endl;
		return;
	}
	cout << "路径倒序为:" << endl;
	for (int i = lastnum; i !=-1; i=huisuout[i]) {
		cout << vertexes[i]<<" ";
	}
	cout << endl;
	
}



void AdjMatrixUndirGraph::Display()
// 操作结果: 显示邻接矩阵无向图
{

	for (int v = 0; v < vexNum; v++)
		cout << "\t" << vertexes[v];
	cout << endl;

	for (int v = 0; v < vexNum; v++) {
		cout << vertexes[v];
		for (int u = 0; u < vexNum; u++)
			cout << "\t" << arcs[v][u];
		cout << endl;
	}
}

bool AdjMatrixUndirGraph::Save()
{
	ofstream file_net;
	file_net.open("friend.txt");
	if (!file_net.is_open())
	{
		cout << "friend.txt打开失败" << endl;
		return false;
	}
	else
		cout << "friend.txt打开成功" << endl;
	file_net << vexMaxNum;
	for (int i = 0; i < vexNum; i++)
	{
		for (int j = 0; j < vexNum; j++)
		{
			if (arcs[i][j] != 0)
			{
				file_net << endl << vertexes[i] << '\t' << vertexes[j] << '\t' << arcs[i][j];
			}
		}
	}
	for (int j = 0; j < vexNum; j++)
	{
			file_net << endl << vertexes[j] << '\t' << vertexes[j] << '\t' << 0;
	}
	file_net.close();
	cout << "朋友网络保存成功" << endl;
	return true;

}

int SearchName(string name[], string n)
{
	for (int i = 0; name[i] != "0"; i++)
	{
		if (n == name[i])
		{
			return 0;
		}
	}
	return 1;
}

bool AdjMatrixUndirGraph::IsLegal(string n)
{
	int i;
	for (i = 0; n != vertexes[i] && i < vexNum; i++);
	if (i == vexNum)
		return false;
	else
		return true;
}

int AdjMatrixUndirGraph::GetWeight(int v0, int v1)
// 返回v0和v1边的权值,若没有边，返回无穷大
{
	return arcs[v0][v1];
}

void AdjMatrixUndirGraph::Floyd(int** path, int** dist)
// 弗洛伊德算法求最短路径
{
	int** Arcs = (int**)new int* [vexNum];
	for (int v = 0; v < vexNum; v++)
		Arcs[v] = new int[vexNum];


	for (int u = 0; u < vexNum; u++)
	{
		for (int v = 0; v < vexNum; v++)
		{
			dist[u][v] = (u != v) ? GetWeight(u, v) : 0;
			Arcs[u][v] = 100 - dist[u][v];
			if (u != v && dist[u][v] < 100)
			{
				path[u][v] = u;
			}
			else
			{
				path[u][v] = -1;
			}
		}
	}
	/*
	cout << "dist[][]" << endl;
	for (int v = 0; v < vexNum; v++)
	{
		cout << "\t" << vertexes[v];
	}
	cout << endl;

	for (int v = 0; v < vexNum; v++) {
		cout << vertexes[v];
		for (int u = 0; u < vexNum; u++)
		{
			if (Arcs[v][u] == 0)
			{
				cout << "\t" << "∞";
			}
			else
			{
				cout << "\t" << Arcs[v][u];
			}
		}
		cout << endl;
	}
	*/
	for (int k = 0; k < vexNum; k++)
		for (int i = 0; i < vexNum; i++)
			for (int j = 0; j < vexNum; j++)
			{
				if (Arcs[i][k] != 100 && Arcs[k][j] != 100 && (Arcs[i][k] + Arcs[k][j]) < Arcs[i][j])
				{
					Arcs[i][j] = Arcs[i][k] + Arcs[k][j] - 100;
					path[i][j] = path[k][j];
				}
			}
	
	cout << "dist[][]" << endl;
	for (int v = 0; v < vexNum; v++)
	{
		cout << "\t" << vertexes[v];
	}
	cout << endl;

	for (int v = 0; v < vexNum; v++) {
		cout << vertexes[v];
		for (int u = 0; u < vexNum; u++)
		{
			if (Arcs[v][u] == 0)
			{
				cout << "\t" << "∞";
			}
			else
			{
				cout << "\t" << Arcs[v][u];
			}
		}
		cout << endl;
	}
	
	for (int v = 0; v < vexNum; v++)
		for (int u = 0; u < vexNum; u++)
			dist[v][u] = 100-Arcs[v][u];
	for (int v = 0; v < vexNum; v++)
		delete[]Arcs[v];
	delete[]Arcs;

}


void AdjMatrixUndirGraph::DisplayFloyd()
//展示弗洛伊德算法
{
	//创建辅助二维数组
	int** path = (int**)new int* [vexNum];
	for (int v = 0; v < vexNum; v++)
		path[v] = new int[vexNum];
	int** dist = (int**)new int* [vexNum];
	for (int v = 0; v < vexNum; v++)
		dist[v] = new int[vexNum];
	Floyd(path, dist);

	//输出
	cout << "dist[][]" << endl;
	for (int v = 0; v < vexNum; v++)
	{
		cout << "\t" << vertexes[v];
	}
	cout << endl;

	for (int v = 0; v < vexNum; v++) {
		cout << vertexes[v];
		for (int u = 0; u < vexNum; u++)
		{
			if (dist[v][u] == 0)
			{
				cout << "\t" << "∞";
			}
			else
			{
				cout << "\t" << dist[v][u];
			}
		}
		cout << endl;
	}
	cout << "path[][]" << endl;
	for (int v = 0; v < vexNum; v++)
	{
		cout << "\t" << vertexes[v];
	}
	cout << endl;

	for (int v = 0; v < vexNum; v++) {
		cout << vertexes[v];
		for (int u = 0; u < vexNum; u++)
		{
			if (path[v][u] == 0)
			{
				cout << "\t" << "∞";
			}
			else
			{
				cout << "\t" << path[v][u];
			}
		}
		cout << endl;
	}
}
#endif