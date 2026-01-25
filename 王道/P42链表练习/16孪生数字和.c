int pairlist(Node L){
    Node fast=L->next,slow=L;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;    // 快指针每次走两步
        slow = slow->next;          // 慢指针每次走一步
    }

    // 反转链表后一半部分
    Node newHead = NULL, p = slow->next, tmp;
    while (p != NULL) {            // 反转链表后一半部分的元素，采用头插法
        tmp = p->next;            // p 指向当前待插入结点，令 tmp 指向其下一个结点
        p->next = newHead;        // 将 p 所指结点插入到新链表的首结点之前
        newHead = p;              // newHead 指向刚才新插入的结点，作为新链表的头
        p = tmp;                  // 当前待处理结点变为下一结点
    }

    // 计算后半部分反转后的链表元素之和
    int mx = 0;p=L;
    Node q = newHead;
    while (q != NULL) {
        if((p->element+q->element)>mx)
            mx=p->element+q->element;
        p=p->next;
        q=q->next;
    }
    
    return mx;
}