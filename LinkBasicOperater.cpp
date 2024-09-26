#include "HeadFile.h"

// ������ p ָ���ֵΪ e �Ľ��, ������
Status MakeNode(Link& p, ElemType e) {
    p = new LNode;
    if (!p) return false; // ����ʧ��
    p->data = e;          // ��ֵ
    p->next = nullptr;    // ��ʼ�� next ָ��
    return true;          // �ɹ�
}

// �ͷ� p ��ָ���
void FreeNode(Link& p) {
    delete p;             // �ͷŽڵ�
    p = nullptr;          // ��ֹ����ָ��
}

// ����һ���յ��������� L
Status InitList(LinkList& L) {
    L.head = L.tail = nullptr; // ��ʼ��ͷβָ��
    L.len = 0;                 // ����Ϊ0
    return true;               // �ɹ�
}

// ������������ L �� L ���ٴ���
Status DestoryList(LinkList& L) {
    Link p = L.head;
    while (p) {
        Link q = p;            // ���浱ǰ�ڵ�
        p = p->next;          // �ƶ�����һ���ڵ�
        FreeNode(q);          // �ͷŵ�ǰ�ڵ�
    }
    L.head = L.tail = nullptr; // ���ͷβָ��
    L.len = 0;                 // ����Ϊ0
    return true;               // �ɹ�
}

// ��������������Ϊ�ձ�, ���ͷ�ԭ����Ľ��ռ�
Status ClearList(LinkList& L) {
    return DestoryList(L);    // �������ٺ���
}

// ��֪ h ָ�����������ͷ���, �� s ��ָ�����ڵ�һ�����֮ǰ
Status InsFirst(Link h, Link s) {
    if (!s) return false;      // s Ϊ��
    s->next = h->next;         // �� s ָ��ԭ���ĵ�һ���ڵ�
    h->next = s;               // ��ͷ�ڵ�ָ���²���Ľڵ�
    return true;               // �ɹ�
}

// ��֪ h ָ�����������ͷ���, ɾ�������еĵ�һ����㲢�� q ����
Status DelFirst(Link h, Link& q) {
    if (!h->next) return false; // ����Ϊ��
    q = h->next;               // �����һ���ڵ�
    h->next = q->next;         // ��ͷ�ڵ�� next ָ��ڶ����ڵ�
    return true;               // �ɹ�
}

// ��ָ�� s ��ָ���˴���ָ����������һ������������������� L �����һ�����
// ֮��,���ı������βָ��ָ���µ�β���
Status Append(LinkList& L, Link s) {
    if (!s) return false;        // s Ϊ��
    if (!L.head) {               // �������Ϊ��
        L.head = s;              // ͷָ��ָ�� s
    }
    else {
        L.tail->next = s;        // ���ɵ�β�ڵ�� next ָ�� s
    }
    while (s->next) s = s->next; // �ҵ��µ�β�ڵ�
    L.tail = s;                  // ����βָ��
    L.len++;                      // ���ӳ���
    return true;                 // �ɹ�
}

// ɾ���������� L �е�β��㲢�� q ����, �ı����� L ��βָ��ָ���µ�β���
Status Remove(LinkList& L, Link& q) {
    if (!L.head) return false;    // ����Ϊ��
    if (L.head == L.tail) {       // ֻ��һ���ڵ�
        q = L.head;                // ����β�ڵ�
        L.head = L.tail = nullptr; // �������
    }
    else {
        Link p = L.head;
        while (p->next != L.tail) // �ҵ������ڶ����ڵ�
            p = p->next;
        q = L.tail;               // ����β�ڵ�
        L.tail = p;               // ����βָ��
        L.tail->next = nullptr;    // �Ͽ�β�ڵ�
    }
    L.len--;                       // ���ٳ���
    return true;                  // �ɹ�
}

// ��֪ p ָ���������� L �е�һ�����, �� s ��ָ�������� p ��ָ���֮ǰ,
// ���޸�ָ�� p ָ���²���Ľ��
Status InsBefore(LinkList& L, Link& p, Link s) {
    if (!s || p == L.head) return false; // s Ϊ�ջ� p ��ͷ�ڵ�
    Link prev = L.head;                   // ��ͷ�ڵ㿪ʼ����ǰ��
    while (prev->next != p) {             // �ҵ� p ��ǰ��
        prev = prev->next;
    }
    prev->next = s;                       // ���� s
    s->next = p;                          // s ָ�� p
    return true;                          // �ɹ�
}

// ��֪ p ָ�����������е�һ�����, �� s ��ָ�������� p ��ָ���֮��,
// ���޸�ָ�� p ָ���²���Ľ��
Status InsAfter(LinkList& L, Link& p, Link s) {
    if (!s) return false;                // s Ϊ��
    s->next = p->next;                   // s ָ�� p ����һ���ڵ�
    p->next = s;                         // p ָ�� s
    if (p == L.tail)                     // ��� p ��β�ڵ�
        L.tail = s;                      // ����βָ��
    return true;                         // �ɹ�
}

