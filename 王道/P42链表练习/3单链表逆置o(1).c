void reverselist(Node head){//头插法(将原链表的节点逐个摘下来,重新插入到头节点之后(头插))
    Node p,r;//p扫描指针
    p=head->next;head->next=NULL;
    while(p){
        r=r->next;//r暂存p的后继节点
        p->next=head->next;//节点指向NULL
        head->next=p;//头节点指向该节点
        p=r;
    }
}