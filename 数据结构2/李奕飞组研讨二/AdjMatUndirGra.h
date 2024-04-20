#pragma once
#ifndef __ADJ_MATRIX_UNDIR_GRAPH_H__
#define __ADJ_MATRIX_UNDIR_GRAPH_H__
#include <cstring>
#include"SeqStack.h"
#include<map>	

SeqStack<string> s1;
// ȫ�ֵ�ջ����������һ��ʹ��
class AdjMatrixUndirGraph
{
protected:
	// �ڽӾ�������ݳ�Ա:
	int vexNum, vexMaxNum, arcNum;		// ������Ŀ������Ķ��������Ŀ�ͱ���
	int **arcs;							// ��ű���Ϣ�ڽӾ��󣨴�����ܶȣ�
	string *vertexes;					// ��Ŷ�����Ϣ�����飨���ÿ�������������
	mutable Status* tag;				// ��־����
	int* huisu;                         //��־���飬��¼·��
	int* huisuout;
	int maxnum,lastnum;
	
	//�����ú���
	bool IsFriend(string n1, string n2);		 // �ж������Ƿ�Ϊ����
	int FirstAdjVex(int v) const;				 // ���ض���v�ĵ�һ���ڽӵ�			 
	int NextAdjVex(int v1, int v2) const;		 // ���ض���v1�������v2����һ���ڽӵ�	
	Status GetTag(int v) const;			         // ���ض���v�ı�־		 
	void SetTag(int v, Status val) const;		 // ���ö���v�ı�־Ϊval
	bool IsUnicom(string n1, string n2);		 // �ж��������Ƿ���ͨ
	void DFS(int v);							 // DFS�������������
	void DFSOut(int v);							 // DFS�������������
	void DFS_All(int v1, int v2);				 // ������·����

	//void fuzhi(int* v);
	//int Max_Span_Tree(int v);                  // �������������Ȩֵ
	void myDFS(int v, int n);
	int DFS_huisuout(pair<int, int>& mm);
	void myDFS_out(int v, int n, int maxn);
public:
	int Max_Span_Tree(int v);                    // �������������Ȩֵ
	void Max_Span_Forest( int& count, pair<int, int>* maxnn);      //�����������ɭ��Ȩֵ
	int DFS_huisu(int v);                        //�����ݵ�DFS�㷨
	void Max_line(pair<int, int> &mm);           //�ֱ��
	

	// �ڽӾ������͵ķ�������:
	AdjMatrixUndirGraph(string es[], int vertexNum, int vertexMaxNum);
	// ������es[]Ϊ����,�������ΪvertexNum,����Ķ��������ĿΪvertexMaxNum,����Ϊ0������ͼ
	AdjMatrixUndirGraph(int vertexMaxNum = DEFAULT_SIZE);
	// ��������Ķ��������ĿΪvertexMaxNum,����Ϊ0������ͼ
	~AdjMatrixUndirGraph();				// ��������

	// ���ܺ���
	void DisplayPath(string n1, string n2);		 // �����˷Ǻ��ѣ�������й�ϵ��·
	void DFSTraverse();							 // DFS����
	void SmallGroup(int n);						 // �������ܶȣ��ҳ���������2��С����
	void InsertVex(const string& d);			 // ����Ԫ��ֵΪd�Ķ���		 
	void InsertArc(int v1, int v2, int w);		 // ���붥��Ϊv1��v2�ı�			 
	void DeleteVex(const string& d);			 // ɾ��Ԫ��ֵΪd�Ķ���			 
	void DeleteArc(int v1, int v2);			     // ɾ������Ϊv1��v2�ı�
	int Trans(string n)const;					 // ������ת��Ϊ�±�
	string Trans(int n)const;					 // ���±�ת��Ϊ����
	bool Save();								 // �������ݵ�TXT�ļ�
	bool IsLegal(string n);						 // �ж�����������Ƿ�Ϸ�
	void Floyd(int** path, int** dist);			 // ���������㷨
	//������
	int GetWeight(int v0, int v1);				 // ����v0��v1�ߵ�Ȩֵ
	void Display();								 // ��ʾ�ڽӾ�������ͼ
	void DisplayFloyd();
};


