void changelist(Node head){
    Node p,q,r,s;
    p=q=head;
    while(q->next!=NULL){
        p=p->next;//p走到中间节点
        q=q->next;
        if(q->next!=NULL)q=q->next;//q走两步到尾
    }
    q=p->next;
    p->next=NULL;
    while(q){//后半部分逆置
        r=q->next;
        q->next=p->next;
        p->next=q;
        q=r;
    }
    s=head->next;
    q=p->next;
    p->next=NULL;
    while(q){
        r=q->next;
        q->next=s->next;
        s->next=q;
        s=q->next;
        q=r;
    }
}