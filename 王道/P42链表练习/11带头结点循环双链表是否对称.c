bool symmetry(Node head){
    Node p=head->next,q=head->prior;
    while(p!=q&&p->next!=q){
        if(p->element==q->element){
            p=p->next;
            q=q->prior
        }else
            return 0;
    }
    return 1;
}