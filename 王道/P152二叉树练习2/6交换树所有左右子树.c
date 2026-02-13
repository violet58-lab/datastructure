void swap(Node b){
    if(b){
        swap(b->left);
        swap(b->right);
        Node tmp = b->left;
        b->left = b->right;
        b->right = tmp;
    }
}