Node locate(Node L,E x){
    Node p=L->next,q;
    while(p&&p->element!=x){
        p=p->next;
    }
    if(!p)
        exit(0);
    else{
        p->freq++;
        if(p->pre==L||p->pre->freq>p->freq)
            return p;//p为首节点，或freq值小于前驱
        if(p->next !=NULL)p->next->pre=p->pre;
        p->pre->next=p->next;
        q=p->pre;//将p从链表上摘下来
        while(q!=L&&q->freq<=p->freq)//查找p要插入的位置
            q=q->next;
        p->next=q->next;
        if(q->next!=NULL)q->next->pre=p;//p排在同频率第一个
        p->pre=q;
        q->next=p;
    }
}