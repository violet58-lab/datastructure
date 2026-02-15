//gpt还给了一个思路，可以稍微了解一下：

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char val;
    Node* left;
    Node* right;
    Node(char v): val(v), left(nullptr), right(nullptr) {}
};

void postOrder2Stacks(Node* root) {
    if (!root) return;
    stack<Node*> s1, s2;//s1遍历树，s2逆序输出
    s1.push(root);

    while (!s1.empty()) {
        Node* x = s1.top(); s1.pop();
        s2.push(x);
        if (x->left)  s1.push(x->left);
        if (x->right) s1.push(x->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->val << ' ';
        s2.pop();
    }
}