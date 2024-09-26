#pragma once

#include <iostream>
using namespace std;

#define ElemType     int
#define Status       bool 

// 结点
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}*Link, *Position;

// 链表
typedef struct
{
	Link head, tail;
	int len;
}LinkList;

// 分配由 p 指向的值为 e 的结点, 并返回
Status MakeNode(Link &p, ElemType e);

// 释放 p 所指结点
void FreeNode(Link &p);

// 构造一个空的线性链表 L
Status InitList(LinkList &L);

// 销毁线性链表 L ， L 不再存在
Status DestoryList(LinkList &L);

// 将线性链表重置为空表, 并释放原链表的结点空间
Status ClearList(LinkList &L);

// 已知 h 指向线性链表的头结点, 将 s 所指结点插人在第一个结点之前
Status InsFirst(Link h, Link s);

// 已知 h 指向线性链表的头结点, 删除链表中的第一个结点并以 q 返回
Status DelFirst(Link h, Link &q);

// 将指针 s 所指（彼此以指针相链）的一串结点链接在线性链表 L 的最后一个结点
// 之后,并改变链表工的尾指针指向新的尾结点
Status Append(LinkList &L,Link s);

// 删除线性链表 L 中的尾结点并以 q 返回, 改变链表 L 的尾指针指向新的尾结点
Status Remove(LinkList &L, Link &q);

// 已知 p 指向线性链表 L 中的一个结点, 将 s 所指结点插入在 p 所指结点之前,
// 并修改指针 p 指向新插人的结点
Status InsBefore(LinkList &L, Link &p, Link s);

// 已知 p 指向线性链表工中的一个结点, 将 s 所指结点插入在 p 所指结点之后,
// 并修改指针 p 指向新插入的结点
Status InsAfter(LinkList &L, Link &p, Link s);

// 已知 p 指向线性链表中的一个结点, 用 e 更新 p 所指结点中数据元素的值
Status SetCurElem(Link &p, ElemType e);

// 已知 p 指向线性链表中的一个结点, 返回 p 所指结点中数据元素的值
ElemType GetCurElem(Link p);

// 若线性链表 L 为空表, 则返回 TRUE, 否则返回 FALSE
Status ListEmpty(LinkList L);

// 返回线性链表 L 中元素个数
int ListLength(LinkList L);

// 返回线性链表 L 中头结点的位置
Position GetHead(LinkList L);

// 返回线性链表 L 中最后一个结点的位置
Position GetLast(LinkList L);

// 已知 p 指向线性链表 L 中的一个结点, 返回 p 所指结点的直接前驱的位置, 
// 若无前驱, 则返回 NULL
Position PriorPos(LinkList L, Link p);

// 已知 p 指向线性链表 L 中的一个结点, 返回 p 所指结点的直接后继的位置,
// 若无后继, 则返回 NULL
Position NextPos(LinkList L, Link p);

// 返回 p 指示线性链表 L 中第 i 个结点的位置并返回 OK, i 值不合法时返回 ERROR
Status LocatePos(LinkList L, int i, Link &p);

// 返回线性链表 L 中第 1 个与 e 满足函数 compare() 判定关系的元素的位置, 
// 若不存在这样的元素, 则返回 NULL
Position LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType));

// 依次对 L 的每个元素调用函数 visit(), 一旦 visit() 失败, 则操作失败
Status ListTraverse(LinkList L, Status(*visit)());

// 打印链表
Status PrintElem(ElemType e);