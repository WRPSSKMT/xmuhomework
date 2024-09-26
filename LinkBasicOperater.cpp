#include "HeadFile.h"

// 分配由 p 指向的值为 e 的结点, 并返回
Status MakeNode(Link& p, ElemType e) {
    p = new LNode;
    if (!p) return false; // 分配失败
    p->data = e;          // 赋值
    p->next = nullptr;    // 初始化 next 指针
    return true;          // 成功
}

// 释放 p 所指结点
void FreeNode(Link& p) {
    delete p;             // 释放节点
    p = nullptr;          // 防止悬空指针
}

// 构造一个空的线性链表 L
Status InitList(LinkList& L) {
    L.head = L.tail = nullptr; // 初始化头尾指针
    L.len = 0;                 // 长度为0
    return true;               // 成功
}

// 销毁线性链表 L ， L 不再存在
Status DestoryList(LinkList& L) {
    Link p = L.head;
    while (p) {
        Link q = p;            // 保存当前节点
        p = p->next;          // 移动到下一个节点
        FreeNode(q);          // 释放当前节点
    }
    L.head = L.tail = nullptr; // 清空头尾指针
    L.len = 0;                 // 长度为0
    return true;               // 成功
}

// 将线性链表重置为空表, 并释放原链表的结点空间
Status ClearList(LinkList& L) {
    return DestoryList(L);    // 调用销毁函数
}

// 已知 h 指向线性链表的头结点, 将 s 所指结点插在第一个结点之前
Status InsFirst(Link h, Link s) {
    if (!s) return false;      // s 为空
    s->next = h->next;         // 让 s 指向原来的第一个节点
    h->next = s;               // 让头节点指向新插入的节点
    return true;               // 成功
}

// 已知 h 指向线性链表的头结点, 删除链表中的第一个结点并以 q 返回
Status DelFirst(Link h, Link& q) {
    if (!h->next) return false; // 链表为空
    q = h->next;               // 保存第一个节点
    h->next = q->next;         // 将头节点的 next 指向第二个节点
    return true;               // 成功
}

// 将指针 s 所指（彼此以指针相链）的一串结点链接在线性链表 L 的最后一个结点
// 之后,并改变链表的尾指针指向新的尾结点
Status Append(LinkList& L, Link s) {
    if (!s) return false;        // s 为空
    if (!L.head) {               // 如果链表为空
        L.head = s;              // 头指针指向 s
    }
    else {
        L.tail->next = s;        // 将旧的尾节点的 next 指向 s
    }
    while (s->next) s = s->next; // 找到新的尾节点
    L.tail = s;                  // 更新尾指针
    L.len++;                      // 增加长度
    return true;                 // 成功
}

// 删除线性链表 L 中的尾结点并以 q 返回, 改变链表 L 的尾指针指向新的尾结点
Status Remove(LinkList& L, Link& q) {
    if (!L.head) return false;    // 链表为空
    if (L.head == L.tail) {       // 只有一个节点
        q = L.head;                // 保存尾节点
        L.head = L.tail = nullptr; // 清空链表
    }
    else {
        Link p = L.head;
        while (p->next != L.tail) // 找到倒数第二个节点
            p = p->next;
        q = L.tail;               // 保存尾节点
        L.tail = p;               // 更新尾指针
        L.tail->next = nullptr;    // 断开尾节点
    }
    L.len--;                       // 减少长度
    return true;                  // 成功
}

// 已知 p 指向线性链表 L 中的一个结点, 将 s 所指结点插入在 p 所指结点之前,
// 并修改指针 p 指向新插入的结点
Status InsBefore(LinkList& L, Link& p, Link s) {
    if (!s || p == L.head) return false; // s 为空或 p 是头节点
    Link prev = L.head;                   // 从头节点开始查找前驱
    while (prev->next != p) {             // 找到 p 的前驱
        prev = prev->next;
    }
    prev->next = s;                       // 插入 s
    s->next = p;                          // s 指向 p
    return true;                          // 成功
}

// 已知 p 指向线性链表中的一个结点, 将 s 所指结点插入在 p 所指结点之后,
// 并修改指针 p 指向新插入的结点
Status InsAfter(LinkList& L, Link& p, Link s) {
    if (!s) return false;                // s 为空
    s->next = p->next;                   // s 指向 p 的下一个节点
    p->next = s;                         // p 指向 s
    if (p == L.tail)                     // 如果 p 是尾节点
        L.tail = s;                      // 更新尾指针
    return true;                         // 成功
}

// 已知 p 指向线性链表中的一个结点, 用 e 更新 p 所指结点中数据元素的值
Status SetCurElem(Link& p, ElemType e) {
    if (!p) return false;               // p 为空
    p->data = e;                        // 更新数据
    return true;                        // 成功
}

