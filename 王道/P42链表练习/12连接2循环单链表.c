Node linklist(Node A,Node B){
    Node p=h1,q=h2;
    while(p->next!=h1)
        p=p->next;
    while(q->next!=h2)
        q=q->next;
    p->next=h2;
    q->next=h1;
    return h1;
}