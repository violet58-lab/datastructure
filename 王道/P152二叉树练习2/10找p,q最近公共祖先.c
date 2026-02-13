typedef struct {
    BiTree t;
    int tag;  // tag=0 表示左子女已被访问，tag=1 表示右子女已被访问
} stack;

stack s[],s1[];

BiTree Ancestor(BiTree ROOT, BiTNode *p, BiTNode *q) {
    int top = 0, top1 = 0;
    BiTree bt = ROOT;
    
    while (bt != NULL || top > 0) {
        // 沿左分支一直入栈
        while (bt != NULL) {
            s[++top].t = bt;
            s[top].tag = 0;
            bt = bt->left;
        }
        while (top != 0 && s[top].tag == 1) {
            // 如果当前节点是 p，则将当前栈复制到辅助栈 s1
            if (s[top].t == p) {
                for (int i = 1; i <= top; i++) {
                    s1[i] = s[i];
                }
                top1 = top;
            }
            // 如果当前节点是 q，则在辅助栈中匹配最近的公共祖先
            if (s[top].t == q) {
                for (int i = top; i > 0; i--) {      // 从当前栈顶往下找
                    for (int j = top1; j > 0; j--) { // 从辅助栈顶往下找
                        if (s1[j].t == s[i].t) {
                            return s[i].t;  // 返回第一个匹配的节点
                        }
                    }
                }
            }
            top--;  //退栈
        }
        if (top != 0) {
            s[top].tag = 1;
            bt = s[top].t->right;
        }
    }
    
    return NULL;  //p.q到公共祖先
}