void deletelist(Node head,E x){//1.尾插法(尾节点置空)
    Node p=head->next,r=head,q;//p扫描指针，r指向新链表的最后一个节点，q用于存x再释放空间(删)
    while(p){
        if(p->element!=x){
            r->next=p;//存下
            r=p;//尾指针后移
            p=p->next;//后移
        }
        else{
            q=p;
            p=p->next;
            free(q);
        }
    }
    r->next=NULL;//尾节点置空
}