// ��֪ p ָ�����������е�һ�����, �� e ���� p ��ָ���������Ԫ�ص�ֵ
Status SetCurElem(Link& p, ElemType e) {
    if (!p) return false;               // p Ϊ��
    p->data = e;                        // ��������
    return true;                        // �ɹ�
}

// ��֪ p ָ�����������е�һ�����, ���� p ��ָ���������Ԫ�ص�ֵ
ElemType GetCurElem(Link p) {
    return p->data;                     // ��������
}

// ���������� L Ϊ�ձ�, �򷵻� TRUE, ���򷵻� FALSE
Status ListEmpty(LinkList L) {
    return L.len == 0;                  // ��鳤���Ƿ�Ϊ0
}

// ������������ L ��Ԫ�ظ���
int ListLength(LinkList L) {
    return L.len;                       // ���س���
}

// ������������ L ��ͷ����λ��
Position GetHead(LinkList L) {
    return L.head;                      // ����ͷ�ڵ�
}

// ������������ L �����һ������λ��
Position GetLast(LinkList L) {
    return L.tail;                      // ����β�ڵ�
}

// ��֪ p ָ���������� L �е�һ�����, ���� p ��ָ����ֱ��ǰ����λ��, 
// ����ǰ��, �򷵻� NULL
Position PriorPos(LinkList L, Link p) {
    if (p == L.head) return nullptr;   // p ��ͷ�ڵ㣬û��ǰ��
    Link q = L.head;
    while (q->next != p) {              // �ҵ�ǰ��
        q = q->next;
    }
    return q;                           // ����ǰ��
}

// ��֪ p ָ���������� L �е�һ�����, ���� p ��ָ����ֱ�Ӻ�̵�λ��,
// ���޺��, �򷵻� NULL
Position NextPos(LinkList L, Link p) {
    return p->next;                     // ���غ��
}

// ���� p ָʾ�������� L �е� i ������λ�ò����� OK, i ֵ���Ϸ�ʱ���� ERROR
Status LocatePos(LinkList L, int i, Link& p) {
    if (i < 1 || i > L.len) return false; // i ���Ϸ�
    p = L.head;
    for (int j = 1; j < i; j++) {
        p = p->next;                     // �ƶ����� i ���ڵ�
    }
    return true;                         // �ɹ�
}

// ������������ L �е� 1 ���� e ���㺯�� compare() �ж���ϵ��Ԫ�ص�λ��, 
// ��������������Ԫ��, �򷵻� NULL
Position LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
    Link p = L.head;
    while (p) {
        if (compare(p->data, e)) return p;     // �ҵ�����������Ԫ��
        p = p->next;                           // �ƶ�����һ���ڵ�
    }
    return nullptr;                            // δ�ҵ�
}

// ���ζ� L ��ÿ��Ԫ�ص��ú��� visit(), һ�� visit() ʧ��, �����ʧ��
Status ListTraverse(LinkList L, Status(*visit)(ElemType)) {
    Link current = L.head;

    while (current != nullptr) {
        if (!visit(current->data)) {
            return false; // ����ʧ��
        }
        current = current->next; // ��һ��
    }
    return true; // �ɹ�
}

// ��ӡ�����Ԫ��
Status PrintElem(ElemType e) {
    cout << e << " "; 
    return true;
}

// �ȽϺ���
Status compare(ElemType a, ElemType b) {
    return a == b; // ��������Ԫ���Ƿ����
}

int main() {
    LinkList L;
    InitList(L); // ��ʼ������

    // ����һЩ�ڵ�
    Link node1, node2, node3;
    MakeNode(node1, 1);
    MakeNode(node2, 2);
    MakeNode(node3, 3);

    // ���ڵ���ӵ�����
    Append(L, node1);
    Append(L, node2);
    Append(L, node3);

    cout << "������: " << ListLength(L) << endl; // ��ӡ������
    cout << "����Ԫ��: ";
    ListTraverse(L, PrintElem); // ��ӡ����Ԫ��
    cout << endl;

    // ��ͷ�������½ڵ�
    Link newNode;
    MakeNode(newNode, 0);
    InsFirst(L.head, newNode);
    cout << "���� 0 ������Ԫ��: ";
    ListTraverse(L, PrintElem);
    cout << endl;

    // ɾ����һ���ڵ�
    Link deletedNode;
    DelFirst(L.head, deletedNode);
    cout << "ɾ��ͷ�ڵ������Ԫ��: ";
    ListTraverse(L, PrintElem);
    cout << endl;

    // �ڵڶ����ڵ�ǰ�����½ڵ�
    Link insertBeforeNode;
    MakeNode(insertBeforeNode, 1);
    InsBefore(L, node2, insertBeforeNode);
    cout << "�� 1 �����ڵ������Ԫ��: ";
    ListTraverse(L, PrintElem);
    cout << endl;

    // �ڵڶ����ڵ������½ڵ�
    Link insertAfterNode;
    MakeNode(insertAfterNode, 2);
    InsAfter(L, node2, insertAfterNode);
    cout << "�� 2 �����ڵ������Ԫ��: ";
    ListTraverse(L, PrintElem);
    cout << endl;

    // �������
    ClearList(L);
    cout << "��������, ������: " << ListLength(L) << endl; // Ӧ��Ϊ0

    return 0;
}
