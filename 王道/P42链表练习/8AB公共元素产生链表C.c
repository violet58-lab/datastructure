void samelist(Node A,Node B){//依次比较，若两元素不等，则值小的后移；若相等，则插入，二者都移
    Node C=malloc(sizeof(struct ListNode));
    C->next=NULL;
    Node p=A->next,q=B->next,r=C;//r指向C的尾节点
    while(p!=NULL&&q!=NULL){
        if(p->element<q->element){
            p=p->next;
        }else if(p->element==q->element){//注意要复制产生节点s
            Node s=malloc(sizeof(struct ListNode));
            s->element=p->element;
            r->next=s;
            r=s;//r要移至结尾了
            p=p->next;
            q=q->next;
        }
        else q=q->next;
    }r->next=NULL;
}