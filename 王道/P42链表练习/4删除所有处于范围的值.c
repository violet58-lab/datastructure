bool deletelist(Node head,E s,E t){
    if(s>=t)return 0;
    Node p=head->next,pre=head,q;
    while(p){
        if(p->element>s && p->element<t){
            pre->next=p->next;
            q=p;
            p=p->next;
            free(q);
        }else{//不删除，2指针都后移
            pre=p;
            p=p->next;
        }
    }
    return 1;
}