AdjMatrixUndirGraph::AdjMatrixUndirGraph(string es[], int vertexNum, int vertexMaxNum = DEFAULT_SIZE)
{
	if (vertexMaxNum < 0)
		throw Error("����Ķ��������Ŀ����Ϊ��!");			// �׳��쳣

	if (vertexMaxNum < vertexNum)
		throw Error("������Ŀ���ܴ�������Ķ��������Ŀ!");	// �׳��쳣

	vexNum = vertexNum;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;

	vertexes = new string[vexMaxNum];						// �������ɶ�����Ϣ����
	tag = new Status[vexMaxNum];							// ���ɱ�־����
	arcs = (int**)new int* [vexMaxNum];						// �����ڽӾ���
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
// �������������������������ĿΪvertexMaxNum�Ŀ�����ͼ
{
	if (vertexMaxNum < 0)
		throw Error("����Ķ��������Ŀ����Ϊ��!");

	vexNum = 0;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;

	vertexes = new string[vexMaxNum];						// �������ɶ�����Ϣ����
	tag = new Status[vexMaxNum];							// ���ɱ�־����
	arcs = (int**)new int* [vexMaxNum];						// �����ڽӾ���
	for (int v = 0; v < vexMaxNum; v++)
		arcs[v] = new int[vexMaxNum];
}

AdjMatrixUndirGraph::~AdjMatrixUndirGraph()
// ����������ͷŶ�����ռ�õĿռ�
{
	delete[]vertexes;										// �ͷŶ�������
	delete[]tag;											// �ͷű�־

	for (int v = 0; v < vexMaxNum; v++)						// �ͷ��ڽӾ������
		delete[]arcs[v];
	delete[]arcs;											// �ͷ��ڽӾ���
}

int AdjMatrixUndirGraph::FirstAdjVex(int v) const
// ������������ض���v�ĵ�1���ڽӵ�����		 
{
	if (v < 0 || v >= vexNum)
		throw Error("v���Ϸ�!");	// �׳��쳣

	for (int u = 0; u < vexNum; u++)
		if (arcs[v][u] != 0)
			return u;

	return -1;						// ����-1��ʾ���ڽӵ�
}

int AdjMatrixUndirGraph::NextAdjVex(int v1, int v2) const
// ������������ض���v1�������v2����һ���ڽӵ�			 
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1���Ϸ�!");	// �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2���Ϸ�!");	// �׳��쳣
	if (v1 == v2) throw
		Error("v1���ܵ���v2!");		// �׳��쳣

	for (int u = v2 + 1; u < vexNum; u++)
		if (arcs[v1][u] != 0)
			return u;

	return -1;						// ����-1��ʾ����һ���ڽӵ�
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
// ������������ض���v�ı�־		 
{
	if (v < 0 || v >= vexNum)
		throw Error("v���Ϸ�!");	// �׳��쳣

	return tag[v];
}

void AdjMatrixUndirGraph::SetTag(int v, Status val) const
// ������������ö���v�ı�־Ϊval		 
{
	if (v < 0 || v >= vexNum)
		throw Error("v���Ϸ�!");	// �׳��쳣

	tag[v] = val;
}

void AdjMatrixUndirGraph::DisplayPath(string n1, string n2)
{
	for (int v = 0; v < vexNum; v++)
		SetTag(v, UNVISITED);					// ��ÿ����������δ���ʱ�־
	if (IsFriend(n1, n2) == true)
		cout << "����������";
	else if (IsUnicom(n1, n2) == false)
	{
		cout << "�����˼��޹�ϵ��·";
	}
	else
	{
		for (int v = 0; v < vexNum; v++)
			SetTag(v, UNVISITED);				// ��ÿ����������δ���ʱ�־
		cout << "���˵Ĺ�ϵ��·Ϊ��" << endl;
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
			cout << "С����" << ++n << "Ϊ��" << endl;
			DFSOut(v);
			cout << endl;
		}
	}
}

void AdjMatrixUndirGraph::SmallGroup(int n)
{
	int** Arcs = (int**)new int* [vexNum];
	for (int v = 0; v < vexNum; v++)
		Arcs[v] = new int[vexNum];				// �´���һ����ά����
	for (int v = 0; v < vexNum; v++)
		for (int u = 0; u < vexNum; u++)
			Arcs[v][u] = arcs[v][u];			// ��ԭ���ı���Ϣ��������������
	for (int v = 0; v < vexNum; v++)
		for (int u = 0; u < vexNum; u++)
		{
			if (arcs[u][v] != 0)
				arcs[v][u] = arcs[u][v];		// �����������洢ת��Ϊ����
			if (arcs[v][u] < n)
				arcs[v][u] = 0;					// С����ֵ�ı�ֱ����0
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
// ������������붥��d			 
{
	if (vexNum == vexMaxNum)
		throw Error("ͼ�Ķ��������ܳ�������������!");	

	vertexes[vexNum] = d;
	tag[vexNum] = UNVISITED;
	for (int v = 0; v <= vexNum; v++) {
		arcs[vexNum][v] = 0;
		arcs[v][vexNum] = 0;
	}
	vexNum++;
}


void AdjMatrixUndirGraph::InsertArc(int v1, int v2, int w)
// ���������������������v1��v2�ı�			 
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1���Ϸ�!");				// �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2���Ϸ�!");				// �׳��쳣
	if (v1 == v2)
		throw Error("v1���ܵ���v2!");			// �׳��쳣

	//if (arcs[v1][v2] == 0) {					// ԭ����ͼ��û�б�(v1, v2) 
		arcNum++;
		arcs[v1][v2] = w;
	//	arcs[v2][v1] = w;
	//}
}

