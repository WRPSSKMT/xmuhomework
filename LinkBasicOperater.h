#pragma once

#include <iostream>
using namespace std;

#define ElemType     int
#define Status       bool 

// ���
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}*Link, *Position;

// ����
typedef struct
{
	Link head, tail;
	int len;
}LinkList;

// ������ p ָ���ֵΪ e �Ľ��, ������
Status MakeNode(Link &p, ElemType e);

// �ͷ� p ��ָ���
void FreeNode(Link &p);

// ����һ���յ��������� L
Status InitList(LinkList &L);

// ������������ L �� L ���ٴ���
Status DestoryList(LinkList &L);

// ��������������Ϊ�ձ�, ���ͷ�ԭ����Ľ��ռ�
Status ClearList(LinkList &L);

// ��֪ h ָ�����������ͷ���, �� s ��ָ�������ڵ�һ�����֮ǰ
Status InsFirst(Link h, Link s);

// ��֪ h ָ�����������ͷ���, ɾ�������еĵ�һ����㲢�� q ����
Status DelFirst(Link h, Link &q);

// ��ָ�� s ��ָ���˴���ָ����������һ������������������� L �����һ�����
// ֮��,���ı�������βָ��ָ���µ�β���
Status Append(LinkList &L,Link s);

// ɾ���������� L �е�β��㲢�� q ����, �ı����� L ��βָ��ָ���µ�β���
Status Remove(LinkList &L, Link &q);

// ��֪ p ָ���������� L �е�һ�����, �� s ��ָ�������� p ��ָ���֮ǰ,
// ���޸�ָ�� p ָ���²��˵Ľ��
Status InsBefore(LinkList &L, Link &p, Link s);

// ��֪ p ָ�����������е�һ�����, �� s ��ָ�������� p ��ָ���֮��,
// ���޸�ָ�� p ָ���²���Ľ��
Status InsAfter(LinkList &L, Link &p, Link s);

// ��֪ p ָ�����������е�һ�����, �� e ���� p ��ָ���������Ԫ�ص�ֵ
Status SetCurElem(Link &p, ElemType e);

// ��֪ p ָ�����������е�һ�����, ���� p ��ָ���������Ԫ�ص�ֵ
ElemType GetCurElem(Link p);

// ���������� L Ϊ�ձ�, �򷵻� TRUE, ���򷵻� FALSE
Status ListEmpty(LinkList L);

// ������������ L ��Ԫ�ظ���
int ListLength(LinkList L);

// ������������ L ��ͷ����λ��
Position GetHead(LinkList L);

// ������������ L �����һ������λ��
Position GetLast(LinkList L);

// ��֪ p ָ���������� L �е�һ�����, ���� p ��ָ����ֱ��ǰ����λ��, 
// ����ǰ��, �򷵻� NULL
Position PriorPos(LinkList L, Link p);

// ��֪ p ָ���������� L �е�һ�����, ���� p ��ָ����ֱ�Ӻ�̵�λ��,
// ���޺��, �򷵻� NULL
Position NextPos(LinkList L, Link p);

// ���� p ָʾ�������� L �е� i ������λ�ò����� OK, i ֵ���Ϸ�ʱ���� ERROR
Status LocatePos(LinkList L, int i, Link &p);

// ������������ L �е� 1 ���� e ���㺯�� compare() �ж���ϵ��Ԫ�ص�λ��, 
// ��������������Ԫ��, �򷵻� NULL
Position LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType));

// ���ζ� L ��ÿ��Ԫ�ص��ú��� visit(), һ�� visit() ʧ��, �����ʧ��
Status ListTraverse(LinkList L, Status(*visit)());

// ��ӡ����
Status PrintElem(ElemType e);