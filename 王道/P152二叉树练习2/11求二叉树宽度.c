typedef struct {
    BiTree data[MAXSize]; // 保存队列中的结点指针
    int level[MAXSize];   // 保存data中相同下标结点的层次
    int front, rear;
} Qu;

int BTWidth(BiTree b) {
    BiTree p;
    int k, max, i, n;
    Qu.front = Qu.rear = -1; // 队列为空
    Qu.rear++;
    Qu.data[Qu.rear] = b;    // 根结点指针入队
    Qu.level[Qu.rear] = 1;   // 根结点层次为1

    while (Qu.front < Qu.rear) {
        Qu.front++;          // 出队
        p = Qu.data[Qu.front]; // 出队结点
        k = Qu.level[Qu.front]; // 出队结点的层次

        if (p->left != NULL) { // 左孩子入队
            Qu.rear++;
            Qu.data[Qu.rear] = p->left;
            Qu.level[Qu.rear] = k + 1;
        }
        if (p->right != NULL) { // 右孩子入队
            Qu.rear++;
            Qu.data[Qu.rear] = p->right;
            Qu.level[Qu.rear] = k + 1;
        }
    }
    max = 0;i = 0; 
    k=1;
    while (i <= Qu.rear) {
        n = 0;
        while (i <= Qu.rear && Qu.level[i] == k) {
            n++;
            i++;
        }
        k=Qu.level[i];
        if (n > max)
            max = n;
    }
    return max;
}