void AdjMatrixUndirGraph::DeleteVex(const string& d)
// ���������ɾ��Ԫ��Ϊd�Ķ���			 
{
	int v;
	for (v = 0; v < vexNum; v++)
		if (vertexes[v] == d)
			break;
	if (v == vexNum)
		throw Error("ͼ�в�����Ҫɾ���Ķ���!");	// �׳��쳣

	for (int u = 0; u < vexNum; u++)             // ɾ���붥��d������ı� 
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
// ���������ɾ����������v1��v2�ı�			 
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1���Ϸ�!");				// �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2���Ϸ�!");				// �׳��쳣
	if (v1 == v2)
		throw Error("v1���ܵ���v2!");			// �׳��쳣

	if (arcs[v1][v2] != 0) {					// ԭ����ͼ���ڱ�(v1, v2)
		arcNum--;
		arcs[v1][v2] = 0;
		arcs[v2][v1] = 0;
	}
	else
	{
		cout << "����İ���Ĳ�����İ��";
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
	SetTag(v, VISITED);						// ���ö���v�ѷ��ʱ�־
	for (int w = FirstAdjVex(v); w != -1; w = NextAdjVex(v, w))
		if (GetTag(w) == UNVISITED)
			DFS(w);							// ��v����δ���ʹ����ڽӶ���w��ʼ���������������
}

void AdjMatrixUndirGraph::DFSOut(int v)
{
	SetTag(v, VISITED);						// ���ö���v�ѷ��ʱ�־
	cout << vertexes[v] << " ";
	for (int w = FirstAdjVex(v); w != -1; w = NextAdjVex(v, w))
		if (GetTag(w) == UNVISITED)
			DFSOut(w);						// ��v����δ���ʹ����ڽӶ���w��ʼ���������������
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

	int count=0;                                 //  ��¼������ֵ
	bool flag = true;
	bool* isJoin = new bool[vexNum];

	int* MaxCost = new int[vexNum];
	for (int i = 0; i < vexNum; i++) {
		isJoin[i] = false;
		MaxCost[i] = 0;
	}
	pair<int,int> Each_Max_cost;              //first Ϊֵ��secondΪ���
	Each_Max_cost = make_pair(0, v);
	pair<int, int>Last_pair = make_pair(-1, -1);
	isJoin[v] = true;
	tag[v] = VISITED;
	for (int i = 0; i < vexNum; i++)
	{
		MaxCost[i] = arcs[v][i];
	}
	//��ʼ��prim,��������ʼ�����
	while (flag) {
		Each_Max_cost.first = 0;
		for (int i = 0; i < vexNum; i++)                      //�������Ӧ��
			if (isJoin[i]== false && MaxCost[i] > Each_Max_cost.first) {     //û���ʹ������ܶ����
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
		cout << "����ͨ·��" << endl;
		return;
	}
	cout << "·������Ϊ:" << endl;
	for (int i = lastnum; i !=-1; i=huisuout[i]) {
		cout << vertexes[i]<<" ";
	}
	cout << endl;
	
}



void AdjMatrixUndirGraph::Display()
// �������: ��ʾ�ڽӾ�������ͼ
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
		cout << "friend.txt��ʧ��" << endl;
		return false;
	}
	else
		cout << "friend.txt�򿪳ɹ�" << endl;
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
	cout << "�������籣��ɹ�" << endl;
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
// ����v0��v1�ߵ�Ȩֵ,��û�бߣ����������
{
	return arcs[v0][v1];
}

void AdjMatrixUndirGraph::Floyd(int** path, int** dist)
// ���������㷨�����·��
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
				cout << "\t" << "��";
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
				cout << "\t" << "��";
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
//չʾ���������㷨
{
	//����������ά����
	int** path = (int**)new int* [vexNum];
	for (int v = 0; v < vexNum; v++)
		path[v] = new int[vexNum];
	int** dist = (int**)new int* [vexNum];
	for (int v = 0; v < vexNum; v++)
		dist[v] = new int[vexNum];
	Floyd(path, dist);

	//���
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
				cout << "\t" << "��";
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
				cout << "\t" << "��";
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