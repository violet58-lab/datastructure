Node split(Node A){
    Node B=malloc(sizeof(struct ListNode));//创建B线性表
    B->next=NULL;//B的初始化
    Node p=A->next,q;//扫描指针
    Node r=A;//r指向新链表的表尾
    while(p){
        r->next=p;
        r=p;//r移动
        p=p->next;//p再移动一次，就到B了
        if(p){
            q=p->next;//先保存p的后继，否则会断链
            p->next=B->next;//断链是这里引起的
            B->next=p;
            p=q;
        }
    }
    r->next=NULL;
    return B;//直接返回指针
}