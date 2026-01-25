bool is_constant_list(Node A,Node B){
    Node p=A;
    Node pre=p;//记住每次比较开始时A的节点
    Node q=B;
    while(p&&q){
        if(p->element==q->element){
            p=p->next;
            q=q->next;
        }else{
            pre=pre->next;//失败后回到下一位
            p=pre;
            q=B;   
        }
    }
    if(q==NULL)return 1;
    else return 0;
}