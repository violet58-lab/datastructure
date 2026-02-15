#include <bits/stdc++.h>
using namespace std;

struct Node {
    char val;
    Node* left;
    Node* right;
    Node(char v): val(v), left(nullptr), right(nullptr) {}
};

void postOrder(Node* root) {
    stack<Node*> st;
    Node* cur = root;
    Node* prev = nullptr;  // 上一次“访问(输出)”的结点

    while (cur || !st.empty()) {
        // 1) 一直往左下走
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }

        // 2) 看栈顶
        Node* top = st.top();

        // 如果右子树不存在，或者右子树刚刚访问过，则可以访问 top
        if (top->right == nullptr || top->right == prev) {
            cout << top->val << ' ';
            st.pop();
            prev = top;          // 记录刚访问的结点
            // cur 仍为 nullptr，继续回看新的栈顶
        } else {
            // 否则先去遍历右子树
            cur = top->right;
        }
    }
}