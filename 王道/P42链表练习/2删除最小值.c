void deletdlist(Node head){
    Node p=head->next,minp=p,pre=head,minpre=head;//p为扫描指针
    while(p){
        if(p->element<minp->element){
            minp=p;
            minpre=pre;
        }
        pre=p;
        p=p->next;
    }
    minpre->next=minp->next;
    free(minp);
}