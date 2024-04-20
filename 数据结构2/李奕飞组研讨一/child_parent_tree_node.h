#pragma once
#ifndef __CHILD_PARENT_TREE_NODE_H__
#define __CHILD_PARENT_TREE_NODE_H__

#include "node.h"				// 线性链表


// 孩子双法表示树结点类
template <class ElemType>
struct ChildParentTreeNode
{
	// 数据成员:
	ElemType nam, bir, mar, add, sta, dea;
	// 基本成员信息（名字，出生日期，婚姻，地址，目前状况，死亡日期）
	Node<int>* childLkList;			// 孩子链表
	int num, gen, parent;			// 双亲位置域

	// 构造函数:
	ChildParentTreeNode();			// 无参数的构造函数
	ChildParentTreeNode(ElemType na, ElemType b, ElemType m,
		ElemType a, ElemType s, ElemType d, int pt, int nu, int g, Node<int>* childlk);// 已知数据域值和双亲位置建立结构
};

// 孩子双法表示树结点类的实现部分
template<class ElemType>
ChildParentTreeNode<ElemType>::ChildParentTreeNode()
// 操作结果：构造双亲域为-1的结点
{
	parent = -1;
	nam = "未知", bir = "未知", mar = "未知", add = "未知", sta = "未知", dea = "未知";
	childLkList = NULL;
}

template<class ElemType>
ChildParentTreeNode<ElemType>::ChildParentTreeNode(ElemType na, ElemType b, ElemType m,
	ElemType a, ElemType s, ElemType d, int pt, int nu, int g, Node<int>* childlk)
	// 操作结果：构造一个数据域为item和双亲域为pt的结点
{
	nam = na, bir = b, mar = m, add = a, sta = s, dea = d, gen = g;
	parent = pt, num = nu, gen = g;					// 双亲
	childLkList = childlk;
}

#endif