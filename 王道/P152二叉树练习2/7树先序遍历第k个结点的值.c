int i=1;
E PreOrder(Node root,int k){
    if(root==NULL)return "#";
    if(i==k)return root->element;
    i++;
    ch=PreOrder(root->left,k);
    if(ch != "#")return ch;
    ch=PreOrder(root->right,k);
    return ch;
}