// 已知 p 指向线性链表中的一个结点, 返回 p 所指结点中数据元素的值
ElemType GetCurElem(Link p) {
    return p->data;                     // 返回数据
}

// 若线性链表 L 为空表, 则返回 TRUE, 否则返回 FALSE
Status ListEmpty(LinkList L) {
    return L.len == 0;                  // 检查长度是否为0
}

// 返回线性链表 L 中元素个数
int ListLength(LinkList L) {
    return L.len;                       // 返回长度
}

// 返回线性链表 L 中头结点的位置
Position GetHead(LinkList L) {
    return L.head;                      // 返回头节点
}

// 返回线性链表 L 中最后一个结点的位置
Position GetLast(LinkList L) {
    return L.tail;                      // 返回尾节点
}

// 已知 p 指向线性链表 L 中的一个结点, 返回 p 所指结点的直接前驱的位置, 
// 若无前驱, 则返回 NULL
Position PriorPos(LinkList L, Link p) {
    if (p == L.head) return nullptr;   // p 是头节点，没有前驱
    Link q = L.head;
    while (q->next != p) {              // 找到前驱
        q = q->next;
    }
    return q;                           // 返回前驱
}

// 已知 p 指向线性链表 L 中的一个结点, 返回 p 所指结点的直接后继的位置,
// 若无后继, 则返回 NULL
Position NextPos(LinkList L, Link p) {
    return p->next;                     // 返回后继
}

// 返回 p 指示线性链表 L 中第 i 个结点的位置并返回 OK, i 值不合法时返回 ERROR
Status LocatePos(LinkList L, int i, Link& p) {
    if (i < 1 || i > L.len) return false; // i 不合法
    p = L.head;
    for (int j = 1; j < i; j++) {
        p = p->next;                     // 移动到第 i 个节点
    }
    return true;                         // 成功
}

// 返回线性链表 L 中第 1 个与 e 满足函数 compare() 判定关系的元素的位置, 
// 若不存在这样的元素, 则返回 NULL
Position LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
    Link p = L.head;
    while (p) {
        if (compare(p->data, e)) return p;     // 找到满足条件的元素
        p = p->next;                           // 移动到下一个节点
    }
    return nullptr;                            // 未找到
}

// 依次对 L 的每个元素调用函数 visit(), 一旦 visit() 失败, 则操作失败
Status ListTraverse(LinkList L, Status(*visit)(ElemType)) {
    Link current = L.head;

    while (current != nullptr) {
        if (!visit(current->data)) {
            return false; // 访问失败
        }
        current = current->next; // 下一个
    }
    return true; // 成功
}

// 打印链表的元素
Status PrintElem(ElemType e) {
    cout << e << " "; 
    return true;
}

// 比较函数
Status compare(ElemType a, ElemType b) {
    return a == b; // 返回两个元素是否相等
}

int main() {
    LinkList L;
    InitList(L); // 初始化链表

    // 创建一些节点
    Link node1, node2, node3;
    MakeNode(node1, 1);
    MakeNode(node2, 2);
    MakeNode(node3, 3);

    // 将节点添加到链表
    Append(L, node1);
    Append(L, node2);
    Append(L, node3);

    cout << "链表长度: " << ListLength(L) << endl; // 打印链表长度
    cout << "链表元素: ";
    ListTraverse(L, PrintElem); // 打印链表元素
    cout << endl;

    // 在头部插入新节点
    Link newNode;
    MakeNode(newNode, 0);
    InsFirst(L.head, newNode);
    cout << "插入 0 后链表元素: ";
    ListTraverse(L, PrintElem);
    cout << endl;

    // 删除第一个节点
    Link deletedNode;
    DelFirst(L.head, deletedNode);
    cout << "删除头节点后链表元素: ";
    ListTraverse(L, PrintElem);
    cout << endl;

    // 在第二个节点前插入新节点
    Link insertBeforeNode;
    MakeNode(insertBeforeNode, 1);
    InsBefore(L, node2, insertBeforeNode);
    cout << "在 1 后插入节点后链表元素: ";
    ListTraverse(L, PrintElem);
    cout << endl;

    // 在第二个节点后插入新节点
    Link insertAfterNode;
    MakeNode(insertAfterNode, 2);
    InsAfter(L, node2, insertAfterNode);
    cout << "在 2 后插入节点后链表元素: ";
    ListTraverse(L, PrintElem);
    cout << endl;

    // 清空链表
    ClearList(L);
    cout << "清空链表后, 链表长度: " << ListLength(L) << endl; // 应该为0

    return 0;
}
