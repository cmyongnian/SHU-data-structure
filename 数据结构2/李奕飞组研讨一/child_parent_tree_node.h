#pragma once
#ifndef __CHILD_PARENT_TREE_NODE_H__
#define __CHILD_PARENT_TREE_NODE_H__

#include "node.h"				// ��������


// ����˫����ʾ�������
template <class ElemType>
struct ChildParentTreeNode
{
	// ���ݳ�Ա:
	ElemType nam, bir, mar, add, sta, dea;
	// ������Ա��Ϣ�����֣��������ڣ���������ַ��Ŀǰ״�����������ڣ�
	Node<int>* childLkList;			// ��������
	int num, gen, parent;			// ˫��λ����

	// ���캯��:
	ChildParentTreeNode();			// �޲����Ĺ��캯��
	ChildParentTreeNode(ElemType na, ElemType b, ElemType m,
		ElemType a, ElemType s, ElemType d, int pt, int nu, int g, Node<int>* childlk);// ��֪������ֵ��˫��λ�ý����ṹ
};

// ����˫����ʾ��������ʵ�ֲ���
template<class ElemType>
ChildParentTreeNode<ElemType>::ChildParentTreeNode()
// �������������˫����Ϊ-1�Ľ��
{
	parent = -1;
	nam = "δ֪", bir = "δ֪", mar = "δ֪", add = "δ֪", sta = "δ֪", dea = "δ֪";
	childLkList = NULL;
}

template<class ElemType>
ChildParentTreeNode<ElemType>::ChildParentTreeNode(ElemType na, ElemType b, ElemType m,
	ElemType a, ElemType s, ElemType d, int pt, int nu, int g, Node<int>* childlk)
	// �������������һ��������Ϊitem��˫����Ϊpt�Ľ��
{
	nam = na, bir = b, mar = m, add = a, sta = s, dea = d, gen = g;
	parent = pt, num = nu, gen = g;					// ˫��
	childLkList = childlk;
}

#endif