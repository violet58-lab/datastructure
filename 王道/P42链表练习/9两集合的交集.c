void sameset(Node A,Node B){
    Node p=A->next,q=B->next,r=A;//r指向A的尾节点
    r->next=NULL;//只是把 A 的 next 断开
    while(p!=NULL&&q!=NULL){
        if(p->element<q->element){
            p=p->next;
        }else if(p->element==q->element){//注意要复制产生节点s
            Node s=malloc(sizeof(struct ListNode));
            s->element=p->element;
            s->next=NULL;//关键，要初始化
            r->next=s;
            r=s;//r要移至结尾了
            p=p->next;
            q=q->next;
        }
        else q=q->next;
    }r->next=NULL;
}
//官方：复用 A 中的结点作为结果表，释放其余无用结点，彻底节省内存
//若 pa == pb → 把 A 里的这个结点留下，挂到结果链
//若 pa < pb → A 里这个结点不可能出现在交集 → 释放
//若 pa > pb → B 里这个结点不可能出现在交集 → 释放
//扫描结束 → 释放剩余结点 → A 只剩交集
LinkList Union(LinkList la, LinkList lb)
{
    LNode *pa = la->next;   // A 工作指针
    LNode *pb = lb->next;   // B 工作指针
    LNode *pc = la;         // 结果链表尾指针
    LNode *u;

    while (pa && pb) {
        if (pa->data == pb->data) {   // 交集元素
            pc->next = pa;            // A 结点并入结果链
            pc = pa;
            pa = pa->next;

            u = pb;                   // 释放 B 中对应结点
            pb = pb->next;
            free(u);
        }
        else if (pa->data < pb->data) {  // A 当前结点不在交集
            u = pa;
            pa = pa->next;
            free(u);
        }
        else {                           // B 当前结点不在交集
            u = pb;
            pb = pb->next;
            free(u);
        }
    }

    // 释放 A 中剩余结点
    while (pa) {
        u = pa;
        pa = pa->next;
        free(u);
    }

    // 释放 B 中剩余结点
    while (pb) {
        u = pb;
        pb = pb->next;
        free(u);
    }

    pc->next = NULL;   // 结果链表封尾
    free(lb);          // 释放 B 的头结点

    return la;
}